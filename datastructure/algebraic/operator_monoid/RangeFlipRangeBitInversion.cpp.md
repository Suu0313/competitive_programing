---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: datastructure/algebraic/monoid/BitInversionMonoid.cpp
    title: datastructure/algebraic/monoid/BitInversionMonoid.cpp
  - icon: ':warning:'
    path: datastructure/algebraic/monoid/XorMonoid.cpp
    title: datastructure/algebraic/monoid/XorMonoid.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/algebraic/operator_monoid/RangeFlipRangeBitInversion.cpp\"\
    \n\r\n#line 2 \"datastructure/algebraic/monoid/BitInversionMonoid.cpp\"\n\r\n\
    template<typename T>\r\nstruct BitInversionMonoid{\r\n\r\n  BitInversionMonoid()\
    \ = default;\r\n  BitInversionMonoid(const BitInversionMonoid&) = default;\r\n\
    \  BitInversionMonoid(BitInversionMonoid&&) = default;\r\n  BitInversionMonoid\
    \ &operator=(const BitInversionMonoid&) = default;\r\n  BitInversionMonoid &operator=(BitInversionMonoid&&)\
    \ = default;\r\n\r\n  T zero = 0, one = 0, inv = 0;\r\n  BitInversionMonoid(bool\
    \ b){\r\n    (b ? one : zero) = 1;\r\n  }\r\n\r\n  BitInversionMonoid &operator+=(const\
    \ BitInversionMonoid &m){\r\n    inv += m.inv + one * m.zero;\r\n    zero += m.zero;\r\
    \n    one += m.one;\r\n    return (*this);\r\n  }\r\n\r\n  BitInversionMonoid\
    \ operator+(const BitInversionMonoid &m){ return BitInversionMonoid(*this) +=\
    \ m; }\r\n\r\n  bool operator==(const BitInversionMonoid &m) const { return (zero\
    \ == m.zero) && (one == m.one) && (inv == m.inv); }\r\n  bool operator!=(const\
    \ BitInversionMonoid &m) const { return !((*this) == m); }\r\n\r\n};\r\n#line\
    \ 4 \"datastructure/algebraic/operator_monoid/RangeFlipRangeBitInversion.cpp\"\
    \n\r\n#line 2 \"datastructure/algebraic/monoid/XorMonoid.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct XorMonoid{\r\n\r\n  XorMonoid() = default;\r\n  XorMonoid(const\
    \ XorMonoid&) = default;\r\n  XorMonoid(XorMonoid&&) = default;\r\n  XorMonoid\
    \ &operator=(const XorMonoid&) = default;\r\n  XorMonoid &operator=(XorMonoid&&)\
    \ = default;\r\n\r\n  T x = 0;\r\n  XorMonoid(const T &x): x(x) {}\r\n\r\n  XorMonoid\
    \ &operator+=(const XorMonoid &m){\r\n    x ^= m.x;\r\n    return (*this);\r\n\
    \  }\r\n\r\n  XorMonoid operator+(const XorMonoid &m){ return XorMonoid(*this)\
    \ += m; }\r\n\r\n  bool operator==(const XorMonoid &m) const { return x == m.x;\
    \ }\r\n  bool operator!=(const XorMonoid &m) const { return !((*this) == m); }\r\
    \n\r\n};\r\n#line 6 \"datastructure/algebraic/operator_monoid/RangeFlipRangeBitInversion.cpp\"\
    \n\r\ntemplate<typename T>\r\nstruct RangeFlipRangeBitInversion{\r\n  using Monoid\
    \ = BitInversionMonoid<T>;\r\n  using OperatorMonoid = XorMonoid<bool>;\r\n  static\
    \ void act(Monoid &m, const OperatorMonoid &f){\r\n    if(!f.x) return;\r\n  \
    \  m.inv = m.zero * m.one - m.inv;\r\n    swap(m.zero, m.one);\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include \"../monoid/BitInversionMonoid.cpp\"\r\n\r\n\
    #include \"../monoid/XorMonoid.cpp\"\r\n\r\ntemplate<typename T>\r\nstruct RangeFlipRangeBitInversion{\r\
    \n  using Monoid = BitInversionMonoid<T>;\r\n  using OperatorMonoid = XorMonoid<bool>;\r\
    \n  static void act(Monoid &m, const OperatorMonoid &f){\r\n    if(!f.x) return;\r\
    \n    m.inv = m.zero * m.one - m.inv;\r\n    swap(m.zero, m.one);\r\n  }\r\n};\r\
    \n"
  dependsOn:
  - datastructure/algebraic/monoid/BitInversionMonoid.cpp
  - datastructure/algebraic/monoid/XorMonoid.cpp
  isVerificationFile: false
  path: datastructure/algebraic/operator_monoid/RangeFlipRangeBitInversion.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/operator_monoid/RangeFlipRangeBitInversion.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/operator_monoid/RangeFlipRangeBitInversion.cpp
- /library/datastructure/algebraic/operator_monoid/RangeFlipRangeBitInversion.cpp.html
title: datastructure/algebraic/operator_monoid/RangeFlipRangeBitInversion.cpp
---
