// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "CesiumGltf/Library.h"
#include "CesiumGltf/PropertyTable.h"
#include "CesiumGltf/PropertyTexture.h"
#include "CesiumGltf/Schema.h"

#include <CesiumUtility/ExtensibleObject.h>

#include <optional>
#include <string>
#include <vector>

namespace CesiumGltf {
/**
 * @brief glTF extension that assigns properties to features in a model.
 */
struct CESIUMGLTF_API ExtensionModelExtMeshFeatures final
    : public CesiumUtility::ExtensibleObject {
  static inline constexpr const char* TypeName =
      "ExtensionModelExtMeshFeatures";
  static inline constexpr const char* ExtensionName = "EXT_mesh_features";

  /**
   * @brief An object defining classes and enums.
   */
  std::optional<CesiumGltf::Schema> schema;

  /**
   * @brief The URI (or IRI) of the external schema file.
   */
  std::optional<std::string> schemaUri;

  /**
   * @brief An array of property table definitions, which may be referenced by
   * index.
   */
  std::vector<CesiumGltf::PropertyTable> propertyTables;

  /**
   * @brief An array of property texture definitions, which may be referenced by
   * index.
   */
  std::vector<CesiumGltf::PropertyTexture> propertyTextures;
};
} // namespace CesiumGltf