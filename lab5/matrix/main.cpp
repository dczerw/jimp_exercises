//
// Created by dawid on 02.04.17.
//


#include <iostream>
#include "Matrix.h"

using namespace std;
using namespace algebra;

int main(int argc, char* argv[])
{
    Matrix pauli{{2., 3.}, {1., 4.}};
    cout<<(pauli.Pow(5)).Print();
}