---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/convolution/gcd_convolution.cpp
    title: math/convolution/gcd_convolution.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/convolution/multiple_fast_zeta_transform.cpp\"\n\r\n\
    template<typename T, class Plus = plus<T>>\r\nvector<T> multiple_fast_zeta_transform(vector<T>\
    \ f, const Plus &op = Plus{}){\r\n  int n = int(f.size());\r\n  vector<bool> sieve(n,\
    \ true);\r\n  for(int p = 2; p < n; ++p){\r\n    if(!sieve[p]) continue;\r\n \
    \   for(int k = (n-1) / p; k >= 1; --k){\r\n      sieve[k * p] = false;\r\n  \
    \    f[k] = op(f[k], f[k * p]);\r\n    }\r\n  }\r\n  return f;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T, class Plus = plus<T>>\r\nvector<T>\
    \ multiple_fast_zeta_transform(vector<T> f, const Plus &op = Plus{}){\r\n  int\
    \ n = int(f.size());\r\n  vector<bool> sieve(n, true);\r\n  for(int p = 2; p <\
    \ n; ++p){\r\n    if(!sieve[p]) continue;\r\n    for(int k = (n-1) / p; k >= 1;\
    \ --k){\r\n      sieve[k * p] = false;\r\n      f[k] = op(f[k], f[k * p]);\r\n\
    \    }\r\n  }\r\n  return f;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/convolution/multiple_fast_zeta_transform.cpp
  requiredBy:
  - math/convolution/gcd_convolution.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/convolution/multiple_fast_zeta_transform.cpp
layout: document
redirect_from:
- /library/math/convolution/multiple_fast_zeta_transform.cpp
- /library/math/convolution/multiple_fast_zeta_transform.cpp.html
title: math/convolution/multiple_fast_zeta_transform.cpp
---
