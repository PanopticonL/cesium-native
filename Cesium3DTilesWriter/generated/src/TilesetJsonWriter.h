// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

// forward declarations
namespace CesiumJsonWriter {
class JsonWriter;
class ExtensionWriterContext;
} // namespace CesiumJsonWriter

// forward declarations
namespace Cesium3DTiles {
struct Extension3dTilesContentGltf;
struct Extension3dTilesMultipleContents;
struct Extension3dTilesBoundingVolumeS2;
struct Extension3dTilesImplicitTiling;
struct Extension3dTilesImplicitTilingExtension3dTilesMultipleContents;
struct Extension3dTilesImplicitTilingExtension3dTilesMetadata;
struct ExtensionTileset3dTilesMetadata;
struct ExtensionTile3dTilesMetadata;
struct ExtensionContent3dTilesMetadata;
struct MetadataEntity;
struct TilesetMetadata;
struct GroupMetadata;
struct Statistics;
struct ClassStatistics;
struct PropertyStatistics;
struct Schema;
struct Enum;
struct EnumValue;
struct Class;
struct Property;
struct SubtreeMetadataProperty;
struct Availability;
struct Subtrees;
struct Content;
struct BoundingVolume;
struct Subtree;
struct BufferView;
struct Buffer;
struct Tileset;
struct Tile;
struct Properties;
struct Asset;
} // namespace Cesium3DTiles

namespace Cesium3DTilesWriter {

struct Extension3dTilesContentGltfJsonWriter {
  using ValueType = Cesium3DTiles::Extension3dTilesContentGltf;

  static inline constexpr const char* ExtensionName = "3DTILES_content_gltf";

  static void write(
      const Cesium3DTiles::Extension3dTilesContentGltf& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct Extension3dTilesMultipleContentsJsonWriter {
  using ValueType = Cesium3DTiles::Extension3dTilesMultipleContents;

  static inline constexpr const char* ExtensionName =
      "3DTILES_multiple_contents";

  static void write(
      const Cesium3DTiles::Extension3dTilesMultipleContents& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct Extension3dTilesBoundingVolumeS2JsonWriter {
  using ValueType = Cesium3DTiles::Extension3dTilesBoundingVolumeS2;

  static inline constexpr const char* ExtensionName =
      "3DTILES_bounding_volume_S2";

  static void write(
      const Cesium3DTiles::Extension3dTilesBoundingVolumeS2& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct Extension3dTilesImplicitTilingJsonWriter {
  using ValueType = Cesium3DTiles::Extension3dTilesImplicitTiling;

  static inline constexpr const char* ExtensionName = "3DTILES_implicit_tiling";

  static void write(
      const Cesium3DTiles::Extension3dTilesImplicitTiling& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct
    Extension3dTilesImplicitTilingExtension3dTilesMultipleContentsJsonWriter {
  using ValueType = Cesium3DTiles::
      Extension3dTilesImplicitTilingExtension3dTilesMultipleContents;

  static inline constexpr const char* ExtensionName =
      "3DTILES_multiple_contents";

  static void write(
      const Cesium3DTiles::
          Extension3dTilesImplicitTilingExtension3dTilesMultipleContents& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct Extension3dTilesImplicitTilingExtension3dTilesMetadataJsonWriter {
  using ValueType =
      Cesium3DTiles::Extension3dTilesImplicitTilingExtension3dTilesMetadata;

  static inline constexpr const char* ExtensionName = "3DTILES_metadata";

  static void write(
      const Cesium3DTiles::
          Extension3dTilesImplicitTilingExtension3dTilesMetadata& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionTileset3dTilesMetadataJsonWriter {
  using ValueType = Cesium3DTiles::ExtensionTileset3dTilesMetadata;

  static inline constexpr const char* ExtensionName = "3DTILES_metadata";

  static void write(
      const Cesium3DTiles::ExtensionTileset3dTilesMetadata& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionTile3dTilesMetadataJsonWriter {
  using ValueType = Cesium3DTiles::ExtensionTile3dTilesMetadata;

  static inline constexpr const char* ExtensionName = "3DTILES_metadata";

  static void write(
      const Cesium3DTiles::ExtensionTile3dTilesMetadata& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionContent3dTilesMetadataJsonWriter {
  using ValueType = Cesium3DTiles::ExtensionContent3dTilesMetadata;

  static inline constexpr const char* ExtensionName = "3DTILES_metadata";

  static void write(
      const Cesium3DTiles::ExtensionContent3dTilesMetadata& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct MetadataEntityJsonWriter {
  using ValueType = Cesium3DTiles::MetadataEntity;

  static void write(
      const Cesium3DTiles::MetadataEntity& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct TilesetMetadataJsonWriter {
  using ValueType = Cesium3DTiles::TilesetMetadata;

  static void write(
      const Cesium3DTiles::TilesetMetadata& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct GroupMetadataJsonWriter {
  using ValueType = Cesium3DTiles::GroupMetadata;

  static void write(
      const Cesium3DTiles::GroupMetadata& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct StatisticsJsonWriter {
  using ValueType = Cesium3DTiles::Statistics;

  static void write(
      const Cesium3DTiles::Statistics& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ClassStatisticsJsonWriter {
  using ValueType = Cesium3DTiles::ClassStatistics;

  static void write(
      const Cesium3DTiles::ClassStatistics& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct PropertyStatisticsJsonWriter {
  using ValueType = Cesium3DTiles::PropertyStatistics;

  static void write(
      const Cesium3DTiles::PropertyStatistics& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct SchemaJsonWriter {
  using ValueType = Cesium3DTiles::Schema;

  static void write(
      const Cesium3DTiles::Schema& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct EnumJsonWriter {
  using ValueType = Cesium3DTiles::Enum;

  static void write(
      const Cesium3DTiles::Enum& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct EnumValueJsonWriter {
  using ValueType = Cesium3DTiles::EnumValue;

  static void write(
      const Cesium3DTiles::EnumValue& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ClassJsonWriter {
  using ValueType = Cesium3DTiles::Class;

  static void write(
      const Cesium3DTiles::Class& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct PropertyJsonWriter {
  using ValueType = Cesium3DTiles::Property;

  static void write(
      const Cesium3DTiles::Property& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct SubtreeMetadataPropertyJsonWriter {
  using ValueType = Cesium3DTiles::SubtreeMetadataProperty;

  static void write(
      const Cesium3DTiles::SubtreeMetadataProperty& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct AvailabilityJsonWriter {
  using ValueType = Cesium3DTiles::Availability;

  static void write(
      const Cesium3DTiles::Availability& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct SubtreesJsonWriter {
  using ValueType = Cesium3DTiles::Subtrees;

  static void write(
      const Cesium3DTiles::Subtrees& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ContentJsonWriter {
  using ValueType = Cesium3DTiles::Content;

  static void write(
      const Cesium3DTiles::Content& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct BoundingVolumeJsonWriter {
  using ValueType = Cesium3DTiles::BoundingVolume;

  static void write(
      const Cesium3DTiles::BoundingVolume& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct SubtreeJsonWriter {
  using ValueType = Cesium3DTiles::Subtree;

  static void write(
      const Cesium3DTiles::Subtree& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct BufferViewJsonWriter {
  using ValueType = Cesium3DTiles::BufferView;

  static void write(
      const Cesium3DTiles::BufferView& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct BufferJsonWriter {
  using ValueType = Cesium3DTiles::Buffer;

  static void write(
      const Cesium3DTiles::Buffer& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct TilesetJsonWriter {
  using ValueType = Cesium3DTiles::Tileset;

  static void write(
      const Cesium3DTiles::Tileset& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct TileJsonWriter {
  using ValueType = Cesium3DTiles::Tile;

  static void write(
      const Cesium3DTiles::Tile& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct PropertiesJsonWriter {
  using ValueType = Cesium3DTiles::Properties;

  static void write(
      const Cesium3DTiles::Properties& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct AssetJsonWriter {
  using ValueType = Cesium3DTiles::Asset;

  static void write(
      const Cesium3DTiles::Asset& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

} // namespace Cesium3DTilesWriter
