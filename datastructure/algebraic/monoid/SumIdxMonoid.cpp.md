---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: datastructure/algebraic/operator_monoid/RangeArithmeticAddRangeSum.cpp
    title: datastructure/algebraic/operator_monoid/RangeArithmeticAddRangeSum.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/algebraic/monoid/SumIdxMonoid.cpp\"\n\r\n\
    template<typename T>\r\nstruct SumIdxMonoid{\r\n  T sum = 0;\r\n  int l = -1,\
    \ r = -1;\r\n  SumIdxMonoid() = default;\r\n  SumIdxMonoid(const SumIdxMonoid&)\
    \ = default;\r\n  SumIdxMonoid(SumIdxMonoid&&) = default;\r\n\r\n  SumIdxMonoid(const\
    \ T &x, int k): sum(x), l(k), r(k + 1) {}\r\n\r\n  SumIdxMonoid &operator=(const\
    \ SumIdxMonoid&) = default;\r\n  SumIdxMonoid &operator=(SumIdxMonoid&&) = default;\r\
    \n\r\n  SumIdxMonoid &operator+=(const SumIdxMonoid &m){\r\n    if(m.l == -1)\
    \ return (*this);\r\n    if(this->l == -1) return (*this) = m;\r\n    sum += m.sum;\r\
    \n    r = m.r;\r\n    return (*this);\r\n  }\r\n  SumIdxMonoid operator+(const\
    \ SumIdxMonoid &m) const {\r\n    return SumIdxMonoid(*this) += m;\r\n  }\r\n\
    };\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct SumIdxMonoid{\r\n  T sum\
    \ = 0;\r\n  int l = -1, r = -1;\r\n  SumIdxMonoid() = default;\r\n  SumIdxMonoid(const\
    \ SumIdxMonoid&) = default;\r\n  SumIdxMonoid(SumIdxMonoid&&) = default;\r\n\r\
    \n  SumIdxMonoid(const T &x, int k): sum(x), l(k), r(k + 1) {}\r\n\r\n  SumIdxMonoid\
    \ &operator=(const SumIdxMonoid&) = default;\r\n  SumIdxMonoid &operator=(SumIdxMonoid&&)\
    \ = default;\r\n\r\n  SumIdxMonoid &operator+=(const SumIdxMonoid &m){\r\n   \
    \ if(m.l == -1) return (*this);\r\n    if(this->l == -1) return (*this) = m;\r\
    \n    sum += m.sum;\r\n    r = m.r;\r\n    return (*this);\r\n  }\r\n  SumIdxMonoid\
    \ operator+(const SumIdxMonoid &m) const {\r\n    return SumIdxMonoid(*this) +=\
    \ m;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/algebraic/monoid/SumIdxMonoid.cpp
  requiredBy:
  - datastructure/algebraic/operator_monoid/RangeArithmeticAddRangeSum.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/monoid/SumIdxMonoid.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/monoid/SumIdxMonoid.cpp
- /library/datastructure/algebraic/monoid/SumIdxMonoid.cpp.html
title: datastructure/algebraic/monoid/SumIdxMonoid.cpp
---
