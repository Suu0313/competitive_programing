---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/Graph.cpp
    title: graph/Graph.cpp
  - icon: ':warning:'
    path: string/RollingHash.cpp
    title: string/RollingHash.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/tree/AHUHash.cpp\"\n\r\n#line 2 \"graph/Graph.cpp\"\
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
    };\r\n#line 4 \"graph/tree/AHUHash.cpp\"\n\r\n#line 2 \"string/RollingHash.cpp\"\
    \n\r\nstruct RollingHash{\r\n  static constexpr uint64_t mod = (1ull << 61) -\
    \ 1;\r\n  static constexpr uint64_t mask(int k){ return (1ull << k) - 1; }\r\n\
    \  static constexpr uint64_t add(uint64_t a, uint64_t b){\r\n    return ((a+=b)\
    \ >= mod) ? (a - mod) : a;\r\n  }\r\n  static constexpr uint64_t mul(uint64_t\
    \ a, uint64_t b){\r\n    uint64_t au = a >> 31, ad = a & mask(31);\r\n    uint64_t\
    \ bu = b >> 31, bd = b & mask(31);\r\n    int64_t mid = ad*bu + au*bd;\r\n   \
    \ uint64_t mu = mid >> 30, md = mid & mask(30);\r\n    return au*bu*2 + mu + (md\
    \ << 31) + ad*bd;\r\n  }\r\n  static constexpr uint64_t cal_mod(uint64_t x){\r\
    \n    uint64_t res = (x >> 61) + (x & mask(61));\r\n    return (res>=mod) ? (res-mod)\
    \ : res;\r\n  }\r\n\r\n  static inline uint64_t generate_base(){\r\n    mt19937_64\
    \ mt(random_device{}());\r\n    uniform_int_distribution<uint64_t> rand(1, mod-1);\r\
    \n    return rand(mt);\r\n  }\r\n\r\n  inline void expand(size_t n){\r\n    if(size_t\
    \ pn = pow_table.size(); pn < n+1){\r\n      pow_table.resize(n + 1);\r\n    \
    \  for(size_t i = pn-1; i < n; ++i){\r\n        pow_table[i+1] = cal_mod(mul(pow_table[i],\
    \ base));\r\n      }\r\n    }\r\n  }\r\n\r\n  const uint64_t base;\r\n  vector<uint64_t>\
    \ pow_table;\r\n\r\n  RollingHash(uint64_t base = generate_base()): base(base),\
    \ pow_table(1,1) {}\r\n\r\n  vector<uint64_t> build(const string &s) const {\r\
    \n    int n = int(s.size());\r\n    vector<uint64_t> res(n + 1);\r\n    for(int\
    \ i = 0; i < n; ++i) res[i+1] = cal_mod(mul(res[i], base) + s[i]);\r\n    return\
    \ res;\r\n  }\r\n\r\n  template<typename T>\r\n  vector<uint64_t> build(const\
    \ vector<T> &s) const {\r\n    int n = int(s.size());\r\n    vector<uint64_t>\
    \ res(n + 1);\r\n    for(int i = 0; i < n; ++i) res[i+1] = cal_mod(mul(res[i],\
    \ base) + s[i]);\r\n    return res;\r\n  }\r\n\r\n  uint64_t query(const vector<uint64_t>\
    \ &s, int l = 0, size_t n = string::npos){\r\n    n = min(n, s.size()-1 - l);\r\
    \n    expand(n);\r\n    return cal_mod(s[l+n] + mod*4 - mul(s[l], pow_table[n]));\r\
    \n  }\r\n\r\n  uint64_t cat(uint64_t hl, uint64_t hr, size_t hr_len){\r\n    expand(hr_len);\r\
    \n    return cal_mod(mul(hl, pow_table[hr_len]) + hr);\r\n  }\r\n\r\n  int lcp(const\
    \ vector<uint64_t> &a, int la, int ra, const vector<uint64_t> &b, int lb, int\
    \ rb){\r\n    int n = min(ra - la, rb - lb);\r\n    int l = 0, r = n+1;\r\n  \
    \  while(r-l > 1){\r\n      int m = (l+r) >> 1;\r\n      if(query(a, la, m) ==\
    \ query(b, lb, m)) l = m;\r\n      else r = m;\r\n    }\r\n    return l;\r\n \
    \ }\r\n};\r\n#line 6 \"graph/tree/AHUHash.cpp\"\n\r\ntemplate<typename T>\r\n\
    struct IsomorphismofTree{\r\n  unordered_map<uint64_t, int> mp;\r\n  RollingHash\
    \ rh;\r\n \r\n  IsomorphismofTree(): mp{}, rh{} {}\r\n \r\n  bool Isomorphism(const\
    \ Graph<T> &tree1, const Graph<T> &tree2){\r\n    auto cs1 = CenterofTree(tree1),\
    \ cs2 = CenterofTree(tree2);\r\n    for(auto&c1 : cs1)for(auto&c2 : cs2){\r\n\
    \      if(AHUHash(tree1, c1) == AHUHash(tree2, c2)) return true;\r\n    }\r\n\
    \    return false;\r\n  }\r\n \r\n  bool Isomorphism(const Graph<T> &tree1, int\
    \ p1, const Graph<T> &tree2, int p2){\r\n    return (AHUHash(tree1, p1) == AHUHash(tree2,\
    \ p2));\r\n  }\r\n \r\n  int AHUHash(const Graph<T> &tree, int v, int p = -1){\r\
    \n    vector<int> res;\r\n    for(auto&e : tree[v]){\r\n      if(e.to == p) continue;\r\
    \n      res.emplace_back(AHUHash(tree, e.to, v));\r\n    }\r\n    sort(begin(res),\
    \ end(res));\r\n    auto hs = rh.query(rh.build(res));\r\n    if(mp.find(hs) ==\
    \ mp.end()){\r\n      int h = int(mp.size()) + 1;\r\n      mp[hs] = h;\r\n   \
    \ }\r\n    return mp[hs];\r\n  }\r\n \r\n  vector<int> CenterofTree(const Graph<T>\
    \ &tree, int p = 0){\r\n    auto[dist, par]  = bfs(tree, p);\r\n    int u = max_element(begin(dist),\
    \ end(dist)) - begin(dist);\r\n \r\n    tie(dist, par) = bfs(tree, u);\r\n   \
    \ auto it = max_element(begin(dist), end(dist));\r\n    int dmax = *it, v = it\
    \ - begin(dist);\r\n \r\n    for(int i = 0; i < dmax/2; ++i) v = par[v];\r\n \r\
    \n    if(dmax%2 == 0) return {v};\r\n    return {v, par[v]};\r\n  }\r\n \r\n \
    \ pair<vector<int>, vector<int>> bfs(const Graph<T> &tree, int pp = 0){\r\n  \
    \  int n = int(tree.size());\r\n    vector<int> dist(n, -1), par(n, -1);\r\n \
    \   dist[pp] = 0;\r\n    queue<pair<int, int>> qu;\r\n    for(qu.emplace(pp, -1);\
    \ !qu.empty(); qu.pop()){\r\n      auto[v, p] = qu.front();\r\n      for(auto&e\
    \ : tree[v]){\r\n        if(e.to == p) continue;\r\n        par[e.to] = v;\r\n\
    \        dist[e.to] = dist[v] + 1;\r\n        qu.emplace(e.to, v);\r\n      }\r\
    \n    }\r\n    return {dist, par};\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include \"../Graph.cpp\"\r\n\r\n#include \"../../string/RollingHash.cpp\"\
    \r\n\r\ntemplate<typename T>\r\nstruct IsomorphismofTree{\r\n  unordered_map<uint64_t,\
    \ int> mp;\r\n  RollingHash rh;\r\n \r\n  IsomorphismofTree(): mp{}, rh{} {}\r\
    \n \r\n  bool Isomorphism(const Graph<T> &tree1, const Graph<T> &tree2){\r\n \
    \   auto cs1 = CenterofTree(tree1), cs2 = CenterofTree(tree2);\r\n    for(auto&c1\
    \ : cs1)for(auto&c2 : cs2){\r\n      if(AHUHash(tree1, c1) == AHUHash(tree2, c2))\
    \ return true;\r\n    }\r\n    return false;\r\n  }\r\n \r\n  bool Isomorphism(const\
    \ Graph<T> &tree1, int p1, const Graph<T> &tree2, int p2){\r\n    return (AHUHash(tree1,\
    \ p1) == AHUHash(tree2, p2));\r\n  }\r\n \r\n  int AHUHash(const Graph<T> &tree,\
    \ int v, int p = -1){\r\n    vector<int> res;\r\n    for(auto&e : tree[v]){\r\n\
    \      if(e.to == p) continue;\r\n      res.emplace_back(AHUHash(tree, e.to, v));\r\
    \n    }\r\n    sort(begin(res), end(res));\r\n    auto hs = rh.query(rh.build(res));\r\
    \n    if(mp.find(hs) == mp.end()){\r\n      int h = int(mp.size()) + 1;\r\n  \
    \    mp[hs] = h;\r\n    }\r\n    return mp[hs];\r\n  }\r\n \r\n  vector<int> CenterofTree(const\
    \ Graph<T> &tree, int p = 0){\r\n    auto[dist, par]  = bfs(tree, p);\r\n    int\
    \ u = max_element(begin(dist), end(dist)) - begin(dist);\r\n \r\n    tie(dist,\
    \ par) = bfs(tree, u);\r\n    auto it = max_element(begin(dist), end(dist));\r\
    \n    int dmax = *it, v = it - begin(dist);\r\n \r\n    for(int i = 0; i < dmax/2;\
    \ ++i) v = par[v];\r\n \r\n    if(dmax%2 == 0) return {v};\r\n    return {v, par[v]};\r\
    \n  }\r\n \r\n  pair<vector<int>, vector<int>> bfs(const Graph<T> &tree, int pp\
    \ = 0){\r\n    int n = int(tree.size());\r\n    vector<int> dist(n, -1), par(n,\
    \ -1);\r\n    dist[pp] = 0;\r\n    queue<pair<int, int>> qu;\r\n    for(qu.emplace(pp,\
    \ -1); !qu.empty(); qu.pop()){\r\n      auto[v, p] = qu.front();\r\n      for(auto&e\
    \ : tree[v]){\r\n        if(e.to == p) continue;\r\n        par[e.to] = v;\r\n\
    \        dist[e.to] = dist[v] + 1;\r\n        qu.emplace(e.to, v);\r\n      }\r\
    \n    }\r\n    return {dist, par};\r\n  }\r\n};\r\n"
  dependsOn:
  - graph/Graph.cpp
  - string/RollingHash.cpp
  isVerificationFile: false
  path: graph/tree/AHUHash.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/AHUHash.cpp
layout: document
redirect_from:
- /library/graph/tree/AHUHash.cpp
- /library/graph/tree/AHUHash.cpp.html
title: graph/tree/AHUHash.cpp
---
