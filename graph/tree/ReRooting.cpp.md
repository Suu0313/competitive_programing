---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: calculate rerooting dp (T, T) => T, (T, U) => T
    links: []
  bundledCode: "#line 2 \"graph/tree/ReRooting.cpp\"\n\n/**\n * @brief calculate rerooting\
    \ dp (T, T) => T, (T, U) => T\n * \n * @tparam T dp value\n * @tparam U edge value\n\
    \ */\ntemplate<typename T, typename U>\nstruct ReRooting{\n  struct Edge{\n  \
    \  int to;\n    U data;\n    T dp, ndp;\n    Edge(int to, const U &data, const\
    \ T &dp, const T &ndp)\n      : to(to), data(data), dp(dp), ndp(ndp) {}\n  };\n\
    \  using F = function<T(T, T)>;\n  using G = function<T(T, U)>;\n\n  const int\
    \ V;\n  vector<vector<Edge>> tree;\n  const F f;\n  const G g;\n  const T e;\n\
    \  vector<T> dp, dp_p;\n\n  vector<int> dag, rev;\n\n  ReRooting() = delete;\n\
    \  ReRooting(const ReRooting&) = delete;\n  ReRooting(ReRooting&&) = delete;\n\
    \n  /**\n   * @brief f(s, g(dp, edge))\n   * \n   * @param V vertex size\n   *\
    \ @param f (dp[v], dp[v2]) => dp[v]\n   * @param g (dp[c], edge) => dp[v]\n  \
    \ * @param e identity\n   */\n  ReRooting(int V, const F f, const G g, const T\
    \ &e)\n    : V(V), tree(V), f(f), g(g), e(e), dp(V, e), dp_p(V, e) {}\n  \n  void\
    \ add_edge(int u, int v, const U &c){\n    tree[u].emplace_back(v, c, e, e);\n\
    \    tree[v].emplace_back(u, c, e, e);\n  }\n\n  void add_edge_bi(int u, int v,\
    \ const U &c, const U &d){\n    tree[u].emplace_back(v, c, e, e);\n    tree[v].emplace_back(u,\
    \ d, e, e);\n  }\n\n  vector<T> solve(int root = 0){\n    TopologicalSort(root);\n\
    \    for(int i = V-1; i >= 0; i--) dfs_sub(i, dag[i]);\n    for(int i = 0; i <\
    \ V; i++) dfs_all(i, dag[i]);\n    return dp;\n  }\n\nprivate:\n\n  void TopologicalSort(int\
    \ root){\n    queue<int> qu;\n    vector<bool> seen(V);\n    dag.emplace_back(root);\
    \ seen[root] = true;\n\n    for(qu.emplace(root); !qu.empty(); qu.pop()){\n  \
    \    int v = qu.front();\n      for(auto&&e : tree[v]){\n        if(seen[e.to])\
    \ continue;\n        seen[e.to] = true;\n        dag.emplace_back(e.to);\n   \
    \     qu.emplace(e.to);\n      }\n    }\n    rev.resize(V);\n    for(int i = 0;\
    \ i < V; i++) rev[dag[i]] = i;\n  }\n\n  void dfs_sub(int idx, int v){\n    for(auto&&e\
    \ : tree[v]){\n      if(rev[e.to] < idx) continue;\n      dp[v] = f(dp[v], g(dp[e.to],\
    \ e.data));\n    }\n  }\n\n  void dfs_all(int idx, int v){\n    T buff{e};\n \
    \   for(int i = 0; i < (int)tree[v].size(); i++){\n      auto &e = tree[v][i];\n\
    \      e.ndp = buff;\n      if(rev[e.to] < idx) e.dp = g(dp_p[v], e.data);\n \
    \     else e.dp = g(dp[e.to], e.data);\n      buff = f(buff, e.dp);\n    }\n \
    \   dp[v] = buff;\n    buff = e;\n    for(int i = (int)tree[v].size()-1; i >=\
    \ 0; i--){\n      auto &e = tree[v][i];\n      if(rev[e.to] > idx) dp_p[e.to]\
    \ = f(e.ndp, buff);\n      e.ndp = f(e.ndp, buff); buff = f(buff, e.dp);\n   \
    \ }\n  }\n};\n"
  code: "#pragma once\n\n/**\n * @brief calculate rerooting dp (T, T) => T, (T, U)\
    \ => T\n * \n * @tparam T dp value\n * @tparam U edge value\n */\ntemplate<typename\
    \ T, typename U>\nstruct ReRooting{\n  struct Edge{\n    int to;\n    U data;\n\
    \    T dp, ndp;\n    Edge(int to, const U &data, const T &dp, const T &ndp)\n\
    \      : to(to), data(data), dp(dp), ndp(ndp) {}\n  };\n  using F = function<T(T,\
    \ T)>;\n  using G = function<T(T, U)>;\n\n  const int V;\n  vector<vector<Edge>>\
    \ tree;\n  const F f;\n  const G g;\n  const T e;\n  vector<T> dp, dp_p;\n\n \
    \ vector<int> dag, rev;\n\n  ReRooting() = delete;\n  ReRooting(const ReRooting&)\
    \ = delete;\n  ReRooting(ReRooting&&) = delete;\n\n  /**\n   * @brief f(s, g(dp,\
    \ edge))\n   * \n   * @param V vertex size\n   * @param f (dp[v], dp[v2]) => dp[v]\n\
    \   * @param g (dp[c], edge) => dp[v]\n   * @param e identity\n   */\n  ReRooting(int\
    \ V, const F f, const G g, const T &e)\n    : V(V), tree(V), f(f), g(g), e(e),\
    \ dp(V, e), dp_p(V, e) {}\n  \n  void add_edge(int u, int v, const U &c){\n  \
    \  tree[u].emplace_back(v, c, e, e);\n    tree[v].emplace_back(u, c, e, e);\n\
    \  }\n\n  void add_edge_bi(int u, int v, const U &c, const U &d){\n    tree[u].emplace_back(v,\
    \ c, e, e);\n    tree[v].emplace_back(u, d, e, e);\n  }\n\n  vector<T> solve(int\
    \ root = 0){\n    TopologicalSort(root);\n    for(int i = V-1; i >= 0; i--) dfs_sub(i,\
    \ dag[i]);\n    for(int i = 0; i < V; i++) dfs_all(i, dag[i]);\n    return dp;\n\
    \  }\n\nprivate:\n\n  void TopologicalSort(int root){\n    queue<int> qu;\n  \
    \  vector<bool> seen(V);\n    dag.emplace_back(root); seen[root] = true;\n\n \
    \   for(qu.emplace(root); !qu.empty(); qu.pop()){\n      int v = qu.front();\n\
    \      for(auto&&e : tree[v]){\n        if(seen[e.to]) continue;\n        seen[e.to]\
    \ = true;\n        dag.emplace_back(e.to);\n        qu.emplace(e.to);\n      }\n\
    \    }\n    rev.resize(V);\n    for(int i = 0; i < V; i++) rev[dag[i]] = i;\n\
    \  }\n\n  void dfs_sub(int idx, int v){\n    for(auto&&e : tree[v]){\n      if(rev[e.to]\
    \ < idx) continue;\n      dp[v] = f(dp[v], g(dp[e.to], e.data));\n    }\n  }\n\
    \n  void dfs_all(int idx, int v){\n    T buff{e};\n    for(int i = 0; i < (int)tree[v].size();\
    \ i++){\n      auto &e = tree[v][i];\n      e.ndp = buff;\n      if(rev[e.to]\
    \ < idx) e.dp = g(dp_p[v], e.data);\n      else e.dp = g(dp[e.to], e.data);\n\
    \      buff = f(buff, e.dp);\n    }\n    dp[v] = buff;\n    buff = e;\n    for(int\
    \ i = (int)tree[v].size()-1; i >= 0; i--){\n      auto &e = tree[v][i];\n    \
    \  if(rev[e.to] > idx) dp_p[e.to] = f(e.ndp, buff);\n      e.ndp = f(e.ndp, buff);\
    \ buff = f(buff, e.dp);\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/ReRooting.cpp
  requiredBy: []
  timestamp: '2023-05-13 03:14:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/ReRooting.cpp
layout: document
redirect_from:
- /library/graph/tree/ReRooting.cpp
- /library/graph/tree/ReRooting.cpp.html
title: calculate rerooting dp (T, T) => T, (T, U) => T
---
