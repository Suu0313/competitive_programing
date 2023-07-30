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
  bundledCode: "#line 2 \"datastructure/algebraic/monoid/ClampAddMonoid.cpp\"\n\r\n\
    template<typename T>\r\nstruct ClampAddMonoid{\r\n\r\n  ClampAddMonoid() = default;\r\
    \n  ClampAddMonoid(const ClampAddMonoid&) = default;\r\n  ClampAddMonoid(ClampAddMonoid&&)\
    \ = default;\r\n  ClampAddMonoid &operator=(const ClampAddMonoid&) = default;\r\
    \n  ClampAddMonoid &operator=(ClampAddMonoid&&) = default;\r\n\r\n  static constexpr\
    \ T inf = numeric_limits<T>::max();\r\n\r\n  T add = T(0), chmx = -inf, chmn =\
    \ inf;\r\n\r\n  ClampAddMonoid(const T &add, const T &chmx, const T &chmn): add(add),\
    \ chmx(chmx), chmn(chmn) {}\r\n  ClampAddMonoid(int t, const T &x){\r\n    if(t\
    \ == 0) add = x;\r\n    if(t == 1) chmx = x;\r\n    if(t == 2) chmn = x;\r\n \
    \ }\r\n\r\n  ClampAddMonoid &operator+=(const ClampAddMonoid &m){\r\n    add +=\
    \ m.add;\r\n    chmx = max(min(((chmx == -inf) ? chmx : chmx + m.add), m.chmn),\
    \  m.chmx);\r\n    chmn = min(max(((chmn == inf) ? chmn : chmn + m.add), m.chmx),\
    \  m.chmn);\r\n    return (*this);\r\n  }\r\n\r\n  ClampAddMonoid operator+(const\
    \ ClampAddMonoid &m) const { return ClampAddMonoid(*this) += m; }\r\n\r\n  T operator*(const\
    \ T &x) const { return min(chmn, max(chmx, x + add)); }\r\n\r\n  bool operator==(const\
    \ ClampAddMonoid &m) const { return (add == m.add) && (chmx == m.chmx) && (chmn\
    \ == m.chmn); }\r\n  bool operator!=(const ClampAddMonoid &m) const { return !((*this)\
    \ == m); }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct ClampAddMonoid{\r\n\r\n\
    \  ClampAddMonoid() = default;\r\n  ClampAddMonoid(const ClampAddMonoid&) = default;\r\
    \n  ClampAddMonoid(ClampAddMonoid&&) = default;\r\n  ClampAddMonoid &operator=(const\
    \ ClampAddMonoid&) = default;\r\n  ClampAddMonoid &operator=(ClampAddMonoid&&)\
    \ = default;\r\n\r\n  static constexpr T inf = numeric_limits<T>::max();\r\n\r\
    \n  T add = T(0), chmx = -inf, chmn = inf;\r\n\r\n  ClampAddMonoid(const T &add,\
    \ const T &chmx, const T &chmn): add(add), chmx(chmx), chmn(chmn) {}\r\n  ClampAddMonoid(int\
    \ t, const T &x){\r\n    if(t == 0) add = x;\r\n    if(t == 1) chmx = x;\r\n \
    \   if(t == 2) chmn = x;\r\n  }\r\n\r\n  ClampAddMonoid &operator+=(const ClampAddMonoid\
    \ &m){\r\n    add += m.add;\r\n    chmx = max(min(((chmx == -inf) ? chmx : chmx\
    \ + m.add), m.chmn),  m.chmx);\r\n    chmn = min(max(((chmn == inf) ? chmn : chmn\
    \ + m.add), m.chmx),  m.chmn);\r\n    return (*this);\r\n  }\r\n\r\n  ClampAddMonoid\
    \ operator+(const ClampAddMonoid &m) const { return ClampAddMonoid(*this) += m;\
    \ }\r\n\r\n  T operator*(const T &x) const { return min(chmn, max(chmx, x + add));\
    \ }\r\n\r\n  bool operator==(const ClampAddMonoid &m) const { return (add == m.add)\
    \ && (chmx == m.chmx) && (chmn == m.chmn); }\r\n  bool operator!=(const ClampAddMonoid\
    \ &m) const { return !((*this) == m); }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/algebraic/monoid/ClampAddMonoid.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/monoid/ClampAddMonoid.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/monoid/ClampAddMonoid.cpp
- /library/datastructure/algebraic/monoid/ClampAddMonoid.cpp.html
title: datastructure/algebraic/monoid/ClampAddMonoid.cpp
---
