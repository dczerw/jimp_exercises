//
// Created by dawid on 21.03.17.
//

#include "Square.h"


namespace geometry
{

    Square::Square() {
    ;
    }

    Square::Square(const Point &up_left, const Point &down_left, const Point &up_right, const Point &down_right)
    {
        double basic_distance = up_left.Distance(down_left);
        if(down_left.Distance(down_right) == basic_distance and down_right.Distance(up_right) == basic_distance and up_right.Distance(up_left)== basic_distance)
        {
            up_left_ = up_left;
            down_left_ = down_left;
            up_right_ = up_right;
            down_right_ = down_right;
        }
        else {
            up_left_.SetX(0);
            down_left_.SetY(0);
            up_right_.SetX(0);
            down_right_.SetX(0);

            up_left_.SetY(0);
            down_left_.SetY(0);
            up_right_.SetY(0);
            down_right_.SetY(0);
        }

    }

    Square::~Square() {
    ;
    }

    double Square::Circumference() {

        double basic_distance = up_left_.Distance(down_left_);
        if(down_left_.Distance(down_right_) == basic_distance and down_right_.Distance(up_right_) == basic_distance and up_right_.Distance(up_left_)== basic_distance) {
            return 4 * (up_left_.Distance(up_right_));
        }
        else return 0;
    }

    double Square::Area() {

        double basic_distance = up_left_.Distance(down_left_);
        if(down_left_.Distance(down_right_) == basic_distance and down_right_.Distance(up_right_) == basic_distance and up_right_.Distance(up_left_)== basic_distance) {
            return (up_left_.Distance(up_right_)) * (up_left_.Distance(up_right_));
        }
        else return 0;
    }
}