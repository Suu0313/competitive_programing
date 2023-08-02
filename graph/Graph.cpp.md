---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: dp/chinese_postman_problem.cpp
    title: dp/chinese_postman_problem.cpp
  - icon: ':warning:'
    path: graph/CycleDetection.cpp
    title: graph/CycleDetection.cpp
  - icon: ':warning:'
    path: graph/LowLink.cpp
    title: graph/LowLink.cpp
  - icon: ':warning:'
    path: graph/enumerate_triangles.cpp
    title: graph/enumerate_triangles.cpp
  - icon: ':warning:'
    path: graph/prim.cpp
    title: graph/prim.cpp
  - icon: ':warning:'
    path: graph/shortestpath/EppsteinsAlgorithm.cpp
    title: graph/shortestpath/EppsteinsAlgorithm.cpp
  - icon: ':warning:'
    path: graph/shortestpath/bellmanford.cpp
    title: graph/shortestpath/bellmanford.cpp
  - icon: ':warning:'
    path: graph/shortestpath/dijkstra.cpp
    title: graph/shortestpath/dijkstra.cpp
  - icon: ':warning:'
    path: graph/shortestpath/dijkstra_fibonacci.cpp
    title: graph/shortestpath/dijkstra_fibonacci.cpp
  - icon: ':warning:'
    path: graph/shortestpath/johnson_APSP.cpp
    title: graph/shortestpath/johnson_APSP.cpp
  - icon: ':warning:'
    path: graph/shortestpath/shortest_path_faster_algorithm.cpp
    title: graph/shortestpath/shortest_path_faster_algorithm.cpp
  - icon: ':warning:'
    path: graph/tree/AHUHash.cpp
    title: graph/tree/AHUHash.cpp
  - icon: ':warning:'
    path: graph/tree/HeavyLightDecomposition.cpp
    title: graph/tree/HeavyLightDecomposition.cpp
  - icon: ':warning:'
    path: graph/tree/IsomorphismofTree.cpp
    title: graph/tree/IsomorphismofTree.cpp
  - icon: ':warning:'
    path: graph/tree/TreeDiameter.cpp
    title: graph/tree/TreeDiameter.cpp
  - icon: ':warning:'
    path: graph/tree/TreeHash.cpp
    title: graph/tree/TreeHash.cpp
  - icon: ':warning:'
    path: graph/tree/TreeHeight.cpp
    title: graph/tree/TreeHeight.cpp
  - icon: ':warning:'
    path: graph/tree/centroid_decomposition/CentroidDecomposition.cpp
    title: graph/tree/centroid_decomposition/CentroidDecomposition.cpp
  - icon: ':warning:'
    path: graph/tree/centroid_decomposition/ContourAggregationQueryOnTree.cpp
    title: graph/tree/centroid_decomposition/ContourAggregationQueryOnTree.cpp
  - icon: ':warning:'
    path: graph/tree/lca/LCA-Doubling.cpp
    title: graph/tree/lca/LCA-Doubling.cpp
  - icon: ':warning:'
    path: graph/tree/lca/LCA-RmQ.cpp
    title: graph/tree/lca/LCA-RmQ.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/Graph.cpp\"\n\r\ntemplate<typename T = int>\r\nstruct\
    \ Edge{\r\n  int src, to; T cost; int idx;\r\n  Edge() = default;\r\n  Edge(int\
    \ src, int to, T cost = -1, int idx = -1): src(src), to(to), cost(cost), idx(idx)\
    \ {}\r\n  operator int() const { return to; }\r\n};\r\ntemplate<typename T> using\
    \ Edges = vector<Edge<T>>;\r\n\r\ntemplate<typename T = int>\r\nstruct Graph :\
    \ vector<vector<Edge<T>>> {\r\n  using base_t = vector<vector<Edge<T>>>;\r\n \
    \ using base_t::base_t;\r\n  size_t es;\r\n  Graph(size_t n): base_t(n), es(0)\
    \ {}\r\n\r\n  int deg(int v) const { return int(base_t::operator[](v).size());\
    \ }\r\n\r\n  void add_edge(int src, int to, T cost = 1){\r\n    base_t::operator[](src).emplace_back(src,\
    \ to, cost, es);\r\n    base_t::operator[](to).emplace_back(to, src, cost, es++);\r\
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
    };\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T = int>\r\nstruct Edge{\r\n  int src,\
    \ to; T cost; int idx;\r\n  Edge() = default;\r\n  Edge(int src, int to, T cost\
    \ = -1, int idx = -1): src(src), to(to), cost(cost), idx(idx) {}\r\n  operator\
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
    };\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/Graph.cpp
  requiredBy:
  - dp/chinese_postman_problem.cpp
  - graph/prim.cpp
  - graph/LowLink.cpp
  - graph/CycleDetection.cpp
  - graph/tree/TreeHash.cpp
  - graph/tree/centroid_decomposition/ContourAggregationQueryOnTree.cpp
  - graph/tree/centroid_decomposition/CentroidDecomposition.cpp
  - graph/tree/AHUHash.cpp
  - graph/tree/lca/LCA-Doubling.cpp
  - graph/tree/lca/LCA-RmQ.cpp
  - graph/tree/HeavyLightDecomposition.cpp
  - graph/tree/IsomorphismofTree.cpp
  - graph/tree/TreeDiameter.cpp
  - graph/tree/TreeHeight.cpp
  - graph/enumerate_triangles.cpp
  - graph/shortestpath/johnson_APSP.cpp
  - graph/shortestpath/shortest_path_faster_algorithm.cpp
  - graph/shortestpath/EppsteinsAlgorithm.cpp
  - graph/shortestpath/bellmanford.cpp
  - graph/shortestpath/dijkstra.cpp
  - graph/shortestpath/dijkstra_fibonacci.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/Graph.cpp
layout: document
redirect_from:
- /library/graph/Graph.cpp
- /library/graph/Graph.cpp.html
title: graph/Graph.cpp
---
