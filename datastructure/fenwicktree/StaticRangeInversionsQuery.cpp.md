---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: datastructure/fenwicktree/FenwickTree.cpp
    title: datastructure/fenwicktree/FenwickTree.cpp
  - icon: ':warning:'
    path: other/sort/merge_sort.cpp
    title: other/sort/merge_sort.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/fenwicktree/StaticRangeInversionsQuery.cpp\"\
    \n\r\n#line 2 \"datastructure/fenwicktree/FenwickTree.cpp\"\n\ntemplate <typename\
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
    \ return x;\n  }\n};\n#line 2 \"other/sort/merge_sort.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nlong long merge_sort(vector<T> &a){\r\n  int n = int(a.size());\r\n  long\
    \ long inv = 0;\r\n\r\n  vector<T> b(n);\r\n  for(int len = 1; len < n; len *=\
    \ 2){\r\n    for(int l=0,m=len,r=min(len*2,n),i=0; l<n; l=r,m=min(l+len,n),r=min(m+len,n)){\r\
    \n      for(int p = l, q = m; p < m || q < r; ){\r\n        if(p == m){\r\n  \
    \        while(q < r) b[i++] = a[q++];\r\n          break;\r\n        }\r\n  \
    \      if(q == r){\r\n          while(p < m) b[i++] = a[p++];\r\n          break;\r\
    \n        }\r\n\r\n        if(a[p] > a[q]){\r\n          b[i++] = a[q++]; inv\
    \ += m - p;\r\n        }else{\r\n          b[i++] = a[p++];\r\n        }\r\n \
    \     }\r\n    }\r\n    swap(a, b);\r\n  }\r\n\r\n  return inv;\r\n}\r\n#line\
    \ 5 \"datastructure/fenwicktree/StaticRangeInversionsQuery.cpp\"\n\r\nstruct StaticRangeInversionsQuery{\r\
    \n  int n, sn;\r\n  vector<int> a;\r\n  vector<vector<int64_t>> binv;\r\n  vector<FenwickTree<int>>\
    \ bits;\r\n\r\n  template<typename T>\r\n  StaticRangeInversionsQuery(const vector<T>\
    \ &x){\r\n    n = int(x.size());\r\n    sn = 1; while(sn*sn < n) ++sn;\r\n   \
    \ a = compress(x).first;\r\n    n = sn*sn; a.resize(n, n-1);\r\n    binv = vector(sn,\
    \ vector<int64_t>(sn+1));\r\n\r\n    for(int i = 0; i < n; i += sn){\r\n     \
    \ int64_t inv = 0;\r\n      FenwickTree<int> bit(n);\r\n      for(int j = i; j\
    \ < n; ++j){\r\n        inv += (j-i) - bit.sum(a[j] + 1);\r\n        bit.add(a[j],\
    \ 1);\r\n        if((j+1)%sn == 0) binv[i/sn][(j+1)/sn] = inv;\r\n      }\r\n\
    \    }\r\n\r\n    bits.assign(sn+1, n);\r\n    for(int i = 0; i < n; ++i){\r\n\
    \      if(i%sn == 0) bits[i/sn].node = bits[sn].node;\r\n      bits[sn].add(a[i],\
    \ 1);\r\n    }\r\n  }\r\n\r\n  int64_t query(int l, int r){\r\n    if(l/sn ==\
    \ (r-1)/sn){\r\n      vector<int> b(begin(a)+l, begin(a)+r);\r\n      return merge_sort(b);\r\
    \n    }\r\n\r\n    int i = (l+sn-1)/sn, j = r/sn;\r\n    int64_t inv = binv[i][j];\r\
    \n    vector<int> b(begin(a)+l, begin(a)+i*sn);\r\n\r\n    for(int k = l; k <\
    \ i*sn; ++k){\r\n      inv += bits[j].sum(a[k]) - bits[i].sum(a[k]);\r\n    }\r\
    \n    for(int k = j*sn; k < r; ++k){\r\n      inv += bits[j].query(a[k]+1, n)\
    \ - bits[i].query(a[k]+1, n);\r\n      b.push_back(a[k]);\r\n    }\r\n\r\n   \
    \ inv += merge_sort(b);\r\n    return inv;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include \"./FenwickTree.cpp\"\r\n#include \"../../other/sort/merge_sort.cpp\"\
    \r\n\r\nstruct StaticRangeInversionsQuery{\r\n  int n, sn;\r\n  vector<int> a;\r\
    \n  vector<vector<int64_t>> binv;\r\n  vector<FenwickTree<int>> bits;\r\n\r\n\
    \  template<typename T>\r\n  StaticRangeInversionsQuery(const vector<T> &x){\r\
    \n    n = int(x.size());\r\n    sn = 1; while(sn*sn < n) ++sn;\r\n    a = compress(x).first;\r\
    \n    n = sn*sn; a.resize(n, n-1);\r\n    binv = vector(sn, vector<int64_t>(sn+1));\r\
    \n\r\n    for(int i = 0; i < n; i += sn){\r\n      int64_t inv = 0;\r\n      FenwickTree<int>\
    \ bit(n);\r\n      for(int j = i; j < n; ++j){\r\n        inv += (j-i) - bit.sum(a[j]\
    \ + 1);\r\n        bit.add(a[j], 1);\r\n        if((j+1)%sn == 0) binv[i/sn][(j+1)/sn]\
    \ = inv;\r\n      }\r\n    }\r\n\r\n    bits.assign(sn+1, n);\r\n    for(int i\
    \ = 0; i < n; ++i){\r\n      if(i%sn == 0) bits[i/sn].node = bits[sn].node;\r\n\
    \      bits[sn].add(a[i], 1);\r\n    }\r\n  }\r\n\r\n  int64_t query(int l, int\
    \ r){\r\n    if(l/sn == (r-1)/sn){\r\n      vector<int> b(begin(a)+l, begin(a)+r);\r\
    \n      return merge_sort(b);\r\n    }\r\n\r\n    int i = (l+sn-1)/sn, j = r/sn;\r\
    \n    int64_t inv = binv[i][j];\r\n    vector<int> b(begin(a)+l, begin(a)+i*sn);\r\
    \n\r\n    for(int k = l; k < i*sn; ++k){\r\n      inv += bits[j].sum(a[k]) - bits[i].sum(a[k]);\r\
    \n    }\r\n    for(int k = j*sn; k < r; ++k){\r\n      inv += bits[j].query(a[k]+1,\
    \ n) - bits[i].query(a[k]+1, n);\r\n      b.push_back(a[k]);\r\n    }\r\n\r\n\
    \    inv += merge_sort(b);\r\n    return inv;\r\n  }\r\n};\r\n"
  dependsOn:
  - datastructure/fenwicktree/FenwickTree.cpp
  - other/sort/merge_sort.cpp
  isVerificationFile: false
  path: datastructure/fenwicktree/StaticRangeInversionsQuery.cpp
  requiredBy: []
  timestamp: '2023-07-22 06:20:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/fenwicktree/StaticRangeInversionsQuery.cpp
layout: document
redirect_from:
- /library/datastructure/fenwicktree/StaticRangeInversionsQuery.cpp
- /library/datastructure/fenwicktree/StaticRangeInversionsQuery.cpp.html
title: datastructure/fenwicktree/StaticRangeInversionsQuery.cpp
---
