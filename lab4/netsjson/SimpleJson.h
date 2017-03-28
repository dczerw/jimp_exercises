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
#include <iomanip>




namespace nets{
    class JsonValue
    {
    private:
        int value_int;
        float value_double;
        std::string value_string;
        bool value_bool;
        std::vector<nets::JsonValue> value_vector;
        std::map<std::string, nets::JsonValue> value_map;

        int type; // 1-int 2-double 3-string 4-bool 5-vector 6-map

    public:

        JsonValue(const int &value);
        JsonValue(const double &value);
        JsonValue(const std::string value);
        JsonValue(const bool &value);
        JsonValue(const std::vector<nets::JsonValue> &value);
        JsonValue(std::map<std::string, nets::JsonValue> value);

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;
    };

    std::string escape(std::string to_escape);
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
