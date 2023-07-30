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
  bundledCode: "#line 2 \"datastructure/unionfind/UnionFindTree.cpp\"\n\r\nstruct\
    \ UnionFindTree {\r\n  \r\n  vector<int> data, left, right, anc;\r\n  int merge_cnt;\r\
    \n  \r\n  UnionFindTree() {}\r\n  UnionFindTree(int n): data(n,-1), left(n*2-1,\
    \ -1), right(n*2-1, -1), anc(n*2-1), merge_cnt(n) {\r\n    iota(begin(anc), end(anc),\
    \ 0);\r\n  }\r\n  \r\n  int find(int x) {\r\n    int root = x;\r\n    while(data[root]\
    \ >= 0) root = data[root];\r\n    while(data[x] >= 0) x = exchange(data[x], root);\r\
    \n    return root;\r\n  }\r\n\r\n  int ancestor(int x){ return anc[find(x)]; }\r\
    \n\r\n  bool unite(int x, int y){\r\n    x = find(x);\r\n    y = find(y);\r\n\
    \    if(x == y) return false;\r\n\r\n    if(data[x] > data[y]) swap(x,y);\r\n\
    \    data[x] += data[y];\r\n\r\n    left[merge_cnt] = anc[x];\r\n    right[merge_cnt]\
    \ = anc[y];\r\n    anc[x] = merge_cnt++;\r\n    data[y] = x;\r\n    return true;\r\
    \n  }\r\n\r\n  bool same(int x, int y){\r\n    return find(x) == find(y);\r\n\
    \  }\r\n  \r\n  int size(int x){\r\n    return -data[find(x)];\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\nstruct UnionFindTree {\r\n  \r\n  vector<int> data, left,\
    \ right, anc;\r\n  int merge_cnt;\r\n  \r\n  UnionFindTree() {}\r\n  UnionFindTree(int\
    \ n): data(n,-1), left(n*2-1, -1), right(n*2-1, -1), anc(n*2-1), merge_cnt(n)\
    \ {\r\n    iota(begin(anc), end(anc), 0);\r\n  }\r\n  \r\n  int find(int x) {\r\
    \n    int root = x;\r\n    while(data[root] >= 0) root = data[root];\r\n    while(data[x]\
    \ >= 0) x = exchange(data[x], root);\r\n    return root;\r\n  }\r\n\r\n  int ancestor(int\
    \ x){ return anc[find(x)]; }\r\n\r\n  bool unite(int x, int y){\r\n    x = find(x);\r\
    \n    y = find(y);\r\n    if(x == y) return false;\r\n\r\n    if(data[x] > data[y])\
    \ swap(x,y);\r\n    data[x] += data[y];\r\n\r\n    left[merge_cnt] = anc[x];\r\
    \n    right[merge_cnt] = anc[y];\r\n    anc[x] = merge_cnt++;\r\n    data[y] =\
    \ x;\r\n    return true;\r\n  }\r\n\r\n  bool same(int x, int y){\r\n    return\
    \ find(x) == find(y);\r\n  }\r\n  \r\n  int size(int x){\r\n    return -data[find(x)];\r\
    \n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/unionfind/UnionFindTree.cpp
  requiredBy: []
  timestamp: '2023-07-22 06:23:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/unionfind/UnionFindTree.cpp
layout: document
redirect_from:
- /library/datastructure/unionfind/UnionFindTree.cpp
- /library/datastructure/unionfind/UnionFindTree.cpp.html
title: datastructure/unionfind/UnionFindTree.cpp
---
