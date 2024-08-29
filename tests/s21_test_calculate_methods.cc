#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

/*

Transpose

*/

TEST(Transpose, ordinary1) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2 = matrix1.Transpose();

  for (int i = 0; i < DEFAULT_ROWS; ++i) {
    for (int j = 0; j < DEFAULT_COLS; ++j) {
      EXPECT_EQ(matrix1.get_value(i, j), matrix2.get_value(j, i));
    }
  }
}

TEST(Transpose, ordinary2) {
  S21::S21Matrix matrix1;
  S21::S21Matrix matrix2 = matrix1.Transpose();

  EXPECT_EQ(matrix1.EqMatrix(matrix2), true);

  for (int i = 0; i < DEFAULT_ROWS; ++i) {
    for (int j = 0; j < DEFAULT_COLS; ++j) {
      EXPECT_EQ(matrix1.get_value(i, j), matrix2.get_value(j, i));
    }
  }
}

TEST(Transpose, ordinary3) {
  S21::S21Matrix matrix1(2, 3);
  std::vector<std::vector<double>> arr = {{1, -32.2, 3}, {4, 5, 0}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2 = matrix1.Transpose();

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      EXPECT_EQ(matrix1.get_value(i, j), matrix2.get_value(j, i));
    }
  }
}

TEST(Transpose, ordinary4) {
  S21::S21Matrix matrix1(1, 1);
  std::vector<std::vector<double>> arr = {{-32}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2 = matrix1.Transpose();
  EXPECT_EQ(matrix1.EqMatrix(matrix2), true);
}

/*

Determinant

*/

TEST(Determinant, 4X4) {
  S21::S21Matrix matrix1(4, 4);
  std::vector<std::vector<double>> arr = {
      {3, -3, -5, 8}, {-3, 2, 4, -6}, {2, -5, -7, 5}, {-4, 3, 5, -6}};
  matrix1.FillFrom2DArr(arr);
  double det = matrix1.Determinant();

  ASSERT_EQ(det, 18);
}

TEST(Determinant, 3X3) {
  S21::S21Matrix matrix1(3, 3);
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);
  double det = matrix1.Determinant();

  ASSERT_EQ(det, 0);
}

TEST(Determinant, 3X3_2) {
  S21::S21Matrix matrix1(3, 3);
  std::vector<std::vector<double>> arr = {{1, -2, 3}, {4, 0, 6}, {-7, 8, 9}};
  matrix1.FillFrom2DArr(arr);
  double det = matrix1.Determinant();

  ASSERT_EQ(det, 204);
}

TEST(Determinant, 2X2) {
  S21::S21Matrix matrix1(2, 2);

  std::vector<std::vector<double>> arr = {{3, -3}, {-4, 3}};
  matrix1.FillFrom2DArr(arr);
  EXPECT_EQ(matrix1.Determinant(), -3);

  arr = {{11, -3}, {-15, -2}};
  matrix1.FillFrom2DArr(arr);
  EXPECT_EQ(matrix1.Determinant(), -67);
}

TEST(Determinant, 1X1) {
  S21::S21Matrix matrix1(1, 1);
  matrix1.set_value(0, 0, -3);
  EXPECT_EQ(matrix1.Determinant(), -3);

  matrix1.set_value(0, 0, 3213.233223);
  EXPECT_EQ(matrix1.Determinant(), 3213.233223);

  matrix1.set_value(0, 0, 0);
  EXPECT_EQ(matrix1.Determinant(), 0);
}

TEST(Determinant, throw1) {
  S21::S21Matrix matrix1(1, 2);
  EXPECT_THROW({ matrix1.Determinant(); }, std::invalid_argument);
}

TEST(Determinant, throw2) {
  S21::S21Matrix matrix1(4, 11);
  EXPECT_THROW({ matrix1.Determinant(); }, std::invalid_argument);
}

/*

CalcComplements

*/

TEST(CalcComplements, 3X3) {
  S21::S21Matrix matrix1(3, 3);
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
  std::vector<std::vector<double>> ref = {
      {0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2 = matrix1.CalcComplements();

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      EXPECT_EQ(matrix2.get_value(i, j), ref[i][j]);
    }
  }
}

TEST(CalcComplements, 4X4) {
  S21::S21Matrix matrix1(4, 4);
  std::vector<std::vector<double>> arr = {
      {3, -3, -5, 8}, {-3, 2, 4, -6}, {2, -5, -7, 5}, {-4, 3, 5, -6}};
  std::vector<std::vector<double>> ref = {
      {-2, -25, 23, 8}, {8, -53, 43, 4}, {-4, 4, -8, -2}, {-14, 23, -19, 2}};

  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2 = matrix1.CalcComplements();

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      EXPECT_EQ(matrix2.get_value(i, j), ref[i][j]);
    }
  }
}

TEST(CalcComplements, throw1) {
  S21::S21Matrix matrix1(1, 2);
  EXPECT_THROW({ matrix1.CalcComplements(); }, std::invalid_argument);
}

TEST(CalcComplements, throw2) {
  S21::S21Matrix matrix1(4, 11);
  EXPECT_THROW({ matrix1.CalcComplements(); }, std::invalid_argument);
}

TEST(CalcComplements, throw3) {
  S21::S21Matrix matrix1(1, 1);
  EXPECT_THROW({ matrix1.CalcComplements(); }, std::invalid_argument);
}

/*

InverseMatrix

*/

TEST(InverseMatrix, 1X1) {
  S21::S21Matrix matrix1(1, 1);
  matrix1.set_value(0, 0, 7);

  S21::S21Matrix matrix2 = matrix1.InverseMatrix();

  EXPECT_EQ(matrix2.get_value(0, 0), 1.0 / 7);
}

TEST(InverseMatrix, 2X2) {
  S21::S21Matrix matrix1(2, 2);
  std::vector<std::vector<double>> arr = {{4, 7}, {2, 6}};

  std::vector<std::vector<double>> ref = {{0.6, -0.7}, {-0.2, 0.4}};

  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2 = matrix1.InverseMatrix();

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(matrix2.get_value(i, j), ref[i][j]);
    }
  }
}

TEST(InverseMatrix, 3X3) {
  S21::S21Matrix matrix1(3, 3);
  std::vector<std::vector<double>> arr = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};

  std::vector<std::vector<double>> ref = {
      {1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};

  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2 = matrix1.InverseMatrix();

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      EXPECT_EQ(matrix2.get_value(i, j), ref[i][j]);
    }
  }
}

TEST(InverseMatrix, 4X4) {
  S21::S21Matrix matrix1(4, 4);
  std::vector<std::vector<double>> arr = {
      {3, -3, -5, 8}, {-3, 2, 4, -6}, {2, -5, -7, 5}, {-4, 3, 5, -6}};

  std::vector<std::vector<double>> ref = {
      {-1.0 / 9, 4.0 / 9, -2.0 / 9, -7.0 / 9},
      {-25.0 / 18, -53.0 / 18, 2.0 / 9, 23.0 / 18},
      {23.0 / 18, 43.0 / 18, -4.0 / 9, -19.0 / 18},
      {4.0 / 9, 2.0 / 9, -1.0 / 9, 1.0 / 9}};

  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2 = matrix1.InverseMatrix();

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      EXPECT_EQ(matrix2.get_value(i, j), ref[i][j]);
    }
  }
}

TEST(InverseMatrix, throw1) {
  S21::S21Matrix matrix1(3, 3);
  std::vector<std::vector<double>> arr = {{0, 0, 0}, {6, 9, -5}, {4, 7, -3}};
  matrix1.FillFrom2DArr(arr);
  EXPECT_THROW({ matrix1.InverseMatrix(); }, std::invalid_argument);
}

TEST(InverseMatrix, throw2) {
  S21::S21Matrix matrix1(4, 11);
  EXPECT_THROW({ matrix1.InverseMatrix(); }, std::invalid_argument);
}

TEST(InverseMatrix, throw3) {
  S21::S21Matrix matrix1(3, 2);
  EXPECT_THROW({ matrix1.InverseMatrix(); }, std::invalid_argument);
}
