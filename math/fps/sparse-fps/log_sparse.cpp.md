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
  bundledCode: "#line 2 \"math/fps/sparse-fps/log_sparse.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nvector<T> log_sparse(vector<pair<int, T>> f, int n){\r\n  if(n == 0) return\
    \ {};\r\n  assert(!f.empty());\r\n  auto[p, c] = f[0];\r\n  assert(p == 0 && c\
    \ == T(1));\r\n\r\n  f.erase(begin(f));\r\n\r\n  vector<T> g(n - 1), inv(n, 1);\r\
    \n  int mod = T::get_mod();\r\n\r\n  auto it = begin(f);\r\n\r\n  for(int i =\
    \ 0; i < n - 1; ++i){\r\n    while(it != end(f) && it->first < i + 1) ++it;\r\n\
    \    if(it != end(f) && it->first == i + 1){\r\n      g[i] = (it->second) * (i\
    \ + 1);\r\n    }\r\n    for(const auto&[j, x] : f){\r\n      if(j > i) break;\r\
    \n      g[i] -= x * g[i - j];\r\n    }\r\n  }\r\n\r\n  g.insert(begin(g), 0);\r\
    \n\r\n  for(int i = 2; i < n; ++i) g[i] *= (inv[i] = -inv[mod%i] * (mod/i));\r\
    \n\r\n  return g;\r\n}\r\n\r\n\r\ntemplate<typename T>\r\nvector<T> log_sparse(const\
    \ vector<T> &f, int n = -1){\r\n  if(n == -1) n = int(f.size());\r\n  vector<pair<int,\
    \ T>> xs;\r\n  for(int i = 0, m = int(f.size()); i < m; ++i){\r\n    if(f[i] !=\
    \ T(0)) xs.emplace_back(i, f[i]);\r\n  }\r\n  return log_sparse(xs, n);\r\n}\r\
    \n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nvector<T> log_sparse(vector<pair<int,\
    \ T>> f, int n){\r\n  if(n == 0) return {};\r\n  assert(!f.empty());\r\n  auto[p,\
    \ c] = f[0];\r\n  assert(p == 0 && c == T(1));\r\n\r\n  f.erase(begin(f));\r\n\
    \r\n  vector<T> g(n - 1), inv(n, 1);\r\n  int mod = T::get_mod();\r\n\r\n  auto\
    \ it = begin(f);\r\n\r\n  for(int i = 0; i < n - 1; ++i){\r\n    while(it != end(f)\
    \ && it->first < i + 1) ++it;\r\n    if(it != end(f) && it->first == i + 1){\r\
    \n      g[i] = (it->second) * (i + 1);\r\n    }\r\n    for(const auto&[j, x] :\
    \ f){\r\n      if(j > i) break;\r\n      g[i] -= x * g[i - j];\r\n    }\r\n  }\r\
    \n\r\n  g.insert(begin(g), 0);\r\n\r\n  for(int i = 2; i < n; ++i) g[i] *= (inv[i]\
    \ = -inv[mod%i] * (mod/i));\r\n\r\n  return g;\r\n}\r\n\r\n\r\ntemplate<typename\
    \ T>\r\nvector<T> log_sparse(const vector<T> &f, int n = -1){\r\n  if(n == -1)\
    \ n = int(f.size());\r\n  vector<pair<int, T>> xs;\r\n  for(int i = 0, m = int(f.size());\
    \ i < m; ++i){\r\n    if(f[i] != T(0)) xs.emplace_back(i, f[i]);\r\n  }\r\n  return\
    \ log_sparse(xs, n);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/fps/sparse-fps/log_sparse.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fps/sparse-fps/log_sparse.cpp
layout: document
redirect_from:
- /library/math/fps/sparse-fps/log_sparse.cpp
- /library/math/fps/sparse-fps/log_sparse.cpp.html
title: math/fps/sparse-fps/log_sparse.cpp
---
