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
  bundledCode: "#line 2 \"datastructure/algebraic/monoid/AndMonoid.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct AndMonoid{\r\n\r\n  AndMonoid() = default;\r\n  AndMonoid(const\
    \ AndMonoid&) = default;\r\n  AndMonoid(AndMonoid&&) = default;\r\n  AndMonoid\
    \ &operator=(const AndMonoid&) = default;\r\n  AndMonoid &operator=(AndMonoid&&)\
    \ = default;\r\n\r\n  T x = -1;\r\n  AndMonoid(const T &x): x(x) {}\r\n\r\n  AndMonoid\
    \ &operator+=(const AndMonoid &m){\r\n    x &= m.x;\r\n    return (*this);\r\n\
    \  }\r\n\r\n  AndMonoid operator+(const AndMonoid &m){ return AndMonoid(*this)\
    \ += m; }\r\n\r\n  bool operator==(const AndMonoid &m) const { return x == m.x;\
    \ }\r\n  bool operator!=(const AndMonoid &m) const { return !((*this) == m); }\r\
    \n\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct AndMonoid{\r\n\r\n  AndMonoid()\
    \ = default;\r\n  AndMonoid(const AndMonoid&) = default;\r\n  AndMonoid(AndMonoid&&)\
    \ = default;\r\n  AndMonoid &operator=(const AndMonoid&) = default;\r\n  AndMonoid\
    \ &operator=(AndMonoid&&) = default;\r\n\r\n  T x = -1;\r\n  AndMonoid(const T\
    \ &x): x(x) {}\r\n\r\n  AndMonoid &operator+=(const AndMonoid &m){\r\n    x &=\
    \ m.x;\r\n    return (*this);\r\n  }\r\n\r\n  AndMonoid operator+(const AndMonoid\
    \ &m){ return AndMonoid(*this) += m; }\r\n\r\n  bool operator==(const AndMonoid\
    \ &m) const { return x == m.x; }\r\n  bool operator!=(const AndMonoid &m) const\
    \ { return !((*this) == m); }\r\n\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/algebraic/monoid/AndMonoid.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/monoid/AndMonoid.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/monoid/AndMonoid.cpp
- /library/datastructure/algebraic/monoid/AndMonoid.cpp.html
title: datastructure/algebraic/monoid/AndMonoid.cpp
---
