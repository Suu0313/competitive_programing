---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: datastructure/algebraic/monoid/CompositeMonoid.cpp
    title: datastructure/algebraic/monoid/CompositeMonoid.cpp
  - icon: ':warning:'
    path: datastructure/algebraic/monoid/LengthMonoid.cpp
    title: datastructure/algebraic/monoid/LengthMonoid.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/algebraic/operator_monoid/RangeAffineRangeSum.cpp\"\
    \n\r\n\r\n#line 2 \"datastructure/algebraic/monoid/LengthMonoid.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct LengthMonoid{\r\n  T x{};\r\n  size_t l = 0;\r\n\r\n  LengthMonoid()\
    \ = default;\r\n  LengthMonoid(const LengthMonoid&) = default;\r\n  LengthMonoid(LengthMonoid&&)\
    \ = default;\r\n\r\n  LengthMonoid(const T &x, size_t l = 1): x(x), l(l) {}\r\n\
    \r\n  LengthMonoid &operator=(const LengthMonoid&) = default;\r\n  LengthMonoid\
    \ &operator=(LengthMonoid&&) = default;\r\n\r\n  LengthMonoid &operator+=(const\
    \ LengthMonoid &m){\r\n    x += m.x; l += m.l;\r\n    return (*this);\r\n  }\r\
    \n  LengthMonoid operator+(const LengthMonoid &m) const {\r\n    return LengthMonoid(*this)\
    \ += m;\r\n  }\r\n\r\n  bool operator==(const LengthMonoid &m) const { return\
    \ x == m.x && l == m.l; }\r\n  bool operator!=(const LengthMonoid &m) const {\
    \ return !((*this) == m); }\r\n};\r\n#line 2 \"datastructure/algebraic/monoid/CompositeMonoid.cpp\"\
    \n\r\ntemplate<typename T>\r\nstruct CompositeMonoid{\r\n  T a = 1, b = 0;\r\n\
    \  CompositeMonoid() = default;\r\n  CompositeMonoid(const CompositeMonoid&) =\
    \ default;\r\n  CompositeMonoid(CompositeMonoid&&) = default;\r\n\r\n  CompositeMonoid(const\
    \ T &a, const T &b): a(a), b(b) {}\r\n\r\n  CompositeMonoid &operator=(const CompositeMonoid&)\
    \ = default;\r\n  CompositeMonoid &operator=(CompositeMonoid&&) = default;\r\n\
    \r\n  CompositeMonoid &operator+=(const CompositeMonoid &m){\r\n    a *= m.a;\r\
    \n    b = b * m.a + m.b;\r\n    return (*this);\r\n  }\r\n  CompositeMonoid operator+(const\
    \ CompositeMonoid &m) const {\r\n    return CompositeMonoid(*this) += m;\r\n \
    \ }\r\n  bool operator==(const CompositeMonoid &m) const { return a == m.a &&\
    \ b == m.b; }\r\n  bool operator!=(const CompositeMonoid &m) const { return !((*this)\
    \ == m); }\r\n};\r\n#line 6 \"datastructure/algebraic/operator_monoid/RangeAffineRangeSum.cpp\"\
    \n\r\ntemplate<typename T>\r\nstruct RangeAffineRangeSum{\r\n  using Monoid =\
    \ LengthMonoid<T>;\r\n  using OperatorMonoid = CompositeMonoid<T>;\r\n\r\n  static\
    \ void act(Monoid &m, const OperatorMonoid &f){\r\n    m = Monoid(f.a * m.x +\
    \ f.b * m.l, m.l);\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n\r\n#include \"../monoid/LengthMonoid.cpp\"\r\n#include\
    \ \"../monoid/CompositeMonoid.cpp\"\r\n\r\ntemplate<typename T>\r\nstruct RangeAffineRangeSum{\r\
    \n  using Monoid = LengthMonoid<T>;\r\n  using OperatorMonoid = CompositeMonoid<T>;\r\
    \n\r\n  static void act(Monoid &m, const OperatorMonoid &f){\r\n    m = Monoid(f.a\
    \ * m.x + f.b * m.l, m.l);\r\n  }\r\n};\r\n"
  dependsOn:
  - datastructure/algebraic/monoid/LengthMonoid.cpp
  - datastructure/algebraic/monoid/CompositeMonoid.cpp
  isVerificationFile: false
  path: datastructure/algebraic/operator_monoid/RangeAffineRangeSum.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/operator_monoid/RangeAffineRangeSum.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/operator_monoid/RangeAffineRangeSum.cpp
- /library/datastructure/algebraic/operator_monoid/RangeAffineRangeSum.cpp.html
title: datastructure/algebraic/operator_monoid/RangeAffineRangeSum.cpp
---
