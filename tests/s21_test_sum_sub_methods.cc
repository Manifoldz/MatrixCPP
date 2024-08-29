#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

/*

SumMatrix

*/

TEST(SumMatrix, ordinary1) {
  S21::S21Matrix matrix1;
  S21::S21Matrix matrix2;
  matrix1.SumMatrix(matrix2);
  EXPECT_EQ(matrix1.EqMatrix(matrix2), true);
  EXPECT_EQ(matrix2.EqMatrix(matrix1), true);
}

TEST(SumMatrix, ordinary2) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2;
  matrix2.SumMatrix(matrix1);
  EXPECT_EQ(matrix1.EqMatrix(matrix2), true);
  EXPECT_EQ(matrix2.EqMatrix(matrix1), true);
}

TEST(SumMatrix, ordinary3) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2;
  matrix2.FillFrom2DArr(arr);

  matrix1.SumMatrix(matrix2);
  EXPECT_EQ(matrix1.EqMatrix(matrix2), false);
  EXPECT_EQ(matrix2.EqMatrix(matrix1), false);

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_NEAR(matrix1.get_value(i, j), 2 * arr[i][j], PRECISION);
      EXPECT_EQ(matrix2.get_value(i, j), arr[i][j]);
    }
  }
}

TEST(SumMatrix, ordinary4) {
  S21::S21Matrix matrix1(4, 2);
  std::vector<std::vector<double>> arr = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2(4, 2);
  matrix2.FillFrom2DArr(arr);

  matrix2.SumMatrix(matrix1);
  EXPECT_EQ(matrix1.EqMatrix(matrix2), false);
  EXPECT_EQ(matrix2.EqMatrix(matrix1), false);

  for (int i = 0; i < matrix1.get_rows(); i++) {
    for (int j = 0; j < matrix1.get_cols(); j++) {
      EXPECT_NEAR(matrix2.get_value(i, j), 2 * arr[i][j], PRECISION);
      EXPECT_EQ(matrix1.get_value(i, j), arr[i][j]);
    }
  }
}

TEST(SumMatrix, selfsum1) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  matrix1.SumMatrix(matrix1);
  EXPECT_EQ(matrix1.EqMatrix(matrix1), true);
  EXPECT_EQ(matrix1.EqMatrix(matrix1), true);
  for (int i = 0; i < matrix1.get_rows(); i++) {
    for (int j = 0; j < matrix1.get_cols(); j++) {
      EXPECT_EQ(matrix1.get_value(i, j), 2 * arr[i][j]);
    }
  }
}

TEST(SumMatrix, throw1) {
  S21::S21Matrix matrix1(3, 4);
  S21::S21Matrix matrix2;
  EXPECT_THROW({ matrix1.SumMatrix(matrix2); }, std::invalid_argument);
}

TEST(SumMatrix, throw2) {
  S21::S21Matrix matrix1(4, 3);
  S21::S21Matrix matrix2;
  EXPECT_THROW({ matrix1.SumMatrix(matrix2); }, std::invalid_argument);
}

/*

SubMatrix

*/

TEST(SubMatrix, ordinary1) {
  S21::S21Matrix matrix1;
  S21::S21Matrix matrix2;
  matrix1.SubMatrix(matrix2);
  EXPECT_EQ(matrix1.EqMatrix(matrix2), true);
  EXPECT_EQ(matrix2.EqMatrix(matrix1), true);
}

TEST(SubMatrix, ordinary2) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2;
  matrix1.SubMatrix(matrix2);

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_EQ(matrix1.get_value(i, j), arr[i][j]);
    }
  }
}

TEST(SubMatrix, ordinary3) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2;
  matrix2.SubMatrix(matrix1);

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_EQ(matrix2.get_value(i, j), -1 * arr[i][j]);
    }
  }
}

TEST(SubMatrix, ordinary4) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2;
  matrix2.FillFrom2DArr(arr);

  matrix1.SubMatrix(matrix2);
  EXPECT_EQ(matrix1.EqMatrix(matrix2), false);
  EXPECT_EQ(matrix2.EqMatrix(matrix1), false);

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_EQ(matrix1.get_value(i, j), 0);
      EXPECT_EQ(matrix2.get_value(i, j), arr[i][j]);
    }
  }
}

TEST(SubMatrix, ordinary5) {
  S21::S21Matrix matrix1(4, 2);
  std::vector<std::vector<double>> arr = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  matrix1.FillFrom2DArr(arr);

  std::vector<std::vector<double>> arr2 = {
      {1.3213, 2.3123}, {-232.32, 4}, {0, -323.222}, {0.000001, -0.0000001}};
  S21::S21Matrix matrix2(4, 2);
  matrix2.FillFrom2DArr(arr2);

  matrix1.SubMatrix(matrix2);

  for (int i = 0; i < matrix1.get_rows(); i++) {
    for (int j = 0; j < matrix1.get_cols(); j++) {
      EXPECT_EQ(matrix1.get_value(i, j), arr[i][j] - arr2[i][j]);
    }
  }
}

TEST(SubMatrix, selfsub1) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  matrix1.SubMatrix(matrix1);
  for (int i = 0; i < matrix1.get_rows(); i++) {
    for (int j = 0; j < matrix1.get_cols(); j++) {
      EXPECT_EQ(matrix1.get_value(i, j), 0);
    }
  }
}

TEST(SubMatrix, throw1) {
  S21::S21Matrix matrix1(3, 4);
  S21::S21Matrix matrix2;
  EXPECT_THROW({ matrix1.SubMatrix(matrix2); }, std::invalid_argument);
  EXPECT_THROW({ matrix2.SubMatrix(matrix1); }, std::invalid_argument);
}

TEST(SubMatrix, throw2) {
  S21::S21Matrix matrix1(4, 3);
  S21::S21Matrix matrix2;
  EXPECT_THROW({ matrix1.SubMatrix(matrix2); }, std::invalid_argument);
  EXPECT_THROW({ matrix2.SubMatrix(matrix1); }, std::invalid_argument);
}