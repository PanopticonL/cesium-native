// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "Cesium3DTiles/ExtensibleObject.h"
#include "Cesium3DTiles/Library.h"

namespace Cesium3DTiles {
/**
 * @brief A dictionary object of metadata about per-feature properties.
 */
struct CESIUM3DTILES_API Properties final : public ExtensibleObject {
  static inline constexpr const char* TypeName = "Properties";

  /**
   * @brief The maximum value of this property of all the features in the
   * tileset.
   */
  double maximum = double();

  /**
   * @brief The minimum value of this property of all the features in the
   * tileset.
   */
  double minimum = double();
};
} // namespace Cesium3DTiles
