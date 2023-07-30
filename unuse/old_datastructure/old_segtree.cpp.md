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
  bundledCode: "#line 1 \"unuse/old_datastructure/old_segtree.cpp\"\ntemplate<typename\
    \ T, typename OP>\r\nstruct SegmentTree{\r\n\r\n  int n, n0;\r\n  vector<T> node;\r\
    \n  T id;\r\n  const OP op;\r\n\r\n  SegmentTree(int n_, const T &id, const OP\
    \ &op) : id(id), op(op){\r\n    n = 1;\r\n    n0 = n_;\r\n    while(n < n_) n\
    \ <<= 1;\r\n    node.assign(2*n, id);\r\n  }\r\n\r\n  void init(int n_){\r\n \
    \   n = 1;\r\n    n0 = n_;\r\n    while(n < n_) n <<= 1;\r\n    node.assign(2*n,\
    \ id);\r\n  }\r\n\r\n  void set(int k, const T &x){\r\n    node.at(k+n) = x;\r\
    \n  }\r\n\r\n  void build(){\r\n    for(int k = n - 1; k > 0; k--){\r\n      node.at(k)\
    \ = op(node.at(2*k),node.at(2*k+1));\r\n    }\r\n  }\r\n\r\n  void build(const\
    \ vector<T> &v){\r\n    assert((int)v.size() == n0);\r\n    for(int k = 0; k <\
    \ n0; k++) node[k+n] = v[k];\r\n    build();\r\n  }\r\n\r\n  void change(int k,\
    \ const T &x){\r\n    k += n;\r\n    node.at(k) = x;\r\n    while(k >>= 1){\r\n\
    \      node.at(k) = op(node.at(2*k), node.at(2*k+1));\r\n    }\r\n  }\r\n\r\n\
    \  void change(int l, int r, const T &x){\r\n    for(int k = l; k < r; k++) change(k,x);\r\
    \n  }\r\n\r\n  template<typename C>\r\n  void update(int k, const C &c){\r\n \
    \   T x = node.at(k+n);\r\n    T x2 = c(x);\r\n    change(k, x2);\r\n  }\r\n\r\
    \n  template<typename C>\r\n  void update(int l, int r, const C &c){\r\n    for(int\
    \ k = l; k < r; k++) update(k,c);\r\n  }\r\n\r\n  T at(int k) const { return node.at(k+n);\
    \ }\r\n  T operator[](int k) const { return node.at(k+n); }\r\n\r\n  void add(int\
    \ k, const T &a){\r\n    T x = at(k)+a;\r\n    change(k,x);\r\n  }\r\n\r\n  void\
    \ add(int l, int r, const T &a){\r\n    for(int k = l; k < r; k++) add(k,a);\r\
    \n  }\r\n\r\n  T query(int a, int b){\r\n    if(a==0 && b==n0) return all_query();\r\
    \n    T L = id, R = id;\r\n    for(a += n, b += n; a < b; a >>= 1, b >>= 1) {\r\
    \n      if(a & 1) L = op(L, node.at(a++));\r\n      if(b & 1) R = op(node.at(--b),\
    \ R);\r\n    }\r\n    return op(L, R);\r\n  }\r\n\r\n  T all_query() const { return\
    \ node.at(1); }\r\n\r\n  template<typename C>\r\n  int max_right(int l, const\
    \ C &check){\r\n    if(l == n0) return n0;\r\n    l += n;\r\n    T tm = id;\r\n\
    \    do{\r\n      while(l%2 == 0) l >>= 1;\r\n      if(!check(op(tm, node.at(l)))){\r\
    \n        while(l < n){\r\n          l *= 2;\r\n          if(check(op(tm, node.at(l)))){\r\
    \n            tm = op(tm, node.at(l));\r\n            l++;\r\n          }\r\n\
    \        }\r\n        return l - n;\r\n      }\r\n      tm = op(tm, node.at(l));\r\
    \n      l++;\r\n    }while((l&-l) != l);\r\n    return n0;\r\n  }\r\n\r\n  template<typename\
    \ C>\r\n  int min_left(int r, const C &check){\r\n    if(r == 0) return 0;\r\n\
    \    r += n;\r\n    T tm = id;\r\n    do{\r\n      r--;\r\n      while(r>1 &&\
    \ (r%2)) r >>= 1;\r\n      if(!check(op(node.at(r), tm))){\r\n        while(r\
    \ < n){\r\n          r = 2*r + 1;\r\n          if(check(op(node.at(r), tm))){\r\
    \n            tm = op(node.at(r), tm);\r\n            r--;\r\n          }\r\n\
    \        }\r\n        return r + 1 - n;\r\n      }\r\n      tm = op(node.at(r),\
    \ tm);\r\n    }while((r&-r) != r);\r\n    return 0;\r\n  }\r\n};\r\n\r\ntemplate<typename\
    \ T, typename OP>\r\nSegmentTree<T,OP> get_segtree(int n, const T &id, const OP\
    \ &op){\r\n  return {n, id, op};\r\n}\r\n\r\ntemplate<typename T, typename OP>\r\
    \nSegmentTree<T,OP> get_segtree(int n, const T &id, const OP &op, const vector<T>\
    \ &v){\r\n  SegmentTree<T,OP> seg(n, id, op);\r\n  seg.build(v);\r\n  return seg;\r\
    \n}\r\n"
  code: "template<typename T, typename OP>\r\nstruct SegmentTree{\r\n\r\n  int n,\
    \ n0;\r\n  vector<T> node;\r\n  T id;\r\n  const OP op;\r\n\r\n  SegmentTree(int\
    \ n_, const T &id, const OP &op) : id(id), op(op){\r\n    n = 1;\r\n    n0 = n_;\r\
    \n    while(n < n_) n <<= 1;\r\n    node.assign(2*n, id);\r\n  }\r\n\r\n  void\
    \ init(int n_){\r\n    n = 1;\r\n    n0 = n_;\r\n    while(n < n_) n <<= 1;\r\n\
    \    node.assign(2*n, id);\r\n  }\r\n\r\n  void set(int k, const T &x){\r\n  \
    \  node.at(k+n) = x;\r\n  }\r\n\r\n  void build(){\r\n    for(int k = n - 1; k\
    \ > 0; k--){\r\n      node.at(k) = op(node.at(2*k),node.at(2*k+1));\r\n    }\r\
    \n  }\r\n\r\n  void build(const vector<T> &v){\r\n    assert((int)v.size() ==\
    \ n0);\r\n    for(int k = 0; k < n0; k++) node[k+n] = v[k];\r\n    build();\r\n\
    \  }\r\n\r\n  void change(int k, const T &x){\r\n    k += n;\r\n    node.at(k)\
    \ = x;\r\n    while(k >>= 1){\r\n      node.at(k) = op(node.at(2*k), node.at(2*k+1));\r\
    \n    }\r\n  }\r\n\r\n  void change(int l, int r, const T &x){\r\n    for(int\
    \ k = l; k < r; k++) change(k,x);\r\n  }\r\n\r\n  template<typename C>\r\n  void\
    \ update(int k, const C &c){\r\n    T x = node.at(k+n);\r\n    T x2 = c(x);\r\n\
    \    change(k, x2);\r\n  }\r\n\r\n  template<typename C>\r\n  void update(int\
    \ l, int r, const C &c){\r\n    for(int k = l; k < r; k++) update(k,c);\r\n  }\r\
    \n\r\n  T at(int k) const { return node.at(k+n); }\r\n  T operator[](int k) const\
    \ { return node.at(k+n); }\r\n\r\n  void add(int k, const T &a){\r\n    T x =\
    \ at(k)+a;\r\n    change(k,x);\r\n  }\r\n\r\n  void add(int l, int r, const T\
    \ &a){\r\n    for(int k = l; k < r; k++) add(k,a);\r\n  }\r\n\r\n  T query(int\
    \ a, int b){\r\n    if(a==0 && b==n0) return all_query();\r\n    T L = id, R =\
    \ id;\r\n    for(a += n, b += n; a < b; a >>= 1, b >>= 1) {\r\n      if(a & 1)\
    \ L = op(L, node.at(a++));\r\n      if(b & 1) R = op(node.at(--b), R);\r\n   \
    \ }\r\n    return op(L, R);\r\n  }\r\n\r\n  T all_query() const { return node.at(1);\
    \ }\r\n\r\n  template<typename C>\r\n  int max_right(int l, const C &check){\r\
    \n    if(l == n0) return n0;\r\n    l += n;\r\n    T tm = id;\r\n    do{\r\n \
    \     while(l%2 == 0) l >>= 1;\r\n      if(!check(op(tm, node.at(l)))){\r\n  \
    \      while(l < n){\r\n          l *= 2;\r\n          if(check(op(tm, node.at(l)))){\r\
    \n            tm = op(tm, node.at(l));\r\n            l++;\r\n          }\r\n\
    \        }\r\n        return l - n;\r\n      }\r\n      tm = op(tm, node.at(l));\r\
    \n      l++;\r\n    }while((l&-l) != l);\r\n    return n0;\r\n  }\r\n\r\n  template<typename\
    \ C>\r\n  int min_left(int r, const C &check){\r\n    if(r == 0) return 0;\r\n\
    \    r += n;\r\n    T tm = id;\r\n    do{\r\n      r--;\r\n      while(r>1 &&\
    \ (r%2)) r >>= 1;\r\n      if(!check(op(node.at(r), tm))){\r\n        while(r\
    \ < n){\r\n          r = 2*r + 1;\r\n          if(check(op(node.at(r), tm))){\r\
    \n            tm = op(node.at(r), tm);\r\n            r--;\r\n          }\r\n\
    \        }\r\n        return r + 1 - n;\r\n      }\r\n      tm = op(node.at(r),\
    \ tm);\r\n    }while((r&-r) != r);\r\n    return 0;\r\n  }\r\n};\r\n\r\ntemplate<typename\
    \ T, typename OP>\r\nSegmentTree<T,OP> get_segtree(int n, const T &id, const OP\
    \ &op){\r\n  return {n, id, op};\r\n}\r\n\r\ntemplate<typename T, typename OP>\r\
    \nSegmentTree<T,OP> get_segtree(int n, const T &id, const OP &op, const vector<T>\
    \ &v){\r\n  SegmentTree<T,OP> seg(n, id, op);\r\n  seg.build(v);\r\n  return seg;\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: unuse/old_datastructure/old_segtree.cpp
  requiredBy: []
  timestamp: '2022-07-22 00:06:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unuse/old_datastructure/old_segtree.cpp
layout: document
redirect_from:
- /library/unuse/old_datastructure/old_segtree.cpp
- /library/unuse/old_datastructure/old_segtree.cpp.html
title: unuse/old_datastructure/old_segtree.cpp
---
