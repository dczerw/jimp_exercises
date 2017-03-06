//
// Created by dawid on 06.03.17.
//
#include <string>
#include <iostream>
#include "MultiplicationTable.h"
using namespace std;
void MultiplicationTable(int tab[][10])
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            tab[i][j]=(i+1)*(j+1);
        }
    }
}
void MultiplicationTablePrint(int tab[][10])
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
}

