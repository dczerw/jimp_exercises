//
// Created by dawid on 27.03.17.
//

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "SimpleJson.h"

using ::std::vector;
using ::std::map;
using ::std::cout;
using ::std::endl;
using ::std::string;
using ::nets::JsonValue;
using ::std::literals::operator""s;

int main() {

    nets::JsonValue js{R"(\\\\\\"http:\\\\\\"klmno)"s};
    cout<<js.ToString()<<endl;

}