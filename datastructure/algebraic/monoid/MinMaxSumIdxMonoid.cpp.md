---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: datastructure/algebraic/operator_monoid/RangeArithmeticUpdateRangeMinMaxSum.cpp
    title: datastructure/algebraic/operator_monoid/RangeArithmeticUpdateRangeMinMaxSum.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/algebraic/monoid/MinMaxSumIdxMonoid.cpp\"\n\
    \r\ntemplate<typename T>\r\nstruct MinMaxSumIdxMonoid{\r\n  T mn = numeric_limits<T>::min(),\
    \ mx = numeric_limits<T>::max(), sum = 0;\r\n  int l = -1, r = -1;\r\n  MinMaxSumIdxMonoid()\
    \ = default;\r\n  MinMaxSumIdxMonoid(const MinMaxSumIdxMonoid&) = default;\r\n\
    \  MinMaxSumIdxMonoid(MinMaxSumIdxMonoid&&) = default;\r\n\r\n  MinMaxSumIdxMonoid(const\
    \ T &x, int k): mn(x), mx(x), sum(x), l(k), r(k + 1) {}\r\n  MinMaxSumIdxMonoid(const\
    \ T &x, int l, int r): mn(x), mx(x), sum(x * (r - l)), l(l), r(r) {}\r\n  MinMaxSumIdxMonoid(const\
    \ T &mn, const T &mx, const T &sum, int l, int r): mn(mn), mx(mx), sum(sum), l(l),\
    \ r(r) {}\r\n\r\n  MinMaxSumIdxMonoid &operator=(const MinMaxSumIdxMonoid&) =\
    \ default;\r\n  MinMaxSumIdxMonoid &operator=(MinMaxSumIdxMonoid&&) = default;\r\
    \n\r\n  MinMaxSumIdxMonoid &operator+=(const MinMaxSumIdxMonoid &m){\r\n    if(m.l\
    \ == -1) return (*this);\r\n    if(this->l == -1) return (*this) = m;\r\n    mn\
    \ = min(mn, m.mn);\r\n    mx = max(mx, m.mx);\r\n    sum += m.sum;\r\n    r =\
    \ m.r;\r\n    return (*this);\r\n  }\r\n  MinMaxSumIdxMonoid operator+(const MinMaxSumIdxMonoid\
    \ &m) const {\r\n    return MinMaxSumIdxMonoid(*this) += m;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct MinMaxSumIdxMonoid{\r\n\
    \  T mn = numeric_limits<T>::min(), mx = numeric_limits<T>::max(), sum = 0;\r\n\
    \  int l = -1, r = -1;\r\n  MinMaxSumIdxMonoid() = default;\r\n  MinMaxSumIdxMonoid(const\
    \ MinMaxSumIdxMonoid&) = default;\r\n  MinMaxSumIdxMonoid(MinMaxSumIdxMonoid&&)\
    \ = default;\r\n\r\n  MinMaxSumIdxMonoid(const T &x, int k): mn(x), mx(x), sum(x),\
    \ l(k), r(k + 1) {}\r\n  MinMaxSumIdxMonoid(const T &x, int l, int r): mn(x),\
    \ mx(x), sum(x * (r - l)), l(l), r(r) {}\r\n  MinMaxSumIdxMonoid(const T &mn,\
    \ const T &mx, const T &sum, int l, int r): mn(mn), mx(mx), sum(sum), l(l), r(r)\
    \ {}\r\n\r\n  MinMaxSumIdxMonoid &operator=(const MinMaxSumIdxMonoid&) = default;\r\
    \n  MinMaxSumIdxMonoid &operator=(MinMaxSumIdxMonoid&&) = default;\r\n\r\n  MinMaxSumIdxMonoid\
    \ &operator+=(const MinMaxSumIdxMonoid &m){\r\n    if(m.l == -1) return (*this);\r\
    \n    if(this->l == -1) return (*this) = m;\r\n    mn = min(mn, m.mn);\r\n   \
    \ mx = max(mx, m.mx);\r\n    sum += m.sum;\r\n    r = m.r;\r\n    return (*this);\r\
    \n  }\r\n  MinMaxSumIdxMonoid operator+(const MinMaxSumIdxMonoid &m) const {\r\
    \n    return MinMaxSumIdxMonoid(*this) += m;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/algebraic/monoid/MinMaxSumIdxMonoid.cpp
  requiredBy:
  - datastructure/algebraic/operator_monoid/RangeArithmeticUpdateRangeMinMaxSum.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/monoid/MinMaxSumIdxMonoid.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/monoid/MinMaxSumIdxMonoid.cpp
- /library/datastructure/algebraic/monoid/MinMaxSumIdxMonoid.cpp.html
title: datastructure/algebraic/monoid/MinMaxSumIdxMonoid.cpp
---
