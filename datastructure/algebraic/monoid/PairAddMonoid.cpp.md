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
  bundledCode: "#line 2 \"datastructure/algebraic/monoid/PairAddMonoid.cpp\"\n\r\n\
    template<typename T>\r\nstruct PairAddMonoid{\r\n  T a = T{}, b = T{};\r\n\r\n\
    \  PairAddMonoid() = default;\r\n  PairAddMonoid(const PairAddMonoid&) = default;\r\
    \n  PairAddMonoid(PairAddMonoid&&) = default;\r\n  PairAddMonoid &operator=(const\
    \ PairAddMonoid&) = default;\r\n  PairAddMonoid &operator=(PairAddMonoid&&) =\
    \ default;\r\n\r\n  PairAddMonoid(const T &a, const T &b): a(a), b(b) {}\r\n \
    \ PairAddMonoid(const T &a, const T &b, size_t l): a(a - b * l), b(b) {}\r\n\r\
    \n  PairAddMonoid &operator+=(const PairAddMonoid &m){\r\n    a += m.a, b += m.b;\r\
    \n    return (*this);\r\n  }\r\n\r\n  PairAddMonoid operator+(const PairAddMonoid\
    \ &m) const { return PairAddMonoid(*this) += m; }\r\n\r\n  bool operator==(const\
    \ PairAddMonoid &m) const { return (a == m.a) && (b == m.b); }\r\n\r\n  bool operator!=(const\
    \ PairAddMonoid &m) const { return !((*this) == m); }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct PairAddMonoid{\r\n  T\
    \ a = T{}, b = T{};\r\n\r\n  PairAddMonoid() = default;\r\n  PairAddMonoid(const\
    \ PairAddMonoid&) = default;\r\n  PairAddMonoid(PairAddMonoid&&) = default;\r\n\
    \  PairAddMonoid &operator=(const PairAddMonoid&) = default;\r\n  PairAddMonoid\
    \ &operator=(PairAddMonoid&&) = default;\r\n\r\n  PairAddMonoid(const T &a, const\
    \ T &b): a(a), b(b) {}\r\n  PairAddMonoid(const T &a, const T &b, size_t l): a(a\
    \ - b * l), b(b) {}\r\n\r\n  PairAddMonoid &operator+=(const PairAddMonoid &m){\r\
    \n    a += m.a, b += m.b;\r\n    return (*this);\r\n  }\r\n\r\n  PairAddMonoid\
    \ operator+(const PairAddMonoid &m) const { return PairAddMonoid(*this) += m;\
    \ }\r\n\r\n  bool operator==(const PairAddMonoid &m) const { return (a == m.a)\
    \ && (b == m.b); }\r\n\r\n  bool operator!=(const PairAddMonoid &m) const { return\
    \ !((*this) == m); }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/algebraic/monoid/PairAddMonoid.cpp
  requiredBy:
  - datastructure/algebraic/operator_monoid/RangeArithmeticAddRangeSum.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/monoid/PairAddMonoid.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/monoid/PairAddMonoid.cpp
- /library/datastructure/algebraic/monoid/PairAddMonoid.cpp.html
title: datastructure/algebraic/monoid/PairAddMonoid.cpp
---
