//
// Created by dawid on 11.04.17.
//

#ifndef JIMP_EXERCISES_KOLO_H
#define JIMP_EXERCISES_KOLO_H

#include <math.h>

class Kolo
{
protected:
    double x_,y_,r_;
public:
    Kolo();
    Kolo(double x, double y, double r);
    double pole();
};

#endif //JIMP_EXERCISES_KOLO_H
