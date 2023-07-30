---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: datastructure/segtree/DynamicSegTree.cpp
    title: datastructure/segtree/DynamicSegTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/segtree/Dynamic2DSegTree.cpp\"\n\r\n#line\
    \ 2 \"datastructure/segtree/DynamicSegTree.cpp\"\n\r\ntemplate<typename T>\r\n\
    struct DynamicSegTree{\r\n\r\n  using OP = function<T(T,T)>;\r\n  uint64_t n,\
    \ n0;\r\n  T id;\r\n  OP op;\r\n\r\n  DynamicSegTree() {}\r\n  DynamicSegTree(uint64_t\
    \ n_, const T &id, const OP &op) : n(1), n0(n_), id(id),op(op){\r\n    while(n\
    \ < n_) n<<=1;\r\n  }\r\n\r\n  void change(uint64_t k, const T &x){ root = change(root,\
    \ k, x, 0, n); }\r\n  T query(uint64_t l, uint64_t r) const { return query(root,\
    \ l, r, 0, n); }\r\n  T all_query() const { return query(0, n); }\r\n  T at(uint64_t\
    \ k) const { return query(k, k+1); }\r\n\r\nprivate:\r\n\r\n  struct Node{\r\n\
    \    T val;\r\n    Node *l, *r;\r\n    Node(const T &v): val(v), l(nullptr), r(nullptr)\
    \ {}\r\n  } *root = nullptr;\r\n  using np = Node*;\r\n\r\n  T val(np t) const\
    \ { return !t ? id : t->val; }\r\n\r\n  np change(np t, uint64_t k, const T &x,\
    \ uint64_t l, uint64_t r){\r\n    if(!t) t = new Node(id);\r\n    if(l+1==r){\
    \ t->val = x; return t; }\r\n\r\n    uint64_t m = l + ((r-l) >> 1);\r\n    if(k\
    \ < m) t->l = change(t->l, k, x, l, m);\r\n    else t->r = change(t->r, k, x,\
    \ m, r);\r\n\r\n    t->val = op(val(t->l), val(t->r));\r\n    return t;\r\n  }\r\
    \n\r\n  T query(np t, uint64_t ql, uint64_t qr, uint64_t l, uint64_t r) const\
    \ {\r\n    if(!t || r<=ql || qr<=l) return id;\r\n    if(ql<=l && r<=qr) return\
    \ t->val;\r\n\r\n    uint64_t m = l + ((r-l) >> 1);\r\n    return op(query(t->l,\
    \ ql, qr, l, m), query(t->r, ql, qr, m, r));\r\n  }\r\n};\r\n#line 4 \"datastructure/segtree/Dynamic2DSegTree.cpp\"\
    \n\r\ntemplate<typename T>\r\nstruct Dynamic2DSegTree{\r\n  using OP = function<T(T,T)>;\r\
    \n  uint64_t h, h0, w, w0;\r\n  const T id;\r\n  const OP op;\r\n  vector<DynamicSegTree<T>>\
    \ node;\r\n\r\n  Dynamic2DSegTree() {}\r\n  Dynamic2DSegTree(uint64_t h0, uint64_t\
    \ w0, const T &id, const OP &op)\r\n    : h(1), h0(h0), w(1), w0(w0), id(id),\
    \ op(op){\r\n    while(h < h0) h <<= 1;\r\n    while(w < w0) w <<= 1;\r\n    node.assign(2*h,\
    \ {w, id, op});\r\n  }\r\n\r\n  void add(uint64_t i, uint64_t j, const T &x){\r\
    \n    i += h;\r\n    node[i].change(j, op(node[i].at(j), x));\r\n    while(i >>=\
    \ 1){\r\n      node[i].change(j, op(node[i].at(j), x));\r\n    }\r\n  }\r\n\r\n\
    \  T query(uint64_t l, uint64_t r, uint64_t d, uint64_t u){\r\n    T L = id, R\
    \ = id;\r\n    for(l += h, r += h; l < r; l >>= 1, r >>= 1) {\r\n      if(l &\
    \ 1) L = op(L, node[l++].query(d, u));\r\n      if(r & 1) R = op(node[--r].query(d,\
    \ u), R);\r\n    }\r\n    return op(L, R);\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include \"./DynamicSegTree.cpp\"\r\n\r\ntemplate<typename\
    \ T>\r\nstruct Dynamic2DSegTree{\r\n  using OP = function<T(T,T)>;\r\n  uint64_t\
    \ h, h0, w, w0;\r\n  const T id;\r\n  const OP op;\r\n  vector<DynamicSegTree<T>>\
    \ node;\r\n\r\n  Dynamic2DSegTree() {}\r\n  Dynamic2DSegTree(uint64_t h0, uint64_t\
    \ w0, const T &id, const OP &op)\r\n    : h(1), h0(h0), w(1), w0(w0), id(id),\
    \ op(op){\r\n    while(h < h0) h <<= 1;\r\n    while(w < w0) w <<= 1;\r\n    node.assign(2*h,\
    \ {w, id, op});\r\n  }\r\n\r\n  void add(uint64_t i, uint64_t j, const T &x){\r\
    \n    i += h;\r\n    node[i].change(j, op(node[i].at(j), x));\r\n    while(i >>=\
    \ 1){\r\n      node[i].change(j, op(node[i].at(j), x));\r\n    }\r\n  }\r\n\r\n\
    \  T query(uint64_t l, uint64_t r, uint64_t d, uint64_t u){\r\n    T L = id, R\
    \ = id;\r\n    for(l += h, r += h; l < r; l >>= 1, r >>= 1) {\r\n      if(l &\
    \ 1) L = op(L, node[l++].query(d, u));\r\n      if(r & 1) R = op(node[--r].query(d,\
    \ u), R);\r\n    }\r\n    return op(L, R);\r\n  }\r\n};\r\n"
  dependsOn:
  - datastructure/segtree/DynamicSegTree.cpp
  isVerificationFile: false
  path: datastructure/segtree/Dynamic2DSegTree.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/segtree/Dynamic2DSegTree.cpp
layout: document
redirect_from:
- /library/datastructure/segtree/Dynamic2DSegTree.cpp
- /library/datastructure/segtree/Dynamic2DSegTree.cpp.html
title: datastructure/segtree/Dynamic2DSegTree.cpp
---
