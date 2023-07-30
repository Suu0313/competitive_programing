---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/convolution/bitwise_and_convolution.cpp
    title: math/convolution/bitwise_and_convolution.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/convolution/superset_fast_zeta_transform.cpp\"\n\r\n\
    template<typename T, class Plus = plus<T>>\r\nvector<T> superset_fast_zeta_transform(vector<T>\
    \ f, const Plus &op = Plus{}){\r\n  int n = int(f.size());\r\n  for(int i = 1;\
    \ i < n; i <<= 1){\r\n    for(int j = 0; j < n; ++j){\r\n      if((i&j) == 0)\
    \ f[j] = op(f[j], f[j | i]);\r\n    }\r\n  }\r\n  return f;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T, class Plus = plus<T>>\r\nvector<T>\
    \ superset_fast_zeta_transform(vector<T> f, const Plus &op = Plus{}){\r\n  int\
    \ n = int(f.size());\r\n  for(int i = 1; i < n; i <<= 1){\r\n    for(int j = 0;\
    \ j < n; ++j){\r\n      if((i&j) == 0) f[j] = op(f[j], f[j | i]);\r\n    }\r\n\
    \  }\r\n  return f;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/convolution/superset_fast_zeta_transform.cpp
  requiredBy:
  - math/convolution/bitwise_and_convolution.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/convolution/superset_fast_zeta_transform.cpp
layout: document
redirect_from:
- /library/math/convolution/superset_fast_zeta_transform.cpp
- /library/math/convolution/superset_fast_zeta_transform.cpp.html
title: math/convolution/superset_fast_zeta_transform.cpp
---
