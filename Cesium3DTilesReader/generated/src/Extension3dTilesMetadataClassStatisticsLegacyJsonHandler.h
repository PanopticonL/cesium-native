// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "Extension3dTilesMetadataPropertyStatisticsLegacyJsonHandler.h"

#include <Cesium3DTiles/Extension3dTilesMetadataClassStatisticsLegacy.h>
#include <CesiumJsonReader/DictionaryJsonHandler.h>
#include <CesiumJsonReader/ExtensibleObjectJsonHandler.h>
#include <CesiumJsonReader/IntegerJsonHandler.h>

namespace CesiumJsonReader {
class ExtensionReaderContext;
}

namespace Cesium3DTilesReader {
class Extension3dTilesMetadataClassStatisticsLegacyJsonHandler
    : public CesiumJsonReader::ExtensibleObjectJsonHandler {
public:
  using ValueType =
      Cesium3DTiles::Extension3dTilesMetadataClassStatisticsLegacy;

  Extension3dTilesMetadataClassStatisticsLegacyJsonHandler(
      const CesiumJsonReader::ExtensionReaderContext& context) noexcept;
  void reset(
      IJsonHandler* pParentHandler,
      Cesium3DTiles::Extension3dTilesMetadataClassStatisticsLegacy* pObject);

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* readObjectKeyExtension3dTilesMetadataClassStatisticsLegacy(
      const std::string& objectType,
      const std::string_view& str,
      Cesium3DTiles::Extension3dTilesMetadataClassStatisticsLegacy& o);

private:
  Cesium3DTiles::Extension3dTilesMetadataClassStatisticsLegacy* _pObject =
      nullptr;
  CesiumJsonReader::IntegerJsonHandler<int64_t> _count;
  CesiumJsonReader::DictionaryJsonHandler<
      Cesium3DTiles::Extension3dTilesMetadataPropertyStatisticsLegacy,
      Extension3dTilesMetadataPropertyStatisticsLegacyJsonHandler>
      _properties;
};
} // namespace Cesium3DTilesReader
