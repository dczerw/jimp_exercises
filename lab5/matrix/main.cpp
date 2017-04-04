//
// Created by dawid on 02.04.17.
//


#include <iostream>
#include "Matrix.h"

using namespace std;
using namespace algebra;

int main(int argc, char* argv[])
{

    Matrix m1{{1.0i}, {1.0i}};
    Matrix m2{{7. + 1.0i, 3.2}, {0. + 3.9i, 1.0i}, {1.6 + 2.11i, 0. + 3.5i}};
    cout<<m2.Size().first;
    cout<<m2.Size().second;

}