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
  bundledCode: "#line 2 \"datastructure/algebraic/monoid/GcdMonoid.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct GcdMonoid{\r\n  T x = 0;\r\n  GcdMonoid() = default;\r\n  GcdMonoid(const\
    \ GcdMonoid&) = default;\r\n  GcdMonoid(GcdMonoid&&) = default;\r\n\r\n  GcdMonoid(const\
    \ T &a, const T &b): a(a), b(b) {}\r\n\r\n  GcdMonoid &operator=(const GcdMonoid&)\
    \ = default;\r\n  GcdMonoid &operator=(GcdMonoid&&) = default;\r\n\r\n  GcdMonoid\
    \ &operator+=(const GcdMonoid &m){\r\n    if(m.x != 0) x = gcd(x, m.x);\r\n  \
    \  return (*this);\r\n  }\r\n  GcdMonoid operator+(const GcdMonoid &m) const {\r\
    \n    return GcdMonoid(*this) += m;\r\n  }\r\n\r\n  bool operator==(const GcdMonoid\
    \ &m) const { return x == m.x; }\r\n  bool operator!=(const GcdMonoid &m) const\
    \ { return !((*this) == m); }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct GcdMonoid{\r\n  T x =\
    \ 0;\r\n  GcdMonoid() = default;\r\n  GcdMonoid(const GcdMonoid&) = default;\r\
    \n  GcdMonoid(GcdMonoid&&) = default;\r\n\r\n  GcdMonoid(const T &a, const T &b):\
    \ a(a), b(b) {}\r\n\r\n  GcdMonoid &operator=(const GcdMonoid&) = default;\r\n\
    \  GcdMonoid &operator=(GcdMonoid&&) = default;\r\n\r\n  GcdMonoid &operator+=(const\
    \ GcdMonoid &m){\r\n    if(m.x != 0) x = gcd(x, m.x);\r\n    return (*this);\r\
    \n  }\r\n  GcdMonoid operator+(const GcdMonoid &m) const {\r\n    return GcdMonoid(*this)\
    \ += m;\r\n  }\r\n\r\n  bool operator==(const GcdMonoid &m) const { return x ==\
    \ m.x; }\r\n  bool operator!=(const GcdMonoid &m) const { return !((*this) ==\
    \ m); }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/algebraic/monoid/GcdMonoid.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/monoid/GcdMonoid.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/monoid/GcdMonoid.cpp
- /library/datastructure/algebraic/monoid/GcdMonoid.cpp.html
title: datastructure/algebraic/monoid/GcdMonoid.cpp
---
