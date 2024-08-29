#include "s21_matrix_oop.h"

namespace S21 {

void S21Matrix::Clean() {
  if (matrix_ != nullptr) {
    std::memset(matrix_[0], 0, sizeof(double) * rows_ * cols_);
  }
}

void S21Matrix::FillFrom2DArr(std::vector<std::vector<double>>& arr) {
  if (rows_ != (int)arr.size() || cols_ != (int)arr[0].size()) {
    throw std::invalid_argument("Rows and cols must be the same");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = arr[i][j];
    }
  }
}

double S21Matrix::RecursiveDeterminant(bool* ban_rows, bool* ban_cols) const {
  // find quantity of not banned rows
  int left_size = cols_;
  for (int i = 0; i < cols_; i++) {
    left_size -= ban_rows[i];
  }

  if (left_size == 1) {
    // if first element is banned - take element with index 1(true)
    return matrix_[1 - ban_rows[1]][1 - ban_cols[1]];
  } else if (left_size == 2) {
    // get minor 2x2
    return Minor(ban_rows, ban_cols);
  }

  // find first row not banned
  int first_row = 0;
  for (int i = 0; i < rows_; i++) {
    if (!ban_rows[i]) {
      first_row = i;
      break;
    }
  }

  // relative to the first row make recursion
  double res = 0;
  ban_rows[first_row] = true;
  int sign = 1;
  for (int i = 0; i < rows_; i++) {
    if (ban_cols[i]) {
      continue;
    }
    ban_cols[i] = true;
    double minor = RecursiveDeterminant(ban_rows, ban_cols);
    res += sign * matrix_[first_row][i] * minor;
    ban_cols[i] = false;
    // vice versa next sign
    sign *= -1;
  }
  ban_rows[first_row] = false;
  return res;
}

double S21Matrix::Minor(bool* ban_rows, bool* ban_cols) const {
  double last_values[4] = {0};
  int last_filled = 0;
  for (int i = 0; i < rows_; i++) {
    if (ban_rows[i]) {
      continue;
    }
    for (int j = 0; j < cols_; j++) {
      if (ban_cols[j]) {
        continue;
      }
      last_values[last_filled] = matrix_[i][j];
      last_filled++;
    }
  }
  return last_values[0] * last_values[3] - last_values[1] * last_values[2];
}

}  // namespace S21