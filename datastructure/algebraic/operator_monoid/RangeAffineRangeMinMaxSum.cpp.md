---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: datastructure/algebraic/monoid/CompositeMonoid.cpp
    title: datastructure/algebraic/monoid/CompositeMonoid.cpp
  - icon: ':warning:'
    path: datastructure/algebraic/monoid/MinMaxSumMonoid.cpp
    title: datastructure/algebraic/monoid/MinMaxSumMonoid.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/algebraic/operator_monoid/RangeAffineRangeMinMaxSum.cpp\"\
    \n\r\n#line 2 \"datastructure/algebraic/monoid/MinMaxSumMonoid.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct MinMaxSumMonoid{\r\n  T mn = numeric_limits<T>::min(), mx = numeric_limits<T>::max(),\
    \ sum = 0;\r\n  size_t len = 0;\r\n  MinMaxSumMonoid() = default;\r\n  MinMaxSumMonoid(const\
    \ MinMaxSumMonoid&) = default;\r\n  MinMaxSumMonoid(MinMaxSumMonoid&&) = default;\r\
    \n\r\n  MinMaxSumMonoid(const T &x, size_t l = 1): mn(x), mx(x), sum(x * l), len(l)\
    \ {}\r\n  MinMaxSumMonoid(const T &mn, const T &mx, const T &sum, size_t len):\
    \ mn(mn), mx(mx), sum(sum), len(len) {}\r\n\r\n  MinMaxSumMonoid &operator=(const\
    \ MinMaxSumMonoid&) = default;\r\n  MinMaxSumMonoid &operator=(MinMaxSumMonoid&&)\
    \ = default;\r\n\r\n  MinMaxSumMonoid &operator+=(const MinMaxSumMonoid &m){\r\
    \n    mn = min(mn, m.mn);\r\n    mx = max(mx, m.mx);\r\n    sum += m.sum;\r\n\
    \    len += m.len;\r\n    return (*this);\r\n  }\r\n  MinMaxSumMonoid operator+(const\
    \ MinMaxSumMonoid &m) const {\r\n    return MinMaxSumMonoid(*this) += m;\r\n \
    \ }\r\n};\r\n#line 2 \"datastructure/algebraic/monoid/CompositeMonoid.cpp\"\n\r\
    \ntemplate<typename T>\r\nstruct CompositeMonoid{\r\n  T a = 1, b = 0;\r\n  CompositeMonoid()\
    \ = default;\r\n  CompositeMonoid(const CompositeMonoid&) = default;\r\n  CompositeMonoid(CompositeMonoid&&)\
    \ = default;\r\n\r\n  CompositeMonoid(const T &a, const T &b): a(a), b(b) {}\r\
    \n\r\n  CompositeMonoid &operator=(const CompositeMonoid&) = default;\r\n  CompositeMonoid\
    \ &operator=(CompositeMonoid&&) = default;\r\n\r\n  CompositeMonoid &operator+=(const\
    \ CompositeMonoid &m){\r\n    a *= m.a;\r\n    b = b * m.a + m.b;\r\n    return\
    \ (*this);\r\n  }\r\n  CompositeMonoid operator+(const CompositeMonoid &m) const\
    \ {\r\n    return CompositeMonoid(*this) += m;\r\n  }\r\n  bool operator==(const\
    \ CompositeMonoid &m) const { return a == m.a && b == m.b; }\r\n  bool operator!=(const\
    \ CompositeMonoid &m) const { return !((*this) == m); }\r\n};\r\n#line 5 \"datastructure/algebraic/operator_monoid/RangeAffineRangeMinMaxSum.cpp\"\
    \n\r\ntemplate<typename T>\r\nstruct RangeAffineRangeMinMaxSum{\r\n  using Monoid\
    \ = MinMaxSumMonoid<T>;\r\n  using OperatorMonoid = CompositeMonoid<T>;\r\n\r\n\
    \  static void act(Monoid &m, const OperatorMonoid &f){\r\n    T x1 = f.a * m.mn\
    \ + f.b;\r\n    T x2 = f.a * m.mx + f.b;\r\n    T sum = f.a * m.sum + f.b * m.len;\r\
    \n    m = Monoid(min(x1, x2), max(x1, x2), sum, m.len);\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include \"../monoid/MinMaxSumMonoid.cpp\"\r\n#include\
    \ \"../monoid/CompositeMonoid.cpp\"\r\n\r\ntemplate<typename T>\r\nstruct RangeAffineRangeMinMaxSum{\r\
    \n  using Monoid = MinMaxSumMonoid<T>;\r\n  using OperatorMonoid = CompositeMonoid<T>;\r\
    \n\r\n  static void act(Monoid &m, const OperatorMonoid &f){\r\n    T x1 = f.a\
    \ * m.mn + f.b;\r\n    T x2 = f.a * m.mx + f.b;\r\n    T sum = f.a * m.sum + f.b\
    \ * m.len;\r\n    m = Monoid(min(x1, x2), max(x1, x2), sum, m.len);\r\n  }\r\n\
    };\r\n"
  dependsOn:
  - datastructure/algebraic/monoid/MinMaxSumMonoid.cpp
  - datastructure/algebraic/monoid/CompositeMonoid.cpp
  isVerificationFile: false
  path: datastructure/algebraic/operator_monoid/RangeAffineRangeMinMaxSum.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/operator_monoid/RangeAffineRangeMinMaxSum.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/operator_monoid/RangeAffineRangeMinMaxSum.cpp
- /library/datastructure/algebraic/operator_monoid/RangeAffineRangeMinMaxSum.cpp.html
title: datastructure/algebraic/operator_monoid/RangeAffineRangeMinMaxSum.cpp
---
