---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/shortestpath/EppsteinsAlgorithm.cpp
    title: graph/shortestpath/EppsteinsAlgorithm.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/heap/PersistentLeftistHeap.cpp\"\n\r\ntemplate<typename\
    \ T, class Compair = less<T>>\r\nstruct PersistentLeftistHeap{\r\n  struct Node;\r\
    \n  using Np = shared_ptr<Node>;\r\n  template<class... Args>\r\n  static Np make_np(Args&&...\
    \ args){\r\n      return make_shared<Node>(forward<Args>(args)...);\r\n  }\r\n\
    \r\n  struct Node{\r\n    T val;\r\n    Np l = nullptr, r = nullptr;\r\n    size_t\
    \ s = 1;\r\n    Node() = default;\r\n    Node(const T &val): val(val) {}\r\n \
    \   Node(const Node&) = default;\r\n    Node(Node&&) = default;\r\n    Node &operator=(const\
    \ Node&) = default;\r\n    Node &operator=(Node&&) = default;\r\n  };\r\n\r\n\
    \  static Np make_root(){ return nullptr; }\r\n  static Np make_clone(Np t){ return\
    \ t ? make_np(*t) : nullptr; }\r\n  static size_t get_s(Np t){ return t ? t->s\
    \ : 0; }\r\n\r\n  Compair cmp;\r\n  \r\n  PersistentLeftistHeap(const Compair\
    \ &cmp = Compair{}): cmp(cmp) {}\r\n\r\n  Np meld(Np a, Np b){\r\n    if(!b) return\
    \ make_clone(a);\r\n    if(!a) return make_clone(b);\r\n    a = make_clone(a);\
    \ b = make_clone(b);\r\n    if(cmp(b->val, a->val)) a.swap(b);\r\n\r\n    a->r\
    \ = meld(a->r, b);\r\n    if(!a->l || a->l->s < a->r->s) a->l.swap(a->r);\r\n\
    \    a->s = get_s(a->r) + 1;\r\n    return a;\r\n  }\r\n  Np push(Np t, const\
    \ T &x){ return meld(t, make_np(x)); }\r\n  Np pop(Np t){ return meld(t->l, t->r);\
    \ }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T, class Compair = less<T>>\r\nstruct\
    \ PersistentLeftistHeap{\r\n  struct Node;\r\n  using Np = shared_ptr<Node>;\r\
    \n  template<class... Args>\r\n  static Np make_np(Args&&... args){\r\n      return\
    \ make_shared<Node>(forward<Args>(args)...);\r\n  }\r\n\r\n  struct Node{\r\n\
    \    T val;\r\n    Np l = nullptr, r = nullptr;\r\n    size_t s = 1;\r\n    Node()\
    \ = default;\r\n    Node(const T &val): val(val) {}\r\n    Node(const Node&) =\
    \ default;\r\n    Node(Node&&) = default;\r\n    Node &operator=(const Node&)\
    \ = default;\r\n    Node &operator=(Node&&) = default;\r\n  };\r\n\r\n  static\
    \ Np make_root(){ return nullptr; }\r\n  static Np make_clone(Np t){ return t\
    \ ? make_np(*t) : nullptr; }\r\n  static size_t get_s(Np t){ return t ? t->s :\
    \ 0; }\r\n\r\n  Compair cmp;\r\n  \r\n  PersistentLeftistHeap(const Compair &cmp\
    \ = Compair{}): cmp(cmp) {}\r\n\r\n  Np meld(Np a, Np b){\r\n    if(!b) return\
    \ make_clone(a);\r\n    if(!a) return make_clone(b);\r\n    a = make_clone(a);\
    \ b = make_clone(b);\r\n    if(cmp(b->val, a->val)) a.swap(b);\r\n\r\n    a->r\
    \ = meld(a->r, b);\r\n    if(!a->l || a->l->s < a->r->s) a->l.swap(a->r);\r\n\
    \    a->s = get_s(a->r) + 1;\r\n    return a;\r\n  }\r\n  Np push(Np t, const\
    \ T &x){ return meld(t, make_np(x)); }\r\n  Np pop(Np t){ return meld(t->l, t->r);\
    \ }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/heap/PersistentLeftistHeap.cpp
  requiredBy:
  - graph/shortestpath/EppsteinsAlgorithm.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/heap/PersistentLeftistHeap.cpp
layout: document
redirect_from:
- /library/datastructure/heap/PersistentLeftistHeap.cpp
- /library/datastructure/heap/PersistentLeftistHeap.cpp.html
title: datastructure/heap/PersistentLeftistHeap.cpp
---
