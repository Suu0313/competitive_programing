---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/sparsetable/DisjointSparseTable.cpp
    title: datastructure/sparsetable/DisjointSparseTable.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/verify/lc/static_range_sum_DisjointSparseTable.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"datastructure/sparsetable/DisjointSparseTable.cpp\"\
    \n\r\n\r\ntemplate<typename SemiGroup>\r\nstruct DisjointSparseTable{\r\n  vector<vector<SemiGroup>>\
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
    \ + table[p][r];\r\n  }\r\n};\r\n#line 7 \"test/verify/lc/static_range_sum_DisjointSparseTable.test.cpp\"\
    \n\nint main(){\n  int n, q; cin >> n >> q;\n  vector<int> a(n); for(auto&&e :\
    \ a) cin >> e;\n  DisjointSparseTable<int64_t> st(a);\n  while(q--){\n    int\
    \ l, r; cin >> l >> r;\n    cout << st.query(l, r) << \"\\n\";\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"datastructure/sparsetable/DisjointSparseTable.cpp\"\
    \n\nint main(){\n  int n, q; cin >> n >> q;\n  vector<int> a(n); for(auto&&e :\
    \ a) cin >> e;\n  DisjointSparseTable<int64_t> st(a);\n  while(q--){\n    int\
    \ l, r; cin >> l >> r;\n    cout << st.query(l, r) << \"\\n\";\n  }\n}\n"
  dependsOn:
  - datastructure/sparsetable/DisjointSparseTable.cpp
  isVerificationFile: true
  path: test/verify/lc/static_range_sum_DisjointSparseTable.test.cpp
  requiredBy: []
  timestamp: '2023-08-01 22:12:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/lc/static_range_sum_DisjointSparseTable.test.cpp
layout: document
redirect_from:
- /verify/test/verify/lc/static_range_sum_DisjointSparseTable.test.cpp
- /verify/test/verify/lc/static_range_sum_DisjointSparseTable.test.cpp.html
title: test/verify/lc/static_range_sum_DisjointSparseTable.test.cpp
---
