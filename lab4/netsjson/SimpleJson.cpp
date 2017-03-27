//
// Created by dawid on 27.03.17.
//

#include "SimpleJson.h"

namespace nets
{
    JsonValue::JsonValue(const int &value) {
    value_int=value;
        type="int";
    }

    JsonValue::JsonValue(const float &value) {
        //value_float_.emplace("None", value);
        //type="float";
    }

    JsonValue::JsonValue(const std::string &value) {
        //value_string_.emplace("None", value);
        //type="string";

    }

    JsonValue::JsonValue(const bool &value) {
        //value_bool_.emplace("None", value);
        //type="bool";

    }

    /*JsonValue::JsonValue(const nets::JsonValue &value) {
        value_Json_.emplace(value);
        type="Json";

    }*/

    /*JsonValue::JsonValue(std::map<std::string, nets::JsonValue> &value) {
        value_map_.emplace(value);
        type="map";
    }*/

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {
        return std::experimental::optional<JsonValue>();
    }

    std::string JsonValue::ToString() const {
        std::string new_value;
        if(type=="int")
        {
            std::stringstream ss;
            ss << value_int;
            new_value = ss.str();
        }
        return new_value;
        //return std::__cxx11::string();
    }
}