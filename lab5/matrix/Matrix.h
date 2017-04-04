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
#include <list>



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
        Matrix(const Matrix &matrix); // kopiujacy
        //3. operator przypisania kopiujący
        Matrix &operator=(const Matrix &matrix);
        Matrix &operator=(Matrix &&matrix); // przypisania przenoszacy
        Matrix(const std::initializer_list<std::vector<std::complex<double>>> &elements);
        ~Matrix();
        std::complex<double> GetElement(int n_rows, int n_columns);
        void SetElement(int n_rows, int n_columns, std::complex<double> element);
        std::string Print() const;
        Matrix Add(const Matrix &m2) const;
        Matrix Sub(Matrix m2);
        Matrix Mul(std::complex<double> number);
        Matrix Mul(const Matrix &m2) const;
        Matrix Div(std::complex<double> number);
        Matrix Pow(int value) const;
        std::pair<long unsigned int, long unsigned int> Size() const;
    };

    std::string doubleToString(double value);

}

#endif //JIMP_EXERCISES_MATRIX_H
