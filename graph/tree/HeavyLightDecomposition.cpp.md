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
  bundledCode: "#line 2 \"graph/tree/HeavyLightDecomposition.cpp\"\n\n#line 2 \"graph/Graph.cpp\"\
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
    };\r\n#line 4 \"graph/tree/HeavyLightDecomposition.cpp\"\n\ntemplate<typename\
    \ T = int>\nstruct HeavyLightDecomposition{\n  int n;\n  Graph<T> g;\n  vector<int>\
    \ sz, depth, par, in, out, rev, branch;\n  vector<T> dist;\n\n  HeavyLightDecomposition(const\
    \ Graph<T> &g, int root = 0):\n      n(g.size()), g(g),\n      sz(n,0), depth(n,0),\
    \ par(n,0),\n      in(n,0), out(n,0), rev(n,0), branch(n,0), dist(n,0) {\n   \
    \ dfs0(root); dfs(root);\n  }\n\n  int level_ancestor(int v, int k) const {\n\
    \    if(depth[v] < k) return -1;\n    while(1){\n      int u = branch[v];\n  \
    \    if(in[v]-k >= in[u]) return rev[in[v] - k];\n      k -= in[v] - in[u] + 1;\n\
    \      v = par[u];\n    }\n  }\n\n  int jump(int u, int v, int k) const {\n  \
    \  int p = lca(u, v);\n    if(depth[u] + depth[v] - 2*depth[p] < k) return -1;\n\
    \    if(depth[u] - depth[p] >= k) return level_ancestor(u, k);\n    k -= depth[u]\
    \ - depth[p];\n    return level_ancestor(v, depth[v] - depth[p] - k);\n  }\n\n\
    \  int lca(int u, int v) const {\n    for(;; v = par[branch[v]]){\n      if(in[u]\
    \ > in[v]) swap(u, v);\n      if(branch[u] == branch[v]) return u;\n    }\n  }\n\
    \n  T get_dist(int u, int v) const {\n    return dist[u] + dist[v] - 2*dist[lca(u,\
    \ v)];\n  }\n\n  bool cmp_in(int u, int v) const {\n    return in[u] < in[v];\n\
    \  }\n\n  vector<pair<int, int>> auxiliary(vector<int> vs) const {\n    auto cmp\
    \ = [&](int u, int v){ return in[u] < in[v]; };\n    sort(vs.begin(), vs.end(),\
    \ cmp);\n    vs.erase(unique(vs.begin(), vs.end()), vs.end());\n    int k = vs.size();\n\
    \    for(int i = 1; i < k; i++) vs.emplace_back(lca(vs[i-1], vs[i]));\n    sort(vs.begin(),\
    \ vs.end(), cmp);\n    vs.erase(unique(vs.begin(), vs.end()), vs.end());\n   \
    \ vector<pair<int, int>> es;\n    stack<int> st;\n    for(auto&&v : vs){\n   \
    \   while(!st.empty() && out[st.top()] <= in[v]) st.pop();\n      if(!st.empty())\
    \ es.emplace_back(st.top(), v);\n      st.emplace(v);\n    }\n    return es;\n\
    \  }\n\n  int to_vertex(int k) const { return rev[k]; }\n\n  int to_idx(int v)\
    \ const { return in[v]; }\n\n\n  int to_idx(int u, int v) const {\n    if(in[u]\
    \ > in[v]) swap(u, v);\n    assert(par[v] == u);\n    return in[v];\n  }\n  \n\
    \  template<typename Q>\n  void update_vertex(int v, const Q &q) const { q(in[v]);\
    \ }\n\n  template<typename Q>\n  void update_edge(int u, int v, const Q &q) const\
    \ {\n    if(in[u] > in[v]) swap(u, v);\n    assert(par[v] == u);\n    q(in[v]);\n\
    \  }\n\n  template<typename Q>\n  void update_subtree(int v, const Q &q, bool\
    \ isedge = false) const {\n    q(in[v]+isedge, out[v]);\n  }\n\n  template<typename\
    \ Q>\n  void update_path(int u, int v, const Q &q, bool isedge = false) const\
    \ {\n    for(;; v = par[branch[v]]){\n      if(in[u] > in[v]) swap(u, v);\n  \
    \    if(branch[u] == branch[v]) break;\n      q(in[branch[v]], in[v] + 1);\n \
    \   }\n    q(in[u]+isedge, in[v] + 1);\n  }\n\n  vector<pair<int,int>> get_segments(int\
    \ u, int v, bool isedge = false) const {\n    vector<pair<int,int>> l, r;\n  \
    \  while(branch[u] != branch[v]){\n      if(in[u] > in[v]) l.emplace_back(in[u]+1,\
    \ in[branch[u]]), u=par[branch[u]];\n      else r.emplace_back(in[branch[v]],\
    \ in[v]+1), v=par[branch[v]];\n    }\n    if(in[u] > in[v])  l.emplace_back(in[u]+1,\
    \ in[v]+isedge);\n    else r.emplace_back(in[u]+isedge, in[v]+1);\n    reverse(begin(r),\
    \ end(r));\n    for(auto&e : r) l.push_back(e);\n    return l;\n  }\n\n  template<typename\
    \ M, typename F>\n  M query_path(int u, int v, const F &get_val, bool isedge =\
    \ false) const {\n    M l{}, r{};\n    for(;; v = par[branch[v]]){\n      if(in[u]\
    \ > in[v]) swap(u, v), swap(l, r);\n      if(branch[u] == branch[v]) break;\n\
    \      l += get_val(in[branch[v]], in[v] + 1);\n    }\n    return get_val(in[u]+isedge,\
    \ in[v] + 1) + l + r;\n  }\n\n  template<typename U, typename F>\n  U query_subtree(int\
    \ v, const F &f, bool isedge = false) const {\n    return f(in[v]+isedge, out[v]);\n\
    \  }\n\n  template<typename M, typename F1, typename F2>\n  M query_path(int u,\
    \ int v, const F1 &get_val1, const F2 &get_val2, bool isedge) const {\n    M res{};\n\
    \    for(auto&[a, b] : get_segments(u, v, isedge)){\n      if(a > b) res += get_val2(b,\
    \ a);\n      else res += get_val1(a, b);\n    }\n    return res;\n  }\n\nprivate:\n\
    \  void dfs0(int root){\n    stack<int> st;\n    st.emplace(root);\n    par[root]\
    \ = -1;\n    while(!st.empty()){\n      auto v = st.top(); st.pop();\n      if(v\
    \ < n){\n        sz[v] = 1; st.emplace(v + n);\n        if(g[v].size() && g[v][0]\
    \ == par[v]) swap(g[v].front(), g[v].back());\n        \n        for(auto&&to\
    \ : g[v]){\n          if(to == par[v]) continue;\n          depth[to] = depth[v]\
    \ + 1;\n          dist[to] = dist[v] + to.cost;\n          par[to] = v;\n    \
    \      st.emplace(to);\n        }\n      }else{\n        v -= n;\n        for(auto&&to\
    \ : g[v]){\n          sz[v] += sz[to];\n          if(sz[g[v].front()] < sz[to])\
    \ swap(g[v].front(), to);\n        }\n      }\n    }\n  }\n\n  void dfs(int root){\n\
    \    stack<int> st;\n    st.emplace(root);\n    int t = 0;\n    while(!st.empty()){\n\
    \      auto v = st.top(); st.pop();\n      if(v < n){\n        in[v] = t++; rev[in[v]]\
    \ = v;\n        st.emplace(v + n);\n        for(int i = (int)g[v].size()-1; i\
    \ >= 0; i--){\n          auto&&to = g[v][i];\n          if(to == par[v]) continue;\n\
    \          if(g[v].front() == to) branch[to] = branch[v];\n          else branch[to]\
    \ = to;\n          st.emplace(to);\n        }\n      }else{\n        out[v - n]\
    \ = t;\n      }\n    }\n  }\n};\n"
  code: "#pragma once\n\n#include \"../Graph.cpp\"\n\ntemplate<typename T = int>\n\
    struct HeavyLightDecomposition{\n  int n;\n  Graph<T> g;\n  vector<int> sz, depth,\
    \ par, in, out, rev, branch;\n  vector<T> dist;\n\n  HeavyLightDecomposition(const\
    \ Graph<T> &g, int root = 0):\n      n(g.size()), g(g),\n      sz(n,0), depth(n,0),\
    \ par(n,0),\n      in(n,0), out(n,0), rev(n,0), branch(n,0), dist(n,0) {\n   \
    \ dfs0(root); dfs(root);\n  }\n\n  int level_ancestor(int v, int k) const {\n\
    \    if(depth[v] < k) return -1;\n    while(1){\n      int u = branch[v];\n  \
    \    if(in[v]-k >= in[u]) return rev[in[v] - k];\n      k -= in[v] - in[u] + 1;\n\
    \      v = par[u];\n    }\n  }\n\n  int jump(int u, int v, int k) const {\n  \
    \  int p = lca(u, v);\n    if(depth[u] + depth[v] - 2*depth[p] < k) return -1;\n\
    \    if(depth[u] - depth[p] >= k) return level_ancestor(u, k);\n    k -= depth[u]\
    \ - depth[p];\n    return level_ancestor(v, depth[v] - depth[p] - k);\n  }\n\n\
    \  int lca(int u, int v) const {\n    for(;; v = par[branch[v]]){\n      if(in[u]\
    \ > in[v]) swap(u, v);\n      if(branch[u] == branch[v]) return u;\n    }\n  }\n\
    \n  T get_dist(int u, int v) const {\n    return dist[u] + dist[v] - 2*dist[lca(u,\
    \ v)];\n  }\n\n  bool cmp_in(int u, int v) const {\n    return in[u] < in[v];\n\
    \  }\n\n  vector<pair<int, int>> auxiliary(vector<int> vs) const {\n    auto cmp\
    \ = [&](int u, int v){ return in[u] < in[v]; };\n    sort(vs.begin(), vs.end(),\
    \ cmp);\n    vs.erase(unique(vs.begin(), vs.end()), vs.end());\n    int k = vs.size();\n\
    \    for(int i = 1; i < k; i++) vs.emplace_back(lca(vs[i-1], vs[i]));\n    sort(vs.begin(),\
    \ vs.end(), cmp);\n    vs.erase(unique(vs.begin(), vs.end()), vs.end());\n   \
    \ vector<pair<int, int>> es;\n    stack<int> st;\n    for(auto&&v : vs){\n   \
    \   while(!st.empty() && out[st.top()] <= in[v]) st.pop();\n      if(!st.empty())\
    \ es.emplace_back(st.top(), v);\n      st.emplace(v);\n    }\n    return es;\n\
    \  }\n\n  int to_vertex(int k) const { return rev[k]; }\n\n  int to_idx(int v)\
    \ const { return in[v]; }\n\n\n  int to_idx(int u, int v) const {\n    if(in[u]\
    \ > in[v]) swap(u, v);\n    assert(par[v] == u);\n    return in[v];\n  }\n  \n\
    \  template<typename Q>\n  void update_vertex(int v, const Q &q) const { q(in[v]);\
    \ }\n\n  template<typename Q>\n  void update_edge(int u, int v, const Q &q) const\
    \ {\n    if(in[u] > in[v]) swap(u, v);\n    assert(par[v] == u);\n    q(in[v]);\n\
    \  }\n\n  template<typename Q>\n  void update_subtree(int v, const Q &q, bool\
    \ isedge = false) const {\n    q(in[v]+isedge, out[v]);\n  }\n\n  template<typename\
    \ Q>\n  void update_path(int u, int v, const Q &q, bool isedge = false) const\
    \ {\n    for(;; v = par[branch[v]]){\n      if(in[u] > in[v]) swap(u, v);\n  \
    \    if(branch[u] == branch[v]) break;\n      q(in[branch[v]], in[v] + 1);\n \
    \   }\n    q(in[u]+isedge, in[v] + 1);\n  }\n\n  vector<pair<int,int>> get_segments(int\
    \ u, int v, bool isedge = false) const {\n    vector<pair<int,int>> l, r;\n  \
    \  while(branch[u] != branch[v]){\n      if(in[u] > in[v]) l.emplace_back(in[u]+1,\
    \ in[branch[u]]), u=par[branch[u]];\n      else r.emplace_back(in[branch[v]],\
    \ in[v]+1), v=par[branch[v]];\n    }\n    if(in[u] > in[v])  l.emplace_back(in[u]+1,\
    \ in[v]+isedge);\n    else r.emplace_back(in[u]+isedge, in[v]+1);\n    reverse(begin(r),\
    \ end(r));\n    for(auto&e : r) l.push_back(e);\n    return l;\n  }\n\n  template<typename\
    \ M, typename F>\n  M query_path(int u, int v, const F &get_val, bool isedge =\
    \ false) const {\n    M l{}, r{};\n    for(;; v = par[branch[v]]){\n      if(in[u]\
    \ > in[v]) swap(u, v), swap(l, r);\n      if(branch[u] == branch[v]) break;\n\
    \      l += get_val(in[branch[v]], in[v] + 1);\n    }\n    return get_val(in[u]+isedge,\
    \ in[v] + 1) + l + r;\n  }\n\n  template<typename U, typename F>\n  U query_subtree(int\
    \ v, const F &f, bool isedge = false) const {\n    return f(in[v]+isedge, out[v]);\n\
    \  }\n\n  template<typename M, typename F1, typename F2>\n  M query_path(int u,\
    \ int v, const F1 &get_val1, const F2 &get_val2, bool isedge) const {\n    M res{};\n\
    \    for(auto&[a, b] : get_segments(u, v, isedge)){\n      if(a > b) res += get_val2(b,\
    \ a);\n      else res += get_val1(a, b);\n    }\n    return res;\n  }\n\nprivate:\n\
    \  void dfs0(int root){\n    stack<int> st;\n    st.emplace(root);\n    par[root]\
    \ = -1;\n    while(!st.empty()){\n      auto v = st.top(); st.pop();\n      if(v\
    \ < n){\n        sz[v] = 1; st.emplace(v + n);\n        if(g[v].size() && g[v][0]\
    \ == par[v]) swap(g[v].front(), g[v].back());\n        \n        for(auto&&to\
    \ : g[v]){\n          if(to == par[v]) continue;\n          depth[to] = depth[v]\
    \ + 1;\n          dist[to] = dist[v] + to.cost;\n          par[to] = v;\n    \
    \      st.emplace(to);\n        }\n      }else{\n        v -= n;\n        for(auto&&to\
    \ : g[v]){\n          sz[v] += sz[to];\n          if(sz[g[v].front()] < sz[to])\
    \ swap(g[v].front(), to);\n        }\n      }\n    }\n  }\n\n  void dfs(int root){\n\
    \    stack<int> st;\n    st.emplace(root);\n    int t = 0;\n    while(!st.empty()){\n\
    \      auto v = st.top(); st.pop();\n      if(v < n){\n        in[v] = t++; rev[in[v]]\
    \ = v;\n        st.emplace(v + n);\n        for(int i = (int)g[v].size()-1; i\
    \ >= 0; i--){\n          auto&&to = g[v][i];\n          if(to == par[v]) continue;\n\
    \          if(g[v].front() == to) branch[to] = branch[v];\n          else branch[to]\
    \ = to;\n          st.emplace(to);\n        }\n      }else{\n        out[v - n]\
    \ = t;\n      }\n    }\n  }\n};\n"
  dependsOn:
  - graph/Graph.cpp
  isVerificationFile: false
  path: graph/tree/HeavyLightDecomposition.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/HeavyLightDecomposition.cpp
layout: document
redirect_from:
- /library/graph/tree/HeavyLightDecomposition.cpp
- /library/graph/tree/HeavyLightDecomposition.cpp.html
title: graph/tree/HeavyLightDecomposition.cpp
---
