//
// Created by dawid on 06.03.17.
//

#include "GreatestProduct.h"
int GreatestProduct(const std::vector<int> &numbers, int k)
{
    vector<int> another_vector={0,0,0};
    for(int i=0;i<numbers.size();i++)
    {
        for(int j=i+1;j<numbers.size();j++)
        {
            if(numbers[j]*numbers[i]>another_vector[2]) {
                another_vector[0] = numbers[i];
                another_vector[1] = numbers[j];
                another_vector[2] = numbers[i] * numbers[j];
            }
        }
    }

    return another_vector[2];
}