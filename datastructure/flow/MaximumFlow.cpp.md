---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: datastructure/flow/ProjectSelectionProblem.cpp
    title: datastructure/flow/ProjectSelectionProblem.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/flow/MaximumFlow.cpp\"\n\r\ntemplate <class\
    \ Cap>\r\nstruct Dinic{\r\n  using cap_type = Cap;\r\n  int n;\r\n  struct edge{\r\
    \n    int to, rev;\r\n    Cap cap;\r\n    edge(int to, int rev, Cap cap) : to(to),\
    \ rev(rev), cap(cap) {}\r\n  };\r\n  vector<pair<int,int>> pos;\r\n  vector<vector<edge>>\
    \ graph;\r\n  \r\n  Dinic(): n(0) {}\r\n  Dinic(int n): n(n), graph(n) {}\r\n\r\
    \n  int add_edge(int from, int to, Cap cap){\r\n    int res = pos.size();\r\n\
    \    pos.emplace_back(from, graph.at(from).size());\r\n    graph.at(from).emplace_back(to,\
    \ graph.at(to).size(), cap);\r\n    graph.at(to).emplace_back(from, graph.at(from).size()-1,\
    \ 0);\r\n    return res;\r\n  }\r\n\r\n  void change_edge(int i, Cap new_cap,\
    \ Cap new_flow){\r\n    auto& e = graph.at(pos.at(i).first).at(pos.at(i).second);\r\
    \n    auto& re = graph.at(e.to).at(e.rev);\r\n    e.cap = new_cap - new_flow;\r\
    \n    re.cap = new_flow;\r\n  }\r\n\r\n  Cap flow(int s, int t){\r\n    return\
    \ flow(s, t, numeric_limits<Cap>::max());\r\n  }\r\n  Cap flow(int s, int t, Cap\
    \ flow_limit){\r\n    vector<int> level(n), iter(n);\r\n\r\n    auto bfs = [&](){\r\
    \n      fill(level.begin(), level.end(), -1);\r\n      level.at(s) = 0;\r\n  \
    \    queue<int> que;\r\n      que.push(s);\r\n      while(!que.empty()){\r\n \
    \       int v = que.front(); que.pop();\r\n        for(auto e : graph.at(v)){\r\
    \n          if(e.cap==0 || level.at(e.to)>=0) continue;\r\n          level.at(e.to)\
    \ = level.at(v)+1;\r\n          if(e.to == t) return;\r\n          que.push(e.to);\r\
    \n        }\r\n      }\r\n    };\r\n    auto dfs = [&](auto self, const int v,\
    \ Cap up){\r\n      if(v == s) return up;\r\n      Cap res = 0;\r\n      int lv\
    \ = level.at(v);\r\n      for(int i = iter.at(v); i < int(graph.at(v).size());\
    \ i++){\r\n        edge &e = graph.at(v).at(i);\r\n        if(lv<=level.at(e.to)\
    \ || graph.at(e.to).at(e.rev).cap==0) continue;\r\n        Cap d = self(self,\
    \ e.to, min(up-res, graph.at(e.to).at(e.rev).cap));\r\n        if(d <= 0) continue;\r\
    \n        graph.at(v).at(i).cap += d;\r\n        graph.at(e.to).at(e.rev).cap\
    \ -= d;\r\n        res += d;\r\n        if(res == up) return res;\r\n      }\r\
    \n      level.at(v) = n;\r\n      return res;\r\n    };\r\n\r\n    Cap flow =\
    \ 0;\r\n    while(flow < flow_limit){\r\n      bfs();\r\n      if(level.at(t)\
    \ == -1) break;\r\n      fill(iter.begin(), iter.end(), 0);\r\n      Cap f = dfs(dfs,\
    \ t, flow_limit - flow);\r\n      if(!f) break;\r\n      flow += f;\r\n    }\r\
    \n    return flow;\r\n  }\r\n\r\n  vector<bool> min_cut(int s){\r\n    vector<bool>\
    \ visited(n,false);\r\n    queue<int> que;\r\n    que.push(s);\r\n    while(!que.empty()){\r\
    \n      int p = que.front(); que.pop();\r\n      visited.at(p) = true;\r\n   \
    \   for(auto e : graph.at(p)){\r\n        if(e.cap && !visited.at(e.to)){\r\n\
    \          visited.at(e.to) = true;\r\n          que.push(e.to);\r\n        }\r\
    \n      }\r\n    }\r\n    return visited;\r\n  }\r\n\r\n  struct egdeinfo{\r\n\
    \    int from, to;\r\n    Cap cap, flow;\r\n    egdeinfo(int from, int to, Cap\
    \ cap, Cap flow):from(from), to(to), cap(cap), flow(flow) {}\r\n  };\r\n  egdeinfo\
    \ get_edge(int i){\r\n    auto [x,y] = pos.at(i);\r\n    auto e = graph.at(x).at(y);\r\
    \n    auto re = graph.at(e.to).at(e.rev);\r\n    return egdeinfo(x, e.to, e.cap+re.cap,\
    \ re.cap);\r\n  }\r\n  vector<egdeinfo> edges(){\r\n    vector<egdeinfo> res;\r\
    \n    int m = pos.size();\r\n    res.reserve(m);\r\n    for(int i = 0; i < m;\
    \ i++) res.emplace_back(get_edge(i));\r\n    return res;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <class Cap>\r\nstruct Dinic{\r\n  using cap_type\
    \ = Cap;\r\n  int n;\r\n  struct edge{\r\n    int to, rev;\r\n    Cap cap;\r\n\
    \    edge(int to, int rev, Cap cap) : to(to), rev(rev), cap(cap) {}\r\n  };\r\n\
    \  vector<pair<int,int>> pos;\r\n  vector<vector<edge>> graph;\r\n  \r\n  Dinic():\
    \ n(0) {}\r\n  Dinic(int n): n(n), graph(n) {}\r\n\r\n  int add_edge(int from,\
    \ int to, Cap cap){\r\n    int res = pos.size();\r\n    pos.emplace_back(from,\
    \ graph.at(from).size());\r\n    graph.at(from).emplace_back(to, graph.at(to).size(),\
    \ cap);\r\n    graph.at(to).emplace_back(from, graph.at(from).size()-1, 0);\r\n\
    \    return res;\r\n  }\r\n\r\n  void change_edge(int i, Cap new_cap, Cap new_flow){\r\
    \n    auto& e = graph.at(pos.at(i).first).at(pos.at(i).second);\r\n    auto& re\
    \ = graph.at(e.to).at(e.rev);\r\n    e.cap = new_cap - new_flow;\r\n    re.cap\
    \ = new_flow;\r\n  }\r\n\r\n  Cap flow(int s, int t){\r\n    return flow(s, t,\
    \ numeric_limits<Cap>::max());\r\n  }\r\n  Cap flow(int s, int t, Cap flow_limit){\r\
    \n    vector<int> level(n), iter(n);\r\n\r\n    auto bfs = [&](){\r\n      fill(level.begin(),\
    \ level.end(), -1);\r\n      level.at(s) = 0;\r\n      queue<int> que;\r\n   \
    \   que.push(s);\r\n      while(!que.empty()){\r\n        int v = que.front();\
    \ que.pop();\r\n        for(auto e : graph.at(v)){\r\n          if(e.cap==0 ||\
    \ level.at(e.to)>=0) continue;\r\n          level.at(e.to) = level.at(v)+1;\r\n\
    \          if(e.to == t) return;\r\n          que.push(e.to);\r\n        }\r\n\
    \      }\r\n    };\r\n    auto dfs = [&](auto self, const int v, Cap up){\r\n\
    \      if(v == s) return up;\r\n      Cap res = 0;\r\n      int lv = level.at(v);\r\
    \n      for(int i = iter.at(v); i < int(graph.at(v).size()); i++){\r\n       \
    \ edge &e = graph.at(v).at(i);\r\n        if(lv<=level.at(e.to) || graph.at(e.to).at(e.rev).cap==0)\
    \ continue;\r\n        Cap d = self(self, e.to, min(up-res, graph.at(e.to).at(e.rev).cap));\r\
    \n        if(d <= 0) continue;\r\n        graph.at(v).at(i).cap += d;\r\n    \
    \    graph.at(e.to).at(e.rev).cap -= d;\r\n        res += d;\r\n        if(res\
    \ == up) return res;\r\n      }\r\n      level.at(v) = n;\r\n      return res;\r\
    \n    };\r\n\r\n    Cap flow = 0;\r\n    while(flow < flow_limit){\r\n      bfs();\r\
    \n      if(level.at(t) == -1) break;\r\n      fill(iter.begin(), iter.end(), 0);\r\
    \n      Cap f = dfs(dfs, t, flow_limit - flow);\r\n      if(!f) break;\r\n   \
    \   flow += f;\r\n    }\r\n    return flow;\r\n  }\r\n\r\n  vector<bool> min_cut(int\
    \ s){\r\n    vector<bool> visited(n,false);\r\n    queue<int> que;\r\n    que.push(s);\r\
    \n    while(!que.empty()){\r\n      int p = que.front(); que.pop();\r\n      visited.at(p)\
    \ = true;\r\n      for(auto e : graph.at(p)){\r\n        if(e.cap && !visited.at(e.to)){\r\
    \n          visited.at(e.to) = true;\r\n          que.push(e.to);\r\n        }\r\
    \n      }\r\n    }\r\n    return visited;\r\n  }\r\n\r\n  struct egdeinfo{\r\n\
    \    int from, to;\r\n    Cap cap, flow;\r\n    egdeinfo(int from, int to, Cap\
    \ cap, Cap flow):from(from), to(to), cap(cap), flow(flow) {}\r\n  };\r\n  egdeinfo\
    \ get_edge(int i){\r\n    auto [x,y] = pos.at(i);\r\n    auto e = graph.at(x).at(y);\r\
    \n    auto re = graph.at(e.to).at(e.rev);\r\n    return egdeinfo(x, e.to, e.cap+re.cap,\
    \ re.cap);\r\n  }\r\n  vector<egdeinfo> edges(){\r\n    vector<egdeinfo> res;\r\
    \n    int m = pos.size();\r\n    res.reserve(m);\r\n    for(int i = 0; i < m;\
    \ i++) res.emplace_back(get_edge(i));\r\n    return res;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/flow/MaximumFlow.cpp
  requiredBy:
  - datastructure/flow/ProjectSelectionProblem.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/flow/MaximumFlow.cpp
layout: document
redirect_from:
- /library/datastructure/flow/MaximumFlow.cpp
- /library/datastructure/flow/MaximumFlow.cpp.html
title: datastructure/flow/MaximumFlow.cpp
---
