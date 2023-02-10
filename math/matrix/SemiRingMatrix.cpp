#pragma once


template <typename SemiRing>
struct SemiRingMatrix{
  vector<vector<SemiRing>> A;

  SemiRingMatrix() {}
  SemiRingMatrix(size_t n, size_t m, SemiRing e = SemiRing::e()): A(n, vector<SemiRing>(m, e)) {}
  SemiRingMatrix(size_t n): A(n, vector<SemiRing>(n)) {}
  SemiRingMatrix(const vector<vector<SemiRing>> &e): A(e) {}
  SemiRingMatrix(const initializer_list<initializer_list<SemiRing>> &x): A(x.begin(),x.end()) {}
  
  size_t height() const { return A.size(); }
  size_t width() const { return A.at(0).size(); }

  vector<SemiRing> &operator[](int k) { return A.at(k); }
  const vector<SemiRing> &operator[](int k) const { return A.at(k); }
  vector<SemiRing> &at(int k) { return A.at(k); }
  const vector<SemiRing> &at(int k) const { return A.at(k); }

  SemiRingMatrix &operator+=(const SemiRingMatrix &B){
    assert(height() == B.height() && width() == B.width());
    size_t n = height(), m = width();
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        (*this)[i][j] += B[i][j];
    return (*this);
  }

  SemiRingMatrix &operator-=(const SemiRingMatrix &B){
    assert(height() == B.height() && width() == B.width());
    size_t n = height(), m = width();
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        (*this)[i][j] -= B[i][j];
    return (*this);
  }

  SemiRingMatrix &operator*=(const SemiRingMatrix &B){
    assert(width() == B.height());
    size_t n = height(), m = B.width(), l = width();
    vector<vector<SemiRing>> C(n, vector<SemiRing>(m, SemiRing::id()));
    for (size_t i = 0; i < n; i++)
      for (size_t k = 0; k < l; k++)
        for (size_t j = 0; j < m; j++)
          C[i][j] += (*this)[i][k] * B[k][j];
    A.swap(C);
    return (*this);
  }

  SemiRingMatrix &operator*=(const SemiRing &c){
    size_t n = height(), m = width();
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        (*this)[i][j] *= c;
    return (*this);
  }

  SemiRingMatrix &operator/=(const SemiRing &c){
    return (*this) *= SemiRing(1)/c;
  }

  SemiRingMatrix &operator^=(long long k){
    assert(height() == width());
    SemiRingMatrix B = SemiRingMatrix::I(height());
    while(k > 0){
      if(k&1) B *= *this;
      *this *= *this;
      k >>= 1;
    }
    A.swap(B.A);
    return (*this);
  }

  SemiRingMatrix operator+(const SemiRingMatrix &B) const { return SemiRingMatrix(*this) += B; }
  SemiRingMatrix operator-(const SemiRingMatrix &B) const { return SemiRingMatrix(*this) -= B; }
  SemiRingMatrix operator*(const SemiRingMatrix &B) const { return SemiRingMatrix(*this) *= B; }
  SemiRingMatrix operator^(const long long k) const { return SemiRingMatrix(*this) ^= k; }
  SemiRingMatrix operator*(const SemiRing &c) const { return SemiRingMatrix(*this) *= c; }
  SemiRingMatrix operator/(const SemiRing &c) const { return SemiRingMatrix(*this) /= c; }

  vector<SemiRing> operator*(const vector<SemiRing> &x) const {
    assert(width() == x.size());
    size_t n = height(), m = width();
    vector<SemiRing> res(n, SemiRing::id());
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        res[i] += (*this)[i][j] * x[j];
    return res;
  }

  SemiRingMatrix Transpose() const {
    size_t n = height(), m = width();
    SemiRingMatrix res(m, n);
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        res[j][i] = (*this)[i][j];
    return res;
  }

  friend istream &operator>>(istream &is, SemiRingMatrix &p){
    size_t n = p.height(), m = p.width();
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        is >>  p[i][j];
    return (is);
  }

  friend ostream &operator<<(ostream &os, const SemiRingMatrix &p){
    size_t n = p.height(), m = p.width();
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        os << p[i][j] << " \n"[j+1==m];
    return (os);
  }

  static SemiRingMatrix I(size_t n){
    SemiRingMatrix res(n, n, SemiRing::id());
    for (size_t i = 0; i < n; i++) res[i][i] = SemiRing::e();
    return res;
  }
};
