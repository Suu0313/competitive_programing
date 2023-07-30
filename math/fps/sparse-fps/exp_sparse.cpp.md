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
  bundledCode: "#line 2 \"math/fps/sparse-fps/exp_sparse.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nvector<T> exp_sparse(vector<pair<int, T>> f, int n){\r\n  if(n == 0) return\
    \ {};\r\n\r\n  for(auto&[i, x] : f) x *= i--;\r\n\r\n  vector<T> g(n), inv(n,\
    \ 1); g[0] = 1;\r\n  int mod = T::get_mod();\r\n\r\n  for(int i = 0; i < n - 1;\
    \ ++i){\r\n    for(const auto&[j, x] : f){\r\n      if(j > i) break;\r\n     \
    \ g[i + 1] += x * g[i - j];\r\n    }\r\n    if(i != 0) inv[i + 1] = -inv[mod %\
    \ (i + 1)] * (mod / (i + 1));\r\n    g[i + 1] *= inv[i + 1];\r\n  }\r\n  return\
    \ g;\r\n}\r\n\r\ntemplate<typename T>\r\nvector<T> exp_sparse(const vector<T>\
    \ &f, int n = -1){\r\n  if(n == -1) n = int(f.size());\r\n  vector<pair<int, T>>\
    \ xs;\r\n  for(int i = 0, m = int(f.size()); i < m; ++i){\r\n    if(f[i] != T(0))\
    \ xs.emplace_back(i, f[i]);\r\n  }\r\n  return exp_sparse(xs, n);\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nvector<T> exp_sparse(vector<pair<int,\
    \ T>> f, int n){\r\n  if(n == 0) return {};\r\n\r\n  for(auto&[i, x] : f) x *=\
    \ i--;\r\n\r\n  vector<T> g(n), inv(n, 1); g[0] = 1;\r\n  int mod = T::get_mod();\r\
    \n\r\n  for(int i = 0; i < n - 1; ++i){\r\n    for(const auto&[j, x] : f){\r\n\
    \      if(j > i) break;\r\n      g[i + 1] += x * g[i - j];\r\n    }\r\n    if(i\
    \ != 0) inv[i + 1] = -inv[mod % (i + 1)] * (mod / (i + 1));\r\n    g[i + 1] *=\
    \ inv[i + 1];\r\n  }\r\n  return g;\r\n}\r\n\r\ntemplate<typename T>\r\nvector<T>\
    \ exp_sparse(const vector<T> &f, int n = -1){\r\n  if(n == -1) n = int(f.size());\r\
    \n  vector<pair<int, T>> xs;\r\n  for(int i = 0, m = int(f.size()); i < m; ++i){\r\
    \n    if(f[i] != T(0)) xs.emplace_back(i, f[i]);\r\n  }\r\n  return exp_sparse(xs,\
    \ n);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/fps/sparse-fps/exp_sparse.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fps/sparse-fps/exp_sparse.cpp
layout: document
redirect_from:
- /library/math/fps/sparse-fps/exp_sparse.cpp
- /library/math/fps/sparse-fps/exp_sparse.cpp.html
title: math/fps/sparse-fps/exp_sparse.cpp
---
