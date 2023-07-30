---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/convolution/lcm_convolution.cpp
    title: math/convolution/lcm_convolution.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/convolution/divisor_fast_mobius_transform.cpp\"\n\r\
    \ntemplate<typename T, class Minus = minus<T>>\r\nvector<T> divisor_fast_mobius_transform(vector<T>\
    \ f, const Minus &op = Minus{}){\r\n  int n = int(f.size());\r\n  vector<bool>\
    \ sieve(n, true);\r\n  for(int p = 2; p < n; ++p){\r\n    if(!sieve[p]) continue;\r\
    \n    for(int k = (n-1) / p; k >= 1; --k){\r\n      sieve[p * k] = false;\r\n\
    \      f[p * k] = op(f[p * k], f[k]);\r\n    }\r\n  }\r\n  return f;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T, class Minus = minus<T>>\r\nvector<T>\
    \ divisor_fast_mobius_transform(vector<T> f, const Minus &op = Minus{}){\r\n \
    \ int n = int(f.size());\r\n  vector<bool> sieve(n, true);\r\n  for(int p = 2;\
    \ p < n; ++p){\r\n    if(!sieve[p]) continue;\r\n    for(int k = (n-1) / p; k\
    \ >= 1; --k){\r\n      sieve[p * k] = false;\r\n      f[p * k] = op(f[p * k],\
    \ f[k]);\r\n    }\r\n  }\r\n  return f;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/convolution/divisor_fast_mobius_transform.cpp
  requiredBy:
  - math/convolution/lcm_convolution.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/convolution/divisor_fast_mobius_transform.cpp
layout: document
redirect_from:
- /library/math/convolution/divisor_fast_mobius_transform.cpp
- /library/math/convolution/divisor_fast_mobius_transform.cpp.html
title: math/convolution/divisor_fast_mobius_transform.cpp
---
