//
// Created by Kuba on 21.04.2017.
//

#include "Points.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using ::std::istream;
using ::std::ws;

namespace geometry {

/* Aby wskazać, ze definicja funkcji dotyczy metody danej klasy
  stosujemy tzw. operator zasięgu - "::"
*/

//Specjalna inicjalizacja zmiennych. Zmienne są inicjowane
//nim zostanie wywołane ciało konstruktora
    Point::Point() : x_(0), y_(0) {
        std::cout << "Point - non parametric constructor" << endl;
    }

    Point::Point(double x, double y) {
        std::cout << "Point - parametric constructor" << endl;
        x_ = x;
        y_ = y;
    }

    Point::~Point() {
        std::cout << "Point - destructor";
        std::cout << endl;
    }

    double Point::Distance(const Point &other) const {
        return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2));
    }

    void Point::ToString(ostream *out) const {
        (*out) << "(" << GetX() << ";" << GetY() << ")";
    }

    void Point::SetX(double x) {
        x_ = x;
    }

    void Point::SetY(double y) {
        y_ = y;
    }

    double Point::GetX() const {
        return x_;
    }

    double Point::GetY() const {
        return y_;
    }

    void CheckNextChar(char c, istream *is) {
        int next_char = is->peek();
        if (next_char != c) {
            throw ("invalid character");
        }
        is->ignore();
    }

    void IgnoreWhitespace(istream *is) {
        (*is) >> ws;
    }

    double ReadNumber(istream *is) {
        double d;
        (*is) >> d;
        return d;
    }


// Właściwa definicja, obydwa argumenty funkcji nie
//są zadeklarowane jako const, bo obydwa są modyfikowane
//wewnątrz funkcji (STL nie używa naszej konwencji z przekazywaniem
//przez wskaźnik)
    istream &operator>>(istream &input, Point &p) {
        CheckNextChar('(', &input);
        p.SetX(ReadNumber(&input));
        CheckNextChar(',', &input);
        IgnoreWhitespace(&input);
        p.SetY(ReadNumber(&input));
        CheckNextChar(')', &input);
        return input;      // Umożliwia cin >> a >> b >> c;
    }

    std::ostream &operator<<(std::ostream &out, Point &point)
    {
        out<<"("<<point.GetX()<<","<<point.GetY()<<")";
        return out;
    }

    Point3D::Point3D() {
        std::cout<<"Point 3D - non parametric constructor"<<std::endl;
        x_=1;
        y_=1;
        z_=1;
    }

    Point3D::Point3D(double x, double y, double z) {
        std::cout<<"Point 3D - parametric constructor"<<std::endl;
        x_=x;
        y_=y;
        z_=z;
    }

    Point3D::~Point3D() {
        std::cout<<"Point 3D - destructor"<<std::endl;
    }


    double Point3D::GetY() const {
        return z_;
    }

    double Point3D::Distance(const Point3D &other) const {

        return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2)
                    + pow(GetY()-other.GetY(),2));
    }

}