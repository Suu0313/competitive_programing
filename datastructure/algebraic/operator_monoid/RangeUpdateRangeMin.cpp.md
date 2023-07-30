---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: datastructure/algebraic/monoid/MinMonoid.cpp
    title: datastructure/algebraic/monoid/MinMonoid.cpp
  - icon: ':warning:'
    path: datastructure/algebraic/monoid/SetMonoid.cpp
    title: datastructure/algebraic/monoid/SetMonoid.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/algebraic/operator_monoid/RangeUpdateRangeMin.cpp\"\
    \n\r\n#line 2 \"datastructure/algebraic/monoid/MinMonoid.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct MinMonoid{\r\n  T x = numeric_limits<T>::max();\r\n  MinMonoid()\
    \ = default;\r\n  MinMonoid(const MinMonoid&) = default;\r\n  MinMonoid(MinMonoid&&)\
    \ = default;\r\n\r\n  MinMonoid(const T &x): x(x) {}\r\n\r\n  MinMonoid &operator=(const\
    \ MinMonoid&) = default;\r\n  MinMonoid &operator=(MinMonoid&&) = default;\r\n\
    \r\n  MinMonoid &operator+=(const MinMonoid &m){\r\n    x = min(x, m.x);\r\n \
    \   return (*this);\r\n  }\r\n  MinMonoid operator+(const MinMonoid &m) const\
    \ {\r\n    return MinMonoid(*this) += m;\r\n  }\r\n};\r\n#line 2 \"datastructure/algebraic/monoid/SetMonoid.cpp\"\
    \n\r\ntemplate<typename T>\r\nstruct SetMonoid{\r\n  bool id = 1;\r\n  T x{};\r\
    \n\r\n  SetMonoid() = default;\r\n  SetMonoid(const SetMonoid&) = default;\r\n\
    \  SetMonoid(SetMonoid&&) = default;\r\n  SetMonoid &operator=(const SetMonoid&)\
    \ = default;\r\n  SetMonoid &operator=(SetMonoid&&) = default;\r\n\r\n  SetMonoid(const\
    \ T &x): id(false), x(x) {}\r\n\r\n  SetMonoid &operator+=(const SetMonoid &m){\r\
    \n    if(!m.id) id = m.id, x = m.x;\r\n    return (*this);\r\n  }\r\n\r\n  SetMonoid\
    \ operator+(const SetMonoid &m){ return SetMonoid(*this) += m; }\r\n\r\n  bool\
    \ operator==(const SetMonoid &m) const {\r\n    if(id && m.id) return true;\r\n\
    \    if(id != m.id) return false;\r\n    return x == m.x;\r\n  }\r\n\r\n  bool\
    \ operator!=(const SetMonoid &m) const { return !((*this) == m); }\r\n};\r\n#line\
    \ 5 \"datastructure/algebraic/operator_monoid/RangeUpdateRangeMin.cpp\"\n\r\n\
    template<typename T>\r\nstruct RangeUpdateRangeMin{\r\n  using Monoid = MinMonoid<T>;\r\
    \n  using OperatorMonoid = SetMonoid<T>;\r\n\r\n  static void act(Monoid &m, const\
    \ OperatorMonoid &f){\r\n    m.x = f.x;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include \"../monoid/MinMonoid.cpp\"\r\n#include \"../monoid/SetMonoid.cpp\"\
    \r\n\r\ntemplate<typename T>\r\nstruct RangeUpdateRangeMin{\r\n  using Monoid\
    \ = MinMonoid<T>;\r\n  using OperatorMonoid = SetMonoid<T>;\r\n\r\n  static void\
    \ act(Monoid &m, const OperatorMonoid &f){\r\n    m.x = f.x;\r\n  }\r\n};\r\n"
  dependsOn:
  - datastructure/algebraic/monoid/MinMonoid.cpp
  - datastructure/algebraic/monoid/SetMonoid.cpp
  isVerificationFile: false
  path: datastructure/algebraic/operator_monoid/RangeUpdateRangeMin.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/operator_monoid/RangeUpdateRangeMin.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/operator_monoid/RangeUpdateRangeMin.cpp
- /library/datastructure/algebraic/operator_monoid/RangeUpdateRangeMin.cpp.html
title: datastructure/algebraic/operator_monoid/RangeUpdateRangeMin.cpp
---
