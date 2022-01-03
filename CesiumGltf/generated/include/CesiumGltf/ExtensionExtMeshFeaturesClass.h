// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "CesiumGltf/ExtensionExtMeshFeaturesClassProperty.h"
#include "CesiumGltf/Library.h"

#include <CesiumUtility/ExtensibleObject.h>

#include <optional>
#include <string>
#include <unordered_map>

namespace CesiumGltf {
/**
 * @brief A class containing a set of properties.
 */
struct CESIUMGLTF_API ExtensionExtMeshFeaturesClass final
    : public CesiumUtility::ExtensibleObject {
  static inline constexpr const char* TypeName =
      "ExtensionExtMeshFeaturesClass";

  /**
   * @brief The name of the class, e.g. for display purposes.
   */
  std::optional<std::string> name;

  /**
   * @brief The description of the class.
   */
  std::optional<std::string> description;

  /**
   * @brief A dictionary, where each key is a property ID and each value is an
   * object defining the property. Property IDs may contain only alphanumeric
   * and underscore characters.
   */
  std::unordered_map<
      std::string,
      CesiumGltf::ExtensionExtMeshFeaturesClassProperty>
      properties;
};
} // namespace CesiumGltf