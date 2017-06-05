//
// Created by Kuba on 05.06.2017.
//



#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <utility>
#include <chrono>

namespace profiling{
    template<typename T>
        auto TimeRecorder(T arg){
            static std::chrono::high_resolution_clock::time_point time1 = std::chrono::high_resolution_clock::now();
            auto check = (arg)();

            std::chrono::duration<double, std::milli> time_span = std::chrono::high_resolution_clock::now() - time1;

            return std::pair<decltype(check),double>(check, time_span.count());
        }
}
#endif //JIMP_EXERCISES_TIMERECORDER_H
