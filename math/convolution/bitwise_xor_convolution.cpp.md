---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/convolution/fast_walsh_hadamard_transform.cpp
    title: math/convolution/fast_walsh_hadamard_transform.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/convolution/bitwise_xor_convolution.cpp\"\n\r\n#line\
    \ 2 \"math/convolution/fast_walsh_hadamard_transform.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nvector<T> fast_walsh_hadamard_transform(vector<T> f, bool inv = false){\r\
    \n  int n = int(f.size());\r\n  for(int i = 1; i < n; i <<= 1){\r\n    for(int\
    \ j = 0; j < n; ++j){\r\n      if((i&j) == 0){\r\n        T x = f[j], y = f[j|i];\r\
    \n        f[j] = x + y; f[j|i] = x - y;\r\n      }\r\n    }\r\n  }\r\n  if(inv){\r\
    \n    T in = T(1)/n;\r\n    for(auto&x : f) x *= in;\r\n  }\r\n  return f;\r\n\
    }\r\n#line 4 \"math/convolution/bitwise_xor_convolution.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nvector<T> bitwise_xor_convolution(vector<T> f, vector<T> g){\r\n  f =\
    \ fast_walsh_hadamard_transform(f, false);\r\n  g = fast_walsh_hadamard_transform(g,\
    \ false);\r\n  int n = int(f.size());\r\n  for(int i = 0; i < n; ++i) f[i] *=\
    \ g[i];\r\n  return fast_walsh_hadamard_transform(f, true);\r\n}\r\n"
  code: "#pragma once\r\n\r\n#include \"./fast_walsh_hadamard_transform.cpp\"\r\n\r\
    \ntemplate<typename T>\r\nvector<T> bitwise_xor_convolution(vector<T> f, vector<T>\
    \ g){\r\n  f = fast_walsh_hadamard_transform(f, false);\r\n  g = fast_walsh_hadamard_transform(g,\
    \ false);\r\n  int n = int(f.size());\r\n  for(int i = 0; i < n; ++i) f[i] *=\
    \ g[i];\r\n  return fast_walsh_hadamard_transform(f, true);\r\n}\r\n"
  dependsOn:
  - math/convolution/fast_walsh_hadamard_transform.cpp
  isVerificationFile: false
  path: math/convolution/bitwise_xor_convolution.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/convolution/bitwise_xor_convolution.cpp
layout: document
redirect_from:
- /library/math/convolution/bitwise_xor_convolution.cpp
- /library/math/convolution/bitwise_xor_convolution.cpp.html
title: math/convolution/bitwise_xor_convolution.cpp
---
