#include "CesiumGltfReader/GltfReader.h"

#include "ModelJsonHandler.h"
#include "decodeDataUrls.h"
#include "decodeDraco.h"
#include "registerExtensions.h"

#include <CesiumAsync/IAssetRequest.h>
#include <CesiumAsync/IAssetResponse.h>
#include <CesiumJsonReader/ExtensionReaderContext.h>
#include <CesiumJsonReader/JsonHandler.h>
#include <CesiumJsonReader/JsonReader.h>
#include <CesiumUtility/Tracing.h>
#include <CesiumUtility/Uri.h>

#include <ktx.h>
#include <rapidjson/reader.h>

#include <algorithm>
#include <cstddef>
#include <iomanip>
#include <sstream>
#include <string>

#define STB_IMAGE_IMPLEMENTATION
#define STBI_FAILURE_USERMSG
#include <stb_image.h>

using namespace CesiumAsync;
using namespace CesiumGltf;
using namespace CesiumGltfReader;
using namespace CesiumJsonReader;
using namespace CesiumUtility;

namespace {
#pragma pack(push, 1)
struct GlbHeader {
  uint32_t magic;
  uint32_t version;
  uint32_t length;
};

struct ChunkHeader {
  uint32_t chunkLength;
  uint32_t chunkType;
};
#pragma pack(pop)

bool isBinaryGltf(const gsl::span<const std::byte>& data) noexcept {
  if (data.size() < sizeof(GlbHeader)) {
    return false;
  }

  return reinterpret_cast<const GlbHeader*>(data.data())->magic == 0x46546C67;
}

GltfReaderResult readJsonGltf(
    const CesiumJsonReader::ExtensionReaderContext& context,
    const gsl::span<const std::byte>& data) {

  CESIUM_TRACE("CesiumGltfReader::GltfReader::readJsonGltf");

  ModelJsonHandler modelHandler(context);
  CesiumJsonReader::ReadJsonResult<Model> jsonResult =
      CesiumJsonReader::JsonReader::readJson(data, modelHandler);

  return GltfReaderResult{
      std::move(jsonResult.value),
      std::move(jsonResult.errors),
      std::move(jsonResult.warnings)};
}

/**
 * @brief Creates a string representation for the given magic value.
 *
 * The details are not specified, but the output will include a
 * hex representation of the given value, as well as the result
 * of interpreting the value as 4 unsigned characters.
 *
 * @param i The value
 * @return The string
 */
std::string toMagicString(uint32_t i) {
  const unsigned char c0 = static_cast<unsigned char>(i & 0xFF);
  const unsigned char c1 = static_cast<unsigned char>((i >> 8) & 0xFF);
  const unsigned char c2 = static_cast<unsigned char>((i >> 16) & 0xFF);
  const unsigned char c3 = static_cast<unsigned char>((i >> 24) & 0xFF);
  std::stringstream stream;
  stream << c0 << c1 << c2 << c3 << " (0x" << std::hex << i << ")";
  return stream.str();
}

GltfReaderResult readBinaryGltf(
    const CesiumJsonReader::ExtensionReaderContext& context,
    const gsl::span<const std::byte>& data) {
  CESIUM_TRACE("CesiumGltfReader::GltfReader::readBinaryGltf");

  if (data.size() < sizeof(GlbHeader) + sizeof(ChunkHeader)) {
    return {std::nullopt, {"Too short to be a valid GLB."}, {}};
  }

  const GlbHeader* pHeader = reinterpret_cast<const GlbHeader*>(data.data());
  if (pHeader->magic != 0x46546C67) {
    return {
        std::nullopt,
        {"GLB does not start with the expected magic value 'glTF', but " +
         toMagicString(pHeader->magic)},
        {}};
  }

  if (pHeader->version != 2) {
    return {
        std::nullopt,
        {"Only binary glTF version 2 is supported, found version " +
         std::to_string(pHeader->version)},
        {}};
  }

  if (pHeader->length > data.size()) {
    return {
        std::nullopt,
        {"GLB extends past the end of the buffer, header size " +
         std::to_string(pHeader->length) + ", data size " +
         std::to_string(data.size())},
        {}};
  }

  const gsl::span<const std::byte> glbData = data.subspan(0, pHeader->length);

  const ChunkHeader* pJsonChunkHeader =
      reinterpret_cast<const ChunkHeader*>(glbData.data() + sizeof(GlbHeader));
  if (pJsonChunkHeader->chunkType != 0x4E4F534A) {
    return {
        std::nullopt,
        {"GLB JSON chunk does not have the expected chunkType 'JSON', but " +
         toMagicString(pJsonChunkHeader->chunkType)},
        {}};
  }

  const size_t jsonStart = sizeof(GlbHeader) + sizeof(ChunkHeader);
  const size_t jsonEnd = jsonStart + pJsonChunkHeader->chunkLength;

  if (jsonEnd > glbData.size()) {
    return {
        std::nullopt,
        {"GLB JSON chunk extends past the end of the buffer, JSON end at " +
         std::to_string(jsonEnd) + ", data size " +
         std::to_string(glbData.size())},
        {}};
  }

  const gsl::span<const std::byte> jsonChunk =
      glbData.subspan(jsonStart, pJsonChunkHeader->chunkLength);
  gsl::span<const std::byte> binaryChunk;

  if (jsonEnd + sizeof(ChunkHeader) <= data.size()) {
    const ChunkHeader* pBinaryChunkHeader =
        reinterpret_cast<const ChunkHeader*>(glbData.data() + jsonEnd);
    if (pBinaryChunkHeader->chunkType != 0x004E4942) {
      return {
          std::nullopt,
          {"GLB binary chunk does not have the expected chunkType 'BIN', but " +
           toMagicString(pBinaryChunkHeader->chunkType)},
          {}};
    }

    const size_t binaryStart = jsonEnd + sizeof(ChunkHeader);
    const size_t binaryEnd = binaryStart + pBinaryChunkHeader->chunkLength;

    if (binaryEnd > glbData.size()) {
      return {
          std::nullopt,
          {"GLB binary chunk extends past the end of the buffer, binary end "
           "at " +
           std::to_string(binaryEnd) + ", data size " +
           std::to_string(glbData.size())},
          {}};
    }

    binaryChunk = glbData.subspan(binaryStart, pBinaryChunkHeader->chunkLength);
  }

  GltfReaderResult result = readJsonGltf(context, jsonChunk);

  if (result.model && !binaryChunk.empty()) {
    Model& model = result.model.value();

    if (model.buffers.empty()) {
      result.errors.emplace_back(
          "GLB has a binary chunk but the JSON does not define any buffers.");
      return result;
    }

    Buffer& buffer = model.buffers[0];
    if (buffer.uri) {
      result.errors.emplace_back("GLB has a binary chunk but the first buffer "
                                 "in the JSON chunk also has a 'uri'.");
      return result;
    }

    const int64_t binaryChunkSize = static_cast<int64_t>(binaryChunk.size());
    if (buffer.byteLength > binaryChunkSize ||
        buffer.byteLength + 3 < binaryChunkSize) {
      result.errors.emplace_back("GLB binary chunk size does not match the "
                                 "size of the first buffer in the JSON chunk.");
      return result;
    }

    buffer.cesium.data = std::vector<std::byte>(
        binaryChunk.begin(),
        binaryChunk.begin() + buffer.byteLength);
  }

  return result;
}

void postprocess(
    const GltfReader& reader,
    GltfReaderResult& readGltf,
    const GltfReaderOptions& options) {
  Model& model = readGltf.model.value();

  if (options.decodeDataUrls) {
    decodeDataUrls(reader, readGltf, options);
  }

  if (options.decodeEmbeddedImages) {
    CESIUM_TRACE("CesiumGltfReader::decodeEmbeddedImages");
    for (Image& image : model.images) {
      // Ignore external images for now.
      if (image.uri) {
        continue;
      }

      const BufferView& bufferView =
          Model::getSafe(model.bufferViews, image.bufferView);
      const Buffer& buffer = Model::getSafe(model.buffers, bufferView.buffer);

      if (bufferView.byteOffset + bufferView.byteLength >
          static_cast<int64_t>(buffer.cesium.data.size())) {
        readGltf.warnings.emplace_back(
            "Image bufferView's byte offset is " +
            std::to_string(bufferView.byteOffset) + " and the byteLength is " +
            std::to_string(bufferView.byteLength) + ", the result is " +
            std::to_string(bufferView.byteOffset + bufferView.byteLength) +
            ", which is more than the available " +
            std::to_string(buffer.cesium.data.size()) + " bytes.");
        continue;
      }

      const gsl::span<const std::byte> bufferSpan(buffer.cesium.data);
      const gsl::span<const std::byte> bufferViewSpan = bufferSpan.subspan(
          static_cast<size_t>(bufferView.byteOffset),
          static_cast<size_t>(bufferView.byteLength));
      ImageReaderResult imageResult =
          GltfReader::readImage(bufferViewSpan, options.ktx2TranscodeTargets);
      readGltf.warnings.insert(
          readGltf.warnings.end(),
          imageResult.warnings.begin(),
          imageResult.warnings.end());
      readGltf.errors.insert(
          readGltf.errors.end(),
          imageResult.errors.begin(),
          imageResult.errors.end());
      if (imageResult.image) {
        image.cesium = std::move(imageResult.image.value());
      } else {
        if (image.mimeType) {
          readGltf.errors.emplace_back(
              "Declared image MIME Type: " + image.mimeType.value());
        } else {
          readGltf.errors.emplace_back("Image does not declare a MIME Type");
        }
      }
    }
  }

  if (options.decodeDraco) {
    decodeDraco(readGltf);
  }
}

} // namespace

GltfReader::GltfReader() : _context() { registerExtensions(this->_context); }

CesiumJsonReader::ExtensionReaderContext& GltfReader::getExtensions() {
  return this->_context;
}

const CesiumJsonReader::ExtensionReaderContext&
GltfReader::getExtensions() const {
  return this->_context;
}

GltfReaderResult GltfReader::readGltf(
    const gsl::span<const std::byte>& data,
    const GltfReaderOptions& options) const {

  const CesiumJsonReader::ExtensionReaderContext& context =
      this->getExtensions();
  GltfReaderResult result = isBinaryGltf(data) ? readBinaryGltf(context, data)
                                               : readJsonGltf(context, data);

  if (result.model) {
    postprocess(*this, result, options);
  }

  return result;
}

/*static*/
Future<GltfReaderResult> GltfReader::resolveExternalData(
    const std::shared_ptr<AsyncSystem>& pAsyncSystem,
    const std::string& baseUrl,
    const HttpHeaders& headers,
    std::shared_ptr<IAssetAccessor> pAssetAccessor,
    const GltfReaderOptions& options,
    GltfReaderResult&& result) {

  // TODO: Can we avoid this copy conversion?
  std::vector<IAssetAccessor::THeader> tHeaders(headers.begin(), headers.end());

  if (!result.model) {
    return pAsyncSystem->createResolvedFuture(std::move(result));
  }

  // Get a rough count of how many external buffers we may have.
  // Some of these may be data uris though.
  size_t uriBuffersCount = 0;
  for (const Buffer& buffer : result.model->buffers) {
    if (buffer.uri) {
      ++uriBuffersCount;
    }
  }

  for (const Image& image : result.model->images) {
    if (image.uri) {
      ++uriBuffersCount;
    }
  }

  if (uriBuffersCount == 0) {
    return pAsyncSystem->createResolvedFuture(std::move(result));
  }

  auto pResult = std::make_unique<GltfReaderResult>(std::move(result));

  struct ExternalBufferLoadResult {
    bool success = false;
    std::string bufferUri;
  };

  std::vector<Future<ExternalBufferLoadResult>> resolvedBuffers;
  resolvedBuffers.reserve(uriBuffersCount);

  // We need to skip data uris.
  constexpr std::string_view dataPrefix = "data:";
  constexpr size_t dataPrefixLength = dataPrefix.size();

  for (Buffer& buffer : pResult->model->buffers) {
    if (buffer.uri && buffer.uri->substr(0, dataPrefixLength) != dataPrefix) {
      resolvedBuffers.push_back(
          pAssetAccessor
              ->get(pAsyncSystem, Uri::resolve(baseUrl, *buffer.uri), tHeaders)
              .thenInWorkerThread(
                  [pBuffer =
                       &buffer](std::shared_ptr<IAssetRequest>&& pRequest) {
                    const IAssetResponse* pResponse = pRequest->response();

                    std::string bufferUri = *pBuffer->uri;

                    if (pResponse) {
                      pBuffer->uri = std::nullopt;
                      pBuffer->cesium.data = std::vector<std::byte>(
                          pResponse->data().begin(),
                          pResponse->data().end());
                      return ExternalBufferLoadResult{true, bufferUri};
                    }

                    return ExternalBufferLoadResult{false, bufferUri};
                  }));
    }
  }

  for (Image& image : pResult->model->images) {
    if (image.uri && image.uri->substr(0, dataPrefixLength) != dataPrefix) {
      resolvedBuffers.push_back(
          pAssetAccessor
              ->get(pAsyncSystem, Uri::resolve(baseUrl, *image.uri), tHeaders)
              .thenInWorkerThread(
                  [pImage = &image,
                   ktx2TranscodeTargets = options.ktx2TranscodeTargets](
                      std::shared_ptr<IAssetRequest>&& pRequest) {
                    const IAssetResponse* pResponse = pRequest->response();

                    std::string imageUri = *pImage->uri;

                    if (pResponse) {
                      pImage->uri = std::nullopt;

                      ImageReaderResult imageResult =
                          readImage(pResponse->data(), ktx2TranscodeTargets);
                      if (imageResult.image) {
                        pImage->cesium = std::move(*imageResult.image);
                        return ExternalBufferLoadResult{true, imageUri};
                      }
                    }

                    return ExternalBufferLoadResult{false, imageUri};
                  }));
    }
  }

  return pAsyncSystem->all(std::move(resolvedBuffers))
      .thenInWorkerThread(
          [pResult = std::move(pResult)](
              std::vector<ExternalBufferLoadResult>&& loadResults) mutable {
            for (auto& bufferResult : loadResults) {
              if (!bufferResult.success) {
                pResult->warnings.push_back(
                    "Could not load the external gltf buffer: " +
                    bufferResult.bufferUri);
              }
            }
            return std::move(*pResult.release());
          });
}

bool isKtx(const gsl::span<const std::byte>& data) {
  const size_t ktxMagicByteLength = 12;
  if (data.size() < ktxMagicByteLength) {
    return false;
  }

  const uint8_t ktxMagic[ktxMagicByteLength] =
      {0xAB, 0x4B, 0x54, 0x58, 0x20, 0x32, 0x30, 0xBB, 0x0D, 0x0A, 0x1A, 0x0A};

  return memcmp(data.data(), ktxMagic, ktxMagicByteLength) == 0;
}

/*static*/
ImageReaderResult GltfReader::readImage(
    const gsl::span<const std::byte>& data,
    const Ktx2TranscodeTargets& ktx2TranscodeTargets) {
  CESIUM_TRACE("CesiumGltfReader::readImage");

  ImageReaderResult result;

  result.image.emplace();
  ImageCesium& image = result.image.value();

  if (isKtx(data)) {
    ktxTexture2* pTexture = nullptr;
    KTX_error_code errorCode;

    errorCode = ktxTexture2_CreateFromMemory(
        reinterpret_cast<const std::uint8_t*>(data.data()),
        data.size(),
        KTX_TEXTURE_CREATE_LOAD_IMAGE_DATA_BIT,
        &pTexture);

    if (errorCode == KTX_SUCCESS) {
      if (ktxTexture2_NeedsTranscoding(pTexture)) {

        CESIUM_TRACE("Transcode KTXv2");

        image.channels =
            static_cast<int32_t>(ktxTexture2_GetNumComponents(pTexture));
        GpuCompressedPixelFormat transcodeTargetFormat =
            GpuCompressedPixelFormat::NONE;

        if (pTexture->supercompressionScheme == KTX_SS_BASIS_LZ) {
          switch (image.channels) {
          case 1:
            transcodeTargetFormat = ktx2TranscodeTargets.ETC1S_R;
            break;
          case 2:
            transcodeTargetFormat = ktx2TranscodeTargets.ETC1S_RG;
            break;
          case 3:
            transcodeTargetFormat = ktx2TranscodeTargets.ETC1S_RGB;
            break;
          // case 4:
          default:
            transcodeTargetFormat = ktx2TranscodeTargets.ETC1S_RGBA;
          }
        } else {
          switch (image.channels) {
          case 1:
            transcodeTargetFormat = ktx2TranscodeTargets.UASTC_R;
            break;
          case 2:
            transcodeTargetFormat = ktx2TranscodeTargets.UASTC_RG;
            break;
          case 3:
            transcodeTargetFormat = ktx2TranscodeTargets.UASTC_RGB;
            break;
          // case 4:
          default:
            transcodeTargetFormat = ktx2TranscodeTargets.UASTC_RGBA;
          }
        }

        ktx_transcode_fmt_e transcodeTargetFormat_ = KTX_TTF_RGBA32;
        switch (transcodeTargetFormat) {
        case GpuCompressedPixelFormat::ETC1_RGB:
          transcodeTargetFormat_ = KTX_TTF_ETC1_RGB;
          break;
        case GpuCompressedPixelFormat::ETC2_RGBA:
          transcodeTargetFormat_ = KTX_TTF_ETC2_RGBA;
          break;
        case GpuCompressedPixelFormat::BC1_RGB:
          transcodeTargetFormat_ = KTX_TTF_BC1_RGB;
          break;
        case GpuCompressedPixelFormat::BC3_RGBA:
          transcodeTargetFormat_ = KTX_TTF_BC3_RGBA;
          break;
        case GpuCompressedPixelFormat::BC4_R:
          transcodeTargetFormat_ = KTX_TTF_BC4_R;
          break;
        case GpuCompressedPixelFormat::BC5_RG:
          transcodeTargetFormat_ = KTX_TTF_BC5_RG;
          break;
        case GpuCompressedPixelFormat::BC7_RGBA:
          transcodeTargetFormat_ = KTX_TTF_BC7_RGBA;
          break;
        case GpuCompressedPixelFormat::PVRTC1_4_RGB:
          transcodeTargetFormat_ = KTX_TTF_PVRTC1_4_RGB;
          break;
        case GpuCompressedPixelFormat::PVRTC1_4_RGBA:
          transcodeTargetFormat_ = KTX_TTF_PVRTC1_4_RGBA;
          break;
        case GpuCompressedPixelFormat::ASTC_4x4_RGBA:
          transcodeTargetFormat_ = KTX_TTF_ASTC_4x4_RGBA;
          break;
        case GpuCompressedPixelFormat::PVRTC2_4_RGB:
          transcodeTargetFormat_ = KTX_TTF_PVRTC2_4_RGB;
          break;
        case GpuCompressedPixelFormat::PVRTC2_4_RGBA:
          transcodeTargetFormat_ = KTX_TTF_PVRTC2_4_RGBA;
          break;
        case GpuCompressedPixelFormat::ETC2_EAC_R11:
          transcodeTargetFormat_ = KTX_TTF_ETC2_EAC_R11;
          break;
        case GpuCompressedPixelFormat::ETC2_EAC_RG11:
          transcodeTargetFormat_ = KTX_TTF_ETC2_EAC_RG11;
          break;
        // case NONE:
        default:
          transcodeTargetFormat_ = KTX_TTF_RGBA32;
          break;
        };

        errorCode =
            ktxTexture2_TranscodeBasis(pTexture, transcodeTargetFormat_, 0);
        if (errorCode == KTX_SUCCESS) {
          image.compressedPixelFormat = transcodeTargetFormat;
          image.width = static_cast<int32_t>(pTexture->baseWidth);
          image.height = static_cast<int32_t>(pTexture->baseHeight);

          if (transcodeTargetFormat == GpuCompressedPixelFormat::NONE) {
            // We fully decompressed the texture in this case.
            image.bytesPerChannel = 1;
            image.channels = 4;
          }

          // Copy over the positions of each mip within the buffer.
          image.mipPositions.resize(pTexture->numLevels);
          for (ktx_uint32_t level = 0; level < pTexture->numLevels; ++level) {
            ktx_size_t imageOffset;
            ktxTexture_GetImageOffset(
                ktxTexture(pTexture),
                level,
                0,
                0,
                &imageOffset);
            ktx_size_t imageSize =
                ktxTexture_GetImageSize(ktxTexture(pTexture), level);

            image.mipPositions[level] = {imageOffset, imageSize};
          }

          // Copy over the entire buffer, including all mips.
          ktx_uint8_t* pixelData = ktxTexture_GetData(ktxTexture(pTexture));
          ktx_size_t pixelDataSize =
              ktxTexture_GetDataSize(ktxTexture(pTexture));

          image.pixelData.resize(pixelDataSize);
          std::uint8_t* u8Pointer =
              reinterpret_cast<std::uint8_t*>(image.pixelData.data());
          std::copy(pixelData, pixelData + pixelDataSize, u8Pointer);

          ktxTexture_Destroy(ktxTexture(pTexture));

          return result;
        }
      }
    }

    result.image.reset();
    result.errors.emplace_back("KTX2 loading failed");

    return result;
  }

  {
    CESIUM_TRACE("Decode JPG / PNG");

    image.bytesPerChannel = 1;
    image.channels = 4;

    int channelsInFile;
    stbi_uc* pImage = stbi_load_from_memory(
        reinterpret_cast<const stbi_uc*>(data.data()),
        static_cast<int>(data.size()),
        &image.width,
        &image.height,
        &channelsInFile,
        image.channels);
    if (pImage) {
      CESIUM_TRACE(
          "copy image " + std::to_string(image.width) + "x" +
          std::to_string(image.height) + "x" + std::to_string(image.channels) +
          "x" + std::to_string(image.bytesPerChannel));
      // std::uint8_t is not implicitly convertible to std::byte, so we must use
      // reinterpret_cast to (safely) force the conversion.
      const auto lastByte =
          image.width * image.height * image.channels * image.bytesPerChannel;
      image.pixelData.resize(static_cast<std::size_t>(lastByte));
      std::uint8_t* u8Pointer =
          reinterpret_cast<std::uint8_t*>(image.pixelData.data());
      std::copy(pImage, pImage + lastByte, u8Pointer);
      stbi_image_free(pImage);
    } else {
      result.image.reset();
      result.errors.emplace_back(stbi_failure_reason());
    }
  }

  return result;
}
