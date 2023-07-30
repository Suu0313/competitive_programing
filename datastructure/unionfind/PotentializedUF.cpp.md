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
  bundledCode: "#line 2 \"datastructure/unionfind/PotentializedUF.cpp\"\n\r\ntemplate\
    \ <typename T = int>\r\nstruct PotentializedUF {\r\n  \r\n  vector<int> data;\r\
    \n  vector<T> diff_weight;\r\n  \r\n  PotentializedUF() {}\r\n  \r\n  PotentializedUF(int\
    \ n):data(n, -1), diff_weight(n) { }\r\n  \r\n  void init(int n) { \r\n    data.assign(n,\
    \ -1);\r\n    diff_weight.assign(n,0);\r\n  }\r\n  \r\n  \r\n  int find(int x)\
    \ {\r\n    if(data[x] < 0) return x;\r\n    int r = find(data[x]);\r\n    diff_weight[x]\
    \ += diff_weight[data[x]];\r\n    return data[x] = r;\r\n    \r\n  }\r\n\r\n \
    \ bool unite(int x, int y, T w){\r\n    w += weight(x); w -= weight(y);\r\n  \
    \  x = find(x); y = find(y);\r\n    if(x == y) return false;\r\n\r\n    if(data[x]\
    \ > data[y]){ swap(x,y); w = -w; }\r\n    data[x] += data[y];\r\n    data[y] =\
    \ x;\r\n    diff_weight[y] = w;\r\n    return true;\r\n  }\r\n\r\n  T weight(int\
    \ x){\r\n    find(x);\r\n    return diff_weight[x];\r\n  }\r\n\r\n  T diff(int\
    \ x, int y){\r\n    if(same(x,y)){\r\n      return weight(y) - weight(x);\r\n\
    \    }\r\n    return T(0);\r\n  }\r\n\r\n  bool same(int x, int y){\r\n    return\
    \ find(x) == find(y);\r\n  }\r\n  \r\n  int size(int x){\r\n    return -data[find(x)];\r\
    \n  }\r\n\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename T = int>\r\nstruct PotentializedUF\
    \ {\r\n  \r\n  vector<int> data;\r\n  vector<T> diff_weight;\r\n  \r\n  PotentializedUF()\
    \ {}\r\n  \r\n  PotentializedUF(int n):data(n, -1), diff_weight(n) { }\r\n  \r\
    \n  void init(int n) { \r\n    data.assign(n, -1);\r\n    diff_weight.assign(n,0);\r\
    \n  }\r\n  \r\n  \r\n  int find(int x) {\r\n    if(data[x] < 0) return x;\r\n\
    \    int r = find(data[x]);\r\n    diff_weight[x] += diff_weight[data[x]];\r\n\
    \    return data[x] = r;\r\n    \r\n  }\r\n\r\n  bool unite(int x, int y, T w){\r\
    \n    w += weight(x); w -= weight(y);\r\n    x = find(x); y = find(y);\r\n   \
    \ if(x == y) return false;\r\n\r\n    if(data[x] > data[y]){ swap(x,y); w = -w;\
    \ }\r\n    data[x] += data[y];\r\n    data[y] = x;\r\n    diff_weight[y] = w;\r\
    \n    return true;\r\n  }\r\n\r\n  T weight(int x){\r\n    find(x);\r\n    return\
    \ diff_weight[x];\r\n  }\r\n\r\n  T diff(int x, int y){\r\n    if(same(x,y)){\r\
    \n      return weight(y) - weight(x);\r\n    }\r\n    return T(0);\r\n  }\r\n\r\
    \n  bool same(int x, int y){\r\n    return find(x) == find(y);\r\n  }\r\n  \r\n\
    \  int size(int x){\r\n    return -data[find(x)];\r\n  }\r\n\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/unionfind/PotentializedUF.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/unionfind/PotentializedUF.cpp
layout: document
redirect_from:
- /library/datastructure/unionfind/PotentializedUF.cpp
- /library/datastructure/unionfind/PotentializedUF.cpp.html
title: datastructure/unionfind/PotentializedUF.cpp
---
