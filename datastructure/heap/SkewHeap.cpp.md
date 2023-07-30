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
  bundledCode: "#line 2 \"datastructure/heap/SkewHeap.cpp\"\n\r\ntemplate<typename\
    \ T, typename Compare = less<T>>\r\nstruct SkewHeap{\r\n  struct Node{\r\n   \
    \ T key, lazy;\r\n    Node *l, *r;\r\n    int idx;\r\n    Node(const T &key, int\
    \ idx)\r\n      : key(key), lazy(0), l(nullptr), r(nullptr), idx(idx){}\r\n  };\r\
    \n  SkewHeap() = default;\r\n  SkewHeap(const Compare &comp): comp(comp) {}\r\n\
    \  \r\n  Node *meld(Node *x, Node *y){\r\n    propagate(x); propagate(y);\r\n\
    \    if(!x || !y) return x? x : y;\r\n    if(comp(x->key, y->key)) swap(x, y);\r\
    \n    x->r = meld(y, x->r);\r\n    swap(x->l, x->r);\r\n    return x;\r\n  }\r\
    \n  Node *push(Node *t, const T &key, int idx = -1){\r\n    return meld(t, alloc(key,\
    \ idx));\r\n  }\r\n  Node *pop(Node *t){\r\n    assert(t);\r\n    return meld(t->l,\
    \ t->r);\r\n  }\r\n  Node *add(Node *t, const T &lazy){\r\n    if(t){ t->lazy\
    \ += lazy; propagate(t); }\r\n    return t;\r\n  }\r\n  Node *make_root(){ return\
    \ nullptr; }\r\n\r\nprivate:\r\n  Compare comp{};\r\n  Node *alloc(const T &key,\
    \ int idx = -1) const {\r\n    return new Node(key, idx);\r\n  }\r\n  Node *propagate(Node\
    \ *t){\r\n    if(t && t->lazy!=0){\r\n      if(t->l) t->l->lazy += t->lazy;\r\n\
    \      if(t->r) t->r->lazy += t->lazy;\r\n      t->key += t->lazy;\r\n      t->lazy\
    \ = 0;\r\n    }\r\n    return t;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T, typename Compare = less<T>>\r\n\
    struct SkewHeap{\r\n  struct Node{\r\n    T key, lazy;\r\n    Node *l, *r;\r\n\
    \    int idx;\r\n    Node(const T &key, int idx)\r\n      : key(key), lazy(0),\
    \ l(nullptr), r(nullptr), idx(idx){}\r\n  };\r\n  SkewHeap() = default;\r\n  SkewHeap(const\
    \ Compare &comp): comp(comp) {}\r\n  \r\n  Node *meld(Node *x, Node *y){\r\n \
    \   propagate(x); propagate(y);\r\n    if(!x || !y) return x? x : y;\r\n    if(comp(x->key,\
    \ y->key)) swap(x, y);\r\n    x->r = meld(y, x->r);\r\n    swap(x->l, x->r);\r\
    \n    return x;\r\n  }\r\n  Node *push(Node *t, const T &key, int idx = -1){\r\
    \n    return meld(t, alloc(key, idx));\r\n  }\r\n  Node *pop(Node *t){\r\n   \
    \ assert(t);\r\n    return meld(t->l, t->r);\r\n  }\r\n  Node *add(Node *t, const\
    \ T &lazy){\r\n    if(t){ t->lazy += lazy; propagate(t); }\r\n    return t;\r\n\
    \  }\r\n  Node *make_root(){ return nullptr; }\r\n\r\nprivate:\r\n  Compare comp{};\r\
    \n  Node *alloc(const T &key, int idx = -1) const {\r\n    return new Node(key,\
    \ idx);\r\n  }\r\n  Node *propagate(Node *t){\r\n    if(t && t->lazy!=0){\r\n\
    \      if(t->l) t->l->lazy += t->lazy;\r\n      if(t->r) t->r->lazy += t->lazy;\r\
    \n      t->key += t->lazy;\r\n      t->lazy = 0;\r\n    }\r\n    return t;\r\n\
    \  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/heap/SkewHeap.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/heap/SkewHeap.cpp
layout: document
redirect_from:
- /library/datastructure/heap/SkewHeap.cpp
- /library/datastructure/heap/SkewHeap.cpp.html
title: datastructure/heap/SkewHeap.cpp
---
