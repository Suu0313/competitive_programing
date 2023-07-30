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
  bundledCode: "#line 2 \"datastructure/segtree/PersistentSegmentTree.cpp\"\n\r\n\r\
    \ntemplate<typename T>\r\nstruct PersistentSegmentTree{\r\n  using OP = function<T(T,T)>;\r\
    \n  int n, n0;\r\n  const T id;\r\n  const OP op;\r\n  struct Node{\r\n    T val;\r\
    \n    Node *l, *r;\r\n    Node(const T &val): val(val), l(nullptr), r(nullptr)\
    \ {}\r\n  };\r\n  using Np = Node*;\r\n\r\n  PersistentSegmentTree(int n_, const\
    \ T &id, const OP &op) : n(1), n0(n_), id(id),op(op){\r\n    while(n < n_) n<<=1;\r\
    \n  }\r\n\r\n  Np build(){ return build(vector<T>{}); }\r\n\r\n  Np build(const\
    \ vector<T> &v){ return build(0, n, v); }\r\n\r\n  Np update(Np root, int k, const\
    \ T &x){ return update(root, k, x, 0, n); }\r\n\r\n  T query(Np root, int l, int\
    \ r){ return query(root, l, r, 0, n); }\r\n\r\nprivate:\r\n\r\n  T val(Np t) const\
    \ { return !t ? id : t->val; }\r\n\r\n  Np merge(Np l, Np r){\r\n    Np t = new\
    \ Node(op(val(l), val(r)));\r\n    t->l = l; t->r = r;\r\n    return t;\r\n  }\r\
    \n\r\n  Np build(int l, int r, const vector<T> &v){\r\n    if(l+1 == r) return\
    \ new Node(l<int(v.size()) ? v[l] : id);\r\n    int m = l + ((r-l)>>1);\r\n  \
    \  return merge(build(l, m, v), build(m, r, v));\r\n  }\r\n\r\n  Np update(Np\
    \ t, int k, const T &x, int l, int r){\r\n    if(k < l || r <= k) return t;\r\n\
    \    if(l+1 == r) return new Node(x);\r\n    int m = l + ((r-l)>>1);\r\n    return\
    \ merge(update(t->l, k, x, l, m), update(t->r, k, x, m, r));\r\n  }\r\n\r\n  T\
    \ query(Np t, int ql, int qr, int l, int r) const {\r\n    if(!t || r<=ql || qr<=l)\
    \ return id;\r\n    if(ql<=l && r<=qr) return t->val;\r\n    int m = l + ((r-l)\
    \ >> 1);\r\n    return op(query(t->l, ql, qr, l, m), query(t->r, ql, qr, m, r));\r\
    \n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n\r\ntemplate<typename T>\r\nstruct PersistentSegmentTree{\r\
    \n  using OP = function<T(T,T)>;\r\n  int n, n0;\r\n  const T id;\r\n  const OP\
    \ op;\r\n  struct Node{\r\n    T val;\r\n    Node *l, *r;\r\n    Node(const T\
    \ &val): val(val), l(nullptr), r(nullptr) {}\r\n  };\r\n  using Np = Node*;\r\n\
    \r\n  PersistentSegmentTree(int n_, const T &id, const OP &op) : n(1), n0(n_),\
    \ id(id),op(op){\r\n    while(n < n_) n<<=1;\r\n  }\r\n\r\n  Np build(){ return\
    \ build(vector<T>{}); }\r\n\r\n  Np build(const vector<T> &v){ return build(0,\
    \ n, v); }\r\n\r\n  Np update(Np root, int k, const T &x){ return update(root,\
    \ k, x, 0, n); }\r\n\r\n  T query(Np root, int l, int r){ return query(root, l,\
    \ r, 0, n); }\r\n\r\nprivate:\r\n\r\n  T val(Np t) const { return !t ? id : t->val;\
    \ }\r\n\r\n  Np merge(Np l, Np r){\r\n    Np t = new Node(op(val(l), val(r)));\r\
    \n    t->l = l; t->r = r;\r\n    return t;\r\n  }\r\n\r\n  Np build(int l, int\
    \ r, const vector<T> &v){\r\n    if(l+1 == r) return new Node(l<int(v.size())\
    \ ? v[l] : id);\r\n    int m = l + ((r-l)>>1);\r\n    return merge(build(l, m,\
    \ v), build(m, r, v));\r\n  }\r\n\r\n  Np update(Np t, int k, const T &x, int\
    \ l, int r){\r\n    if(k < l || r <= k) return t;\r\n    if(l+1 == r) return new\
    \ Node(x);\r\n    int m = l + ((r-l)>>1);\r\n    return merge(update(t->l, k,\
    \ x, l, m), update(t->r, k, x, m, r));\r\n  }\r\n\r\n  T query(Np t, int ql, int\
    \ qr, int l, int r) const {\r\n    if(!t || r<=ql || qr<=l) return id;\r\n   \
    \ if(ql<=l && r<=qr) return t->val;\r\n    int m = l + ((r-l) >> 1);\r\n    return\
    \ op(query(t->l, ql, qr, l, m), query(t->r, ql, qr, m, r));\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/segtree/PersistentSegmentTree.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/segtree/PersistentSegmentTree.cpp
layout: document
redirect_from:
- /library/datastructure/segtree/PersistentSegmentTree.cpp
- /library/datastructure/segtree/PersistentSegmentTree.cpp.html
title: datastructure/segtree/PersistentSegmentTree.cpp
---
