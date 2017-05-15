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
    BuildingRepository repository{};
    Building b1{101, "B-1", {Room {101301, "H-24", Room::Type::LECTURE_HALL}, Room {102683, "021", Room::Type::COMPUTER_LAB}}};
    Building b2{102, "B-2", {}};
    Building c2{103, "C-2", {Room {100110, "208", Room::Type::COMPUTER_LAB}}};

    repository.Add(b1);
    repository.Add(b2);
    repository.Add(c2);

    std::experimental::optional<Building> ob1 = repository[101];

    std::cout<<c2.Id();

    return 0;
}