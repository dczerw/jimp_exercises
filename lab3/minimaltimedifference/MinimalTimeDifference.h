//
// Created by dawid on 14.03.17.
//



#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
#include <iostream>
#include<string>
using namespace std;

#ifndef JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
#define JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
namespace minimaltimedifference {
    unsigned int ToMinutes(std::string time_HH_MM);

    unsigned int MinimalTimeDifference(std::vector<std::string> times);
    int StringToInt(string time);
}
#endif //JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
