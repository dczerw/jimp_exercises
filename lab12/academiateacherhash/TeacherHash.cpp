//
// Created by dawid on 05.06.17.
//

#include "TeacherHash.h"
namespace academia{
    TeacherId::TeacherId(int id) {
        id_=id;
    }

    TeacherId::TeacherId() {
        id_=0;
    }

    Teacher::Teacher(std::string name, std::string place, TeacherId id) {
        name_=name;
        place_=place;
        id_=id;
    }

}