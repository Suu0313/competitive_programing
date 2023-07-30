---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: extended gcd ax + by = gcd(a, b)
    links: []
  bundledCode: "#line 2 \"math/extgcd.cpp\"\n\r\n/**\r\n* @brief extended gcd ax +\
    \ by = gcd(a, b)\r\n*/\r\ntemplate<typename T>\r\nT extgcd(T a, T b, T &x, T &y)\
    \ {\r\n  if (b == 0) {\r\n      x = 1;\r\n      y = 0;\r\n      return a;\r\n\
    \  }\r\n  T d = extgcd(b, a%b, y, x);\r\n  y -= a/b * x;\r\n  return d;\r\n}\r\
    \n"
  code: "#pragma once\r\n\r\n/**\r\n* @brief extended gcd ax + by = gcd(a, b)\r\n\
    */\r\ntemplate<typename T>\r\nT extgcd(T a, T b, T &x, T &y) {\r\n  if (b == 0)\
    \ {\r\n      x = 1;\r\n      y = 0;\r\n      return a;\r\n  }\r\n  T d = extgcd(b,\
    \ a%b, y, x);\r\n  y -= a/b * x;\r\n  return d;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/extgcd.cpp
  requiredBy: []
  timestamp: '2023-02-24 14:16:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/extgcd.cpp
layout: document
redirect_from:
- /library/math/extgcd.cpp
- /library/math/extgcd.cpp.html
title: extended gcd ax + by = gcd(a, b)
---
