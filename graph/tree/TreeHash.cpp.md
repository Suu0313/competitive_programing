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
  bundledCode: "#line 2 \"graph/tree/TreeHash.cpp\"\n\r\n#line 2 \"graph/Graph.cpp\"\
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
    };\r\n#line 4 \"graph/tree/TreeHash.cpp\"\n\r\n#line 2 \"string/RollingHash.cpp\"\
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
    \ }\r\n};\r\n#line 6 \"graph/tree/TreeHash.cpp\"\n\r\n\r\nstruct TreeHash{\r\n\
    \  unordered_map<uint64_t, int> mp;\r\n  RollingHash rh;\r\n  TreeHash(): mp{},\
    \ rh{} {}\r\n\r\n  int to_hash(vector<int> &vs){\r\n    sort(begin(vs), end(vs));\r\
    \n    auto hs = rh.query(rh.build(vs));\r\n    if(mp.find(hs) == mp.end()){\r\n\
    \      int h = int(mp.size()) + 1;\r\n      mp[hs] = h;\r\n    }\r\n    return\
    \ mp[hs];\r\n  }\r\n\r\n  vector<int> to_hash_v(const vector<int> &vs){\r\n  \
    \  int n = int(vs.size());\r\n    auto hs = rh.build(vs);\r\n    vector<int> res(n);\r\
    \n    for(int i = 0; i < n; ++i){\r\n      auto hl = rh.query(hs, 0, i), hr =\
    \ rh.query(hs, i + 1);\r\n      auto nh = rh.cat(hl, hr, vs.size() - i - 1);\r\
    \n      if(mp.find(nh) == mp.end()){\r\n        int h = int(mp.size()) + 1;\r\n\
    \        mp[nh] = h;\r\n      }\r\n      res[i] = mp[nh];\r\n    }\r\n    return\
    \ res;\r\n  }\r\n\r\n  template<typename T>\r\n  vector<int> rooted_AHUHash(Graph<T>\
    \ tree, int r = 0){\r\n    tree = tree.get_directed_tree(r);\r\n    vector<int>\
    \ idx = tree.topological_order();\r\n    reverse(begin(idx), end(idx));\r\n  \
    \  vector<int> dp(idx.size());\r\n    for(int v : idx){\r\n      vector<int> hs;\r\
    \n      for(const auto&e : tree[v]) hs.push_back(dp[e]);\r\n      dp[v] = to_hash(hs);\r\
    \n    }\r\n    return dp;\r\n  }\r\n\r\n  // (v, p): h\r\n  template<typename\
    \ T>\r\n  map<pair<int, int>, int> AHUHash(const Graph<T> &tree){\r\n    map<pair<int,\
    \ int>, int> res;\r\n    vector<int> idx = tree.get_directed_tree(0).topological_order();\r\
    \n    int n = int(idx.size());\r\n    vector<int> rev(n);\r\n    for(int i = 0;\
    \ i < n; ++i) rev[idx[i]] = i;\r\n    vector<int> dp0 = rooted_AHUHash(tree, 0);\r\
    \n\r\n    for(int v : idx){\r\n      vector<pair<int, int>> hs_idx;\r\n      for(const\
    \ auto&e : tree[v]){\r\n        if(rev[v] < rev[e]) hs_idx.emplace_back(dp0[e],\
    \ e.to);\r\n        else hs_idx.emplace_back(res.at(make_pair(e.to, v)), e.to);\r\
    \n      }\r\n      sort(begin(hs_idx), end(hs_idx));\r\n      int m = int(hs_idx.size());\r\
    \n      vector<int> hs(m);\r\n      for(int i = 0; i < m; ++i) hs[i] = hs_idx[i].first;\r\
    \n      vector<int> nhs = to_hash_v(hs);\r\n      for(int i = 0; i < m; ++i) res[make_pair(v,\
    \ hs_idx[i].second)] = nhs[i];\r\n      res[make_pair(v, -1)] = to_hash(hs);\r\
    \n    }\r\n    return res;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include \"../Graph.cpp\"\r\n\r\n#include \"../../string/RollingHash.cpp\"\
    \r\n\r\n\r\nstruct TreeHash{\r\n  unordered_map<uint64_t, int> mp;\r\n  RollingHash\
    \ rh;\r\n  TreeHash(): mp{}, rh{} {}\r\n\r\n  int to_hash(vector<int> &vs){\r\n\
    \    sort(begin(vs), end(vs));\r\n    auto hs = rh.query(rh.build(vs));\r\n  \
    \  if(mp.find(hs) == mp.end()){\r\n      int h = int(mp.size()) + 1;\r\n     \
    \ mp[hs] = h;\r\n    }\r\n    return mp[hs];\r\n  }\r\n\r\n  vector<int> to_hash_v(const\
    \ vector<int> &vs){\r\n    int n = int(vs.size());\r\n    auto hs = rh.build(vs);\r\
    \n    vector<int> res(n);\r\n    for(int i = 0; i < n; ++i){\r\n      auto hl\
    \ = rh.query(hs, 0, i), hr = rh.query(hs, i + 1);\r\n      auto nh = rh.cat(hl,\
    \ hr, vs.size() - i - 1);\r\n      if(mp.find(nh) == mp.end()){\r\n        int\
    \ h = int(mp.size()) + 1;\r\n        mp[nh] = h;\r\n      }\r\n      res[i] =\
    \ mp[nh];\r\n    }\r\n    return res;\r\n  }\r\n\r\n  template<typename T>\r\n\
    \  vector<int> rooted_AHUHash(Graph<T> tree, int r = 0){\r\n    tree = tree.get_directed_tree(r);\r\
    \n    vector<int> idx = tree.topological_order();\r\n    reverse(begin(idx), end(idx));\r\
    \n    vector<int> dp(idx.size());\r\n    for(int v : idx){\r\n      vector<int>\
    \ hs;\r\n      for(const auto&e : tree[v]) hs.push_back(dp[e]);\r\n      dp[v]\
    \ = to_hash(hs);\r\n    }\r\n    return dp;\r\n  }\r\n\r\n  // (v, p): h\r\n \
    \ template<typename T>\r\n  map<pair<int, int>, int> AHUHash(const Graph<T> &tree){\r\
    \n    map<pair<int, int>, int> res;\r\n    vector<int> idx = tree.get_directed_tree(0).topological_order();\r\
    \n    int n = int(idx.size());\r\n    vector<int> rev(n);\r\n    for(int i = 0;\
    \ i < n; ++i) rev[idx[i]] = i;\r\n    vector<int> dp0 = rooted_AHUHash(tree, 0);\r\
    \n\r\n    for(int v : idx){\r\n      vector<pair<int, int>> hs_idx;\r\n      for(const\
    \ auto&e : tree[v]){\r\n        if(rev[v] < rev[e]) hs_idx.emplace_back(dp0[e],\
    \ e.to);\r\n        else hs_idx.emplace_back(res.at(make_pair(e.to, v)), e.to);\r\
    \n      }\r\n      sort(begin(hs_idx), end(hs_idx));\r\n      int m = int(hs_idx.size());\r\
    \n      vector<int> hs(m);\r\n      for(int i = 0; i < m; ++i) hs[i] = hs_idx[i].first;\r\
    \n      vector<int> nhs = to_hash_v(hs);\r\n      for(int i = 0; i < m; ++i) res[make_pair(v,\
    \ hs_idx[i].second)] = nhs[i];\r\n      res[make_pair(v, -1)] = to_hash(hs);\r\
    \n    }\r\n    return res;\r\n  }\r\n};\r\n"
  dependsOn:
  - graph/Graph.cpp
  - string/RollingHash.cpp
  isVerificationFile: false
  path: graph/tree/TreeHash.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/TreeHash.cpp
layout: document
redirect_from:
- /library/graph/tree/TreeHash.cpp
- /library/graph/tree/TreeHash.cpp.html
title: graph/tree/TreeHash.cpp
---
