// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "AnimationChannelJsonHandler.h"
#include "AnimationSamplerJsonHandler.h"
#include "ArrayJsonHandler.h"
#include "NamedObjectJsonHandler.h"

namespace CesiumGltf {
  struct Animation;

  class AnimationJsonHandler : public NamedObjectJsonHandler {
  public:
    void reset(IJsonHandler* pHandler, Animation* pObject);
    Animation* getObject();
    virtual void reportWarning(const std::string& warning, std::vector<std::string>&& context = std::vector<std::string>()) override;

    virtual IJsonHandler* Key(const char* str, size_t length, bool copy) override;

  protected:
    IJsonHandler* AnimationKey(const char* str, Animation& o);

  private:

    Animation* _pObject = nullptr;
    ArrayJsonHandler<AnimationChannel, AnimationChannelJsonHandler> _channels;
    ArrayJsonHandler<AnimationSampler, AnimationSamplerJsonHandler> _samplers;
  };
}
