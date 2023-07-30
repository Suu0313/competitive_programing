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
  bundledCode: "#line 2 \"math/fps/sparse-fps/inv_sparse.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nvector<T> inv_sparse(vector<pair<int, T>> f, int n){\r\n  assert(!f.empty());\r\
    \n  auto[p, c] = f[0];\r\n  assert(p == 0 && c != T(0));\r\n\r\n  T c_inv = c.inverse();\r\
    \n  f.erase(begin(f));\r\n\r\n  vector<T> g(n); g[0] = c_inv;\r\n  for(int i =\
    \ 1; i < n; ++i){\r\n    for(const auto&[j, x] : f){\r\n      if(j > i) break;\r\
    \n      g[i] -= x * g[i - j];\r\n    }\r\n    g[i] *= c_inv;\r\n  }\r\n  return\
    \ g;\r\n}\r\n\r\ntemplate<typename T>\r\nvector<T> inv_sparse(const vector<T>\
    \ &f, int n = -1){\r\n  if(n == -1) n = int(f.size());\r\n  vector<pair<int, T>>\
    \ xs;\r\n  for(int i = 0, m = int(f.size()); i < m; ++i){\r\n    if(f[i] != T(0))\
    \ xs.emplace_back(i, f[i]);\r\n  }\r\n  return inv_sparse(xs, n);\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nvector<T> inv_sparse(vector<pair<int,\
    \ T>> f, int n){\r\n  assert(!f.empty());\r\n  auto[p, c] = f[0];\r\n  assert(p\
    \ == 0 && c != T(0));\r\n\r\n  T c_inv = c.inverse();\r\n  f.erase(begin(f));\r\
    \n\r\n  vector<T> g(n); g[0] = c_inv;\r\n  for(int i = 1; i < n; ++i){\r\n   \
    \ for(const auto&[j, x] : f){\r\n      if(j > i) break;\r\n      g[i] -= x * g[i\
    \ - j];\r\n    }\r\n    g[i] *= c_inv;\r\n  }\r\n  return g;\r\n}\r\n\r\ntemplate<typename\
    \ T>\r\nvector<T> inv_sparse(const vector<T> &f, int n = -1){\r\n  if(n == -1)\
    \ n = int(f.size());\r\n  vector<pair<int, T>> xs;\r\n  for(int i = 0, m = int(f.size());\
    \ i < m; ++i){\r\n    if(f[i] != T(0)) xs.emplace_back(i, f[i]);\r\n  }\r\n  return\
    \ inv_sparse(xs, n);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/fps/sparse-fps/inv_sparse.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fps/sparse-fps/inv_sparse.cpp
layout: document
redirect_from:
- /library/math/fps/sparse-fps/inv_sparse.cpp
- /library/math/fps/sparse-fps/inv_sparse.cpp.html
title: math/fps/sparse-fps/inv_sparse.cpp
---
