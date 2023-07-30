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
  bundledCode: "#line 2 \"math/prime/enumerate_primes.cpp\"\n\r\nvector<int> enumerate_primes(int\
    \ n){\r\n  vector<bool> table(n + 1, 1);\r\n  vector<int> ps;\r\n  int i = 2;\r\
    \n  for(; i * i <= n; ++i){\r\n    if(!table[i]) continue;\r\n    ps.push_back(i);\r\
    \n    for(int j = i * i; j <= n; j += i) table[j] = 0;\r\n  }\r\n\r\n  for(; i\
    \ <= n; ++i) if(table[i]) ps.push_back(i);\r\n\r\n  return ps;\r\n}\r\n"
  code: "#pragma once\r\n\r\nvector<int> enumerate_primes(int n){\r\n  vector<bool>\
    \ table(n + 1, 1);\r\n  vector<int> ps;\r\n  int i = 2;\r\n  for(; i * i <= n;\
    \ ++i){\r\n    if(!table[i]) continue;\r\n    ps.push_back(i);\r\n    for(int\
    \ j = i * i; j <= n; j += i) table[j] = 0;\r\n  }\r\n\r\n  for(; i <= n; ++i)\
    \ if(table[i]) ps.push_back(i);\r\n\r\n  return ps;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime/enumerate_primes.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime/enumerate_primes.cpp
layout: document
redirect_from:
- /library/math/prime/enumerate_primes.cpp
- /library/math/prime/enumerate_primes.cpp.html
title: math/prime/enumerate_primes.cpp
---
