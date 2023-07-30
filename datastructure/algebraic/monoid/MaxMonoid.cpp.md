---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: datastructure/algebraic/operator_monoid/RangeAddRangeMax.cpp
    title: datastructure/algebraic/operator_monoid/RangeAddRangeMax.cpp
  - icon: ':warning:'
    path: datastructure/algebraic/operator_monoid/RangeUpdateRangeMax.cpp
    title: datastructure/algebraic/operator_monoid/RangeUpdateRangeMax.cpp
  - icon: ':warning:'
    path: datastructure/algebraic/operator_monoid/RangechmaxRangeMax.cpp
    title: datastructure/algebraic/operator_monoid/RangechmaxRangeMax.cpp
  - icon: ':warning:'
    path: datastructure/algebraic/operator_monoid/RangechmaxRangeMin.cpp
    title: datastructure/algebraic/operator_monoid/RangechmaxRangeMin.cpp
  - icon: ':warning:'
    path: datastructure/algebraic/operator_monoid/RangechminRangeMax.cpp
    title: datastructure/algebraic/operator_monoid/RangechminRangeMax.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/algebraic/monoid/MaxMonoid.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct MaxMonoid{\r\n  T x = numeric_limits<T>::min();\r\n  MaxMonoid()\
    \ = default;\r\n  MaxMonoid(const MaxMonoid&) = default;\r\n  MaxMonoid(MaxMonoid&&)\
    \ = default;\r\n\r\n  MaxMonoid(const T &x): x(x) {}\r\n\r\n  MaxMonoid &operator=(const\
    \ MaxMonoid&) = default;\r\n  MaxMonoid &operator=(MaxMonoid&&) = default;\r\n\
    \r\n  MaxMonoid &operator+=(const MaxMonoid &m){\r\n    x = max(x, m.x);\r\n \
    \   return (*this);\r\n  }\r\n  MaxMonoid operator+(const MaxMonoid &m) const\
    \ {\r\n    return MaxMonoid(*this) += m;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct MaxMonoid{\r\n  T x =\
    \ numeric_limits<T>::min();\r\n  MaxMonoid() = default;\r\n  MaxMonoid(const MaxMonoid&)\
    \ = default;\r\n  MaxMonoid(MaxMonoid&&) = default;\r\n\r\n  MaxMonoid(const T\
    \ &x): x(x) {}\r\n\r\n  MaxMonoid &operator=(const MaxMonoid&) = default;\r\n\
    \  MaxMonoid &operator=(MaxMonoid&&) = default;\r\n\r\n  MaxMonoid &operator+=(const\
    \ MaxMonoid &m){\r\n    x = max(x, m.x);\r\n    return (*this);\r\n  }\r\n  MaxMonoid\
    \ operator+(const MaxMonoid &m) const {\r\n    return MaxMonoid(*this) += m;\r\
    \n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/algebraic/monoid/MaxMonoid.cpp
  requiredBy:
  - datastructure/algebraic/operator_monoid/RangechmaxRangeMax.cpp
  - datastructure/algebraic/operator_monoid/RangeUpdateRangeMax.cpp
  - datastructure/algebraic/operator_monoid/RangechmaxRangeMin.cpp
  - datastructure/algebraic/operator_monoid/RangechminRangeMax.cpp
  - datastructure/algebraic/operator_monoid/RangeAddRangeMax.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/monoid/MaxMonoid.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/monoid/MaxMonoid.cpp
- /library/datastructure/algebraic/monoid/MaxMonoid.cpp.html
title: datastructure/algebraic/monoid/MaxMonoid.cpp
---
