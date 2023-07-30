---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/convolution/divisor_fast_mobius_transform.cpp
    title: math/convolution/divisor_fast_mobius_transform.cpp
  - icon: ':warning:'
    path: math/convolution/divisor_fast_zeta_transform.cpp
    title: math/convolution/divisor_fast_zeta_transform.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/convolution/lcm_convolution.cpp\"\n\r\n#line 2 \"math/convolution/divisor_fast_zeta_transform.cpp\"\
    \n\r\ntemplate<typename T, class Plus = plus<T>>\r\nvector<T> divisor_fast_zeta_transform(vector<T>\
    \ f, const Plus &op = Plus{}){\r\n  int n = int(f.size());\r\n  vector<bool> sieve(n,\
    \ true);\r\n  for(int p = 2; p < n; ++p){\r\n    if(!sieve[p]) continue;\r\n \
    \   for(int k = 1; p * k < n; ++k){\r\n      sieve[k * p] = false;\r\n      f[k\
    \ * p] = op(f[k], f[k * p]);\r\n    }\r\n  }\r\n  return f;\r\n}\r\n#line 4 \"\
    math/convolution/lcm_convolution.cpp\"\n\r\n#line 2 \"math/convolution/divisor_fast_mobius_transform.cpp\"\
    \n\r\ntemplate<typename T, class Minus = minus<T>>\r\nvector<T> divisor_fast_mobius_transform(vector<T>\
    \ f, const Minus &op = Minus{}){\r\n  int n = int(f.size());\r\n  vector<bool>\
    \ sieve(n, true);\r\n  for(int p = 2; p < n; ++p){\r\n    if(!sieve[p]) continue;\r\
    \n    for(int k = (n-1) / p; k >= 1; --k){\r\n      sieve[p * k] = false;\r\n\
    \      f[p * k] = op(f[p * k], f[k]);\r\n    }\r\n  }\r\n  return f;\r\n}\r\n\
    #line 6 \"math/convolution/lcm_convolution.cpp\"\n\r\ntemplate<typename T>\r\n\
    vector<T> lcm_convolution(vector<T> f, vector<T> g){\r\n  int n = int(max(f.size(),\
    \ g.size()));\r\n  f.resize(n, 0); g.resize(n, 0);\r\n  f = divisor_fast_zeta_transform(f);\r\
    \n  g = divisor_fast_zeta_transform(g);\r\n  for(int i = 0; i < n; ++i) f[i] *=\
    \ g[i];\r\n  return divisor_fast_mobius_transform(f);\r\n}\r\n"
  code: "#pragma once\r\n\r\n#include \"./divisor_fast_zeta_transform.cpp\"\r\n\r\n\
    #include \"./divisor_fast_mobius_transform.cpp\"\r\n\r\ntemplate<typename T>\r\
    \nvector<T> lcm_convolution(vector<T> f, vector<T> g){\r\n  int n = int(max(f.size(),\
    \ g.size()));\r\n  f.resize(n, 0); g.resize(n, 0);\r\n  f = divisor_fast_zeta_transform(f);\r\
    \n  g = divisor_fast_zeta_transform(g);\r\n  for(int i = 0; i < n; ++i) f[i] *=\
    \ g[i];\r\n  return divisor_fast_mobius_transform(f);\r\n}\r\n"
  dependsOn:
  - math/convolution/divisor_fast_zeta_transform.cpp
  - math/convolution/divisor_fast_mobius_transform.cpp
  isVerificationFile: false
  path: math/convolution/lcm_convolution.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/convolution/lcm_convolution.cpp
layout: document
redirect_from:
- /library/math/convolution/lcm_convolution.cpp
- /library/math/convolution/lcm_convolution.cpp.html
title: math/convolution/lcm_convolution.cpp
---
