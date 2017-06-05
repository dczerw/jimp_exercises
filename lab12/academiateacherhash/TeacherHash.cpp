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

    Teacher::Teacher(TeacherId id, std::string name, std::string place) {
        name_=name;
        place_=place;
        id_=id;
    }

    /*int TeacherId::Id() {
        return id_;
    }*/

    TeacherId Teacher::Id() {
        return id_;
    }

    std::string Teacher::Name() {
        return name_;
    }

    std::string Teacher::Department() {
        return place_;
    }

    TeacherId::operator int() const {
        return id_;
    }


    size_t TeacherHash::operator()(const Teacher &teacher) const{
        return 0;
    }

    bool Teacher::operator!=(const Teacher teacher) const{
        return false;
    }

    bool Teacher::operator==(const Teacher teacher) const {
        return true;
    }

}