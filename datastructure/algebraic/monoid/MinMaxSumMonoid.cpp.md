---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: datastructure/algebraic/operator_monoid/RangeAffineRangeMinMaxSum.cpp
    title: datastructure/algebraic/operator_monoid/RangeAffineRangeMinMaxSum.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/algebraic/monoid/MinMaxSumMonoid.cpp\"\n\r\
    \ntemplate<typename T>\r\nstruct MinMaxSumMonoid{\r\n  T mn = numeric_limits<T>::min(),\
    \ mx = numeric_limits<T>::max(), sum = 0;\r\n  size_t len = 0;\r\n  MinMaxSumMonoid()\
    \ = default;\r\n  MinMaxSumMonoid(const MinMaxSumMonoid&) = default;\r\n  MinMaxSumMonoid(MinMaxSumMonoid&&)\
    \ = default;\r\n\r\n  MinMaxSumMonoid(const T &x, size_t l = 1): mn(x), mx(x),\
    \ sum(x * l), len(l) {}\r\n  MinMaxSumMonoid(const T &mn, const T &mx, const T\
    \ &sum, size_t len): mn(mn), mx(mx), sum(sum), len(len) {}\r\n\r\n  MinMaxSumMonoid\
    \ &operator=(const MinMaxSumMonoid&) = default;\r\n  MinMaxSumMonoid &operator=(MinMaxSumMonoid&&)\
    \ = default;\r\n\r\n  MinMaxSumMonoid &operator+=(const MinMaxSumMonoid &m){\r\
    \n    mn = min(mn, m.mn);\r\n    mx = max(mx, m.mx);\r\n    sum += m.sum;\r\n\
    \    len += m.len;\r\n    return (*this);\r\n  }\r\n  MinMaxSumMonoid operator+(const\
    \ MinMaxSumMonoid &m) const {\r\n    return MinMaxSumMonoid(*this) += m;\r\n \
    \ }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct MinMaxSumMonoid{\r\n \
    \ T mn = numeric_limits<T>::min(), mx = numeric_limits<T>::max(), sum = 0;\r\n\
    \  size_t len = 0;\r\n  MinMaxSumMonoid() = default;\r\n  MinMaxSumMonoid(const\
    \ MinMaxSumMonoid&) = default;\r\n  MinMaxSumMonoid(MinMaxSumMonoid&&) = default;\r\
    \n\r\n  MinMaxSumMonoid(const T &x, size_t l = 1): mn(x), mx(x), sum(x * l), len(l)\
    \ {}\r\n  MinMaxSumMonoid(const T &mn, const T &mx, const T &sum, size_t len):\
    \ mn(mn), mx(mx), sum(sum), len(len) {}\r\n\r\n  MinMaxSumMonoid &operator=(const\
    \ MinMaxSumMonoid&) = default;\r\n  MinMaxSumMonoid &operator=(MinMaxSumMonoid&&)\
    \ = default;\r\n\r\n  MinMaxSumMonoid &operator+=(const MinMaxSumMonoid &m){\r\
    \n    mn = min(mn, m.mn);\r\n    mx = max(mx, m.mx);\r\n    sum += m.sum;\r\n\
    \    len += m.len;\r\n    return (*this);\r\n  }\r\n  MinMaxSumMonoid operator+(const\
    \ MinMaxSumMonoid &m) const {\r\n    return MinMaxSumMonoid(*this) += m;\r\n \
    \ }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/algebraic/monoid/MinMaxSumMonoid.cpp
  requiredBy:
  - datastructure/algebraic/operator_monoid/RangeAffineRangeMinMaxSum.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/monoid/MinMaxSumMonoid.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/monoid/MinMaxSumMonoid.cpp
- /library/datastructure/algebraic/monoid/MinMaxSumMonoid.cpp.html
title: datastructure/algebraic/monoid/MinMaxSumMonoid.cpp
---
