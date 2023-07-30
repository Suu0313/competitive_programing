---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/prime/is_prime_64bit.cpp
    title: math/prime/is_prime_64bit.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/prime/fast_prime_factor.cpp\"\n\r\n#line 2 \"math/prime/is_prime_64bit.cpp\"\
    \n\r\nconstexpr bool is_prime_64bit(long long n){\r\n  if(n <= 1) return false;\r\
    \n  constexpr long long witnesses[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,\
    \ 37};\r\n  for(long long a : witnesses) if(n == a) return true;\r\n  if(~n &\
    \ 1) return false;\r\n  long long d = n-1;\r\n  d >>= __builtin_ctzll(d);\r\n\
    \  for(long long a : witnesses){\r\n    long long t = d, y = 1;\r\n    {\r\n \
    \     long long x = a%n, k = t, m = n;\r\n      while(k){\r\n        if(k & 1)\
    \ y = (__int128_t)y * x % m;\r\n        x = (__int128_t)x * x % m; k >>= 1;\r\n\
    \      }\r\n    }\r\n    while (t != n-1 && y != 1 && y != n-1){\r\n        y\
    \ = (__int128_t)y * y % n; \r\n        t <<= 1;\r\n    }\r\n    if (y != n-1 &&\
    \ ~t & 1) return false;\r\n  }\r\n  return true;\r\n}\r\n#line 4 \"math/prime/fast_prime_factor.cpp\"\
    \n\r\nint64_t pollard_pho(int64_t n){\r\n  if(~n & 1) return 2;\r\n  if(is_prime_64bit(n))\
    \ return n;\r\n  for(int c = 1; ; ++c){\r\n    int64_t x = 2, y = 2, d = 1;\r\n\
    \    for( ; d == 1; d = gcd((y - x) >= 0 ? (y - x) : (y - x + n), n)){\r\n   \
    \   x = (__int128_t(x) * x + c) % n;\r\n      y = (__int128_t(y) * y + c) % n;\r\
    \n      y = (__int128_t(y) * y + c) % n;\r\n    }\r\n\r\n    if(d < n) return\
    \ d;\r\n  }\r\n  return -1;\r\n}\r\n\r\nvector<int64_t> fast_prime_factor(int64_t\
    \ n){\r\n  if(n <= 1) return {};\r\n  if(is_prime(n)) return {n};\r\n\r\n  int64_t\
    \ m = pollard_pho(n);\r\n  vector<int64_t> res = fast_prime_factor(m);\r\n  auto\
    \ r = fast_prime_factor(n / m);\r\n  res.insert(end(res), begin(r), end(r));\r\
    \n  sort(begin(res), end(res));\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n\r\n#include \"./is_prime_64bit.cpp\"\r\n\r\nint64_t pollard_pho(int64_t\
    \ n){\r\n  if(~n & 1) return 2;\r\n  if(is_prime_64bit(n)) return n;\r\n  for(int\
    \ c = 1; ; ++c){\r\n    int64_t x = 2, y = 2, d = 1;\r\n    for( ; d == 1; d =\
    \ gcd((y - x) >= 0 ? (y - x) : (y - x + n), n)){\r\n      x = (__int128_t(x) *\
    \ x + c) % n;\r\n      y = (__int128_t(y) * y + c) % n;\r\n      y = (__int128_t(y)\
    \ * y + c) % n;\r\n    }\r\n\r\n    if(d < n) return d;\r\n  }\r\n  return -1;\r\
    \n}\r\n\r\nvector<int64_t> fast_prime_factor(int64_t n){\r\n  if(n <= 1) return\
    \ {};\r\n  if(is_prime(n)) return {n};\r\n\r\n  int64_t m = pollard_pho(n);\r\n\
    \  vector<int64_t> res = fast_prime_factor(m);\r\n  auto r = fast_prime_factor(n\
    \ / m);\r\n  res.insert(end(res), begin(r), end(r));\r\n  sort(begin(res), end(res));\r\
    \n  return res;\r\n}\r\n"
  dependsOn:
  - math/prime/is_prime_64bit.cpp
  isVerificationFile: false
  path: math/prime/fast_prime_factor.cpp
  requiredBy: []
  timestamp: '2023-07-08 15:34:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime/fast_prime_factor.cpp
layout: document
redirect_from:
- /library/math/prime/fast_prime_factor.cpp
- /library/math/prime/fast_prime_factor.cpp.html
title: math/prime/fast_prime_factor.cpp
---
