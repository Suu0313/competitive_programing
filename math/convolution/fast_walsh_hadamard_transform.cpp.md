---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/convolution/bitwise_xor_convolution.cpp
    title: math/convolution/bitwise_xor_convolution.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/convolution/fast_walsh_hadamard_transform.cpp\"\n\r\
    \ntemplate<typename T>\r\nvector<T> fast_walsh_hadamard_transform(vector<T> f,\
    \ bool inv = false){\r\n  int n = int(f.size());\r\n  for(int i = 1; i < n; i\
    \ <<= 1){\r\n    for(int j = 0; j < n; ++j){\r\n      if((i&j) == 0){\r\n    \
    \    T x = f[j], y = f[j|i];\r\n        f[j] = x + y; f[j|i] = x - y;\r\n    \
    \  }\r\n    }\r\n  }\r\n  if(inv){\r\n    T in = T(1)/n;\r\n    for(auto&x : f)\
    \ x *= in;\r\n  }\r\n  return f;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nvector<T> fast_walsh_hadamard_transform(vector<T>\
    \ f, bool inv = false){\r\n  int n = int(f.size());\r\n  for(int i = 1; i < n;\
    \ i <<= 1){\r\n    for(int j = 0; j < n; ++j){\r\n      if((i&j) == 0){\r\n  \
    \      T x = f[j], y = f[j|i];\r\n        f[j] = x + y; f[j|i] = x - y;\r\n  \
    \    }\r\n    }\r\n  }\r\n  if(inv){\r\n    T in = T(1)/n;\r\n    for(auto&x :\
    \ f) x *= in;\r\n  }\r\n  return f;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/convolution/fast_walsh_hadamard_transform.cpp
  requiredBy:
  - math/convolution/bitwise_xor_convolution.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/convolution/fast_walsh_hadamard_transform.cpp
layout: document
redirect_from:
- /library/math/convolution/fast_walsh_hadamard_transform.cpp
- /library/math/convolution/fast_walsh_hadamard_transform.cpp.html
title: math/convolution/fast_walsh_hadamard_transform.cpp
---
