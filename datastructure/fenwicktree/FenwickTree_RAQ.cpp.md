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
  bundledCode: "#line 2 \"datastructure/fenwicktree/FenwickTree_RAQ.cpp\"\n\ntemplate\
    \ <typename T>\nstruct FenwickTree_RAQ{ //ToDo: verify\n  int n;\n  vector<T>\
    \ node0, node1;\n\n  FenwickTree_RAQ() = default;\n  FenwickTree_RAQ(int n_) :\
    \ n(n_+1), node0(n, 0), node1(n, 0) {}\n\n  void add(int l, int r, T x){ // [l,r)\n\
    \    add_sub(node0, l, -x*l);\n    add_sub(node0, r, x*r);\n    add_sub(node1,\
    \ l, x);\n    add_sub(node1, r, -x);\n  }\n\n  T sum(int i) const { //[0,i)\n\
    \    return sum_sub(node0, i) + sum_sub(node1, i)*i;\n  }\n\n  T query(int l,\
    \ int r) const { //[l,r)\n    return sum(r) - sum(l); \n  }\n\n  T operator[](int\
    \ i) const { return query(i, i+1); }\n\nprivate:\n  void add_sub(vector<T> &node,\
    \ int i, T x){\n    for(int idx = i+1; idx < n; idx += (idx & -idx)){\n      node[idx]\
    \ += x;\n    }\n  }\n\n  T sum_sub(const vector<T> &node, int i) const {\n   \
    \ T s{};\n    for(int idx = i; idx > 0; idx -= (idx & -idx)){\n      s += node[idx];\n\
    \    }\n    return s;\n  }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct FenwickTree_RAQ{ //ToDo: verify\n\
    \  int n;\n  vector<T> node0, node1;\n\n  FenwickTree_RAQ() = default;\n  FenwickTree_RAQ(int\
    \ n_) : n(n_+1), node0(n, 0), node1(n, 0) {}\n\n  void add(int l, int r, T x){\
    \ // [l,r)\n    add_sub(node0, l, -x*l);\n    add_sub(node0, r, x*r);\n    add_sub(node1,\
    \ l, x);\n    add_sub(node1, r, -x);\n  }\n\n  T sum(int i) const { //[0,i)\n\
    \    return sum_sub(node0, i) + sum_sub(node1, i)*i;\n  }\n\n  T query(int l,\
    \ int r) const { //[l,r)\n    return sum(r) - sum(l); \n  }\n\n  T operator[](int\
    \ i) const { return query(i, i+1); }\n\nprivate:\n  void add_sub(vector<T> &node,\
    \ int i, T x){\n    for(int idx = i+1; idx < n; idx += (idx & -idx)){\n      node[idx]\
    \ += x;\n    }\n  }\n\n  T sum_sub(const vector<T> &node, int i) const {\n   \
    \ T s{};\n    for(int idx = i; idx > 0; idx -= (idx & -idx)){\n      s += node[idx];\n\
    \    }\n    return s;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/fenwicktree/FenwickTree_RAQ.cpp
  requiredBy: []
  timestamp: '2023-07-22 06:20:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/fenwicktree/FenwickTree_RAQ.cpp
layout: document
redirect_from:
- /library/datastructure/fenwicktree/FenwickTree_RAQ.cpp
- /library/datastructure/fenwicktree/FenwickTree_RAQ.cpp.html
title: datastructure/fenwicktree/FenwickTree_RAQ.cpp
---
