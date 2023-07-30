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
  bundledCode: "#line 2 \"datastructure/fenwicktree/FenwickTree2d.cpp\"\n\ntemplate\
    \ <typename T>\nstruct FenwickTree2d{\n  int H, W;\n  vector<vector<T>> node;\n\
    \  \n  FenwickTree2d(int H_, int W_): H(H_+1), W(W_+1), node(H, vector<T>(W))\
    \ {}\n\n  void add(int h, int w, T x){\n    for(int i = h+1; i < H; i += (i&-i)){\n\
    \      for(int j = w+1; j < W; j += (j&-j)){\n        node.at(i).at(j) += x;\n\
    \      }\n    }\n  }\n\n  T sum(int h, int w) const { // [0,H) * [0,W)\n    T\
    \ s{};\n    for(int i = h; i > 0; i -= (i&-i)){\n      for(int j = w; j > 0; j\
    \ -= (j&-j)){\n        s += node.at(i).at(j);\n      }\n    }\n    return s;\n\
    \  }\n\n  T query(int h1, int w1, int h2, int w2) const { // [h1,h2) * [w1,w2)\n\
    \    return sum(h2, w2) - sum(h2, w1) - sum(h1, w2) + sum(h1, w1);\n  }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct FenwickTree2d{\n  int H, W;\n\
    \  vector<vector<T>> node;\n  \n  FenwickTree2d(int H_, int W_): H(H_+1), W(W_+1),\
    \ node(H, vector<T>(W)) {}\n\n  void add(int h, int w, T x){\n    for(int i =\
    \ h+1; i < H; i += (i&-i)){\n      for(int j = w+1; j < W; j += (j&-j)){\n   \
    \     node.at(i).at(j) += x;\n      }\n    }\n  }\n\n  T sum(int h, int w) const\
    \ { // [0,H) * [0,W)\n    T s{};\n    for(int i = h; i > 0; i -= (i&-i)){\n  \
    \    for(int j = w; j > 0; j -= (j&-j)){\n        s += node.at(i).at(j);\n   \
    \   }\n    }\n    return s;\n  }\n\n  T query(int h1, int w1, int h2, int w2)\
    \ const { // [h1,h2) * [w1,w2)\n    return sum(h2, w2) - sum(h2, w1) - sum(h1,\
    \ w2) + sum(h1, w1);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/fenwicktree/FenwickTree2d.cpp
  requiredBy: []
  timestamp: '2023-07-22 06:20:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/fenwicktree/FenwickTree2d.cpp
layout: document
redirect_from:
- /library/datastructure/fenwicktree/FenwickTree2d.cpp
- /library/datastructure/fenwicktree/FenwickTree2d.cpp.html
title: datastructure/fenwicktree/FenwickTree2d.cpp
---
