//
// Created by dawid on 05.06.17.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H
#include <string>

namespace academia{
    class TeacherId{
    public:
        TeacherId(int id);
        TeacherId();
    private:
        int id_;
    };
    class Teacher{
    public:
        Teacher(std::string name,std::string place,TeacherId id);
    private:
        std::string name_;
        std::string place_;
        TeacherId id_;

        
    };
}

#endif //JIMP_EXERCISES_TEACHERHASH_H
