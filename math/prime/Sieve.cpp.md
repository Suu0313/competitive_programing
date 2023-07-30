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
  bundledCode: "#line 2 \"math/prime/Sieve.cpp\"\n\r\nstruct Sieve{\r\n  int n;\r\n\
    \  vector<int> min_factor;\r\n\r\n  Sieve(int n_):n(n_+1), min_factor(n/2){\r\n\
    \    int sn = sqrt(n)+1, ni = n/2, sni = sn/2;\r\n    for(int i = 0; i < ni; ++i)\
    \ min_factor[i] = 2*i + 1;\r\n\r\n    for(int i = 1; i < sni; ++i){\r\n      if(min_factor[i]\
    \ < 2*i+1) continue;\r\n      for(int j = 2*i*(i+1); j < ni; j += 2*i+1){\r\n\
    \        if(min_factor[j] > 2*i + 1) min_factor[j] = 2*i + 1;\r\n      }\r\n \
    \   }\r\n  }\r\n\r\n  map<int,int> factor(int a) const {\r\n    map<int,int> res;\r\
    \n    while(~a&1 && a > 1){ ++res[2]; a >>= 1; }\r\n    while(a > 1){\r\n    \
    \  res[min_factor[a>>1]]++;\r\n      a /= min_factor[a>>1];\r\n    }\r\n    return\
    \ res;\r\n  }\r\n\r\n  vector<int> vfactor(int a) const {\r\n    vector<int> ps;\r\
    \n    while(~a&1 && a > 1){ ps.push_back(2); a >>= 1; }\r\n    while(a > 1){\r\
    \n      ps.push_back(min_factor[a>>1]);\r\n      a /= min_factor[a>>1];\r\n  \
    \  }\r\n    return ps;\r\n  }\r\n\r\n  bool is_prime(int p) const {\r\n    if(p<=1)\
    \ return false;\r\n    if(p==2) return true;\r\n    return min_factor[p>>1] ==\
    \ p;\r\n  }\r\n\r\n  vector<int> prime_table() const {\r\n    vector<int> res;\r\
    \n    for(int i=2; i < n ; i++){\r\n      if(is_prime(i)) res.push_back(i);\r\n\
    \    }\r\n    return res;\r\n  }\r\n\r\n  vector<int> divisors(int a) const {\r\
    \n    if(a <= 0) return {};\r\n    vector<int> res(1, 1);\r\n    for(const auto[p,\
    \ c] : factor(a)){\r\n      int m = int(res.size());\r\n      res.resize(m * (c\
    \ + 1));\r\n      for(int i = 0; i < m * c; ++i){\r\n        res[i + m] = res[i]\
    \ * p;\r\n      }\r\n    }\r\n    return res;\r\n  }\r\n\r\n  int cnt_divisors(int\
    \ a) const {\r\n    if(a <= 0) return 0;\r\n    int res = 1;\r\n    for(const\
    \ auto[p, c] : factor(a)) res *= c + 1;\r\n    return res;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\nstruct Sieve{\r\n  int n;\r\n  vector<int> min_factor;\r\
    \n\r\n  Sieve(int n_):n(n_+1), min_factor(n/2){\r\n    int sn = sqrt(n)+1, ni\
    \ = n/2, sni = sn/2;\r\n    for(int i = 0; i < ni; ++i) min_factor[i] = 2*i +\
    \ 1;\r\n\r\n    for(int i = 1; i < sni; ++i){\r\n      if(min_factor[i] < 2*i+1)\
    \ continue;\r\n      for(int j = 2*i*(i+1); j < ni; j += 2*i+1){\r\n        if(min_factor[j]\
    \ > 2*i + 1) min_factor[j] = 2*i + 1;\r\n      }\r\n    }\r\n  }\r\n\r\n  map<int,int>\
    \ factor(int a) const {\r\n    map<int,int> res;\r\n    while(~a&1 && a > 1){\
    \ ++res[2]; a >>= 1; }\r\n    while(a > 1){\r\n      res[min_factor[a>>1]]++;\r\
    \n      a /= min_factor[a>>1];\r\n    }\r\n    return res;\r\n  }\r\n\r\n  vector<int>\
    \ vfactor(int a) const {\r\n    vector<int> ps;\r\n    while(~a&1 && a > 1){ ps.push_back(2);\
    \ a >>= 1; }\r\n    while(a > 1){\r\n      ps.push_back(min_factor[a>>1]);\r\n\
    \      a /= min_factor[a>>1];\r\n    }\r\n    return ps;\r\n  }\r\n\r\n  bool\
    \ is_prime(int p) const {\r\n    if(p<=1) return false;\r\n    if(p==2) return\
    \ true;\r\n    return min_factor[p>>1] == p;\r\n  }\r\n\r\n  vector<int> prime_table()\
    \ const {\r\n    vector<int> res;\r\n    for(int i=2; i < n ; i++){\r\n      if(is_prime(i))\
    \ res.push_back(i);\r\n    }\r\n    return res;\r\n  }\r\n\r\n  vector<int> divisors(int\
    \ a) const {\r\n    if(a <= 0) return {};\r\n    vector<int> res(1, 1);\r\n  \
    \  for(const auto[p, c] : factor(a)){\r\n      int m = int(res.size());\r\n  \
    \    res.resize(m * (c + 1));\r\n      for(int i = 0; i < m * c; ++i){\r\n   \
    \     res[i + m] = res[i] * p;\r\n      }\r\n    }\r\n    return res;\r\n  }\r\
    \n\r\n  int cnt_divisors(int a) const {\r\n    if(a <= 0) return 0;\r\n    int\
    \ res = 1;\r\n    for(const auto[p, c] : factor(a)) res *= c + 1;\r\n    return\
    \ res;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime/Sieve.cpp
  requiredBy: []
  timestamp: '2023-03-29 23:06:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime/Sieve.cpp
layout: document
redirect_from:
- /library/math/prime/Sieve.cpp
- /library/math/prime/Sieve.cpp.html
title: math/prime/Sieve.cpp
---
