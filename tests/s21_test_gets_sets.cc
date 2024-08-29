#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

/*

Gets

*/

TEST(Gets, ordinary1) {
  S21::S21Matrix matrix;
  EXPECT_EQ(matrix.get_rows(), 3);
  EXPECT_EQ(matrix.get_cols(), 3);
}

TEST(Gets, ordinary2) {
  S21::S21Matrix matrix(31, 1);
  EXPECT_EQ(matrix.get_rows(), 31);
  EXPECT_EQ(matrix.get_cols(), 1);
}

TEST(Gets, ordinary3) {
  S21::S21Matrix matrix(3, 12);
  EXPECT_EQ(matrix.get_rows(), 3);
  EXPECT_EQ(matrix.get_cols(), 12);
}

/*

SetRows

*/

TEST(SetRows, ordinary1) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  matrix1.set_rows(4);

  ASSERT_EQ(matrix1.get_rows(), 4);
  ASSERT_EQ(matrix1.get_cols(), 3);
  for (int i = 0; i < matrix1.get_rows(); ++i) {
    for (int j = 0; j < matrix1.get_cols(); ++j) {
      if (i != 3) {
        EXPECT_EQ(matrix1.get_value(i, j), arr[i][j]);
      } else {
        EXPECT_EQ(matrix1.get_value(i, j), 0.0);
      }
    }
  }
}

TEST(SetRows, ordinary2) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  matrix1.set_rows(2);

  ASSERT_EQ(matrix1.get_rows(), 2);
  ASSERT_EQ(matrix1.get_cols(), 3);
  for (int i = 0; i < matrix1.get_rows(); ++i) {
    for (int j = 0; j < matrix1.get_cols(); ++j) {
      EXPECT_EQ(matrix1.get_value(i, j), arr[i][j]);
    }
  }
}

TEST(SetRows, ordinary3) {
  S21::S21Matrix matrix1(3, 4);
  std::vector<std::vector<double>> arr = {
      {3, -3, -5, 8}, {-3, 2, 4, -6}, {2, -5, -7, 5}};
  matrix1.FillFrom2DArr(arr);

  matrix1.set_rows(1);

  ASSERT_EQ(matrix1.get_rows(), 1);
  ASSERT_EQ(matrix1.get_cols(), 4);
  for (int i = 0; i < matrix1.get_rows(); ++i) {
    for (int j = 0; j < matrix1.get_cols(); ++j) {
      EXPECT_EQ(matrix1.get_value(i, j), arr[i][j]);
    }
  }
}

TEST(SetRows, ordinary4) {
  S21::S21Matrix matrix1(3, 4);
  std::vector<std::vector<double>> arr = {
      {3, -3, -5, 8}, {-3, 2, 4, -6}, {2, -5, -7, 5}};
  matrix1.FillFrom2DArr(arr);

  matrix1.set_rows(5);

  ASSERT_EQ(matrix1.get_rows(), 5);
  ASSERT_EQ(matrix1.get_cols(), 4);
  for (int i = 0; i < matrix1.get_rows(); ++i) {
    for (int j = 0; j < matrix1.get_cols(); ++j) {
      if (i > 2) {
        EXPECT_EQ(matrix1.get_value(i, j), 0.0);
      } else {
        EXPECT_EQ(matrix1.get_value(i, j), arr[i][j]);
      }
    }
  }
}

TEST(SetRows, ordinary5) {
  S21::S21Matrix matrix1(1, 1);
  matrix1.set_value(0, 0, -312.32321);

  matrix1.set_rows(2);

  ASSERT_EQ(matrix1.get_rows(), 2);
  ASSERT_EQ(matrix1.get_cols(), 1);
  EXPECT_EQ(matrix1.get_value(0, 0), -312.32321);
  EXPECT_EQ(matrix1.get_value(1, 0), 0.0);
}

/*

SetCols

*/

TEST(SetCols, ordinary1) {
  S21::S21Matrix matrix1(3, 4);
  std::vector<std::vector<double>> arr = {
      {3, -3, -5, 8}, {-3, 2, 4, -6}, {2, -5, -7, 5}};
  matrix1.FillFrom2DArr(arr);

  matrix1.set_cols(6);

  ASSERT_EQ(matrix1.get_rows(), 3);
  ASSERT_EQ(matrix1.get_cols(), 6);
  for (int i = 0; i < matrix1.get_rows(); ++i) {
    for (int j = 0; j < matrix1.get_cols(); ++j) {
      if (j > 3) {
        EXPECT_EQ(matrix1.get_value(i, j), 0.0);
      } else {
        EXPECT_EQ(matrix1.get_value(i, j), arr[i][j]);
      }
    }
  }
}

TEST(SetCols, ordinary2) {
  S21::S21Matrix matrix1(3, 4);
  std::vector<std::vector<double>> arr = {
      {3, -3, -5, 8}, {-3, 2, 4, -6}, {2, -5, -7, 5}};
  matrix1.FillFrom2DArr(arr);

  matrix1.set_cols(1);

  ASSERT_EQ(matrix1.get_rows(), 3);
  ASSERT_EQ(matrix1.get_cols(), 1);
  for (int i = 0; i < matrix1.get_rows(); ++i) {
    for (int j = 0; j < matrix1.get_cols(); ++j) {
      EXPECT_EQ(matrix1.get_value(i, j), arr[i][j]);
    }
  }
}

TEST(SetCols, ordinary3) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  matrix1.set_cols(2);

  ASSERT_EQ(matrix1.get_rows(), 3);
  ASSERT_EQ(matrix1.get_cols(), 2);
  for (int i = 0; i < matrix1.get_rows(); ++i) {
    for (int j = 0; j < matrix1.get_cols(); ++j) {
      EXPECT_EQ(matrix1.get_value(i, j), arr[i][j]);
    }
  }
}

TEST(SetCols, ordinary4) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  matrix1.set_cols(10);

  ASSERT_EQ(matrix1.get_rows(), 3);
  ASSERT_EQ(matrix1.get_cols(), 10);
  for (int i = 0; i < matrix1.get_rows(); ++i) {
    for (int j = 0; j < matrix1.get_cols(); ++j) {
      if (j <= 2) {
        EXPECT_EQ(matrix1.get_value(i, j), arr[i][j]);
      } else {
        EXPECT_EQ(matrix1.get_value(i, j), 0.0);
      }
    }
  }
}

TEST(SetCols, ordinary5) {
  S21::S21Matrix matrix1(1, 1);
  matrix1.set_value(0, 0, -312.32321);

  matrix1.set_cols(2);

  ASSERT_EQ(matrix1.get_rows(), 1);
  ASSERT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_value(0, 0), -312.32321);
  EXPECT_EQ(matrix1.get_value(0, 1), 0.0);
}

/*

SetsGetsValue

*/

TEST(SetsGetsValue, ordinary1) {
  S21::S21Matrix matrix;
  for (int i = 0; i < matrix.get_rows(); ++i) {
    for (int j = 0; j < matrix.get_cols(); ++j) {
      EXPECT_EQ(matrix.get_value(i, j), 0.0);
      EXPECT_EQ(matrix(i, j), 0.0);
    }
  }
  matrix.set_value(0, 0, -23.32);
  matrix(1, 2) = 123.42434;
  matrix(2, 2) = 5.3232;
  EXPECT_EQ(matrix.get_value(0, 0), -23.32);
  EXPECT_EQ(matrix(0, 0), -23.32);
  EXPECT_EQ(matrix.get_value(1, 2), 123.42434);
  EXPECT_EQ(matrix(1, 2), 123.42434);
  EXPECT_EQ(matrix.get_value(2, 2), 5.3232);
  EXPECT_EQ(matrix(2, 2), 5.3232);
}

TEST(SetsGetsValue, ordinary2) {
  S21::S21Matrix matrix(2, 4);
  for (int i = 0; i < matrix.get_rows(); ++i) {
    for (int j = 0; j < matrix.get_cols(); ++j) {
      EXPECT_EQ(matrix.get_value(i, j), 0.0);
      EXPECT_EQ(matrix(i, j), 0.0);
    }
  }
  matrix.set_value(0, 0, -23.32);
  matrix(1, 3) = 123.42434;
  matrix.set_value(1, 2, 5.3232);
  EXPECT_EQ(matrix.get_value(0, 0), -23.32);
  EXPECT_EQ(matrix(0, 0), -23.32);
  EXPECT_EQ(matrix.get_value(1, 3), 123.42434);
  EXPECT_EQ(matrix(1, 3), 123.42434);
  EXPECT_EQ(matrix.get_value(1, 2), 5.3232);
  EXPECT_EQ(matrix(1, 2), 5.3232);
}

TEST(SetsValue, throw1) {
  S21::S21Matrix matrix(2, 4);
  EXPECT_THROW({ matrix.set_value(2, 3, -23.32); }, std::invalid_argument);
  EXPECT_THROW({ matrix.set_value(1, 4, -23.32); }, std::invalid_argument);
  EXPECT_THROW({ matrix(-1, 2) = -23.32; }, std::invalid_argument);
  EXPECT_THROW({ matrix.set_value(1, -2, -23.32); }, std::invalid_argument);
  EXPECT_NO_THROW({ matrix(1, 1) = -23.32; });
}

TEST(GetsValue, throw1) {
  S21::S21Matrix matrix(2, 4);
  EXPECT_THROW({ matrix.get_value(2, 3); }, std::invalid_argument);
  EXPECT_THROW({ matrix(1, 4); }, std::invalid_argument);
  EXPECT_THROW({ matrix.get_value(-1, 2); }, std::invalid_argument);
  EXPECT_THROW({ matrix(1, -2); }, std::invalid_argument);
  EXPECT_NO_THROW({ matrix.get_value(1, 1); });
}