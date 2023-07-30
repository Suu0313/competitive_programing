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
  bundledCode: "#line 2 \"datastructure/flow/MinimumPathCoverDAG.cpp\"\n\r\ntemplate<class\
    \ F>\r\nstruct MinimumPathCoverDAG{\r\n  int n, s, t;\r\n  F flow;\r\n\r\n  MinimumPathCoverDAG()\
    \ = default;\r\n  MinimumPathCoverDAG(int n): n(n), s(n * 2), t(s + 1), flow(t\
    \ + 1) {\r\n    for(int i = 0; i < n; ++i){\r\n      flow.add_edge(s, i, 1);\r\
    \n      flow.add_edge(i + n, t, 1);\r\n    }\r\n  }\r\n\r\n  void add_edge(int\
    \ u, int v){\r\n    flow.add_edge(u, v + n, 1);\r\n  }\r\n\r\n  int solve(){\r\
    \n    return n - flow.flow(s, t);\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<class F>\r\nstruct MinimumPathCoverDAG{\r\n\
    \  int n, s, t;\r\n  F flow;\r\n\r\n  MinimumPathCoverDAG() = default;\r\n  MinimumPathCoverDAG(int\
    \ n): n(n), s(n * 2), t(s + 1), flow(t + 1) {\r\n    for(int i = 0; i < n; ++i){\r\
    \n      flow.add_edge(s, i, 1);\r\n      flow.add_edge(i + n, t, 1);\r\n    }\r\
    \n  }\r\n\r\n  void add_edge(int u, int v){\r\n    flow.add_edge(u, v + n, 1);\r\
    \n  }\r\n\r\n  int solve(){\r\n    return n - flow.flow(s, t);\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/flow/MinimumPathCoverDAG.cpp
  requiredBy: []
  timestamp: '2023-03-10 19:33:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/flow/MinimumPathCoverDAG.cpp
layout: document
redirect_from:
- /library/datastructure/flow/MinimumPathCoverDAG.cpp
- /library/datastructure/flow/MinimumPathCoverDAG.cpp.html
title: datastructure/flow/MinimumPathCoverDAG.cpp
---
