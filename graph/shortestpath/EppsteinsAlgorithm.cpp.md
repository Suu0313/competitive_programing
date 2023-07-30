---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: datastructure/heap/PersistentLeftistHeap.cpp
    title: datastructure/heap/PersistentLeftistHeap.cpp
  - icon: ':warning:'
    path: graph/Graph.cpp
    title: graph/Graph.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/shortestpath/EppsteinsAlgorithm.cpp\"\n\r\n#line 2\
    \ \"graph/Graph.cpp\"\n\r\ntemplate<typename T = int>\r\nstruct Edge{\r\n  int\
    \ src, to; T cost; int idx;\r\n  Edge() = default;\r\n  Edge(int src, int to,\
    \ T cost = -1, int idx = -1): src(src), to(to), cost(cost), idx(idx) {}\r\n  operator\
    \ int() const { return to; }\r\n};\r\ntemplate<typename T> using Edges = vector<Edge<T>>;\r\
    \n\r\ntemplate<typename T = int>\r\nstruct Graph : vector<vector<Edge<T>>> {\r\
    \n  using base_t = vector<vector<Edge<T>>>;\r\n  using base_t::base_t;\r\n  size_t\
    \ es;\r\n  Graph(size_t n): base_t(n), es(0) {}\r\n\r\n  int deg(int v) const\
    \ { return int(base_t::operator[](v).size()); }\r\n\r\n  void add_edge(int src,\
    \ int to, T cost = 1){\r\n    base_t::operator[](src).emplace_back(src, to, cost,\
    \ es);\r\n    base_t::operator[](to).emplace_back(to, src, cost, es++);\r\n  }\r\
    \n  void add_directed_edge(int src, int to, T cost = 1){\r\n    base_t::operator[](src).emplace_back(src,\
    \ to, cost, es++);\r\n  }\r\n\r\n  void read(int m, int base = 1, bool weighted\
    \ = false, bool directed = false, const T &id = 1){\r\n    for (int i = 0; i <\
    \ m; i++){\r\n      int u, v; cin >> u >> v; u -= base; v -= base;\r\n      T\
    \ c = id;\r\n      if(weighted) cin >> c;\r\n      if(directed) add_directed_edge(u,\
    \ v, c);\r\n      else add_edge(u, v, c);\r\n    }\r\n  }\r\n  \r\n  vector<int>\
    \ topological_order() const {\r\n    int n = int(this->size());\r\n    vector<int>\
    \ vs, ind(n); vs.reserve(n);\r\n    for(const auto&edges : (*this)){\r\n     \
    \ for(const auto&edge : edges) ++ind[edge.to];\r\n    }\r\n    queue<int> qu;\r\
    \n    for(int v = 0; v < n; ++v){\r\n      if(ind[v] == 0) qu.push(v);\r\n   \
    \ }\r\n    while(!qu.empty()){\r\n      int v = qu.front(); qu.pop();\r\n    \
    \  vs.push_back(v);\r\n      for(const auto &e :  base_t::operator[](v)){\r\n\
    \        if(--ind[e.to] == 0) qu.push(e.to);\r\n      }\r\n    }\r\n    return\
    \ vs;\r\n  }\r\n\r\n  Graph<T> get_directed_tree(int root = 0) const {\r\n   \
    \ Graph<T> tree(this->size());\r\n    queue<pair<int, int>> qu;\r\n    for(qu.emplace(root,\
    \ -1); !qu.empty(); qu.pop()){\r\n      auto[v, p] = qu.front();\r\n      for(const\
    \ auto &e : base_t::operator[](v)){\r\n        if(e.to == p) continue;\r\n   \
    \     tree.add_directed_edge(v, e.to, e.cost);\r\n        qu.emplace(e.to, v);\r\
    \n      }\r\n    }\r\n    return tree;\r\n  }\r\n\r\n  vector<T> bfs_dist(int\
    \ root) const {\r\n    vector<T> dist(this->size());\r\n    queue<pair<int, int>>\
    \ qu;\r\n    for(qu.emplace(root, -1); !qu.empty(); qu.pop()){\r\n      auto[v,\
    \ p] = qu.front();\r\n      for(const auto &e : base_t::operator[](v)){\r\n  \
    \      if(e.to == p) continue;\r\n        dist[e.to] = dist[v] + e.cost;\r\n \
    \       qu.emplace(e.to, v);\r\n      }\r\n    }\r\n    return dist;\r\n  }\r\n\
    };\r\n#line 4 \"graph/shortestpath/EppsteinsAlgorithm.cpp\"\n\r\n#line 2 \"datastructure/heap/PersistentLeftistHeap.cpp\"\
    \n\r\ntemplate<typename T, class Compair = less<T>>\r\nstruct PersistentLeftistHeap{\r\
    \n  struct Node;\r\n  using Np = shared_ptr<Node>;\r\n  template<class... Args>\r\
    \n  static Np make_np(Args&&... args){\r\n      return make_shared<Node>(forward<Args>(args)...);\r\
    \n  }\r\n\r\n  struct Node{\r\n    T val;\r\n    Np l = nullptr, r = nullptr;\r\
    \n    size_t s = 1;\r\n    Node() = default;\r\n    Node(const T &val): val(val)\
    \ {}\r\n    Node(const Node&) = default;\r\n    Node(Node&&) = default;\r\n  \
    \  Node &operator=(const Node&) = default;\r\n    Node &operator=(Node&&) = default;\r\
    \n  };\r\n\r\n  static Np make_root(){ return nullptr; }\r\n  static Np make_clone(Np\
    \ t){ return t ? make_np(*t) : nullptr; }\r\n  static size_t get_s(Np t){ return\
    \ t ? t->s : 0; }\r\n\r\n  Compair cmp;\r\n  \r\n  PersistentLeftistHeap(const\
    \ Compair &cmp = Compair{}): cmp(cmp) {}\r\n\r\n  Np meld(Np a, Np b){\r\n   \
    \ if(!b) return make_clone(a);\r\n    if(!a) return make_clone(b);\r\n    a =\
    \ make_clone(a); b = make_clone(b);\r\n    if(cmp(b->val, a->val)) a.swap(b);\r\
    \n\r\n    a->r = meld(a->r, b);\r\n    if(!a->l || a->l->s < a->r->s) a->l.swap(a->r);\r\
    \n    a->s = get_s(a->r) + 1;\r\n    return a;\r\n  }\r\n  Np push(Np t, const\
    \ T &x){ return meld(t, make_np(x)); }\r\n  Np pop(Np t){ return meld(t->l, t->r);\
    \ }\r\n};\r\n#line 6 \"graph/shortestpath/EppsteinsAlgorithm.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct EppsteinsAlgorithm{\r\n  int n;\r\n  Graph<T> g, rg;\r\n  vector<T>\
    \ rdist;\r\n  vector<vector<int>> chs;\r\n  vector<int> par, idx;\r\n\r\n  EppsteinsAlgorithm(int\
    \ n): n(n), g(n), rg(n) {}\r\n\r\n  void add_directed_edge(int s, int t, const\
    \ T &d){\r\n    g.add_directed_edge(s, t, d);\r\n    rg.add_directed_edge(t, s,\
    \ d);\r\n  }\r\n\r\n  void dijkstra_rev(int t){\r\n    rdist.assign(n, -1);\r\n\
    \    chs.resize(n);\r\n    par.assign(n, -1);\r\n    idx.assign(n, -1);\r\n  \
    \  rdist[t] = 0;\r\n    priority_queue pq{greater<>{}, vector<pair<T, int>>()};\r\
    \n    pq.emplace(0, t);\r\n    vector<bool> seen(n);\r\n    while(!pq.empty()){\r\
    \n      auto[d, v] = pq.top(); pq.pop();\r\n      if(seen[v]) continue;\r\n  \
    \    seen[v] = true;\r\n\r\n      if(par[v] != -1) chs[par[v]].push_back(v);\r\
    \n\r\n      for(const auto& e : rg[v]){\r\n        auto nd = d + e.cost;\r\n \
    \       if(rdist[e] == -1 || nd < rdist[e]){\r\n          rdist[e] = nd;\r\n \
    \         par[e] = v;\r\n          idx[e] = e.idx;\r\n          pq.emplace(nd,\
    \ e);\r\n        }\r\n      }\r\n    }\r\n  }\r\n\r\n  using Heap = PersistentLeftistHeap<pair<T,\
    \ int>>;\r\n  using Np = typename Heap::Np;\r\n  Heap heap;\r\n  vector<Np> h;\r\
    \n\r\n  void build_heap(int t){\r\n    h.assign(n, Heap::make_root());\r\n   \
    \ queue<int> qu; qu.push(t);\r\n    while(!qu.empty()){\r\n      int v = qu.front();\
    \ qu.pop();\r\n\r\n      for(const auto&e : g[v]){\r\n        if(e.idx != idx[v]\
    \ && rdist[e.to] != -1)\r\n          h[v] = heap.push(h[v], {e.cost - rdist[v]\
    \ + rdist[e.to], e.to});\r\n      }\r\n\r\n      if(par[v] != -1) h[v] = heap.meld(h[v],\
    \ h[par[v]]);\r\n      for(int e : chs[v]) qu.push(e);\r\n    }\r\n  }\r\n\r\n\
    \  vector<T> k_shortest_walk(int s, int t, size_t k){\r\n    dijkstra_rev(t);\r\
    \n    if(rdist[s] == -1) return {};\r\n    build_heap(t);\r\n\r\n    using P =\
    \ pair<T, Np>;\r\n\r\n    auto cmp = [&](const P &a, const P &b){ return a.first\
    \ > b.first; };\r\n    priority_queue pq{cmp, vector<P>()};\r\n\r\n    auto get_v\
    \ = [&](const Np &p){ return p->val.first; };\r\n\r\n    Np h_s = Heap::make_root();\r\
    \n    h_s = heap.push(h_s, {rdist[s], s});\r\n    pq.emplace(rdist[s], h_s);\r\
    \n    \r\n    vector<T> ans;\r\n\r\n    while(!pq.empty()){\r\n      auto[d, p]\
    \ = pq.top(); pq.pop();\r\n      auto[cost, to] = p->val;\r\n      ans.push_back(d);\r\
    \n      if(ans.size() == k) break;\r\n\r\n      if(p->l) pq.emplace(d + get_v(p->l)\
    \ - cost, p->l);\r\n      if(p->r) pq.emplace(d + get_v(p->r) - cost, p->r);\r\
    \n      if(h[to]) pq.emplace(d + get_v(h[to]), h[to]);\r\n    }\r\n\r\n    return\
    \ ans;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include \"../Graph.cpp\"\r\n\r\n#include \"../../datastructure/heap/PersistentLeftistHeap.cpp\"\
    \r\n\r\ntemplate<typename T>\r\nstruct EppsteinsAlgorithm{\r\n  int n;\r\n  Graph<T>\
    \ g, rg;\r\n  vector<T> rdist;\r\n  vector<vector<int>> chs;\r\n  vector<int>\
    \ par, idx;\r\n\r\n  EppsteinsAlgorithm(int n): n(n), g(n), rg(n) {}\r\n\r\n \
    \ void add_directed_edge(int s, int t, const T &d){\r\n    g.add_directed_edge(s,\
    \ t, d);\r\n    rg.add_directed_edge(t, s, d);\r\n  }\r\n\r\n  void dijkstra_rev(int\
    \ t){\r\n    rdist.assign(n, -1);\r\n    chs.resize(n);\r\n    par.assign(n, -1);\r\
    \n    idx.assign(n, -1);\r\n    rdist[t] = 0;\r\n    priority_queue pq{greater<>{},\
    \ vector<pair<T, int>>()};\r\n    pq.emplace(0, t);\r\n    vector<bool> seen(n);\r\
    \n    while(!pq.empty()){\r\n      auto[d, v] = pq.top(); pq.pop();\r\n      if(seen[v])\
    \ continue;\r\n      seen[v] = true;\r\n\r\n      if(par[v] != -1) chs[par[v]].push_back(v);\r\
    \n\r\n      for(const auto& e : rg[v]){\r\n        auto nd = d + e.cost;\r\n \
    \       if(rdist[e] == -1 || nd < rdist[e]){\r\n          rdist[e] = nd;\r\n \
    \         par[e] = v;\r\n          idx[e] = e.idx;\r\n          pq.emplace(nd,\
    \ e);\r\n        }\r\n      }\r\n    }\r\n  }\r\n\r\n  using Heap = PersistentLeftistHeap<pair<T,\
    \ int>>;\r\n  using Np = typename Heap::Np;\r\n  Heap heap;\r\n  vector<Np> h;\r\
    \n\r\n  void build_heap(int t){\r\n    h.assign(n, Heap::make_root());\r\n   \
    \ queue<int> qu; qu.push(t);\r\n    while(!qu.empty()){\r\n      int v = qu.front();\
    \ qu.pop();\r\n\r\n      for(const auto&e : g[v]){\r\n        if(e.idx != idx[v]\
    \ && rdist[e.to] != -1)\r\n          h[v] = heap.push(h[v], {e.cost - rdist[v]\
    \ + rdist[e.to], e.to});\r\n      }\r\n\r\n      if(par[v] != -1) h[v] = heap.meld(h[v],\
    \ h[par[v]]);\r\n      for(int e : chs[v]) qu.push(e);\r\n    }\r\n  }\r\n\r\n\
    \  vector<T> k_shortest_walk(int s, int t, size_t k){\r\n    dijkstra_rev(t);\r\
    \n    if(rdist[s] == -1) return {};\r\n    build_heap(t);\r\n\r\n    using P =\
    \ pair<T, Np>;\r\n\r\n    auto cmp = [&](const P &a, const P &b){ return a.first\
    \ > b.first; };\r\n    priority_queue pq{cmp, vector<P>()};\r\n\r\n    auto get_v\
    \ = [&](const Np &p){ return p->val.first; };\r\n\r\n    Np h_s = Heap::make_root();\r\
    \n    h_s = heap.push(h_s, {rdist[s], s});\r\n    pq.emplace(rdist[s], h_s);\r\
    \n    \r\n    vector<T> ans;\r\n\r\n    while(!pq.empty()){\r\n      auto[d, p]\
    \ = pq.top(); pq.pop();\r\n      auto[cost, to] = p->val;\r\n      ans.push_back(d);\r\
    \n      if(ans.size() == k) break;\r\n\r\n      if(p->l) pq.emplace(d + get_v(p->l)\
    \ - cost, p->l);\r\n      if(p->r) pq.emplace(d + get_v(p->r) - cost, p->r);\r\
    \n      if(h[to]) pq.emplace(d + get_v(h[to]), h[to]);\r\n    }\r\n\r\n    return\
    \ ans;\r\n  }\r\n};\r\n"
  dependsOn:
  - graph/Graph.cpp
  - datastructure/heap/PersistentLeftistHeap.cpp
  isVerificationFile: false
  path: graph/shortestpath/EppsteinsAlgorithm.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/shortestpath/EppsteinsAlgorithm.cpp
layout: document
redirect_from:
- /library/graph/shortestpath/EppsteinsAlgorithm.cpp
- /library/graph/shortestpath/EppsteinsAlgorithm.cpp.html
title: graph/shortestpath/EppsteinsAlgorithm.cpp
---
