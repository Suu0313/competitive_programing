---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: datastructure/algebraic/monoid/MaxMonoid.cpp
    title: datastructure/algebraic/monoid/MaxMonoid.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/algebraic/operator_monoid/RangechmaxRangeMax.cpp\"\
    \n\r\n#line 2 \"datastructure/algebraic/monoid/MaxMonoid.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct MaxMonoid{\r\n  T x = numeric_limits<T>::min();\r\n  MaxMonoid()\
    \ = default;\r\n  MaxMonoid(const MaxMonoid&) = default;\r\n  MaxMonoid(MaxMonoid&&)\
    \ = default;\r\n\r\n  MaxMonoid(const T &x): x(x) {}\r\n\r\n  MaxMonoid &operator=(const\
    \ MaxMonoid&) = default;\r\n  MaxMonoid &operator=(MaxMonoid&&) = default;\r\n\
    \r\n  MaxMonoid &operator+=(const MaxMonoid &m){\r\n    x = max(x, m.x);\r\n \
    \   return (*this);\r\n  }\r\n  MaxMonoid operator+(const MaxMonoid &m) const\
    \ {\r\n    return MaxMonoid(*this) += m;\r\n  }\r\n};\r\n#line 4 \"datastructure/algebraic/operator_monoid/RangechmaxRangeMax.cpp\"\
    \n\r\ntemplate<typename T>\r\nstruct RangechmaxRangeMax{\r\n  using Monoid = MaxMonoid<T>;\r\
    \n  using OperatorMonoid = MaxMonoid<T>;\r\n\r\n  static void act(Monoid &m, const\
    \ OperatorMonoid &f){\r\n    m += f;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include \"../monoid/MaxMonoid.cpp\"\r\n\r\ntemplate<typename\
    \ T>\r\nstruct RangechmaxRangeMax{\r\n  using Monoid = MaxMonoid<T>;\r\n  using\
    \ OperatorMonoid = MaxMonoid<T>;\r\n\r\n  static void act(Monoid &m, const OperatorMonoid\
    \ &f){\r\n    m += f;\r\n  }\r\n};\r\n"
  dependsOn:
  - datastructure/algebraic/monoid/MaxMonoid.cpp
  isVerificationFile: false
  path: datastructure/algebraic/operator_monoid/RangechmaxRangeMax.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/operator_monoid/RangechmaxRangeMax.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/operator_monoid/RangechmaxRangeMax.cpp
- /library/datastructure/algebraic/operator_monoid/RangechmaxRangeMax.cpp.html
title: datastructure/algebraic/operator_monoid/RangechmaxRangeMax.cpp
---
