#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <vector>
#include <iostream>
using namespace std;

class Matrix {
public:
    Matrix();
    Matrix(int rows, int cols);

    int rows() const { return rows_; }
    int cols() const { return cols_; }
    void Print();

// private:
    vector<int> values_;
    int rows_, cols_;
};


ostream& operator<<(ostream& os, const Matrix& m);
Matrix operator+(const Matrix& lm, const Matrix& rm);
Matrix operator-(const Matrix& lm, const Matrix& rm);
Matrix operator*(const Matrix& lm, const Matrix& rm);

Matrix operator+(const int& a, const Matrix& rm);
Matrix operator-(const int& a, const Matrix& rm);
Matrix operator*(const int& a, const Matrix& rm);
Matrix operator+(const Matrix& lm, const int& a);
Matrix operator-(const Matrix& lm, const int& a);
Matrix operator*(const Matrix& lm, const int& a);

#endif

