---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: sum[0,n) floor((ai+b)/m), O(log min{n, m, a})
    links: []
  bundledCode: "#line 2 \"math/floor_sum.cpp\"\n\r\n/**\r\n* @brief sum[0,n) floor((ai+b)/m),\
    \ O(log min{n, m, a})\r\n*/\r\ntemplate<typename T>\r\nT floor_sum(T n, T m, T\
    \ a, T b){\r\n  T res = 0;\r\n  if(a < 0){\r\n    T a2 = a % m;\r\n    if(a2 <\
    \ 0) a2 += m;\r\n    res -= n * (n-1)/2 * ((a2 - a)/m);\r\n    a = a2;\r\n  }\r\
    \n  if(b < 0){\r\n    T b2 = b % m;\r\n    if(b2 < 0) b2 += m;\r\n    res -= n\
    \ * ((b2 - b)/m);\r\n    b = b2;\r\n  }\r\n\r\n  while(true){\r\n    if (a >=\
    \ m) {\r\n      res += (n - 1) * n / 2 * (a / m);\r\n      a %= m;\r\n    }\r\n\
    \    if (b >= m) {\r\n      res += n * (b / m);\r\n      b %= m;\r\n    }\r\n\r\
    \n    T y = a * n + b;\r\n    if(y < m) break;\r\n    n = y / m; b = y % m;\r\n\
    \    swap(m, a);\r\n  }\r\n\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n\r\n/**\r\n* @brief sum[0,n) floor((ai+b)/m), O(log min{n,\
    \ m, a})\r\n*/\r\ntemplate<typename T>\r\nT floor_sum(T n, T m, T a, T b){\r\n\
    \  T res = 0;\r\n  if(a < 0){\r\n    T a2 = a % m;\r\n    if(a2 < 0) a2 += m;\r\
    \n    res -= n * (n-1)/2 * ((a2 - a)/m);\r\n    a = a2;\r\n  }\r\n  if(b < 0){\r\
    \n    T b2 = b % m;\r\n    if(b2 < 0) b2 += m;\r\n    res -= n * ((b2 - b)/m);\r\
    \n    b = b2;\r\n  }\r\n\r\n  while(true){\r\n    if (a >= m) {\r\n      res +=\
    \ (n - 1) * n / 2 * (a / m);\r\n      a %= m;\r\n    }\r\n    if (b >= m) {\r\n\
    \      res += n * (b / m);\r\n      b %= m;\r\n    }\r\n\r\n    T y = a * n +\
    \ b;\r\n    if(y < m) break;\r\n    n = y / m; b = y % m;\r\n    swap(m, a);\r\
    \n  }\r\n\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/floor_sum.cpp
  requiredBy: []
  timestamp: '2023-02-24 14:27:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/floor_sum.cpp
layout: document
redirect_from:
- /library/math/floor_sum.cpp
- /library/math/floor_sum.cpp.html
title: sum[0,n) floor((ai+b)/m), O(log min{n, m, a})
---
