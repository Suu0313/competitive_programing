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
  bundledCode: "#line 2 \"graph/tree/lca/LCA.cpp\"\n\ntemplate<typename T = int>\n\
    struct LCA{\n  vector<vector<int>> parent;\n  vector<int> dist;\n\n  LCA (vector<vector<T>>\
    \ &G, int root){ init(G, root); }\n\n  void init(vector<vector<T>> &G, int root){\n\
    \    int V = G.size();\n    int K = 1;\n    while((1<<K) < V) K++;\n    parent.assign(K,\
    \ vector<int>(V, -1));\n    dist.assign(V,-1);\n    dfs(G,root,-1,0);\n    for(int\
    \ k = 0; k < K-1; k++){\n      for(int v = 0; v < V; v++){\n        if(parent.at(k).at(v)<0){\n\
    \          parent.at(k+1).at(v) = -1;\n        }else{\n          parent.at(k+1).at(v)\
    \ = parent.at(k).at(parent.at(k).at(v));\n        }\n      }\n    }\n  }\n\n \
    \ void dfs(vector<vector<T>> &G, int v, int p, int d){\n    parent.at(0).at(v)\
    \ = p;\n    dist.at(v) = d;\n    for(auto &&e : G.at(v)){\n      if(e != p) dfs(G,\
    \ e, v, d+1);\n    }\n  }\n\n  int quert(int u, int v){\n    if(dist.at(u) < dist.at(v))\
    \ swap(u,v);\n    int K = parent.size();\n\n    for(int k = 0; k < K; k++){\n\
    \      if((dist.at(u)-dist.at(v))>>k & 1){\n        u = parent.at(k).at(u);\n\
    \      }\n    }\n    if(u==v) return u;\n\n    for(int k = K-1; k >= 0; k--){\n\
    \      if(parent.at(k).at(u) != parent.at(k).at(v)){\n        u = parent.at(k).at(u);\n\
    \        v = parent.at(k).at(v);\n      }\n    }\n    return parent.at(0).at(u);\n\
    \  }\n\n  int getdist(int u, int v){\n    return dist.at(u) + dist.at(v) - 2*dist.at(quert(u,v));\n\
    \  }\n\n  bool isonpath(int u, int v, int a){\n    return getdist(u,a) + getdist(a,v)\
    \ == getdist(u,v);\n  }\n\n  bool isonpath(int u, int v, int a, int b){\n    return\
    \ isonpath(u,v,a) && isonpath(u,v,b);\n  }\n};\n"
  code: "#pragma once\n\ntemplate<typename T = int>\nstruct LCA{\n  vector<vector<int>>\
    \ parent;\n  vector<int> dist;\n\n  LCA (vector<vector<T>> &G, int root){ init(G,\
    \ root); }\n\n  void init(vector<vector<T>> &G, int root){\n    int V = G.size();\n\
    \    int K = 1;\n    while((1<<K) < V) K++;\n    parent.assign(K, vector<int>(V,\
    \ -1));\n    dist.assign(V,-1);\n    dfs(G,root,-1,0);\n    for(int k = 0; k <\
    \ K-1; k++){\n      for(int v = 0; v < V; v++){\n        if(parent.at(k).at(v)<0){\n\
    \          parent.at(k+1).at(v) = -1;\n        }else{\n          parent.at(k+1).at(v)\
    \ = parent.at(k).at(parent.at(k).at(v));\n        }\n      }\n    }\n  }\n\n \
    \ void dfs(vector<vector<T>> &G, int v, int p, int d){\n    parent.at(0).at(v)\
    \ = p;\n    dist.at(v) = d;\n    for(auto &&e : G.at(v)){\n      if(e != p) dfs(G,\
    \ e, v, d+1);\n    }\n  }\n\n  int quert(int u, int v){\n    if(dist.at(u) < dist.at(v))\
    \ swap(u,v);\n    int K = parent.size();\n\n    for(int k = 0; k < K; k++){\n\
    \      if((dist.at(u)-dist.at(v))>>k & 1){\n        u = parent.at(k).at(u);\n\
    \      }\n    }\n    if(u==v) return u;\n\n    for(int k = K-1; k >= 0; k--){\n\
    \      if(parent.at(k).at(u) != parent.at(k).at(v)){\n        u = parent.at(k).at(u);\n\
    \        v = parent.at(k).at(v);\n      }\n    }\n    return parent.at(0).at(u);\n\
    \  }\n\n  int getdist(int u, int v){\n    return dist.at(u) + dist.at(v) - 2*dist.at(quert(u,v));\n\
    \  }\n\n  bool isonpath(int u, int v, int a){\n    return getdist(u,a) + getdist(a,v)\
    \ == getdist(u,v);\n  }\n\n  bool isonpath(int u, int v, int a, int b){\n    return\
    \ isonpath(u,v,a) && isonpath(u,v,b);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/lca/LCA.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/lca/LCA.cpp
layout: document
redirect_from:
- /library/graph/tree/lca/LCA.cpp
- /library/graph/tree/lca/LCA.cpp.html
title: graph/tree/lca/LCA.cpp
---
