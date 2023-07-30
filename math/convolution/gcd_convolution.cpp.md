---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/convolution/multiple_fast_mobius_transform.cpp
    title: math/convolution/multiple_fast_mobius_transform.cpp
  - icon: ':warning:'
    path: math/convolution/multiple_fast_zeta_transform.cpp
    title: math/convolution/multiple_fast_zeta_transform.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/convolution/gcd_convolution.cpp\"\n\r\n#line 2 \"math/convolution/multiple_fast_zeta_transform.cpp\"\
    \n\r\ntemplate<typename T, class Plus = plus<T>>\r\nvector<T> multiple_fast_zeta_transform(vector<T>\
    \ f, const Plus &op = Plus{}){\r\n  int n = int(f.size());\r\n  vector<bool> sieve(n,\
    \ true);\r\n  for(int p = 2; p < n; ++p){\r\n    if(!sieve[p]) continue;\r\n \
    \   for(int k = (n-1) / p; k >= 1; --k){\r\n      sieve[k * p] = false;\r\n  \
    \    f[k] = op(f[k], f[k * p]);\r\n    }\r\n  }\r\n  return f;\r\n}\r\n#line 4\
    \ \"math/convolution/gcd_convolution.cpp\"\n\r\n#line 2 \"math/convolution/multiple_fast_mobius_transform.cpp\"\
    \n\r\ntemplate<typename T, class Minus = minus<T>>\r\nvector<T> multiple_fast_mobius_transform(vector<T>\
    \ f, const Minus &op = Minus{}){\r\n  int n = int(f.size());\r\n  vector<bool>\
    \ sieve(n, true);\r\n  for(int p = 2; p < n; ++p){\r\n    if(!sieve[p]) continue;\r\
    \n    for(int k = 1; p * k < n; ++k){\r\n      sieve[p * k] = false;\r\n     \
    \ f[k] = op(f[k], f[p * k]);\r\n    }\r\n  }\r\n  return f;\r\n}\r\n#line 6 \"\
    math/convolution/gcd_convolution.cpp\"\n\r\ntemplate<typename T>\r\nvector<T>\
    \ gcd_convolution(vector<T> f, vector<T> g){\r\n  int n = int(max(f.size(), g.size()));\r\
    \n  f.resize(n, 0); g.resize(n, 0);\r\n  f = multiple_fast_zeta_transform(f);\r\
    \n  g = multiple_fast_zeta_transform(g);\r\n  for(int i = 0; i < n; ++i) f[i]\
    \ *= g[i];\r\n  return multiple_fast_mobius_transform(f);\r\n}\r\n"
  code: "#pragma once\r\n\r\n#include \"./multiple_fast_zeta_transform.cpp\"\r\n\r\
    \n#include \"./multiple_fast_mobius_transform.cpp\"\r\n\r\ntemplate<typename T>\r\
    \nvector<T> gcd_convolution(vector<T> f, vector<T> g){\r\n  int n = int(max(f.size(),\
    \ g.size()));\r\n  f.resize(n, 0); g.resize(n, 0);\r\n  f = multiple_fast_zeta_transform(f);\r\
    \n  g = multiple_fast_zeta_transform(g);\r\n  for(int i = 0; i < n; ++i) f[i]\
    \ *= g[i];\r\n  return multiple_fast_mobius_transform(f);\r\n}\r\n"
  dependsOn:
  - math/convolution/multiple_fast_zeta_transform.cpp
  - math/convolution/multiple_fast_mobius_transform.cpp
  isVerificationFile: false
  path: math/convolution/gcd_convolution.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/convolution/gcd_convolution.cpp
layout: document
redirect_from:
- /library/math/convolution/gcd_convolution.cpp
- /library/math/convolution/gcd_convolution.cpp.html
title: math/convolution/gcd_convolution.cpp
---
