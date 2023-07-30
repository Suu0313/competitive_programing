---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: datastructure/unionfind/PersistentUnionFind.cpp
    title: datastructure/unionfind/PersistentUnionFind.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/unionfind/PersistentArray.cpp\"\n\r\ntemplate<typename\
    \ T, size_t M = 20>\r\nstruct PersistentArray{\r\n  struct Node;\r\n  using Np\
    \ = shared_ptr<Node>;\r\n\r\n  struct Node{\r\n    T x;\r\n    array<Np, M> child\
    \ = {};\r\n\r\n    Node() = default;\r\n    Node(const T &x): x(x) {}\r\n  };\r\
    \n\r\n  Np root = Np{};\r\n\r\n  PersistentArray() = default;\r\n  template<class\
    \ Iiter>\r\n  PersistentArray(Iiter first, Iiter last){\r\n    size_t n = distance(first,\
    \ last);\r\n    for(size_t i = 0; i != n; ++i, ++first) set(root, i, *first);\r\
    \n  }\r\n  template<class Container>\r\n  PersistentArray(const Container &c):\
    \ PersistentArray(begin(c), end(c)) {}\r\n\r\n  void set(Np &t, size_t k, const\
    \ T &x){\r\n    if(!t) t = Np(new Node());\r\n    if(!k) t->x = x;\r\n    else\
    \ set(t->child[k % M], k / M, x);\r\n  }\r\n\r\n  void set(size_t k, const T &x){\
    \ set(root, k, x); }\r\n\r\n  Np update(const Np &t, size_t k, const T &x){\r\n\
    \    Np res(new Node());\r\n\r\n    if(t){\r\n      copy(begin(t->child), end(t->child),\
    \ begin(res->child));\r\n      res->x = t->x;\r\n    }\r\n\r\n    if(!k) res->x\
    \ = x;\r\n    else res->child[k % M] = update(res->child[k % M], k / M, x);\r\n\
    \r\n    return res;\r\n  }\r\n\r\n  Np update(size_t k, const T &x){ return update(root,\
    \ k, x); }\r\n\r\n  T get(const Np &t, size_t k) const {\r\n    assert(!!t);\r\
    \n    if(!k) return t->x;\r\n    return get(t->child[k % M], k / M);\r\n  }\r\n\
    \r\n  T get(size_t k) const { return get(root, k); }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T, size_t M = 20>\r\nstruct PersistentArray{\r\
    \n  struct Node;\r\n  using Np = shared_ptr<Node>;\r\n\r\n  struct Node{\r\n \
    \   T x;\r\n    array<Np, M> child = {};\r\n\r\n    Node() = default;\r\n    Node(const\
    \ T &x): x(x) {}\r\n  };\r\n\r\n  Np root = Np{};\r\n\r\n  PersistentArray() =\
    \ default;\r\n  template<class Iiter>\r\n  PersistentArray(Iiter first, Iiter\
    \ last){\r\n    size_t n = distance(first, last);\r\n    for(size_t i = 0; i !=\
    \ n; ++i, ++first) set(root, i, *first);\r\n  }\r\n  template<class Container>\r\
    \n  PersistentArray(const Container &c): PersistentArray(begin(c), end(c)) {}\r\
    \n\r\n  void set(Np &t, size_t k, const T &x){\r\n    if(!t) t = Np(new Node());\r\
    \n    if(!k) t->x = x;\r\n    else set(t->child[k % M], k / M, x);\r\n  }\r\n\r\
    \n  void set(size_t k, const T &x){ set(root, k, x); }\r\n\r\n  Np update(const\
    \ Np &t, size_t k, const T &x){\r\n    Np res(new Node());\r\n\r\n    if(t){\r\
    \n      copy(begin(t->child), end(t->child), begin(res->child));\r\n      res->x\
    \ = t->x;\r\n    }\r\n\r\n    if(!k) res->x = x;\r\n    else res->child[k % M]\
    \ = update(res->child[k % M], k / M, x);\r\n\r\n    return res;\r\n  }\r\n\r\n\
    \  Np update(size_t k, const T &x){ return update(root, k, x); }\r\n\r\n  T get(const\
    \ Np &t, size_t k) const {\r\n    assert(!!t);\r\n    if(!k) return t->x;\r\n\
    \    return get(t->child[k % M], k / M);\r\n  }\r\n\r\n  T get(size_t k) const\
    \ { return get(root, k); }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/unionfind/PersistentArray.cpp
  requiredBy:
  - datastructure/unionfind/PersistentUnionFind.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/unionfind/PersistentArray.cpp
layout: document
redirect_from:
- /library/datastructure/unionfind/PersistentArray.cpp
- /library/datastructure/unionfind/PersistentArray.cpp.html
title: datastructure/unionfind/PersistentArray.cpp
---
