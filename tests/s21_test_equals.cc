#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

/*

Equal method and operator==

*/

TEST(Equal, true1) {
  S21::S21Matrix matrix1(6, 2);
  S21::S21Matrix matrix2(6, 2);
  EXPECT_EQ(matrix1.EqMatrix(matrix2), true);
  EXPECT_EQ(matrix2.EqMatrix(matrix1), true);
  EXPECT_EQ(matrix2 == matrix1, true);
  EXPECT_EQ(matrix1 == matrix2, true);
}

TEST(Equal, true2) {
  S21::S21Matrix matrix1(6, 2);
  S21::S21Matrix matrix2(matrix1);
  EXPECT_EQ(matrix1.EqMatrix(matrix2), true);
  EXPECT_EQ(matrix2.EqMatrix(matrix1), true);
  EXPECT_EQ(matrix2 == matrix1, true);
  EXPECT_EQ(matrix1 == matrix2, true);
}

TEST(Equal, true3) {
  S21::S21Matrix matrix1(4, 3);
  std::vector<std::vector<double>> arr = {
      {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2(matrix1);
  EXPECT_EQ(matrix1.EqMatrix(matrix2), true);
  EXPECT_EQ(matrix2.EqMatrix(matrix1), true);
  EXPECT_EQ(matrix2 == matrix1, true);
  EXPECT_EQ(matrix1 == matrix2, true);
  EXPECT_EQ(matrix1.get_value(0, 0), matrix2.get_value(0, 0));
  EXPECT_EQ(matrix1.get_value(2, 2), matrix2.get_value(2, 2));
}

TEST(Equal, true4) {
  S21::S21Matrix matrix1(3, 3);
  S21::S21Matrix matrix2;
  EXPECT_EQ(matrix1.EqMatrix(matrix2), true);
  EXPECT_EQ(matrix2.EqMatrix(matrix1), true);
  EXPECT_EQ(matrix2 == matrix1, true);
  EXPECT_EQ(matrix1 == matrix2, true);
}

TEST(Equal, true5) {
  S21::S21Matrix matrix1(2, 2);
  std::vector<std::vector<double>> arr = {{0.00000009, 0.000000099999},
                                          {0.00000009, 0.000000099999}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2(2, 2);
  EXPECT_EQ(matrix1.EqMatrix(matrix2), true);
  EXPECT_EQ(matrix2.EqMatrix(matrix1), true);
  EXPECT_EQ(matrix2 == matrix1, true);
  EXPECT_EQ(matrix1 == matrix2, true);
}

TEST(Equal, false1) {
  S21::S21Matrix matrix1(4, 3);
  std::vector<std::vector<double>> arr = {
      {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2(matrix1);
  matrix1.set_value(3, 2, 100);
  EXPECT_EQ(matrix1.EqMatrix(matrix2), false);
  EXPECT_EQ(matrix2.EqMatrix(matrix1), false);
  EXPECT_EQ(matrix2 == matrix1, false);
  EXPECT_EQ(matrix1 == matrix2, false);
}

TEST(Equal, false2) {
  S21::S21Matrix matrix1(4, 3);
  S21::S21Matrix matrix2;
  EXPECT_EQ(matrix1.EqMatrix(matrix2), false);
  EXPECT_EQ(matrix2.EqMatrix(matrix1), false);
  EXPECT_EQ(matrix2 == matrix1, false);
  EXPECT_EQ(matrix1 == matrix2, false);
}

TEST(Equal, false3) {
  S21::S21Matrix matrix1(3, 4);
  S21::S21Matrix matrix2;
  EXPECT_EQ(matrix1.EqMatrix(matrix2), false);
  EXPECT_EQ(matrix2.EqMatrix(matrix1), false);
  EXPECT_EQ(matrix2 == matrix1, false);
  EXPECT_EQ(matrix1 == matrix2, false);
}

TEST(Equal, false4) {
  S21::S21Matrix matrix1(2, 2);
  std::vector<std::vector<double>> arr = {{0.0000001, 0.000000099999},
                                          {0.0000001, 0.000000099999}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2(2, 2);
  EXPECT_EQ(matrix1.EqMatrix(matrix2), false);
  EXPECT_EQ(matrix2.EqMatrix(matrix1), false);
  EXPECT_EQ(matrix2 == matrix1, false);
  EXPECT_EQ(matrix1 == matrix2, false);
}