//
// Created by dawid on 06.03.17.
//

#include "Array2D.h"
#include <iostream>
using namespace std;
int **Array2D(int n_rows, int n_columns)
{
    int **tab = new int*[n_columns];


    for(int i=0;i<n_columns;i++)
    {
        tab[i]= new int[n_rows];
    }
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_columns; j++) {
            *(*(tab+j)+i)=(j+1)*(i+1);

        }
    }
    return tab;
}
void Print(int **tab, int n_columns, int n_rows)
{

    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_columns; j++) {
            cout<<*(*(tab+j)+i)<<" ";

        }
        cout<<endl;
    }
}
void DeleteArray2D(int **array, int n_rows, int n_columns)
{
    /*for(int i=0;i<n_columns;i++)
    {
        delete [] array[i];
    }*/
    delete [] array;
}