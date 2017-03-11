//
// Created by dawid on 07.03.17.
//

#include "Polybius.h"

string IntToString(int i)
{
    ostringstream ss;
    ss<<i;
    string str = ss.str();
    return str;
}
int StringToInt(string number)
{
    int i;
    istringstream iss(number);
    iss >> i;
}
string PolybiusCrypt(string message) {
    map <char,int> PolybiusMap = {{'a' , 11},
    {'b' , 12},
    {'c' , 13},
                                  {'d' , 14},
    {'e' , 15},
    {'f' , 21},
    {'g' , 22},
    {'h' , 23},
    {'i' , 24},
    {'j' , 24},
    {'k' , 25},
    {'l' , 31},
    {'m' , 32},
    {'n' , 33},
    {'o' , 34},
    {'p' , 35},
    {'q' , 41},
    {'r' , 42},
    {'s' , 43},
    {'t' , 44},
    {'u' , 45},
    {'v' , 51},
    {'w' , 52},
    {'x' , 53},
    {'y' , 54},
    {'z' , 55},

};
    transform(message.begin(),message.end(),message.begin(), ::tolower);
    int len=message.length();
    string MessageCrypted;
    for(int i=0;i<len;i++)
    {
        if(message[i]==' ') continue;
        MessageCrypted += IntToString(PolybiusMap[message[i]]);
    }
    return MessageCrypted;
}

string PolybiusDecrypt(string message) {
    map <int, char > PolybiusMapDecrypt = {{11 , 'a'},
    {12 , 'b'},
    {13 , 'c'},
    {14 , 'd'},
    {15 , 'e'},
    {21 , 'f'},
    {22 , 'g'},
    {23 , 'h'},
    {24 , 'i'},
    {24 , 'j'},
    {25 , 'k'},
    {31  ,'l'},
    {32  ,'m'},
    {33 , 'n'},
    {34 , 'o'},
    {35 , 'p'},
    {41 , 'q'},
    {42 , 'r'},
    {43 , 's'},
    {44 , 't'},
    {45 , 'u'},
    {51 , 'v'},
    {52 , 'w'},
    {53 , 'x'},
    {54  ,'y'},
    {55 , 'z'},
};
    int len=message.size();
    //if(len==0) return nullptr;

    string MessageDecrypted,helpstring;
    for(int i=0;i<len;i=i+2) {
        helpstring += message[i];
        helpstring += message[i+1];
        MessageDecrypted += PolybiusMapDecrypt[StringToInt(helpstring)];
        cout<<MessageDecrypted;
    }
    return MessageDecrypted;
}