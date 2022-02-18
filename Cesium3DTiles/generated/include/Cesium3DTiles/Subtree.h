// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "Cesium3DTiles/Availability.h"
#include "Cesium3DTiles/Buffer.h"
#include "Cesium3DTiles/BufferView.h"
#include "Cesium3DTiles/Library.h"
#include "Cesium3DTiles/PropertyTable.h"
#include "Cesium3DTiles/SubtreeMetadata.h"

#include <CesiumUtility/ExtensibleObject.h>

#include <optional>
#include <vector>

namespace Cesium3DTiles {
/**
 * @brief An object describing the availability of tiles and content in a
 * subtree, as well as availability of children subtrees. May also store
 * metadata for available tiles and content.
 */
struct CESIUM3DTILES_API Subtree final
    : public CesiumUtility::ExtensibleObject {
  static inline constexpr const char* TypeName = "Subtree";

  /**
   * @brief An array of buffers.
   */
  std::vector<Cesium3DTiles::Buffer> buffers;

  /**
   * @brief An array of buffer views.
   */
  std::vector<Cesium3DTiles::BufferView> bufferViews;

  /**
   * @brief The availability of tiles in the subtree. The availability bitstream
   * is a 1D boolean array where tiles are ordered by their level in the subtree
   * and Morton index within that level. A tile's availability is determined by
   * a single bit, 1 meaning a tile exists at that spatial index, and 0 meaning
   * it does not. The number of elements in the array is `(N^subtreeLevels -
   * 1)/(N - 1)` where N is 4 for subdivision scheme `QUADTREE` and 8 for
   * `OCTREE`. Availability may be stored in a buffer view or as a constant
   * value that applies to all tiles. If a non-root tile's availability is 1 its
   * parent tile's availability must also be 1. `tileAvailability.constant: 0`
   * is disallowed, as subtrees must have at least one tile.
   */
  Cesium3DTiles::Availability tileAvailability;

  /**
   * @brief An array of content availability objects. If the tile has a single
   * content this array will have one element; if the tile has multiple contents
   * - as supported by EXT_multiple_contents and 3D Tiles 1.1 - this array will
   * have multiple elements.
   */
  std::vector<Cesium3DTiles::Availability> contentAvailability;

  /**
   * @brief The availability of children subtrees. The availability bitstream is
   * a 1D boolean array where subtrees are ordered by their Morton index in the
   * level of the tree immediately below the bottom row of the subtree. A child
   * subtree's availability is determined by a single bit, 1 meaning a subtree
   * exists at that spatial index, and 0 meaning it does not. The number of
   * elements in the array is `N^subtreeLevels` where N is 4 for subdivision
   * scheme `QUADTREE` and 8 for `OCTREE`. Availability may be stored in a
   * buffer view or as a constant value that applies to all child subtrees. If
   * availability is 0 for all child subtrees, then the tileset does not
   * subdivide further.
   */
  Cesium3DTiles::Availability childSubtreeAvailability;

  /**
   * @brief A property table containing tile metadata. Tile metadata only exists
   * for available tiles and is tightly packed by increasing tile index. To
   * access individual tile metadata, implementations may create a mapping from
   * tile indices to tile metadata indices.
   */
  std::optional<Cesium3DTiles::PropertyTable> tileMetadata;

  /**
   * @brief An array of property tables containing content metadata. If the tile
   * has a single content this array will have one element; if the tile has
   * multiple contents - as supported by EXT_multiple_contents and 3D Tiles 1.1
   * - this array will have multiple elements. Content metadata only exists for
   * available contents and is tightly packed by increasing tile index. To
   * access individual content metadata, implementations may create a mapping
   * from tile indices to content metadata indices.
   */
  std::vector<Cesium3DTiles::PropertyTable> contentMetadata;

  /**
   * @brief Subtree metadata encoded in JSON.
   */
  std::optional<Cesium3DTiles::SubtreeMetadata> subtreeMetadata;
};
} // namespace Cesium3DTiles
