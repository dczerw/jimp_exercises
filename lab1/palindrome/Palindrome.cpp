//
// Created by dawid on 06.03.17.
//

#include "Palindrome.h"
#include <string>
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