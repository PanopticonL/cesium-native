#pragma once

#include "CesiumGeometry/AvailabilitySubtree.h"
#include "CesiumGeometry/QuadtreeSubtreeAvailability.h"
#include "CesiumGeometry/QuadtreeTileRectangularRange.h"
#include "CesiumGeospatial/Projection.h"
#include "Tile.h"
#include "TileContext.h"

#include <memory>

namespace Cesium3DTilesSelection {

class Tile;

/**
 * @brief The result of loading a {@link Tile}'s content.
 *
 * The result of loading a tile's content depends on the specific type of
 * content. It can yield a glTF model, a tighter-fitting bounding volume, or
 * knowledge of the availability of tiles deeper in the tile hierarchy. This
 * structure encapsulates all of those possibilities. Each possible result is
 * therefore provided as an `std::optional`.
 *
 * Instances of this structure are created internally, by the
 * {@link TileContentFactory}, when the response to a network request for
 * loading the tile content was received.
 */
struct TileContentLoadResult {
  /**
   * @brief The glTF model to be rendered for this tile.
   *
   * If this is `std::nullopt`, the tile cannot be rendered.
   * If it has a value but the model is blank, the tile can
   * be "rendered", but it is rendered as nothing.
   */
  std::optional<CesiumGltf::Model> model{};

  /**
   * @brief A new context, if any, used by the `childTiles`.
   */
  std::unique_ptr<TileContext> pNewTileContext{};

  /**
   * @brief New child tiles discovered by loading this tile.
   *
   * For example, if the content is an external tileset, this property
   * contains the root tiles of the subtree. This is ignored if the
   * tile already has any child tiles.
   */
  std::optional<std::vector<Tile>> childTiles{};

  /**
   * @brief An improved bounding volume for this tile.
   *
   * If this is available, then it is more accurate than the one the tile used
   * originally.
   */
  std::optional<BoundingVolume> updatedBoundingVolume{};

  /**
   * @brief Available quadtree tiles discovered as a result of loading this
   * tile.
   */
  std::vector<CesiumGeometry::QuadtreeTileRectangularRange>
      availableTileRectangles{};

  /**
   * @brief The result of loading this tile's availability subtree.
   *
   * Only applicable if the implicit tiling extension is being used.
   */
  std::optional<CesiumGeometry::AvailabilitySubtree> subtreeLoadResult;

  /**
   * @brief The HTTP status code received when accessing this content.
   */
  uint16_t httpStatusCode = 0;

  /**
   * @brief The raster overlay projections for which texture coordinates have
   * been generated.
   *
   * For the projection at index `n`, there is a set of texture coordinates
   * with the attribute name `_CESIUMOVERLAY_n` that corresponds to that
   * projection.
   */
  std::vector<CesiumGeospatial::Projection> rasterOverlayProjections;
};

} // namespace Cesium3DTilesSelection
