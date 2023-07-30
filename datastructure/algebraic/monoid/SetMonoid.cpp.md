---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: datastructure/algebraic/operator_monoid/RangeUpdateRangeMax.cpp
    title: datastructure/algebraic/operator_monoid/RangeUpdateRangeMax.cpp
  - icon: ':warning:'
    path: datastructure/algebraic/operator_monoid/RangeUpdateRangeMin.cpp
    title: datastructure/algebraic/operator_monoid/RangeUpdateRangeMin.cpp
  - icon: ':warning:'
    path: datastructure/algebraic/operator_monoid/RangeUpdateRangeSum.cpp
    title: datastructure/algebraic/operator_monoid/RangeUpdateRangeSum.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/algebraic/monoid/SetMonoid.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct SetMonoid{\r\n  bool id = 1;\r\n  T x{};\r\n\r\n  SetMonoid() =\
    \ default;\r\n  SetMonoid(const SetMonoid&) = default;\r\n  SetMonoid(SetMonoid&&)\
    \ = default;\r\n  SetMonoid &operator=(const SetMonoid&) = default;\r\n  SetMonoid\
    \ &operator=(SetMonoid&&) = default;\r\n\r\n  SetMonoid(const T &x): id(false),\
    \ x(x) {}\r\n\r\n  SetMonoid &operator+=(const SetMonoid &m){\r\n    if(!m.id)\
    \ id = m.id, x = m.x;\r\n    return (*this);\r\n  }\r\n\r\n  SetMonoid operator+(const\
    \ SetMonoid &m){ return SetMonoid(*this) += m; }\r\n\r\n  bool operator==(const\
    \ SetMonoid &m) const {\r\n    if(id && m.id) return true;\r\n    if(id != m.id)\
    \ return false;\r\n    return x == m.x;\r\n  }\r\n\r\n  bool operator!=(const\
    \ SetMonoid &m) const { return !((*this) == m); }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct SetMonoid{\r\n  bool id\
    \ = 1;\r\n  T x{};\r\n\r\n  SetMonoid() = default;\r\n  SetMonoid(const SetMonoid&)\
    \ = default;\r\n  SetMonoid(SetMonoid&&) = default;\r\n  SetMonoid &operator=(const\
    \ SetMonoid&) = default;\r\n  SetMonoid &operator=(SetMonoid&&) = default;\r\n\
    \r\n  SetMonoid(const T &x): id(false), x(x) {}\r\n\r\n  SetMonoid &operator+=(const\
    \ SetMonoid &m){\r\n    if(!m.id) id = m.id, x = m.x;\r\n    return (*this);\r\
    \n  }\r\n\r\n  SetMonoid operator+(const SetMonoid &m){ return SetMonoid(*this)\
    \ += m; }\r\n\r\n  bool operator==(const SetMonoid &m) const {\r\n    if(id &&\
    \ m.id) return true;\r\n    if(id != m.id) return false;\r\n    return x == m.x;\r\
    \n  }\r\n\r\n  bool operator!=(const SetMonoid &m) const { return !((*this) ==\
    \ m); }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/algebraic/monoid/SetMonoid.cpp
  requiredBy:
  - datastructure/algebraic/operator_monoid/RangeUpdateRangeMax.cpp
  - datastructure/algebraic/operator_monoid/RangeUpdateRangeSum.cpp
  - datastructure/algebraic/operator_monoid/RangeUpdateRangeMin.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/monoid/SetMonoid.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/monoid/SetMonoid.cpp
- /library/datastructure/algebraic/monoid/SetMonoid.cpp.html
title: datastructure/algebraic/monoid/SetMonoid.cpp
---
