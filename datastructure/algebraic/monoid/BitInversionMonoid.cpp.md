---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: datastructure/algebraic/operator_monoid/RangeFlipRangeBitInversion.cpp
    title: datastructure/algebraic/operator_monoid/RangeFlipRangeBitInversion.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/algebraic/monoid/BitInversionMonoid.cpp\"\n\
    \r\ntemplate<typename T>\r\nstruct BitInversionMonoid{\r\n\r\n  BitInversionMonoid()\
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
    \ BitInversionMonoid &m) const { return !((*this) == m); }\r\n\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct BitInversionMonoid{\r\n\
    \r\n  BitInversionMonoid() = default;\r\n  BitInversionMonoid(const BitInversionMonoid&)\
    \ = default;\r\n  BitInversionMonoid(BitInversionMonoid&&) = default;\r\n  BitInversionMonoid\
    \ &operator=(const BitInversionMonoid&) = default;\r\n  BitInversionMonoid &operator=(BitInversionMonoid&&)\
    \ = default;\r\n\r\n  T zero = 0, one = 0, inv = 0;\r\n  BitInversionMonoid(bool\
    \ b){\r\n    (b ? one : zero) = 1;\r\n  }\r\n\r\n  BitInversionMonoid &operator+=(const\
    \ BitInversionMonoid &m){\r\n    inv += m.inv + one * m.zero;\r\n    zero += m.zero;\r\
    \n    one += m.one;\r\n    return (*this);\r\n  }\r\n\r\n  BitInversionMonoid\
    \ operator+(const BitInversionMonoid &m){ return BitInversionMonoid(*this) +=\
    \ m; }\r\n\r\n  bool operator==(const BitInversionMonoid &m) const { return (zero\
    \ == m.zero) && (one == m.one) && (inv == m.inv); }\r\n  bool operator!=(const\
    \ BitInversionMonoid &m) const { return !((*this) == m); }\r\n\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/algebraic/monoid/BitInversionMonoid.cpp
  requiredBy:
  - datastructure/algebraic/operator_monoid/RangeFlipRangeBitInversion.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/monoid/BitInversionMonoid.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/monoid/BitInversionMonoid.cpp
- /library/datastructure/algebraic/monoid/BitInversionMonoid.cpp.html
title: datastructure/algebraic/monoid/BitInversionMonoid.cpp
---
