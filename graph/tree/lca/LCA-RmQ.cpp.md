---
data:
  _extendedDependsOn:
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
  bundledCode: "#line 2 \"graph/tree/lca/LCA-RmQ.cpp\"\n\r\n#line 2 \"graph/Graph.cpp\"\
    \n\r\ntemplate<typename T = int>\r\nstruct Edge{\r\n  int src, to; T cost; int\
    \ idx;\r\n  Edge() = default;\r\n  Edge(int src, int to, T cost = -1, int idx\
    \ = -1): src(src), to(to), cost(cost), idx(idx) {}\r\n  operator int() const {\
    \ return to; }\r\n};\r\ntemplate<typename T> using Edges = vector<Edge<T>>;\r\n\
    \r\ntemplate<typename T = int>\r\nstruct Graph : vector<vector<Edge<T>>> {\r\n\
    \  using base_t = vector<vector<Edge<T>>>;\r\n  using base_t::base_t;\r\n  size_t\
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
    };\r\n#line 4 \"graph/tree/lca/LCA-RmQ.cpp\"\n\r\ntemplate<typename T = int>\r\
    \nstruct LCA{\r\n  Graph<T> g;\r\n\r\n  LCA() = default;\r\n  LCA(int n): g(n)\
    \ {}\r\n  LCA(const Graph<T> &g, int root = 0, bool cal = true): g(g) {\r\n  \
    \  if(cal) build(root);\r\n  }\r\n\r\n  void build(int root = 0){\r\n    size_t\
    \ n = g.size();\r\n    ord.reserve(n*2 - 1); dep.reserve(n*2 - 1);\r\n    in.resize(n);\
    \ dist.assign(n, 0);\r\n    dfs(root, -1, 0);\r\n    build_sp();\r\n  }\r\n\r\n\
    \  void build(const Graph<T> &g, int root = 0){\r\n    this->g = g;\r\n    build(root);\r\
    \n  }\r\n\r\n  void add_edge(int u, int v, T cost = 1){\r\n    g.add_edge(u, v,\
    \ cost);\r\n  }\r\n\r\n  int lca(int u, int v) const {\r\n    if(in[u] > in[v])\
    \ swap(u, v);\r\n    return u==v ? u : ord[rmq(in[u], in[v])];\r\n  }\r\n\r\n\
    \  int operator()(int u, int v) const {\r\n    return lca(u, v);\r\n  }\r\n\r\n\
    \  int get_dist(int u, int v) const {\r\n    return dist[u] + dist[v] - 2*dist[lca(u,v)];\r\
    \n  }\r\n\r\nprivate:\r\n  vector<int> ord, dep, in, dist;\r\n\r\n  void dfs(int\
    \ v, int p, int d){\r\n    in[v] = (int)ord.size();\r\n    ord.emplace_back(v);\r\
    \n    dep.emplace_back(d);\r\n    for(auto&&e : g[v]){\r\n      if(e.to == p)\
    \ continue;\r\n      dist[e.to] = dist[v] + 1;\r\n      dfs(e.to, v, d+1);\r\n\
    \      ord.emplace_back(v);\r\n      dep.emplace_back(d);\r\n    }\r\n  }\r\n\r\
    \n  vector<vector<int>> st;\r\n  vector<int> lookup;\r\n\r\n  int sp_op(int a,\
    \ int b) const { return dep[a] < dep[b] ? a : b; }\r\n\r\n  void build_sp(){\r\
    \n    int n = int(g.size()), m = n*2 - 1;\r\n    int b = 32 - __builtin_clz(m);\r\
    \n\r\n    st.assign(b, vector<int>(m, 0));\r\n    iota(begin(st[0]), end(st[0]),\
    \ 0);\r\n\r\n    for(int i = 1; i < b; i++){\r\n      for(int j = 0; j+(1<<i)\
    \ <= m; j++){\r\n        st[i][j] = sp_op(st[i-1][j], st[i-1][j+(1<<(i-1))]);\r\
    \n      }\r\n    }\r\n\r\n    lookup.assign(m+1, 0);\r\n    for(int i = 2; i <=\
    \ m; ++i) lookup[i] = lookup[i >> 1] + 1;\r\n  }\r\n\r\n  int rmq(int l, int r)\
    \ const {\r\n    int b = lookup[r - l];\r\n    return sp_op(st[b][l], st[b][r\
    \ - (1<<b)]);\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include \"../../Graph.cpp\"\r\n\r\ntemplate<typename\
    \ T = int>\r\nstruct LCA{\r\n  Graph<T> g;\r\n\r\n  LCA() = default;\r\n  LCA(int\
    \ n): g(n) {}\r\n  LCA(const Graph<T> &g, int root = 0, bool cal = true): g(g)\
    \ {\r\n    if(cal) build(root);\r\n  }\r\n\r\n  void build(int root = 0){\r\n\
    \    size_t n = g.size();\r\n    ord.reserve(n*2 - 1); dep.reserve(n*2 - 1);\r\
    \n    in.resize(n); dist.assign(n, 0);\r\n    dfs(root, -1, 0);\r\n    build_sp();\r\
    \n  }\r\n\r\n  void build(const Graph<T> &g, int root = 0){\r\n    this->g = g;\r\
    \n    build(root);\r\n  }\r\n\r\n  void add_edge(int u, int v, T cost = 1){\r\n\
    \    g.add_edge(u, v, cost);\r\n  }\r\n\r\n  int lca(int u, int v) const {\r\n\
    \    if(in[u] > in[v]) swap(u, v);\r\n    return u==v ? u : ord[rmq(in[u], in[v])];\r\
    \n  }\r\n\r\n  int operator()(int u, int v) const {\r\n    return lca(u, v);\r\
    \n  }\r\n\r\n  int get_dist(int u, int v) const {\r\n    return dist[u] + dist[v]\
    \ - 2*dist[lca(u,v)];\r\n  }\r\n\r\nprivate:\r\n  vector<int> ord, dep, in, dist;\r\
    \n\r\n  void dfs(int v, int p, int d){\r\n    in[v] = (int)ord.size();\r\n   \
    \ ord.emplace_back(v);\r\n    dep.emplace_back(d);\r\n    for(auto&&e : g[v]){\r\
    \n      if(e.to == p) continue;\r\n      dist[e.to] = dist[v] + 1;\r\n      dfs(e.to,\
    \ v, d+1);\r\n      ord.emplace_back(v);\r\n      dep.emplace_back(d);\r\n   \
    \ }\r\n  }\r\n\r\n  vector<vector<int>> st;\r\n  vector<int> lookup;\r\n\r\n \
    \ int sp_op(int a, int b) const { return dep[a] < dep[b] ? a : b; }\r\n\r\n  void\
    \ build_sp(){\r\n    int n = int(g.size()), m = n*2 - 1;\r\n    int b = 32 - __builtin_clz(m);\r\
    \n\r\n    st.assign(b, vector<int>(m, 0));\r\n    iota(begin(st[0]), end(st[0]),\
    \ 0);\r\n\r\n    for(int i = 1; i < b; i++){\r\n      for(int j = 0; j+(1<<i)\
    \ <= m; j++){\r\n        st[i][j] = sp_op(st[i-1][j], st[i-1][j+(1<<(i-1))]);\r\
    \n      }\r\n    }\r\n\r\n    lookup.assign(m+1, 0);\r\n    for(int i = 2; i <=\
    \ m; ++i) lookup[i] = lookup[i >> 1] + 1;\r\n  }\r\n\r\n  int rmq(int l, int r)\
    \ const {\r\n    int b = lookup[r - l];\r\n    return sp_op(st[b][l], st[b][r\
    \ - (1<<b)]);\r\n  }\r\n};\r\n"
  dependsOn:
  - graph/Graph.cpp
  isVerificationFile: false
  path: graph/tree/lca/LCA-RmQ.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/lca/LCA-RmQ.cpp
layout: document
redirect_from:
- /library/graph/tree/lca/LCA-RmQ.cpp
- /library/graph/tree/lca/LCA-RmQ.cpp.html
title: graph/tree/lca/LCA-RmQ.cpp
---
