//
// Created by dawid on 07.03.17.
//

#include "Polybius.h"
#include <string>

using namespace std;

string PolybiusCrypt(string message)
{
    map<char, int> PolybiusMap = {{'a', 11},
                                  {'b', 12},
                                  {'c', 13},
                                  {'d', 14},
                                  {'e', 15},
                                  {'f', 21},
                                  {'g', 22},
                                  {'h', 23},
                                  {'i', 24},
                                  {'j', 24},
                                  {'k', 25},
                                  {'l', 31},
                                  {'m', 32},
                                  {'n', 33},
                                  {'o', 34},
                                  {'p', 35},
                                  {'q', 41},
                                  {'r', 42},
                                  {'s', 43},
                                  {'t', 44},
                                  {'u', 45},
                                  {'v', 51},
                                  {'w', 52},
                                  {'x', 53},
                                  {'y', 54},
                                  {'z', 55}};


    string crypted;
    transform(message.begin(), message.end(), message.begin(), ::tolower);

    for(int i=0; i<message.length(); i++)
    {
        //cout<<PolybiusMap[message[i]]<<endl;
        if(message[i]==' ') continue;
        crypted+=to_string(PolybiusMap[message[i]]);
    }

    return crypted;
}

string PolybiusDecrypt(string crypted)
{
    string decrypted;
    for(int i=0; i<crypted.size();i+=2 )
    {
        string letter;
        letter+=crypted[i];
        letter+=crypted[i+1];
        decrypted+=PolybiusDecryptLetter(letter);
    }
    decrypted;

    return decrypted;

}

string PolybiusDecryptLetter(string crypted)
{
    map<int, char> PolybiusMapDecrypt = {{11, 'a'},
                                         {12, 'b'},
                                         {13, 'c'},
                                         {14, 'd'},
                                         {15, 'e'},
                                         {21, 'f'},
                                         {22, 'g'},
                                         {23, 'h'},
                                         {24, 'i'},
                                         {24, 'j'},
                                         {25, 'k'},
                                         {31, 'l'},
                                         {32, 'm'},
                                         {33, 'n'},
                                         {34, 'o'},
                                         {35, 'p'},
                                         {41, 'q'},
                                         {42, 'r'},
                                         {43, 's'},
                                         {44, 't'},
                                         {45, 'u'},
                                         {51, 'v'},
                                         {52, 'w'},
                                         {53, 'x'},
                                         {54, 'y'},
                                         {55, 'z'},
    };

    string decrypted;
/*
    for(int i=0; i<crypted.length(); i++)
    {
        //cout<<PolybiusMap[message[i]]<<endl;
        cout<<PolybiusMapDecrypt[crypted[i]];
    }
    */
    //int decrypted_int=atoi(crypted.c_str());
    decrypted+=PolybiusMapDecrypt[atoi(crypted.c_str())];
    return decrypted;
}