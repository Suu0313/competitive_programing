---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: datastructure/algebraic/monoid/ArithmeticUpdateMonoid.cpp
    title: datastructure/algebraic/monoid/ArithmeticUpdateMonoid.cpp
  - icon: ':warning:'
    path: datastructure/algebraic/monoid/MinMaxSumIdxMonoid.cpp
    title: datastructure/algebraic/monoid/MinMaxSumIdxMonoid.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/algebraic/operator_monoid/RangeArithmeticUpdateRangeMinMaxSum.cpp\"\
    \n\r\n#line 2 \"datastructure/algebraic/monoid/MinMaxSumIdxMonoid.cpp\"\n\r\n\
    template<typename T>\r\nstruct MinMaxSumIdxMonoid{\r\n  T mn = numeric_limits<T>::min(),\
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
    \ &m) const {\r\n    return MinMaxSumIdxMonoid(*this) += m;\r\n  }\r\n};\r\n#line\
    \ 2 \"datastructure/algebraic/monoid/ArithmeticUpdateMonoid.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct ArithmeticUpdateMonoid{\r\n  bool id = 1;\r\n  T a = T{}, b = T{};\r\
    \n\r\n  ArithmeticUpdateMonoid() = default;\r\n  ArithmeticUpdateMonoid(const\
    \ ArithmeticUpdateMonoid&) = default;\r\n  ArithmeticUpdateMonoid(ArithmeticUpdateMonoid&&)\
    \ = default;\r\n  ArithmeticUpdateMonoid &operator=(const ArithmeticUpdateMonoid&)\
    \ = default;\r\n  ArithmeticUpdateMonoid &operator=(ArithmeticUpdateMonoid&&)\
    \ = default;\r\n\r\n  ArithmeticUpdateMonoid(const T &a, const T &b): id(false),\
    \ a(a), b(b) {}\r\n  ArithmeticUpdateMonoid(const T &a, const T &b, size_t l):\
    \ id(false), a(a - b * l), b(b) {}\r\n\r\n  ArithmeticUpdateMonoid &operator+=(const\
    \ ArithmeticUpdateMonoid &m){\r\n    if(!m.id) id = m.id, a = m.a, b = m.b;\r\n\
    \    return (*this);\r\n  }\r\n\r\n  ArithmeticUpdateMonoid operator+(const ArithmeticUpdateMonoid\
    \ &m){ return ArithmeticUpdateMonoid(*this) += m; }\r\n\r\n  bool operator==(const\
    \ ArithmeticUpdateMonoid &m) const {\r\n    if(id && m.id) return true;\r\n  \
    \  if(id != m.id) return false;\r\n    return (a == m.a) && (b == m.b);\r\n  }\r\
    \n\r\n  bool operator!=(const ArithmeticUpdateMonoid &m) const { return !((*this)\
    \ == m); }\r\n};\r\n#line 5 \"datastructure/algebraic/operator_monoid/RangeArithmeticUpdateRangeMinMaxSum.cpp\"\
    \n\r\n\r\ntemplate<typename T>\r\nstruct RangeArithmeticUpdateRangeMinMaxSum{\r\
    \n  using Monoid = MinMaxSumIdxMonoid<T>;\r\n  using OperatorMonoid = ArithmeticUpdateMonoid<T>;\r\
    \n  static void act(Monoid &m, const OperatorMonoid &f){\r\n    if(f.id) return;\r\
    \n    T x = f.a + f.b * m.l, y = f.a + f.b * (m.r - 1);\r\n    m.mn = min(x, y);\
    \ m.mx = max(x, y);\r\n    m.sum = (x + y) * (m.r - m.l) /2;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include \"../monoid/MinMaxSumIdxMonoid.cpp\"\r\n#include\
    \ \"../monoid/ArithmeticUpdateMonoid.cpp\"\r\n\r\n\r\ntemplate<typename T>\r\n\
    struct RangeArithmeticUpdateRangeMinMaxSum{\r\n  using Monoid = MinMaxSumIdxMonoid<T>;\r\
    \n  using OperatorMonoid = ArithmeticUpdateMonoid<T>;\r\n  static void act(Monoid\
    \ &m, const OperatorMonoid &f){\r\n    if(f.id) return;\r\n    T x = f.a + f.b\
    \ * m.l, y = f.a + f.b * (m.r - 1);\r\n    m.mn = min(x, y); m.mx = max(x, y);\r\
    \n    m.sum = (x + y) * (m.r - m.l) /2;\r\n  }\r\n};\r\n"
  dependsOn:
  - datastructure/algebraic/monoid/MinMaxSumIdxMonoid.cpp
  - datastructure/algebraic/monoid/ArithmeticUpdateMonoid.cpp
  isVerificationFile: false
  path: datastructure/algebraic/operator_monoid/RangeArithmeticUpdateRangeMinMaxSum.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/operator_monoid/RangeArithmeticUpdateRangeMinMaxSum.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/operator_monoid/RangeArithmeticUpdateRangeMinMaxSum.cpp
- /library/datastructure/algebraic/operator_monoid/RangeArithmeticUpdateRangeMinMaxSum.cpp.html
title: datastructure/algebraic/operator_monoid/RangeArithmeticUpdateRangeMinMaxSum.cpp
---
