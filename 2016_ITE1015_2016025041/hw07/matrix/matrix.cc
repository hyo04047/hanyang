#include "matrix.h"

using namespace std;

Matrix::Matrix() {
    /* Implement Here */
    values_.clear();
    rows_ = 0, cols_ = 0;
}

Matrix::Matrix(int rows, int cols) {
    /* Implement Here */
    values_.clear();
    rows_ = rows, cols_ = cols;
}

void Matrix::Print(void) {
    /* Implement Here */
    for(int i = 0; i < rows_; i++){
        for(int j = 0; j < cols_; j++){
            cout << values_[i * cols_ + j] << " ";
        }
        cout << endl;
    }
}

Matrix operator+(const Matrix& lm, const Matrix& rm) {
    /* Implement Here */
    Matrix temp(lm.rows_, lm.cols_);
    for(int i = 0; i < lm.rows_ * lm.cols_; i++){
    	temp.values_.push_back(lm.values_[i] + rm.values_[i]);
    }
    return temp;
}

Matrix operator-(const Matrix& lm, const Matrix& rm) {
    /* Implement Here */
    Matrix temp(lm.rows_, lm.cols_);
    for(int i = 0; i < lm.rows_ * lm.cols_; i++){
    	temp.values_.push_back(lm.values_[i] - rm.values_[i]);
    }
    return temp;
}

Matrix operator*(const Matrix& lm, const Matrix& rm) {
    /* Implement Here */
    // cout << "*" << endl;
	Matrix temp(lm.rows_, rm.cols_);
	for(int i = 0; i < lm.rows_; i++){
		for(int j = 0; j < rm.cols_; j++){
			// temp.values_.push_back(lm.values_[i * lm.cols_ + j] * rm.values_[j * rm.rows_ + i]);
			int save = 0;
			for(int k = 0; k < lm.cols_; k++){
				save += lm.values_[i * lm.cols_ + k] * rm.values_[k * rm.cols_ + j];
			}
			temp.values_.push_back(save);
		}
	}
	return temp;
}

Matrix operator+(const int& a, const Matrix& rm) {
    /* Implement Here */
    Matrix temp(rm.rows_, rm.cols_);
    for(int i = 0; i < rm.rows_ * rm.cols_; i++){
    	temp.values_.push_back(rm.values_[i] + a);
    }
    return temp;
}

Matrix operator-(const int& a, const Matrix& rm){
    /* Implement Here */
    Matrix temp(rm.rows_, rm.cols_);
    for(int i = 0; i < rm.rows_ * rm.cols_; i++){
    	temp.values_.push_back(a - rm.values_[i]);
    }
    return temp;
}	

Matrix operator*(const int& a, const Matrix& rm) {
    /* Implement Here */
    Matrix temp(rm.rows_, rm.cols_);
    for(int i = 0; i < rm.rows_ * rm.cols_; i++){
    	temp.values_.push_back(a * rm.values_[i]);
    }
    return temp;
}

Matrix operator+(const Matrix& lm, const int& a) {
    /* Implement Here */
    Matrix temp(lm.rows_, lm.cols_);
    for(int i = 0; i < lm.rows_ * lm.cols_; i++){
    	temp.values_.push_back(lm.values_[i] + a);
    }
    return temp;
}

Matrix operator-(const Matrix& lm, const int& a) {
    /* Implement Here */
    Matrix temp(lm.rows_, lm.cols_);
    for(int i = 0; i < lm.rows_ * lm.cols_; i++){
    	temp.values_.push_back(lm.values_[i] - a);
    }
    return temp;
}	

Matrix operator*(const Matrix& lm, const int& a) {
    /* Implement Here */
    Matrix temp(lm.rows_, lm.cols_);
    for(int i = 0; i < lm.rows_ * lm.cols_; i++){
    	temp.values_.push_back(lm.values_[i] * a);
    }
    return temp;
}