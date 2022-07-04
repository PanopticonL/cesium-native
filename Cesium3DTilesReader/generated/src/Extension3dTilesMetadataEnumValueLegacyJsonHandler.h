// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include <Cesium3DTiles/Extension3dTilesMetadataEnumValueLegacy.h>
#include <CesiumJsonReader/ExtensibleObjectJsonHandler.h>
#include <CesiumJsonReader/IntegerJsonHandler.h>
#include <CesiumJsonReader/StringJsonHandler.h>

namespace CesiumJsonReader {
class ExtensionReaderContext;
}

namespace Cesium3DTilesReader {
class Extension3dTilesMetadataEnumValueLegacyJsonHandler
    : public CesiumJsonReader::ExtensibleObjectJsonHandler {
public:
  using ValueType = Cesium3DTiles::Extension3dTilesMetadataEnumValueLegacy;

  Extension3dTilesMetadataEnumValueLegacyJsonHandler(
      const CesiumJsonReader::ExtensionReaderContext& context) noexcept;
  void reset(
      IJsonHandler* pParentHandler,
      Cesium3DTiles::Extension3dTilesMetadataEnumValueLegacy* pObject);

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* readObjectKeyExtension3dTilesMetadataEnumValueLegacy(
      const std::string& objectType,
      const std::string_view& str,
      Cesium3DTiles::Extension3dTilesMetadataEnumValueLegacy& o);

private:
  Cesium3DTiles::Extension3dTilesMetadataEnumValueLegacy* _pObject = nullptr;
  CesiumJsonReader::StringJsonHandler _name;
  CesiumJsonReader::StringJsonHandler _description;
  CesiumJsonReader::IntegerJsonHandler<int64_t> _value;
};
} // namespace Cesium3DTilesReader
