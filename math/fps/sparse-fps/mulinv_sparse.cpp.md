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
  bundledCode: "#line 2 \"math/fps/sparse-fps/mulinv_sparse.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nvector<T> mulinv_sparse(vector<T> f, vector<pair<int, T>> g, int d){\r\
    \n  assert(!g.empty());\r\n  auto[p, c] = g[0];\r\n  assert(p == 0 && c != T(0));\r\
    \n  T c_inv = c.inverse();\r\n\r\n  g.erase(begin(g));\r\n\r\n  f.resize(d);\r\
    \n  f[0] *= c_inv;\r\n\r\n  for(int i = 1; i < d; ++i){\r\n    for(const auto&[j,\
    \ x] : g){\r\n      if(j > i) break;\r\n      f[i] -= x * f[i - j];\r\n    }\r\
    \n    f[i] *= c_inv;\r\n  }\r\n  return f;\r\n}\r\n\r\ntemplate<typename T>\r\n\
    vector<T> mulinv_sparse(const vector<T> &f, const vector<T> &g, int n){\r\n  vector<pair<int,\
    \ T>> xs;\r\n  for(int i = 0, m = int(g.size()); i < m; ++i){\r\n    if(g[i] !=\
    \ T(0)) xs.emplace_back(i, g[i]);\r\n  }\r\n  return mulinv_sparse(f, xs, n);\r\
    \n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nvector<T> mulinv_sparse(vector<T>\
    \ f, vector<pair<int, T>> g, int d){\r\n  assert(!g.empty());\r\n  auto[p, c]\
    \ = g[0];\r\n  assert(p == 0 && c != T(0));\r\n  T c_inv = c.inverse();\r\n\r\n\
    \  g.erase(begin(g));\r\n\r\n  f.resize(d);\r\n  f[0] *= c_inv;\r\n\r\n  for(int\
    \ i = 1; i < d; ++i){\r\n    for(const auto&[j, x] : g){\r\n      if(j > i) break;\r\
    \n      f[i] -= x * f[i - j];\r\n    }\r\n    f[i] *= c_inv;\r\n  }\r\n  return\
    \ f;\r\n}\r\n\r\ntemplate<typename T>\r\nvector<T> mulinv_sparse(const vector<T>\
    \ &f, const vector<T> &g, int n){\r\n  vector<pair<int, T>> xs;\r\n  for(int i\
    \ = 0, m = int(g.size()); i < m; ++i){\r\n    if(g[i] != T(0)) xs.emplace_back(i,\
    \ g[i]);\r\n  }\r\n  return mulinv_sparse(f, xs, n);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/fps/sparse-fps/mulinv_sparse.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fps/sparse-fps/mulinv_sparse.cpp
layout: document
redirect_from:
- /library/math/fps/sparse-fps/mulinv_sparse.cpp
- /library/math/fps/sparse-fps/mulinv_sparse.cpp.html
title: math/fps/sparse-fps/mulinv_sparse.cpp
---
