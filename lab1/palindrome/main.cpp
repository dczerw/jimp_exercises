//
// Created by dawid on 06.03.17.
//
#include <iostream>
#include "Palindrome.h"
#include <string>
using namespace std;

int main() {
    int ending=0;
    string str;
    while(ending==0) {
        cout<<"1-wyjscie, 0-sprawdz palindrome"<<endl;
        cin>>ending;
           if(ending==0) {
               cout<<"Podaj napis"<<endl;
               cin>>str;
               if (is_palindrome(str)) {
                   cout << "Jest" << endl;
               } else {
                   cout << "Nie jest" << endl;
               }
           }
    }

}


