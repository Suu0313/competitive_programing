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
  bundledCode: "#line 2 \"datastructure/unionfind/UndoUF.cpp\"\n\r\nstruct UndoUF\
    \ {\r\n  vector<int> data;\r\n  stack<pair<int, int>> hist;\r\n  \r\n  UndoUF()\
    \ {}\r\n  UndoUF(int n): data(n, -1) {}\r\n  void init(int n){\r\n    data.assign(n,-1);\r\
    \n  }\r\n\r\n  int find(int x) {\r\n    while(data[x] >= 0) x = data[x];\r\n \
    \   return x;\r\n  }\r\n\r\n  bool unite(int x, int y){\r\n    x = find(x);\r\n\
    \    y = find(y);\r\n    hist.emplace(x,data[x]);\r\n    hist.emplace(y,data[y]);\r\
    \n    if(x == y) return false;\r\n\r\n    if(data[x] > data[y]) swap(x,y);\r\n\
    \    data[x] += data[y];\r\n    data[y] = x;\r\n    return true;\r\n  }\r\n\r\n\
    \  bool same(int x, int y){\r\n    return find(x) == find(y);\r\n  }\r\n\r\n \
    \ int size(int x){\r\n    return -data[find(x)];\r\n  }\r\n\r\n  bool undo(){\r\
    \n    if(hist.empty()) return false;\r\n    for(int i = 0; i < 2; i++){\r\n  \
    \    auto[x,px] = hist.top();\r\n      data[x] = px;\r\n      hist.pop();\r\n\
    \    }\r\n    return true;\r\n  }\r\n\r\n  void clear(){\r\n    while(!hist.empty())\
    \ hist.pop();\r\n  }\r\n  \r\n  void rollback(){\r\n    while(!hist.empty()) undo();\r\
    \n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\nstruct UndoUF {\r\n  vector<int> data;\r\n  stack<pair<int,\
    \ int>> hist;\r\n  \r\n  UndoUF() {}\r\n  UndoUF(int n): data(n, -1) {}\r\n  void\
    \ init(int n){\r\n    data.assign(n,-1);\r\n  }\r\n\r\n  int find(int x) {\r\n\
    \    while(data[x] >= 0) x = data[x];\r\n    return x;\r\n  }\r\n\r\n  bool unite(int\
    \ x, int y){\r\n    x = find(x);\r\n    y = find(y);\r\n    hist.emplace(x,data[x]);\r\
    \n    hist.emplace(y,data[y]);\r\n    if(x == y) return false;\r\n\r\n    if(data[x]\
    \ > data[y]) swap(x,y);\r\n    data[x] += data[y];\r\n    data[y] = x;\r\n   \
    \ return true;\r\n  }\r\n\r\n  bool same(int x, int y){\r\n    return find(x)\
    \ == find(y);\r\n  }\r\n\r\n  int size(int x){\r\n    return -data[find(x)];\r\
    \n  }\r\n\r\n  bool undo(){\r\n    if(hist.empty()) return false;\r\n    for(int\
    \ i = 0; i < 2; i++){\r\n      auto[x,px] = hist.top();\r\n      data[x] = px;\r\
    \n      hist.pop();\r\n    }\r\n    return true;\r\n  }\r\n\r\n  void clear(){\r\
    \n    while(!hist.empty()) hist.pop();\r\n  }\r\n  \r\n  void rollback(){\r\n\
    \    while(!hist.empty()) undo();\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/unionfind/UndoUF.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/unionfind/UndoUF.cpp
layout: document
redirect_from:
- /library/datastructure/unionfind/UndoUF.cpp
- /library/datastructure/unionfind/UndoUF.cpp.html
title: datastructure/unionfind/UndoUF.cpp
---
