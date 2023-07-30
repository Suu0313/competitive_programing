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
  bundledCode: "#line 2 \"datastructure/fenwicktree/runtimeBIT.cpp\"\n\r\ntemplate\
    \ <typename T=int, typename U = long long>\r\nstruct runtimeBIT{\r\n  U n;\r\n\
    \  umap<U, T> node; //1-indexed\r\n  runtimeBIT() : n(0) {}\r\n  runtimeBIT(U\
    \ n_) : n(n_+1) {}\r\n\r\n  void add(U i, T x){\r\n    if(i==0)return;\r\n   \
    \ for(LL idx = i; idx < n; idx += (idx & -idx)){\r\n      node[idx] += x;\r\n\
    \    }\r\n  }\r\n  T sum(U i){ //[1,i]\r\n    T s(0);\r\n    for(U idx = i; idx\
    \ > 0; idx -= (idx & -idx)){\r\n      s += node[idx];\r\n    }\r\n    return s;\r\
    \n  }\r\n  T query(U l, U r){ //[l,r)\r\n    return sum(r-1)-sum(l-1); \r\n  }\r\
    \n\r\n  U lower_bound(T w){\r\n    if(w <= 0) return 0;\r\n    U x = 0, r = 1;\r\
    \n    while(r < n) r *= 2;\r\n    for(U len = r; len>0; len>>=1){\r\n      if(x+len<n\
    \ && node[x+len] < w){\r\n        w -= node[x+len];\r\n        x += len;\r\n \
    \     }\r\n    }\r\n    return x+1;\r\n  }\r\n  /*\r\n  //invension number\r\n\
    \  REP(i,N){\r\n    ans += i - bit.sum(a.at(i));\r\n    bit.add(a.at(i),1);\r\n\
    \  }\r\n  */\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename T=int, typename U = long long>\r\n\
    struct runtimeBIT{\r\n  U n;\r\n  umap<U, T> node; //1-indexed\r\n  runtimeBIT()\
    \ : n(0) {}\r\n  runtimeBIT(U n_) : n(n_+1) {}\r\n\r\n  void add(U i, T x){\r\n\
    \    if(i==0)return;\r\n    for(LL idx = i; idx < n; idx += (idx & -idx)){\r\n\
    \      node[idx] += x;\r\n    }\r\n  }\r\n  T sum(U i){ //[1,i]\r\n    T s(0);\r\
    \n    for(U idx = i; idx > 0; idx -= (idx & -idx)){\r\n      s += node[idx];\r\
    \n    }\r\n    return s;\r\n  }\r\n  T query(U l, U r){ //[l,r)\r\n    return\
    \ sum(r-1)-sum(l-1); \r\n  }\r\n\r\n  U lower_bound(T w){\r\n    if(w <= 0) return\
    \ 0;\r\n    U x = 0, r = 1;\r\n    while(r < n) r *= 2;\r\n    for(U len = r;\
    \ len>0; len>>=1){\r\n      if(x+len<n && node[x+len] < w){\r\n        w -= node[x+len];\r\
    \n        x += len;\r\n      }\r\n    }\r\n    return x+1;\r\n  }\r\n  /*\r\n\
    \  //invension number\r\n  REP(i,N){\r\n    ans += i - bit.sum(a.at(i));\r\n \
    \   bit.add(a.at(i),1);\r\n  }\r\n  */\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/fenwicktree/runtimeBIT.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/fenwicktree/runtimeBIT.cpp
layout: document
redirect_from:
- /library/datastructure/fenwicktree/runtimeBIT.cpp
- /library/datastructure/fenwicktree/runtimeBIT.cpp.html
title: datastructure/fenwicktree/runtimeBIT.cpp
---
