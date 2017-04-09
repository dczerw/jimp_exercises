//
// Created by dawid on 04.04.17.
//

#include "Point.h"
#include <cmath>
#include <ostream>
#include "Point.h"
#include <iomanip>
#include <iostream>

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
        //std::cout << "Konstruktor bezparametrowy" << endl;
    }

    Point::Point(double x, double y) {
        //std::cout << "Konstruktor parametrowy" << endl;
        x_ = x;
        y_ = y;
    }

    Point::~Point() {
        //std::cout << "Destruktor! Nic nie robie, bo nie musze zwalniać pamięci!";
        //std::cout << endl;
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

//Helper functions:
    void CheckNextChar(char c, istream *is) {
        int next_char = is->peek();
        //if (next_char != c) {
        //    throw runtime_error("invalid character");
        //}
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
}