//
// Created by dawid on 02.04.17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <complex>
#include <string.h>
#include <vector>
#include <iostream>
#include <sstream>




namespace algebra
{

    class Matrix
    {
    private:

        std::complex<double> **matrix_;
        int n_columns_, n_rows_;


    public:
        Matrix(); // bezparametryczny
        Matrix(std::string matlab); //parametryczny matlab
        Matrix(int n_rows, int n_columns); // parametryczny rozmiar
        Matrix(const Matrix &matrix);
        std::complex<double> GetElement(int n_rows, int n_columns);
        void SetElement(int n_rows, int n_columns, std::complex<double> element);
        std::string print();
        Matrix add(Matrix m2);
        Matrix sub(Matrix m2);
        Matrix mul(std::complex<double> number);
        Matrix mul(Matrix m2);
        Matrix div(std::complex<double> number);
        Matrix pow(int value);
        std::pair<int, int> Size();
    };

    std::string doubleToString(double value);

}

#endif //JIMP_EXERCISES_MATRIX_H
