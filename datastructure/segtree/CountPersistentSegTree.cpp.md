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
  bundledCode: "#line 2 \"datastructure/segtree/CountPersistentSegTree.cpp\"\n\r\n\
    template<typename T, typename M>\r\nstruct CountPersistentSegTree{\r\n  using\
    \ OP = function<M(M, M)>;\r\n\r\n  const M id;\r\n  const OP op, inv;\r\n\r\n\
    \  CountPersistentSegTree(const M &id, const OP &op, const OP &inv): id(id), op(op),\
    \ inv(inv) { }\r\n\r\n  void add(const T &x, const T &y, const M &v){\r\n    ps.emplace_back(x,\
    \ y, v);\r\n  }\r\n\r\n  void build(){\r\n    sort(begin(ps), end(ps));\r\n  \
    \  int m = int(ps.size());\r\n    xs.resize(m);\r\n    ys.resize(m);\r\n    roots.resize(m+1,\
    \ nullptr);\r\n\r\n    for(int i = 0; i < m; ++i){\r\n      auto[x,y,v] = ps[i];\r\
    \n      xs[i] = x;\r\n      ys[i] = y;\r\n    }\r\n    compress();\r\n    n0 =\
    \ int(pys.size());\r\n    for(n=1; n < n0; n<<=1);\r\n\r\n    for(int i = 0; i\
    \ < m; ++i){\r\n      auto[x,y,v] = ps[i];\r\n      roots[i+1] = add(roots[i],\
    \ v, ks[i], 0, n);\r\n    }\r\n  }\r\n\r\n  M fold(const T &lx, const T &rx, const\
    \ T &ly, const T &ry){\r\n    return inv(fold(roots[lb(xs, rx)],  lb(pys, ly),\
    \ lb(pys, ry), 0, n), fold(roots[lb(xs, lx)],  lb(pys, ly), lb(pys, ry), 0, n));\r\
    \n  }\r\n\r\n  int count(const T &lx, const T &rx, const T &ly, const T &ry){\r\
    \n    return count(roots[lb(xs, rx)],  lb(pys, ly), lb(pys, ry), 0, n) - count(roots[lb(xs,\
    \ lx)],  lb(pys, ly), lb(pys, ry), 0, n);\r\n  }\r\n\r\n  T kth_element(const\
    \ T &lx, const T &rx, int k){\r\n    return pys[kth_element(roots[lb(xs, rx)],\
    \ roots[lb(xs, lx)], k, 0, n)];\r\n  }\r\n\r\nprivate:\r\n  struct Node{\r\n \
    \   M val; int cnt;\r\n    Node *l = nullptr, *r = nullptr;\r\n    Node() {}\r\
    \n    Node(const M &val, int cnt): val(val), cnt(cnt) {};\r\n  };\r\n  using Np\
    \ = Node*;\r\n  int n, n0;\r\n  vector<tuple<T,T,M>> ps;\r\n  vector<T> xs, ys,\
    \ pys;\r\n  vector<int> ks;\r\n  vector<Np> roots;\r\n\r\n  void compress(){\r\
    \n    int m = ys.size();\r\n    vector<int> idx(m); iota(begin(idx), end(idx),\
    \ 0);\r\n    sort(begin(idx), end(idx), [&](int i, int j){ return ys[i] < ys[j];\
    \ });\r\n    pys.assign(1, ys[idx[0]]);\r\n    ks.assign(m, 0);\r\n    for(int\
    \ i = 1; i < m; ++i){\r\n      int a = idx[i-1], b = idx[i];\r\n      if(ys[a]\
    \ == ys[b]) ks[b] = ks[a];\r\n      else{\r\n        ks[b] = ks[a] + 1;\r\n  \
    \      pys.emplace_back(ys[b]);\r\n      }\r\n    }\r\n  }\r\n\r\n  int lb(const\
    \ vector<T> &vs, const T &v){\r\n    return lower_bound(begin(vs), end(vs), v)\
    \ - begin(vs);\r\n  }\r\n\r\n  int cnt(Np t){ return !t ? 0 : t->cnt; }\r\n  M\
    \ val(Np t) { return !t ? id : t->val; }\r\n\r\n  Np add(Np t, const M &v, int\
    \ k, int l, int r){\r\n    if(k < l || r <= k) return t;\r\n    Np s = new Node(op(val(t),\
    \ v), cnt(t)+1);\r\n    if(t){ s->l = t->l; s->r = t->r; }\r\n    if(l+1 == r)\
    \ return s;\r\n    int m = l + ((r-l) >> 1);\r\n    s->l = add(s->l, v, k, l,\
    \ m);\r\n    s->r = add(s->r, v, k, m, r);\r\n    return s;\r\n  }\r\n\r\n  int\
    \ count(Np t, int ql, int qr, int l, int r){\r\n    if(!t || qr<=l || r<=ql) return\
    \ 0;\r\n    if(ql<=l && r<=qr) return cnt(t);\r\n    int m = l + ((r-l) >> 1);\r\
    \n    return count(t->l, ql, qr, l, m) + count(t->r, ql, qr, m, r);\r\n  }\r\n\
    \r\n  M fold(Np t, int ql, int qr, int l, int r){\r\n    if(!t || qr<=l || r<=ql)\
    \ return id;\r\n    if(ql<=l && r<=qr) return val(t);\r\n    int m = l + ((r-l)\
    \ >> 1);\r\n    return op(fold(t->l, ql, qr, l, m), fold(t->r, ql, qr, m, r));\r\
    \n  }\r\n\r\n  int kth_element(Np s, Np t, int k, int l, int r){\r\n    if(l+1\
    \ == r) return l;\r\n    if(!s) s = new Node(id, 0);\r\n    if(!t) t = new Node(id,\
    \ 0);\r\n    int lc = cnt(s->l) - cnt(t->l);\r\n    int m = l + ((r-l) >> 1);\r\
    \n    if(lc > k) return kth_element(s->l, t->l, k, l, m);\r\n    return kth_element(s->r,\
    \ t->r, k-lc, m, r);\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T, typename M>\r\nstruct CountPersistentSegTree{\r\
    \n  using OP = function<M(M, M)>;\r\n\r\n  const M id;\r\n  const OP op, inv;\r\
    \n\r\n  CountPersistentSegTree(const M &id, const OP &op, const OP &inv): id(id),\
    \ op(op), inv(inv) { }\r\n\r\n  void add(const T &x, const T &y, const M &v){\r\
    \n    ps.emplace_back(x, y, v);\r\n  }\r\n\r\n  void build(){\r\n    sort(begin(ps),\
    \ end(ps));\r\n    int m = int(ps.size());\r\n    xs.resize(m);\r\n    ys.resize(m);\r\
    \n    roots.resize(m+1, nullptr);\r\n\r\n    for(int i = 0; i < m; ++i){\r\n \
    \     auto[x,y,v] = ps[i];\r\n      xs[i] = x;\r\n      ys[i] = y;\r\n    }\r\n\
    \    compress();\r\n    n0 = int(pys.size());\r\n    for(n=1; n < n0; n<<=1);\r\
    \n\r\n    for(int i = 0; i < m; ++i){\r\n      auto[x,y,v] = ps[i];\r\n      roots[i+1]\
    \ = add(roots[i], v, ks[i], 0, n);\r\n    }\r\n  }\r\n\r\n  M fold(const T &lx,\
    \ const T &rx, const T &ly, const T &ry){\r\n    return inv(fold(roots[lb(xs,\
    \ rx)],  lb(pys, ly), lb(pys, ry), 0, n), fold(roots[lb(xs, lx)],  lb(pys, ly),\
    \ lb(pys, ry), 0, n));\r\n  }\r\n\r\n  int count(const T &lx, const T &rx, const\
    \ T &ly, const T &ry){\r\n    return count(roots[lb(xs, rx)],  lb(pys, ly), lb(pys,\
    \ ry), 0, n) - count(roots[lb(xs, lx)],  lb(pys, ly), lb(pys, ry), 0, n);\r\n\
    \  }\r\n\r\n  T kth_element(const T &lx, const T &rx, int k){\r\n    return pys[kth_element(roots[lb(xs,\
    \ rx)], roots[lb(xs, lx)], k, 0, n)];\r\n  }\r\n\r\nprivate:\r\n  struct Node{\r\
    \n    M val; int cnt;\r\n    Node *l = nullptr, *r = nullptr;\r\n    Node() {}\r\
    \n    Node(const M &val, int cnt): val(val), cnt(cnt) {};\r\n  };\r\n  using Np\
    \ = Node*;\r\n  int n, n0;\r\n  vector<tuple<T,T,M>> ps;\r\n  vector<T> xs, ys,\
    \ pys;\r\n  vector<int> ks;\r\n  vector<Np> roots;\r\n\r\n  void compress(){\r\
    \n    int m = ys.size();\r\n    vector<int> idx(m); iota(begin(idx), end(idx),\
    \ 0);\r\n    sort(begin(idx), end(idx), [&](int i, int j){ return ys[i] < ys[j];\
    \ });\r\n    pys.assign(1, ys[idx[0]]);\r\n    ks.assign(m, 0);\r\n    for(int\
    \ i = 1; i < m; ++i){\r\n      int a = idx[i-1], b = idx[i];\r\n      if(ys[a]\
    \ == ys[b]) ks[b] = ks[a];\r\n      else{\r\n        ks[b] = ks[a] + 1;\r\n  \
    \      pys.emplace_back(ys[b]);\r\n      }\r\n    }\r\n  }\r\n\r\n  int lb(const\
    \ vector<T> &vs, const T &v){\r\n    return lower_bound(begin(vs), end(vs), v)\
    \ - begin(vs);\r\n  }\r\n\r\n  int cnt(Np t){ return !t ? 0 : t->cnt; }\r\n  M\
    \ val(Np t) { return !t ? id : t->val; }\r\n\r\n  Np add(Np t, const M &v, int\
    \ k, int l, int r){\r\n    if(k < l || r <= k) return t;\r\n    Np s = new Node(op(val(t),\
    \ v), cnt(t)+1);\r\n    if(t){ s->l = t->l; s->r = t->r; }\r\n    if(l+1 == r)\
    \ return s;\r\n    int m = l + ((r-l) >> 1);\r\n    s->l = add(s->l, v, k, l,\
    \ m);\r\n    s->r = add(s->r, v, k, m, r);\r\n    return s;\r\n  }\r\n\r\n  int\
    \ count(Np t, int ql, int qr, int l, int r){\r\n    if(!t || qr<=l || r<=ql) return\
    \ 0;\r\n    if(ql<=l && r<=qr) return cnt(t);\r\n    int m = l + ((r-l) >> 1);\r\
    \n    return count(t->l, ql, qr, l, m) + count(t->r, ql, qr, m, r);\r\n  }\r\n\
    \r\n  M fold(Np t, int ql, int qr, int l, int r){\r\n    if(!t || qr<=l || r<=ql)\
    \ return id;\r\n    if(ql<=l && r<=qr) return val(t);\r\n    int m = l + ((r-l)\
    \ >> 1);\r\n    return op(fold(t->l, ql, qr, l, m), fold(t->r, ql, qr, m, r));\r\
    \n  }\r\n\r\n  int kth_element(Np s, Np t, int k, int l, int r){\r\n    if(l+1\
    \ == r) return l;\r\n    if(!s) s = new Node(id, 0);\r\n    if(!t) t = new Node(id,\
    \ 0);\r\n    int lc = cnt(s->l) - cnt(t->l);\r\n    int m = l + ((r-l) >> 1);\r\
    \n    if(lc > k) return kth_element(s->l, t->l, k, l, m);\r\n    return kth_element(s->r,\
    \ t->r, k-lc, m, r);\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/segtree/CountPersistentSegTree.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/segtree/CountPersistentSegTree.cpp
layout: document
redirect_from:
- /library/datastructure/segtree/CountPersistentSegTree.cpp
- /library/datastructure/segtree/CountPersistentSegTree.cpp.html
title: datastructure/segtree/CountPersistentSegTree.cpp
---
