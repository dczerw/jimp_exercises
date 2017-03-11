//
// Created by dawid on 06.03.17.
//

#include "Array2D.h"
#include <iostream>
using namespace std;
int **Array2D(int n_rows, int n_columns)
{
    if(n_rows>0 and n_columns) {

        int **tab = new int *[n_rows], n = 1;


        for (int i = 0; i < n_rows; i++) {
            tab[i] = new int[n_columns];
        }
        for (int i = 0; i < n_rows; i++) {
            for (int j = 0; j < n_columns; j++) {
                tab[i][j] = n;
                n++;

            }
        }
        return tab;
    }
    return NULL;
}
void Print(int **tab, int n_rows, int n_columns)
{

    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_columns; j++) {
            cout<<tab[i][j]<<" ";

        }
        cout<<endl;
    }
}
void DeleteArray2D(int **array, int n_rows, int n_columns)
{
    for(int i=0;i<n_rows;i++)
    {
        delete [] array[i];
    }
    delete [] array;
}