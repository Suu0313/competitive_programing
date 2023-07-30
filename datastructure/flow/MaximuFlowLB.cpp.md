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
  bundledCode: "#line 2 \"datastructure/flow/MaximuFlowLB.cpp\"\n\r\ntemplate<class\
    \ F>\r\nstruct MaximuFlowLB{\r\n  using Cap = F::cap_type;\r\n  F f;\r\n  int\
    \ S, T;\r\n  Cap lb_sum;\r\n\r\n  MaximuFlowLB(int n): f(n + 2), S(n), T(S + 1),\
    \ lb_sum(0) {}\r\n\r\n  void add_edge(int from, int to, Cap lb, Cap ub){\r\n\r\
    \n    if(lb != ub){\r\n      f.add_edge(from, to, ub - lb);\r\n    }\r\n\r\n \
    \   if(lb != 0){\r\n      lb_sum += lb;\r\n      f.add_edge(S, to, lb);\r\n  \
    \    f.add_edge(from, T, lb);\r\n    }\r\n  }\r\n\r\n  Cap flow(int s, int t){\r\
    \n    Cap a = f.flow(S, T);\r\n    Cap b = f.flow(s, T);\r\n    Cap c = f.flow(S,\
    \ t);\r\n    Cap d = f.flow(s, t);\r\n    if(lb_sum == a + b && lb_sum == a +\
    \ c) return b + d;\r\n    return -1;\r\n  }\r\n};\r\n//TODO: verify\n"
  code: "#pragma once\r\n\r\ntemplate<class F>\r\nstruct MaximuFlowLB{\r\n  using\
    \ Cap = F::cap_type;\r\n  F f;\r\n  int S, T;\r\n  Cap lb_sum;\r\n\r\n  MaximuFlowLB(int\
    \ n): f(n + 2), S(n), T(S + 1), lb_sum(0) {}\r\n\r\n  void add_edge(int from,\
    \ int to, Cap lb, Cap ub){\r\n\r\n    if(lb != ub){\r\n      f.add_edge(from,\
    \ to, ub - lb);\r\n    }\r\n\r\n    if(lb != 0){\r\n      lb_sum += lb;\r\n  \
    \    f.add_edge(S, to, lb);\r\n      f.add_edge(from, T, lb);\r\n    }\r\n  }\r\
    \n\r\n  Cap flow(int s, int t){\r\n    Cap a = f.flow(S, T);\r\n    Cap b = f.flow(s,\
    \ T);\r\n    Cap c = f.flow(S, t);\r\n    Cap d = f.flow(s, t);\r\n    if(lb_sum\
    \ == a + b && lb_sum == a + c) return b + d;\r\n    return -1;\r\n  }\r\n};\r\n\
    //TODO: verify"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/flow/MaximuFlowLB.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/flow/MaximuFlowLB.cpp
layout: document
redirect_from:
- /library/datastructure/flow/MaximuFlowLB.cpp
- /library/datastructure/flow/MaximuFlowLB.cpp.html
title: datastructure/flow/MaximuFlowLB.cpp
---
