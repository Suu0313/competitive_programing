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
  bundledCode: "#line 2 \"datastructure/flow/MinimumCostFlow.cpp\"\n\r\ntemplate<typename\
    \ cap_t, typename cost_t>\r\nstruct PrimalDual{\r\n  struct Edge{\r\n    int to;\r\
    \n    cap_t cap;\r\n    cost_t cost;\r\n    size_t rev_idx;\r\n    bool is_rev;\r\
    \n  };\r\n\r\n  int n;\r\n  vector<vector<Edge>> g;\r\n  vector<cost_t> min_cost,\
    \ potential;\r\n  \r\n  PrimalDual(int n): n(n), g(n), min_cost(n), potential(n)\
    \ {}\r\n\r\n  void add_edge(int from, int to, cap_t cap, cost_t cost){\r\n   \
    \ g[from].emplace_back((Edge){to, cap, cost, g[to].size(), false});\r\n    g[to].emplace_back((Edge){from,\
    \ 0, -cost, g[from].size()-1, true});\r\n  }\r\n\r\n  cost_t flow(int s, int t,\
    \ cap_t flow_limit){\r\n    using P = pair<cost_t, int>;\r\n    priority_queue<P,\
    \ vector<P>, greater<P>> pq;\r\n    cost_t res = 0, inf = numeric_limits<cost_t>::max();\r\
    \n    vector<pair<int, int>> pre(n);\r\n\r\n    while(flow_limit > 0){\r\n   \
    \   pq.emplace(0, s);\r\n      min_cost.assign(n, inf);\r\n      min_cost[s] =\
    \ 0;\r\n\r\n      while(!pq.empty()){\r\n        auto[cost, v] = pq.top(); pq.pop();\r\
    \n        if(min_cost[v] < cost) continue;\r\n        for(int i = 0, m = int(g[v].size());\
    \ i < m; ++i){\r\n          Edge &e = g[v][i];\r\n          cost_t ncost = cost\
    \ + e.cost + potential[v] - potential[e.to];\r\n          \r\n          if(e.cap\
    \ > 0 && min_cost[e.to] > ncost){\r\n            assert(ncost >= 0);\r\n     \
    \       min_cost[e.to] = ncost;\r\n            pq.emplace(ncost, e.to);\r\n  \
    \          pre[e.to] = make_pair(v, i);\r\n          }\r\n        }\r\n      }\r\
    \n\r\n      if(min_cost[t] == inf) return -1;\r\n      for(int v = 0; v < n; ++v)\
    \ if(min_cost[v] != inf) potential[v] += min_cost[v];\r\n      cap_t min_cap =\
    \ flow_limit;\r\n      for(int v = t; v != s; v = pre[v].first){\r\n        auto[i,\
    \ j] = pre[v];\r\n        min_cap = min(min_cap, g[i][j].cap);\r\n      }\r\n\
    \      for(int v = t; v != s; v = pre[v].first){\r\n        auto[i, j] = pre[v];\r\
    \n        g[i][j].cap -= min_cap;\r\n        g[v][g[i][j].rev_idx].cap += min_cap;\r\
    \n      }\r\n      flow_limit -= min_cap;\r\n      res += min_cap * potential[t];\r\
    \n    }\r\n    return res;\r\n  }\r\n\r\n  vector<cost_t> slope(int s, int t,\
    \ cap_t flow_limit){\r\n    using P = pair<cost_t, int>;\r\n    priority_queue<P,\
    \ vector<P>, greater<P>> pq;\r\n    cost_t inf = numeric_limits<cost_t>::max();\r\
    \n    vector<pair<int, int>> pre(n);\r\n\r\n    vector<cost_t> ret(1, 0);\r\n\r\
    \n    while(flow_limit > 0){\r\n      pq.emplace(0, s);\r\n      min_cost.assign(n,\
    \ inf);\r\n      min_cost[s] = 0;\r\n\r\n      while(!pq.empty()){\r\n       \
    \ auto[cost, v] = pq.top(); pq.pop();\r\n        if(min_cost[v] < cost) continue;\r\
    \n        for(int i = 0, m = int(g[v].size()); i < m; ++i){\r\n          Edge\
    \ &e = g[v][i];\r\n          cost_t ncost = cost + e.cost + potential[v] - potential[e.to];\r\
    \n          \r\n          if(e.cap > 0 && min_cost[e.to] > ncost){\r\n       \
    \     assert(ncost >= 0);\r\n            min_cost[e.to] = ncost;\r\n         \
    \   pq.emplace(ncost, e.to);\r\n            pre[e.to] = make_pair(v, i);\r\n \
    \         }\r\n        }\r\n      }\r\n\r\n      if(min_cost[t] == inf) return\
    \ ret;\r\n      for(int v = 0; v < n; ++v) if(min_cost[v] != inf) potential[v]\
    \ += min_cost[v];\r\n      cap_t min_cap = flow_limit;\r\n      for(int v = t;\
    \ v != s; v = pre[v].first){\r\n        auto[i, j] = pre[v];\r\n        min_cap\
    \ = min(min_cap, g[i][j].cap);\r\n      }\r\n      for(int v = t; v != s; v =\
    \ pre[v].first){\r\n        auto[i, j] = pre[v];\r\n        g[i][j].cap -= min_cap;\r\
    \n        g[v][g[i][j].rev_idx].cap += min_cap;\r\n      }\r\n      flow_limit\
    \ -= min_cap;\r\n      for(cap_t i = 0; i < min_cap; ++i){\r\n        ret.push_back(ret.back()\
    \ + potential[t]);\r\n      }\r\n    }\r\n    return ret;\r\n  }\r\n\r\n  vector<pair<cap_t,\
    \ cost_t>> slope_sparse(int s, int t, cap_t flow_limit){\r\n    // ToDo\r\n  }\r\
    \n\r\n  void remove_minus_dag(int s){\r\n    queue<int> qu;\r\n    vector<int>\
    \ in(n);\r\n    cost_t inf = numeric_limits<cost_t>::max();\r\n    potential.assign(n,\
    \ inf); potential[s] = 0;\r\n\r\n    for(int i = 0; i < n; ++i){\r\n      for(auto&&e\
    \ : g[i]){\r\n        if(e.is_rev) continue;\r\n        ++in[e.to];\r\n      }\r\
    \n    }\r\n\r\n    for(int i = 0; i < n; ++i) if(in[i] == 0) qu.push(i);\r\n\r\
    \n    while(!qu.empty()){\r\n      int v = qu.front(); qu.pop();\r\n      for(auto&&e\
    \ : g[v]){\r\n        if(e.is_rev) continue;\r\n        if(potential[v] != inf){\r\
    \n          potential[e.to] = min(potential[e.to], potential[v] + e.cost);\r\n\
    \        }\r\n        if(--in[e.to] == 0) qu.push(e.to);\r\n      }\r\n    }\r\
    \n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename cap_t, typename cost_t>\r\nstruct PrimalDual{\r\
    \n  struct Edge{\r\n    int to;\r\n    cap_t cap;\r\n    cost_t cost;\r\n    size_t\
    \ rev_idx;\r\n    bool is_rev;\r\n  };\r\n\r\n  int n;\r\n  vector<vector<Edge>>\
    \ g;\r\n  vector<cost_t> min_cost, potential;\r\n  \r\n  PrimalDual(int n): n(n),\
    \ g(n), min_cost(n), potential(n) {}\r\n\r\n  void add_edge(int from, int to,\
    \ cap_t cap, cost_t cost){\r\n    g[from].emplace_back((Edge){to, cap, cost, g[to].size(),\
    \ false});\r\n    g[to].emplace_back((Edge){from, 0, -cost, g[from].size()-1,\
    \ true});\r\n  }\r\n\r\n  cost_t flow(int s, int t, cap_t flow_limit){\r\n   \
    \ using P = pair<cost_t, int>;\r\n    priority_queue<P, vector<P>, greater<P>>\
    \ pq;\r\n    cost_t res = 0, inf = numeric_limits<cost_t>::max();\r\n    vector<pair<int,\
    \ int>> pre(n);\r\n\r\n    while(flow_limit > 0){\r\n      pq.emplace(0, s);\r\
    \n      min_cost.assign(n, inf);\r\n      min_cost[s] = 0;\r\n\r\n      while(!pq.empty()){\r\
    \n        auto[cost, v] = pq.top(); pq.pop();\r\n        if(min_cost[v] < cost)\
    \ continue;\r\n        for(int i = 0, m = int(g[v].size()); i < m; ++i){\r\n \
    \         Edge &e = g[v][i];\r\n          cost_t ncost = cost + e.cost + potential[v]\
    \ - potential[e.to];\r\n          \r\n          if(e.cap > 0 && min_cost[e.to]\
    \ > ncost){\r\n            assert(ncost >= 0);\r\n            min_cost[e.to] =\
    \ ncost;\r\n            pq.emplace(ncost, e.to);\r\n            pre[e.to] = make_pair(v,\
    \ i);\r\n          }\r\n        }\r\n      }\r\n\r\n      if(min_cost[t] == inf)\
    \ return -1;\r\n      for(int v = 0; v < n; ++v) if(min_cost[v] != inf) potential[v]\
    \ += min_cost[v];\r\n      cap_t min_cap = flow_limit;\r\n      for(int v = t;\
    \ v != s; v = pre[v].first){\r\n        auto[i, j] = pre[v];\r\n        min_cap\
    \ = min(min_cap, g[i][j].cap);\r\n      }\r\n      for(int v = t; v != s; v =\
    \ pre[v].first){\r\n        auto[i, j] = pre[v];\r\n        g[i][j].cap -= min_cap;\r\
    \n        g[v][g[i][j].rev_idx].cap += min_cap;\r\n      }\r\n      flow_limit\
    \ -= min_cap;\r\n      res += min_cap * potential[t];\r\n    }\r\n    return res;\r\
    \n  }\r\n\r\n  vector<cost_t> slope(int s, int t, cap_t flow_limit){\r\n    using\
    \ P = pair<cost_t, int>;\r\n    priority_queue<P, vector<P>, greater<P>> pq;\r\
    \n    cost_t inf = numeric_limits<cost_t>::max();\r\n    vector<pair<int, int>>\
    \ pre(n);\r\n\r\n    vector<cost_t> ret(1, 0);\r\n\r\n    while(flow_limit > 0){\r\
    \n      pq.emplace(0, s);\r\n      min_cost.assign(n, inf);\r\n      min_cost[s]\
    \ = 0;\r\n\r\n      while(!pq.empty()){\r\n        auto[cost, v] = pq.top(); pq.pop();\r\
    \n        if(min_cost[v] < cost) continue;\r\n        for(int i = 0, m = int(g[v].size());\
    \ i < m; ++i){\r\n          Edge &e = g[v][i];\r\n          cost_t ncost = cost\
    \ + e.cost + potential[v] - potential[e.to];\r\n          \r\n          if(e.cap\
    \ > 0 && min_cost[e.to] > ncost){\r\n            assert(ncost >= 0);\r\n     \
    \       min_cost[e.to] = ncost;\r\n            pq.emplace(ncost, e.to);\r\n  \
    \          pre[e.to] = make_pair(v, i);\r\n          }\r\n        }\r\n      }\r\
    \n\r\n      if(min_cost[t] == inf) return ret;\r\n      for(int v = 0; v < n;\
    \ ++v) if(min_cost[v] != inf) potential[v] += min_cost[v];\r\n      cap_t min_cap\
    \ = flow_limit;\r\n      for(int v = t; v != s; v = pre[v].first){\r\n       \
    \ auto[i, j] = pre[v];\r\n        min_cap = min(min_cap, g[i][j].cap);\r\n   \
    \   }\r\n      for(int v = t; v != s; v = pre[v].first){\r\n        auto[i, j]\
    \ = pre[v];\r\n        g[i][j].cap -= min_cap;\r\n        g[v][g[i][j].rev_idx].cap\
    \ += min_cap;\r\n      }\r\n      flow_limit -= min_cap;\r\n      for(cap_t i\
    \ = 0; i < min_cap; ++i){\r\n        ret.push_back(ret.back() + potential[t]);\r\
    \n      }\r\n    }\r\n    return ret;\r\n  }\r\n\r\n  vector<pair<cap_t, cost_t>>\
    \ slope_sparse(int s, int t, cap_t flow_limit){\r\n    // ToDo\r\n  }\r\n\r\n\
    \  void remove_minus_dag(int s){\r\n    queue<int> qu;\r\n    vector<int> in(n);\r\
    \n    cost_t inf = numeric_limits<cost_t>::max();\r\n    potential.assign(n, inf);\
    \ potential[s] = 0;\r\n\r\n    for(int i = 0; i < n; ++i){\r\n      for(auto&&e\
    \ : g[i]){\r\n        if(e.is_rev) continue;\r\n        ++in[e.to];\r\n      }\r\
    \n    }\r\n\r\n    for(int i = 0; i < n; ++i) if(in[i] == 0) qu.push(i);\r\n\r\
    \n    while(!qu.empty()){\r\n      int v = qu.front(); qu.pop();\r\n      for(auto&&e\
    \ : g[v]){\r\n        if(e.is_rev) continue;\r\n        if(potential[v] != inf){\r\
    \n          potential[e.to] = min(potential[e.to], potential[v] + e.cost);\r\n\
    \        }\r\n        if(--in[e.to] == 0) qu.push(e.to);\r\n      }\r\n    }\r\
    \n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/flow/MinimumCostFlow.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/flow/MinimumCostFlow.cpp
layout: document
redirect_from:
- /library/datastructure/flow/MinimumCostFlow.cpp
- /library/datastructure/flow/MinimumCostFlow.cpp.html
title: datastructure/flow/MinimumCostFlow.cpp
---
