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
  bundledCode: "#line 2 \"math/prime/is_prime.cpp\"\n\r\nbool is_prime(long long N){\r\
    \n  if(N <= 1) return false;\r\n  for(long long i = 2; i*i <= N; ++i){\r\n   \
    \ if(N%i == 0) return false;\r\n  }\r\n  return true;\r\n}\r\n"
  code: "#pragma once\r\n\r\nbool is_prime(long long N){\r\n  if(N <= 1) return false;\r\
    \n  for(long long i = 2; i*i <= N; ++i){\r\n    if(N%i == 0) return false;\r\n\
    \  }\r\n  return true;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime/is_prime.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime/is_prime.cpp
layout: document
redirect_from:
- /library/math/prime/is_prime.cpp
- /library/math/prime/is_prime.cpp.html
title: math/prime/is_prime.cpp
---
