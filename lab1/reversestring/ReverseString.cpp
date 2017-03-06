//
// Created by dawid on 06.03.17.
//
#include <string>
#include <iostream>
#include "ReverseString.h"
using namespace std;

string reverse(string str)
{
    int size=str.size();
    const char *characters=str.c_str();
    string rts;
    for(int i=0;i<size;i++)
    {
        rts+=(characters[size-i-1]);
    }
    return rts;
}