---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: datastructure/algebraic/operator_monoid/RangeArithmeticUpdateRangeMinMaxSum.cpp
    title: datastructure/algebraic/operator_monoid/RangeArithmeticUpdateRangeMinMaxSum.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/algebraic/monoid/ArithmeticUpdateMonoid.cpp\"\
    \n\r\ntemplate<typename T>\r\nstruct ArithmeticUpdateMonoid{\r\n  bool id = 1;\r\
    \n  T a = T{}, b = T{};\r\n\r\n  ArithmeticUpdateMonoid() = default;\r\n  ArithmeticUpdateMonoid(const\
    \ ArithmeticUpdateMonoid&) = default;\r\n  ArithmeticUpdateMonoid(ArithmeticUpdateMonoid&&)\
    \ = default;\r\n  ArithmeticUpdateMonoid &operator=(const ArithmeticUpdateMonoid&)\
    \ = default;\r\n  ArithmeticUpdateMonoid &operator=(ArithmeticUpdateMonoid&&)\
    \ = default;\r\n\r\n  ArithmeticUpdateMonoid(const T &a, const T &b): id(false),\
    \ a(a), b(b) {}\r\n  ArithmeticUpdateMonoid(const T &a, const T &b, size_t l):\
    \ id(false), a(a - b * l), b(b) {}\r\n\r\n  ArithmeticUpdateMonoid &operator+=(const\
    \ ArithmeticUpdateMonoid &m){\r\n    if(!m.id) id = m.id, a = m.a, b = m.b;\r\n\
    \    return (*this);\r\n  }\r\n\r\n  ArithmeticUpdateMonoid operator+(const ArithmeticUpdateMonoid\
    \ &m){ return ArithmeticUpdateMonoid(*this) += m; }\r\n\r\n  bool operator==(const\
    \ ArithmeticUpdateMonoid &m) const {\r\n    if(id && m.id) return true;\r\n  \
    \  if(id != m.id) return false;\r\n    return (a == m.a) && (b == m.b);\r\n  }\r\
    \n\r\n  bool operator!=(const ArithmeticUpdateMonoid &m) const { return !((*this)\
    \ == m); }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct ArithmeticUpdateMonoid{\r\
    \n  bool id = 1;\r\n  T a = T{}, b = T{};\r\n\r\n  ArithmeticUpdateMonoid() =\
    \ default;\r\n  ArithmeticUpdateMonoid(const ArithmeticUpdateMonoid&) = default;\r\
    \n  ArithmeticUpdateMonoid(ArithmeticUpdateMonoid&&) = default;\r\n  ArithmeticUpdateMonoid\
    \ &operator=(const ArithmeticUpdateMonoid&) = default;\r\n  ArithmeticUpdateMonoid\
    \ &operator=(ArithmeticUpdateMonoid&&) = default;\r\n\r\n  ArithmeticUpdateMonoid(const\
    \ T &a, const T &b): id(false), a(a), b(b) {}\r\n  ArithmeticUpdateMonoid(const\
    \ T &a, const T &b, size_t l): id(false), a(a - b * l), b(b) {}\r\n\r\n  ArithmeticUpdateMonoid\
    \ &operator+=(const ArithmeticUpdateMonoid &m){\r\n    if(!m.id) id = m.id, a\
    \ = m.a, b = m.b;\r\n    return (*this);\r\n  }\r\n\r\n  ArithmeticUpdateMonoid\
    \ operator+(const ArithmeticUpdateMonoid &m){ return ArithmeticUpdateMonoid(*this)\
    \ += m; }\r\n\r\n  bool operator==(const ArithmeticUpdateMonoid &m) const {\r\n\
    \    if(id && m.id) return true;\r\n    if(id != m.id) return false;\r\n    return\
    \ (a == m.a) && (b == m.b);\r\n  }\r\n\r\n  bool operator!=(const ArithmeticUpdateMonoid\
    \ &m) const { return !((*this) == m); }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/algebraic/monoid/ArithmeticUpdateMonoid.cpp
  requiredBy:
  - datastructure/algebraic/operator_monoid/RangeArithmeticUpdateRangeMinMaxSum.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/monoid/ArithmeticUpdateMonoid.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/monoid/ArithmeticUpdateMonoid.cpp
- /library/datastructure/algebraic/monoid/ArithmeticUpdateMonoid.cpp.html
title: datastructure/algebraic/monoid/ArithmeticUpdateMonoid.cpp
---
