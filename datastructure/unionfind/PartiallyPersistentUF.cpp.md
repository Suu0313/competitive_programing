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
  bundledCode: "#line 2 \"datastructure/unionfind/PartiallyPersistentUF.cpp\"\n\r\n\
    struct PartiallyPersistentUF {\r\n  vector<int> par, siz, last;\r\n  int now;\r\
    \n  vector<vector<pair<int, int>>> hist;\r\n  \r\n  PartiallyPersistentUF() {}\r\
    \n  PartiallyPersistentUF(int n)\r\n  : par(n,-1),siz(n,1),last(n,numeric_limits<int>::max()/2),now(0)\
    \ {\r\n    iota(par.begin(), par.end(), 0);\r\n    hist.assign(n,vector<pair<int,\
    \ int>>(1,{0,1}));\r\n  }\r\n  void init(int n){\r\n    par.resize(n);\r\n   \
    \ iota(par.begin(), par.end(),0);\r\n    siz.assign(n,1);\r\n    last.assign(n,numeric_limits<int>::max()/2);\r\
    \n    now = 0;\r\n    hist.assign(n,vector<pair<int, int>>(1,{0,1}));\r\n  }\r\
    \n\r\n  int find(int t,int x) {\r\n    while(last.at(x)<=t) x = par.at(x);\r\n\
    \    return x;\r\n  }\r\n\r\n  pair<bool,int> unite(int x, int y){\r\n    x =\
    \ find(now, x);\r\n    y = find(now, y);\r\n    now++;\r\n    if(x == y) return\
    \ {false,now-1};\r\n\r\n    if(siz[x] < siz[y]){\r\n      swap(x,y);\r\n    }\r\
    \n    siz[x] += siz[y];\r\n    par[y] = x;\r\n    last[y] = now;\r\n    hist.at(x).emplace_back(now,\
    \ siz[x]);\r\n    return {true, now-1};\r\n  }\r\n\r\n  bool same(int t, int x,\
    \ int y){\r\n    return find(t, x) == find(t, y);\r\n  }\r\n\r\n  int size(int\
    \ t, int x){\r\n    x = find(t, x);\r\n    return prev(partition_point(\r\n  \
    \    hist[x].begin(), hist[x].end(),\r\n      [t](pair<int, int> &h){ return h.first<=t;})\r\
    \n      )->second;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\nstruct PartiallyPersistentUF {\r\n  vector<int> par,\
    \ siz, last;\r\n  int now;\r\n  vector<vector<pair<int, int>>> hist;\r\n  \r\n\
    \  PartiallyPersistentUF() {}\r\n  PartiallyPersistentUF(int n)\r\n  : par(n,-1),siz(n,1),last(n,numeric_limits<int>::max()/2),now(0)\
    \ {\r\n    iota(par.begin(), par.end(), 0);\r\n    hist.assign(n,vector<pair<int,\
    \ int>>(1,{0,1}));\r\n  }\r\n  void init(int n){\r\n    par.resize(n);\r\n   \
    \ iota(par.begin(), par.end(),0);\r\n    siz.assign(n,1);\r\n    last.assign(n,numeric_limits<int>::max()/2);\r\
    \n    now = 0;\r\n    hist.assign(n,vector<pair<int, int>>(1,{0,1}));\r\n  }\r\
    \n\r\n  int find(int t,int x) {\r\n    while(last.at(x)<=t) x = par.at(x);\r\n\
    \    return x;\r\n  }\r\n\r\n  pair<bool,int> unite(int x, int y){\r\n    x =\
    \ find(now, x);\r\n    y = find(now, y);\r\n    now++;\r\n    if(x == y) return\
    \ {false,now-1};\r\n\r\n    if(siz[x] < siz[y]){\r\n      swap(x,y);\r\n    }\r\
    \n    siz[x] += siz[y];\r\n    par[y] = x;\r\n    last[y] = now;\r\n    hist.at(x).emplace_back(now,\
    \ siz[x]);\r\n    return {true, now-1};\r\n  }\r\n\r\n  bool same(int t, int x,\
    \ int y){\r\n    return find(t, x) == find(t, y);\r\n  }\r\n\r\n  int size(int\
    \ t, int x){\r\n    x = find(t, x);\r\n    return prev(partition_point(\r\n  \
    \    hist[x].begin(), hist[x].end(),\r\n      [t](pair<int, int> &h){ return h.first<=t;})\r\
    \n      )->second;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/unionfind/PartiallyPersistentUF.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/unionfind/PartiallyPersistentUF.cpp
layout: document
redirect_from:
- /library/datastructure/unionfind/PartiallyPersistentUF.cpp
- /library/datastructure/unionfind/PartiallyPersistentUF.cpp.html
title: datastructure/unionfind/PartiallyPersistentUF.cpp
---
