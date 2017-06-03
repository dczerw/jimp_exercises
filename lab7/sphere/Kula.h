//
// Created by dawid on 11.04.17.
//

#ifndef JIMP_EXERCISES_KULA_H
#define JIMP_EXERCISES_KULA_H

#include "Kolo.h"

class Kula: public Kolo
{
private:
    double z_;
public:
    Kula();
    Kula(double x, double y, double z, double r);
    double pole();


};

#endif //JIMP_EXERCISES_KULA_H
