---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: datastructure/fenwicktree/RangeInversionsQuery.cpp
    title: datastructure/fenwicktree/RangeInversionsQuery.cpp
  - icon: ':warning:'
    path: datastructure/fenwicktree/StaticRangeInversionsQuery.cpp
    title: datastructure/fenwicktree/StaticRangeInversionsQuery.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/fenwicktree/FenwickTree.cpp\"\n\ntemplate\
    \ <typename T=int>\nstruct FenwickTree{\n  int n;\n  vector<T> node;\n  FenwickTree()\
    \ = default;\n  FenwickTree(int n_) : n(n_+1), node(n) {}\n  FenwickTree(const\
    \ FenwickTree&) = default;\n  FenwickTree(FenwickTree&&) = default;\n  FenwickTree\
    \ &operator=(const FenwickTree&) = default;\n  FenwickTree &operator=(FenwickTree&&)\
    \ = default;\n\n  void add(int i, T x){\n    for(int idx = i+1; idx < n; idx +=\
    \ (idx & -idx)){\n      node.at(idx) += x;\n    }\n  }\n\n  T sum(int i) const\
    \ { //[0,i)\n    T s{};\n    for(int idx = i; idx > 0; idx -= (idx & -idx)){\n\
    \      s += node.at(idx);\n    }\n    return s;\n  }\n  T query(int l, int r)\
    \ const { //[l,r)\n    return sum(r)-sum(l); \n  }\n\n  T operator[](int i) const\
    \ { return query(i,i+1); }\n\n  int lower_bound(T w) const {\n    if(w <= 0) return\
    \ 0;\n    int x = 0, r = 1;\n    while(r < n) r *= 2;\n    for(int len = r; len>0;\
    \ len>>=1){\n      if(x+len<n && node.at(x+len) < w){\n        w -= node.at(x+=len);\n\
    \      }\n    }\n    return x;\n  }\n};\n"
  code: "#pragma once\n\ntemplate <typename T=int>\nstruct FenwickTree{\n  int n;\n\
    \  vector<T> node;\n  FenwickTree() = default;\n  FenwickTree(int n_) : n(n_+1),\
    \ node(n) {}\n  FenwickTree(const FenwickTree&) = default;\n  FenwickTree(FenwickTree&&)\
    \ = default;\n  FenwickTree &operator=(const FenwickTree&) = default;\n  FenwickTree\
    \ &operator=(FenwickTree&&) = default;\n\n  void add(int i, T x){\n    for(int\
    \ idx = i+1; idx < n; idx += (idx & -idx)){\n      node.at(idx) += x;\n    }\n\
    \  }\n\n  T sum(int i) const { //[0,i)\n    T s{};\n    for(int idx = i; idx >\
    \ 0; idx -= (idx & -idx)){\n      s += node.at(idx);\n    }\n    return s;\n \
    \ }\n  T query(int l, int r) const { //[l,r)\n    return sum(r)-sum(l); \n  }\n\
    \n  T operator[](int i) const { return query(i,i+1); }\n\n  int lower_bound(T\
    \ w) const {\n    if(w <= 0) return 0;\n    int x = 0, r = 1;\n    while(r < n)\
    \ r *= 2;\n    for(int len = r; len>0; len>>=1){\n      if(x+len<n && node.at(x+len)\
    \ < w){\n        w -= node.at(x+=len);\n      }\n    }\n    return x;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/fenwicktree/FenwickTree.cpp
  requiredBy:
  - datastructure/fenwicktree/StaticRangeInversionsQuery.cpp
  - datastructure/fenwicktree/RangeInversionsQuery.cpp
  timestamp: '2023-07-22 06:20:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/fenwicktree/FenwickTree.cpp
layout: document
redirect_from:
- /library/datastructure/fenwicktree/FenwickTree.cpp
- /library/datastructure/fenwicktree/FenwickTree.cpp.html
title: datastructure/fenwicktree/FenwickTree.cpp
---
