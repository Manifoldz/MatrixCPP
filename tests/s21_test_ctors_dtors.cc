#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

/*

Ctor default

*/

TEST(ConstructorDefault, ordinary1) {
  S21::S21Matrix matrix;
  EXPECT_EQ(matrix.get_rows(), DEFAULT_ROWS);
  EXPECT_EQ(matrix.get_cols(), DEFAULT_COLS);
}

/*

Ctor param

*/

TEST(ConstructorParam, ordinary1) {
  S21::S21Matrix matrix(2, 2);
  EXPECT_EQ(matrix.get_rows(), 2);
  EXPECT_EQ(matrix.get_cols(), 2);
}

TEST(ConstructorParam, ordinary2) {
  S21::S21Matrix matrix(1, 1);
  EXPECT_EQ(matrix.get_rows(), 1);
  EXPECT_EQ(matrix.get_cols(), 1);
}

TEST(ConstructorParam, ordinary3) {
  S21::S21Matrix matrix(5, 2);
  EXPECT_EQ(matrix.get_rows(), 5);
  EXPECT_EQ(matrix.get_cols(), 2);
}

TEST(ConstructorParam, ordinary4) {
  S21::S21Matrix matrix(2, 5);
  EXPECT_EQ(matrix.get_rows(), 2);
  EXPECT_EQ(matrix.get_cols(), 5);
  for (int i = 0; i < matrix.get_rows(); ++i) {
    for (int j = 0; j < matrix.get_cols(); ++j) {
      EXPECT_EQ(matrix.get_value(i, j), 0.0);
    }
  }
}

TEST(ConstructorParam, throw1) {
  EXPECT_THROW({ S21::S21Matrix matrix(0, 5); }, std::invalid_argument);
  EXPECT_THROW({ S21::S21Matrix matrix(-2, 5); }, std::invalid_argument);
  EXPECT_THROW({ S21::S21Matrix matrix(5, 0); }, std::invalid_argument);
  EXPECT_THROW({ S21::S21Matrix matrix(5, -2); }, std::invalid_argument);
}

/*

Ctor copy

*/

TEST(ConstructorCopy, ordinary1) {
  S21::S21Matrix matrix1(6, 2);
  matrix1.set_value(4, 1, -32.32323);
  S21::S21Matrix matrix2(matrix1);
  EXPECT_EQ(matrix2.get_rows(), 6);
  EXPECT_EQ(matrix2.get_cols(), 2);
  EXPECT_EQ(matrix2.get_value(4, 1), -32.32323);
}

TEST(ConstructorCopy, ordinary2) {
  S21::S21Matrix matrix1(2, 6);
  S21::S21Matrix matrix2(matrix1);
  for (int i = 0; i < matrix1.get_rows(); ++i) {
    for (int j = 0; j < matrix1.get_cols(); ++j) {
      EXPECT_EQ(matrix2.get_value(i, j), 0.0);
      EXPECT_EQ(matrix2.get_value(i, j), matrix1.get_value(i, j));
    }
  }
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 6);
}

TEST(ConstructorCopy, ordinary3) {
  S21::S21Matrix matrix1(1, 1);
  matrix1.set_value(0, 0, -32.32323);
  S21::S21Matrix matrix2(matrix1);
  EXPECT_EQ(matrix2.get_rows(), 1);
  EXPECT_EQ(matrix2.get_cols(), 1);
  EXPECT_EQ(matrix2.get_value(0, 0), -32.32323);
}

/*

Ctor move

*/

TEST(ConstructorMove, ordinary1) {
  S21::S21Matrix matrix1(6, 2);
  matrix1.set_value(2, 1, 123.124);
  S21::S21Matrix matrix2(std::move(matrix1));
  EXPECT_EQ(matrix2.get_rows(), 6);
  EXPECT_EQ(matrix2.get_cols(), 2);
  EXPECT_EQ(matrix2.get_value(2, 1), 123.124);

  for (int i = 0; i < matrix2.get_rows(); ++i) {
    for (int j = 0; j < matrix2.get_cols(); ++j) {
      if (i != 2 && j != 1) {
        EXPECT_EQ(matrix2.get_value(i, j), 0.0);
      }
    }
  }
}

TEST(ConstructorMove, ordinary2) {
  S21::S21Matrix matrix1(2, 6);
  S21::S21Matrix matrix2(std::move(matrix1));
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 6);
}

TEST(ConstructorMove, ordinary3) {
  S21::S21Matrix matrix1(1, 1);
  S21::S21Matrix matrix2(std::move(matrix1));
  EXPECT_EQ(matrix2.get_rows(), 1);
  EXPECT_EQ(matrix2.get_cols(), 1);
}