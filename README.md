## 🧮 MatrixCPP

### Implementation of library for work with matrix
🚀 Developed in a OOP programming style in C++ language.

📑 98%+ coveraged by unit test with Google test

  #### Ctors and dtor
  
  - S21Matrix();
  - S21Matrix(int rows, int cols);
  - S21Matrix(const S21Matrix& other);
  - S21Matrix(S21Matrix&& other) noexcept;
  - ~S21Matrix();

  #### Accessors and mutators
  - int get_rows() const;
  - int get_cols() const;
  - void set_rows(int new_rows);
  - void set_cols(int new_cols);
  - double get_value(int row, int column) const;
  - void set_value(int row, int column, double value) const;

  #### Main methods
  - bool EqMatrix(const S21Matrix& other) const;
  - void SumMatrix(const S21Matrix& other);
  - void SubMatrix(const S21Matrix& other);
  - void MulNumber(const double num);
  - void MulMatrix(const S21Matrix& other);
  - S21Matrix Transpose() const;
  - S21Matrix CalcComplements() const;
  - double Determinant() const;
  - S21Matrix InverseMatrix() const;

  #### Aux methods
  - void FillFrom2DArr(std::vector<std::vector<double>>& arr);
  - void Clean();

  #### Operators
  - S21Matrix operator+(const S21Matrix& other) const;
  - S21Matrix operator-(const S21Matrix& other) const;
  - S21Matrix operator*(const S21Matrix& other) const;
  - S21Matrix operator*(const double num) const;
  - bool operator==(const S21Matrix& other) const;
  - S21Matrix& operator=(const S21Matrix& other);
  - S21Matrix& operator=(S21Matrix&& other);
  - S21Matrix& operator+=(const S21Matrix& other);
  - S21Matrix& operator-=(const S21Matrix& other);
  - S21Matrix& operator*=(const S21Matrix& other);
  - S21Matrix& operator*=(const double num);
  - double& operator()(int i, int j) const;
  - S21Matrix operator*(const double lhs, const S21Matrix rhs);



