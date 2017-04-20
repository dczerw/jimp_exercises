//
// Created by dawid on 27.03.17.
//

#include "SimpleJson.h"

namespace nets
{
    JsonValue::JsonValue(const int &value) {
    value_int=value;
        type=1;
    }

    JsonValue::JsonValue(const double &value) {
        value_double=value;
        type=2;
    }

    JsonValue::JsonValue(const std::string value) {
        value_string=value;
        int i;
        type=3;

    }

    JsonValue::JsonValue(const bool &value) {
        value_bool=value;
        type=4;

    }


    JsonValue::JsonValue(const std::vector<nets::JsonValue> &value) {
        value_vector=value;
        type=5;
    }

    JsonValue::JsonValue(std::map<std::string, nets::JsonValue> value) {
        value_map=value;
        type=6;
    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {

        auto search = value_map.find(name);
        if (search != value_map.end()) {
            return search->second;
        }

        //return std::experimental::optional<JsonValue>();
    }

    std::string JsonValue::ToString() const {

        switch(type)
        {
            case 1:
            {
                return std::to_string(value_int);
            }
            case 2:
            {
                std::ostringstream strs;
                strs << value_double;
                std::string str = strs.str();
                return str;
            }
            case 3:
            {
                std::string correct;
                int i=0;
                while(value_string[i]!='\0')
                {
                    //correct+=value_string[i];
                    if(value_string[i]=='\\') correct+='\\';
                    if(value_string[i]=='\"') correct+='\\';
                    correct+=value_string[i];
                    i++;
                }


                return correct;
            }
            case 4:
            {
                if(value_bool==true) return "true";
                else return "false";
            }
            case 5:
            {
                std::string correct = "[";
                for(int i=0; i<value_vector.size()-1;i++)
                {
                    correct+=value_vector[i].ToString();
                    correct+=", ";
                }
                correct+=value_vector[value_vector.size()-1].ToString()+"]";
                return correct;
            }
            case 6:
            {
                std::string correct = "[";
                    for (auto n: value_map) {
                        correct += '{';
                        correct += n.first;
                        correct += ':';
                        correct += n.second.ToString();
                        correct += "}, ";
                    }
                    correct.pop_back();
                correct.pop_back();
                correct+="]\0";

                return correct;
            }

            default:
            {
                return "";
            }
        }

        return std::__cxx11::string();
    }
}