#include "s21_matrix_oop.h"

namespace S21 {

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    Deallocation();
    rows_ = other.rows_;
    cols_ = other.cols_;
    Allocation();
    std::memcpy(matrix_[0], other.matrix_[0], rows_ * cols_ * sizeof(double));
  }
  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) {
  if (this != &other) {
    rows_ = other.rows_;
    cols_ = other.cols_;
    std::swap(matrix_, other.matrix_);
  }
  return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Rows and cols of both matrix must be equal");
  }
  S21Matrix res(*this);
  return res += other;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Rows and cols of both matrix must be equal");
  }
  S21Matrix res(*this);
  return res -= other;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  if (cols_ != other.rows_) {
    throw std::invalid_argument("Cols of left matrix not equal rows of right");
  }
  S21Matrix res(*this);
  return res *= other;
}

S21Matrix S21Matrix::operator*(const double num) const {
  S21Matrix res(*this);
  return res *= num;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  return EqMatrix(other);
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

double& S21Matrix::operator()(int i, int j) const {
  if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
    throw std::invalid_argument("Row and column index out of range");
  }
  return matrix_[i][j];
}

S21Matrix operator*(const double lhs, const S21Matrix rhs) { return rhs * lhs; }

}  // namespace S21