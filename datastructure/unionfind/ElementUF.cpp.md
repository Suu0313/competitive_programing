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
  bundledCode: "#line 2 \"datastructure/unionfind/ElementUF.cpp\"\n\r\ntemplate<class\
    \ Monoid>\r\nstruct ElementUF {\r\n  \r\n  vector<int> data;\r\n  vector<Monoid>\
    \ val;\r\n  \r\n  ElementUF() = default;\r\n  ElementUF(int n): data(n, -1), val(n)\
    \ {}\r\n  template<typename Iiter>\r\n  ElementUF(Iiter first, Iiter last): ElementUF(distance(first,\
    \ last)) {\r\n    for(int i = 0; first != last; ++i, ++first) val[i] = *first;\r\
    \n  }\r\n  template<typename T>\r\n  ElementUF(const vector<T> &x): ElementUF(x.begin(),\
    \ x.end()) {}\r\n  \r\n  int find(int x) {\r\n    int root = x;\r\n    while(data[root]\
    \ >= 0) root = data[root];\r\n    while(data[x] >= 0) x = exchange(data[x], root);\r\
    \n    return root;\r\n  }\r\n\r\n  bool unite(int x, int y){\r\n    x = find(x);\r\
    \n    y = find(y);\r\n    if(x == y) return false;\r\n\r\n    if(data[x] > data[y])\
    \ swap(x, y);\r\n\r\n    val[x] += val[y];\r\n    data[x] += data[y];\r\n    data[y]\
    \ = x;\r\n    return true;\r\n  }\r\n\r\n  bool same(int x, int y){\r\n    return\
    \ find(x) == find(y);\r\n  }\r\n  \r\n  int size(int x){\r\n    return -data[find(x)];\r\
    \n  }\r\n\r\n  Monoid &operator[](int k){ return val[k]; }\r\n  const Monoid &operator[](int\
    \ k) const { return val[k]; }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<class Monoid>\r\nstruct ElementUF {\r\n  \r\n\
    \  vector<int> data;\r\n  vector<Monoid> val;\r\n  \r\n  ElementUF() = default;\r\
    \n  ElementUF(int n): data(n, -1), val(n) {}\r\n  template<typename Iiter>\r\n\
    \  ElementUF(Iiter first, Iiter last): ElementUF(distance(first, last)) {\r\n\
    \    for(int i = 0; first != last; ++i, ++first) val[i] = *first;\r\n  }\r\n \
    \ template<typename T>\r\n  ElementUF(const vector<T> &x): ElementUF(x.begin(),\
    \ x.end()) {}\r\n  \r\n  int find(int x) {\r\n    int root = x;\r\n    while(data[root]\
    \ >= 0) root = data[root];\r\n    while(data[x] >= 0) x = exchange(data[x], root);\r\
    \n    return root;\r\n  }\r\n\r\n  bool unite(int x, int y){\r\n    x = find(x);\r\
    \n    y = find(y);\r\n    if(x == y) return false;\r\n\r\n    if(data[x] > data[y])\
    \ swap(x, y);\r\n\r\n    val[x] += val[y];\r\n    data[x] += data[y];\r\n    data[y]\
    \ = x;\r\n    return true;\r\n  }\r\n\r\n  bool same(int x, int y){\r\n    return\
    \ find(x) == find(y);\r\n  }\r\n  \r\n  int size(int x){\r\n    return -data[find(x)];\r\
    \n  }\r\n\r\n  Monoid &operator[](int k){ return val[k]; }\r\n  const Monoid &operator[](int\
    \ k) const { return val[k]; }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/unionfind/ElementUF.cpp
  requiredBy: []
  timestamp: '2023-07-22 06:23:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/unionfind/ElementUF.cpp
layout: document
redirect_from:
- /library/datastructure/unionfind/ElementUF.cpp
- /library/datastructure/unionfind/ElementUF.cpp.html
title: datastructure/unionfind/ElementUF.cpp
---
