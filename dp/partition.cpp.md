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
  bundledCode: "#line 2 \"dp/partition.cpp\"\n\r\ntemplate<typename T, typename U>\r\
    \nT partition(U sum, const vector<U> &d, const vector<U> &u, const vector<U> &m){\r\
    \n\r\n  auto com = [&](U n, U r) -> T {\r\n    if(n < r) return T(0);\r\n    if\
    \ (n < 0 || r < 0) return T(0);\r\n    r = min(r, n - r);\r\n    T res = 1;\r\n\
    \    for(int i = 0; i < r; i++){\r\n      res *= n - i; res /= i + 1;\r\n    }\r\
    \n    return res;\r\n  };\r\n\r\n  int n = u.size();\r\n  auto msum = 0;\r\n \
    \ for(auto &e : m) msum += e;\r\n\r\n  auto dfs = [&](auto f, int ind, U sum)\
    \ -> T {\r\n    if(ind == n){\r\n      return com(sum+msum-1, msum-1);\r\n   \
    \ }\r\n\r\n    T res = 0;\r\n    auto nu = u[ind] - d[ind];\r\n    auto nsum =\
    \ sum - d[ind] * m[ind];\r\n\r\n    for(int i = 0; i <= m[ind]; i++){\r\n    \
    \  res += f(f, ind+1, nsum - (nu+1) * i) * com(m[ind], i) * (i%2==0 ? 1 : -1);\r\
    \n    }\r\n\r\n    return res;\r\n  };\r\n\r\n  return dfs(dfs, 0, sum);\r\n}\r\
    \n"
  code: "#pragma once\r\n\r\ntemplate<typename T, typename U>\r\nT partition(U sum,\
    \ const vector<U> &d, const vector<U> &u, const vector<U> &m){\r\n\r\n  auto com\
    \ = [&](U n, U r) -> T {\r\n    if(n < r) return T(0);\r\n    if (n < 0 || r <\
    \ 0) return T(0);\r\n    r = min(r, n - r);\r\n    T res = 1;\r\n    for(int i\
    \ = 0; i < r; i++){\r\n      res *= n - i; res /= i + 1;\r\n    }\r\n    return\
    \ res;\r\n  };\r\n\r\n  int n = u.size();\r\n  auto msum = 0;\r\n  for(auto &e\
    \ : m) msum += e;\r\n\r\n  auto dfs = [&](auto f, int ind, U sum) -> T {\r\n \
    \   if(ind == n){\r\n      return com(sum+msum-1, msum-1);\r\n    }\r\n\r\n  \
    \  T res = 0;\r\n    auto nu = u[ind] - d[ind];\r\n    auto nsum = sum - d[ind]\
    \ * m[ind];\r\n\r\n    for(int i = 0; i <= m[ind]; i++){\r\n      res += f(f,\
    \ ind+1, nsum - (nu+1) * i) * com(m[ind], i) * (i%2==0 ? 1 : -1);\r\n    }\r\n\
    \r\n    return res;\r\n  };\r\n\r\n  return dfs(dfs, 0, sum);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/partition.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/partition.cpp
layout: document
redirect_from:
- /library/dp/partition.cpp
- /library/dp/partition.cpp.html
title: dp/partition.cpp
---
