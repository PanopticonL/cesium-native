#include "NodeWriter.h"
#include <CesiumGltf/Image.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <vector>

const std::vector<double> IDENTITY_4X4 { 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1 };
const std::vector<double> DEFAULT_ROTATION { 0, 0, 0, 1};
const std::vector<double> DEFAULT_SCALE { 1, 1, 1 };
const std::vector<double> DEFAULT_TRANSLATION { 0, 0, 0 };

void CesiumGltf::writeNode(
    const std::vector<Node>& nodes,
    rapidjson::Writer<rapidjson::StringBuffer>& jsonWriter
) {
    if (nodes.empty()) {
        return;
    }

    auto& j = jsonWriter;

    j.Key("nodes");
    j.StartArray();
    for (const auto& node : nodes) {
        j.StartObject();
        if (node.camera >= 0) {
            j.Key("camera");
            j.Int(node.camera);
        }

        if (!node.children.empty()) {
            j.Key("children");
            j.StartArray();
            for (const auto& child : node.children) {
                j.Int(child);
            }
            j.EndArray();
        }

        if (node.skin >= 0) {
            j.Key("skin");
            j.Int(node.skin);
        }

        if (node.matrix != IDENTITY_4X4) {
            assert(node.matrix.size() == IDENTITY_4X4.size());
            j.Key("matrix");
            j.StartArray();
            for (size_t i = 0; i < IDENTITY_4X4.size(); ++i) {
                j.Double(node.matrix[i]);
            }
            j.EndArray();
        } 

        if (node.rotation != DEFAULT_ROTATION) {
            assert(node.rotation.size() == DEFAULT_ROTATION.size());
            j.Key("rotation");
            j.StartArray();
            for (size_t i = 0; i < DEFAULT_ROTATION.size(); ++i) {
                j.Double(node.rotation[i]);
            }
            j.EndArray();
        }

        if (node.scale != DEFAULT_SCALE) {
            assert(node.scale.size() == DEFAULT_SCALE.size());
            j.Key("scale");
            j.StartArray();
            for (size_t i = 0; i < DEFAULT_SCALE.size(); ++i) {
                j.Double(node.scale[i]);
            }
            j.EndArray();
        }

        if (node.translation != DEFAULT_TRANSLATION) {
            assert(node.translation.size() == DEFAULT_TRANSLATION.size());
            j.Key("translation");
            j.StartArray();
            for (size_t i = 0; i < DEFAULT_TRANSLATION.size(); ++i) {
                j.Double(node.translation[i]);
            }
            j.EndArray();
        }

        if (!node.weights.empty()) {
            j.Key("weights");
            j.StartArray();
            for (const auto& weight : node.weights) {
                j.Double(weight);
            }
            j.EndArray();
        }

        if (!node.name.empty()) {
            j.Key("name");
            j.String(node.name.c_str());
        }

        // TODO: extensions / extras

        j.EndObject();
    }
    j.EndArray();
}