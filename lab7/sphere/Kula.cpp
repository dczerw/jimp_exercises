//
// Created by dawid on 11.04.17.
//

#include "Kula.h"

Kula::Kula()
{
    x_=1;
    y_=1;
    z_=1;
    r_=1;
}

Kula::Kula(double x, double y, double z, double r) : Kolo(x,y,r)
{
    z_=1;
}

double Kula::pole() {
    return (4/3)*M_PI*(pow(r_,3));
}
