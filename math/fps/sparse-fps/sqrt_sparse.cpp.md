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
  bundledCode: "#line 2 \"math/fps/sparse-fps/sqrt_sparse.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nvector<T> sqrt_sparse(vector<pair<int, T>> f, const function< T(T) > &get_sqrt,\
    \ int n){\r\n\r\n  if(f.empty()) return vector<T>(n);\r\n  int d = f[0].first,\
    \ offset = d >> 1;\r\n  if(d & 1) return {};\r\n\r\n  T c = f[0].second, c_inv\
    \ = c.inverse(), inv2 = T(2).inverse();\r\n  T sc = get_sqrt(c);\r\n  if(sc *\
    \ sc != c) return {};\r\n  for(auto&[i, x] : f) i -= d, x *= c_inv;\r\n  f.erase(begin(f));\r\
    \n\r\n  int mod = T::get_mod();\r\n  vector<T> g(n - offset), inv(n - offset,\
    \ 1); g[0] = 1;\r\n  for(int i = 0; i < n - offset - 1; ++i){\r\n    for(auto&[j,\
    \ x] : f){\r\n      if(j > i + 1) break;\r\n      g[i + 1] += x * g[i - j + 1]\
    \ * (inv2 * j - (i - j + 1));\r\n    }\r\n    if(i > 0) inv[i + 1] = -inv[mod%(i\
    \ + 1)] * (mod/(i + 1));\r\n    g[i + 1] *= inv[i + 1];\r\n  }\r\n  for(auto &e\
    \ : g) e *= sc;\r\n  g.resize(n); rotate(begin(g), begin(g) + n - offset, end(g));\r\
    \n  return g;\r\n}\r\n\r\ntemplate<typename T>\r\nvector<T> sqrt_sparse(const\
    \ vector<T> &f, const function< T(T) > &get_sqrt, int n = -1){\r\n  if(n == -1)\
    \ n = int(f.size());\r\n  vector<pair<int, T>> xs;\r\n  for(int i = 0, m = int(f.size());\
    \ i < m; ++i){\r\n    if(f[i] != T(0)) xs.emplace_back(i, f[i]);\r\n  }\r\n  return\
    \ sqrt_sparse(xs, get_sqrt, n);\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nvector<T> sqrt_sparse(vector<pair<int,\
    \ T>> f, const function< T(T) > &get_sqrt, int n){\r\n\r\n  if(f.empty()) return\
    \ vector<T>(n);\r\n  int d = f[0].first, offset = d >> 1;\r\n  if(d & 1) return\
    \ {};\r\n\r\n  T c = f[0].second, c_inv = c.inverse(), inv2 = T(2).inverse();\r\
    \n  T sc = get_sqrt(c);\r\n  if(sc * sc != c) return {};\r\n  for(auto&[i, x]\
    \ : f) i -= d, x *= c_inv;\r\n  f.erase(begin(f));\r\n\r\n  int mod = T::get_mod();\r\
    \n  vector<T> g(n - offset), inv(n - offset, 1); g[0] = 1;\r\n  for(int i = 0;\
    \ i < n - offset - 1; ++i){\r\n    for(auto&[j, x] : f){\r\n      if(j > i + 1)\
    \ break;\r\n      g[i + 1] += x * g[i - j + 1] * (inv2 * j - (i - j + 1));\r\n\
    \    }\r\n    if(i > 0) inv[i + 1] = -inv[mod%(i + 1)] * (mod/(i + 1));\r\n  \
    \  g[i + 1] *= inv[i + 1];\r\n  }\r\n  for(auto &e : g) e *= sc;\r\n  g.resize(n);\
    \ rotate(begin(g), begin(g) + n - offset, end(g));\r\n  return g;\r\n}\r\n\r\n\
    template<typename T>\r\nvector<T> sqrt_sparse(const vector<T> &f, const function<\
    \ T(T) > &get_sqrt, int n = -1){\r\n  if(n == -1) n = int(f.size());\r\n  vector<pair<int,\
    \ T>> xs;\r\n  for(int i = 0, m = int(f.size()); i < m; ++i){\r\n    if(f[i] !=\
    \ T(0)) xs.emplace_back(i, f[i]);\r\n  }\r\n  return sqrt_sparse(xs, get_sqrt,\
    \ n);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/fps/sparse-fps/sqrt_sparse.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fps/sparse-fps/sqrt_sparse.cpp
layout: document
redirect_from:
- /library/math/fps/sparse-fps/sqrt_sparse.cpp
- /library/math/fps/sparse-fps/sqrt_sparse.cpp.html
title: math/fps/sparse-fps/sqrt_sparse.cpp
---
