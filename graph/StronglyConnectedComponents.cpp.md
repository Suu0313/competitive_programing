---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/TwoSat.cpp
    title: graph/TwoSat.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/StronglyConnectedComponents.cpp\"\n\nstruct StronglyConnectedComponents{\n\
    \  int n;\n  vector<vector<int>> G, rG;\n\n  int group;\n  vector<int> compo,\
    \ order;\n  vector<bool> used;\n\n  template<typename T>\n  StronglyConnectedComponents(const\
    \ T &g, bool cal = true):n(g.size()), G(n), rG(n){\n    for(int i = 0; i < n;\
    \ i++){\n      for(auto&&e : g[i]){\n        G[i].emplace_back(e.to);\n      \
    \  rG[e.to].emplace_back(i);\n      }\n    }\n    if(cal) build();\n  }\n  StronglyConnectedComponents(int\
    \ n):n(n), G(n), rG(n){}\n\n  int at(int k) const { return compo.at(k); }\n  int\
    \ operator[](int k) const { return compo.at(k); }\n\n  void add_edge(int u, int\
    \ v){\n    G[u].emplace_back(v);\n    rG[v].emplace_back(u);\n  }\n\n  void build(){\n\
    \    compo.assign(n,-1);\n    used.assign(n,false);\n    order.clear(); order.reserve(n);\n\
    \    group = 0;\n\n    for(int i = 0; i < n; i++) dfs(i);\n    reverse(order.begin(),\
    \ order.end());\n    for(auto&&e : order){\n      if(compo.at(e) == -1){\n   \
    \     rdfs(e,group);\n        group++;\n      }\n    }\n  }\n\n  bool is_same(int\
    \ u, int v) const { return compo.at(u) == compo.at(v); }\n\n  vector<vector<int>>\
    \ reconstruct() const {\n    vector<vector<int>> ret(group);\n    for(int i =\
    \ 0; i < n; i++){\n      for(auto to : G.at(i)){\n        int s = compo.at(i);\n\
    \        int t = compo.at(to);\n        if(s != t) ret.at(s).emplace_back(t);\n\
    \      }\n    }\n    for(auto&&v : ret){\n      sort(v.begin(), v.end());\n  \
    \    v.erase(unique(v.begin(), v.end()), v.end());\n    }\n    return ret;\n \
    \ }\n\n  vector<vector<int>> groups() const {\n    vector<vector<int>> res(group);\n\
    \    for(int i = 0; i < n; i++){\n      int p = compo.at(i);\n      res.at(p).emplace_back(i);\n\
    \    }\n    return res;\n  }\n\nprivate:\n  void dfs(int now){\n    if(used[now])\
    \ return;\n\n    stack<int> st;\n    st.emplace(now);\n\n    while(!st.empty()){\n\
    \      auto v = st.top(); st.pop();\n      if(v < n){\n        if(used[v]) continue;\n\
    \        used[v] = true;\n\n        st.emplace(v + n);\n        for(auto&&e :\
    \ G[v]){\n          if(used[e]) continue;\n          st.emplace(e);\n        }\n\
    \      }else{\n        order.emplace_back(v - n);\n      }\n    }\n  }\n\n  void\
    \ rdfs(int now, int cnt){\n    if(compo.at(now) != -1) return;\n    compo.at(now)\
    \ = cnt;\n\n    stack<int> st; st.push(now);\n    while(!st.empty()){\n      auto\
    \ v = st.top(); st.pop();\n\n      for(auto&&e : rG[v]){\n        if(compo[e]\
    \ != -1) continue;\n        compo[e] = cnt;\n        st.push(e);\n      }\n  \
    \  }\n  }\n};\n"
  code: "#pragma once\n\nstruct StronglyConnectedComponents{\n  int n;\n  vector<vector<int>>\
    \ G, rG;\n\n  int group;\n  vector<int> compo, order;\n  vector<bool> used;\n\n\
    \  template<typename T>\n  StronglyConnectedComponents(const T &g, bool cal =\
    \ true):n(g.size()), G(n), rG(n){\n    for(int i = 0; i < n; i++){\n      for(auto&&e\
    \ : g[i]){\n        G[i].emplace_back(e.to);\n        rG[e.to].emplace_back(i);\n\
    \      }\n    }\n    if(cal) build();\n  }\n  StronglyConnectedComponents(int\
    \ n):n(n), G(n), rG(n){}\n\n  int at(int k) const { return compo.at(k); }\n  int\
    \ operator[](int k) const { return compo.at(k); }\n\n  void add_edge(int u, int\
    \ v){\n    G[u].emplace_back(v);\n    rG[v].emplace_back(u);\n  }\n\n  void build(){\n\
    \    compo.assign(n,-1);\n    used.assign(n,false);\n    order.clear(); order.reserve(n);\n\
    \    group = 0;\n\n    for(int i = 0; i < n; i++) dfs(i);\n    reverse(order.begin(),\
    \ order.end());\n    for(auto&&e : order){\n      if(compo.at(e) == -1){\n   \
    \     rdfs(e,group);\n        group++;\n      }\n    }\n  }\n\n  bool is_same(int\
    \ u, int v) const { return compo.at(u) == compo.at(v); }\n\n  vector<vector<int>>\
    \ reconstruct() const {\n    vector<vector<int>> ret(group);\n    for(int i =\
    \ 0; i < n; i++){\n      for(auto to : G.at(i)){\n        int s = compo.at(i);\n\
    \        int t = compo.at(to);\n        if(s != t) ret.at(s).emplace_back(t);\n\
    \      }\n    }\n    for(auto&&v : ret){\n      sort(v.begin(), v.end());\n  \
    \    v.erase(unique(v.begin(), v.end()), v.end());\n    }\n    return ret;\n \
    \ }\n\n  vector<vector<int>> groups() const {\n    vector<vector<int>> res(group);\n\
    \    for(int i = 0; i < n; i++){\n      int p = compo.at(i);\n      res.at(p).emplace_back(i);\n\
    \    }\n    return res;\n  }\n\nprivate:\n  void dfs(int now){\n    if(used[now])\
    \ return;\n\n    stack<int> st;\n    st.emplace(now);\n\n    while(!st.empty()){\n\
    \      auto v = st.top(); st.pop();\n      if(v < n){\n        if(used[v]) continue;\n\
    \        used[v] = true;\n\n        st.emplace(v + n);\n        for(auto&&e :\
    \ G[v]){\n          if(used[e]) continue;\n          st.emplace(e);\n        }\n\
    \      }else{\n        order.emplace_back(v - n);\n      }\n    }\n  }\n\n  void\
    \ rdfs(int now, int cnt){\n    if(compo.at(now) != -1) return;\n    compo.at(now)\
    \ = cnt;\n\n    stack<int> st; st.push(now);\n    while(!st.empty()){\n      auto\
    \ v = st.top(); st.pop();\n\n      for(auto&&e : rG[v]){\n        if(compo[e]\
    \ != -1) continue;\n        compo[e] = cnt;\n        st.push(e);\n      }\n  \
    \  }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/StronglyConnectedComponents.cpp
  requiredBy:
  - graph/TwoSat.cpp
  timestamp: '2023-04-05 20:07:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/StronglyConnectedComponents.cpp
layout: document
redirect_from:
- /library/graph/StronglyConnectedComponents.cpp
- /library/graph/StronglyConnectedComponents.cpp.html
title: graph/StronglyConnectedComponents.cpp
---
