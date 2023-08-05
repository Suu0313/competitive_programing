---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/lc/point_set_range_composite.test.cpp
    title: test/verify/lc/point_set_range_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/segtree/SegmentTree.cpp\"\n\r\ntemplate<class\
    \ Monoid>\r\nstruct SegmentTree{\r\n  int n;\r\n  vector<Monoid> node;\r\n\r\n\
    \  SegmentTree() = default;\r\n  SegmentTree(int n): n(n), node(n * 2) {}\r\n\
    \  SegmentTree(int n, const Monoid &x): n(n), node(n * 2, x){ build(); }\r\n \
    \ template<class Iiter>\r\n  SegmentTree(Iiter first, Iiter last): SegmentTree(int(distance(first,\
    \ last))){\r\n    for(int i = 0; i < n; ++i, ++first) node[i + n] = *first;\r\n\
    \    build();\r\n  }\r\n  template<class Container>\r\n  SegmentTree(const Container\
    \ &c): SegmentTree(begin(c), end(c)) {}\r\n\r\n\r\n  void build(){\r\n    for(int\
    \ k = n - 1; k > 0; --k) node[k] = node[k << 1] + node[k << 1 | 1];\r\n  }\r\n\
    \r\n  void set(int k, const Monoid &x){ node[k + n] = x; }\r\n\r\n  void change(int\
    \ k, const Monoid &x){\r\n    k += n;\r\n    node[k] = x;\r\n    while(k >>= 1)\
    \ node[k] = node[k << 1] + node[k << 1 | 1];\r\n  }\r\n\r\n  void change(int l,\
    \ int r, const Monoid &x){\r\n    for(int k = l; k < r; k++) change(k, x);\r\n\
    \  }\r\n\r\n  template<typename F>\r\n  void update(int k, const F &f){\r\n  \
    \  change(k, f(node[k + n]));\r\n  }\r\n\r\n  template<typename F>\r\n  void update(int\
    \ l, int r, const F &f){\r\n    for(int k = l; k < r; k++) update(k, f);\r\n \
    \ }\r\n\r\n  const Monoid &operator[](int k) const { return node[k + n]; }\r\n\
    \r\n  Monoid query(int l, int r) const {\r\n    Monoid res_l{}, res_r{};\r\n \
    \   for(l += n, r += n; l < r; l >>= 1, r >>= 1){\r\n      if(l & 1) res_l +=\
    \ node[l++];\r\n      if(r & 1) res_r = node[--r] + res_r;\r\n    }\r\n    return\
    \ res_l += res_r;\r\n  }\r\n\r\n  template<typename C>\r\n  int max_right(int\
    \ l, const C &check){\r\n    if(l == n) return n;\r\n    Monoid x{};\r\n    l\
    \ += n;\r\n    int r = n * 2, h = 0;\r\n    for(; l < r; l >>= 1, r >>= 1, ++h){\r\
    \n      if(l & 1){\r\n        if(!check(x + node[l])){\r\n          while(l <\
    \ n){\r\n            l <<= 1;\r\n            if(check(x + node[l])) x += node[l++];\r\
    \n          }\r\n          return l - n;\r\n        }\r\n        x += node[l++];\r\
    \n      }\r\n      if(r & 1) --r;\r\n    }\r\n\r\n    while(r <<= 1, h--){\r\n\
    \      if(((r + 1) << h) <= n * 2) {\r\n        if(!check(x + node[r])){\r\n \
    \         while(r < n){\r\n            r <<= 1;\r\n            if(check(x + node[r]))\
    \ x += node[r++];\r\n          }\r\n          return r - n;\r\n        }\r\n \
    \       x += node[r++];\r\n      }\r\n    }\r\n\r\n    return n;\r\n  }\r\n\r\n\
    \  template<typename C>\r\n  int min_left(int r, const C &check){\r\n    if(r\
    \ == 0) return 0;\r\n    Monoid x{};\r\n    r += n;\r\n    int l = n, h = 0;\r\
    \n    for(; l < r; l >>= 1, r >>= 1, ++h){\r\n      if(l & 1) ++l;\r\n      if(r\
    \ & 1){\r\n        --r;\r\n        if(!check(node[r] + x)){\r\n          while(r\
    \ < n){\r\n            r = 2*r + 1;\r\n            if(check(node[r] + x)) x =\
    \ node[r--] + x;\r\n          }\r\n          return r - n + 1;\r\n        }\r\n\
    \        x = node[r] + x;\r\n      }\r\n    }\r\n\r\n    while(l <<= 1, h--){\r\
    \n      if(((l - 1) << h) >= n){\r\n        --l;\r\n        if(!check(node[l]\
    \ + x)){\r\n          while(l < n){\r\n            l = l * 2 + 1;\r\n        \
    \    if(check(node[l] + x)) x = node[l--] + x;\r\n          }\r\n          return\
    \ l - n + 1;\r\n        }\r\n        x = node[l] + x;\r\n      }\r\n    }\r\n\
    \    \r\n    return 0;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<class Monoid>\r\nstruct SegmentTree{\r\n  int\
    \ n;\r\n  vector<Monoid> node;\r\n\r\n  SegmentTree() = default;\r\n  SegmentTree(int\
    \ n): n(n), node(n * 2) {}\r\n  SegmentTree(int n, const Monoid &x): n(n), node(n\
    \ * 2, x){ build(); }\r\n  template<class Iiter>\r\n  SegmentTree(Iiter first,\
    \ Iiter last): SegmentTree(int(distance(first, last))){\r\n    for(int i = 0;\
    \ i < n; ++i, ++first) node[i + n] = *first;\r\n    build();\r\n  }\r\n  template<class\
    \ Container>\r\n  SegmentTree(const Container &c): SegmentTree(begin(c), end(c))\
    \ {}\r\n\r\n\r\n  void build(){\r\n    for(int k = n - 1; k > 0; --k) node[k]\
    \ = node[k << 1] + node[k << 1 | 1];\r\n  }\r\n\r\n  void set(int k, const Monoid\
    \ &x){ node[k + n] = x; }\r\n\r\n  void change(int k, const Monoid &x){\r\n  \
    \  k += n;\r\n    node[k] = x;\r\n    while(k >>= 1) node[k] = node[k << 1] +\
    \ node[k << 1 | 1];\r\n  }\r\n\r\n  void change(int l, int r, const Monoid &x){\r\
    \n    for(int k = l; k < r; k++) change(k, x);\r\n  }\r\n\r\n  template<typename\
    \ F>\r\n  void update(int k, const F &f){\r\n    change(k, f(node[k + n]));\r\n\
    \  }\r\n\r\n  template<typename F>\r\n  void update(int l, int r, const F &f){\r\
    \n    for(int k = l; k < r; k++) update(k, f);\r\n  }\r\n\r\n  const Monoid &operator[](int\
    \ k) const { return node[k + n]; }\r\n\r\n  Monoid query(int l, int r) const {\r\
    \n    Monoid res_l{}, res_r{};\r\n    for(l += n, r += n; l < r; l >>= 1, r >>=\
    \ 1){\r\n      if(l & 1) res_l += node[l++];\r\n      if(r & 1) res_r = node[--r]\
    \ + res_r;\r\n    }\r\n    return res_l += res_r;\r\n  }\r\n\r\n  template<typename\
    \ C>\r\n  int max_right(int l, const C &check){\r\n    if(l == n) return n;\r\n\
    \    Monoid x{};\r\n    l += n;\r\n    int r = n * 2, h = 0;\r\n    for(; l <\
    \ r; l >>= 1, r >>= 1, ++h){\r\n      if(l & 1){\r\n        if(!check(x + node[l])){\r\
    \n          while(l < n){\r\n            l <<= 1;\r\n            if(check(x +\
    \ node[l])) x += node[l++];\r\n          }\r\n          return l - n;\r\n    \
    \    }\r\n        x += node[l++];\r\n      }\r\n      if(r & 1) --r;\r\n    }\r\
    \n\r\n    while(r <<= 1, h--){\r\n      if(((r + 1) << h) <= n * 2) {\r\n    \
    \    if(!check(x + node[r])){\r\n          while(r < n){\r\n            r <<=\
    \ 1;\r\n            if(check(x + node[r])) x += node[r++];\r\n          }\r\n\
    \          return r - n;\r\n        }\r\n        x += node[r++];\r\n      }\r\n\
    \    }\r\n\r\n    return n;\r\n  }\r\n\r\n  template<typename C>\r\n  int min_left(int\
    \ r, const C &check){\r\n    if(r == 0) return 0;\r\n    Monoid x{};\r\n    r\
    \ += n;\r\n    int l = n, h = 0;\r\n    for(; l < r; l >>= 1, r >>= 1, ++h){\r\
    \n      if(l & 1) ++l;\r\n      if(r & 1){\r\n        --r;\r\n        if(!check(node[r]\
    \ + x)){\r\n          while(r < n){\r\n            r = 2*r + 1;\r\n          \
    \  if(check(node[r] + x)) x = node[r--] + x;\r\n          }\r\n          return\
    \ r - n + 1;\r\n        }\r\n        x = node[r] + x;\r\n      }\r\n    }\r\n\r\
    \n    while(l <<= 1, h--){\r\n      if(((l - 1) << h) >= n){\r\n        --l;\r\
    \n        if(!check(node[l] + x)){\r\n          while(l < n){\r\n            l\
    \ = l * 2 + 1;\r\n            if(check(node[l] + x)) x = node[l--] + x;\r\n  \
    \        }\r\n          return l - n + 1;\r\n        }\r\n        x = node[l]\
    \ + x;\r\n      }\r\n    }\r\n    \r\n    return 0;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/segtree/SegmentTree.cpp
  requiredBy: []
  timestamp: '2023-07-30 22:29:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/lc/point_set_range_composite.test.cpp
documentation_of: datastructure/segtree/SegmentTree.cpp
layout: document
title: Segment Tree
---

## 概要

非二冪非再帰一点更新区間取得セグメントツリー

以下の条件をみたす構造体 `Monoid` を乗せる

- デフォルトコンストラクタ `Monoid{}` が単位元
- `operator+`, `operator+=`, `opetator=` をもつ
- $(a + b) + c = a + (b + c)$

## 使い方

以下, $a + b$ を $O(1)$ で求められるとする

- `SegmentTree()`: デフォルトコンストラクタ. 要素を持たない空で構築する. $O(1)$
- `SegmentTree(int n)`: $n$ 個の `Monoid{}` で構築. $\Theta(n)$
- `SegmentTree(int n, const Monoid &x)`: $n$ 個の `x` で構築. $\Theta(n)$
- `SegmentTree(Iiter first, Iiter last)`: イレテータ範囲 `[first, last)` を要素としてコピーしてオブジェクトを構築. `distance(first, last)` $= n$ として $\Theta(n)$
- `SegmentTree(const Container &c)`: `SegmentTree(begin(c), end(c))` と等価
- ` void build()`: 現在セットされている値でセグ木を構築. $\Theta(n)$
- `void set(int k, const Monoid &x)`: $k$ 番目の値を `x` に変更, 伝播はさせない. $O(1)$
- `void change(int k, const Monoid &x)`: $k$ 番目の値を `x` に変更. $O(\log n)$
- `void change(int l, int r, const Monoid &x)`: $k \in [l, r)$ に対して `change(k, x)` を適用. $O((r - l)\log n)$
- `void update(int k, const F &f)`: `change(k, f(seg[k]))` と等価
- `void update(int l, int r, const F &f)`: $k \in [l, r)$ に対して `update(k, f)` を適用.
- `const Monoid &operator[](int k)`: $k$ 番目の値を取得. $O(1)$
- `Monoid query(int l, int r)`: $\sum _ {l \le k < r}$ `seg[k]` を取得. $O(\log n)$
- `int max_right(int l, const C &check)`: `check(query(l, r))` が `true` となる最大の `r` を取得. `check(Monoid{})` は `true` であること. $O(\log n)$
- `int min_left(int r, const C &check)`: `check(query(l, r))` が `true` となる最小の `l` を取得. `check(Monoid{})` は `true` であること. $O(\log n)$ (verify していない)
