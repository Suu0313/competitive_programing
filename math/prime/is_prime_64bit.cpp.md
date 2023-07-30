---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/prime/fast_prime_factor.cpp
    title: math/prime/fast_prime_factor.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/prime/is_prime_64bit.cpp\"\n\r\nconstexpr bool is_prime_64bit(long\
    \ long n){\r\n  if(n <= 1) return false;\r\n  constexpr long long witnesses[12]\
    \ = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};\r\n  for(long long a : witnesses)\
    \ if(n == a) return true;\r\n  if(~n & 1) return false;\r\n  long long d = n-1;\r\
    \n  d >>= __builtin_ctzll(d);\r\n  for(long long a : witnesses){\r\n    long long\
    \ t = d, y = 1;\r\n    {\r\n      long long x = a%n, k = t, m = n;\r\n      while(k){\r\
    \n        if(k & 1) y = (__int128_t)y * x % m;\r\n        x = (__int128_t)x *\
    \ x % m; k >>= 1;\r\n      }\r\n    }\r\n    while (t != n-1 && y != 1 && y !=\
    \ n-1){\r\n        y = (__int128_t)y * y % n; \r\n        t <<= 1;\r\n    }\r\n\
    \    if (y != n-1 && ~t & 1) return false;\r\n  }\r\n  return true;\r\n}\r\n"
  code: "#pragma once\r\n\r\nconstexpr bool is_prime_64bit(long long n){\r\n  if(n\
    \ <= 1) return false;\r\n  constexpr long long witnesses[12] = {2, 3, 5, 7, 11,\
    \ 13, 17, 19, 23, 29, 31, 37};\r\n  for(long long a : witnesses) if(n == a) return\
    \ true;\r\n  if(~n & 1) return false;\r\n  long long d = n-1;\r\n  d >>= __builtin_ctzll(d);\r\
    \n  for(long long a : witnesses){\r\n    long long t = d, y = 1;\r\n    {\r\n\
    \      long long x = a%n, k = t, m = n;\r\n      while(k){\r\n        if(k & 1)\
    \ y = (__int128_t)y * x % m;\r\n        x = (__int128_t)x * x % m; k >>= 1;\r\n\
    \      }\r\n    }\r\n    while (t != n-1 && y != 1 && y != n-1){\r\n        y\
    \ = (__int128_t)y * y % n; \r\n        t <<= 1;\r\n    }\r\n    if (y != n-1 &&\
    \ ~t & 1) return false;\r\n  }\r\n  return true;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime/is_prime_64bit.cpp
  requiredBy:
  - math/prime/fast_prime_factor.cpp
  timestamp: '2023-07-08 15:34:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime/is_prime_64bit.cpp
layout: document
redirect_from:
- /library/math/prime/is_prime_64bit.cpp
- /library/math/prime/is_prime_64bit.cpp.html
title: math/prime/is_prime_64bit.cpp
---
