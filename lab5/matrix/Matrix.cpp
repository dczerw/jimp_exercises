//
// Created by dawid on 02.04.17.
//

#include "Matrix.h"

namespace algebra
{
    Matrix::Matrix()
    {

    }

    Matrix::Matrix(std::string matlab) {
        int i = 1;
        n_columns_ = 1, n_rows_ = 1;
        std::string number="";

        std::vector<std::complex<double>> objects;

        while (matlab[i] != '\0') {
            if(matlab[i]!=' ' and matlab[i]!= ';' and matlab[i]!=']')
            {
                if(matlab[i]!='i') number+=matlab[i];
                else number+=',';
            }
            if (matlab[i] == ' ' or matlab[i]==';' or matlab[i]==']')
            {
                std::istringstream is('(' + number + ')');
                std::complex<double> c;
                is >> c;
                objects.emplace_back(c);
                if(matlab[i]==' ' or matlab[i]==']') n_columns_++;
                else
                {
                    n_rows_++;
                    i++;
                }
                number="";
            }
            i++;
        }


        n_columns_ = n_columns_/n_rows_;
        //n_rows++;
        n_columns_++;



        matrix_ = new std::complex<double> *[n_rows_];

        for (i = 0; i < n_rows_; i++) {
            matrix_[i] = new std::complex<double>[n_columns_];
        }
        int n=0;
        for (int i = 0; i < n_rows_; i++) {
            for (int j = 0; j < n_columns_; j++) {
                matrix_[i][j] = objects[n];
                //std::cout<<matrix_[i][j]<<std::endl;
                n++;

            }
        }
    }

    Matrix::Matrix(const Matrix &matrix)
    {
        n_rows_=matrix.n_rows_;
        n_columns_=matrix.n_columns_;

        matrix_ = new std::complex<double> *[n_rows_];

        for (int i = 0; i < n_rows_; i++) {
            matrix_[i] = new std::complex<double>[n_columns_];
        }

        for (int i = 0; i < n_rows_; i++) {
            for (int j = 0; j < n_columns_; j++) {
                matrix_[i][j] = matrix.matrix_[i][j];
                //std::cout<<matrix_[i][j]<<std::endl;
            }
        }
    }

    std::complex<double> Matrix::GetElement(int n_rows, int n_columns)
    {
        std::complex<double> element=matrix_[n_rows][n_columns];

        return element;
    }

    void Matrix::SetElement(int n_rows, int n_columns, std::complex<double> element)
    {
        matrix_[n_rows][n_columns]=element;
    }

    Matrix::Matrix(int n_rows, int n_columns)
    {
        n_rows_=n_rows;
        n_columns_=n_columns;
        matrix_ = new std::complex<double> *[n_rows];

        for (int i = 0; i < n_rows; i++)
        {
            matrix_[i] = new std::complex<double>[n_columns];
        }
            for (int i = 0; i < n_rows; i++)
            {
                for (int j = 0; j < n_columns; j++)
                {
                    matrix_[i][j] = 0;
                    //std::cout<<matrix_[i][j]<<std::endl;
                }
            }
    }

    Matrix Matrix::Add(const Matrix &m2) const
    {
        Matrix m3(n_rows_,n_columns_);
        for (int i = 0; i < n_rows_; i++)
        {
            for (int j = 0; j < n_columns_; j++)
            {
                m3.matrix_[i][j] = matrix_[i][j]+ m2.matrix_[i][j];
            }
        }
        return m3;
    }

    Matrix Matrix::Sub(Matrix m2)
    {
        Matrix m3(n_rows_,n_columns_);
        for (int i = 0; i < n_rows_; i++)
        {
            for (int j = 0; j < n_columns_; j++)
            {
                m3.matrix_[i][j] = matrix_[i][j]-m2.matrix_[i][j];
            }
        }
        return m3;
    }

    Matrix Matrix::Mul(std::complex<double> number)
    {
        Matrix m2(n_rows_,n_columns_);
        for (int i = 0; i < n_rows_; i++)
        {
            for (int j = 0; j < n_columns_; j++)
            {
                m2.matrix_[i][j] = matrix_[i][j]*number;
                std::cout<<m2.matrix_[i][j]<<std::endl;
            }
        }
        return m2;
    }

    Matrix Matrix::Mul(Matrix m2)
    {
        if(n_columns_!=m2.n_rows_)
        {
            Matrix answer{};
            std::cout<<"test";
            return answer;
            //return Matrix();
        }
        else
        {
            Matrix m3(n_rows_,m2.n_columns_);
            for(int i=0; i<n_rows_; i++)
            {
                for(int j=0; j<m2.n_columns_; j++)
                {
                    for(int k=0; k<n_columns_; k++)
                    {
                        m3.matrix_[i][j] = m3.matrix_[i][j] + (matrix_[i][k] * m2.matrix_[k][j]);
                    }
                }
            }
            return m3;
        }
    }

    Matrix Matrix::Div(std::complex<double> number)
    {
        Matrix m2(n_rows_,n_columns_);
        for (int i = 0; i < n_rows_; i++)
        {
            for (int j = 0; j < n_columns_; j++)
            {
                m2.matrix_[i][j] = matrix_[i][j]/number;
            }
        }
        return m2;
    }

    std::string Matrix::Print() const
    {
        if(n_columns_==0 and n_rows_==0) return "[]";
        std::string matrix="[";
        for(int i=0; i<n_rows_; i++)
        {
            for(int j=0; j<n_columns_; j++)
            {
                matrix+=algebra::doubleToString(matrix_[i][j].real());
                    matrix+="i"+algebra::doubleToString(matrix_[i][j].imag());
                matrix+=", ";
            }
            matrix.pop_back();
            matrix.pop_back();
            matrix+="; ";
        }
        matrix.pop_back();
        matrix.pop_back();
        matrix.pop_back();
        matrix+=algebra::doubleToString(matrix_[n_rows_-1][n_columns_-1].imag());
        return matrix+"]";
    }

    std::string doubleToString(double value)
    {
        std::ostringstream strs;
        strs << value;
        std::string str = strs.str();
        return str;
    }

    Matrix Matrix::Pow(int value)
    {
        algebra::Matrix m=*this;
        for(int i=1; i<value; i++)
        {
            m=m.Mul(*this);
        }
        return m;
    }

    std::pair<long unsigned int, long unsigned int> Matrix::Size() {
        std::pair<long unsigned int,long unsigned int> size;
        size = {n_rows_, n_columns_};

        return size;
    }

    Matrix::Matrix(const std::initializer_list<std::vector<std::complex<double>>> &elements)
    {
        std::vector<std::complex<double>> objects;
        n_columns_=0;
        n_rows_=0;

        int i=0;
        for(auto k: elements)
        {
            n_rows_++;
            for(auto l: k)
            {
                n_columns_++;
                objects.emplace_back(l);
            }
            i++;
        }

        n_columns_ = n_columns_/n_rows_;
        //n_rows++;
        //n_columns_++;

        //std::cout<<n_columns_<<" "<<n_rows_<<std::endl;

        matrix_ = new std::complex<double> *[n_rows_];

        for (i = 0; i < n_rows_; i++) {
            matrix_[i] = new std::complex<double>[n_columns_];
        }

        int n=0;
        for (int i = 0; i < n_rows_; i++) {
            for (int j = 0; j < n_columns_; j++) {
                matrix_[i][j] = objects[n];
                //std::cout<<matrix_[i][j]<<std::endl;
                n++;
            }
        }

    }

    Matrix::~Matrix()
    {
        for(int i=0;i<n_rows_;i++)
        {
            delete [] matrix_[i];
        }
        delete [] matrix_;
    }
}