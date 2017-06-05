//
// Created by Kuba on 16.05.2017.
//

#include <vector>
#include "Algo.h"
#include <iostream?
using namespace std;

int main()
{
    vector v={3,7,1,4};

    algo::Sort(v);

    for (auto a : v) {
        std::cout << a << " ";
    }

    return 0;
}

