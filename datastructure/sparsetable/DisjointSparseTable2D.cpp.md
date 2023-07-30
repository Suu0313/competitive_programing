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
  bundledCode: "#line 2 \"datastructure/sparsetable/DisjointSparseTable2D.cpp\"\n\r\
    \ntemplate<typename T>\r\nstruct DisjointSparseTable2D{\r\n  using F = function<T(T,\
    \ T)>;\r\n  const F f;\r\n  vector<vector<vector<vector<T>>>> table;\r\n  vector<int>\
    \ lookup;\r\n\r\n  DisjointSparseTable2D(const vector<vector<T>> &v, const F &f):\
    \ f(f){\r\n    const int n = v.size(), m = v[0].size();\r\n    const int nb =\
    \ 32 - __builtin_clz(n), mb = 32 - __builtin_clz(m);\r\n    table.assign(nb, vector(n,\
    \ vector(mb, vector<T>(m))));\r\n    for(int rj = 0; rj < n; rj++){\r\n\r\n  \
    \    for(int cj = 0; cj < m; cj++) table[0][rj][0][cj] = v[rj][cj];\r\n\r\n  \
    \    for(int ci = 1; ci < mb; ci++){\r\n        int shift = 1 << ci;\r\n     \
    \   for(int cj = 0; cj < m; cj += shift << 1){\r\n          int t = min(cj+shift,\
    \ m);\r\n          table[0][rj][ci][t-1] = v[rj][t-1];\r\n          for(int k\
    \ = t-2; k >= cj; k--){\r\n            table[0][rj][ci][k] = f(v[rj][k], table[0][rj][ci][k+1]);\r\
    \n          }\r\n          if(m <= t) break;\r\n          table[0][rj][ci][t]\
    \ = v[rj][t];\r\n          int r = min(t+shift, m);\r\n          for(int k = t+1;\
    \ k < r; k++){\r\n            table[0][rj][ci][k] = f(table[0][rj][ci][k-1], v[rj][k]);\r\
    \n          }\r\n        }\r\n      }\r\n    }\r\n\r\n    for(int ri = 1; ri <\
    \ nb; ri++){\r\n      int rshift = 1 << ri;\r\n      for(int rj = 0; rj < n; rj\
    \ += rshift << 1){\r\n        int rt = min(rj+rshift, n);\r\n        for(int ci\
    \ = 0; ci < mb; ci++){\r\n          for(int cj = 0; cj < m; cj++){\r\n       \
    \     table[ri][rt-1][ci][cj] = table[0][rt-1][ci][cj];\r\n            for(int\
    \ k = rt-2; k >= rj; k--){\r\n              table[ri][k][ci][cj] = f(table[0][k][ci][cj],\
    \ table[ri][k+1][ci][cj]);\r\n            }\r\n          }\r\n        }\r\n  \
    \      if(n <= rt) break;\r\n        for(int ci = 0; ci < mb; ci++){\r\n     \
    \     for(int cj = 0; cj < m; cj++){\r\n            table[ri][rt][ci][cj] = table[0][rt][ci][cj];\r\
    \n            int r = min(rt+rshift, n);\r\n            for(int k = rt+1; k <\
    \ r; k++){\r\n              table[ri][k][ci][cj] = f(table[ri][k-1][ci][cj], table[0][k][ci][cj]);\r\
    \n            }\r\n          }\r\n        }\r\n      }\r\n    }\r\n    const int\
    \ b = max(nb, mb);\r\n    lookup.assign(1 << b, 0);\r\n    for(int i = 2; i <\
    \ (1 << b); i++){\r\n      lookup.at(i) = lookup.at(i>>1) + 1;\r\n    }\r\n  }\r\
    \n\r\n  T query(int x1, int x2, int y1, int y2) const {\r\n    x2--; y2--;\r\n\
    \    if(x1 >= x2){\r\n      if(y1 >= y2) return table[0][x1][0][y1];\r\n     \
    \ int p = lookup[y1 ^ y2];\r\n      return f(table[0][x1][p][y1], table[0][x1][p][y2]);\r\
    \n    }\r\n    int np = lookup[x1 ^ x2];\r\n    if(y1 >= y2) return f(table[np][x1][0][y1],\
    \ table[np][x2][0][y1]);\r\n    int mp = lookup[y1 ^ y2];\r\n    T R1 = f(table[np][x1][mp][y1],\
    \ table[np][x1][mp][y2]);\r\n    T R2 = f(table[np][x2][mp][y1], table[np][x2][mp][y2]);\r\
    \n    return f(R1, R2);\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct DisjointSparseTable2D{\r\
    \n  using F = function<T(T, T)>;\r\n  const F f;\r\n  vector<vector<vector<vector<T>>>>\
    \ table;\r\n  vector<int> lookup;\r\n\r\n  DisjointSparseTable2D(const vector<vector<T>>\
    \ &v, const F &f): f(f){\r\n    const int n = v.size(), m = v[0].size();\r\n \
    \   const int nb = 32 - __builtin_clz(n), mb = 32 - __builtin_clz(m);\r\n    table.assign(nb,\
    \ vector(n, vector(mb, vector<T>(m))));\r\n    for(int rj = 0; rj < n; rj++){\r\
    \n\r\n      for(int cj = 0; cj < m; cj++) table[0][rj][0][cj] = v[rj][cj];\r\n\
    \r\n      for(int ci = 1; ci < mb; ci++){\r\n        int shift = 1 << ci;\r\n\
    \        for(int cj = 0; cj < m; cj += shift << 1){\r\n          int t = min(cj+shift,\
    \ m);\r\n          table[0][rj][ci][t-1] = v[rj][t-1];\r\n          for(int k\
    \ = t-2; k >= cj; k--){\r\n            table[0][rj][ci][k] = f(v[rj][k], table[0][rj][ci][k+1]);\r\
    \n          }\r\n          if(m <= t) break;\r\n          table[0][rj][ci][t]\
    \ = v[rj][t];\r\n          int r = min(t+shift, m);\r\n          for(int k = t+1;\
    \ k < r; k++){\r\n            table[0][rj][ci][k] = f(table[0][rj][ci][k-1], v[rj][k]);\r\
    \n          }\r\n        }\r\n      }\r\n    }\r\n\r\n    for(int ri = 1; ri <\
    \ nb; ri++){\r\n      int rshift = 1 << ri;\r\n      for(int rj = 0; rj < n; rj\
    \ += rshift << 1){\r\n        int rt = min(rj+rshift, n);\r\n        for(int ci\
    \ = 0; ci < mb; ci++){\r\n          for(int cj = 0; cj < m; cj++){\r\n       \
    \     table[ri][rt-1][ci][cj] = table[0][rt-1][ci][cj];\r\n            for(int\
    \ k = rt-2; k >= rj; k--){\r\n              table[ri][k][ci][cj] = f(table[0][k][ci][cj],\
    \ table[ri][k+1][ci][cj]);\r\n            }\r\n          }\r\n        }\r\n  \
    \      if(n <= rt) break;\r\n        for(int ci = 0; ci < mb; ci++){\r\n     \
    \     for(int cj = 0; cj < m; cj++){\r\n            table[ri][rt][ci][cj] = table[0][rt][ci][cj];\r\
    \n            int r = min(rt+rshift, n);\r\n            for(int k = rt+1; k <\
    \ r; k++){\r\n              table[ri][k][ci][cj] = f(table[ri][k-1][ci][cj], table[0][k][ci][cj]);\r\
    \n            }\r\n          }\r\n        }\r\n      }\r\n    }\r\n    const int\
    \ b = max(nb, mb);\r\n    lookup.assign(1 << b, 0);\r\n    for(int i = 2; i <\
    \ (1 << b); i++){\r\n      lookup.at(i) = lookup.at(i>>1) + 1;\r\n    }\r\n  }\r\
    \n\r\n  T query(int x1, int x2, int y1, int y2) const {\r\n    x2--; y2--;\r\n\
    \    if(x1 >= x2){\r\n      if(y1 >= y2) return table[0][x1][0][y1];\r\n     \
    \ int p = lookup[y1 ^ y2];\r\n      return f(table[0][x1][p][y1], table[0][x1][p][y2]);\r\
    \n    }\r\n    int np = lookup[x1 ^ x2];\r\n    if(y1 >= y2) return f(table[np][x1][0][y1],\
    \ table[np][x2][0][y1]);\r\n    int mp = lookup[y1 ^ y2];\r\n    T R1 = f(table[np][x1][mp][y1],\
    \ table[np][x1][mp][y2]);\r\n    T R2 = f(table[np][x2][mp][y1], table[np][x2][mp][y2]);\r\
    \n    return f(R1, R2);\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/sparsetable/DisjointSparseTable2D.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/sparsetable/DisjointSparseTable2D.cpp
layout: document
redirect_from:
- /library/datastructure/sparsetable/DisjointSparseTable2D.cpp
- /library/datastructure/sparsetable/DisjointSparseTable2D.cpp.html
title: datastructure/sparsetable/DisjointSparseTable2D.cpp
---
