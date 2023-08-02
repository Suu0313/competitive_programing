---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/matrix/MatrixTree.cpp
    title: math/matrix/MatrixTree.cpp
  - icon: ':warning:'
    path: math/matrix/determinant.cpp
    title: math/matrix/determinant.cpp
  - icon: ':warning:'
    path: math/matrix/inverse.cpp
    title: math/matrix/inverse.cpp
  - icon: ':warning:'
    path: math/matrix/linear_equation.cpp
    title: math/matrix/linear_equation.cpp
  - icon: ':warning:'
    path: math/matrix/minordet.cpp
    title: math/matrix/minordet.cpp
  - icon: ':warning:'
    path: math/matrix/rank.cpp
    title: math/matrix/rank.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix/Matrix.cpp\"\n\r\ntemplate<typename T>\r\nstruct\
    \ Matrix{\r\n  vector<vector<T>> a;\r\n  Matrix() = default;\r\n  Matrix(size_t\
    \ n): Matrix(n, n) {}\r\n  Matrix(size_t n, size_t m, const T &e = T()): a(n,\
    \ vector<T>(m, e)) {}\r\n  Matrix(const vector<vector<T>> &a): a(a) {}\r\n\r\n\
    \  Matrix(const Matrix&) = default;\r\n  Matrix(Matrix&&) = default;\r\n  Matrix\
    \ &operator=(const Matrix&) = default;\r\n  Matrix &operator=(Matrix&&) = default;\r\
    \n\r\n  size_t height() const { return a.size(); }\r\n  size_t width() const {\
    \ return a[0].size(); }\r\n\r\n  vector<T> &operator[](size_t k) { return a[k];\
    \ }\r\n  const vector<T> &operator[](size_t k) const { return a[k]; }\r\n\r\n\
    \  static Matrix I(size_t n){\r\n    Matrix res(n);\r\n    for (size_t i = 0;\
    \ i < n; i++) res[i][i] = 1;\r\n    return res;\r\n  }\r\n\r\n  Matrix Transpose()\
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
    \   os << p[i][j] << \" \\n\"[j+1==m];\r\n    return (os);\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct Matrix{\r\n  vector<vector<T>>\
    \ a;\r\n  Matrix() = default;\r\n  Matrix(size_t n): Matrix(n, n) {}\r\n  Matrix(size_t\
    \ n, size_t m, const T &e = T()): a(n, vector<T>(m, e)) {}\r\n  Matrix(const vector<vector<T>>\
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
    \   os << p[i][j] << \" \\n\"[j+1==m];\r\n    return (os);\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix/Matrix.cpp
  requiredBy:
  - math/matrix/rank.cpp
  - math/matrix/linear_equation.cpp
  - math/matrix/minordet.cpp
  - math/matrix/determinant.cpp
  - math/matrix/inverse.cpp
  - math/matrix/MatrixTree.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix/Matrix.cpp
layout: document
redirect_from:
- /library/math/matrix/Matrix.cpp
- /library/math/matrix/Matrix.cpp.html
title: math/matrix/Matrix.cpp
---
