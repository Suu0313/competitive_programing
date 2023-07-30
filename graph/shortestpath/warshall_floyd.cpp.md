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
  bundledCode: "#line 2 \"graph/shortestpath/warshall_floyd.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nvoid WarshallFloyd(vector<vector<T>> &g, T inf){\r\n  const int n = g.size();\r\
    \n  for(int k = 0; k < n; k++){\r\n    for(int i = 0; i < n; i++)for(int j = 0;\
    \ j < n; j++){\r\n      if(g[i][k] == inf || g[k][j] == inf) continue;\r\n   \
    \   g[i][j] = min(g[i][j], g[i][k] + g[k][j]);\r\n    }\r\n  }\r\n}\r\n\r\ntemplate<typename\
    \ T>\r\nbool isNegative(vector<vector<T>> &g){\r\n  for(size_t i = 0; i < g.size();\
    \ i++){\r\n    if(g[i][i] < 0) return true;\r\n  }\r\n  return false;\r\n}\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nvoid WarshallFloyd(vector<vector<T>>\
    \ &g, T inf){\r\n  const int n = g.size();\r\n  for(int k = 0; k < n; k++){\r\n\
    \    for(int i = 0; i < n; i++)for(int j = 0; j < n; j++){\r\n      if(g[i][k]\
    \ == inf || g[k][j] == inf) continue;\r\n      g[i][j] = min(g[i][j], g[i][k]\
    \ + g[k][j]);\r\n    }\r\n  }\r\n}\r\n\r\ntemplate<typename T>\r\nbool isNegative(vector<vector<T>>\
    \ &g){\r\n  for(size_t i = 0; i < g.size(); i++){\r\n    if(g[i][i] < 0) return\
    \ true;\r\n  }\r\n  return false;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortestpath/warshall_floyd.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/shortestpath/warshall_floyd.cpp
layout: document
redirect_from:
- /library/graph/shortestpath/warshall_floyd.cpp
- /library/graph/shortestpath/warshall_floyd.cpp.html
title: graph/shortestpath/warshall_floyd.cpp
---
