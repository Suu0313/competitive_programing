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
  bundledCode: "#line 2 \"datastructure/bbst/treap/ImplicitTreap.cpp\"\n\r\n\r\ntemplate<typename\
    \ T, typename E>\r\nstruct ImplicitTreap{\r\n  using F = function<T(T, T)>;\r\n\
    \  using G = function<T(T, E, size_t)>;\r\n  using H = function<E(E, E)>;\r\n\r\
    \n  ImplicitTreap() {}\r\n  ImplicitTreap(const T &id, const E &l_id, const F\
    \ &f, const G &g, const H &h)\r\n  : mt(random_device{}()), id(id), l_id(l_id),\
    \ f(f), g(g), h(h) {}\r\n\r\n  void insert(int k, const T &value){ insert(root,\
    \ tok(k), new Node(value, mt(), id, l_id)); }\r\n  void push_front(const T &value){\
    \ insert(0, value); }\r\n  void push_back(const T &value){ insert(size(), value);\
    \ }\r\n\r\n  void erase(int k){ erase(root, tok(k)); }\r\n\r\n  void update(int\
    \ l, int r, const E &x){ if(x != l_id) update(root, tok(l), tok(r), x); }\r\n\
    \  T query(int l, int r){ return query(root, tok(l), tok(r)); }\r\n\r\n  void\
    \ update(int k, const E &x){ update(k, k+1, x); }\r\n  T query(int k){ return\
    \ query(k, k+1); }\r\n\r\n  void reverse(int l, int r){ reverse(root, tok(l),\
    \ tok(r)); }\r\n  void rotate(int l, int m, int r){ rotate(root, tok(l), tok(m),\
    \ tok(r)); }\r\n\r\n  T at(int k){ return at(root, tok(k)); }\r\n  T operator[](int\
    \ k){ return at(root, k); }\r\n\r\n  size_t size() const { return size(root);\
    \ }\r\n  bool empty() const { return !root; }\r\n  explicit operator bool() const\
    \ { return !empty(); }\r\n\r\n  void dump() { dump(root); cout << \"\\n\"; }\r\
    \n\r\n  template<typename C>\r\n  int find(int L, int R, const C &check, bool\
    \ left = true){\r\n    L = tok(L), R = tok(R);\r\n    if(L > R) return -1;\r\n\
    \    if(!left) reverse(L, R);\r\n    np l, m, r;\r\n    split(root, L, l, m);\
    \ split(m, R-L, m, r);\r\n    T cum = id;\r\n    int res = find(m, cum, check);\r\
    \n    merge(m, m, r); merge(root, l, m);\r\n    if(left) res = L + res;\r\n  \
    \  else reverse(L, R), res = R - res;\r\n    return res;\r\n  }\r\n\r\nprivate:\r\
    \n  size_t tok(int k) const {\r\n    if(k >= 0) return k;\r\n    return size()\
    \ + k;\r\n  }\r\n\r\n  mt19937 mt;\r\n\r\n  const T id;\r\n  const E l_id;\r\n\
    \  const F f;\r\n  const G g;\r\n  const H h;\r\n  \r\n  struct Node{\r\n    T\
    \ value, acc;\r\n    E lazy;\r\n    size_t pri, cnt;\r\n    bool rev;\r\n    Node\
    \ *l, *r;\r\n\r\n    Node(const T &value, size_t pri, const T &a, const E &b)\r\
    \n    : value(value), acc(a), lazy(b), pri(pri), cnt(1), rev(false), l(nullptr),\
    \ r(nullptr) {}\r\n  } *root = nullptr;\r\n\r\n  using np = Node *;\r\n\r\n  size_t\
    \ size(np t) const { return !t ? 0 : t->cnt; }\r\n  const T &acc(np t) const {\
    \ return !t ? id : t->acc; }\r\n  \r\n  void push_up(np t){\r\n    if(!t) return;\r\
    \n    t->cnt = size(t->l) + 1 + size(t->r);\r\n    t->acc = f(acc(t->l), f(t->value,\
    \ acc(t->r)));\r\n  }\r\n\r\n  void push_down(np t){\r\n    if(!t) return;\r\n\
    \    if(t->rev){\r\n      t->rev = false;\r\n      swap(t->l, t->r);\r\n     \
    \ if(t->l) t->l->rev ^= 1;\r\n      if(t->r) t->r->rev ^= 1;\r\n    }\r\n\r\n\
    \    if(t->lazy != l_id){\r\n      if(t->l){\r\n        t->l->lazy = h(t->l->lazy,\
    \ t->lazy);\r\n        t->l->acc = g(t->l->acc, t->lazy, size(t->l));\r\n    \
    \  }\r\n      if(t->r){\r\n        t->r->lazy = h(t->r->lazy, t->lazy);\r\n  \
    \      t->r->acc = g(t->r->acc, t->lazy, size(t->r));\r\n      }\r\n      t->value\
    \ = g(t->value, t->lazy, 1);\r\n      t->lazy = l_id;\r\n    }\r\n    push_up(t);\r\
    \n  }\r\n\r\n  void split(np t, size_t key, np &l, np &r){\r\n    if(!t){\r\n\
    \      l = r = nullptr; return;\r\n    }\r\n    push_down(t);\r\n    size_t idx\
    \ = size(t->l) + 1;\r\n    if(key < idx) split(t->l, key, l, t->l), r = t;\r\n\
    \    else split(t->r, key-idx, t->r, r), l = t;\r\n    push_up(l); push_up(r);\r\
    \n  }\r\n\r\n  void merge(np &t, np l, np r){\r\n    push_down(r); push_down(l);\r\
    \n    if(!l || !r) t = !r ? l : r;\r\n    else if(l->pri > r->pri) merge(l->r,\
    \ l->r, r), t = l;\r\n    else merge(r->l, l, r->l), t = r;\r\n    push_up(t);\r\
    \n  }\r\n\r\n  void insert(np &t, size_t key, np x){\r\n    np l, r;\r\n    split(t,\
    \ key, l, r);\r\n    merge(l, l, x);\r\n    merge(t, l, r);\r\n  }\r\n\r\n  void\
    \ erase(np &t, size_t key){\r\n    np l, m, r;\r\n    split(t, key+1, m, r);\r\
    \n    split(m, key, l, m);\r\n    merge(t, l, r);\r\n  }\r\n\r\n  T query(np t,\
    \ size_t L, size_t R){\r\n    if(L > R) return id;\r\n    np l, m, r;\r\n    split(t,\
    \ L, l, m); split(m, R-L, m, r);\r\n    T res = m->acc;\r\n    merge(m, m, r);\
    \ merge(t, l, m);\r\n    return res;\r\n  }\r\n\r\n  void update(np t, size_t\
    \ L, size_t R, const E &x){\r\n    if(L > R) return;\r\n    np l, m, r;\r\n  \
    \  split(t, L, l, m); split(m, R-L, m, r);\r\n    m->lazy = h(m->lazy, x); \r\n\
    \    m->acc = g(m->acc, x, size(m));\r\n    merge(m, m, r); merge(t, l, m);\r\n\
    \  }\r\n\r\n  void reverse(np t, size_t L, size_t R){\r\n    if(L > R) return;\r\
    \n    np l, m, r;\r\n    split(t, L, l, m); split(m, R-L, m, r);\r\n    m->rev\
    \ ^= 1;\r\n    merge(m, m, r); merge(t, l, m);\r\n  }\r\n\r\n  void rotate(np\
    \ t, size_t l, size_t m, size_t r){\r\n    reverse(t, l, r); reverse(t, l, l+r-m);\
    \ reverse(t, l+r-m, r);\r\n  }\r\n\r\n  T at(np t, size_t k){\r\n    np l, m,\
    \ r;\r\n    split(t, k, l, m); split(m, 1, m, r);\r\n    T res = m->acc;\r\n \
    \   merge(m, m, r); merge(t, l, m);\r\n    return res;\r\n  }\r\n\r\n  void dump(np\
    \ t){\r\n    if(!t) return;\r\n    push_down(t);\r\n    dump(t->l);\r\n    cout\
    \ << t->value << \" \";\r\n    dump(t->r);\r\n  }\r\n\r\n  template<typename C>\r\
    \n  int find(np t, T &cum, const C &check){\r\n    if(!t) return 0;\r\n    if(!check(f(cum,\
    \ acc(t->l)))) return find(t->l, cum, check);\r\n    cum = f(cum, acc(t->l));\r\
    \n    if(!check(f(cum, t->value))) return size(t->l);\r\n    cum = f(cum, t->value);\r\
    \n    return size(t->l) + 1 + find(t->r, cum, check);\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n\r\ntemplate<typename T, typename E>\r\nstruct ImplicitTreap{\r\
    \n  using F = function<T(T, T)>;\r\n  using G = function<T(T, E, size_t)>;\r\n\
    \  using H = function<E(E, E)>;\r\n\r\n  ImplicitTreap() {}\r\n  ImplicitTreap(const\
    \ T &id, const E &l_id, const F &f, const G &g, const H &h)\r\n  : mt(random_device{}()),\
    \ id(id), l_id(l_id), f(f), g(g), h(h) {}\r\n\r\n  void insert(int k, const T\
    \ &value){ insert(root, tok(k), new Node(value, mt(), id, l_id)); }\r\n  void\
    \ push_front(const T &value){ insert(0, value); }\r\n  void push_back(const T\
    \ &value){ insert(size(), value); }\r\n\r\n  void erase(int k){ erase(root, tok(k));\
    \ }\r\n\r\n  void update(int l, int r, const E &x){ if(x != l_id) update(root,\
    \ tok(l), tok(r), x); }\r\n  T query(int l, int r){ return query(root, tok(l),\
    \ tok(r)); }\r\n\r\n  void update(int k, const E &x){ update(k, k+1, x); }\r\n\
    \  T query(int k){ return query(k, k+1); }\r\n\r\n  void reverse(int l, int r){\
    \ reverse(root, tok(l), tok(r)); }\r\n  void rotate(int l, int m, int r){ rotate(root,\
    \ tok(l), tok(m), tok(r)); }\r\n\r\n  T at(int k){ return at(root, tok(k)); }\r\
    \n  T operator[](int k){ return at(root, k); }\r\n\r\n  size_t size() const {\
    \ return size(root); }\r\n  bool empty() const { return !root; }\r\n  explicit\
    \ operator bool() const { return !empty(); }\r\n\r\n  void dump() { dump(root);\
    \ cout << \"\\n\"; }\r\n\r\n  template<typename C>\r\n  int find(int L, int R,\
    \ const C &check, bool left = true){\r\n    L = tok(L), R = tok(R);\r\n    if(L\
    \ > R) return -1;\r\n    if(!left) reverse(L, R);\r\n    np l, m, r;\r\n    split(root,\
    \ L, l, m); split(m, R-L, m, r);\r\n    T cum = id;\r\n    int res = find(m, cum,\
    \ check);\r\n    merge(m, m, r); merge(root, l, m);\r\n    if(left) res = L +\
    \ res;\r\n    else reverse(L, R), res = R - res;\r\n    return res;\r\n  }\r\n\
    \r\nprivate:\r\n  size_t tok(int k) const {\r\n    if(k >= 0) return k;\r\n  \
    \  return size() + k;\r\n  }\r\n\r\n  mt19937 mt;\r\n\r\n  const T id;\r\n  const\
    \ E l_id;\r\n  const F f;\r\n  const G g;\r\n  const H h;\r\n  \r\n  struct Node{\r\
    \n    T value, acc;\r\n    E lazy;\r\n    size_t pri, cnt;\r\n    bool rev;\r\n\
    \    Node *l, *r;\r\n\r\n    Node(const T &value, size_t pri, const T &a, const\
    \ E &b)\r\n    : value(value), acc(a), lazy(b), pri(pri), cnt(1), rev(false),\
    \ l(nullptr), r(nullptr) {}\r\n  } *root = nullptr;\r\n\r\n  using np = Node *;\r\
    \n\r\n  size_t size(np t) const { return !t ? 0 : t->cnt; }\r\n  const T &acc(np\
    \ t) const { return !t ? id : t->acc; }\r\n  \r\n  void push_up(np t){\r\n   \
    \ if(!t) return;\r\n    t->cnt = size(t->l) + 1 + size(t->r);\r\n    t->acc =\
    \ f(acc(t->l), f(t->value, acc(t->r)));\r\n  }\r\n\r\n  void push_down(np t){\r\
    \n    if(!t) return;\r\n    if(t->rev){\r\n      t->rev = false;\r\n      swap(t->l,\
    \ t->r);\r\n      if(t->l) t->l->rev ^= 1;\r\n      if(t->r) t->r->rev ^= 1;\r\
    \n    }\r\n\r\n    if(t->lazy != l_id){\r\n      if(t->l){\r\n        t->l->lazy\
    \ = h(t->l->lazy, t->lazy);\r\n        t->l->acc = g(t->l->acc, t->lazy, size(t->l));\r\
    \n      }\r\n      if(t->r){\r\n        t->r->lazy = h(t->r->lazy, t->lazy);\r\
    \n        t->r->acc = g(t->r->acc, t->lazy, size(t->r));\r\n      }\r\n      t->value\
    \ = g(t->value, t->lazy, 1);\r\n      t->lazy = l_id;\r\n    }\r\n    push_up(t);\r\
    \n  }\r\n\r\n  void split(np t, size_t key, np &l, np &r){\r\n    if(!t){\r\n\
    \      l = r = nullptr; return;\r\n    }\r\n    push_down(t);\r\n    size_t idx\
    \ = size(t->l) + 1;\r\n    if(key < idx) split(t->l, key, l, t->l), r = t;\r\n\
    \    else split(t->r, key-idx, t->r, r), l = t;\r\n    push_up(l); push_up(r);\r\
    \n  }\r\n\r\n  void merge(np &t, np l, np r){\r\n    push_down(r); push_down(l);\r\
    \n    if(!l || !r) t = !r ? l : r;\r\n    else if(l->pri > r->pri) merge(l->r,\
    \ l->r, r), t = l;\r\n    else merge(r->l, l, r->l), t = r;\r\n    push_up(t);\r\
    \n  }\r\n\r\n  void insert(np &t, size_t key, np x){\r\n    np l, r;\r\n    split(t,\
    \ key, l, r);\r\n    merge(l, l, x);\r\n    merge(t, l, r);\r\n  }\r\n\r\n  void\
    \ erase(np &t, size_t key){\r\n    np l, m, r;\r\n    split(t, key+1, m, r);\r\
    \n    split(m, key, l, m);\r\n    merge(t, l, r);\r\n  }\r\n\r\n  T query(np t,\
    \ size_t L, size_t R){\r\n    if(L > R) return id;\r\n    np l, m, r;\r\n    split(t,\
    \ L, l, m); split(m, R-L, m, r);\r\n    T res = m->acc;\r\n    merge(m, m, r);\
    \ merge(t, l, m);\r\n    return res;\r\n  }\r\n\r\n  void update(np t, size_t\
    \ L, size_t R, const E &x){\r\n    if(L > R) return;\r\n    np l, m, r;\r\n  \
    \  split(t, L, l, m); split(m, R-L, m, r);\r\n    m->lazy = h(m->lazy, x); \r\n\
    \    m->acc = g(m->acc, x, size(m));\r\n    merge(m, m, r); merge(t, l, m);\r\n\
    \  }\r\n\r\n  void reverse(np t, size_t L, size_t R){\r\n    if(L > R) return;\r\
    \n    np l, m, r;\r\n    split(t, L, l, m); split(m, R-L, m, r);\r\n    m->rev\
    \ ^= 1;\r\n    merge(m, m, r); merge(t, l, m);\r\n  }\r\n\r\n  void rotate(np\
    \ t, size_t l, size_t m, size_t r){\r\n    reverse(t, l, r); reverse(t, l, l+r-m);\
    \ reverse(t, l+r-m, r);\r\n  }\r\n\r\n  T at(np t, size_t k){\r\n    np l, m,\
    \ r;\r\n    split(t, k, l, m); split(m, 1, m, r);\r\n    T res = m->acc;\r\n \
    \   merge(m, m, r); merge(t, l, m);\r\n    return res;\r\n  }\r\n\r\n  void dump(np\
    \ t){\r\n    if(!t) return;\r\n    push_down(t);\r\n    dump(t->l);\r\n    cout\
    \ << t->value << \" \";\r\n    dump(t->r);\r\n  }\r\n\r\n  template<typename C>\r\
    \n  int find(np t, T &cum, const C &check){\r\n    if(!t) return 0;\r\n    if(!check(f(cum,\
    \ acc(t->l)))) return find(t->l, cum, check);\r\n    cum = f(cum, acc(t->l));\r\
    \n    if(!check(f(cum, t->value))) return size(t->l);\r\n    cum = f(cum, t->value);\r\
    \n    return size(t->l) + 1 + find(t->r, cum, check);\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/bbst/treap/ImplicitTreap.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/bbst/treap/ImplicitTreap.cpp
layout: document
redirect_from:
- /library/datastructure/bbst/treap/ImplicitTreap.cpp
- /library/datastructure/bbst/treap/ImplicitTreap.cpp.html
title: datastructure/bbst/treap/ImplicitTreap.cpp
---
