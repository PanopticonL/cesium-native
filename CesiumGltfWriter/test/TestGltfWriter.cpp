#include "CesiumGltfWriter/GltfWriter.h"

#include <CesiumGltf/ExtensionKhrDracoMeshCompression.h>
#include <CesiumGltfReader/GltfReader.h>

#include <catch2/catch.hpp>
#include <rapidjson/document.h>

namespace {
void check(const std::string& input, const std::string& expectedOutput) {
  CesiumGltfReader::GltfReader reader;
  CesiumGltfReader::GltfReaderResult readResult = reader.readGltf(gsl::span(
      reinterpret_cast<const std::byte*>(input.c_str()),
      input.size()));
  REQUIRE(readResult.errors.empty());
  REQUIRE(readResult.warnings.empty());
  REQUIRE(readResult.model.has_value());

  CesiumGltf::Model& model = readResult.model.value();

  CesiumGltfWriter::GltfWriter writer;
  CesiumGltfWriter::GltfWriterResult writeResult = writer.writeGltf(model);
  const auto gltfBytes = writeResult.gltfBytes;

  REQUIRE(writeResult.errors.empty());
  REQUIRE(writeResult.warnings.empty());

  const std::string gltfString(
      reinterpret_cast<const char*>(gltfBytes.data()),
      gltfBytes.size());

  rapidjson::Document gltfJson;
  gltfJson.Parse(gltfString.c_str());

  rapidjson::Document expectedJson;
  expectedJson.Parse(expectedOutput.c_str());

  REQUIRE(gltfJson == expectedJson);
}
} // namespace

TEST_CASE("Writes glTF") {
  std::string string = R"(
    {
      "asset": {
        "version": "2.0"
      },
      "scene": 0,
      "scenes": [
        {
          "nodes": [
            0
          ]
        }
      ],
      "nodes": [
        {
          "children": [
            1
          ]
        },
        {
          "mesh": 0
        }
      ],
      "meshes": [
        {
          "primitives": [
            {
              "attributes": {
                "NORMAL": 1,
                "POSITION": 2,
                "TEXCOORD_0": 3
              },
              "indices": 0,
              "material": 0
            }
          ]
        }
      ],
      "accessors": [
        {
          "bufferView": 0,
          "byteOffset": 0,
          "componentType": 5123,
          "count": 36,
          "type": "SCALAR"
        },
        {
          "bufferView": 1,
          "byteOffset": 0,
          "componentType": 5126,
          "count": 24,
          "type": "VEC3"
        },
        {
          "bufferView": 1,
          "byteOffset": 288,
          "componentType": 5126,
          "count": 24,
          "max": [
            0.5,
            0.5,
            0.5
          ],
          "min": [
            -0.5,
            -0.5,
            -0.5
          ],
          "type": "VEC3"
        },
        {
          "bufferView": 2,
          "byteOffset": 0,
          "componentType": 5126,
          "count": 24,
          "type": "VEC2"
        }
      ],
      "materials": [
        {
          "pbrMetallicRoughness": {
            "baseColorTexture": {
              "index": 0
            },
            "metallicFactor": 0
          }
        }
      ],
      "textures": [
        {
          "sampler": 0,
          "source": 0
        }
      ],
      "images": [
        {
          "uri": "CesiumLogoFlat.png"
        }
      ],
      "samplers": [
        {
          "magFilter": 9729,
          "minFilter": 9986
        }
      ],
      "bufferViews": [
        {
          "buffer": 0,
          "byteOffset": 768,
          "byteLength": 72,
          "target": 34963
        },
        {
          "buffer": 0,
          "byteOffset": 0,
          "byteLength": 576,
          "byteStride": 12,
          "target": 34962
        },
        {
          "buffer": 0,
          "byteOffset": 576,
          "byteLength": 192,
          "byteStride": 8,
          "target": 34962
        }
      ],
      "buffers": [
        {
          "byteLength": 840,
          "uri": "BoxTextured0.bin"
        }
      ]
    }
  )";

  check(string, string);
}

TEST_CASE("Writes glTF with extras") {
  std::string string = R"(
    {
      "asset": {
        "version": "2.0"
      },
      "scene": 0,
      "scenes": [
        {
          "nodes": [0]
        }
      ],
      "nodes": [
        {
          "extras": {
            "D": "Goodbye"
          }
        }
      ],
      "extras": {
        "A": "Hello",
        "B": 1234567,
        "C": {
          "C1": {},
          "C2": [1,2,3,4,5],
          "C3": true
        }
      }
    }
  )";

  check(string, string);
}

TEST_CASE("Writes glTF with custom extension") {
  std::string string = R"(
    {
      "asset": {
        "version": "2.0"
      },
      "scene": 0,
      "scenes": [
        {
          "nodes": [0]
        }
      ],
      "nodes": [
        { }
      ],
      "extensionsUsed": ["A", "B"],
      "extensions": {
        "A": {
          "test": "Hello"
        },
        "B": {
          "another": "Goodbye"
        }
      }
    }
  )";

  check(string, string);
}

TEST_CASE("Writes glTF with default values removed") {
  std::string string = R"(
    {
      "asset": {
        "version": "2.0"
      },
      "scene": 0,
      "scenes": [
        {
          "nodes": [
            0
          ]
        }
      ],
      "nodes": [
        {
          "mesh": 0,
          "matrix": [1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0]
        }
      ],
      "meshes": [
        {
          "primitives": [
            {
              "attributes": {
                "POSITION": 1
              },
              "mode": 4,
              "indices": 0,
              "material": 0
            }
          ]
        }
      ],
      "accessors": [
        {
          "bufferView": 0,
          "byteOffset": 0,
          "componentType": 5123,
          "count": 36,
          "type": "SCALAR"
        },
        {
          "bufferView": 1,
          "byteOffset": 288,
          "componentType": 5126,
          "count": 24,
          "max": [
            0.5,
            0.5,
            0.5
          ],
          "min": [
            -0.5,
            -0.5,
            -0.5
          ],
          "type": "VEC3"
        }
      ],
      "materials": [
        {
          "pbrMetallicRoughness": {
            "baseColorTexture": {
              "index": 0,
              "texCoord": 0
            },
            "roughnessFactor": 1,
            "metallicFactor": 0
          },
          "emissiveFactor": [0, 0, 0]
        }
      ],
      "textures": [
        {
          "sampler": 0,
          "source": 0
        }
      ],
      "images": [
        {
          "uri": "CesiumLogoFlat.png"
        }
      ],
      "samplers": [
        {
          "magFilter": 9729,
          "minFilter": 9986,
          "wrapS": 10497,
          "wrapT": 10497
        }
      ],
      "bufferViews": [
        {
          "buffer": 0,
          "byteOffset": 768,
          "byteLength": 72,
          "target": 34963
        },
        {
          "buffer": 0,
          "byteOffset": 0,
          "byteLength": 576,
          "byteStride": 12,
          "target": 34962
        }
      ],
      "buffers": [
        {
          "byteLength": 840,
          "uri": "BoxTextured0.bin"
        }
      ]
    }
  )";

  std::string expected = R"(
    {
      "asset": {
        "version": "2.0"
      },
      "scene": 0,
      "scenes": [
        {
          "nodes": [
            0
          ]
        }
      ],
      "nodes": [
        {
          "mesh": 0
        }
      ],
      "meshes": [
        {
          "primitives": [
            {
              "attributes": {
                "POSITION": 1
              },
              "indices": 0,
              "material": 0
            }
          ]
        }
      ],
      "accessors": [
        {
          "bufferView": 0,
          "byteOffset": 0,
          "componentType": 5123,
          "count": 36,
          "type": "SCALAR"
        },
        {
          "bufferView": 1,
          "byteOffset": 288,
          "componentType": 5126,
          "count": 24,
          "max": [
            0.5,
            0.5,
            0.5
          ],
          "min": [
            -0.5,
            -0.5,
            -0.5
          ],
          "type": "VEC3"
        }
      ],
      "materials": [
        {
          "pbrMetallicRoughness": {
            "baseColorTexture": {
              "index": 0
            },
            "metallicFactor": 0
          }
        }
      ],
      "textures": [
        {
          "sampler": 0,
          "source": 0
        }
      ],
      "images": [
        {
          "uri": "CesiumLogoFlat.png"
        }
      ],
      "samplers": [
        {
          "magFilter": 9729,
          "minFilter": 9986
        }
      ],
      "bufferViews": [
        {
          "buffer": 0,
          "byteOffset": 768,
          "byteLength": 72,
          "target": 34963
        },
        {
          "buffer": 0,
          "byteOffset": 0,
          "byteLength": 576,
          "byteStride": 12,
          "target": 34962
        }
      ],
      "buffers": [
        {
          "byteLength": 840,
          "uri": "BoxTextured0.bin"
        }
      ]
    }
  )";

  check(string, expected);
}

TEST_CASE("Writes glb") {
  const std::vector<std::byte> bufferData{
      std::byte('H'),
      std::byte('e'),
      std::byte('l'),
      std::byte('l'),
      std::byte('o'),
      std::byte('W'),
      std::byte('o'),
      std::byte('r'),
      std::byte('l'),
      std::byte('d'),
      std::byte('!')};

  CesiumGltf::Model model;
  model.asset.version = "2.0";
  CesiumGltf::Buffer buffer;
  buffer.byteLength = static_cast<int64_t>(bufferData.size());
  model.buffers.push_back(buffer);

  CesiumGltfWriter::GltfWriter writer;
  CesiumGltfWriter::GltfWriterResult writeResult =
      writer.writeGlb(model, bufferData);
  const auto gltfBytes = writeResult.gltfBytes;

  REQUIRE(writeResult.errors.empty());
  REQUIRE(writeResult.warnings.empty());

  // Now read the glb back
  CesiumGltfReader::GltfReader reader;
  CesiumGltfReader::GltfReaderResult readResult = reader.readGltf(gltfBytes);

  REQUIRE(readResult.errors.empty());
  REQUIRE(readResult.warnings.empty());
  REQUIRE(readResult.model.has_value());

  CesiumGltf::Model& readModel = readResult.model.value();
  const std::vector<std::byte> readModelBuffer =
      readModel.buffers[0].cesium.data;

  REQUIRE(readModelBuffer == bufferData);
  REQUIRE(readModel.asset.version == "2.0");
  REQUIRE(readModel.buffers[0].byteLength == 11);
}