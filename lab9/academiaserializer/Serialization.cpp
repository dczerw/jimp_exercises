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

    void Room::Serialize(Serializer *serializer) {
        ;
    }
}