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
  bundledCode: "#line 2 \"datastructure/Imos2D.cpp\"\n\r\ntemplate<typename T>\r\n\
    struct Imos2D{\r\n  int n, m;\r\n  vector<vector<T>> sum;\r\n  Imos2D(int n, int\
    \ m) : n(n), m(m) {\r\n    sum.assign(n+1, vector<T>(m+1, 0));\r\n  }\r\n  \r\n\
    \  vector<T> &operator[](int k) { return sum.at(k); }\r\n  const vector<T> &operator[](int\
    \ k) const { return sum.at(k); }\r\n  vector<T> &at(int k) { return sum.at(k);\
    \ }\r\n  const vector<T> &at(int k) const { return sum.at(k); }\r\n\r\n  void\
    \ build(){\r\n    for(int i=0; i<=n; i++){\r\n      for(int j=0; j<m; j++){\r\n\
    \        sum.at(i).at(j+1) += sum.at(i).at(j);\r\n      }\r\n    }\r\n    for(int\
    \ j=0; j<=m; j++){\r\n      for(int i=0; i<n; i++){\r\n        sum.at(i+1).at(j)\
    \ += sum.at(i).at(j);\r\n      }\r\n    }\r\n  }\r\n  void add(int x1, int x2,\
    \ int y1, int y2, T t = 1){\r\n    sum[x1][y1] += t;\r\n    sum[x2][y1] -= t;\r\
    \n    sum[x1][y2] -= t;\r\n    sum[x2][y2] += t;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct Imos2D{\r\n  int n, m;\r\
    \n  vector<vector<T>> sum;\r\n  Imos2D(int n, int m) : n(n), m(m) {\r\n    sum.assign(n+1,\
    \ vector<T>(m+1, 0));\r\n  }\r\n  \r\n  vector<T> &operator[](int k) { return\
    \ sum.at(k); }\r\n  const vector<T> &operator[](int k) const { return sum.at(k);\
    \ }\r\n  vector<T> &at(int k) { return sum.at(k); }\r\n  const vector<T> &at(int\
    \ k) const { return sum.at(k); }\r\n\r\n  void build(){\r\n    for(int i=0; i<=n;\
    \ i++){\r\n      for(int j=0; j<m; j++){\r\n        sum.at(i).at(j+1) += sum.at(i).at(j);\r\
    \n      }\r\n    }\r\n    for(int j=0; j<=m; j++){\r\n      for(int i=0; i<n;\
    \ i++){\r\n        sum.at(i+1).at(j) += sum.at(i).at(j);\r\n      }\r\n    }\r\
    \n  }\r\n  void add(int x1, int x2, int y1, int y2, T t = 1){\r\n    sum[x1][y1]\
    \ += t;\r\n    sum[x2][y1] -= t;\r\n    sum[x1][y2] -= t;\r\n    sum[x2][y2] +=\
    \ t;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/Imos2D.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/Imos2D.cpp
layout: document
redirect_from:
- /library/datastructure/Imos2D.cpp
- /library/datastructure/Imos2D.cpp.html
title: datastructure/Imos2D.cpp
---
