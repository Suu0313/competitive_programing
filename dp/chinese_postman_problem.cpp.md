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
  bundledCode: "#line 2 \"dp/chinese_postman_problem.cpp\"\n\r\n#line 2 \"graph/Graph.cpp\"\
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
    };\r\n#line 4 \"dp/chinese_postman_problem.cpp\"\n\r\ntemplate<typename T>\r\n\
    T chinese_postman_problem(const Graph<T> &g){\r\n  int n = int(g.size());\r\n\
    \  T sum = 0;\r\n  vector<int> vs;\r\n  T inf = numeric_limits<T>::max();\r\n\
    \  vector dist(n, vector(n, inf));\r\n  for(int v = 0; v < n; ++v) dist[v][v]\
    \ = 0;\r\n\r\n  for(int v = 0; v < n; ++v){\r\n    if(g.deg(v)&1) vs.push_back(v);\r\
    \n    for(auto&e : g[v]){\r\n      sum += e.cost;\r\n      dist[v][e] = min(dist[v][e],\
    \ e.cost);\r\n    }\r\n  }\r\n\r\n  sum /= 2;\r\n  \r\n  for(int k = 0; k < n;\
    \ ++k){\r\n    for(int i = 0; i < n; ++i){\r\n      for(int j = 0; j < n; ++j){\r\
    \n        if(dist[i][k] == inf || dist[k][j] == inf) continue;\r\n        dist[i][j]\
    \ = min(dist[i][j], dist[i][k] + dist[k][j]);\r\n      }\r\n    }\r\n  }\r\n\r\
    \n  int m = int(vs.size());\r\n  vector dp(1<<m, inf); dp[0] = 0;\r\n  for(int\
    \ bit = 0; bit < (1ll << m); ++bit){\r\n    for(int i = 0; i < m; ++i){\r\n  \
    \    for(int j = 0; j < m; ++j){\r\n        if(i == j) continue;\r\n        if((bit>>i&1)\
    \ == 0 || (bit>>j&1) == 0) continue;\r\n        if(dp[bit-(1<<i)-(1<<j)] == inf)\
    \ continue;\r\n        if(dist[vs[i]][vs[j]] == inf) continue;\r\n        dp[bit]\
    \ = min(dp[bit], dp[bit-(1<<i)-(1<<j)] + dist[vs[i]][vs[j]]);\r\n      }\r\n \
    \   }\r\n  }\r\n\r\n  if(dp[(1<<m)-1] == inf) return inf;\r\n  return sum + dp[(1<<m)-1];\r\
    \n}\r\n"
  code: "#pragma once\r\n\r\n#include \"../graph/Graph.cpp\"\r\n\r\ntemplate<typename\
    \ T>\r\nT chinese_postman_problem(const Graph<T> &g){\r\n  int n = int(g.size());\r\
    \n  T sum = 0;\r\n  vector<int> vs;\r\n  T inf = numeric_limits<T>::max();\r\n\
    \  vector dist(n, vector(n, inf));\r\n  for(int v = 0; v < n; ++v) dist[v][v]\
    \ = 0;\r\n\r\n  for(int v = 0; v < n; ++v){\r\n    if(g.deg(v)&1) vs.push_back(v);\r\
    \n    for(auto&e : g[v]){\r\n      sum += e.cost;\r\n      dist[v][e] = min(dist[v][e],\
    \ e.cost);\r\n    }\r\n  }\r\n\r\n  sum /= 2;\r\n  \r\n  for(int k = 0; k < n;\
    \ ++k){\r\n    for(int i = 0; i < n; ++i){\r\n      for(int j = 0; j < n; ++j){\r\
    \n        if(dist[i][k] == inf || dist[k][j] == inf) continue;\r\n        dist[i][j]\
    \ = min(dist[i][j], dist[i][k] + dist[k][j]);\r\n      }\r\n    }\r\n  }\r\n\r\
    \n  int m = int(vs.size());\r\n  vector dp(1<<m, inf); dp[0] = 0;\r\n  for(int\
    \ bit = 0; bit < (1ll << m); ++bit){\r\n    for(int i = 0; i < m; ++i){\r\n  \
    \    for(int j = 0; j < m; ++j){\r\n        if(i == j) continue;\r\n        if((bit>>i&1)\
    \ == 0 || (bit>>j&1) == 0) continue;\r\n        if(dp[bit-(1<<i)-(1<<j)] == inf)\
    \ continue;\r\n        if(dist[vs[i]][vs[j]] == inf) continue;\r\n        dp[bit]\
    \ = min(dp[bit], dp[bit-(1<<i)-(1<<j)] + dist[vs[i]][vs[j]]);\r\n      }\r\n \
    \   }\r\n  }\r\n\r\n  if(dp[(1<<m)-1] == inf) return inf;\r\n  return sum + dp[(1<<m)-1];\r\
    \n}\r\n"
  dependsOn:
  - graph/Graph.cpp
  isVerificationFile: false
  path: dp/chinese_postman_problem.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/chinese_postman_problem.cpp
layout: document
redirect_from:
- /library/dp/chinese_postman_problem.cpp
- /library/dp/chinese_postman_problem.cpp.html
title: dp/chinese_postman_problem.cpp
---
