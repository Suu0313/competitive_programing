---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: datastructure/algebraic/operator_monoid/RangeFlipRangeBitInversion.cpp
    title: datastructure/algebraic/operator_monoid/RangeFlipRangeBitInversion.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/algebraic/monoid/XorMonoid.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct XorMonoid{\r\n\r\n  XorMonoid() = default;\r\n  XorMonoid(const\
    \ XorMonoid&) = default;\r\n  XorMonoid(XorMonoid&&) = default;\r\n  XorMonoid\
    \ &operator=(const XorMonoid&) = default;\r\n  XorMonoid &operator=(XorMonoid&&)\
    \ = default;\r\n\r\n  T x = 0;\r\n  XorMonoid(const T &x): x(x) {}\r\n\r\n  XorMonoid\
    \ &operator+=(const XorMonoid &m){\r\n    x ^= m.x;\r\n    return (*this);\r\n\
    \  }\r\n\r\n  XorMonoid operator+(const XorMonoid &m){ return XorMonoid(*this)\
    \ += m; }\r\n\r\n  bool operator==(const XorMonoid &m) const { return x == m.x;\
    \ }\r\n  bool operator!=(const XorMonoid &m) const { return !((*this) == m); }\r\
    \n\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct XorMonoid{\r\n\r\n  XorMonoid()\
    \ = default;\r\n  XorMonoid(const XorMonoid&) = default;\r\n  XorMonoid(XorMonoid&&)\
    \ = default;\r\n  XorMonoid &operator=(const XorMonoid&) = default;\r\n  XorMonoid\
    \ &operator=(XorMonoid&&) = default;\r\n\r\n  T x = 0;\r\n  XorMonoid(const T\
    \ &x): x(x) {}\r\n\r\n  XorMonoid &operator+=(const XorMonoid &m){\r\n    x ^=\
    \ m.x;\r\n    return (*this);\r\n  }\r\n\r\n  XorMonoid operator+(const XorMonoid\
    \ &m){ return XorMonoid(*this) += m; }\r\n\r\n  bool operator==(const XorMonoid\
    \ &m) const { return x == m.x; }\r\n  bool operator!=(const XorMonoid &m) const\
    \ { return !((*this) == m); }\r\n\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/algebraic/monoid/XorMonoid.cpp
  requiredBy:
  - datastructure/algebraic/operator_monoid/RangeFlipRangeBitInversion.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/monoid/XorMonoid.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/monoid/XorMonoid.cpp
- /library/datastructure/algebraic/monoid/XorMonoid.cpp.html
title: datastructure/algebraic/monoid/XorMonoid.cpp
---
