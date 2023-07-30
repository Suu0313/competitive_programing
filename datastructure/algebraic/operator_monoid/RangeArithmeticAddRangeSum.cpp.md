---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: datastructure/algebraic/monoid/PairAddMonoid.cpp
    title: datastructure/algebraic/monoid/PairAddMonoid.cpp
  - icon: ':warning:'
    path: datastructure/algebraic/monoid/SumIdxMonoid.cpp
    title: datastructure/algebraic/monoid/SumIdxMonoid.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/algebraic/operator_monoid/RangeArithmeticAddRangeSum.cpp\"\
    \n\r\n#line 2 \"datastructure/algebraic/monoid/SumIdxMonoid.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct SumIdxMonoid{\r\n  T sum = 0;\r\n  int l = -1, r = -1;\r\n  SumIdxMonoid()\
    \ = default;\r\n  SumIdxMonoid(const SumIdxMonoid&) = default;\r\n  SumIdxMonoid(SumIdxMonoid&&)\
    \ = default;\r\n\r\n  SumIdxMonoid(const T &x, int k): sum(x), l(k), r(k + 1)\
    \ {}\r\n\r\n  SumIdxMonoid &operator=(const SumIdxMonoid&) = default;\r\n  SumIdxMonoid\
    \ &operator=(SumIdxMonoid&&) = default;\r\n\r\n  SumIdxMonoid &operator+=(const\
    \ SumIdxMonoid &m){\r\n    if(m.l == -1) return (*this);\r\n    if(this->l ==\
    \ -1) return (*this) = m;\r\n    sum += m.sum;\r\n    r = m.r;\r\n    return (*this);\r\
    \n  }\r\n  SumIdxMonoid operator+(const SumIdxMonoid &m) const {\r\n    return\
    \ SumIdxMonoid(*this) += m;\r\n  }\r\n};\r\n#line 2 \"datastructure/algebraic/monoid/PairAddMonoid.cpp\"\
    \n\r\ntemplate<typename T>\r\nstruct PairAddMonoid{\r\n  T a = T{}, b = T{};\r\
    \n\r\n  PairAddMonoid() = default;\r\n  PairAddMonoid(const PairAddMonoid&) =\
    \ default;\r\n  PairAddMonoid(PairAddMonoid&&) = default;\r\n  PairAddMonoid &operator=(const\
    \ PairAddMonoid&) = default;\r\n  PairAddMonoid &operator=(PairAddMonoid&&) =\
    \ default;\r\n\r\n  PairAddMonoid(const T &a, const T &b): a(a), b(b) {}\r\n \
    \ PairAddMonoid(const T &a, const T &b, size_t l): a(a - b * l), b(b) {}\r\n\r\
    \n  PairAddMonoid &operator+=(const PairAddMonoid &m){\r\n    a += m.a, b += m.b;\r\
    \n    return (*this);\r\n  }\r\n\r\n  PairAddMonoid operator+(const PairAddMonoid\
    \ &m) const { return PairAddMonoid(*this) += m; }\r\n\r\n  bool operator==(const\
    \ PairAddMonoid &m) const { return (a == m.a) && (b == m.b); }\r\n\r\n  bool operator!=(const\
    \ PairAddMonoid &m) const { return !((*this) == m); }\r\n};\r\n#line 5 \"datastructure/algebraic/operator_monoid/RangeArithmeticAddRangeSum.cpp\"\
    \n\r\ntemplate<typename T>\r\nstruct RangeArithmeticAddRangeSum{\r\n  using Monoid\
    \ = SumIdxMonoid<T>;\r\n  using OperatorMonoid = PairAddMonoid<T>;\r\n  static\
    \ void act(Monoid &m, const OperatorMonoid &f){\r\n    T a = f.a + f.b * m.l;\r\
    \n    m.sum += (a * 2 + f.b * (m.r - m.l - 1)) * (m.r - m.l) / 2;\r\n  }\r\n};\r\
    \n"
  code: "#pragma once\r\n\r\n#include \"../monoid/SumIdxMonoid.cpp\"\r\n#include \"\
    ../monoid/PairAddMonoid.cpp\"\r\n\r\ntemplate<typename T>\r\nstruct RangeArithmeticAddRangeSum{\r\
    \n  using Monoid = SumIdxMonoid<T>;\r\n  using OperatorMonoid = PairAddMonoid<T>;\r\
    \n  static void act(Monoid &m, const OperatorMonoid &f){\r\n    T a = f.a + f.b\
    \ * m.l;\r\n    m.sum += (a * 2 + f.b * (m.r - m.l - 1)) * (m.r - m.l) / 2;\r\n\
    \  }\r\n};\r\n"
  dependsOn:
  - datastructure/algebraic/monoid/SumIdxMonoid.cpp
  - datastructure/algebraic/monoid/PairAddMonoid.cpp
  isVerificationFile: false
  path: datastructure/algebraic/operator_monoid/RangeArithmeticAddRangeSum.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/operator_monoid/RangeArithmeticAddRangeSum.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/operator_monoid/RangeArithmeticAddRangeSum.cpp
- /library/datastructure/algebraic/operator_monoid/RangeArithmeticAddRangeSum.cpp.html
title: datastructure/algebraic/operator_monoid/RangeArithmeticAddRangeSum.cpp
---
