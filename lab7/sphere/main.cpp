//
// Created by dawid on 11.04.17.
//

#include "Kolo.h"
#include "Kula.h"
#include <iostream>

int main()
{
    Kula k(0,0,0,10);
    Kolo l = k;
    std::cout<<l.pole()<<std::endl;

    return 0;
}