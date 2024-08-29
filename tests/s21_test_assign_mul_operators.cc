#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

/*

AssignCopy

*/

TEST(AssignCopy, ordinary1) {
  S21::S21Matrix matrix1(6, 2);
  S21::S21Matrix matrix2 = matrix1;
  matrix2 = matrix1;
  EXPECT_EQ(matrix2.get_rows(), 6);
  EXPECT_EQ(matrix2.get_cols(), 2);
}

TEST(AssignCopy, ordinary2) {
  S21::S21Matrix matrix1(2, 6);
  S21::S21Matrix matrix2(7, 2);
  matrix2 = matrix1;
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 6);
}

TEST(AssignCopy, ordinary3) {
  S21::S21Matrix matrix1(1, 1);
  S21::S21Matrix matrix2;
  matrix2 = matrix1;
  EXPECT_EQ(matrix2.get_rows(), 1);
  EXPECT_EQ(matrix2.get_cols(), 1);
}

TEST(AssignCopy, ordinary4) {
  S21::S21Matrix matrix1(4, 4);
  S21::S21Matrix& ref = matrix1;
  matrix1 = ref;
  EXPECT_EQ(matrix1.get_rows(), 4);
  EXPECT_EQ(matrix1.get_cols(), 4);
}

/*

AssignMove

*/

TEST(AssignMove, ordinary1) {
  S21::S21Matrix matrix1(6, 2);
  S21::S21Matrix matrix2 = std::move(matrix1);
  EXPECT_EQ(matrix2.get_rows(), 6);
  EXPECT_EQ(matrix2.get_cols(), 2);
}

TEST(AssignMove, ordinary2) {
  S21::S21Matrix matrix1(2, 6);
  S21::S21Matrix matrix2 = std::move(matrix1);
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 6);
}

TEST(AssignMove, ordinary3) {
  S21::S21Matrix matrix1(1, 1);
  S21::S21Matrix matrix2 = std::move(matrix1);
  EXPECT_EQ(matrix2.get_rows(), 1);
  EXPECT_EQ(matrix2.get_cols(), 1);
}

/*

MulMatrixOperator

*/

TEST(MulMatrixOperator, ordinary1) {
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

  S21::S21Matrix matrix3 = matrix1 * matrix2;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      EXPECT_EQ(matrix3.get_value(i, j), ref[i][j]);
    }
  }
}

TEST(MulMatrixOperator, ordinary2) {
  S21::S21Matrix matrix1(3, 3);
  std::vector<std::vector<double>> arr1 = {{5, 8, -4}, {6, 9, -5}, {4, 7, -3}};
  matrix1.FillFrom2DArr(arr1);

  S21::S21Matrix matrix2(3, 1);
  matrix2.set_value(0, 0, 2);
  matrix2.set_value(1, 0, -3);
  matrix2.set_value(2, 0, 1);

  S21::S21Matrix matrix3 = matrix1 * matrix2;

  EXPECT_EQ(matrix3.get_value(0, 0), -18);
  EXPECT_EQ(matrix3.get_value(1, 0), -20);
  EXPECT_EQ(matrix3.get_value(2, 0), -16);
}

TEST(MulMatrixOperator, throw1) {
  S21::S21Matrix matrix1(3, 3);
  S21::S21Matrix matrix2(4, 1);

  EXPECT_THROW(
      { S21::S21Matrix matrix3 = matrix1 * matrix2; }, std::invalid_argument);
}

TEST(MulMatrixOperator, throw2) {
  S21::S21Matrix matrix1(3, 4);
  S21::S21Matrix matrix2(1, 1);

  EXPECT_THROW(
      { S21::S21Matrix matrix3 = matrix1 * matrix2; }, std::invalid_argument);
}

/*

MulMatrixAssignOperator

*/

TEST(MulMatrixAssignOperator, ordinary1) {
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

  matrix1 *= matrix2;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      EXPECT_EQ(matrix1.get_value(i, j), ref[i][j]);
    }
  }
}

TEST(MulMatrixAssignOperator, ordinary2) {
  S21::S21Matrix matrix1(3, 3);
  std::vector<std::vector<double>> arr1 = {{5, 8, -4}, {6, 9, -5}, {4, 7, -3}};
  matrix1.FillFrom2DArr(arr1);

  S21::S21Matrix matrix2(3, 1);
  matrix2.set_value(0, 0, 2);
  matrix2.set_value(1, 0, -3);
  matrix2.set_value(2, 0, 1);

  matrix1 *= matrix2;

  EXPECT_EQ(matrix1.get_value(0, 0), -18);
  EXPECT_EQ(matrix1.get_value(1, 0), -20);
  EXPECT_EQ(matrix1.get_value(2, 0), -16);
}

TEST(MulMatrixAssignOperator, throw1) {
  S21::S21Matrix matrix1(3, 3);
  S21::S21Matrix matrix2(4, 1);

  EXPECT_THROW({ matrix1 *= matrix2; }, std::invalid_argument);
}

TEST(MulMatrixAssignOperator, throw2) {
  S21::S21Matrix matrix1(3, 4);
  S21::S21Matrix matrix2(1, 1);

  EXPECT_THROW({ matrix1 *= matrix2; }, std::invalid_argument);
}

/*

MulAssignNumberOperator

*/

TEST(MulAssignNumberOperator, ordinary1) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  matrix1 *= 2;

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_EQ(matrix1.get_value(i, j), 2 * arr[i][j]);
    }
  }
}

TEST(MulAssignNumberOperator, ordinary2) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  matrix1 *= 0;

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_EQ(matrix1.get_value(i, j), 0 * arr[i][j]);
    }
  }
}

TEST(MulAssignNumberOperator, ordinary3) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  matrix1 *= 2.323153219;

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_EQ(matrix1.get_value(i, j), 2.323153219 * arr[i][j]);
    }
  }
}

TEST(MulAssignNumberOperator, ordinary4) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  matrix1 *= -2.323153219;

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_EQ(matrix1.get_value(i, j), -2.323153219 * arr[i][j]);
    }
  }
}

TEST(MulAssignNumberOperator, ordinary5) {
  S21::S21Matrix matrix1(2, 2);
  std::vector<std::vector<double>> arr = {{1, -2}, {0, 0}};
  matrix1.FillFrom2DArr(arr);

  matrix1 *= -2.323153219;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      EXPECT_EQ(matrix1.get_value(i, j), -2.323153219 * arr[i][j]);
    }
  }
}

TEST(MulAssignNumberOperator, ordinary6) {
  S21::S21Matrix matrix1(2, 1);

  matrix1 *= 321;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 1; j++) {
      EXPECT_EQ(matrix1.get_value(i, j), 321 * 0);
    }
  }
}

/*

MulNumberOperator

*/

TEST(MulNumberOperator, ordinary1) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2 = matrix1 * 2;

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_EQ(matrix2.get_value(i, j), 2 * arr[i][j]);
    }
  }

  S21::S21Matrix matrix3 = 2.0 * matrix1;

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_EQ(matrix3.get_value(i, j), 2 * arr[i][j]);
    }
  }
}

TEST(MulNumberOperator, ordinary2) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2 = matrix1 * 0;

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_EQ(matrix2.get_value(i, j), 0 * arr[i][j]);
    }
  }

  S21::S21Matrix matrix3 = 0.0 * matrix1;

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_EQ(matrix3.get_value(i, j), 0 * arr[i][j]);
    }
  }
}

TEST(MulNumberOperator, ordinary3) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2 = matrix1 * 2.323153219;

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_EQ(matrix2.get_value(i, j), 2.323153219 * arr[i][j]);
    }
  }

  S21::S21Matrix matrix3 = 2.323153219 * matrix1;

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_EQ(matrix3.get_value(i, j), 2.323153219 * arr[i][j]);
    }
  }
}

TEST(MulNumberOperator, ordinary4) {
  S21::S21Matrix matrix1;
  std::vector<std::vector<double>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2 = matrix1 * -2.323153219;

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_EQ(matrix2.get_value(i, j), -2.323153219 * arr[i][j]);
    }
  }

  S21::S21Matrix matrix3 = -2.323153219 * matrix1;

  for (int i = 0; i < DEFAULT_ROWS; i++) {
    for (int j = 0; j < DEFAULT_COLS; j++) {
      EXPECT_EQ(matrix3.get_value(i, j), -2.323153219 * arr[i][j]);
    }
  }
}

TEST(MulNumberOperator, ordinary5) {
  S21::S21Matrix matrix1(2, 2);
  std::vector<std::vector<double>> arr = {{1, -2}, {0, 0}};
  matrix1.FillFrom2DArr(arr);

  S21::S21Matrix matrix2 = matrix1 * -2.323153219;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      EXPECT_EQ(matrix2.get_value(i, j), -2.323153219 * arr[i][j]);
    }
  }

  S21::S21Matrix matrix3 = -2.323153219 * matrix1;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      EXPECT_EQ(matrix3.get_value(i, j), -2.323153219 * arr[i][j]);
    }
  }
}

TEST(MulNumberOperator, ordinary6) {
  S21::S21Matrix matrix1(2, 1);
  matrix1.set_value(0, 0, 2.323);

  S21::S21Matrix matrix2 = matrix1 * 321;

  EXPECT_EQ(matrix2.get_value(0, 0), 321 * 2.323);
  EXPECT_EQ(matrix2.get_value(1, 0), 0);

  S21::S21Matrix matrix3 = 321.0 * matrix1;

  EXPECT_EQ(matrix3.get_value(0, 0), 321 * 2.323);
  EXPECT_EQ(matrix3.get_value(1, 0), 0);
}