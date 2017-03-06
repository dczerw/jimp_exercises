//
// Created by dawid on 06.03.17.
//
#include <cstdint>
#include "DoubleBasePalindromes.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
bool is_palindrome(string str){
    int size=str.size();
    const char *characters=str.c_str();
    string rts;
    for(int i=0;i<size;i++)
    {
        rts+=(characters[size-i-1]);
    }
    if(rts==str) return 1;
    else return 0;

}
string IntToString(int i)
{
    ostringstream ss;
    ss<<i;
    string str = ss.str();
    return str;
}
string DecimalToBinary(int i)
{
    string binary;
    while(i>0)
    {
        binary += IntToString(i%2);
        i=(i-i%2)/2;
    }
    return binary;
}
uint64_t DoubleBasePalindromes(int max_value_exculsive)
{
    int sum=0;
    for(int i=1;i<max_value_exculsive;i++)
    {
        if(is_palindrome(IntToString(i)))
        {
            if(is_palindrome(DecimalToBinary(i)))
            {
                sum=sum+i;
            }
            else
            {
                continue;
            }
        } else{
            continue;
        }
    }
    return sum;
}