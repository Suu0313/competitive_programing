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
  bundledCode: "#line 2 \"datastructure/Namori.cpp\"\n\r\ntemplate<typename F>\r\n\
    struct DirectedNamori{\r\n  int s, d, len;\r\n  vector<int> dist, log;\r\n  F\
    \ f;\r\n\r\n  DirectedNamori(int n, int s, const F &f): s(s), d(0), len(0), dist(n,\
    \ -1), log(0), f(f) {\r\n    int pos = s;\r\n    while(dist[pos] < 0){\r\n   \
    \   dist[pos] = d++;\r\n      log.push_back(pos);\r\n      pos = f(pos);\r\n \
    \   }\r\n    len = d - dist[pos];\r\n  }\r\n\r\n  int query(long long K) const\
    \ {\r\n    if(K < d-len){\r\n      int pos = s;\r\n      for(int i = 0; i < K;\
    \ ++i) pos = f(pos);\r\n      return pos;\r\n    }else{\r\n      K -= d-len;\r\
    \n      K %= len;\r\n      return log[d-len + K];\r\n    }\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename F>\r\nstruct DirectedNamori{\r\n  int\
    \ s, d, len;\r\n  vector<int> dist, log;\r\n  F f;\r\n\r\n  DirectedNamori(int\
    \ n, int s, const F &f): s(s), d(0), len(0), dist(n, -1), log(0), f(f) {\r\n \
    \   int pos = s;\r\n    while(dist[pos] < 0){\r\n      dist[pos] = d++;\r\n  \
    \    log.push_back(pos);\r\n      pos = f(pos);\r\n    }\r\n    len = d - dist[pos];\r\
    \n  }\r\n\r\n  int query(long long K) const {\r\n    if(K < d-len){\r\n      int\
    \ pos = s;\r\n      for(int i = 0; i < K; ++i) pos = f(pos);\r\n      return pos;\r\
    \n    }else{\r\n      K -= d-len;\r\n      K %= len;\r\n      return log[d-len\
    \ + K];\r\n    }\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/Namori.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/Namori.cpp
layout: document
redirect_from:
- /library/datastructure/Namori.cpp
- /library/datastructure/Namori.cpp.html
title: datastructure/Namori.cpp
---
