---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/convolution/subset_fast_mobius_transform.cpp
    title: math/convolution/subset_fast_mobius_transform.cpp
  - icon: ':warning:'
    path: math/convolution/subset_fast_zeta_transform.cpp
    title: math/convolution/subset_fast_zeta_transform.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/convolution/bitwise_or_convolution.cpp\"\n\r\n#line\
    \ 2 \"math/convolution/subset_fast_zeta_transform.cpp\"\n\r\ntemplate<typename\
    \ T, class Plus = plus<T>>\r\nvector<T> subset_fast_zeta_transform(vector<T> f,\
    \ const Plus &op = Plus{}){\r\n  int n = int(f.size());\r\n  for(int i = 1; i\
    \ < n; i <<= 1){\r\n    for(int j = 0; j < n; ++j){\r\n      if((i&j) == 0) f[j\
    \ | i] = op(f[j | i], f[j]);\r\n    }\r\n  }\r\n  return f;\r\n}\r\n#line 4 \"\
    math/convolution/bitwise_or_convolution.cpp\"\n\r\n#line 2 \"math/convolution/subset_fast_mobius_transform.cpp\"\
    \n\r\ntemplate<typename T, class Minus = minus<T>>\r\nvector<T> subset_fast_mobius_transform(vector<T>\
    \ f, const Minus &op = Minus{}){\r\n  int n = int(f.size());\r\n  for(int i =\
    \ 1; i < n; i <<= 1){\r\n    for(int j = 0; j < n; ++j){\r\n      if((i&j) ==\
    \ 0) f[j | i] = op(f[j | i], f[j]);\r\n    }\r\n  }\r\n  return f;\r\n}\r\n#line\
    \ 6 \"math/convolution/bitwise_or_convolution.cpp\"\n\r\ntemplate<typename T>\r\
    \nvector<T> bitwise_or_convolution(vector<T> f, vector<T> g){\r\n  f = subset_fast_zeta_transform(f);\r\
    \n  g = subset_fast_zeta_transform(g);\r\n  int n = min(f.size(), g.size());\r\
    \n  for(int i = 0; i < n; ++i) f[i] *= g[i];\r\n  return subset_fast_mobius_transform(f);\r\
    \n}\r\n"
  code: "#pragma once\r\n\r\n#include \"./subset_fast_zeta_transform.cpp\"\r\n\r\n\
    #include \"./subset_fast_mobius_transform.cpp\"\r\n\r\ntemplate<typename T>\r\n\
    vector<T> bitwise_or_convolution(vector<T> f, vector<T> g){\r\n  f = subset_fast_zeta_transform(f);\r\
    \n  g = subset_fast_zeta_transform(g);\r\n  int n = min(f.size(), g.size());\r\
    \n  for(int i = 0; i < n; ++i) f[i] *= g[i];\r\n  return subset_fast_mobius_transform(f);\r\
    \n}\r\n"
  dependsOn:
  - math/convolution/subset_fast_zeta_transform.cpp
  - math/convolution/subset_fast_mobius_transform.cpp
  isVerificationFile: false
  path: math/convolution/bitwise_or_convolution.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/convolution/bitwise_or_convolution.cpp
layout: document
redirect_from:
- /library/math/convolution/bitwise_or_convolution.cpp
- /library/math/convolution/bitwise_or_convolution.cpp.html
title: math/convolution/bitwise_or_convolution.cpp
---