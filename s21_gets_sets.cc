#include "s21_matrix_oop.h"

namespace S21 {

int S21Matrix::get_rows() const { return rows_; }

int S21Matrix::get_cols() const { return cols_; }

void S21Matrix::set_rows(int new_rows) {
  S21Matrix temp(new_rows, cols_);
  int min_rows = std::min(rows_, new_rows);
  std::memcpy(temp.matrix_[0], matrix_[0], sizeof(double) * min_rows * cols_);
  *this = std::move(temp);
}

void S21Matrix::set_cols(int new_cols) {
  S21Matrix temp(rows_, new_cols);
  int min_cols = std::min(cols_, new_cols);
  for (int i = 0; i < rows_; ++i) {
    std::memcpy(temp.matrix_[i], matrix_[i], sizeof(double) * min_cols);
  }
  *this = std::move(temp);
}

double S21Matrix::get_value(int row, int column) const {
  if (row < 0 || row >= rows_ || column < 0 || column >= cols_) {
    throw std::invalid_argument("Row and column index out of range");
  }
  return matrix_[row][column];
}

void S21Matrix::set_value(int row, int column, double value) const {
  if (row < 0 || row >= rows_ || column < 0 || column >= cols_) {
    throw std::invalid_argument("Row and column index out of range");
  }
  matrix_[row][column] = value;
}

}  // namespace S21
