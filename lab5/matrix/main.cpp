//
// Created by dawid on 02.04.17.
//


#include <iostream>
#include "Matrix.h"

using namespace std;

int main(int argc, char* argv[]){

    algebra::Matrix m1("[1i3 2i5 3; 3 4 5; 6 7 8]");
    algebra::Matrix m2("[3 2 1; 5 4 3; 7 6 5]");

    cout << "Macierz pierwsza: " << endl << m1.print() << endl;
    cout << "Macierz druga: " << endl << m2.print() << endl;

    cout << "Dodawanie" << endl << (m1.add(m2)).print() << endl;
    cout << "Odejmowanie" << endl << (m1.sub(m2)).print() << endl;
    cout << "Mnożenie" << endl << (m1.mul(m2)).print() << endl;
    //cout << "Dzielenie" << (m1.div(m2)).print() << endl;
    cout << "Potęgowanie" << endl << (m1.pow(2)).print() << endl;
    cout << "Potęgowanie" << endl << (m2.pow(2)).print() << endl;

}