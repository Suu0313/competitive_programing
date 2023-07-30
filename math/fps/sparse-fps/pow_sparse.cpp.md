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
  bundledCode: "#line 2 \"math/fps/sparse-fps/pow_sparse.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nvector<T> pow_sparse(vector<pair<int, T>> f, int64_t k, int n){\r\n  if(f.empty()){\r\
    \n    vector<T> g(n);\r\n    if(k == 0 && n != 0) g[0] = 1;\r\n    return g;\r\
    \n  }\r\n  int d = f[0].first;\r\n  if(k < 0) assert(d == 0);\r\n  if(k > 0 &&\
    \ d >= (n + k - 1) / k) return vector<T>(n);\r\n  int offset = d * k; assert(offset\
    \ < n);\r\n  \r\n  T c = f[0].second, c_inv = c.inverse();\r\n  int mod = T::get_mod();\r\
    \n  for(auto&[i, x] : f) i -= d, x *= c_inv;\r\n  f.erase(begin(f));\r\n\r\n \
    \ vector<T> g(n - offset), inv(n - offset, 1); g[0] = 1;\r\n  for(int i = 0; i\
    \ < n - offset - 1; ++i){\r\n    for(auto&[j, x] : f){\r\n      if(j > i + 1)\
    \ break;\r\n      g[i + 1] += x * g[i - j + 1] * (T(k) * j - (i - j + 1));\r\n\
    \    }\r\n    if(i > 0) inv[i + 1] = -inv[mod%(i + 1)] * (mod/(i + 1));\r\n  \
    \  g[i + 1] *= inv[i + 1];\r\n  }\r\n\r\n  T cp = (k >= 0 ? c.pow(k) : c_inv.pow(-k));\r\
    \n  for(auto &e : g) e *= cp;\r\n  g.resize(n); rotate(begin(g), begin(g) + n\
    \ - offset, end(g));\r\n  return g;\r\n}\r\n\r\n\r\ntemplate<typename T>\r\nvector<T>\
    \ pow_sparse(const vector<T> &f, int64_t k, int n = -1){\r\n  if(n == -1) n =\
    \ int(f.size());\r\n  vector<pair<int, T>> xs;\r\n  for(int i = 0, m = int(f.size());\
    \ i < m; ++i){\r\n    if(f[i] != T(0)) xs.emplace_back(i, f[i]);\r\n  }\r\n  return\
    \ pow_sparse(xs, k, n);\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nvector<T> pow_sparse(vector<pair<int,\
    \ T>> f, int64_t k, int n){\r\n  if(f.empty()){\r\n    vector<T> g(n);\r\n   \
    \ if(k == 0 && n != 0) g[0] = 1;\r\n    return g;\r\n  }\r\n  int d = f[0].first;\r\
    \n  if(k < 0) assert(d == 0);\r\n  if(k > 0 && d >= (n + k - 1) / k) return vector<T>(n);\r\
    \n  int offset = d * k; assert(offset < n);\r\n  \r\n  T c = f[0].second, c_inv\
    \ = c.inverse();\r\n  int mod = T::get_mod();\r\n  for(auto&[i, x] : f) i -= d,\
    \ x *= c_inv;\r\n  f.erase(begin(f));\r\n\r\n  vector<T> g(n - offset), inv(n\
    \ - offset, 1); g[0] = 1;\r\n  for(int i = 0; i < n - offset - 1; ++i){\r\n  \
    \  for(auto&[j, x] : f){\r\n      if(j > i + 1) break;\r\n      g[i + 1] += x\
    \ * g[i - j + 1] * (T(k) * j - (i - j + 1));\r\n    }\r\n    if(i > 0) inv[i +\
    \ 1] = -inv[mod%(i + 1)] * (mod/(i + 1));\r\n    g[i + 1] *= inv[i + 1];\r\n \
    \ }\r\n\r\n  T cp = (k >= 0 ? c.pow(k) : c_inv.pow(-k));\r\n  for(auto &e : g)\
    \ e *= cp;\r\n  g.resize(n); rotate(begin(g), begin(g) + n - offset, end(g));\r\
    \n  return g;\r\n}\r\n\r\n\r\ntemplate<typename T>\r\nvector<T> pow_sparse(const\
    \ vector<T> &f, int64_t k, int n = -1){\r\n  if(n == -1) n = int(f.size());\r\n\
    \  vector<pair<int, T>> xs;\r\n  for(int i = 0, m = int(f.size()); i < m; ++i){\r\
    \n    if(f[i] != T(0)) xs.emplace_back(i, f[i]);\r\n  }\r\n  return pow_sparse(xs,\
    \ k, n);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/fps/sparse-fps/pow_sparse.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fps/sparse-fps/pow_sparse.cpp
layout: document
redirect_from:
- /library/math/fps/sparse-fps/pow_sparse.cpp
- /library/math/fps/sparse-fps/pow_sparse.cpp.html
title: math/fps/sparse-fps/pow_sparse.cpp
---
