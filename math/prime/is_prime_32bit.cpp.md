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
  bundledCode: "#line 2 \"math/prime/is_prime_32bit.cpp\"\n\r\nconstexpr bool is_prime_32bit(int\
    \ n){\r\n  if(n <= 1) return false;\r\n  if(n == 2 || n == 7 || n == 61) return\
    \ true;\r\n  if(~n & 1) return false;\r\n  long long d = n-1;\r\n  d >>= __builtin_ctzll(d);\r\
    \n  for(long long a : {2, 7, 61}){\r\n    long long t = d, y = 1;\r\n    {\r\n\
    \      long long x = a%n, k = t, m = n;\r\n      while(k){\r\n        if(k & 1)\
    \ y = y * x % m;\r\n        x = x * x % m; k >>= 1;\r\n      }\r\n    }\r\n  \
    \  while (t != n-1 && y != 1 && y != n-1) {\r\n        y = y * y % n; \r\n   \
    \     t <<= 1;\r\n    }\r\n    if (y != n-1 && ~t & 1) return false;\r\n  }\r\n\
    \  return true;\r\n}\r\n"
  code: "#pragma once\r\n\r\nconstexpr bool is_prime_32bit(int n){\r\n  if(n <= 1)\
    \ return false;\r\n  if(n == 2 || n == 7 || n == 61) return true;\r\n  if(~n &\
    \ 1) return false;\r\n  long long d = n-1;\r\n  d >>= __builtin_ctzll(d);\r\n\
    \  for(long long a : {2, 7, 61}){\r\n    long long t = d, y = 1;\r\n    {\r\n\
    \      long long x = a%n, k = t, m = n;\r\n      while(k){\r\n        if(k & 1)\
    \ y = y * x % m;\r\n        x = x * x % m; k >>= 1;\r\n      }\r\n    }\r\n  \
    \  while (t != n-1 && y != 1 && y != n-1) {\r\n        y = y * y % n; \r\n   \
    \     t <<= 1;\r\n    }\r\n    if (y != n-1 && ~t & 1) return false;\r\n  }\r\n\
    \  return true;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime/is_prime_32bit.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime/is_prime_32bit.cpp
layout: document
redirect_from:
- /library/math/prime/is_prime_32bit.cpp
- /library/math/prime/is_prime_32bit.cpp.html
title: math/prime/is_prime_32bit.cpp
---
