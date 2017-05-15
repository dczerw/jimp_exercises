//
// Created by Kuba on 09.05.2017.
//

#include <iostream>
#include <sstream>
#include "Serialization.h"
#include <string>

using namespace academia;

int main()
{
    BuildingRepository repository{Building {101, "B-1", {Room {101301, "H-24", Room::Type::LECTURE_HALL},
                                                         Room {102683, "021", Room::Type::COMPUTER_LAB}}}};
    std::stringstream out;
    JsonSerializer serializer(&out);
    std::vector<std::reference_wrapper<const Serializable>> empty;

    repository.StoreAll(&serializer);

    return 0;
}