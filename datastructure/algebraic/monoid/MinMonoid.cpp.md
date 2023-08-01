---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: datastructure/algebraic/operator_monoid/RangeAddRangeMin.cpp
    title: datastructure/algebraic/operator_monoid/RangeAddRangeMin.cpp
  - icon: ':warning:'
    path: datastructure/algebraic/operator_monoid/RangeUpdateRangeMin.cpp
    title: datastructure/algebraic/operator_monoid/RangeUpdateRangeMin.cpp
  - icon: ':warning:'
    path: datastructure/algebraic/operator_monoid/RangechmaxRangeMin.cpp
    title: datastructure/algebraic/operator_monoid/RangechmaxRangeMin.cpp
  - icon: ':warning:'
    path: datastructure/algebraic/operator_monoid/RangechminRangeMax.cpp
    title: datastructure/algebraic/operator_monoid/RangechminRangeMax.cpp
  - icon: ':warning:'
    path: datastructure/algebraic/operator_monoid/RangechminRangeMin.cpp
    title: datastructure/algebraic/operator_monoid/RangechminRangeMin.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/lc/staticrmq_DequeAggregation.test.cpp
    title: test/verify/lc/staticrmq_DequeAggregation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/lc/staticrmq_SparseTable.test.cpp
    title: test/verify/lc/staticrmq_SparseTable.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/algebraic/monoid/MinMonoid.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct MinMonoid{\r\n  T x = numeric_limits<T>::max();\r\n  MinMonoid()\
    \ = default;\r\n  MinMonoid(const MinMonoid&) = default;\r\n  MinMonoid(MinMonoid&&)\
    \ = default;\r\n\r\n  MinMonoid(const T &x): x(x) {}\r\n\r\n  MinMonoid &operator=(const\
    \ MinMonoid&) = default;\r\n  MinMonoid &operator=(MinMonoid&&) = default;\r\n\
    \r\n  MinMonoid &operator+=(const MinMonoid &m){\r\n    x = min(x, m.x);\r\n \
    \   return (*this);\r\n  }\r\n  MinMonoid operator+(const MinMonoid &m) const\
    \ {\r\n    return MinMonoid(*this) += m;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct MinMonoid{\r\n  T x =\
    \ numeric_limits<T>::max();\r\n  MinMonoid() = default;\r\n  MinMonoid(const MinMonoid&)\
    \ = default;\r\n  MinMonoid(MinMonoid&&) = default;\r\n\r\n  MinMonoid(const T\
    \ &x): x(x) {}\r\n\r\n  MinMonoid &operator=(const MinMonoid&) = default;\r\n\
    \  MinMonoid &operator=(MinMonoid&&) = default;\r\n\r\n  MinMonoid &operator+=(const\
    \ MinMonoid &m){\r\n    x = min(x, m.x);\r\n    return (*this);\r\n  }\r\n  MinMonoid\
    \ operator+(const MinMonoid &m) const {\r\n    return MinMonoid(*this) += m;\r\
    \n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/algebraic/monoid/MinMonoid.cpp
  requiredBy:
  - datastructure/algebraic/operator_monoid/RangechmaxRangeMin.cpp
  - datastructure/algebraic/operator_monoid/RangechminRangeMax.cpp
  - datastructure/algebraic/operator_monoid/RangeUpdateRangeMin.cpp
  - datastructure/algebraic/operator_monoid/RangeAddRangeMin.cpp
  - datastructure/algebraic/operator_monoid/RangechminRangeMin.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/lc/staticrmq_SparseTable.test.cpp
  - test/verify/lc/staticrmq_DequeAggregation.test.cpp
documentation_of: datastructure/algebraic/monoid/MinMonoid.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/monoid/MinMonoid.cpp
- /library/datastructure/algebraic/monoid/MinMonoid.cpp.html
title: datastructure/algebraic/monoid/MinMonoid.cpp
---
