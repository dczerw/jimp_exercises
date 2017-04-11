//
// Created by dawid on 11.04.17.
//

#include "Kolo.h"

Kolo::Kolo()
{
    x_=1;
    y_=1;
    r_=1;
}

Kolo::Kolo(double x, double y, double r)
{
    x_=x;
    y_=y;
    r_=r;
}

double Kolo::pole()
{
    return M_PI*pow(r_,2);
}
