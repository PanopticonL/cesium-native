// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "PropertyTexturePropertyJsonHandler.h"

#include <CesiumGltf/PropertyTexture.h>
#include <CesiumJsonReader/DictionaryJsonHandler.h>
#include <CesiumJsonReader/ExtensibleObjectJsonHandler.h>
#include <CesiumJsonReader/StringJsonHandler.h>

namespace CesiumJsonReader {
class JsonReaderOptions;
}

namespace CesiumGltfReader {
class PropertyTextureJsonHandler
    : public CesiumJsonReader::ExtensibleObjectJsonHandler {
public:
  using ValueType = CesiumGltf::PropertyTexture;

  PropertyTextureJsonHandler(
      const CesiumJsonReader::JsonReaderOptions& options) noexcept;
  void
  reset(IJsonHandler* pParentHandler, CesiumGltf::PropertyTexture* pObject);

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* readObjectKeyPropertyTexture(
      const std::string& objectType,
      const std::string_view& str,
      CesiumGltf::PropertyTexture& o);

private:
  CesiumGltf::PropertyTexture* _pObject = nullptr;
  CesiumJsonReader::StringJsonHandler _name;
  CesiumJsonReader::StringJsonHandler _classProperty;
  CesiumJsonReader::DictionaryJsonHandler<
      CesiumGltf::PropertyTextureProperty,
      PropertyTexturePropertyJsonHandler>
      _properties;
};
} // namespace CesiumGltfReader
