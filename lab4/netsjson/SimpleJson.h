//
// Created by dawid on 27.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <map>
#include <sstream>
#include <vector>


namespace nets{
    class JsonValue
    {
    private:
        /*std::map<std::string, int> value_int_;
        std::map<std::string, float> value_float_;
        std::map<std::string, std::string> value_string_;
        std::map<std::string, bool> value_bool_;
        std::map<std::string, nets::JsonValue> value_Json_;
        std::map<std::string, std::map<std::string, nets::JsonValue>> value_map_;
         */
        int value_int;
        float value_float;
        std::string value_string;
        bool value_bool;
        std::vector<JsonValue>

    public:

        JsonValue(const int &value);
        JsonValue(const float &value);
        JsonValue(const std::string &value);
        JsonValue(const bool &value);
        JsonValue(const nets::JsonValue& value);
        JsonValue(std::map<std::string, nets::JsonValue> &value);




        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;
    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
