// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

// forward declarations
namespace CesiumJsonWriter {
class JsonWriter;
class ExtensionWriterContext;
} // namespace CesiumJsonWriter

// forward declarations
namespace CesiumGltf {
struct ExtensionCesiumRTC;
struct ExtensionCesiumTileEdges;
struct ExtensionModelExtFeatureMetadata;
struct ExtensionMeshPrimitiveExtFeatureMetadata;
struct ExtensionExtInstanceFeatures;
struct ExtensionExtMeshFeatures;
struct ExtensionExtMeshGpuInstancing;
struct ExtensionBufferExtMeshoptCompression;
struct ExtensionBufferViewExtMeshoptCompression;
struct ExtensionModelExtStructuralMetadata;
struct ExtensionMeshPrimitiveExtStructuralMetadata;
struct ExtensionKhrDracoMeshCompression;
struct ExtensionKhrMaterialsUnlit;
struct ExtensionKhrMaterialsVariants;
struct ExtensionKhrMaterialsVariantsMeshPrimitive;
struct ExtensionKhrTextureBasisu;
struct ExtensionModelMaxarMeshVariants;
struct ExtensionNodeMaxarMeshVariants;
struct ExtensionKhrTextureTransform;
struct ExtensionTextureWebp;
struct ExtensionNodeMaxarMeshVariantsMappingsValue;
struct ExtensionModelMaxarMeshVariantsValue;
struct ExtensionKhrMaterialsVariantsMeshPrimitiveMappingsValue;
struct ExtensionKhrMaterialsVariantsValue;
struct ExtensionExtStructuralMetadataPropertyAttribute;
struct ExtensionExtStructuralMetadataPropertyAttributeProperty;
struct ExtensionExtStructuralMetadataPropertyTexture;
struct ExtensionExtStructuralMetadataPropertyTextureProperty;
struct TextureInfo;
struct ExtensionExtStructuralMetadataPropertyTable;
struct ExtensionExtStructuralMetadataPropertyTableProperty;
struct ExtensionExtStructuralMetadataSchema;
struct ExtensionExtStructuralMetadataEnum;
struct ExtensionExtStructuralMetadataEnumValue;
struct ExtensionExtStructuralMetadataClass;
struct ExtensionExtStructuralMetadataClassProperty;
struct ExtensionExtMeshFeaturesFeatureId;
struct ExtensionExtMeshFeaturesFeatureIdTexture;
struct ExtensionExtInstanceFeaturesFeatureId;
struct FeatureIDTexture;
struct TextureAccessor;
struct FeatureIDAttribute;
struct FeatureIDs;
struct FeatureTexture;
struct FeatureTable;
struct FeatureTableProperty;
struct Statistics;
struct ClassStatistics;
struct PropertyStatistics;
struct Schema;
struct Enum;
struct EnumValue;
struct Class;
struct ClassProperty;
struct Model;
struct Texture;
struct Skin;
struct Scene;
struct Sampler;
struct Node;
struct Mesh;
struct MeshPrimitive;
struct Material;
struct MaterialOcclusionTextureInfo;
struct MaterialNormalTextureInfo;
struct MaterialPBRMetallicRoughness;
struct Image;
struct Camera;
struct CameraPerspective;
struct CameraOrthographic;
struct BufferView;
struct Buffer;
struct Asset;
struct Animation;
struct AnimationSampler;
struct AnimationChannel;
struct AnimationChannelTarget;
struct Accessor;
struct AccessorSparse;
struct AccessorSparseValues;
struct AccessorSparseIndices;
} // namespace CesiumGltf

namespace CesiumGltfWriter {

struct ExtensionCesiumRTCJsonWriter {
  using ValueType = CesiumGltf::ExtensionCesiumRTC;

  static inline constexpr const char* ExtensionName = "CESIUM_RTC";

  static void write(
      const CesiumGltf::ExtensionCesiumRTC& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionCesiumTileEdgesJsonWriter {
  using ValueType = CesiumGltf::ExtensionCesiumTileEdges;

  static inline constexpr const char* ExtensionName = "CESIUM_tile_edges";

  static void write(
      const CesiumGltf::ExtensionCesiumTileEdges& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionModelExtFeatureMetadataJsonWriter {
  using ValueType = CesiumGltf::ExtensionModelExtFeatureMetadata;

  static inline constexpr const char* ExtensionName = "EXT_feature_metadata";

  static void write(
      const CesiumGltf::ExtensionModelExtFeatureMetadata& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionMeshPrimitiveExtFeatureMetadataJsonWriter {
  using ValueType = CesiumGltf::ExtensionMeshPrimitiveExtFeatureMetadata;

  static inline constexpr const char* ExtensionName = "EXT_feature_metadata";

  static void write(
      const CesiumGltf::ExtensionMeshPrimitiveExtFeatureMetadata& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionExtInstanceFeaturesJsonWriter {
  using ValueType = CesiumGltf::ExtensionExtInstanceFeatures;

  static inline constexpr const char* ExtensionName = "EXT_instance_features";

  static void write(
      const CesiumGltf::ExtensionExtInstanceFeatures& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionExtMeshFeaturesJsonWriter {
  using ValueType = CesiumGltf::ExtensionExtMeshFeatures;

  static inline constexpr const char* ExtensionName = "EXT_mesh_features";

  static void write(
      const CesiumGltf::ExtensionExtMeshFeatures& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionExtMeshGpuInstancingJsonWriter {
  using ValueType = CesiumGltf::ExtensionExtMeshGpuInstancing;

  static inline constexpr const char* ExtensionName = "EXT_mesh_gpu_instancing";

  static void write(
      const CesiumGltf::ExtensionExtMeshGpuInstancing& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionBufferExtMeshoptCompressionJsonWriter {
  using ValueType = CesiumGltf::ExtensionBufferExtMeshoptCompression;

  static inline constexpr const char* ExtensionName = "EXT_meshopt_compression";

  static void write(
      const CesiumGltf::ExtensionBufferExtMeshoptCompression& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionBufferViewExtMeshoptCompressionJsonWriter {
  using ValueType = CesiumGltf::ExtensionBufferViewExtMeshoptCompression;

  static inline constexpr const char* ExtensionName = "EXT_meshopt_compression";

  static void write(
      const CesiumGltf::ExtensionBufferViewExtMeshoptCompression& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionModelExtStructuralMetadataJsonWriter {
  using ValueType = CesiumGltf::ExtensionModelExtStructuralMetadata;

  static inline constexpr const char* ExtensionName = "EXT_structural_metadata";

  static void write(
      const CesiumGltf::ExtensionModelExtStructuralMetadata& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionMeshPrimitiveExtStructuralMetadataJsonWriter {
  using ValueType = CesiumGltf::ExtensionMeshPrimitiveExtStructuralMetadata;

  static inline constexpr const char* ExtensionName = "EXT_structural_metadata";

  static void write(
      const CesiumGltf::ExtensionMeshPrimitiveExtStructuralMetadata& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionKhrDracoMeshCompressionJsonWriter {
  using ValueType = CesiumGltf::ExtensionKhrDracoMeshCompression;

  static inline constexpr const char* ExtensionName =
      "KHR_draco_mesh_compression";

  static void write(
      const CesiumGltf::ExtensionKhrDracoMeshCompression& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionKhrMaterialsUnlitJsonWriter {
  using ValueType = CesiumGltf::ExtensionKhrMaterialsUnlit;

  static inline constexpr const char* ExtensionName = "KHR_materials_unlit";

  static void write(
      const CesiumGltf::ExtensionKhrMaterialsUnlit& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionKhrMaterialsVariantsJsonWriter {
  using ValueType = CesiumGltf::ExtensionKhrMaterialsVariants;

  static inline constexpr const char* ExtensionName = "KHR_materials_variants";

  static void write(
      const CesiumGltf::ExtensionKhrMaterialsVariants& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionKhrMaterialsVariantsMeshPrimitiveJsonWriter {
  using ValueType = CesiumGltf::ExtensionKhrMaterialsVariantsMeshPrimitive;

  static inline constexpr const char* ExtensionName = "KHR_materials_variants";

  static void write(
      const CesiumGltf::ExtensionKhrMaterialsVariantsMeshPrimitive& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionKhrTextureBasisuJsonWriter {
  using ValueType = CesiumGltf::ExtensionKhrTextureBasisu;

  static inline constexpr const char* ExtensionName = "KHR_texture_basisu";

  static void write(
      const CesiumGltf::ExtensionKhrTextureBasisu& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionModelMaxarMeshVariantsJsonWriter {
  using ValueType = CesiumGltf::ExtensionModelMaxarMeshVariants;

  static inline constexpr const char* ExtensionName = "MAXAR_mesh_variants";

  static void write(
      const CesiumGltf::ExtensionModelMaxarMeshVariants& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionNodeMaxarMeshVariantsJsonWriter {
  using ValueType = CesiumGltf::ExtensionNodeMaxarMeshVariants;

  static inline constexpr const char* ExtensionName = "MAXAR_mesh_variants";

  static void write(
      const CesiumGltf::ExtensionNodeMaxarMeshVariants& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionKhrTextureTransformJsonWriter {
  using ValueType = CesiumGltf::ExtensionKhrTextureTransform;

  static inline constexpr const char* ExtensionName = "KHR_texture_transform";

  static void write(
      const CesiumGltf::ExtensionKhrTextureTransform& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionTextureWebpJsonWriter {
  using ValueType = CesiumGltf::ExtensionTextureWebp;

  static inline constexpr const char* ExtensionName = "EXT_texture_webp";

  static void write(
      const CesiumGltf::ExtensionTextureWebp& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionNodeMaxarMeshVariantsMappingsValueJsonWriter {
  using ValueType = CesiumGltf::ExtensionNodeMaxarMeshVariantsMappingsValue;

  static void write(
      const CesiumGltf::ExtensionNodeMaxarMeshVariantsMappingsValue& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionModelMaxarMeshVariantsValueJsonWriter {
  using ValueType = CesiumGltf::ExtensionModelMaxarMeshVariantsValue;

  static void write(
      const CesiumGltf::ExtensionModelMaxarMeshVariantsValue& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionKhrMaterialsVariantsMeshPrimitiveMappingsValueJsonWriter {
  using ValueType =
      CesiumGltf::ExtensionKhrMaterialsVariantsMeshPrimitiveMappingsValue;

  static void write(
      const CesiumGltf::ExtensionKhrMaterialsVariantsMeshPrimitiveMappingsValue&
          obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionKhrMaterialsVariantsValueJsonWriter {
  using ValueType = CesiumGltf::ExtensionKhrMaterialsVariantsValue;

  static void write(
      const CesiumGltf::ExtensionKhrMaterialsVariantsValue& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionExtStructuralMetadataPropertyAttributeJsonWriter {
  using ValueType = CesiumGltf::ExtensionExtStructuralMetadataPropertyAttribute;

  static void write(
      const CesiumGltf::ExtensionExtStructuralMetadataPropertyAttribute& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionExtStructuralMetadataPropertyAttributePropertyJsonWriter {
  using ValueType =
      CesiumGltf::ExtensionExtStructuralMetadataPropertyAttributeProperty;

  static void write(
      const CesiumGltf::ExtensionExtStructuralMetadataPropertyAttributeProperty&
          obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionExtStructuralMetadataPropertyTextureJsonWriter {
  using ValueType = CesiumGltf::ExtensionExtStructuralMetadataPropertyTexture;

  static void write(
      const CesiumGltf::ExtensionExtStructuralMetadataPropertyTexture& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionExtStructuralMetadataPropertyTexturePropertyJsonWriter {
  using ValueType =
      CesiumGltf::ExtensionExtStructuralMetadataPropertyTextureProperty;

  static void write(
      const CesiumGltf::ExtensionExtStructuralMetadataPropertyTextureProperty&
          obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct TextureInfoJsonWriter {
  using ValueType = CesiumGltf::TextureInfo;

  static void write(
      const CesiumGltf::TextureInfo& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionExtStructuralMetadataPropertyTableJsonWriter {
  using ValueType = CesiumGltf::ExtensionExtStructuralMetadataPropertyTable;

  static void write(
      const CesiumGltf::ExtensionExtStructuralMetadataPropertyTable& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionExtStructuralMetadataPropertyTablePropertyJsonWriter {
  using ValueType =
      CesiumGltf::ExtensionExtStructuralMetadataPropertyTableProperty;

  static void write(
      const CesiumGltf::ExtensionExtStructuralMetadataPropertyTableProperty&
          obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionExtStructuralMetadataSchemaJsonWriter {
  using ValueType = CesiumGltf::ExtensionExtStructuralMetadataSchema;

  static void write(
      const CesiumGltf::ExtensionExtStructuralMetadataSchema& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionExtStructuralMetadataEnumJsonWriter {
  using ValueType = CesiumGltf::ExtensionExtStructuralMetadataEnum;

  static void write(
      const CesiumGltf::ExtensionExtStructuralMetadataEnum& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionExtStructuralMetadataEnumValueJsonWriter {
  using ValueType = CesiumGltf::ExtensionExtStructuralMetadataEnumValue;

  static void write(
      const CesiumGltf::ExtensionExtStructuralMetadataEnumValue& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionExtStructuralMetadataClassJsonWriter {
  using ValueType = CesiumGltf::ExtensionExtStructuralMetadataClass;

  static void write(
      const CesiumGltf::ExtensionExtStructuralMetadataClass& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionExtStructuralMetadataClassPropertyJsonWriter {
  using ValueType = CesiumGltf::ExtensionExtStructuralMetadataClassProperty;

  static void write(
      const CesiumGltf::ExtensionExtStructuralMetadataClassProperty& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionExtMeshFeaturesFeatureIdJsonWriter {
  using ValueType = CesiumGltf::ExtensionExtMeshFeaturesFeatureId;

  static void write(
      const CesiumGltf::ExtensionExtMeshFeaturesFeatureId& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionExtMeshFeaturesFeatureIdTextureJsonWriter {
  using ValueType = CesiumGltf::ExtensionExtMeshFeaturesFeatureIdTexture;

  static void write(
      const CesiumGltf::ExtensionExtMeshFeaturesFeatureIdTexture& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionExtInstanceFeaturesFeatureIdJsonWriter {
  using ValueType = CesiumGltf::ExtensionExtInstanceFeaturesFeatureId;

  static void write(
      const CesiumGltf::ExtensionExtInstanceFeaturesFeatureId& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct FeatureIDTextureJsonWriter {
  using ValueType = CesiumGltf::FeatureIDTexture;

  static void write(
      const CesiumGltf::FeatureIDTexture& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct TextureAccessorJsonWriter {
  using ValueType = CesiumGltf::TextureAccessor;

  static void write(
      const CesiumGltf::TextureAccessor& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct FeatureIDAttributeJsonWriter {
  using ValueType = CesiumGltf::FeatureIDAttribute;

  static void write(
      const CesiumGltf::FeatureIDAttribute& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct FeatureIDsJsonWriter {
  using ValueType = CesiumGltf::FeatureIDs;

  static void write(
      const CesiumGltf::FeatureIDs& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct FeatureTextureJsonWriter {
  using ValueType = CesiumGltf::FeatureTexture;

  static void write(
      const CesiumGltf::FeatureTexture& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct FeatureTableJsonWriter {
  using ValueType = CesiumGltf::FeatureTable;

  static void write(
      const CesiumGltf::FeatureTable& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct FeatureTablePropertyJsonWriter {
  using ValueType = CesiumGltf::FeatureTableProperty;

  static void write(
      const CesiumGltf::FeatureTableProperty& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct StatisticsJsonWriter {
  using ValueType = CesiumGltf::Statistics;

  static void write(
      const CesiumGltf::Statistics& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ClassStatisticsJsonWriter {
  using ValueType = CesiumGltf::ClassStatistics;

  static void write(
      const CesiumGltf::ClassStatistics& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct PropertyStatisticsJsonWriter {
  using ValueType = CesiumGltf::PropertyStatistics;

  static void write(
      const CesiumGltf::PropertyStatistics& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct SchemaJsonWriter {
  using ValueType = CesiumGltf::Schema;

  static void write(
      const CesiumGltf::Schema& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct EnumJsonWriter {
  using ValueType = CesiumGltf::Enum;

  static void write(
      const CesiumGltf::Enum& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct EnumValueJsonWriter {
  using ValueType = CesiumGltf::EnumValue;

  static void write(
      const CesiumGltf::EnumValue& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ClassJsonWriter {
  using ValueType = CesiumGltf::Class;

  static void write(
      const CesiumGltf::Class& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ClassPropertyJsonWriter {
  using ValueType = CesiumGltf::ClassProperty;

  static void write(
      const CesiumGltf::ClassProperty& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ModelJsonWriter {
  using ValueType = CesiumGltf::Model;

  static void write(
      const CesiumGltf::Model& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct TextureJsonWriter {
  using ValueType = CesiumGltf::Texture;

  static void write(
      const CesiumGltf::Texture& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct SkinJsonWriter {
  using ValueType = CesiumGltf::Skin;

  static void write(
      const CesiumGltf::Skin& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct SceneJsonWriter {
  using ValueType = CesiumGltf::Scene;

  static void write(
      const CesiumGltf::Scene& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct SamplerJsonWriter {
  using ValueType = CesiumGltf::Sampler;

  static void write(
      const CesiumGltf::Sampler& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct NodeJsonWriter {
  using ValueType = CesiumGltf::Node;

  static void write(
      const CesiumGltf::Node& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct MeshJsonWriter {
  using ValueType = CesiumGltf::Mesh;

  static void write(
      const CesiumGltf::Mesh& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct MeshPrimitiveJsonWriter {
  using ValueType = CesiumGltf::MeshPrimitive;

  static void write(
      const CesiumGltf::MeshPrimitive& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct MaterialJsonWriter {
  using ValueType = CesiumGltf::Material;

  static void write(
      const CesiumGltf::Material& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct MaterialOcclusionTextureInfoJsonWriter {
  using ValueType = CesiumGltf::MaterialOcclusionTextureInfo;

  static void write(
      const CesiumGltf::MaterialOcclusionTextureInfo& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct MaterialNormalTextureInfoJsonWriter {
  using ValueType = CesiumGltf::MaterialNormalTextureInfo;

  static void write(
      const CesiumGltf::MaterialNormalTextureInfo& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct MaterialPBRMetallicRoughnessJsonWriter {
  using ValueType = CesiumGltf::MaterialPBRMetallicRoughness;

  static void write(
      const CesiumGltf::MaterialPBRMetallicRoughness& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ImageJsonWriter {
  using ValueType = CesiumGltf::Image;

  static void write(
      const CesiumGltf::Image& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct CameraJsonWriter {
  using ValueType = CesiumGltf::Camera;

  static void write(
      const CesiumGltf::Camera& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct CameraPerspectiveJsonWriter {
  using ValueType = CesiumGltf::CameraPerspective;

  static void write(
      const CesiumGltf::CameraPerspective& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct CameraOrthographicJsonWriter {
  using ValueType = CesiumGltf::CameraOrthographic;

  static void write(
      const CesiumGltf::CameraOrthographic& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct BufferViewJsonWriter {
  using ValueType = CesiumGltf::BufferView;

  static void write(
      const CesiumGltf::BufferView& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct BufferJsonWriter {
  using ValueType = CesiumGltf::Buffer;

  static void write(
      const CesiumGltf::Buffer& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct AssetJsonWriter {
  using ValueType = CesiumGltf::Asset;

  static void write(
      const CesiumGltf::Asset& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct AnimationJsonWriter {
  using ValueType = CesiumGltf::Animation;

  static void write(
      const CesiumGltf::Animation& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct AnimationSamplerJsonWriter {
  using ValueType = CesiumGltf::AnimationSampler;

  static void write(
      const CesiumGltf::AnimationSampler& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct AnimationChannelJsonWriter {
  using ValueType = CesiumGltf::AnimationChannel;

  static void write(
      const CesiumGltf::AnimationChannel& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct AnimationChannelTargetJsonWriter {
  using ValueType = CesiumGltf::AnimationChannelTarget;

  static void write(
      const CesiumGltf::AnimationChannelTarget& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct AccessorJsonWriter {
  using ValueType = CesiumGltf::Accessor;

  static void write(
      const CesiumGltf::Accessor& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct AccessorSparseJsonWriter {
  using ValueType = CesiumGltf::AccessorSparse;

  static void write(
      const CesiumGltf::AccessorSparse& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct AccessorSparseValuesJsonWriter {
  using ValueType = CesiumGltf::AccessorSparseValues;

  static void write(
      const CesiumGltf::AccessorSparseValues& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct AccessorSparseIndicesJsonWriter {
  using ValueType = CesiumGltf::AccessorSparseIndices;

  static void write(
      const CesiumGltf::AccessorSparseIndices& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

} // namespace CesiumGltfWriter
