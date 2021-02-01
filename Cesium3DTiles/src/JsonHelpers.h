#pragma once

#include <optional>
#include "Cesium3DTiles/BoundingVolume.h"
#include <rapidjson/fwd.h>
#include <string>
#include <vector>

namespace Cesium3DTiles {

    class JsonHelpers final {
    public:
        static std::optional<BoundingVolume> getBoundingVolumeProperty(const rapidjson::Value& tileJson, const std::string& key);
        static std::optional<double> getScalarProperty(const rapidjson::Value& tileJson, const std::string& key);
        static std::optional<glm::dmat4x4> getTransformProperty(const rapidjson::Value& tileJson, const std::string& key);

        /**
         * @brief Obtains an array of numbers from the given JSON.
         * 
         * If the property is not found, or is not an array, or does contain 
         * elements that are not numbers, then `std::nullopt` is returned.
         * 
         * If the given expected size is not negative, and the actual size of the 
         * array does not match the expected size, then `nullopt` is returned.
         * 
         * @param json The JSON object.
         * @param expectedSize The expected size of the array.
         * @param key The key (property name) of the array.
         * @return The array, or `nullopt`.
         */
        static std::optional<std::vector<double>> getDoubles(const rapidjson::Value& json, int32_t expectedSize, const std::string& key);
        
        static std::string getStringOrDefault(const rapidjson::Value& json, const std::string& key, const std::string& defaultValue);
        static std::string getStringOrDefault(const rapidjson::Value& json, const std::string& defaultValue);

        static double getDoubleOrDefault(const rapidjson::Value& json, const std::string& key, double defaultValue);
        static double getDoubleOrDefault(const rapidjson::Value& json, double defaultValue);

        static uint32_t getUint32OrDefault(const rapidjson::Value& json, const std::string& key, uint32_t defaultValue);
        static uint32_t getUint32OrDefault(const rapidjson::Value& json, uint32_t defaultValue);

        static std::vector<std::string> getStrings(const rapidjson::Value& json, const std::string& key);
    };

}
