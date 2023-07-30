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
  bundledCode: "#line 2 \"datastructure/Doubling.cpp\"\n\r\ntemplate<typename T, size_t\
    \ bwidth = 60>\r\nstruct DoublingM{\r\n  using OP = function<T(T,T)>;\r\n\r\n\
    \  vector<vector<int>> npos;\r\n  vector<vector<T>> val;\r\n  const OP op;\r\n\
    \  bool is_built;\r\n\r\n  DoublingM(size_t n, const OP &op)\r\n    : npos(bwidth,\
    \ vector<int>(n, -1)), val(bwidth, vector<T>(n)), op(op), is_built(false) {}\r\
    \n\r\n  void set_next(size_t i, int p){ npos[0][i] = p; }\r\n  void set_value(size_t\
    \ i, const T &x){ val[0][i] = x; }\r\n  void set_next(const vector<int> &p){ npos[0]\
    \ = p; }\r\n  void set_value(const vector<T> &v){ val[0] = v; }\r\n\r\n  void\
    \ build(){\r\n    is_built = true;\r\n    size_t n = npos[0].size();\r\n    for(size_t\
    \ d = 0; d+1 < bwidth; d++){\r\n      for(size_t i = 0; i < n; i++){\r\n     \
    \   int p = npos[d][i]; if(p == -1) continue;\r\n        npos[d+1][i] = npos[d][p];\r\
    \n        val[d+1][i] = op(val[d][i], val[d][p]);\r\n      }\r\n    }\r\n  }\r\
    \n\r\n  pair<int, T> query(int s, uint64_t k, const T &id = T()) {\r\n    if(!is_built)\
    \ build();\r\n    T res = id;\r\n    for(int d = bwidth-1; d >= 0; d--){\r\n \
    \     if((k>>d) & 1){\r\n        res = op(res, val[d][s]);\r\n        s = npos[d][s];\r\
    \n      }\r\n    }\r\n    return {s, res};\r\n  }\r\n};\r\n\r\n\r\ntemplate<size_t\
    \ bwidth = 60>\r\nstruct Doubling{\r\n\r\n  vector<vector<int>> npos;\r\n  bool\
    \ is_built;\r\n\r\n  Doubling(size_t n): npos(bwidth, vector<int>(n, -1)), is_built(false)\
    \ {}\r\n\r\n  void set_next(size_t i, int p){ npos[0][i] = p; }\r\n  void set_next(const\
    \ vector<int> &p){ npos[0] = p; }\r\n\r\n  void build(){\r\n    is_built = true;\r\
    \n    size_t n = npos[0].size();\r\n    for(size_t d = 0; d+1 < bwidth; d++){\r\
    \n      for(size_t i = 0; i < n; i++){\r\n        int p = npos[d][i]; if(p ==\
    \ -1) continue;\r\n        npos[d+1][i] = npos[d][p];\r\n      }\r\n    }\r\n\
    \  }\r\n\r\n  int query(int s, uint64_t k) {\r\n    if(!is_built) build();\r\n\
    \    for(int d = bwidth-1; d >= 0; d--){\r\n      if((k>>d) & 1) s = npos[d][s];\r\
    \n    }\r\n    return s;\r\n  }\r\n};\n"
  code: "#pragma once\r\n\r\ntemplate<typename T, size_t bwidth = 60>\r\nstruct DoublingM{\r\
    \n  using OP = function<T(T,T)>;\r\n\r\n  vector<vector<int>> npos;\r\n  vector<vector<T>>\
    \ val;\r\n  const OP op;\r\n  bool is_built;\r\n\r\n  DoublingM(size_t n, const\
    \ OP &op)\r\n    : npos(bwidth, vector<int>(n, -1)), val(bwidth, vector<T>(n)),\
    \ op(op), is_built(false) {}\r\n\r\n  void set_next(size_t i, int p){ npos[0][i]\
    \ = p; }\r\n  void set_value(size_t i, const T &x){ val[0][i] = x; }\r\n  void\
    \ set_next(const vector<int> &p){ npos[0] = p; }\r\n  void set_value(const vector<T>\
    \ &v){ val[0] = v; }\r\n\r\n  void build(){\r\n    is_built = true;\r\n    size_t\
    \ n = npos[0].size();\r\n    for(size_t d = 0; d+1 < bwidth; d++){\r\n      for(size_t\
    \ i = 0; i < n; i++){\r\n        int p = npos[d][i]; if(p == -1) continue;\r\n\
    \        npos[d+1][i] = npos[d][p];\r\n        val[d+1][i] = op(val[d][i], val[d][p]);\r\
    \n      }\r\n    }\r\n  }\r\n\r\n  pair<int, T> query(int s, uint64_t k, const\
    \ T &id = T()) {\r\n    if(!is_built) build();\r\n    T res = id;\r\n    for(int\
    \ d = bwidth-1; d >= 0; d--){\r\n      if((k>>d) & 1){\r\n        res = op(res,\
    \ val[d][s]);\r\n        s = npos[d][s];\r\n      }\r\n    }\r\n    return {s,\
    \ res};\r\n  }\r\n};\r\n\r\n\r\ntemplate<size_t bwidth = 60>\r\nstruct Doubling{\r\
    \n\r\n  vector<vector<int>> npos;\r\n  bool is_built;\r\n\r\n  Doubling(size_t\
    \ n): npos(bwidth, vector<int>(n, -1)), is_built(false) {}\r\n\r\n  void set_next(size_t\
    \ i, int p){ npos[0][i] = p; }\r\n  void set_next(const vector<int> &p){ npos[0]\
    \ = p; }\r\n\r\n  void build(){\r\n    is_built = true;\r\n    size_t n = npos[0].size();\r\
    \n    for(size_t d = 0; d+1 < bwidth; d++){\r\n      for(size_t i = 0; i < n;\
    \ i++){\r\n        int p = npos[d][i]; if(p == -1) continue;\r\n        npos[d+1][i]\
    \ = npos[d][p];\r\n      }\r\n    }\r\n  }\r\n\r\n  int query(int s, uint64_t\
    \ k) {\r\n    if(!is_built) build();\r\n    for(int d = bwidth-1; d >= 0; d--){\r\
    \n      if((k>>d) & 1) s = npos[d][s];\r\n    }\r\n    return s;\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/Doubling.cpp
  requiredBy: []
  timestamp: '2023-03-10 19:27:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/Doubling.cpp
layout: document
redirect_from:
- /library/datastructure/Doubling.cpp
- /library/datastructure/Doubling.cpp.html
title: datastructure/Doubling.cpp
---
