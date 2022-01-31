// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "Cesium3DTiles/Library.h"

#include <CesiumUtility/ExtensibleObject.h>
#include <CesiumUtility/JsonValue.h>

#include <unordered_map>

namespace Cesium3DTiles {
/**
 * @brief Statistics about property values.
 */
struct CESIUM3DTILES_API PropertyStatistics final
    : public CesiumUtility::ExtensibleObject {
  static inline constexpr const char* TypeName = "PropertyStatistics";

  /**
   * @brief The minimum property value occurring in the tileset. Only applicable
   * for single-value numeric types, fixed-length arrays of numeric types,
   * `VECN`, and `MATN` types. For single-value numeric types this is a single
   * number. For fixed-length arrays, `VECN`, and `MATN` types, this is an array
   * of component-wise minimum values. The `normalized` property has no effect
   * on the minimum, which always contains integer values.
   */
  CesiumUtility::JsonValue min;

  /**
   * @brief The maximum property value occurring in the tileset. Only applicable
   * for single-value numeric types, fixed-length arrays of numeric types,
   * `VECN`, and `MATN` types. For single-value numeric types this is a single
   * number. For fixed-length arrays, `VECN`, and `MATN` types, this is an array
   * of component-wise maximum values. The `normalized` property has no effect
   * on the maximum, which always contains integer values.
   */
  CesiumUtility::JsonValue max;

  /**
   * @brief The arithmetic mean of property values occurring in the tileset.
   * Only applicable for single-value numeric types, fixed-length arrays of
   * numeric types, `VECN`, and `MATN` types. For single-value numeric types
   * this is a single number. For fixed-length arrays, `VECN`, and `MATN` types,
   * this is an array of component-wise mean values. The `normalized` property
   * has no effect on the mean, which always contains integer values.
   */
  CesiumUtility::JsonValue mean;

  /**
   * @brief The median of property values occurring in the tileset. Only
   * applicable for single-value numeric types, fixed-length arrays of numeric
   * types, `VECN`, and `MATN` types. For single-value numeric types this is a
   * single number. For fixed-length arrays, `VECN`, and `MATN` types, this is
   * an array of component-wise median values. The `normalized` property has no
   * effect on the median, which always contains integer values.
   */
  CesiumUtility::JsonValue median;

  /**
   * @brief The standard deviation of property values occurring in the tileset.
   * Only applicable for single-value numeric types, fixed-length arrays of
   * numeric types, `VECN`, and `MATN` types. For single-value numeric types
   * this is a single number. For fixed-length arrays, `VECN`, and `MATN` types,
   * this is an array of component-wise standard deviation values. The
   * `normalized` property has no effect on the standard deviation, which always
   * contains integer values.
   */
  CesiumUtility::JsonValue standardDeviation;

  /**
   * @brief The variance of property values occurring in the tileset. Only
   * applicable for single-value numeric types, fixed-length arrays of numeric
   * types, `VECN`, and `MATN` types. For single-value numeric types this is a
   * single number. For fixed-length arrays, `VECN`, and `MATN` types, this is
   * an array of component-wise variance values. The `normalized` property has
   * no effect on the variance, which always contains integer values.
   */
  CesiumUtility::JsonValue variance;

  /**
   * @brief The sum of property values occurring in the tileset. Only applicable
   * for single-value numeric types, fixed-length arrays of numeric types,
   * `VECN`, and `MATN` types. For single-value numeric types this is a single
   * number. For fixed-length arrays, `VECN`, and `MATN` types, this is an array
   * of component-wise sum values. The `normalized` property has no effect on
   * the sum, which always contains integer values.
   */
  CesiumUtility::JsonValue sum;

  /**
   * @brief A dictionary, where each key corresponds to an enum `name` and each
   * value is the number of occurrences of that enum. Only applicable when
   * `componentType` is `ENUM`. For fixed-length arrays, this is an array of
   * component-wise occurrences.
   */
  std::unordered_map<std::string, CesiumUtility::JsonValue> occurrences;
};
} // namespace Cesium3DTiles
