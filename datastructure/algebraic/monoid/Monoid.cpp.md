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
  bundledCode: "#line 2 \"datastructure/algebraic/monoid/Monoid.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct Monoid{\r\n\r\n  Monoid() = default;\r\n  Monoid(const Monoid&)\
    \ = default;\r\n  Monoid(Monoid&&) = default;\r\n  Monoid &operator=(const Monoid&)\
    \ = default;\r\n  Monoid &operator=(Monoid&&) = default;\r\n\r\n  T x = T{}; //\
    \ id\r\n  Monoid(const T &x): x(x) {}\r\n\r\n  Monoid &operator+=(const Monoid\
    \ &m){\r\n    x += m.x;\r\n    return (*this);\r\n  }\r\n\r\n  Monoid operator+(const\
    \ Monoid &m) const { return Monoid(*this) += m; }\r\n\r\n  bool operator==(const\
    \ Monoid &m) const { return x == m.x; }\r\n  bool operator!=(const Monoid &m)\
    \ const { return !((*this) == m); }\r\n\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct Monoid{\r\n\r\n  Monoid()\
    \ = default;\r\n  Monoid(const Monoid&) = default;\r\n  Monoid(Monoid&&) = default;\r\
    \n  Monoid &operator=(const Monoid&) = default;\r\n  Monoid &operator=(Monoid&&)\
    \ = default;\r\n\r\n  T x = T{}; // id\r\n  Monoid(const T &x): x(x) {}\r\n\r\n\
    \  Monoid &operator+=(const Monoid &m){\r\n    x += m.x;\r\n    return (*this);\r\
    \n  }\r\n\r\n  Monoid operator+(const Monoid &m) const { return Monoid(*this)\
    \ += m; }\r\n\r\n  bool operator==(const Monoid &m) const { return x == m.x; }\r\
    \n  bool operator!=(const Monoid &m) const { return !((*this) == m); }\r\n\r\n\
    };\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/algebraic/monoid/Monoid.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/monoid/Monoid.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/monoid/Monoid.cpp
- /library/datastructure/algebraic/monoid/Monoid.cpp.html
title: datastructure/algebraic/monoid/Monoid.cpp
---
