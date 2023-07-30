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
  bundledCode: "#line 2 \"datastructure/sparsetable/SparseTable.cpp\"\n\r\n\r\ntemplate<typename\
    \ Band>\r\nstruct SparseTable{\r\n  vector<vector<Band>> table;\r\n  vector<int>\
    \ lookup;\r\n  \r\n  SparseTable() = default;\r\n  template<class Iiter>\r\n \
    \ SparseTable(Iiter first, Iiter last): table(1, vector<Band>(first, last)){\r\
    \n    size_t n = table[0].size();\r\n    for(size_t i = 1, b = 1; b < table.back().size();\
    \ ++i, b <<= 1){\r\n      table.emplace_back(); table.reserve(n - b);\r\n    \
    \  for(size_t j = b; j < table[i-1].size(); ++j){\r\n        table[i].push_back(table[i-1][j\
    \ - b] + table[i-1][j]);\r\n      }\r\n    }\r\n    lookup.assign(n + 1, 0);\r\
    \n    for(size_t i = 2; i < n+1; i++) lookup[i] = lookup[i >> 1] + 1;\r\n  }\r\
    \n  template<class Container>\r\n  SparseTable(const Container &c): SparseTable(begin(c),\
    \ end(c)) {}\r\n  \r\n\r\n  Band fold(int l, int r) const {\r\n    if(l == r)\
    \ return Band{};\r\n    int b = lookup[r - l];\r\n    return table[b][l] + table[b][r\
    \ - (1 << b)];\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n\r\ntemplate<typename Band>\r\nstruct SparseTable{\r\n\
    \  vector<vector<Band>> table;\r\n  vector<int> lookup;\r\n  \r\n  SparseTable()\
    \ = default;\r\n  template<class Iiter>\r\n  SparseTable(Iiter first, Iiter last):\
    \ table(1, vector<Band>(first, last)){\r\n    size_t n = table[0].size();\r\n\
    \    for(size_t i = 1, b = 1; b < table.back().size(); ++i, b <<= 1){\r\n    \
    \  table.emplace_back(); table.reserve(n - b);\r\n      for(size_t j = b; j <\
    \ table[i-1].size(); ++j){\r\n        table[i].push_back(table[i-1][j - b] + table[i-1][j]);\r\
    \n      }\r\n    }\r\n    lookup.assign(n + 1, 0);\r\n    for(size_t i = 2; i\
    \ < n+1; i++) lookup[i] = lookup[i >> 1] + 1;\r\n  }\r\n  template<class Container>\r\
    \n  SparseTable(const Container &c): SparseTable(begin(c), end(c)) {}\r\n  \r\n\
    \r\n  Band fold(int l, int r) const {\r\n    if(l == r) return Band{};\r\n   \
    \ int b = lookup[r - l];\r\n    return table[b][l] + table[b][r - (1 << b)];\r\
    \n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/sparsetable/SparseTable.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/sparsetable/SparseTable.cpp
layout: document
redirect_from:
- /library/datastructure/sparsetable/SparseTable.cpp
- /library/datastructure/sparsetable/SparseTable.cpp.html
title: datastructure/sparsetable/SparseTable.cpp
---
