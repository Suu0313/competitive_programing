---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/unionfind/UnionFind.cpp
    title: datastructure/unionfind/UnionFind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/verify/lc/unionfind.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/unionfind\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 2 \"datastructure/unionfind/UnionFind.cpp\"\n\nstruct\
    \ UnionFind {\n  \n  vector<int> data;\n  int cnt,n,smax;\n  \n  UnionFind() =\
    \ default;\n  UnionFind(int n_): data(n_,-1),cnt(n_),n(n_),smax(1) {}\n  \n  void\
    \ init(int n_) {\n    data.assign(n_,-1);\n    cnt = n_;\n    n = n_;\n    smax\
    \ = 1;\n  }\n  \n  int find(int x) {\n    int root = x;\n    while(data[root]\
    \ >= 0) root = data[root];\n    while(data[x] >= 0) x = exchange(data[x], root);\n\
    \    return root;\n  }\n\n  bool unite(int x, int y){\n    x = find(x);\n    y\
    \ = find(y);\n    if(x == y) return false;\n    cnt--;\n\n    if(data[x] > data[y])\
    \ swap(x,y);\n    data[x] += data[y];\n    smax = max(smax, -data[x]);\n    data[y]\
    \ = x;\n    return true;\n  }\n\n  bool same(int x, int y){\n    return find(x)\
    \ == find(y);\n  }\n  \n  int size(int x){\n    return -data[find(x)];\n  }\n\n\
    \n  vector<vector<int>> groups() {\n    vector<int> leader_buf(n), group_size(n);\n\
    \    for(int i=0; i<n; i++){\n      leader_buf.at(i) = find(i);\n      group_size.at(leader_buf.at(i))++;\n\
    \    }\n    vector<vector<int>> result(n);\n    for(int i=0; i<n; i++){\n    \
    \  result.at(i).reserve(group_size.at(i));\n    }\n    for(int i=0; i<n; i++){\n\
    \      result.at(leader_buf.at(i)).emplace_back(i);\n    }\n    result.erase(\n\
    \      remove_if(\n        result.begin(), result.end(),\n        [&](const vector<int>&\
    \ v) { return v.empty(); }\n      ),\n      result.end()\n    );\n    return result;\n\
    \  }\n\n};\n#line 7 \"test/verify/lc/unionfind.test.cpp\"\n\nint main(){\n  int\
    \ n, q; cin >> n >> q;\n  UnionFind uf(n);\n  while(q--){\n    int t, u, v; cin\
    \ >> t >> u >> v;\n    if(t == 0) uf.unite(u, v);\n    else cout << uf.same(u,\
    \ v) << \"\\n\";\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"datastructure/unionfind/UnionFind.cpp\"\
    \n\nint main(){\n  int n, q; cin >> n >> q;\n  UnionFind uf(n);\n  while(q--){\n\
    \    int t, u, v; cin >> t >> u >> v;\n    if(t == 0) uf.unite(u, v);\n    else\
    \ cout << uf.same(u, v) << \"\\n\";\n  }\n}\n"
  dependsOn:
  - datastructure/unionfind/UnionFind.cpp
  isVerificationFile: true
  path: test/verify/lc/unionfind.test.cpp
  requiredBy: []
  timestamp: '2023-07-31 01:08:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/lc/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/verify/lc/unionfind.test.cpp
- /verify/test/verify/lc/unionfind.test.cpp.html
title: test/verify/lc/unionfind.test.cpp
---
