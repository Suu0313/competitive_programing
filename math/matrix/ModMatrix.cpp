template <typename T>
struct Matrix{
  vector<vector<T>> A;

  Matrix() {}
  Matrix(size_t n, size_t m, T e = 0): A(n, vector<T>(m, e)) {}
  Matrix(size_t n): A(n, vector<T>(n)) {}
  Matrix(const vector<vector<T>> &e): A(e) {}
  Matrix(const initializer_list<initializer_list<T>> &x): A(x.begin(),x.end()) {}
  
  size_t height() const { return A.size(); }
  size_t width() const { return A.at(0).size(); }

  vector<T> &operator[](int k) { return A.at(k); }
  const vector<T> &operator[](int k) const { return A.at(k); }
  vector<T> &at(int k) { return A.at(k); }
  const vector<T> &at(int k) const { return A.at(k); }

  Matrix &operator+=(const Matrix &B){
    assert(height() == B.height() && width() == B.width());
    size_t n = height(), m = width();
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        (*this)[i][j] += B[i][j];
    return (*this);
  }

  Matrix &operator-=(const Matrix &B){
    assert(height() == B.height() && width() == B.width());
    size_t n = height(), m = width();
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        (*this)[i][j] -= B[i][j];
    return (*this);
  }

  Matrix &operator*=(const Matrix &B){
    assert(width() == B.height());
    size_t n = height(), m = B.width(), l = width();
    vector<vector<T>> C(n, vector<T>(m));
    for (size_t i = 0; i < n; i++)
      for (size_t k = 0; k < l; k++)
        for (size_t j = 0; j < m; j++)
          C[i][j] += (*this)[i][k] * B[k][j];
    A.swap(C);
    return (*this);
  }

  Matrix &operator*=(const T &c){
    size_t n = height(), m = width();
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        (*this)[i][j] *= c;
    return (*this);
  }

  Matrix &operator/=(const T &c){
    return (*this) *= T(1)/c;
  }

  Matrix &operator^=(long long k){
    assert(height() == width());
    Matrix B = Matrix::I(height());
    while(k > 0){
      if(k&1) B *= *this;
      *this *= *this;
      k >>= 1;
    }
    A.swap(B.A);
    return (*this);
  }

  Matrix operator+(const Matrix &B) const { return Matrix(*this) += B; }
  Matrix operator-(const Matrix &B) const { return Matrix(*this) -= B; }
  Matrix operator*(const Matrix &B) const { return Matrix(*this) *= B; }
  Matrix operator^(const long long k) const { return Matrix(*this) ^= k; }
  Matrix operator*(const T &c) const { return Matrix(*this) *= c; }
  Matrix operator/(const T &c) const { return Matrix(*this) /= c; }

  vector<T> operator*(const vector<T> &x) const {
    assert(width() == x.size());
    size_t n = height(), m = width();
    vector<T> res(n);
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        res[i] += (*this)[i][j] * x[j];
    return res;
  }

  Matrix Transpose() const {
    size_t n = height(), m = width();
    Matrix res(m, n);
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        res[j][i] = (*this)[i][j];
    return res;
  }

  friend istream &operator>>(istream &is, Matrix &p){
    size_t n = p.height(), m = p.width();
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        is >>  p[i][j];
    return (is);
  }

  friend ostream &operator<<(ostream &os, const Matrix &p){
    size_t n = p.height(), m = p.width();
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        os << p[i][j] << " \n"[j+1==m];
    return (os);
  }

  static Matrix I(size_t n){
    Matrix res(n);
    for (size_t i = 0; i < n; i++) res[i][i] = 1;
    return res;
  }

  size_t GaussJordan(bool is_extended = false){
    size_t n = height(), m = width();
    size_t rank = 0;
    for(size_t col = 0; col < m; ++col){
      if(is_extended && col == m-1) break;
      int pivot = -1;
      for(size_t row = rank; row < n; ++row){
        if(A[row][col] != 0){
          pivot = row; break;
        }
      }
      if(pivot == -1) break;
      swap(A[pivot], A[rank]);
      T finv = T(1)/A[rank][col];
      for(size_t col2 = 0; col2 < m; ++col2) A[rank][col2] *= finv;
      for(size_t row = 0; row < n; ++row){
        if(row != rank && A[row][col] != 0){
          T fac = A[row][col];
          for(size_t col2 = 0; col2 < m; ++col2){
            A[row][col2] -= A[rank][col2] * fac;
          }
        }
      }
      ++rank;
    }
    return rank;
  }

  vector<T> linear_equation(vector<T> &b){
    assert(height() == b.size());
    size_t n = height(), m = width();
    Matrix M(n, m+1);
    for (size_t i = 0; i < n; i++){
      for (size_t j = 0; j < m; j++) M[i][j] = (*this)[i][j];
      M[i][m] = b[i];
    }
    size_t rank = M.GaussJordan(true);

    vector<T> res;
    for(size_t row = rank; row < n; ++row){
      if(M[row][m] != 0) return res;
    }

    res.assign(m, 0);
    for(size_t i = 0; i < rank; ++i) res[i] = M[i][m];
    return res;
  }

  Matrix inv() const {
    assert(height() == width());
    size_t n = height();
    Matrix M(n, n*2);
    for (size_t i = 0; i < n; i++){
      for (size_t j = 0; j < n; j++) M[i][j] = (*this)[i][j];
      M[i][i+n] = 1;
    }
    size_t rank = M.GaussJordan();
    if(rank != n) return {};
    Matrix res(n);
    for (size_t i = 0; i < n; i++){
      for (size_t j = 0; j < n; j++){
        res[i][j] = M[i][j+n];
      }
    }
    return res;
  }

  T determinant() const {
    assert(height() == width());
    Matrix M(*this);
    size_t n = height();
    T res = 1;
    for(size_t col = 0; col < n; ++col){
      int pivot = -1;
      for(size_t row = col; row < n; ++row){
        if(M[row][col] != 0){
          pivot = row; break;
        }
      }
      if(pivot == -1) return 0;
      if(col != pivot){
        res *= -1; swap(M[col], M[pivot]);
      }
      res *= M[col][col];
      T finv = T(1)/M[col][col];
      for(size_t col2 = 0; col2 < n; ++col2) M[col][col2] *= finv;
      for(size_t row = col+1; row < n; ++row){
        T fac = M[row][col];
        for(size_t col2 = 0; col2 < n; ++col2){
          M[row][col2] -= M[col][col2] * fac;
        }
      }
    }
    return res;
  }

  T minordet(int i, int j) const {
    assert(height() == width());
    size_t n = height();
    if(n == 1) return 1;
    Matrix M(n-1);
    for(size_t row = 0; row < n; ++row){
      for(size_t col = 0; col < n; ++col){
        if(row == i || col == j) continue;
        M[row-(row>i)][col-(col>j)] = (*this)[row][col];
      }
    }
    return M.determinant() * ((i+j)%2 ? -1 : 1);
  }
};
