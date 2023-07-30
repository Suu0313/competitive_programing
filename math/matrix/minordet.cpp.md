---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/matrix/Matrix.cpp
    title: math/matrix/Matrix.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix/minordet.cpp\"\n\r\n#line 2 \"math/matrix/Matrix.cpp\"\
    \n\r\ntemplate<typename T>\r\nstruct Matrix{\r\n  vector<vector<T>> a;\r\n  Matrix()\
    \ = default;\r\n  Matrix(size_t n): Matrix(n, n) {}\r\n  Matrix(size_t n, size_t\
    \ m, const T &e = T()): a(n, vector<T>(m, e)) {}\r\n  Matrix(const vector<vector<T>>\
    \ &a): a(a) {}\r\n\r\n  Matrix(const Matrix&) = default;\r\n  Matrix(Matrix&&)\
    \ = default;\r\n  Matrix &operator=(const Matrix&) = default;\r\n  Matrix &operator=(Matrix&&)\
    \ = default;\r\n\r\n  size_t height() const { return a.size(); }\r\n  size_t width()\
    \ const { return a[0].size(); }\r\n\r\n  vector<T> &operator[](size_t k) { return\
    \ a[k]; }\r\n  const vector<T> &operator[](size_t k) const { return a[k]; }\r\n\
    \r\n  static Matrix I(size_t n){\r\n    Matrix res(n);\r\n    for (size_t i =\
    \ 0; i < n; i++) res[i][i] = 1;\r\n    return res;\r\n  }\r\n\r\n  Matrix Transpose()\
    \ const {\r\n    size_t n = height(), m = width();\r\n    Matrix res(m, n);\r\n\
    \    for (size_t i = 0; i < n; i++)\r\n      for (size_t j = 0; j < m; j++)\r\n\
    \        res[j][i] = a[i][j];\r\n    return res;\r\n  }\r\n\r\n  Matrix &operator+=(const\
    \ Matrix &b){\r\n    assert(height() == b.height() && width() == b.width());\r\
    \n    size_t n = height(), m = width();\r\n    for (size_t i = 0; i < n; i++)\r\
    \n      for (size_t j = 0; j < m; j++)\r\n        (*this)[i][j] += b[i][j];\r\n\
    \    return (*this);\r\n  }\r\n  \r\n  Matrix &operator-=(const Matrix &b){\r\n\
    \    assert(height() == b.height() && width() == b.width());\r\n    size_t n =\
    \ height(), m = width();\r\n    for (size_t i = 0; i < n; i++)\r\n      for (size_t\
    \ j = 0; j < m; j++)\r\n        (*this)[i][j] -= b[i][j];\r\n    return (*this);\r\
    \n  }\r\n\r\n  Matrix &operator*=(const T &c){\r\n    size_t n = height(), m =\
    \ width();\r\n    for (size_t i = 0; i < n; i++)\r\n      for (size_t j = 0; j\
    \ < m; j++)\r\n        (*this)[i][j] *= c;\r\n    return (*this);\r\n  }\r\n\r\
    \n  Matrix &operator*=(const Matrix &b){\r\n    assert(width() == b.height());\r\
    \n    size_t n = height(), m = b.width(), l = width();\r\n    vector<vector<T>>\
    \ c(n, vector<T>(m));\r\n    for (size_t i = 0; i < n; i++)\r\n      for (size_t\
    \ k = 0; k < l; k++)\r\n        for (size_t j = 0; j < m; j++)\r\n          c[i][j]\
    \ += (*this)[i][k] * b[k][j];\r\n    a.swap(c);\r\n    return (*this);\r\n  }\r\
    \n\r\n  Matrix &operator/=(const T &c){\r\n    return (*this) *= T(1)/c;\r\n \
    \ }\r\n\r\n  Matrix &operator^=(int64_t k){\r\n    assert(height() == width());\r\
    \n    Matrix m = Matrix::I(height());\r\n    while(k > 0){\r\n      if(k&1) m\
    \ *= (*this);\r\n      (*this) *= (*this); k >>= 1;\r\n    }\r\n    a.swap(m.a);\r\
    \n    return (*this);\r\n  }\r\n\r\n  Matrix operator-() const {\r\n    Matrix\
    \ m(*this);\r\n    for(auto&&v : m.a) for(auto&&e : v) e = -e;\r\n    return m;\r\
    \n  }\r\n\r\n  Matrix operator+(const Matrix &b) const { return Matrix(*this)\
    \ += b; }\r\n  Matrix operator-(const Matrix &b) const { return Matrix(*this)\
    \ -= b; }\r\n  Matrix operator*(const T &c) const { return Matrix(*this) *= c;\
    \ }\r\n  Matrix operator*(const Matrix &b) const { return Matrix(*this) *= b;\
    \ }\r\n  Matrix operator/(const T &c) const { return Matrix(*this) /= c; }\r\n\
    \  Matrix operator^(int64_t k) const { return Matrix(*this) ^= k; }\r\n\r\n  Matrix\
    \ pow(int64_t k) const { return (*this) ^ k; }\r\n\r\n  vector<T> operator*(const\
    \ vector<T> &x) const {\r\n    assert(width() == x.size());\r\n    size_t n =\
    \ height(), m = width();\r\n    vector<T> res(n);\r\n    for (size_t i = 0; i\
    \ < n; i++)\r\n      for (size_t j = 0; j < m; j++)\r\n        res[i] += (*this)[i][j]\
    \ * x[j];\r\n    return res;\r\n  }\r\n\r\n  T sum() const {\r\n    T res = 0;\r\
    \n    for(const auto& v : a) res += accumulate(begin(v), end(v), T(0));\r\n  \
    \  return res;\r\n  }\r\n\r\n  T tr() const {\r\n    T res = 0;\r\n    for(size_t\
    \ i = 0, n = height(); i < n; ++i) res += (*this)[i][i];\r\n    return res;\r\n\
    \  }\r\n\r\n  #define def_cmp(cmp) bool operator cmp (const Matrix &b) const {\
    \ return a cmp b.a; }\r\n  def_cmp(==)\r\n  def_cmp(!=)\r\n  def_cmp(<)\r\n  def_cmp(>)\r\
    \n  def_cmp(<=)\r\n  def_cmp(>=)\r\n  #undef def_cmp\r\n  \r\n\r\n  friend istream\
    \ &operator>>(istream &is, Matrix &p){\r\n    size_t n = p.height(), m = p.width();\r\
    \n    for (size_t i = 0; i < n; i++)\r\n      for (size_t j = 0; j < m; j++)\r\
    \n        is >> p[i][j];\r\n    return (is);\r\n  }\r\n\r\n  friend ostream &operator<<(ostream\
    \ &os, const Matrix &p){\r\n    size_t n = p.height(), m = p.width();\r\n    for\
    \ (size_t i = 0; i < n; i++)\r\n      for (size_t j = 0; j < m; j++)\r\n     \
    \   os << p[i][j] << \" \\n\"[j+1==m];\r\n    return (os);\r\n  }\r\n};\r\n#line\
    \ 4 \"math/matrix/minordet.cpp\"\n\r\ntemplate<typename T>\r\nT minordet(const\
    \ Matrix<T> &a, size_t i, size_t j){\r\n  assert(a.height() == a.width());\r\n\
    \  size_t n = a.height();\r\n  if(n == 1) return 1;\r\n  Matrix m(n - 1);\r\n\
    \  for(size_t r = 0; r < n; ++r){\r\n    for(size_t c = 0; c < n; ++c){\r\n  \
    \    if(r == i || c == j) continue;\r\n      m[r - (r>i)][c - (c>j)] = a[r][c];\r\
    \n    }\r\n  }\r\n  return determinant(m) * ((i+j)%2 ? -1 : 1);\r\n}\r\n"
  code: "#pragma once\r\n\r\n#include \"./Matrix.cpp\"\r\n\r\ntemplate<typename T>\r\
    \nT minordet(const Matrix<T> &a, size_t i, size_t j){\r\n  assert(a.height() ==\
    \ a.width());\r\n  size_t n = a.height();\r\n  if(n == 1) return 1;\r\n  Matrix\
    \ m(n - 1);\r\n  for(size_t r = 0; r < n; ++r){\r\n    for(size_t c = 0; c < n;\
    \ ++c){\r\n      if(r == i || c == j) continue;\r\n      m[r - (r>i)][c - (c>j)]\
    \ = a[r][c];\r\n    }\r\n  }\r\n  return determinant(m) * ((i+j)%2 ? -1 : 1);\r\
    \n}\r\n"
  dependsOn:
  - math/matrix/Matrix.cpp
  isVerificationFile: false
  path: math/matrix/minordet.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix/minordet.cpp
layout: document
redirect_from:
- /library/math/matrix/minordet.cpp
- /library/math/matrix/minordet.cpp.html
title: math/matrix/minordet.cpp
---
