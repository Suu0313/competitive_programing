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
  bundledCode: "#line 2 \"datastructure/algebraic/monoid/OrMonoid.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct OrMonoid{\r\n\r\n  OrMonoid() = default;\r\n  OrMonoid(const OrMonoid&)\
    \ = default;\r\n  OrMonoid(OrMonoid&&) = default;\r\n  OrMonoid &operator=(const\
    \ OrMonoid&) = default;\r\n  OrMonoid &operator=(OrMonoid&&) = default;\r\n\r\n\
    \  T x = 0;\r\n  OrMonoid(const T &x): x(x) {}\r\n\r\n  OrMonoid &operator+=(const\
    \ OrMonoid &m){\r\n    x |= m.x;\r\n    return (*this);\r\n  }\r\n\r\n  OrMonoid\
    \ operator+(const OrMonoid &m){ return OrMonoid(*this) += m; }\r\n\r\n  bool operator==(const\
    \ OrMonoid &m) const { return x == m.x; }\r\n  bool operator!=(const OrMonoid\
    \ &m) const { return !((*this) == m); }\r\n\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct OrMonoid{\r\n\r\n  OrMonoid()\
    \ = default;\r\n  OrMonoid(const OrMonoid&) = default;\r\n  OrMonoid(OrMonoid&&)\
    \ = default;\r\n  OrMonoid &operator=(const OrMonoid&) = default;\r\n  OrMonoid\
    \ &operator=(OrMonoid&&) = default;\r\n\r\n  T x = 0;\r\n  OrMonoid(const T &x):\
    \ x(x) {}\r\n\r\n  OrMonoid &operator+=(const OrMonoid &m){\r\n    x |= m.x;\r\
    \n    return (*this);\r\n  }\r\n\r\n  OrMonoid operator+(const OrMonoid &m){ return\
    \ OrMonoid(*this) += m; }\r\n\r\n  bool operator==(const OrMonoid &m) const {\
    \ return x == m.x; }\r\n  bool operator!=(const OrMonoid &m) const { return !((*this)\
    \ == m); }\r\n\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/algebraic/monoid/OrMonoid.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/monoid/OrMonoid.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/monoid/OrMonoid.cpp
- /library/datastructure/algebraic/monoid/OrMonoid.cpp.html
title: datastructure/algebraic/monoid/OrMonoid.cpp
---
