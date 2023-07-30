---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/Graph.cpp
    title: graph/Graph.cpp
  - icon: ':warning:'
    path: graph/tree/centroid_decomposition/CentroidDecomposition.cpp
    title: graph/tree/centroid_decomposition/CentroidDecomposition.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/tree/centroid_decomposition/ContourAggregationQueryOnTree.cpp\"\
    \n\r\n#line 2 \"graph/tree/centroid_decomposition/CentroidDecomposition.cpp\"\n\
    \r\n#line 2 \"graph/Graph.cpp\"\n\r\ntemplate<typename T = int>\r\nstruct Edge{\r\
    \n  int src, to; T cost; int idx;\r\n  Edge() = default;\r\n  Edge(int src, int\
    \ to, T cost = -1, int idx = -1): src(src), to(to), cost(cost), idx(idx) {}\r\n\
    \  operator int() const { return to; }\r\n};\r\ntemplate<typename T> using Edges\
    \ = vector<Edge<T>>;\r\n\r\ntemplate<typename T = int>\r\nstruct Graph : vector<vector<Edge<T>>>\
    \ {\r\n  using base_t = vector<vector<Edge<T>>>;\r\n  using base_t::base_t;\r\n\
    \  size_t es;\r\n  Graph(size_t n): base_t(n), es(0) {}\r\n\r\n  int deg(int v)\
    \ const { return int(base_t::operator[](v).size()); }\r\n\r\n  void add_edge(int\
    \ src, int to, T cost = 1){\r\n    base_t::operator[](src).emplace_back(src, to,\
    \ cost, es);\r\n    base_t::operator[](to).emplace_back(to, src, cost, es++);\r\
    \n  }\r\n  void add_directed_edge(int src, int to, T cost = 1){\r\n    base_t::operator[](src).emplace_back(src,\
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
    };\r\n#line 4 \"graph/tree/centroid_decomposition/CentroidDecomposition.cpp\"\n\
    \r\ntemplate<typename T>\r\nstruct CentroidDecomposition : Graph<T>{\r\n  using\
    \ base_t = Graph<T>;\r\n  using base_t::base_t;\r\n  CentroidDecomposition() =\
    \ default;\r\n  CentroidDecomposition(size_t n):\r\n    base_t(n), used(n), sz(n),\
    \ parent(n), centroids() {}\r\n  CentroidDecomposition(const base_t &tree):\r\n\
    \    base_t(tree), used(tree.size()), sz(tree.size()), parent(tree.size()), centroids()\
    \ {}\r\n  vector<bool> used;\r\n  vector<size_t> sz;\r\n  vector<int> parent,\
    \ centroids;\r\n\r\n  pair<Graph<int>, int> decomposition(){\r\n    Graph<int>\
    \ decomposition_tree(base_t::size());\r\n    int root = decomposition(0, base_t::size(),\
    \ decomposition_tree);\r\n    return {decomposition_tree, root};\r\n  }\r\n\r\n\
    \  int decomposition(int tmp, size_t size, Graph<int> &decomposition_tree){\r\n\
    \    auto[centroid, subtrees] = findCentroid(tmp, size);\r\n    used[centroid]\
    \ = true;\r\n\r\n    for(auto&&[sub_c, sub_sz] : subtrees){\r\n      decomposition_tree.add_directed_edge(\r\
    \n        centroid, decomposition(sub_c, sub_sz, decomposition_tree), sub_sz);\r\
    \n    }\r\n\r\n    used[centroid] = false;\r\n\r\n    return centroid;\r\n  }\r\
    \n\r\n  pair<int, vector<pair<int,int>> > findCentroid(int root, size_t size){\r\
    \n    vector<pair<int, int> > subtrees;\r\n    centroids.clear();\r\n    findCentroidRec(root,\
    \ size);\r\n    int c = centroids[0];\r\n    for (auto&&e : base_t::operator[](c))\
    \ {\r\n        if(used[e]) continue;\r\n        if(e.to == parent[c]) subtrees.emplace_back(e,\
    \ size-sz[c]);\r\n        else subtrees.emplace_back(e, sz[e]);\r\n    }\r\n \
    \   return {c, subtrees};\r\n  }\r\n\r\n  void findCentroidRec(int v, size_t size,\
    \ int p = -1){\r\n    sz[v] = 1; parent[v] = p;\r\n    bool isCentroid = true;\r\
    \n    for(auto&&e : base_t::operator[](v)){\r\n      if(e.to == p || used[e])\
    \ continue;\r\n      findCentroidRec(e, size, v);\r\n      if(sz[e] > size/2)\
    \ isCentroid = false;\r\n      sz[v] += sz[e];\r\n    }\r\n    if(size-sz[v] >\
    \ size/2) isCentroid = false;\r\n    if(isCentroid) centroids.push_back(v);\r\n\
    \  }\r\n};\r\n#line 4 \"graph/tree/centroid_decomposition/ContourAggregationQueryOnTree.cpp\"\
    \n\r\ntemplate<typename T>\r\nstruct ContourAggregationQueryOnTree{\r\n  ContourAggregationQueryOnTree()\
    \ = default;\r\n  ContourAggregationQueryOnTree(size_t n): decomp(n) {}\r\n  ContourAggregationQueryOnTree(const\
    \ Graph<T> &tree): decomp(tree) { build(); }\r\n\r\n  CentroidDecomposition<T>\
    \ decomp;\r\n  vector<bool> used;\r\n  vector<int> par;\r\n\r\n  vector<int> vs;\r\
    \n  vector<vector<int>> idx;\r\n  vector<vector<tuple<int, int, int>>> id_dist;\r\
    \n  vector<vector<int>> bound;\r\n  vector<vector<vector<pair<int, int>>>> range;\r\
    \n\r\n  void build(){\r\n    int n = int(decomp.size());\r\n    auto[tree, root]\
    \ = decomp.decomposition();\r\n\r\n    used.assign(n, false);\r\n    par.assign(n,\
    \ -1);\r\n\r\n    vs.resize(n); iota(begin(vs), end(vs), 0);\r\n    idx.resize(n);\
    \ for(int i = 0; i < n; ++i) idx[i].push_back(i);\r\n    \r\n    id_dist.resize(n);\r\
    \n    bound.resize(n);\r\n    range.resize(n);\r\n\r\n    queue<int> qu; qu.push(root);\r\
    \n\r\n    while(!qu.empty()){\r\n      int centroid = qu.front(); qu.pop();\r\n\
    \      bfs(centroid);\r\n\r\n      for(auto&e : tree[centroid]){\r\n        par[e.to]\
    \ = centroid;\r\n        qu.emplace(e.to);\r\n      }\r\n    }\r\n  }\r\n\r\n\
    \  size_t vs_size() const { return vs.size(); }\r\n\r\n  void bfs(int c){\r\n\
    \    used[c] = true;\r\n    \r\n    queue<tuple<int, int, int, int>> qu;\r\n \
    \   {\r\n      int id = 0;\r\n      for(auto&e : decomp[c]){\r\n        if(used[e])\
    \ continue;\r\n        qu.emplace(e.to, id++, c, 1);\r\n      }\r\n      range[c].resize(id);\r\
    \n      id_dist[c].emplace_back(c, id, 0);\r\n    }\r\n\r\n    if(qu.empty())\
    \ return;\r\n\r\n    while(!qu.empty()){\r\n      auto[v, id, p, d] = qu.front();\
    \ qu.pop();\r\n      int ord = int(vs.size());\r\n      if(int(bound[c].size())\
    \ <= d - 1) bound[c].push_back(ord);\r\n      if(int(range[c][id].size()) <= d\
    \ - 1) range[c][id].emplace_back(ord, ord + 1);\r\n      else range[c][id][d -\
    \ 1].second = ord + 1;\r\n\r\n      id_dist[v].emplace_back(c, id, d);\r\n   \
    \   idx[v].push_back(ord);\r\n      vs.push_back(v);\r\n\r\n      for(auto&e :\
    \ decomp[v]){\r\n        if(used[e]) continue;\r\n        if(e.to == p) continue;\r\
    \n        qu.emplace(e.to, id, v, d + 1);\r\n      }\r\n    }\r\n    bound[c].push_back(vs.size());\r\
    \n  }\r\n\r\n  vector<int> enumerarte_idx(int v) const { return idx[v]; }\r\n\r\
    \n  template<class Monoid, typename F>\r\n  Monoid query(int v, int d, const F\
    \ &get_val) const {\r\n    Monoid res{};\r\n    for(auto[c, id, dist] : id_dist[v]){\r\
    \n      int nd = d - dist;\r\n      if(nd < 0) continue;\r\n      if(nd == 0){\r\
    \n        res += get_val(c, c + 1);\r\n        continue;\r\n      }\r\n      if(int(bound[c].size())\
    \ <= nd) continue;\r\n      int l = bound[c][nd - 1], r = bound[c][nd];\r\n  \
    \    if(int(range[c].size()) == id || int(range[c][id].size()) <= nd - 1){\r\n\
    \        res += get_val(l, r);\r\n      }else{\r\n        auto[ml, mr] = range[c][id][nd\
    \ - 1];\r\n        res += get_val(l, ml) + get_val(mr, r);\r\n      }\r\n    }\r\
    \n    return res;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include \"./CentroidDecomposition.cpp\"\r\n\r\ntemplate<typename\
    \ T>\r\nstruct ContourAggregationQueryOnTree{\r\n  ContourAggregationQueryOnTree()\
    \ = default;\r\n  ContourAggregationQueryOnTree(size_t n): decomp(n) {}\r\n  ContourAggregationQueryOnTree(const\
    \ Graph<T> &tree): decomp(tree) { build(); }\r\n\r\n  CentroidDecomposition<T>\
    \ decomp;\r\n  vector<bool> used;\r\n  vector<int> par;\r\n\r\n  vector<int> vs;\r\
    \n  vector<vector<int>> idx;\r\n  vector<vector<tuple<int, int, int>>> id_dist;\r\
    \n  vector<vector<int>> bound;\r\n  vector<vector<vector<pair<int, int>>>> range;\r\
    \n\r\n  void build(){\r\n    int n = int(decomp.size());\r\n    auto[tree, root]\
    \ = decomp.decomposition();\r\n\r\n    used.assign(n, false);\r\n    par.assign(n,\
    \ -1);\r\n\r\n    vs.resize(n); iota(begin(vs), end(vs), 0);\r\n    idx.resize(n);\
    \ for(int i = 0; i < n; ++i) idx[i].push_back(i);\r\n    \r\n    id_dist.resize(n);\r\
    \n    bound.resize(n);\r\n    range.resize(n);\r\n\r\n    queue<int> qu; qu.push(root);\r\
    \n\r\n    while(!qu.empty()){\r\n      int centroid = qu.front(); qu.pop();\r\n\
    \      bfs(centroid);\r\n\r\n      for(auto&e : tree[centroid]){\r\n        par[e.to]\
    \ = centroid;\r\n        qu.emplace(e.to);\r\n      }\r\n    }\r\n  }\r\n\r\n\
    \  size_t vs_size() const { return vs.size(); }\r\n\r\n  void bfs(int c){\r\n\
    \    used[c] = true;\r\n    \r\n    queue<tuple<int, int, int, int>> qu;\r\n \
    \   {\r\n      int id = 0;\r\n      for(auto&e : decomp[c]){\r\n        if(used[e])\
    \ continue;\r\n        qu.emplace(e.to, id++, c, 1);\r\n      }\r\n      range[c].resize(id);\r\
    \n      id_dist[c].emplace_back(c, id, 0);\r\n    }\r\n\r\n    if(qu.empty())\
    \ return;\r\n\r\n    while(!qu.empty()){\r\n      auto[v, id, p, d] = qu.front();\
    \ qu.pop();\r\n      int ord = int(vs.size());\r\n      if(int(bound[c].size())\
    \ <= d - 1) bound[c].push_back(ord);\r\n      if(int(range[c][id].size()) <= d\
    \ - 1) range[c][id].emplace_back(ord, ord + 1);\r\n      else range[c][id][d -\
    \ 1].second = ord + 1;\r\n\r\n      id_dist[v].emplace_back(c, id, d);\r\n   \
    \   idx[v].push_back(ord);\r\n      vs.push_back(v);\r\n\r\n      for(auto&e :\
    \ decomp[v]){\r\n        if(used[e]) continue;\r\n        if(e.to == p) continue;\r\
    \n        qu.emplace(e.to, id, v, d + 1);\r\n      }\r\n    }\r\n    bound[c].push_back(vs.size());\r\
    \n  }\r\n\r\n  vector<int> enumerarte_idx(int v) const { return idx[v]; }\r\n\r\
    \n  template<class Monoid, typename F>\r\n  Monoid query(int v, int d, const F\
    \ &get_val) const {\r\n    Monoid res{};\r\n    for(auto[c, id, dist] : id_dist[v]){\r\
    \n      int nd = d - dist;\r\n      if(nd < 0) continue;\r\n      if(nd == 0){\r\
    \n        res += get_val(c, c + 1);\r\n        continue;\r\n      }\r\n      if(int(bound[c].size())\
    \ <= nd) continue;\r\n      int l = bound[c][nd - 1], r = bound[c][nd];\r\n  \
    \    if(int(range[c].size()) == id || int(range[c][id].size()) <= nd - 1){\r\n\
    \        res += get_val(l, r);\r\n      }else{\r\n        auto[ml, mr] = range[c][id][nd\
    \ - 1];\r\n        res += get_val(l, ml) + get_val(mr, r);\r\n      }\r\n    }\r\
    \n    return res;\r\n  }\r\n};\r\n"
  dependsOn:
  - graph/tree/centroid_decomposition/CentroidDecomposition.cpp
  - graph/Graph.cpp
  isVerificationFile: false
  path: graph/tree/centroid_decomposition/ContourAggregationQueryOnTree.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/centroid_decomposition/ContourAggregationQueryOnTree.cpp
layout: document
redirect_from:
- /library/graph/tree/centroid_decomposition/ContourAggregationQueryOnTree.cpp
- /library/graph/tree/centroid_decomposition/ContourAggregationQueryOnTree.cpp.html
title: graph/tree/centroid_decomposition/ContourAggregationQueryOnTree.cpp
---
