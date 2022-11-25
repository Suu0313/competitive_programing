template<typename T>
struct Matrix{
  vector<vector<T>> a;
  Matrix() = default;
  Matrix(size_t n): Matrix(n, n) {}
  Matrix(size_t n, size_t m, const T &e = T()): a(n, vector<T>(m, e)) {}
  Matrix(const vector<vector<T>> &a): a(a) {}

  Matrix(const Matrix&) = default;
  Matrix(Matrix&&) = default;
  Matrix &operator=(const Matrix&) = default;
  Matrix &operator=(Matrix&&) = default;

  size_t height() const { return a.size(); }
  size_t width() const { return a[0].size(); }

  vector<T> &operator[](size_t k) { return a[k]; }
  const vector<T> &operator[](size_t k) const { return a[k]; }

  static Matrix I(size_t n){
    Matrix res(n);
    for (size_t i = 0; i < n; i++) res[i][i] = 1;
    return res;
  }

  Matrix Transpose() const {
    size_t n = height(), m = width();
    Matrix res(m, n);
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        res[j][i] = a[i][j];
    return res;
  }

  Matrix &operator+=(const Matrix &b){
    assert(height() == b.height() && width() == b.width());
    size_t n = height(), m = width();
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        (*this)[i][j] += b[i][j];
    return (*this);
  }
  
  Matrix &operator-=(const Matrix &b){
    assert(height() == b.height() && width() == b.width());
    size_t n = height(), m = width();
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        (*this)[i][j] -= b[i][j];
    return (*this);
  }

  Matrix &operator*=(const T &c){
    size_t n = height(), m = width();
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        (*this)[i][j] *= c;
    return (*this);
  }

  Matrix &operator*=(const Matrix &b){
    assert(width() == b.height());
    size_t n = height(), m = b.width(), l = width();
    vector<vector<T>> c(n, vector<T>(m));
    for (size_t i = 0; i < n; i++)
      for (size_t k = 0; k < l; k++)
        for (size_t j = 0; j < m; j++)
          c[i][j] += (*this)[i][k] * b[k][j];
    a.swap(c);
    return (*this);
  }

  Matrix &operator/=(const T &c){
    return (*this) *= T(1)/c;
  }

  Matrix &operator^=(int64_t k){
    assert(height() == width());
    Matrix m = Matrix::I(height());
    while(k > 0){
      if(k&1) m *= (*this);
      (*this) *= (*this); k >>= 1;
    }
    a.swap(m.a);
    return (*this);
  }

  Matrix operator-() const {
    Matrix m(*this);
    for(auto&&v : m.a) for(auto&&e : v) e = -e;
    return m;
  }

  Matrix operator+(const Matrix &b) const { return Matrix(*this) += b; }
  Matrix operator-(const Matrix &b) const { return Matrix(*this) -= b; }
  Matrix operator*(const T &c) const { return Matrix(*this) *= c; }
  Matrix operator*(const Matrix &b) const { return Matrix(*this) *= b; }
  Matrix operator/(const T &c) const { return Matrix(*this) /= c; }
  Matrix operator^(int64_t k) const { return Matrix(*this) ^= k; }

  Matrix pow(int64_t k) const { return (*this) ^ k; }

  vector<T> operator*(const vector<T> &x) const {
    assert(width() == x.size());
    size_t n = height(), m = width();
    vector<T> res(n);
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        res[i] += (*this)[i][j] * x[j];
    return res;
  }

  T sum() const {
    T res = 0;
    for(const auto& v : a) res += accumulate(begin(v), end(v), T(0));
    return res;
  }

  T tr() const {
    T res = 0;
    for(size_t i = 0, n = height(); i < n; ++i) res += (*this)[i][i];
    return res;
  }

  #define def_cmp(cmp) bool operator cmp (const Matrix &b) const { return a cmp b.a; }
  def_cmp(==)
  def_cmp(!=)
  def_cmp(<)
  def_cmp(>)
  def_cmp(<=)
  def_cmp(>=)
  #undef def_cmp
  

  friend istream &operator>>(istream &is, Matrix &p){
    size_t n = p.height(), m = p.width();
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        is >> p[i][j];
    return (is);
  }

  friend ostream &operator<<(ostream &os, const Matrix &p){
    size_t n = p.height(), m = p.width();
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        os << p[i][j] << " \n"[j+1==m];
    return (os);
  }
};
