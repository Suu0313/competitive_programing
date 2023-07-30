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
  bundledCode: "#line 2 \"graph/GridGraph.cpp\"\n\r\nstruct GridGraph{\r\n  int h,\
    \ w;\r\n  vector<pair<int, int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};\r\
    \n  GridGraph() = default;\r\n  GridGraph(int h, int w): h(h), w(w) {}\r\n  GridGraph(int\
    \ h, int w, vector<pair<int, int>> delta): h(h), w(w), delta(delta) {}\r\n  GridGraph(int\
    \ h, int w, vector<int> dx, vector<int> dy): h(h), w(w), delta(dx.size()) {\r\n\
    \    for(size_t i = 0; i != delta.size(); ++i){\r\n      delta[i] = make_pair(dx[i],\
    \ dy[i]);\r\n    }\r\n  }\r\n\r\n  vector<pair<int, int>> adj(int i, int j) const\
    \ {\r\n    vector<pair<int, int>> ps;\r\n    for(const auto [dx, dy] : delta){\r\
    \n      int x = i + dx, y = j + dy;\r\n      if(x < 0 || h <= x || y < 0 || w\
    \ <= y) continue;\r\n      ps.emplace_back(x, y);\r\n    }\r\n    return ps;\r\
    \n  }\r\n\r\n  template<class F>\r\n  vector<vector<int>> bfs(int si, int sj,\
    \ const F &can_move) const {\r\n    vector<vector<int>> dist(h, vector<int>(w,\
    \ -1));\r\n    dist[si][sj] = 0;\r\n    queue<pair<int, int>> qu; qu.emplace(si,\
    \ sj);\r\n    while(!qu.empty()){\r\n      auto[i, j] = qu.front(); qu.pop();\r\
    \n      for(const auto[x, y] : adj(i, j)){\r\n        if(dist[x][y] != -1) continue;\r\
    \n        if(!can_move(x, y)) continue;\r\n        dist[x][y] = dist[i][j] + 1;\r\
    \n        qu.emplace(x, y);\r\n      }\r\n    }\r\n    return dist;\r\n  }\r\n\
    \r\n  template<typename T>\r\n  vector<vector<int>> bfs_sp(int si, int sj, const\
    \ vector<vector<T>> space, const T& sp = 0) const {\r\n    return bfs(si, sj,\
    \ [&](int i, int j){ return space[i][j] == sp; });\r\n  }\r\n\r\n  template<typename\
    \ T>\r\n  vector<vector<int>> bfs_bl(int si, int sj, const vector<vector<T>> block,\
    \ const T& bl = 1) const {\r\n    return bfs(si, sj, [&](int i, int j){ return\
    \ block[i][j] != bl; });\r\n  }\r\n\r\n  vector<vector<int>> bfs_sp(int si, int\
    \ sj, const vector<string> space, char sp = '.') const {\r\n    return bfs(si,\
    \ sj, [&](int i, int j){ return space[i][j] == sp; });\r\n  }\r\n\r\n  vector<vector<int>>\
    \ bfs_bl(int si, int sj, const vector<string> block, char bl = '#') const {\r\n\
    \    return bfs(si, sj, [&](int i, int j){ return block[i][j] != bl; });\r\n \
    \ }\r\n};\r\n"
  code: "#pragma once\r\n\r\nstruct GridGraph{\r\n  int h, w;\r\n  vector<pair<int,\
    \ int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};\r\n  GridGraph() = default;\r\
    \n  GridGraph(int h, int w): h(h), w(w) {}\r\n  GridGraph(int h, int w, vector<pair<int,\
    \ int>> delta): h(h), w(w), delta(delta) {}\r\n  GridGraph(int h, int w, vector<int>\
    \ dx, vector<int> dy): h(h), w(w), delta(dx.size()) {\r\n    for(size_t i = 0;\
    \ i != delta.size(); ++i){\r\n      delta[i] = make_pair(dx[i], dy[i]);\r\n  \
    \  }\r\n  }\r\n\r\n  vector<pair<int, int>> adj(int i, int j) const {\r\n    vector<pair<int,\
    \ int>> ps;\r\n    for(const auto [dx, dy] : delta){\r\n      int x = i + dx,\
    \ y = j + dy;\r\n      if(x < 0 || h <= x || y < 0 || w <= y) continue;\r\n  \
    \    ps.emplace_back(x, y);\r\n    }\r\n    return ps;\r\n  }\r\n\r\n  template<class\
    \ F>\r\n  vector<vector<int>> bfs(int si, int sj, const F &can_move) const {\r\
    \n    vector<vector<int>> dist(h, vector<int>(w, -1));\r\n    dist[si][sj] = 0;\r\
    \n    queue<pair<int, int>> qu; qu.emplace(si, sj);\r\n    while(!qu.empty()){\r\
    \n      auto[i, j] = qu.front(); qu.pop();\r\n      for(const auto[x, y] : adj(i,\
    \ j)){\r\n        if(dist[x][y] != -1) continue;\r\n        if(!can_move(x, y))\
    \ continue;\r\n        dist[x][y] = dist[i][j] + 1;\r\n        qu.emplace(x, y);\r\
    \n      }\r\n    }\r\n    return dist;\r\n  }\r\n\r\n  template<typename T>\r\n\
    \  vector<vector<int>> bfs_sp(int si, int sj, const vector<vector<T>> space, const\
    \ T& sp = 0) const {\r\n    return bfs(si, sj, [&](int i, int j){ return space[i][j]\
    \ == sp; });\r\n  }\r\n\r\n  template<typename T>\r\n  vector<vector<int>> bfs_bl(int\
    \ si, int sj, const vector<vector<T>> block, const T& bl = 1) const {\r\n    return\
    \ bfs(si, sj, [&](int i, int j){ return block[i][j] != bl; });\r\n  }\r\n\r\n\
    \  vector<vector<int>> bfs_sp(int si, int sj, const vector<string> space, char\
    \ sp = '.') const {\r\n    return bfs(si, sj, [&](int i, int j){ return space[i][j]\
    \ == sp; });\r\n  }\r\n\r\n  vector<vector<int>> bfs_bl(int si, int sj, const\
    \ vector<string> block, char bl = '#') const {\r\n    return bfs(si, sj, [&](int\
    \ i, int j){ return block[i][j] != bl; });\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/GridGraph.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/GridGraph.cpp
layout: document
redirect_from:
- /library/graph/GridGraph.cpp
- /library/graph/GridGraph.cpp.html
title: graph/GridGraph.cpp
---
