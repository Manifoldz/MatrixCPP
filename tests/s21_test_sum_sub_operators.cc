#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

/*

SumOperator

*/

TEST(SumOperator, ordinary1) {
  S21::S21Matrix matrix1(4, 3);
  std::vector<std::vector<double>> arr = {
      {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2(4, 3);
  matrix2.FillFrom2DArr(arr);

  S21::S21Matrix matrix3 = matrix1 + matrix2;

  EXPECT_EQ(matrix3.get_rows(), 4);
  EXPECT_EQ(matrix3.get_cols(), 3);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_EQ(matrix3.get_value(i, j), 2 * arr[i][j]);
    }
  }
}

TEST(SumOperator, ordinary2) {
  S21::S21Matrix matrix1(2, 4);
  std::vector<std::vector<double>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2(2, 4);
  matrix2.FillFrom2DArr(arr);

  S21::S21Matrix matrix3 = matrix1 + matrix2;

  EXPECT_EQ(matrix3.get_rows(), 2);
  EXPECT_EQ(matrix3.get_cols(), 4);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      EXPECT_EQ(matrix3.get_value(i, j), 2 * arr[i][j]);
    }
  }
}

TEST(SumOperator, ordinary3) {
  S21::S21Matrix matrix1;
  S21::S21Matrix matrix2;

  S21::S21Matrix matrix3 = matrix1 + matrix2;

  EXPECT_EQ(matrix3.get_rows(), DEFAULT_ROWS);
  EXPECT_EQ(matrix3.get_cols(), DEFAULT_COLS);

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_EQ(matrix3.get_value(i, j), 0);
    }
  }
}

TEST(SumOperator, ordinary4) {
  S21::S21Matrix matrix1;
  S21::S21Matrix matrix2;

  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix3;
  matrix3 = matrix1 + matrix2;

  EXPECT_EQ(matrix3.get_rows(), DEFAULT_ROWS);
  EXPECT_EQ(matrix3.get_cols(), DEFAULT_COLS);

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_EQ(matrix3.get_value(i, j), arr[i][j]);
    }
  }
}

TEST(SumOperator, throw1) {
  S21::S21Matrix matrix1;
  S21::S21Matrix matrix2(3, 2);
  EXPECT_THROW(
      { S21::S21Matrix matrix3 = matrix1 + matrix2; }, std::invalid_argument);
}

/*

SumAssignOperator

*/

TEST(SumAssignOperator, ordinary1) {
  S21::S21Matrix matrix1(4, 3);
  std::vector<std::vector<double>> arr = {
      {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2(4, 3);
  matrix2.FillFrom2DArr(arr);

  matrix1 += matrix2;

  EXPECT_EQ(matrix1.get_rows(), 4);
  EXPECT_EQ(matrix1.get_cols(), 3);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_EQ(matrix1.get_value(i, j), 2 * arr[i][j]);
    }
  }
}

TEST(SumAssignOperator, ordinary2) {
  S21::S21Matrix matrix1(2, 4);
  std::vector<std::vector<double>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2(2, 4);
  matrix2.FillFrom2DArr(arr);

  matrix1 += matrix2;

  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 4);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      EXPECT_EQ(matrix1.get_value(i, j), 2 * arr[i][j]);
    }
  }
}

TEST(SumAssignOperator, ordinary3) {
  S21::S21Matrix matrix1;
  S21::S21Matrix matrix2;

  matrix1 += matrix2;

  EXPECT_EQ(matrix1.get_rows(), DEFAULT_ROWS);
  EXPECT_EQ(matrix1.get_cols(), DEFAULT_COLS);

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_EQ(matrix1.get_value(i, j), 0);
    }
  }
}

TEST(SumAssignOperator, ordinary4) {
  S21::S21Matrix matrix1;
  S21::S21Matrix matrix2;

  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  matrix1 += matrix2;

  EXPECT_EQ(matrix1.get_rows(), DEFAULT_ROWS);
  EXPECT_EQ(matrix1.get_cols(), DEFAULT_COLS);

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_EQ(matrix1.get_value(i, j), arr[i][j]);
    }
  }
}

TEST(SumAssignOperator, throw1) {
  S21::S21Matrix matrix1;
  S21::S21Matrix matrix2(3, 2);
  EXPECT_THROW({ matrix1 += matrix2; }, std::invalid_argument);
}

/*

SubOperator

*/

TEST(SubOperator, ordinary1) {
  S21::S21Matrix matrix1(4, 3);
  std::vector<std::vector<double>> arr = {
      {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2(4, 3);
  matrix2.FillFrom2DArr(arr);

  S21::S21Matrix matrix3 = matrix1 - matrix2;

  EXPECT_EQ(matrix3.get_rows(), 4);
  EXPECT_EQ(matrix3.get_cols(), 3);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_EQ(matrix3.get_value(i, j), 0);
    }
  }
}

TEST(SubOperator, ordinary2) {
  S21::S21Matrix matrix1(4, 3);
  std::vector<std::vector<double>> arr = {
      {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2(4, 3);

  S21::S21Matrix matrix3 = matrix2 - matrix1;

  EXPECT_EQ(matrix3.get_rows(), 4);
  EXPECT_EQ(matrix3.get_cols(), 3);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_EQ(matrix3.get_value(i, j), -1 * arr[i][j]);
    }
  }
}

TEST(SubOperator, ordinary3) {
  S21::S21Matrix matrix1(2, 4);
  std::vector<std::vector<double>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}};
  matrix1.FillFrom2DArr(arr);

  std::vector<std::vector<double>> arr2 = {{3, -4324.4342, 5.5, 5435.445335534},
                                           {424, 1, -432, 43.0000000001}};
  S21::S21Matrix matrix2(2, 4);
  matrix2.FillFrom2DArr(arr2);

  S21::S21Matrix matrix3 = matrix1 - matrix2;

  EXPECT_EQ(matrix3.get_rows(), 2);
  EXPECT_EQ(matrix3.get_cols(), 4);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      EXPECT_EQ(matrix3.get_value(i, j), arr[i][j] - arr2[i][j]);
    }
  }
}

TEST(SubOperator, throw1) {
  S21::S21Matrix matrix1;
  S21::S21Matrix matrix2(3, 2);
  EXPECT_THROW(
      { S21::S21Matrix matrix3 = matrix1 - matrix2; }, std::invalid_argument);
}

TEST(SubOperator, throw2) {
  S21::S21Matrix matrix1;
  S21::S21Matrix matrix2(2, 2);
  EXPECT_THROW(
      { S21::S21Matrix matrix3 = matrix2 - matrix1; }, std::invalid_argument);
}

/*

SubAssignOperator

*/

TEST(SubAssignOperator, ordinary1) {
  S21::S21Matrix matrix1(4, 3);
  std::vector<std::vector<double>> arr = {
      {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2(4, 3);
  matrix2.FillFrom2DArr(arr);

  matrix1 -= matrix2;

  EXPECT_EQ(matrix1.get_rows(), 4);
  EXPECT_EQ(matrix1.get_cols(), 3);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_EQ(matrix1.get_value(i, j), 0);
    }
  }
}

TEST(SubAssignOperator, ordinary2) {
  S21::S21Matrix matrix1(4, 3);
  std::vector<std::vector<double>> arr = {
      {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2(4, 3);

  matrix2 -= matrix1;

  EXPECT_EQ(matrix2.get_rows(), 4);
  EXPECT_EQ(matrix2.get_cols(), 3);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_EQ(matrix2.get_value(i, j), -1 * arr[i][j]);
    }
  }
}

TEST(SubAssignOperator, ordinary3) {
  S21::S21Matrix matrix1(2, 4);
  std::vector<std::vector<double>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}};
  matrix1.FillFrom2DArr(arr);

  std::vector<std::vector<double>> arr2 = {{3, -4324.4342, 5.5, 5435.445335534},
                                           {424, 1, -432, 43.0000000001}};
  S21::S21Matrix matrix2(2, 4);
  matrix2.FillFrom2DArr(arr2);

  matrix1 -= matrix2;

  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 4);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      EXPECT_EQ(matrix1.get_value(i, j), arr[i][j] - arr2[i][j]);
    }
  }
}

TEST(SubAssignOperator, throw1) {
  S21::S21Matrix matrix1;
  S21::S21Matrix matrix2(3, 2);
  EXPECT_THROW({ matrix1 -= matrix2; }, std::invalid_argument);
}

TEST(SubAssignOperator, throw2) {
  S21::S21Matrix matrix1;
  S21::S21Matrix matrix2(2, 2);
  EXPECT_THROW({ matrix2 -= matrix1; }, std::invalid_argument);
}