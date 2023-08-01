---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/fenwicktree/FenwickTree.cpp
    title: datastructure/fenwicktree/FenwickTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/verify/lc/point_add_range_sum_FenwickTree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"datastructure/fenwicktree/FenwickTree.cpp\"\
    \n\ntemplate <typename T=int>\nstruct FenwickTree{\n  int n;\n  vector<T> node;\n\
    \  FenwickTree() = default;\n  FenwickTree(int n_) : n(n_+1), node(n) {}\n  FenwickTree(const\
    \ FenwickTree&) = default;\n  FenwickTree(FenwickTree&&) = default;\n  FenwickTree\
    \ &operator=(const FenwickTree&) = default;\n  FenwickTree &operator=(FenwickTree&&)\
    \ = default;\n\n  void add(int i, T x){\n    for(int idx = i+1; idx < n; idx +=\
    \ (idx & -idx)){\n      node.at(idx) += x;\n    }\n  }\n\n  T sum(int i) const\
    \ { //[0,i)\n    T s{};\n    for(int idx = i; idx > 0; idx -= (idx & -idx)){\n\
    \      s += node.at(idx);\n    }\n    return s;\n  }\n  T query(int l, int r)\
    \ const { //[l,r)\n    return sum(r)-sum(l); \n  }\n\n  T operator[](int i) const\
    \ { return query(i,i+1); }\n\n  int lower_bound(T w) const {\n    if(w <= 0) return\
    \ 0;\n    int x = 0, r = 1;\n    while(r < n) r *= 2;\n    for(int len = r; len>0;\
    \ len>>=1){\n      if(x+len<n && node.at(x+len) < w){\n        w -= node.at(x+=len);\n\
    \      }\n    }\n    return x;\n  }\n};\n#line 7 \"test/verify/lc/point_add_range_sum_FenwickTree.test.cpp\"\
    \n\nint main(){\n  int n, q; cin >> n >> q;\n  FenwickTree<int64_t> ft(n);\n\n\
    \  for(int i = 0; i < n; ++i){\n    int a; cin >> a;\n    ft.add(i, a);\n  }\n\
    \n  while(q--){\n    int  t, l, r; cin >> t >> l >> r;\n\n    if(t == 0) ft.add(l,\
    \ r);\n    else cout << ft.query(l, r) << \"\\n\";\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"datastructure/fenwicktree/FenwickTree.cpp\"\
    \n\nint main(){\n  int n, q; cin >> n >> q;\n  FenwickTree<int64_t> ft(n);\n\n\
    \  for(int i = 0; i < n; ++i){\n    int a; cin >> a;\n    ft.add(i, a);\n  }\n\
    \n  while(q--){\n    int  t, l, r; cin >> t >> l >> r;\n\n    if(t == 0) ft.add(l,\
    \ r);\n    else cout << ft.query(l, r) << \"\\n\";\n  }\n}\n"
  dependsOn:
  - datastructure/fenwicktree/FenwickTree.cpp
  isVerificationFile: true
  path: test/verify/lc/point_add_range_sum_FenwickTree.test.cpp
  requiredBy: []
  timestamp: '2023-08-01 22:12:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/lc/point_add_range_sum_FenwickTree.test.cpp
layout: document
redirect_from:
- /verify/test/verify/lc/point_add_range_sum_FenwickTree.test.cpp
- /verify/test/verify/lc/point_add_range_sum_FenwickTree.test.cpp.html
title: test/verify/lc/point_add_range_sum_FenwickTree.test.cpp
---
