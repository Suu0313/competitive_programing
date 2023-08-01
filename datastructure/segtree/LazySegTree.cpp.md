---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/lc/range_affine_range_sum.test.cpp
    title: test/verify/lc/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/segtree/LazySegTree.cpp\"\n\r\n\r\ntemplate<class\
    \ Operation>\r\nstruct LazySegTree{\r\n  using Monoid = typename Operation::Monoid;\r\
    \n  using OperatorMonoid = typename Operation::OperatorMonoid;\r\n\r\n  int n,\
    \ height;\r\n  vector<Monoid> node;\r\n  vector<OperatorMonoid> lazy;\r\n  vector<int>\
    \ sz;\r\n\r\n\r\n  LazySegTree() = default;\r\n  LazySegTree(int n): n(n), height(ilog2(n)),\
    \ node(n * 2), lazy(n) {}\r\n  LazySegTree(int n, const Monoid &x): n(n), height(ilog2(n)),\
    \ node(n * 2, x), lazy(n) { build(); }\r\n  template<typename Iiter>\r\n  LazySegTree(Iiter\
    \ first, Iiter last): LazySegTree(int(distance(first, last))) {\r\n    for(int\
    \ i = 0; i < n; ++i, ++first) node[i + n] = *first;\r\n    build();\r\n  }\r\n\
    \  template<class Container>\r\n  LazySegTree(const Container &c): LazySegTree(begin(c),\
    \ end(c)) {}\r\n\r\n\r\n  void build(){\r\n    for(int k = n-1; k >= 0; k--) propagate(k);\r\
    \n  }\r\n\r\n  void set(int k, const Monoid &x){ node[k + n] = x; }\r\n\r\n  void\
    \ change(int k, const Monoid &x){\r\n    k += n;\r\n    resolve(k);\r\n    node[k]\
    \ = x;\r\n    build(k);\r\n  }\r\n\r\n  void update(int k, const OperatorMonoid\
    \ &x){\r\n    k += n;\r\n    resolve(k); apply(k, x); build(k);\r\n  }\r\n\r\n\
    \  void update(int l, int r, const OperatorMonoid &x){\r\n    if(l == r) return;\r\
    \n    l += n; r += n;\r\n    int dl = l, dr = r;\r\n    resolve(dl); resolve(dr\
    \ - 1);\r\n\r\n    for(; l < r; l >>= 1, r >>= 1){\r\n      if(l & 1) apply(l++,\
    \ x);\r\n      if(r & 1) apply(--r, x);\r\n    }\r\n\r\n    build(dl); build(dr\
    \ - 1);\r\n  }\r\n\r\n  Monoid operator[](int k){\r\n    resolve(k += n);\r\n\
    \    return node[k];\r\n  }\r\n\r\n  Monoid query(int l, int r){\r\n    Monoid\
    \ res_l{}, res_r{};\r\n    if(l == r) return res_l;\r\n    l += n; r += n;\r\n\
    \    resolve(l); resolve(r - 1);\r\n\r\n    for(; l < r; l >>= 1, r >>= 1){\r\n\
    \      if(l & 1) res_l += node[l++];\r\n      if(r & 1) res_r = node[--r] + res_r;\r\
    \n    }\r\n    return res_l += res_r;\r\n  }\r\n\r\n  template<typename C>\r\n\
    \  int max_right(int l, const C &check){\r\n    if(l == n) return n;\r\n    l\
    \ += n;\r\n    resolve(l);\r\n    Monoid x{};\r\n    int r = n * 2, h = 0;\r\n\
    \    for(; l < r; l >>= 1, r >>= 1, ++h){\r\n      if(l & 1){\r\n        if(!check(x\
    \ + node[l])){\r\n          while(l < n){\r\n            l <<= 1;\r\n        \
    \    if(check(x + node[l])) x += node[l++];\r\n          }\r\n          return\
    \ l - n;\r\n        }\r\n        x += node[l++];\r\n      }\r\n      if(r & 1)\
    \ --r;\r\n    }\r\n\r\n    while(r <<= 1, h--){\r\n      if(((r + 1) << h) <=\
    \ n * 2) {\r\n        if(!check(x + node[r])){\r\n          while(r < n){\r\n\
    \            r <<= 1;\r\n            if(check(x + node[r])) x += node[r++];\r\n\
    \          }\r\n          return r - n;\r\n        }\r\n        x += node[r++];\r\
    \n      }\r\n    }\r\n\r\n    return n;\r\n  }\r\n\r\n  template<typename C>\r\
    \n  int min_left(int r, const C &check){\r\n    if(r == 0) return 0;\r\n    r\
    \ += n;\r\n    resolve(r - 1);\r\n    Monoid x{};\r\n    int l = n, h = 0;\r\n\
    \    for(; l < r; l >>= 1, r >>= 1, ++h){\r\n      if(l & 1) ++l;\r\n      if(r\
    \ & 1){\r\n        --r;\r\n        if(!check(node[r] + x)){\r\n          while(r\
    \ < n){\r\n            r = 2*r + 1;\r\n            if(check(node[r] + x)) x =\
    \ node[r--] + x;\r\n          }\r\n          return r - n + 1;\r\n        }\r\n\
    \        x = node[r] + x;\r\n      }\r\n    }\r\n\r\n    while(l <<= 1, h--){\r\
    \n      if(((l - 1) << h) >= n){\r\n        --l;\r\n        if(!check(node[l]\
    \ + x)){\r\n          while(l < n){\r\n            l = l * 2 + 1;\r\n        \
    \    if(check(node[l] + x)) x = node[l--] + x;\r\n          }\r\n          return\
    \ l - n + 1;\r\n        }\r\n        x = node[l] + x;\r\n      }\r\n    }\r\n\
    \    return 0;\r\n  }\r\n\r\nprivate:\r\n  int ilog2(int m){ return 31 - __builtin_clz(m);\
    \ }\r\n  void propagate(int k){ node[k] = node[k<<1] + node[k<<1 | 1]; }\r\n \
    \ void build(int k){\r\n    while(k){\r\n      k >>= 1;\r\n      propagate(k);\r\
    \n      Operation::act(node[k], lazy[k]);\r\n    }\r\n  }\r\n  void apply(int\
    \ k, const OperatorMonoid &x){\r\n    Operation::act(node[k], x);\r\n    if(k\
    \ < n) lazy[k] += x;\r\n  }\r\n  void resolve(int k){\r\n    OperatorMonoid id{};\r\
    \n    for(int h = height + 2; h > 0; --h){\r\n      int i = k >> h;\r\n      if(lazy[i]\
    \ != id){\r\n        apply(i << 1, lazy[i]);\r\n        apply(i << 1 | 1, lazy[i]);\r\
    \n        lazy[i] = id;\r\n      }\r\n    }\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n\r\ntemplate<class Operation>\r\nstruct LazySegTree{\r\
    \n  using Monoid = typename Operation::Monoid;\r\n  using OperatorMonoid = typename\
    \ Operation::OperatorMonoid;\r\n\r\n  int n, height;\r\n  vector<Monoid> node;\r\
    \n  vector<OperatorMonoid> lazy;\r\n  vector<int> sz;\r\n\r\n\r\n  LazySegTree()\
    \ = default;\r\n  LazySegTree(int n): n(n), height(ilog2(n)), node(n * 2), lazy(n)\
    \ {}\r\n  LazySegTree(int n, const Monoid &x): n(n), height(ilog2(n)), node(n\
    \ * 2, x), lazy(n) { build(); }\r\n  template<typename Iiter>\r\n  LazySegTree(Iiter\
    \ first, Iiter last): LazySegTree(int(distance(first, last))) {\r\n    for(int\
    \ i = 0; i < n; ++i, ++first) node[i + n] = *first;\r\n    build();\r\n  }\r\n\
    \  template<class Container>\r\n  LazySegTree(const Container &c): LazySegTree(begin(c),\
    \ end(c)) {}\r\n\r\n\r\n  void build(){\r\n    for(int k = n-1; k >= 0; k--) propagate(k);\r\
    \n  }\r\n\r\n  void set(int k, const Monoid &x){ node[k + n] = x; }\r\n\r\n  void\
    \ change(int k, const Monoid &x){\r\n    k += n;\r\n    resolve(k);\r\n    node[k]\
    \ = x;\r\n    build(k);\r\n  }\r\n\r\n  void update(int k, const OperatorMonoid\
    \ &x){\r\n    k += n;\r\n    resolve(k); apply(k, x); build(k);\r\n  }\r\n\r\n\
    \  void update(int l, int r, const OperatorMonoid &x){\r\n    if(l == r) return;\r\
    \n    l += n; r += n;\r\n    int dl = l, dr = r;\r\n    resolve(dl); resolve(dr\
    \ - 1);\r\n\r\n    for(; l < r; l >>= 1, r >>= 1){\r\n      if(l & 1) apply(l++,\
    \ x);\r\n      if(r & 1) apply(--r, x);\r\n    }\r\n\r\n    build(dl); build(dr\
    \ - 1);\r\n  }\r\n\r\n  Monoid operator[](int k){\r\n    resolve(k += n);\r\n\
    \    return node[k];\r\n  }\r\n\r\n  Monoid query(int l, int r){\r\n    Monoid\
    \ res_l{}, res_r{};\r\n    if(l == r) return res_l;\r\n    l += n; r += n;\r\n\
    \    resolve(l); resolve(r - 1);\r\n\r\n    for(; l < r; l >>= 1, r >>= 1){\r\n\
    \      if(l & 1) res_l += node[l++];\r\n      if(r & 1) res_r = node[--r] + res_r;\r\
    \n    }\r\n    return res_l += res_r;\r\n  }\r\n\r\n  template<typename C>\r\n\
    \  int max_right(int l, const C &check){\r\n    if(l == n) return n;\r\n    l\
    \ += n;\r\n    resolve(l);\r\n    Monoid x{};\r\n    int r = n * 2, h = 0;\r\n\
    \    for(; l < r; l >>= 1, r >>= 1, ++h){\r\n      if(l & 1){\r\n        if(!check(x\
    \ + node[l])){\r\n          while(l < n){\r\n            l <<= 1;\r\n        \
    \    if(check(x + node[l])) x += node[l++];\r\n          }\r\n          return\
    \ l - n;\r\n        }\r\n        x += node[l++];\r\n      }\r\n      if(r & 1)\
    \ --r;\r\n    }\r\n\r\n    while(r <<= 1, h--){\r\n      if(((r + 1) << h) <=\
    \ n * 2) {\r\n        if(!check(x + node[r])){\r\n          while(r < n){\r\n\
    \            r <<= 1;\r\n            if(check(x + node[r])) x += node[r++];\r\n\
    \          }\r\n          return r - n;\r\n        }\r\n        x += node[r++];\r\
    \n      }\r\n    }\r\n\r\n    return n;\r\n  }\r\n\r\n  template<typename C>\r\
    \n  int min_left(int r, const C &check){\r\n    if(r == 0) return 0;\r\n    r\
    \ += n;\r\n    resolve(r - 1);\r\n    Monoid x{};\r\n    int l = n, h = 0;\r\n\
    \    for(; l < r; l >>= 1, r >>= 1, ++h){\r\n      if(l & 1) ++l;\r\n      if(r\
    \ & 1){\r\n        --r;\r\n        if(!check(node[r] + x)){\r\n          while(r\
    \ < n){\r\n            r = 2*r + 1;\r\n            if(check(node[r] + x)) x =\
    \ node[r--] + x;\r\n          }\r\n          return r - n + 1;\r\n        }\r\n\
    \        x = node[r] + x;\r\n      }\r\n    }\r\n\r\n    while(l <<= 1, h--){\r\
    \n      if(((l - 1) << h) >= n){\r\n        --l;\r\n        if(!check(node[l]\
    \ + x)){\r\n          while(l < n){\r\n            l = l * 2 + 1;\r\n        \
    \    if(check(node[l] + x)) x = node[l--] + x;\r\n          }\r\n          return\
    \ l - n + 1;\r\n        }\r\n        x = node[l] + x;\r\n      }\r\n    }\r\n\
    \    return 0;\r\n  }\r\n\r\nprivate:\r\n  int ilog2(int m){ return 31 - __builtin_clz(m);\
    \ }\r\n  void propagate(int k){ node[k] = node[k<<1] + node[k<<1 | 1]; }\r\n \
    \ void build(int k){\r\n    while(k){\r\n      k >>= 1;\r\n      propagate(k);\r\
    \n      Operation::act(node[k], lazy[k]);\r\n    }\r\n  }\r\n  void apply(int\
    \ k, const OperatorMonoid &x){\r\n    Operation::act(node[k], x);\r\n    if(k\
    \ < n) lazy[k] += x;\r\n  }\r\n  void resolve(int k){\r\n    OperatorMonoid id{};\r\
    \n    for(int h = height + 2; h > 0; --h){\r\n      int i = k >> h;\r\n      if(lazy[i]\
    \ != id){\r\n        apply(i << 1, lazy[i]);\r\n        apply(i << 1 | 1, lazy[i]);\r\
    \n        lazy[i] = id;\r\n      }\r\n    }\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/segtree/LazySegTree.cpp
  requiredBy: []
  timestamp: '2023-03-24 00:46:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/lc/range_affine_range_sum.test.cpp
documentation_of: datastructure/segtree/LazySegTree.cpp
layout: document
redirect_from:
- /library/datastructure/segtree/LazySegTree.cpp
- /library/datastructure/segtree/LazySegTree.cpp.html
title: datastructure/segtree/LazySegTree.cpp
---
