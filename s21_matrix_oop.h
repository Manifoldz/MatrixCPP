#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

#include <cmath>    // used abs for compare
#include <cstring>  // used memcpy in copy ctor
#include <iostream>
#include <limits>
#include <vector>  // used vectors for filling matrix

#define PRECISION 0.0000001
#define DEFAULT_ROWS 3
#define DEFAULT_COLS 3

namespace S21 {

class S21Matrix {
  // Attributes
  int rows_, cols_;
  double** matrix_;

  // Helpers
  void Allocation();
  void Deallocation();
  double RecursiveDeterminant(bool* ban_rows, bool* ban_cols) const;
  double Minor(bool* ban_rows, bool* ban_cols) const;

 public:
  // Ctors and dtor
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix();

  // Accessors and mutators
  int get_rows() const;
  int get_cols() const;
  void set_rows(int new_rows);
  void set_cols(int new_cols);
  double get_value(int row, int column) const;
  void set_value(int row, int column, double value) const;

  // Main methods
  bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() const;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;

  // Aux methods
  void FillFrom2DArr(std::vector<std::vector<double>>& arr);
  void Clean();

  // Operators
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*(const double num) const;
  bool operator==(const S21Matrix& other) const;
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  double& operator()(int i, int j) const;
};

S21Matrix operator*(const double lhs, const S21Matrix rhs);

}  // namespace S21

#endif