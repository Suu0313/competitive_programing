---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: datastructure/fenwicktree/FenwickTree.cpp
    title: datastructure/fenwicktree/FenwickTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/fenwicktree/RangeInversionsQuery.cpp\"\n\r\
    \n#line 2 \"datastructure/fenwicktree/FenwickTree.cpp\"\n\ntemplate <typename\
    \ T=int>\nstruct FenwickTree{\n  int n;\n  vector<T> node;\n  FenwickTree() =\
    \ default;\n  FenwickTree(int n_) : n(n_+1), node(n) {}\n  FenwickTree(const FenwickTree&)\
    \ = default;\n  FenwickTree(FenwickTree&&) = default;\n  FenwickTree &operator=(const\
    \ FenwickTree&) = default;\n  FenwickTree &operator=(FenwickTree&&) = default;\n\
    \n  void add(int i, T x){\n    for(int idx = i+1; idx < n; idx += (idx & -idx)){\n\
    \      node.at(idx) += x;\n    }\n  }\n\n  T sum(int i) const { //[0,i)\n    T\
    \ s{};\n    for(int idx = i; idx > 0; idx -= (idx & -idx)){\n      s += node.at(idx);\n\
    \    }\n    return s;\n  }\n  T query(int l, int r) const { //[l,r)\n    return\
    \ sum(r)-sum(l); \n  }\n\n  T operator[](int i) const { return query(i,i+1); }\n\
    \n  int lower_bound(T w) const {\n    if(w <= 0) return 0;\n    int x = 0, r =\
    \ 1;\n    while(r < n) r *= 2;\n    for(int len = r; len>0; len>>=1){\n      if(x+len<n\
    \ && node.at(x+len) < w){\n        w -= node.at(x+=len);\n      }\n    }\n   \
    \ return x;\n  }\n};\n#line 4 \"datastructure/fenwicktree/RangeInversionsQuery.cpp\"\
    \n\r\nstruct RangeInversionsQuery{\r\n  int n, upper;\r\n  vector<int> a;\r\n\
    \  \r\n  vector<FenwickTree<int>> prefix_freq;\r\n  vector<FenwickTree<int>> large_inv;\r\
    \n  vector<int> small_inv;\r\n  FenwickTree<int> fw;\r\n\r\n  void init(const\
    \ vector<int> &b, int upper){\r\n    this->upper = upper;\r\n    int N = int(b.size());\r\
    \n    for(n = 1; n * n < N; ++n);\r\n    a.assign(n * n, 0);\r\n    for(int i\
    \ = 0; i < N; ++i) a[i] = b[i];\r\n\r\n    prefix_freq.assign(n + 1, upper);\r\
    \n\r\n    for(int i = 0; i < n; ++i){\r\n      prefix_freq[i + 1] = prefix_freq[i];\r\
    \n      for(int j = 0; j < n; ++j){\r\n        prefix_freq[i + 1].add(a[i * n\
    \ + j], 1);\r\n      }\r\n    }\r\n\r\n    fw = FenwickTree<int>(upper);\r\n \
    \   large_inv.assign(n, n);\r\n\r\n    for(int j = 1; j < n; ++j){\r\n      for(int\
    \ k = j * n; k < j * n + n; ++k) fw.add(a[k], 1);\r\n      for(int i = 0; i <\
    \ j; ++i){\r\n        int x = 0;\r\n        for(int k = i * n; k < i * n + n;\
    \ ++k) x += fw.sum(a[k]);\r\n        large_inv[i].add(j, x);\r\n      }\r\n  \
    \    for(int k = j * n; k < j * n + n; ++k) fw.add(a[k], -1);\r\n    }\r\n\r\n\
    \    small_inv.assign(n, 0);\r\n    for(int i = 0; i < n; ++i){\r\n      small_inv[i]\
    \ = cal_inv_short(i * n, i * n + n);\r\n    }\r\n  }\r\n\r\n  void update(int\
    \ k, int x){\r\n    int px = a[k]; a[k] = x;\r\n\r\n    for(int i = k/n; i < n;\
    \ ++i){\r\n      prefix_freq[i + 1].add(px, -1);\r\n      prefix_freq[i + 1].add(x,\
    \ 1);\r\n    }\r\n\r\n    int bk = k / n;\r\n    for(int i = 0; i < n; ++i){\r\
    \n      if(bk < i){\r\n        int pfr = prefix_freq[i + 1].sum(px) - prefix_freq[i].sum(px);\r\
    \n        int fr = prefix_freq[i + 1].sum(x) - prefix_freq[i].sum(x);\r\n    \
    \    large_inv[bk].add(i, fr - pfr);\r\n      }\r\n\r\n      if(i < bk){\r\n \
    \       int pfr = prefix_freq[i + 1].query(px + 1, upper) - prefix_freq[i].query(px\
    \ + 1, upper);\r\n        int fr = prefix_freq[i + 1].query(x + 1, upper) - prefix_freq[i].query(x\
    \ + 1, upper);\r\n        large_inv[i].add(bk, fr - pfr);\r\n      }\r\n    }\r\
    \n\r\n    small_inv[bk] = cal_inv_short(bk * n, bk * n + n);\r\n  }\r\n\r\n  int64_t\
    \ query(int l, int r){\r\n    if(l >= r) return 0;\r\n    int bl = (l + n - 1)/n,\
    \ br = r / n;\r\n    if(bl > br) return cal_inv_short(l, r);\r\n\r\n    int64_t\
    \ inv = cal_inv_short(l, bl * n, br * n, r);\r\n\r\n    for(int i = bl; i < br;\
    \ ++i) inv += large_inv[i].sum(br);\r\n\r\n    for(int i = l; i < bl * n; ++i){\r\
    \n      inv += prefix_freq[br].sum(a[i]) - prefix_freq[bl].sum(a[i]);\r\n    }\r\
    \n\r\n    for(int i = br * n; i < r; ++i){\r\n      inv += (br * n - bl * n) -\
    \ (prefix_freq[br].sum(a[i] + 1) - prefix_freq[bl].sum(a[i] + 1));\r\n    }\r\n\
    \r\n    for(int i = bl; i < br; ++i) inv += small_inv[i];\r\n    return inv;\r\
    \n  }\r\n\r\n  int cal_inv_short(int l, int r){\r\n    int inv = 0;\r\n    for(int\
    \ i = r - 1; i >= l; --i){ inv += fw.sum(a[i]); fw.add(a[i], 1); }\r\n\r\n   \
    \ for(int i = r - 1; i >= l; --i) fw.add(a[i], -1);\r\n\r\n    return inv;\r\n\
    \  }\r\n\r\n  int cal_inv_short(int l1, int r1, int l2, int r2){\r\n    int inv\
    \ = 0;\r\n    for(int i = r2 - 1; i >= l2; --i){\r\n      inv += fw.sum(a[i]);\r\
    \n      fw.add(a[i], 1);\r\n    }\r\n    for(int i = r1 - 1; i >= l1; --i){\r\n\
    \      inv += fw.sum(a[i]);\r\n      fw.add(a[i], 1);\r\n    }\r\n\r\n    for(int\
    \ i = r2 - 1; i >= l2; --i) fw.add(a[i], -1);\r\n    for(int i = r1 - 1; i >=\
    \ l1; --i) fw.add(a[i], -1);\r\n\r\n    return inv;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include \"./FenwickTree.cpp\"\r\n\r\nstruct RangeInversionsQuery{\r\
    \n  int n, upper;\r\n  vector<int> a;\r\n  \r\n  vector<FenwickTree<int>> prefix_freq;\r\
    \n  vector<FenwickTree<int>> large_inv;\r\n  vector<int> small_inv;\r\n  FenwickTree<int>\
    \ fw;\r\n\r\n  void init(const vector<int> &b, int upper){\r\n    this->upper\
    \ = upper;\r\n    int N = int(b.size());\r\n    for(n = 1; n * n < N; ++n);\r\n\
    \    a.assign(n * n, 0);\r\n    for(int i = 0; i < N; ++i) a[i] = b[i];\r\n\r\n\
    \    prefix_freq.assign(n + 1, upper);\r\n\r\n    for(int i = 0; i < n; ++i){\r\
    \n      prefix_freq[i + 1] = prefix_freq[i];\r\n      for(int j = 0; j < n; ++j){\r\
    \n        prefix_freq[i + 1].add(a[i * n + j], 1);\r\n      }\r\n    }\r\n\r\n\
    \    fw = FenwickTree<int>(upper);\r\n    large_inv.assign(n, n);\r\n\r\n    for(int\
    \ j = 1; j < n; ++j){\r\n      for(int k = j * n; k < j * n + n; ++k) fw.add(a[k],\
    \ 1);\r\n      for(int i = 0; i < j; ++i){\r\n        int x = 0;\r\n        for(int\
    \ k = i * n; k < i * n + n; ++k) x += fw.sum(a[k]);\r\n        large_inv[i].add(j,\
    \ x);\r\n      }\r\n      for(int k = j * n; k < j * n + n; ++k) fw.add(a[k],\
    \ -1);\r\n    }\r\n\r\n    small_inv.assign(n, 0);\r\n    for(int i = 0; i < n;\
    \ ++i){\r\n      small_inv[i] = cal_inv_short(i * n, i * n + n);\r\n    }\r\n\
    \  }\r\n\r\n  void update(int k, int x){\r\n    int px = a[k]; a[k] = x;\r\n\r\
    \n    for(int i = k/n; i < n; ++i){\r\n      prefix_freq[i + 1].add(px, -1);\r\
    \n      prefix_freq[i + 1].add(x, 1);\r\n    }\r\n\r\n    int bk = k / n;\r\n\
    \    for(int i = 0; i < n; ++i){\r\n      if(bk < i){\r\n        int pfr = prefix_freq[i\
    \ + 1].sum(px) - prefix_freq[i].sum(px);\r\n        int fr = prefix_freq[i + 1].sum(x)\
    \ - prefix_freq[i].sum(x);\r\n        large_inv[bk].add(i, fr - pfr);\r\n    \
    \  }\r\n\r\n      if(i < bk){\r\n        int pfr = prefix_freq[i + 1].query(px\
    \ + 1, upper) - prefix_freq[i].query(px + 1, upper);\r\n        int fr = prefix_freq[i\
    \ + 1].query(x + 1, upper) - prefix_freq[i].query(x + 1, upper);\r\n        large_inv[i].add(bk,\
    \ fr - pfr);\r\n      }\r\n    }\r\n\r\n    small_inv[bk] = cal_inv_short(bk *\
    \ n, bk * n + n);\r\n  }\r\n\r\n  int64_t query(int l, int r){\r\n    if(l >=\
    \ r) return 0;\r\n    int bl = (l + n - 1)/n, br = r / n;\r\n    if(bl > br) return\
    \ cal_inv_short(l, r);\r\n\r\n    int64_t inv = cal_inv_short(l, bl * n, br *\
    \ n, r);\r\n\r\n    for(int i = bl; i < br; ++i) inv += large_inv[i].sum(br);\r\
    \n\r\n    for(int i = l; i < bl * n; ++i){\r\n      inv += prefix_freq[br].sum(a[i])\
    \ - prefix_freq[bl].sum(a[i]);\r\n    }\r\n\r\n    for(int i = br * n; i < r;\
    \ ++i){\r\n      inv += (br * n - bl * n) - (prefix_freq[br].sum(a[i] + 1) - prefix_freq[bl].sum(a[i]\
    \ + 1));\r\n    }\r\n\r\n    for(int i = bl; i < br; ++i) inv += small_inv[i];\r\
    \n    return inv;\r\n  }\r\n\r\n  int cal_inv_short(int l, int r){\r\n    int\
    \ inv = 0;\r\n    for(int i = r - 1; i >= l; --i){ inv += fw.sum(a[i]); fw.add(a[i],\
    \ 1); }\r\n\r\n    for(int i = r - 1; i >= l; --i) fw.add(a[i], -1);\r\n\r\n \
    \   return inv;\r\n  }\r\n\r\n  int cal_inv_short(int l1, int r1, int l2, int\
    \ r2){\r\n    int inv = 0;\r\n    for(int i = r2 - 1; i >= l2; --i){\r\n     \
    \ inv += fw.sum(a[i]);\r\n      fw.add(a[i], 1);\r\n    }\r\n    for(int i = r1\
    \ - 1; i >= l1; --i){\r\n      inv += fw.sum(a[i]);\r\n      fw.add(a[i], 1);\r\
    \n    }\r\n\r\n    for(int i = r2 - 1; i >= l2; --i) fw.add(a[i], -1);\r\n   \
    \ for(int i = r1 - 1; i >= l1; --i) fw.add(a[i], -1);\r\n\r\n    return inv;\r\
    \n  }\r\n};\r\n"
  dependsOn:
  - datastructure/fenwicktree/FenwickTree.cpp
  isVerificationFile: false
  path: datastructure/fenwicktree/RangeInversionsQuery.cpp
  requiredBy: []
  timestamp: '2023-07-22 06:20:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/fenwicktree/RangeInversionsQuery.cpp
layout: document
redirect_from:
- /library/datastructure/fenwicktree/RangeInversionsQuery.cpp
- /library/datastructure/fenwicktree/RangeInversionsQuery.cpp.html
title: datastructure/fenwicktree/RangeInversionsQuery.cpp
---
