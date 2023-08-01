---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: datastructure/algebraic/operator_monoid/RangeAffineRangeMinMaxSum.cpp
    title: datastructure/algebraic/operator_monoid/RangeAffineRangeMinMaxSum.cpp
  - icon: ':heavy_check_mark:'
    path: datastructure/algebraic/operator_monoid/RangeAffineRangeSum.cpp
    title: datastructure/algebraic/operator_monoid/RangeAffineRangeSum.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/lc/point_set_range_composite.test.cpp
    title: test/verify/lc/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/lc/range_affine_point_get.test.cpp
    title: test/verify/lc/range_affine_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/lc/range_affine_range_sum.test.cpp
    title: test/verify/lc/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/algebraic/monoid/CompositeMonoid.cpp\"\n\r\
    \ntemplate<typename T>\r\nstruct CompositeMonoid{\r\n  T a = 1, b = 0;\r\n  CompositeMonoid()\
    \ = default;\r\n  CompositeMonoid(const CompositeMonoid&) = default;\r\n  CompositeMonoid(CompositeMonoid&&)\
    \ = default;\r\n\r\n  CompositeMonoid(const T &a, const T &b): a(a), b(b) {}\r\
    \n\r\n  CompositeMonoid &operator=(const CompositeMonoid&) = default;\r\n  CompositeMonoid\
    \ &operator=(CompositeMonoid&&) = default;\r\n\r\n  CompositeMonoid &operator+=(const\
    \ CompositeMonoid &m){\r\n    a *= m.a;\r\n    b = b * m.a + m.b;\r\n    return\
    \ (*this);\r\n  }\r\n  CompositeMonoid operator+(const CompositeMonoid &m) const\
    \ {\r\n    return CompositeMonoid(*this) += m;\r\n  }\r\n  bool operator==(const\
    \ CompositeMonoid &m) const { return a == m.a && b == m.b; }\r\n  bool operator!=(const\
    \ CompositeMonoid &m) const { return !((*this) == m); }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct CompositeMonoid{\r\n \
    \ T a = 1, b = 0;\r\n  CompositeMonoid() = default;\r\n  CompositeMonoid(const\
    \ CompositeMonoid&) = default;\r\n  CompositeMonoid(CompositeMonoid&&) = default;\r\
    \n\r\n  CompositeMonoid(const T &a, const T &b): a(a), b(b) {}\r\n\r\n  CompositeMonoid\
    \ &operator=(const CompositeMonoid&) = default;\r\n  CompositeMonoid &operator=(CompositeMonoid&&)\
    \ = default;\r\n\r\n  CompositeMonoid &operator+=(const CompositeMonoid &m){\r\
    \n    a *= m.a;\r\n    b = b * m.a + m.b;\r\n    return (*this);\r\n  }\r\n  CompositeMonoid\
    \ operator+(const CompositeMonoid &m) const {\r\n    return CompositeMonoid(*this)\
    \ += m;\r\n  }\r\n  bool operator==(const CompositeMonoid &m) const { return a\
    \ == m.a && b == m.b; }\r\n  bool operator!=(const CompositeMonoid &m) const {\
    \ return !((*this) == m); }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/algebraic/monoid/CompositeMonoid.cpp
  requiredBy:
  - datastructure/algebraic/operator_monoid/RangeAffineRangeMinMaxSum.cpp
  - datastructure/algebraic/operator_monoid/RangeAffineRangeSum.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/lc/range_affine_point_get.test.cpp
  - test/verify/lc/range_affine_range_sum.test.cpp
  - test/verify/lc/point_set_range_composite.test.cpp
documentation_of: datastructure/algebraic/monoid/CompositeMonoid.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/monoid/CompositeMonoid.cpp
- /library/datastructure/algebraic/monoid/CompositeMonoid.cpp.html
title: datastructure/algebraic/monoid/CompositeMonoid.cpp
---
