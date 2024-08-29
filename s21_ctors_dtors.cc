#include "s21_matrix_oop.h"

namespace S21 {

void S21Matrix::Allocation() {
  if (rows_ <= 0 || cols_ <= 0) {
    throw std::invalid_argument("Rows and cols must be more than 0");
  }
  matrix_ = new double *[rows_];
  matrix_[0] = new double[static_cast<size_t>(rows_) * cols_];
  for (int i = 1; i < rows_; ++i) {
    matrix_[i] = matrix_[0] + i * cols_;
  }
}

void S21Matrix::Deallocation() {
  delete[] matrix_[0];
  delete[] matrix_;
  matrix_ = nullptr;
}

S21Matrix::S21Matrix() : rows_(DEFAULT_ROWS), cols_(DEFAULT_COLS) {
  Allocation();
  Clean();
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  Allocation();
  Clean();
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  Allocation();
  std::memcpy(matrix_[0], other.matrix_[0], sizeof(double) * cols_ * rows_);
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
  if (matrix_ != nullptr) {
    Deallocation();
  }
}

}  // namespace S21
