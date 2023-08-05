---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/algebraic/monoid/LengthMonoid.cpp
    title: datastructure/algebraic/monoid/LengthMonoid.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/algebraic/operator_monoid/RangeAddRangeSum.cpp\"\
    \n\r\n#line 2 \"datastructure/algebraic/monoid/LengthMonoid.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct LengthMonoid{\r\n  T x{};\r\n  size_t l = 0;\r\n\r\n  LengthMonoid()\
    \ = default;\r\n  LengthMonoid(const LengthMonoid&) = default;\r\n  LengthMonoid(LengthMonoid&&)\
    \ = default;\r\n\r\n  LengthMonoid(const T &x, size_t l = 1): x(x), l(l) {}\r\n\
    \r\n  LengthMonoid &operator=(const LengthMonoid&) = default;\r\n  LengthMonoid\
    \ &operator=(LengthMonoid&&) = default;\r\n\r\n  LengthMonoid &operator+=(const\
    \ LengthMonoid &m){\r\n    x += m.x; l += m.l;\r\n    return (*this);\r\n  }\r\
    \n  LengthMonoid operator+(const LengthMonoid &m) const {\r\n    return LengthMonoid(*this)\
    \ += m;\r\n  }\r\n\r\n  bool operator==(const LengthMonoid &m) const { return\
    \ x == m.x && l == m.l; }\r\n  bool operator!=(const LengthMonoid &m) const {\
    \ return !((*this) == m); }\r\n};\r\n#line 4 \"datastructure/algebraic/operator_monoid/RangeAddRangeSum.cpp\"\
    \n\r\ntemplate<typename T>\r\nstruct RangeAddRangeSum{\r\n  using Monoid = LengthMonoid<T>;\r\
    \n  using OperatorMonoid = T;\r\n\r\n  static void act(Monoid &m, const OperatorMonoid\
    \ &f){\r\n    m.x += f * m.l;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include \"../monoid/LengthMonoid.cpp\"\r\n\r\ntemplate<typename\
    \ T>\r\nstruct RangeAddRangeSum{\r\n  using Monoid = LengthMonoid<T>;\r\n  using\
    \ OperatorMonoid = T;\r\n\r\n  static void act(Monoid &m, const OperatorMonoid\
    \ &f){\r\n    m.x += f * m.l;\r\n  }\r\n};\r\n"
  dependsOn:
  - datastructure/algebraic/monoid/LengthMonoid.cpp
  isVerificationFile: false
  path: datastructure/algebraic/operator_monoid/RangeAddRangeSum.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/operator_monoid/RangeAddRangeSum.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/operator_monoid/RangeAddRangeSum.cpp
- /library/datastructure/algebraic/operator_monoid/RangeAddRangeSum.cpp.html
title: datastructure/algebraic/operator_monoid/RangeAddRangeSum.cpp
---