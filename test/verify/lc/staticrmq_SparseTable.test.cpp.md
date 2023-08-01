---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/algebraic/monoid/MinMonoid.cpp
    title: datastructure/algebraic/monoid/MinMonoid.cpp
  - icon: ':heavy_check_mark:'
    path: datastructure/sparsetable/SparseTable.cpp
    title: datastructure/sparsetable/SparseTable.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/verify/lc/staticrmq_SparseTable.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"datastructure/sparsetable/SparseTable.cpp\"\n\
    \r\n\r\ntemplate<typename Band>\r\nstruct SparseTable{\r\n  vector<vector<Band>>\
    \ table;\r\n  vector<int> lookup;\r\n  \r\n  SparseTable() = default;\r\n  template<class\
    \ Iiter>\r\n  SparseTable(Iiter first, Iiter last): table(1, vector<Band>(first,\
    \ last)){\r\n    size_t n = table[0].size();\r\n    for(size_t i = 1, b = 1; b\
    \ < table.back().size(); ++i, b <<= 1){\r\n      table.emplace_back(); table.reserve(n\
    \ - b);\r\n      for(size_t j = b; j < table[i-1].size(); ++j){\r\n        table[i].push_back(table[i-1][j\
    \ - b] + table[i-1][j]);\r\n      }\r\n    }\r\n    lookup.assign(n + 1, 0);\r\
    \n    for(size_t i = 2; i < n+1; i++) lookup[i] = lookup[i >> 1] + 1;\r\n  }\r\
    \n  template<class Container>\r\n  SparseTable(const Container &c): SparseTable(begin(c),\
    \ end(c)) {}\r\n  \r\n\r\n  Band fold(int l, int r) const {\r\n    if(l == r)\
    \ return Band{};\r\n    int b = lookup[r - l];\r\n    return table[b][l] + table[b][r\
    \ - (1 << b)];\r\n  }\r\n};\r\n#line 7 \"test/verify/lc/staticrmq_SparseTable.test.cpp\"\
    \n\n#line 2 \"datastructure/algebraic/monoid/MinMonoid.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct MinMonoid{\r\n  T x = numeric_limits<T>::max();\r\n  MinMonoid()\
    \ = default;\r\n  MinMonoid(const MinMonoid&) = default;\r\n  MinMonoid(MinMonoid&&)\
    \ = default;\r\n\r\n  MinMonoid(const T &x): x(x) {}\r\n\r\n  MinMonoid &operator=(const\
    \ MinMonoid&) = default;\r\n  MinMonoid &operator=(MinMonoid&&) = default;\r\n\
    \r\n  MinMonoid &operator+=(const MinMonoid &m){\r\n    x = min(x, m.x);\r\n \
    \   return (*this);\r\n  }\r\n  MinMonoid operator+(const MinMonoid &m) const\
    \ {\r\n    return MinMonoid(*this) += m;\r\n  }\r\n};\r\n#line 9 \"test/verify/lc/staticrmq_SparseTable.test.cpp\"\
    \n\nint main(){\n  int n, q; cin >> n >> q;\n  vector<int> a(n); for(auto&&e :\
    \ a) cin >> e;\n  SparseTable<MinMonoid<int>> st(a);\n  while(q--){\n    int l,\
    \ r; cin >> l >> r;\n    cout << st.fold(l, r).x << \"\\n\";\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"datastructure/sparsetable/SparseTable.cpp\"\
    \n\n#include \"datastructure/algebraic/monoid/MinMonoid.cpp\"\n\nint main(){\n\
    \  int n, q; cin >> n >> q;\n  vector<int> a(n); for(auto&&e : a) cin >> e;\n\
    \  SparseTable<MinMonoid<int>> st(a);\n  while(q--){\n    int l, r; cin >> l >>\
    \ r;\n    cout << st.fold(l, r).x << \"\\n\";\n  }\n}\n"
  dependsOn:
  - datastructure/sparsetable/SparseTable.cpp
  - datastructure/algebraic/monoid/MinMonoid.cpp
  isVerificationFile: true
  path: test/verify/lc/staticrmq_SparseTable.test.cpp
  requiredBy: []
  timestamp: '2023-08-01 22:12:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/lc/staticrmq_SparseTable.test.cpp
layout: document
redirect_from:
- /verify/test/verify/lc/staticrmq_SparseTable.test.cpp
- /verify/test/verify/lc/staticrmq_SparseTable.test.cpp.html
title: test/verify/lc/staticrmq_SparseTable.test.cpp
---
