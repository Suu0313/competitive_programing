---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/algebraic/monoid/MaxSubsumMonoid.cpp\"\n\r\
    \ntemplate<typename T>\r\nstruct MaxSubsumMonoid{\r\n  T pre = 0, suf = 0, mx\
    \ = 0, whole = 0;\r\n  int len = 0;\r\n\r\n  MaxSubsumMonoid() = default;\r\n\
    \  MaxSubsumMonoid(const MaxSubsumMonoid&) = default;\r\n  MaxSubsumMonoid(MaxSubsumMonoid&&)\
    \ = default;\r\n\r\n  MaxSubsumMonoid(const T &x): pre(x), suf(x), mx(x), whole(x),\
    \ len(1) {}\r\n  MaxSubsumMonoid(const T &x, int n):\r\n    pre(x * n), suf(x\
    \ * n), mx(x * n), whole(x * n), len(n) {\r\n    if(x < 0) pre = suf = mx = x;\r\
    \n  }\r\n\r\n  MaxSubsumMonoid &operator=(const MaxSubsumMonoid&) = default;\r\
    \n  MaxSubsumMonoid &operator=(MaxSubsumMonoid&&) = default;\r\n\r\n  MaxSubsumMonoid\
    \ &operator+=(const MaxSubsumMonoid &m){\r\n    if(m.len == 0) return (*this);\r\
    \n    if(len == 0) return (*this) = m;\r\n    mx = max({mx, suf + m.pre, m.mx});\r\
    \n    pre = max(pre, whole + m.pre);\r\n    suf = max(suf + m.whole, m.suf);\r\
    \n    whole += m.whole;\r\n    len += m.len;\r\n    return (*this);\r\n  }\r\n\
    \  MaxSubsumMonoid operator+(const MaxSubsumMonoid &m) const {\r\n    return MaxSubsumMonoid(*this)\
    \ += m;\r\n  }\r\n\r\n  bool operator==(const MaxSubsumMonoid &m) const {\r\n\
    \    if(len == 0 && m.len == 0) return true;\r\n    return (\r\n      len == m.len\
    \ && pre == m.pre && suf == m.suf\r\n      && mx == m.mx && whole == m.whole\r\
    \n    );\r\n  }\r\n  bool operator!=(const MaxSubsumMonoid &m) const { return\
    \ !((*this) == m); }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct MaxSubsumMonoid{\r\n \
    \ T pre = 0, suf = 0, mx = 0, whole = 0;\r\n  int len = 0;\r\n\r\n  MaxSubsumMonoid()\
    \ = default;\r\n  MaxSubsumMonoid(const MaxSubsumMonoid&) = default;\r\n  MaxSubsumMonoid(MaxSubsumMonoid&&)\
    \ = default;\r\n\r\n  MaxSubsumMonoid(const T &x): pre(x), suf(x), mx(x), whole(x),\
    \ len(1) {}\r\n  MaxSubsumMonoid(const T &x, int n):\r\n    pre(x * n), suf(x\
    \ * n), mx(x * n), whole(x * n), len(n) {\r\n    if(x < 0) pre = suf = mx = x;\r\
    \n  }\r\n\r\n  MaxSubsumMonoid &operator=(const MaxSubsumMonoid&) = default;\r\
    \n  MaxSubsumMonoid &operator=(MaxSubsumMonoid&&) = default;\r\n\r\n  MaxSubsumMonoid\
    \ &operator+=(const MaxSubsumMonoid &m){\r\n    if(m.len == 0) return (*this);\r\
    \n    if(len == 0) return (*this) = m;\r\n    mx = max({mx, suf + m.pre, m.mx});\r\
    \n    pre = max(pre, whole + m.pre);\r\n    suf = max(suf + m.whole, m.suf);\r\
    \n    whole += m.whole;\r\n    len += m.len;\r\n    return (*this);\r\n  }\r\n\
    \  MaxSubsumMonoid operator+(const MaxSubsumMonoid &m) const {\r\n    return MaxSubsumMonoid(*this)\
    \ += m;\r\n  }\r\n\r\n  bool operator==(const MaxSubsumMonoid &m) const {\r\n\
    \    if(len == 0 && m.len == 0) return true;\r\n    return (\r\n      len == m.len\
    \ && pre == m.pre && suf == m.suf\r\n      && mx == m.mx && whole == m.whole\r\
    \n    );\r\n  }\r\n  bool operator!=(const MaxSubsumMonoid &m) const { return\
    \ !((*this) == m); }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/algebraic/monoid/MaxSubsumMonoid.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/algebraic/monoid/MaxSubsumMonoid.cpp
layout: document
redirect_from:
- /library/datastructure/algebraic/monoid/MaxSubsumMonoid.cpp
- /library/datastructure/algebraic/monoid/MaxSubsumMonoid.cpp.html
title: datastructure/algebraic/monoid/MaxSubsumMonoid.cpp
---
