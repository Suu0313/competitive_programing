template <typename T>
struct Matrix{
  valarray<valarray<T>> a;

  Matrix() {}
  Matrix(size_t n, size_t m, T e = 0): a(valarray<T>(e, m), n) {}
  Matrix(size_t n): a(valarray<T>(n), n) {}
  Matrix(const valarray<valarray<T>> &e): a(e) {}
  Matrix(const initializer_list<initializer_list<T>> &x): a(x) {}
  
  size_t height() const { return a.size(); }
  size_t width() const { return a[0].size(); }

  valarray<T> &operator[](int k) { return a[k]; }
  const valarray<T> &operator[](int k) const { return a[k]; }

  T sum() const { return a.sum().sum(); }

  Matrix &operator+=(const Matrix &b){
    (*this).a += b.a; return (*this);
  }

  Matrix &operator-=(const Matrix &b){
    (*this).a -= b.a; return (*this);
  }

  Matrix &operator*=(const Matrix &b){
    assert((*this).width() == b.height());
    size_t n = height(), m = b.width();

    Matrix c(n, m), d(b.Transpose());
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        c[i][j] = ((*this)[i] * d[j]).sum();

    (*this).a = c.a;
    return (*this);
  }

  Matrix &operator*=(const T &b){
    for (auto &&e : (*this.a)) e *= b;
    return (*this);
  }

  Matrix &operator^=(long long k){
    assert((*this).height() == (*this).width());
    Matrix b = Matrix::I(height());
    while(k > 0){
      if(k&1) b *= (*this);
      (*this) *= (*this);
      k >>= 1;
    }
    (*this).a = b.a;
    return (*this);
  }

  Matrix operator+(const Matrix &b) const {
    return Matrix(*this) += b;
  }
  Matrix operator-(const Matrix &b) const {
    return Matrix(*this) -= b;
  }
  Matrix operator*(const Matrix &b) const {
    return Matrix(*this) *= b;
  }
  Matrix operator*(const T &b) const {
    return Matrix(*this) *= b;
  }
  Matrix operator^(const long long k) const {
    return Matrix(*this) ^= k;
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
      T ma = 1e-10;
      for(size_t row = 0; row < n; ++row){
        if(abs((*this)[row][col]) > ma){
          ma = abs((*this)[row][col]); pivot = row;
        }
      }
      if(pivot == -1) continue;
      swap((*this)[pivot], (*this)[rank]);
      T fac = (*this)[rank][col];
      (*this)[rank] /= fac;
      for(size_t row = 0; row < n; ++row){
        if(row != rank && abs((*this)[row][col]) > T(1e-10)){
          T fac = (*this)[row][col];
          (*this)[row] -= (*this)[rank] * fac;
        }
      }
      ++rank;
    }
    return rank;
  }

  valarray<T> linear_equation(const valarray<T> &b){
    size_t n = height(), m = width();
    Matrix M(n, m+1);
    for (size_t i = 0; i < n; i++){
      for (size_t j = 0; j < m; j++){
        M[i][j] = (*this)[i][j];
      }
      M[i][m] = b[i];
    }
    size_t rank = M.GaussJordan(true);

    valarray<T> res; // it has bug! to fix!!
    for(size_t row = rank; row < m; ++row){
      if(abs(M[row][m]) > T(1e-10)) return res;
    }
    res.resize(m, 0);
    for(size_t i = 0; i < rank; ++i) res[i] = M[i][m];
    return res;
  }

  T determinant(){
    // ToDo
  }
};
