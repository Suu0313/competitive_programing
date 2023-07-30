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
  bundledCode: "#line 2 \"datastructure/sparsetable/SparseTable2D.cpp\"\n\r\n\r\n\
    template<typename T>\r\nstruct SparseTable2D{\r\n  using F = function<T(T, T)>;\r\
    \n  const F f;\r\n  vector<vector<vector<vector<T>>>> table;\r\n  vector<int>\
    \ lookup;\r\n\r\n  SparseTable2D(const vector<vector<T>> &v, const F &f): f(f){\r\
    \n    const int n = v.size(), m = v[0].size();\r\n    const int nb = 32 - __builtin_clz(n),\
    \ mb = 32 - __builtin_clz(m);\r\n    table.assign(nb, vector(n, vector(mb, vector<T>(m))));\r\
    \n    for(int rj = 0; rj < n; rj++){\r\n\r\n      for(int cj = 0; cj < m; cj++)\
    \ table[0][rj][0][cj] = v[rj][cj];\r\n\r\n      for(int ci = 1; ci < mb; ci++){\r\
    \n        for(int cj = 0; cj+(1<<ci) <= m; cj++){\r\n          table[0][rj][ci][cj]\r\
    \n            = f(table[0][rj][ci-1][cj], table[0][rj][ci-1][cj+(1<<(ci-1))]);\r\
    \n        }\r\n      }\r\n    }\r\n\r\n    for(int ri = 1; ri <= nb; ri++){\r\n\
    \      for(int rj = 0; rj+(1<<ri) <= n; rj++){\r\n        for(int ci = 0; ci <\
    \ mb; ci++){\r\n          for(int cj = 0; cj < m; cj++){\r\n            table[ri][rj][ci][cj]\r\
    \n              = f(table[ri-1][rj][ci][cj], table[ri-1][rj+(1<<(ri-1))][ci][cj]);\r\
    \n          }\r\n        }\r\n      }\r\n    }\r\n\r\n    int l = max(n, m);\r\
    \n    lookup.assign(l+1, 0);\r\n    for(int i = 2; i < l+1; i++){\r\n      lookup[i]\
    \ = lookup[i>>1] + 1;\r\n    }\r\n  }\r\n\r\n  T fold(int x1, int x2, int y1,\
    \ int y2) const {\r\n    int nb = lookup[x2 - x1], mb = lookup[y2 - y1];\r\n \
    \   T R1 = f(table[nb][x1][mb][y1], table[nb][x1][mb][y2 - (1<<mb)]);\r\n    T\
    \ R2 = f(table[nb][x2 - (1<<nb)][mb][y1], table[nb][x2 - (1<<nb)][mb][y2 - (1<<mb)]);\r\
    \n    return f(R1, R2);\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n\r\ntemplate<typename T>\r\nstruct SparseTable2D{\r\n\
    \  using F = function<T(T, T)>;\r\n  const F f;\r\n  vector<vector<vector<vector<T>>>>\
    \ table;\r\n  vector<int> lookup;\r\n\r\n  SparseTable2D(const vector<vector<T>>\
    \ &v, const F &f): f(f){\r\n    const int n = v.size(), m = v[0].size();\r\n \
    \   const int nb = 32 - __builtin_clz(n), mb = 32 - __builtin_clz(m);\r\n    table.assign(nb,\
    \ vector(n, vector(mb, vector<T>(m))));\r\n    for(int rj = 0; rj < n; rj++){\r\
    \n\r\n      for(int cj = 0; cj < m; cj++) table[0][rj][0][cj] = v[rj][cj];\r\n\
    \r\n      for(int ci = 1; ci < mb; ci++){\r\n        for(int cj = 0; cj+(1<<ci)\
    \ <= m; cj++){\r\n          table[0][rj][ci][cj]\r\n            = f(table[0][rj][ci-1][cj],\
    \ table[0][rj][ci-1][cj+(1<<(ci-1))]);\r\n        }\r\n      }\r\n    }\r\n\r\n\
    \    for(int ri = 1; ri <= nb; ri++){\r\n      for(int rj = 0; rj+(1<<ri) <= n;\
    \ rj++){\r\n        for(int ci = 0; ci < mb; ci++){\r\n          for(int cj =\
    \ 0; cj < m; cj++){\r\n            table[ri][rj][ci][cj]\r\n              = f(table[ri-1][rj][ci][cj],\
    \ table[ri-1][rj+(1<<(ri-1))][ci][cj]);\r\n          }\r\n        }\r\n      }\r\
    \n    }\r\n\r\n    int l = max(n, m);\r\n    lookup.assign(l+1, 0);\r\n    for(int\
    \ i = 2; i < l+1; i++){\r\n      lookup[i] = lookup[i>>1] + 1;\r\n    }\r\n  }\r\
    \n\r\n  T fold(int x1, int x2, int y1, int y2) const {\r\n    int nb = lookup[x2\
    \ - x1], mb = lookup[y2 - y1];\r\n    T R1 = f(table[nb][x1][mb][y1], table[nb][x1][mb][y2\
    \ - (1<<mb)]);\r\n    T R2 = f(table[nb][x2 - (1<<nb)][mb][y1], table[nb][x2 -\
    \ (1<<nb)][mb][y2 - (1<<mb)]);\r\n    return f(R1, R2);\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/sparsetable/SparseTable2D.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/sparsetable/SparseTable2D.cpp
layout: document
redirect_from:
- /library/datastructure/sparsetable/SparseTable2D.cpp
- /library/datastructure/sparsetable/SparseTable2D.cpp.html
title: datastructure/sparsetable/SparseTable2D.cpp
---
