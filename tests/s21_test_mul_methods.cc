#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

/*

MulNumber

*/

TEST(MulNumber, ordinary1) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  matrix1.MulNumber(2);

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_EQ(matrix1.get_value(i, j), 2 * arr[i][j]);
    }
  }
}

TEST(MulNumber, ordinary2) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  matrix1.MulNumber(0);

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_EQ(matrix1.get_value(i, j), 0 * arr[i][j]);
    }
  }
}

TEST(MulNumber, ordinary3) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  matrix1.MulNumber(2.323153219);

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_EQ(matrix1.get_value(i, j), 2.323153219 * arr[i][j]);
    }
  }
}

TEST(MulNumber, ordinary4) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  matrix1.MulNumber(-2.323153219);

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_EQ(matrix1.get_value(i, j), -2.323153219 * arr[i][j]);
    }
  }
}

TEST(MulNumber, ordinary5) {
  S21::S21Matrix matrix1(2, 2);
  std::vector<std::vector<double>> arr = {{1, -2}, {0, 0}};
  matrix1.FillFrom2DArr(arr);

  matrix1.MulNumber(-2.323153219);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      EXPECT_EQ(matrix1.get_value(i, j), -2.323153219 * arr[i][j]);
    }
  }
}

TEST(MulNumber, ordinary6) {
  S21::S21Matrix matrix1(2, 1);

  matrix1.MulNumber(321);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 1; j++) {
      EXPECT_EQ(matrix1.get_value(i, j), 321 * 0);
    }
  }
}

/*

MulMatrix

*/

TEST(MulMatrix, ordinary1) {
  S21::S21Matrix matrix1(8, 5);

  int counter = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 5; j++) {
      matrix1.set_value(i, j, ++counter);
    }
  }

  counter = 0;
  S21::S21Matrix matrix2(5, 8);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 8; j++) {
      matrix2.set_value(i, j, ++counter);
    }
  }

  std::vector<std::vector<double>> ref = {
      {335, 350, 365, 380, 395, 410, 425, 440},
      {760, 800, 840, 880, 920, 960, 1000, 1040},
      {1185, 1250, 1315, 1380, 1445, 1510, 1575, 1640},
      {1610, 1700, 1790, 1880, 1970, 2060, 2150, 2240},
      {2035, 2150, 2265, 2380, 2495, 2610, 2725, 2840},
      {2460, 2600, 2740, 2880, 3020, 3160, 3300, 3440},
      {2885, 3050, 3215, 3380, 3545, 3710, 3875, 4040},
      {3310, 3500, 3690, 3880, 4070, 4260, 4450, 4640}};

  matrix1.MulMatrix(matrix2);

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      EXPECT_EQ(matrix1.get_value(i, j), ref[i][j]);
    }
  }
}

TEST(MulMatrix, ordinary2) {
  S21::S21Matrix matrix1(3, 3);
  std::vector<std::vector<double>> arr1 = {{5, 8, -4}, {6, 9, -5}, {4, 7, -3}};
  matrix1.FillFrom2DArr(arr1);

  S21::S21Matrix matrix2(3, 1);
  matrix2.set_value(0, 0, 2);
  matrix2.set_value(1, 0, -3);
  matrix2.set_value(2, 0, 1);

  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(matrix1.get_value(0, 0), -18);
  EXPECT_EQ(matrix1.get_value(1, 0), -20);
  EXPECT_EQ(matrix1.get_value(2, 0), -16);
}

TEST(MulMatrix, throw1) {
  S21::S21Matrix matrix1(3, 3);
  S21::S21Matrix matrix2(4, 1);

  EXPECT_THROW({ matrix1.MulMatrix(matrix2); }, std::invalid_argument);
}

TEST(MulMatrix, throw2) {
  S21::S21Matrix matrix1(3, 4);
  S21::S21Matrix matrix2(1, 1);

  EXPECT_THROW({ matrix1.MulMatrix(matrix2); }, std::invalid_argument);
}