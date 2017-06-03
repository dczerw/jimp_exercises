//
// Created by Kuba on 21.04.2017.
//

#ifndef JIMP_EXERCISES_POINTS_H
#define JIMP_EXERCISES_POINTS_H

#include <iostream>
#include <cmath>
#include <ostream>
#include <iomanip>

namespace geometry
{
    class Point {
    public:
        //Konstruktor bezparametrowy
        Point();

        //Konstruktor parametrowy
        Point(double x, double y);

        //Destruktor wykonywany przed zwolnieniem pamięci
        ~Point();

        //Metody nie modyfikujące stanu obiektu (const na końcu metody)
        //nie mogą zmodyfikować tego obiektu.
        void ToString(std::ostream *out) const;

        double Distance(const Point &other) const;


        //metody akcesorów są publiczne i tylko w przy ich pomocy
        //można się dostać z zewnątrz do pól klasy
        double GetX() const;

        double GetY() const;

        //metody seterów pozwalające zmienić stan obiektu
        //po jego zainicjalizowaniu
        void SetX(double x);

        void SetY(double y);

    protected:
        //w przeciwienstwie do pythona C++ wymaga jawnej deklaracji składowych pól klasy:
        double x_, y_;
    };

    class Point3D : public Point
    {
    private:
        double z_;

    public:
        Point3D();
        Point3D(double x, double y, double z);
        ~Point3D();

        double GetY() const;
        double Distance(const Point3D &other) const;
    };

    std::istream& operator>>(std::istream &is, Point& point);
    std::ostream& operator<<(std::ostream &out, Point& point);
}


#endif //JIMP_EXERCISES_POINTS_H
