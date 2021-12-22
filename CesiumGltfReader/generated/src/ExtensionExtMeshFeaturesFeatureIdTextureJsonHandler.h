// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "TextureInfoJsonHandler.h"

#include <CesiumGltf/ExtensionExtMeshFeaturesFeatureIdTexture.h>
#include <CesiumJsonReader/IntegerJsonHandler.h>

namespace CesiumJsonReader {
class ExtensionReaderContext;
}

namespace CesiumGltfReader {
class ExtensionExtMeshFeaturesFeatureIdTextureJsonHandler
    : public TextureInfoJsonHandler {
public:
  using ValueType = CesiumGltf::ExtensionExtMeshFeaturesFeatureIdTexture;

  ExtensionExtMeshFeaturesFeatureIdTextureJsonHandler(
      const CesiumJsonReader::ExtensionReaderContext& context) noexcept;
  void reset(
      IJsonHandler* pParentHandler,
      CesiumGltf::ExtensionExtMeshFeaturesFeatureIdTexture* pObject);

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* readObjectKeyExtensionExtMeshFeaturesFeatureIdTexture(
      const std::string& objectType,
      const std::string_view& str,
      CesiumGltf::ExtensionExtMeshFeaturesFeatureIdTexture& o);

private:
  CesiumGltf::ExtensionExtMeshFeaturesFeatureIdTexture* _pObject = nullptr;
  CesiumJsonReader::IntegerJsonHandler<int64_t> _channel;
};
} // namespace CesiumGltfReader
