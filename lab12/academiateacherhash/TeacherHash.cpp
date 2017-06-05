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

    TeacherId Teacher::Id() const{
        return id_;
    }

    std::string Teacher::Name() const{
        return name_;
    }

    std::string Teacher::Department() const{
        return place_;
    }

    TeacherId::operator int() const {
        return id_;
    }


    size_t TeacherHash::operator()(const Teacher &teacher) const{
        size_t h =   std::hash<int>()(teacher.Id()) + std::hash<std::string>()(teacher.Name()) +
                std::hash<std::string>()(teacher.Department());
        return h;
    }

    bool Teacher::operator!=(const Teacher teacher) const{

        if (name_==teacher.Name() and place_==teacher.Department() and id_==teacher.Id()) return false;
        else true;
    }

    bool Teacher::operator==(const Teacher teacher) const {
        return (name_==teacher.Name() and place_==teacher.Department() and id_==teacher.Id());
    }

}