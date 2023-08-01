---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/lc/range_affine_point_get.test.cpp
    title: test/verify/lc/range_affine_point_get.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/segtree/DualSegTree.cpp\"\n\r\ntemplate<class\
    \ Monoid>\r\nstruct DualSegTree{\r\n  int n, height;\r\n  vector<Monoid> lazy;\r\
    \n\r\n  DualSegTree() = default;\r\n  DualSegTree(int n): n(n), height(ilog2(n)),\
    \ lazy(n * 2) {}\r\n  DualSegTree(int n, const Monoid &x): n(n), height(ilog2(n)),\
    \ lazy(n * 2) {\r\n    for(int i = 0; i < n; ++i) lazy[i + n] = x;\r\n  }\r\n\
    \  template<typename Iiter>\r\n  DualSegTree(Iiter first, Iiter last): DualSegTree(int(distance(first,\
    \ last))) {\r\n    for(int i = 0; i < n; ++i, ++first) lazy[i + n] = *first;\r\
    \n  }\r\n  template<class Container>\r\n  DualSegTree(const Container &c): DualSegTree(begin(c),\
    \ end(c)) {}\r\n\r\n\r\n  void update(int k, const Monoid &x){\r\n    if(x ==\
    \ Monoid{}) return;\r\n    resolve(k += n);\r\n    lazy[k] += x;\r\n  }\r\n\r\n\
    \  void update(int l, int r, const Monoid &x){\r\n    if(l >= r || x == Monoid{})\
    \ return;\r\n    l += n; r += n;\r\n    resolve(l); resolve(r - 1);\r\n\r\n  \
    \  for(; l < r; l >>= 1, r >>= 1){\r\n      if(l & 1) lazy[l++] += x;\r\n    \
    \  if(r & 1) lazy[--r] += x;\r\n    }\r\n  }\r\n\r\n  const Monoid &operator[](int\
    \ k){\r\n    resolve(k += n);\r\n    return lazy[k];\r\n  }\r\n\r\nprivate:\r\n\
    \  int ilog2(int m){ return 31 - __builtin_clz(m); }\r\n\r\n  void resolve(int\
    \ k){\r\n    Monoid id{};\r\n    for(int h = height + 2; h > 0; --h){\r\n    \
    \  int i = k >> h;\r\n      if(lazy[i] != id){\r\n        lazy[i << 1] += lazy[i];\r\
    \n        lazy[i << 1 | 1] += lazy[i];\r\n        lazy[i] = id;\r\n      }\r\n\
    \    }\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<class Monoid>\r\nstruct DualSegTree{\r\n  int\
    \ n, height;\r\n  vector<Monoid> lazy;\r\n\r\n  DualSegTree() = default;\r\n \
    \ DualSegTree(int n): n(n), height(ilog2(n)), lazy(n * 2) {}\r\n  DualSegTree(int\
    \ n, const Monoid &x): n(n), height(ilog2(n)), lazy(n * 2) {\r\n    for(int i\
    \ = 0; i < n; ++i) lazy[i + n] = x;\r\n  }\r\n  template<typename Iiter>\r\n \
    \ DualSegTree(Iiter first, Iiter last): DualSegTree(int(distance(first, last)))\
    \ {\r\n    for(int i = 0; i < n; ++i, ++first) lazy[i + n] = *first;\r\n  }\r\n\
    \  template<class Container>\r\n  DualSegTree(const Container &c): DualSegTree(begin(c),\
    \ end(c)) {}\r\n\r\n\r\n  void update(int k, const Monoid &x){\r\n    if(x ==\
    \ Monoid{}) return;\r\n    resolve(k += n);\r\n    lazy[k] += x;\r\n  }\r\n\r\n\
    \  void update(int l, int r, const Monoid &x){\r\n    if(l >= r || x == Monoid{})\
    \ return;\r\n    l += n; r += n;\r\n    resolve(l); resolve(r - 1);\r\n\r\n  \
    \  for(; l < r; l >>= 1, r >>= 1){\r\n      if(l & 1) lazy[l++] += x;\r\n    \
    \  if(r & 1) lazy[--r] += x;\r\n    }\r\n  }\r\n\r\n  const Monoid &operator[](int\
    \ k){\r\n    resolve(k += n);\r\n    return lazy[k];\r\n  }\r\n\r\nprivate:\r\n\
    \  int ilog2(int m){ return 31 - __builtin_clz(m); }\r\n\r\n  void resolve(int\
    \ k){\r\n    Monoid id{};\r\n    for(int h = height + 2; h > 0; --h){\r\n    \
    \  int i = k >> h;\r\n      if(lazy[i] != id){\r\n        lazy[i << 1] += lazy[i];\r\
    \n        lazy[i << 1 | 1] += lazy[i];\r\n        lazy[i] = id;\r\n      }\r\n\
    \    }\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/segtree/DualSegTree.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/lc/range_affine_point_get.test.cpp
documentation_of: datastructure/segtree/DualSegTree.cpp
layout: document
redirect_from:
- /library/datastructure/segtree/DualSegTree.cpp
- /library/datastructure/segtree/DualSegTree.cpp.html
title: datastructure/segtree/DualSegTree.cpp
---
