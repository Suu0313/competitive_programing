---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/lc/static_range_sum_DisjointSparseTable.test.cpp
    title: test/verify/lc/static_range_sum_DisjointSparseTable.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/sparsetable/DisjointSparseTable.cpp\"\n\r\n\
    \r\ntemplate<typename SemiGroup>\r\nstruct DisjointSparseTable{\r\n  vector<vector<SemiGroup>>\
    \ table;\r\n  vector<int> lookup;\r\n\r\n  DisjointSparseTable() = default;\r\n\
    \  template<class Iiter>\r\n  DisjointSparseTable(Iiter first, Iiter last): table(1,\
    \ vector<SemiGroup>(first, last)){\r\n    size_t n = table[0].size();\r\n    for(size_t\
    \ i = 1, b = 1; b < n; ++i, b <<= 1){\r\n      table.push_back(table[0]);\r\n\
    \      for(size_t j = 0; j < n; j += b << 2){\r\n        size_t t = min(j + (b\
    \ << 1), n), r = min(t + (b << 1), n);\r\n        for(size_t k = 0; t >= j+2+k;\
    \ ++k) table[i][t-2-k] = table[0][t-2-k] + table[i][t-1-k];\r\n        if(n <=\
    \ t) break;\r\n        for(size_t k = t+1; k < r; k++) table[i][k] = table[i][k\
    \ - 1] + table[0][k];\r\n      }\r\n    }\r\n    lookup.assign(1 << table.size(),\
    \ 0);\r\n    for(size_t i = 2; i < lookup.size(); i++) lookup[i] = lookup[i >>\
    \ 1] + 1;\r\n  }\r\n  template<class Container>\r\n  DisjointSparseTable(const\
    \ Container &c): DisjointSparseTable(begin(c), end(c)) {}\r\n\r\n\r\n  SemiGroup\
    \ query(int l, int r) const {\r\n    if(l >= r) return SemiGroup{};\r\n    if(l\
    \ >= --r) return table[0][l];\r\n    int p = lookup.at(l ^ r);\r\n    return table[p][l]\
    \ + table[p][r];\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n\r\ntemplate<typename SemiGroup>\r\nstruct DisjointSparseTable{\r\
    \n  vector<vector<SemiGroup>> table;\r\n  vector<int> lookup;\r\n\r\n  DisjointSparseTable()\
    \ = default;\r\n  template<class Iiter>\r\n  DisjointSparseTable(Iiter first,\
    \ Iiter last): table(1, vector<SemiGroup>(first, last)){\r\n    size_t n = table[0].size();\r\
    \n    for(size_t i = 1, b = 1; b < n; ++i, b <<= 1){\r\n      table.push_back(table[0]);\r\
    \n      for(size_t j = 0; j < n; j += b << 2){\r\n        size_t t = min(j + (b\
    \ << 1), n), r = min(t + (b << 1), n);\r\n        for(size_t k = 0; t >= j+2+k;\
    \ ++k) table[i][t-2-k] = table[0][t-2-k] + table[i][t-1-k];\r\n        if(n <=\
    \ t) break;\r\n        for(size_t k = t+1; k < r; k++) table[i][k] = table[i][k\
    \ - 1] + table[0][k];\r\n      }\r\n    }\r\n    lookup.assign(1 << table.size(),\
    \ 0);\r\n    for(size_t i = 2; i < lookup.size(); i++) lookup[i] = lookup[i >>\
    \ 1] + 1;\r\n  }\r\n  template<class Container>\r\n  DisjointSparseTable(const\
    \ Container &c): DisjointSparseTable(begin(c), end(c)) {}\r\n\r\n\r\n  SemiGroup\
    \ query(int l, int r) const {\r\n    if(l >= r) return SemiGroup{};\r\n    if(l\
    \ >= --r) return table[0][l];\r\n    int p = lookup.at(l ^ r);\r\n    return table[p][l]\
    \ + table[p][r];\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/sparsetable/DisjointSparseTable.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/lc/static_range_sum_DisjointSparseTable.test.cpp
documentation_of: datastructure/sparsetable/DisjointSparseTable.cpp
layout: document
redirect_from:
- /library/datastructure/sparsetable/DisjointSparseTable.cpp
- /library/datastructure/sparsetable/DisjointSparseTable.cpp.html
title: datastructure/sparsetable/DisjointSparseTable.cpp
---
