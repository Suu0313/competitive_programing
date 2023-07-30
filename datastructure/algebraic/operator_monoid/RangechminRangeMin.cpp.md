---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: datastructure/algebraic/monoid/MinMonoid.cpp
    title: datastructure/algebraic/monoid/MinMonoid.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/algebraic/operator_monoid/RangechminRangeMin.cpp\"\
    \n\r\n#line 2 \"datastructure/algebraic/monoid/MinMonoid.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct MinMonoid{\r\n  T x = numeric_limits<T>::max();\r\n  MinMonoid()\
    \ = default;\r\n  MinMonoid(const MinMonoid&) = default;\r\n  MinMonoid(MinMonoid&&)\
    \ = default;\r\n\r\n  MinMonoid(const T &x): x(x) {}\r\n\r\n  MinMonoid &operator=(const\
    \ MinMonoid&) = default;\r\n  MinMonoid &operator=(MinMonoid&&) = default;\r\n\
    \r\n  MinMonoid &operator+=(const MinMonoid &m){\r\n    x = min(x, m.x);\r\n \
    \   return (*this);\r\n  }\r\n  MinMonoid operator+(const MinMonoid &m) const\
    \ {\r\n    return MinMonoid(*this) += m;\r\n  }\r\n};\r\n#line 4 \"datastructure/algebraic/operator_monoid/RangechminRangeMin.cpp\"\
    \n\r\ntemplate<typename T>\r\nstruct RangechminRangeMin{\r\n  using Monoid = MinMonoid<T>;\r\
    \n  using OperatorMonoid = MinMonoid<T>;\r\n\r\n  static void act(Monoid &m, const\
    \ OperatorMonoid &f){\r\n    m += f;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include \"../monoid/MinMonoid.cpp\"\r\n\r\ntemplate<typename\
    \ T>\r\nstruct RangechminRangeMin{\r\n  using Monoid = MinMonoid<T>;\r\n  using\
    \ OperatorMonoid = MinMonoid<T>;\r\n\r\n  static void act(Monoid &m, const OperatorMonoid\
    \ &f){\r\n    m += f;\r\n  }\r\n};\r\n"
  dependsOn:
  - datastructure/algebraic/monoid/MinMonoid.cpp
  isVerificationFile: false
  path: datastructure/algebraic/operator_monoid/RangechminRangeMin.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/operator_monoid/RangechminRangeMin.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/operator_monoid/RangechminRangeMin.cpp
- /library/datastructure/algebraic/operator_monoid/RangechminRangeMin.cpp.html
title: datastructure/algebraic/operator_monoid/RangechminRangeMin.cpp
---
