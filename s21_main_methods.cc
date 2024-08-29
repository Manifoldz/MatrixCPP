#include "s21_matrix_oop.h"

namespace S21 {

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (std::abs(matrix_[i][j] - other.matrix_[i][j]) >= PRECISION) {
        return false;
      }
    }
  }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Rows and cols of both matrix must be equal");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Rows and cols of both matrix must be equal");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument("Cols of left matrix not equal rows of right");
  }
  S21Matrix res(rows_, other.cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      for (int k = 0; k < cols_; ++k) {
        res.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  *this = std::move(res);
}

S21Matrix S21Matrix::Transpose() const {
  S21Matrix res(cols_, rows_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      res.matrix_[j][i] = matrix_[i][j];
    }
  }
  return res;
}

double S21Matrix::Determinant() const {
  if (rows_ != cols_) {
    throw std::invalid_argument("Not square matrix for determinant");
  }
  if (rows_ == 1) {
    return matrix_[0][0];
  }
  bool* ban_rows = new bool[rows_]();
  bool* ban_cols = new bool[cols_]();
  double res = RecursiveDeterminant(ban_rows, ban_cols);
  delete[] ban_rows;
  delete[] ban_cols;
  return res;
}

S21Matrix S21Matrix::CalcComplements() const {
  if (rows_ != cols_) {
    throw std::invalid_argument("Not square matrix for CalcComplements");
  }
  if (rows_ == 1) {
    throw std::invalid_argument("1X1 matrix doesn't have complements");
  }
  S21Matrix res(rows_, cols_);
  bool* ban_rows = new bool[rows_]();
  bool* ban_cols = new bool[cols_]();
  for (int i = 0; i < rows_; ++i) {
    ban_rows[i] = true;
    for (int j = 0; j < cols_; ++j) {
      ban_cols[j] = true;
      // even - positive, odd - negative
      int sign = ((j + i) % 2 == 0) ? 1 : -1;
      res.matrix_[i][j] = sign * RecursiveDeterminant(ban_rows, ban_cols);
      ban_cols[j] = false;
    }
    ban_rows[i] = false;
  }
  delete[] ban_rows;
  delete[] ban_cols;
  return res;
}

S21Matrix S21Matrix::InverseMatrix() const {
  double det = Determinant();
  if (det == 0) {
    throw std::invalid_argument("Determinant is 0. InverseMatrix not exists");
  }
  if (rows_ == 1) {
    S21Matrix res(1, 1);
    res.set_value(0, 0, 1 / det);
    return res;
  }
  S21Matrix res = CalcComplements().Transpose();

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      res.matrix_[i][j] /= det;
    }
  }
  return res;
}

}  // namespace S21