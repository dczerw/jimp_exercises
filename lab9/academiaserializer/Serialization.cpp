//
// Created by Kuba on 09.05.2017.
//

#include "Serialization.h"

namespace academia
{
    Serializer::Serializer(std::ostream *out) {
    out_=out;
    }

    Room::Room(int id, std::string name, Room::Type type) {
        id_=id;
        name_=name;
        type_=type;

    }

    std::string Room::EnumToString(Room::Type type) {
        return "COMPUTER_LAB";
    }

    void Room::Serialize(Serializer *serializer) {
        serializer->Header("Room");
        serializer->IntegerField("id",id_);
        serializer->StringField("name",name_);
        serializer->StringField("Type",EnumToString(type_));
        serializer->Footer("Room");
    }
}