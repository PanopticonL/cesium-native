// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "NamedObjectJsonHandler.h"

#include <CesiumGltf/Sampler.h>
#include <CesiumJsonReader/IntegerJsonHandler.h>

namespace CesiumJsonReader {
class ExtensionReaderContext;
}

namespace CesiumGltfReader {
class SamplerJsonHandler : public CesiumGltfReader::NamedObjectJsonHandler {
public:
  using ValueType = CesiumGltf::Sampler;

  SamplerJsonHandler(
      const CesiumJsonReader::ExtensionReaderContext& context) noexcept;
  void reset(IJsonHandler* pParentHandler, CesiumGltf::Sampler* pObject);

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* readObjectKeySampler(
      const std::string& objectType,
      const std::string_view& str,
      CesiumGltf::Sampler& o);

private:
  CesiumGltf::Sampler* _pObject = nullptr;
  CesiumJsonReader::IntegerJsonHandler<int64_t> _magFilter;
  CesiumJsonReader::IntegerJsonHandler<int64_t> _minFilter;
  CesiumJsonReader::IntegerJsonHandler<int64_t> _wrapS;
  CesiumJsonReader::IntegerJsonHandler<int64_t> _wrapT;
};
} // namespace CesiumGltfReader
