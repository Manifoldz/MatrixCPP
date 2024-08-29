#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

/*

FillFrom2DArr

*/

TEST(FillFrom2DArr, ordinary1) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);
  for (size_t i = 0; i < arr.size(); i++) {
    for (size_t j = 0; j < arr[0].size(); j++) {
      EXPECT_EQ(matrix1.get_value(i, j), arr[i][j]);
    }
  }
}

TEST(FillFrom2DArr, ordinary2) {
  S21::S21Matrix matrix1(4, 3);
  std::vector<std::vector<double>> arr = {
      {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
  matrix1.FillFrom2DArr(arr);
  for (size_t i = 0; i < arr.size(); i++) {
    for (size_t j = 0; j < arr[0].size(); j++) {
      EXPECT_EQ(matrix1.get_value(i, j), arr[i][j]);
    }
  }
}

TEST(FillFrom2DArr, ordinary3) {
  S21::S21Matrix matrix1(2, 1);
  std::vector<std::vector<double>> arr = {{1}, {10}};
  matrix1.FillFrom2DArr(arr);
  EXPECT_EQ(matrix1.get_value(0, 0), 1);
  EXPECT_EQ(matrix1.get_value(1, 0), 10);
}

TEST(FillFrom2DArr, throw1) {
  S21::S21Matrix matrix1(2, 1);
  std::vector<std::vector<double>> arr = {{1, 2}, {10, 2}};
  EXPECT_THROW({ matrix1.FillFrom2DArr(arr); }, std::invalid_argument);
}

/*

Clean

*/

TEST(Clean, ordinary1) {
  S21::S21Matrix matrix1(4, 3);
  std::vector<std::vector<double>> arr = {
      {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
  matrix1.FillFrom2DArr(arr);
  matrix1.Clean();
  for (size_t i = 0; i < arr.size(); i++) {
    for (size_t j = 0; j < arr[0].size(); j++) {
      EXPECT_EQ(matrix1.get_value(i, j), 0);
    }
  }
}