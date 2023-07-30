---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: template/template.cpp
    title: template/template.cpp
  - icon: ':warning:'
    path: template/template_integers.cpp
    title: template/template_integers.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/integer/ceil.cpp\"\n\r\ntemplate<class T> constexpr\
    \ T ceil(T x, T y) {\r\n  if(y < 0) x = -x, y = -y;\r\n  if(x >= 0) return (x\
    \ + y - 1) / y;\r\n  return x / y;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<class T> constexpr T ceil(T x, T y) {\r\n  if(y\
    \ < 0) x = -x, y = -y;\r\n  if(x >= 0) return (x + y - 1) / y;\r\n  return x /\
    \ y;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/integer/ceil.cpp
  requiredBy:
  - template/template_integers.cpp
  - template/template.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/integer/ceil.cpp
layout: document
redirect_from:
- /library/math/integer/ceil.cpp
- /library/math/integer/ceil.cpp.html
title: math/integer/ceil.cpp
---
