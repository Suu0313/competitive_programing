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
  bundledCode: "#line 2 \"datastructure/unionfind/UnionEnumerate.cpp\"\n\r\nstruct\
    \ UnionEnumerate{\r\n  vector<int> next;\r\n\r\n  UnionEnumerate() = default;\r\
    \n  UnionEnumerate(int n): next(n) { iota(begin(next), end(next), 0); }\r\n\r\n\
    \  size_t size() const { return next.size(); }\r\n\r\n  vector<int> enumerate(int\
    \ n) const {\r\n    vector<int> res(1, n);\r\n\r\n    for(int pos = next[n]; pos\
    \ != n; pos = next[pos]){\r\n      res.push_back(pos);\r\n    }\r\n\r\n    return\
    \ res;\r\n  }\r\n\r\n  vector<vector<int>> group() const {\r\n    int n = int(next.size());\r\
    \n    vector<vector<int>> res;\r\n    vector<bool> seen(n, false);\r\n\r\n   \
    \ for(int i = 0; i < n; ++i){\r\n      if(seen[i]) continue;\r\n      res.push_back(this->enumerate(i));\r\
    \n      for(const int j : res.back()) seen[j] = true;\r\n    }\r\n\r\n    return\
    \ res;\r\n  }\r\n\r\n  void unite(int u, int v){ swap(next[u], next[v]); }\r\n\
    };\r\n"
  code: "#pragma once\r\n\r\nstruct UnionEnumerate{\r\n  vector<int> next;\r\n\r\n\
    \  UnionEnumerate() = default;\r\n  UnionEnumerate(int n): next(n) { iota(begin(next),\
    \ end(next), 0); }\r\n\r\n  size_t size() const { return next.size(); }\r\n\r\n\
    \  vector<int> enumerate(int n) const {\r\n    vector<int> res(1, n);\r\n\r\n\
    \    for(int pos = next[n]; pos != n; pos = next[pos]){\r\n      res.push_back(pos);\r\
    \n    }\r\n\r\n    return res;\r\n  }\r\n\r\n  vector<vector<int>> group() const\
    \ {\r\n    int n = int(next.size());\r\n    vector<vector<int>> res;\r\n    vector<bool>\
    \ seen(n, false);\r\n\r\n    for(int i = 0; i < n; ++i){\r\n      if(seen[i])\
    \ continue;\r\n      res.push_back(this->enumerate(i));\r\n      for(const int\
    \ j : res.back()) seen[j] = true;\r\n    }\r\n\r\n    return res;\r\n  }\r\n\r\
    \n  void unite(int u, int v){ swap(next[u], next[v]); }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/unionfind/UnionEnumerate.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/unionfind/UnionEnumerate.cpp
layout: document
redirect_from:
- /library/datastructure/unionfind/UnionEnumerate.cpp
- /library/datastructure/unionfind/UnionEnumerate.cpp.html
title: datastructure/unionfind/UnionEnumerate.cpp
---
