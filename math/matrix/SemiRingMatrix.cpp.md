---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix/SemiRingMatrix.cpp\"\n\r\n\r\ntemplate <typename\
    \ SemiRing>\r\nstruct SemiRingMatrix{\r\n  vector<vector<SemiRing>> A;\r\n\r\n\
    \  SemiRingMatrix() {}\r\n  SemiRingMatrix(size_t n, size_t m, SemiRing e = SemiRing::e()):\
    \ A(n, vector<SemiRing>(m, e)) {}\r\n  SemiRingMatrix(size_t n): A(n, vector<SemiRing>(n))\
    \ {}\r\n  SemiRingMatrix(const vector<vector<SemiRing>> &e): A(e) {}\r\n  SemiRingMatrix(const\
    \ initializer_list<initializer_list<SemiRing>> &x): A(x.begin(),x.end()) {}\r\n\
    \  \r\n  size_t height() const { return A.size(); }\r\n  size_t width() const\
    \ { return A.at(0).size(); }\r\n\r\n  vector<SemiRing> &operator[](int k) { return\
    \ A.at(k); }\r\n  const vector<SemiRing> &operator[](int k) const { return A.at(k);\
    \ }\r\n  vector<SemiRing> &at(int k) { return A.at(k); }\r\n  const vector<SemiRing>\
    \ &at(int k) const { return A.at(k); }\r\n\r\n  SemiRingMatrix &operator+=(const\
    \ SemiRingMatrix &B){\r\n    assert(height() == B.height() && width() == B.width());\r\
    \n    size_t n = height(), m = width();\r\n    for (size_t i = 0; i < n; i++)\r\
    \n      for (size_t j = 0; j < m; j++)\r\n        (*this)[i][j] += B[i][j];\r\n\
    \    return (*this);\r\n  }\r\n\r\n  SemiRingMatrix &operator-=(const SemiRingMatrix\
    \ &B){\r\n    assert(height() == B.height() && width() == B.width());\r\n    size_t\
    \ n = height(), m = width();\r\n    for (size_t i = 0; i < n; i++)\r\n      for\
    \ (size_t j = 0; j < m; j++)\r\n        (*this)[i][j] -= B[i][j];\r\n    return\
    \ (*this);\r\n  }\r\n\r\n  SemiRingMatrix &operator*=(const SemiRingMatrix &B){\r\
    \n    assert(width() == B.height());\r\n    size_t n = height(), m = B.width(),\
    \ l = width();\r\n    vector<vector<SemiRing>> C(n, vector<SemiRing>(m, SemiRing::id()));\r\
    \n    for (size_t i = 0; i < n; i++)\r\n      for (size_t k = 0; k < l; k++)\r\
    \n        for (size_t j = 0; j < m; j++)\r\n          C[i][j] += (*this)[i][k]\
    \ * B[k][j];\r\n    A.swap(C);\r\n    return (*this);\r\n  }\r\n\r\n  SemiRingMatrix\
    \ &operator*=(const SemiRing &c){\r\n    size_t n = height(), m = width();\r\n\
    \    for (size_t i = 0; i < n; i++)\r\n      for (size_t j = 0; j < m; j++)\r\n\
    \        (*this)[i][j] *= c;\r\n    return (*this);\r\n  }\r\n\r\n  SemiRingMatrix\
    \ &operator/=(const SemiRing &c){\r\n    return (*this) *= SemiRing(1)/c;\r\n\
    \  }\r\n\r\n  SemiRingMatrix &operator^=(long long k){\r\n    assert(height()\
    \ == width());\r\n    SemiRingMatrix B = SemiRingMatrix::I(height());\r\n    while(k\
    \ > 0){\r\n      if(k&1) B *= *this;\r\n      *this *= *this;\r\n      k >>= 1;\r\
    \n    }\r\n    A.swap(B.A);\r\n    return (*this);\r\n  }\r\n\r\n  SemiRingMatrix\
    \ operator+(const SemiRingMatrix &B) const { return SemiRingMatrix(*this) += B;\
    \ }\r\n  SemiRingMatrix operator-(const SemiRingMatrix &B) const { return SemiRingMatrix(*this)\
    \ -= B; }\r\n  SemiRingMatrix operator*(const SemiRingMatrix &B) const { return\
    \ SemiRingMatrix(*this) *= B; }\r\n  SemiRingMatrix operator^(const long long\
    \ k) const { return SemiRingMatrix(*this) ^= k; }\r\n  SemiRingMatrix operator*(const\
    \ SemiRing &c) const { return SemiRingMatrix(*this) *= c; }\r\n  SemiRingMatrix\
    \ operator/(const SemiRing &c) const { return SemiRingMatrix(*this) /= c; }\r\n\
    \r\n  vector<SemiRing> operator*(const vector<SemiRing> &x) const {\r\n    assert(width()\
    \ == x.size());\r\n    size_t n = height(), m = width();\r\n    vector<SemiRing>\
    \ res(n, SemiRing::id());\r\n    for (size_t i = 0; i < n; i++)\r\n      for (size_t\
    \ j = 0; j < m; j++)\r\n        res[i] += (*this)[i][j] * x[j];\r\n    return\
    \ res;\r\n  }\r\n\r\n  SemiRingMatrix Transpose() const {\r\n    size_t n = height(),\
    \ m = width();\r\n    SemiRingMatrix res(m, n);\r\n    for (size_t i = 0; i <\
    \ n; i++)\r\n      for (size_t j = 0; j < m; j++)\r\n        res[j][i] = (*this)[i][j];\r\
    \n    return res;\r\n  }\r\n\r\n  friend istream &operator>>(istream &is, SemiRingMatrix\
    \ &p){\r\n    size_t n = p.height(), m = p.width();\r\n    for (size_t i = 0;\
    \ i < n; i++)\r\n      for (size_t j = 0; j < m; j++)\r\n        is >>  p[i][j];\r\
    \n    return (is);\r\n  }\r\n\r\n  friend ostream &operator<<(ostream &os, const\
    \ SemiRingMatrix &p){\r\n    size_t n = p.height(), m = p.width();\r\n    for\
    \ (size_t i = 0; i < n; i++)\r\n      for (size_t j = 0; j < m; j++)\r\n     \
    \   os << p[i][j] << \" \\n\"[j+1==m];\r\n    return (os);\r\n  }\r\n\r\n  static\
    \ SemiRingMatrix I(size_t n){\r\n    SemiRingMatrix res(n, n, SemiRing::id());\r\
    \n    for (size_t i = 0; i < n; i++) res[i][i] = SemiRing::e();\r\n    return\
    \ res;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n\r\ntemplate <typename SemiRing>\r\nstruct SemiRingMatrix{\r\
    \n  vector<vector<SemiRing>> A;\r\n\r\n  SemiRingMatrix() {}\r\n  SemiRingMatrix(size_t\
    \ n, size_t m, SemiRing e = SemiRing::e()): A(n, vector<SemiRing>(m, e)) {}\r\n\
    \  SemiRingMatrix(size_t n): A(n, vector<SemiRing>(n)) {}\r\n  SemiRingMatrix(const\
    \ vector<vector<SemiRing>> &e): A(e) {}\r\n  SemiRingMatrix(const initializer_list<initializer_list<SemiRing>>\
    \ &x): A(x.begin(),x.end()) {}\r\n  \r\n  size_t height() const { return A.size();\
    \ }\r\n  size_t width() const { return A.at(0).size(); }\r\n\r\n  vector<SemiRing>\
    \ &operator[](int k) { return A.at(k); }\r\n  const vector<SemiRing> &operator[](int\
    \ k) const { return A.at(k); }\r\n  vector<SemiRing> &at(int k) { return A.at(k);\
    \ }\r\n  const vector<SemiRing> &at(int k) const { return A.at(k); }\r\n\r\n \
    \ SemiRingMatrix &operator+=(const SemiRingMatrix &B){\r\n    assert(height()\
    \ == B.height() && width() == B.width());\r\n    size_t n = height(), m = width();\r\
    \n    for (size_t i = 0; i < n; i++)\r\n      for (size_t j = 0; j < m; j++)\r\
    \n        (*this)[i][j] += B[i][j];\r\n    return (*this);\r\n  }\r\n\r\n  SemiRingMatrix\
    \ &operator-=(const SemiRingMatrix &B){\r\n    assert(height() == B.height() &&\
    \ width() == B.width());\r\n    size_t n = height(), m = width();\r\n    for (size_t\
    \ i = 0; i < n; i++)\r\n      for (size_t j = 0; j < m; j++)\r\n        (*this)[i][j]\
    \ -= B[i][j];\r\n    return (*this);\r\n  }\r\n\r\n  SemiRingMatrix &operator*=(const\
    \ SemiRingMatrix &B){\r\n    assert(width() == B.height());\r\n    size_t n =\
    \ height(), m = B.width(), l = width();\r\n    vector<vector<SemiRing>> C(n, vector<SemiRing>(m,\
    \ SemiRing::id()));\r\n    for (size_t i = 0; i < n; i++)\r\n      for (size_t\
    \ k = 0; k < l; k++)\r\n        for (size_t j = 0; j < m; j++)\r\n          C[i][j]\
    \ += (*this)[i][k] * B[k][j];\r\n    A.swap(C);\r\n    return (*this);\r\n  }\r\
    \n\r\n  SemiRingMatrix &operator*=(const SemiRing &c){\r\n    size_t n = height(),\
    \ m = width();\r\n    for (size_t i = 0; i < n; i++)\r\n      for (size_t j =\
    \ 0; j < m; j++)\r\n        (*this)[i][j] *= c;\r\n    return (*this);\r\n  }\r\
    \n\r\n  SemiRingMatrix &operator/=(const SemiRing &c){\r\n    return (*this) *=\
    \ SemiRing(1)/c;\r\n  }\r\n\r\n  SemiRingMatrix &operator^=(long long k){\r\n\
    \    assert(height() == width());\r\n    SemiRingMatrix B = SemiRingMatrix::I(height());\r\
    \n    while(k > 0){\r\n      if(k&1) B *= *this;\r\n      *this *= *this;\r\n\
    \      k >>= 1;\r\n    }\r\n    A.swap(B.A);\r\n    return (*this);\r\n  }\r\n\
    \r\n  SemiRingMatrix operator+(const SemiRingMatrix &B) const { return SemiRingMatrix(*this)\
    \ += B; }\r\n  SemiRingMatrix operator-(const SemiRingMatrix &B) const { return\
    \ SemiRingMatrix(*this) -= B; }\r\n  SemiRingMatrix operator*(const SemiRingMatrix\
    \ &B) const { return SemiRingMatrix(*this) *= B; }\r\n  SemiRingMatrix operator^(const\
    \ long long k) const { return SemiRingMatrix(*this) ^= k; }\r\n  SemiRingMatrix\
    \ operator*(const SemiRing &c) const { return SemiRingMatrix(*this) *= c; }\r\n\
    \  SemiRingMatrix operator/(const SemiRing &c) const { return SemiRingMatrix(*this)\
    \ /= c; }\r\n\r\n  vector<SemiRing> operator*(const vector<SemiRing> &x) const\
    \ {\r\n    assert(width() == x.size());\r\n    size_t n = height(), m = width();\r\
    \n    vector<SemiRing> res(n, SemiRing::id());\r\n    for (size_t i = 0; i < n;\
    \ i++)\r\n      for (size_t j = 0; j < m; j++)\r\n        res[i] += (*this)[i][j]\
    \ * x[j];\r\n    return res;\r\n  }\r\n\r\n  SemiRingMatrix Transpose() const\
    \ {\r\n    size_t n = height(), m = width();\r\n    SemiRingMatrix res(m, n);\r\
    \n    for (size_t i = 0; i < n; i++)\r\n      for (size_t j = 0; j < m; j++)\r\
    \n        res[j][i] = (*this)[i][j];\r\n    return res;\r\n  }\r\n\r\n  friend\
    \ istream &operator>>(istream &is, SemiRingMatrix &p){\r\n    size_t n = p.height(),\
    \ m = p.width();\r\n    for (size_t i = 0; i < n; i++)\r\n      for (size_t j\
    \ = 0; j < m; j++)\r\n        is >>  p[i][j];\r\n    return (is);\r\n  }\r\n\r\
    \n  friend ostream &operator<<(ostream &os, const SemiRingMatrix &p){\r\n    size_t\
    \ n = p.height(), m = p.width();\r\n    for (size_t i = 0; i < n; i++)\r\n   \
    \   for (size_t j = 0; j < m; j++)\r\n        os << p[i][j] << \" \\n\"[j+1==m];\r\
    \n    return (os);\r\n  }\r\n\r\n  static SemiRingMatrix I(size_t n){\r\n    SemiRingMatrix\
    \ res(n, n, SemiRing::id());\r\n    for (size_t i = 0; i < n; i++) res[i][i] =\
    \ SemiRing::e();\r\n    return res;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix/SemiRingMatrix.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix/SemiRingMatrix.cpp
layout: document
redirect_from:
- /library/math/matrix/SemiRingMatrix.cpp
- /library/math/matrix/SemiRingMatrix.cpp.html
title: math/matrix/SemiRingMatrix.cpp
---
