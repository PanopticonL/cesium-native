// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#include "AssetJsonHandler.h"
#include "CesiumGltf/Asset.h"

#include <cassert>
#include <string>

using namespace CesiumGltf;

void AssetJsonHandler::reset(IJsonHandler* pParent, Asset* pObject) {
  ExtensibleObjectJsonHandler::reset(pParent, pObject);
  this->_pObject = pObject;
}

Asset* AssetJsonHandler::getObject() { return this->_pObject; }

void AssetJsonHandler::reportWarning(
    const std::string& warning,
    std::vector<std::string>&& context) {
  if (this->getCurrentKey()) {
    context.emplace_back(std::string(".") + this->getCurrentKey());
  }
  this->parent()->reportWarning(warning, std::move(context));
}

IJsonHandler*
AssetJsonHandler::Key(const char* str, size_t /*length*/, bool /*copy*/) {
  assert(this->_pObject);
  return this->AssetKey(str, *this->_pObject);
}

IJsonHandler* AssetJsonHandler::AssetKey(const char* str, Asset& o) {
  using namespace std::string_literals;

  if ("copyright"s == str)
    return property("copyright", this->_copyright, o.copyright);
  if ("generator"s == str)
    return property("generator", this->_generator, o.generator);
  if ("version"s == str)
    return property("version", this->_version, o.version);
  if ("minVersion"s == str)
    return property("minVersion", this->_minVersion, o.minVersion);

  return this->ExtensibleObjectKey(str, *this->_pObject);
}
