---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: datastructure/algebraic/operator_monoid/RangeAddRangeSum.cpp
    title: datastructure/algebraic/operator_monoid/RangeAddRangeSum.cpp
  - icon: ':heavy_check_mark:'
    path: datastructure/algebraic/operator_monoid/RangeAffineRangeSum.cpp
    title: datastructure/algebraic/operator_monoid/RangeAffineRangeSum.cpp
  - icon: ':warning:'
    path: datastructure/algebraic/operator_monoid/RangeUpdateRangeSum.cpp
    title: datastructure/algebraic/operator_monoid/RangeUpdateRangeSum.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/lc/range_affine_range_sum.test.cpp
    title: test/verify/lc/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/algebraic/monoid/LengthMonoid.cpp\"\n\r\n\
    template<typename T>\r\nstruct LengthMonoid{\r\n  T x{};\r\n  size_t l = 0;\r\n\
    \r\n  LengthMonoid() = default;\r\n  LengthMonoid(const LengthMonoid&) = default;\r\
    \n  LengthMonoid(LengthMonoid&&) = default;\r\n\r\n  LengthMonoid(const T &x,\
    \ size_t l = 1): x(x), l(l) {}\r\n\r\n  LengthMonoid &operator=(const LengthMonoid&)\
    \ = default;\r\n  LengthMonoid &operator=(LengthMonoid&&) = default;\r\n\r\n \
    \ LengthMonoid &operator+=(const LengthMonoid &m){\r\n    x += m.x; l += m.l;\r\
    \n    return (*this);\r\n  }\r\n  LengthMonoid operator+(const LengthMonoid &m)\
    \ const {\r\n    return LengthMonoid(*this) += m;\r\n  }\r\n\r\n  bool operator==(const\
    \ LengthMonoid &m) const { return x == m.x && l == m.l; }\r\n  bool operator!=(const\
    \ LengthMonoid &m) const { return !((*this) == m); }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct LengthMonoid{\r\n  T x{};\r\
    \n  size_t l = 0;\r\n\r\n  LengthMonoid() = default;\r\n  LengthMonoid(const LengthMonoid&)\
    \ = default;\r\n  LengthMonoid(LengthMonoid&&) = default;\r\n\r\n  LengthMonoid(const\
    \ T &x, size_t l = 1): x(x), l(l) {}\r\n\r\n  LengthMonoid &operator=(const LengthMonoid&)\
    \ = default;\r\n  LengthMonoid &operator=(LengthMonoid&&) = default;\r\n\r\n \
    \ LengthMonoid &operator+=(const LengthMonoid &m){\r\n    x += m.x; l += m.l;\r\
    \n    return (*this);\r\n  }\r\n  LengthMonoid operator+(const LengthMonoid &m)\
    \ const {\r\n    return LengthMonoid(*this) += m;\r\n  }\r\n\r\n  bool operator==(const\
    \ LengthMonoid &m) const { return x == m.x && l == m.l; }\r\n  bool operator!=(const\
    \ LengthMonoid &m) const { return !((*this) == m); }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/algebraic/monoid/LengthMonoid.cpp
  requiredBy:
  - datastructure/algebraic/operator_monoid/RangeAddRangeSum.cpp
  - datastructure/algebraic/operator_monoid/RangeAffineRangeSum.cpp
  - datastructure/algebraic/operator_monoid/RangeUpdateRangeSum.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/lc/range_affine_range_sum.test.cpp
documentation_of: datastructure/algebraic/monoid/LengthMonoid.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/monoid/LengthMonoid.cpp
- /library/datastructure/algebraic/monoid/LengthMonoid.cpp.html
title: datastructure/algebraic/monoid/LengthMonoid.cpp
---
