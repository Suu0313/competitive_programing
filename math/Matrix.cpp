template <typename T>
struct Matrix{
  using mat = vector<vector<T>>;
  mat A;

  Matrix() {}
  Matrix(size_t n, size_t m, T e = 0): A(n, vector<T>(m, e)) {}
  Matrix(size_t n): A(n, vector<T>(n)) {}
  Matrix(mat e): A(e) {}
  Matrix(initializer_list<initializer_list<T>> x): A(x.begin(),x.end()) {}
  
  size_t height() const { return A.size(); }
  size_t width() const { return A.at(0).size(); }

  vector<T> &operator[](int k) { return A.at(k); }
  const vector<T> &operator[](int k) const { return A.at(k); }
  vector<T> &at(int k) { return A.at(k); }
  const vector<T> &at(int k) const { return A.at(k); }

  Matrix &operator+=(const Matrix &B){
    size_t n = height(), m = width();
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        (*this)[i][j] += B[i][j];
    return (*this);
  }

  Matrix &operator-=(const Matrix &B){
    size_t n = height(), m = width();
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        (*this)[i][j] -= B[i][j];
    return (*this);
  }

  Matrix &operator*=(const Matrix &B){
    size_t n = height(), m = B.width(), l = width();
    mat C(n, vector<T> (m));
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        for (size_t k = 0; k < l; k++)
          C[i][j] += (*this)[i][k] * B[k][j];
    A.swap(C);
    return (*this);
  }

  Matrix &operator^=(long long k){
    Matrix B = Matrix::I(height());
    while(k > 0){
      if(k&1) B *= *this;
      *this *= *this;
      k >>= 1;
    }
    A.swap(B.A);
    return (*this);
  }

  Matrix operator+(const Matrix &B) const {
    return Matrix(*this) += B;
  }
  Matrix operator-(const Matrix &B) const {
    return Matrix(*this) -= B;
  }
  Matrix operator*(const Matrix &B) const {
    return Matrix(*this) *= B;
  }
  Matrix operator^(const long long k) const {
    return Matrix(*this) ^= k;
  }

  friend istream &operator>>(istream &is, Matrix &p){
    size_t n = p.height(), m = p.width();
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        is >>  p[i][j];
    return (is);
  }

  friend ostream &operator<<(ostream &os, Matrix &p){
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
      T ma = EPS;
      for(size_t row = 0; row < n; ++row){
        if(abs(A[row][col]) > ma){
          ma = abs(A[row][col]); pivot = row;
        }
      }
      if(pivot == -1) continue;
      swap(A[pivot], A[rank]);
      T fac = A[rank][col];
      for(size_t col2 = 0; col2 < m; ++col2) A[rank][col2] /= fac;
      for(size_t row = 0; row < n; ++row){
        if(row != rank && abs(A[row][col]) > EPS){
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
    size_t n = height(), m = width();
    Matrix M(n, m+1);
    for (size_t i = 0; i < n; i++){
      for (size_t j = 0; j < m; j++){
        M[i][j] = (*this)[i][j];
      }
      M[i][m] = b[i];
    }
    size_t rank = GaussJordan(true);

    vector<T> res;
    for(size_t row = rank; row < m; ++row){
      if(abs(M[row][n]) > EPS) return res;
    }

    res.assign(m, 0);
    for(size_t i = 0; i < rank; ++i) res[i] = M[i][m];
    return res;
  }

  T determinant(){
    // ToDo
  }
};