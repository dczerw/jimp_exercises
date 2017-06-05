//
// Created by dawid on 21.03.17.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include "Point.h"

namespace geometry
{
    class Square
    {
    public:

        Square();
        Square(const Point &up_left, const Point &down_left, const Point &up_right, const Point &down_right);
        ~Square();
        double Circumference();
        double Area();

    private:
        Point up_left_;
        Point down_left_;
        Point up_right_;
        Point down_right_;

    };
}

#endif //JIMP_EXERCISES_SQUARE_H
