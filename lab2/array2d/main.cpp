//
// Created by dawid on 06.03.17.
//
#include <iostream>
#include "Array2D.h"
#include <string>
using namespace std;

int main() {
    int n_columns, n_rows;
    cout<<"Podaj ilosc kolun"<<endl;
    cin>>n_columns;
    cout<<"Podaj ilosc wierszy"<<endl;
    cin>>n_rows;
    int **tab = Array2D(n_rows,n_columns);
    Print(tab,n_columns,n_rows);
    DeleteArray2D(tab,n_columns,n_rows);
}



