---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: datastructure/rangetree/RangeSetQuery.cpp
    title: datastructure/rangetree/RangeSetQuery.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/rangetree/StaticRangeTree.cpp\"\n\r\n\r\n\
    template<typename Tx, typename Ty, typename T = int>\r\nstruct StaticRangeTree{\r\
    \n  using OP = function<T(T, T)>;\r\n  int n;\r\n  vector<Tx> xs;\r\n  vector<vector<Ty>>\
    \ ys;\r\n  vector<vector<T>> sum;\r\n  const OP op, inv;\r\n  const T id;\r\n\r\
    \n  StaticRangeTree(const OP &op = plus{}, const OP &inv = minus{}, const T &id\
    \ = 0)\r\n  : n(1), op(op), inv(inv), id(id) {}\r\n\r\n  void build(vector<tuple<Tx,Ty,T>>\
    \ ps){\r\n    int n0 = int(ps.size());\r\n    sort(begin(ps), end(ps));\r\n  \
    \  xs.resize(n0);\r\n    for(int i = 0; i < n0; ++i) xs[i] = get<0>(ps[i]);\r\n\
    \    xs.erase(unique(begin(xs), end(xs)), end(xs));\r\n    n0 = int(xs.size());\r\
    \n    for(n = 1; n < n0; ) n <<= 1;\r\n    xs.resize(n, numeric_limits<Tx>::max());\r\
    \n    ys.resize(n * 2);\r\n    sum.resize(n * 2, vector<T>(1, id));\r\n    int\
    \ cur = 0;\r\n    for(auto&&[x,y,v] : ps){\r\n      if(xs[cur] != x) ++cur;\r\n\
    \      ys[cur + n].push_back(y);\r\n      sum[cur + n].push_back(v);\r\n    }\r\
    \n\r\n    for(int i = n-1; i > 0; --i){\r\n      for(int l = 0, r = 0; l < int(ys[i*2].size())\
    \ || r < int(ys[i*2+1].size());){\r\n        if(l == int(ys[i*2].size())){\r\n\
    \          while(r < int(ys[i*2+1].size())){\r\n            ys[i].push_back(ys[i*2+1][r]);\r\
    \n            sum[i].push_back(sum[i*2+1][r+1]);\r\n            ++r;\r\n     \
    \     }\r\n          break;\r\n        }\r\n\r\n        if(r == int(ys[i*2+1].size())){\r\
    \n          while(l < int(ys[i*2].size())){\r\n            ys[i].push_back(ys[i*2][l]);\r\
    \n            sum[i].push_back(sum[i*2][l+1]);\r\n            ++l;\r\n       \
    \   }\r\n          break;\r\n        }\r\n\r\n        if(ys[i*2][l] < ys[i*2+1][r]){\r\
    \n          ys[i].push_back(ys[i*2][l]);\r\n          sum[i].push_back(sum[i*2][l+1]);\r\
    \n          ++l;\r\n        }else{\r\n          ys[i].push_back(ys[i*2+1][r]);\r\
    \n          sum[i].push_back(sum[i*2+1][r+1]);\r\n          ++r;\r\n        }\r\
    \n      }\r\n    }\r\n\r\n    for(int i = 1; i < n*2; ++i){\r\n      int m = int(sum[i].size());\r\
    \n      for(int j = 0; j < m-1; ++j) sum[i][j+1] = op(sum[i][j], sum[i][j+1]);\r\
    \n    }\r\n  }\r\n\r\n  void build(const vector<pair<Tx,Ty>> &ps){\r\n    vector<tuple<Tx,Ty,int>>\
    \ psv;\r\n    psv.reserve(ps.size());\r\n    for(auto&&[x,y] : ps) psv.emplace_back(x,\
    \ y, 1);\r\n    build(psv);\r\n  }\r\n\r\n  T query(Tx lx, Tx rx, Ty dy, Ty uy)\
    \ const {\r\n    int l = lower_bound(begin(xs), end(xs), lx) - begin(xs);\r\n\
    \    int r = lower_bound(begin(xs), end(xs), rx) - begin(xs);\r\n    T lres =\
    \ id, rres = id;\r\n    for(l+=n, r+=n; l < r; l>>=1, r>>=1){\r\n      if(l &\
    \ 1){\r\n        int u = lower_bound(begin(ys[l]), end(ys[l]), uy) - begin(ys[l]);\r\
    \n        int d = lower_bound(begin(ys[l]), end(ys[l]), dy) - begin(ys[l]);\r\n\
    \        lres = op(lres, inv(sum[l][u], sum[l][d]));\r\n        ++l;\r\n     \
    \ }\r\n      if(r & 1){\r\n        --r;\r\n        int u = lower_bound(begin(ys[r]),\
    \ end(ys[r]), uy) - begin(ys[r]);\r\n        int d = lower_bound(begin(ys[r]),\
    \ end(ys[r]), dy) - begin(ys[r]);\r\n        rres = op(inv(sum[r][u], sum[r][d]),\
    \ rres);\r\n      }\r\n    }\r\n    return op(lres, rres);\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n\r\ntemplate<typename Tx, typename Ty, typename T = int>\r\
    \nstruct StaticRangeTree{\r\n  using OP = function<T(T, T)>;\r\n  int n;\r\n \
    \ vector<Tx> xs;\r\n  vector<vector<Ty>> ys;\r\n  vector<vector<T>> sum;\r\n \
    \ const OP op, inv;\r\n  const T id;\r\n\r\n  StaticRangeTree(const OP &op = plus{},\
    \ const OP &inv = minus{}, const T &id = 0)\r\n  : n(1), op(op), inv(inv), id(id)\
    \ {}\r\n\r\n  void build(vector<tuple<Tx,Ty,T>> ps){\r\n    int n0 = int(ps.size());\r\
    \n    sort(begin(ps), end(ps));\r\n    xs.resize(n0);\r\n    for(int i = 0; i\
    \ < n0; ++i) xs[i] = get<0>(ps[i]);\r\n    xs.erase(unique(begin(xs), end(xs)),\
    \ end(xs));\r\n    n0 = int(xs.size());\r\n    for(n = 1; n < n0; ) n <<= 1;\r\
    \n    xs.resize(n, numeric_limits<Tx>::max());\r\n    ys.resize(n * 2);\r\n  \
    \  sum.resize(n * 2, vector<T>(1, id));\r\n    int cur = 0;\r\n    for(auto&&[x,y,v]\
    \ : ps){\r\n      if(xs[cur] != x) ++cur;\r\n      ys[cur + n].push_back(y);\r\
    \n      sum[cur + n].push_back(v);\r\n    }\r\n\r\n    for(int i = n-1; i > 0;\
    \ --i){\r\n      for(int l = 0, r = 0; l < int(ys[i*2].size()) || r < int(ys[i*2+1].size());){\r\
    \n        if(l == int(ys[i*2].size())){\r\n          while(r < int(ys[i*2+1].size())){\r\
    \n            ys[i].push_back(ys[i*2+1][r]);\r\n            sum[i].push_back(sum[i*2+1][r+1]);\r\
    \n            ++r;\r\n          }\r\n          break;\r\n        }\r\n\r\n   \
    \     if(r == int(ys[i*2+1].size())){\r\n          while(l < int(ys[i*2].size())){\r\
    \n            ys[i].push_back(ys[i*2][l]);\r\n            sum[i].push_back(sum[i*2][l+1]);\r\
    \n            ++l;\r\n          }\r\n          break;\r\n        }\r\n\r\n   \
    \     if(ys[i*2][l] < ys[i*2+1][r]){\r\n          ys[i].push_back(ys[i*2][l]);\r\
    \n          sum[i].push_back(sum[i*2][l+1]);\r\n          ++l;\r\n        }else{\r\
    \n          ys[i].push_back(ys[i*2+1][r]);\r\n          sum[i].push_back(sum[i*2+1][r+1]);\r\
    \n          ++r;\r\n        }\r\n      }\r\n    }\r\n\r\n    for(int i = 1; i\
    \ < n*2; ++i){\r\n      int m = int(sum[i].size());\r\n      for(int j = 0; j\
    \ < m-1; ++j) sum[i][j+1] = op(sum[i][j], sum[i][j+1]);\r\n    }\r\n  }\r\n\r\n\
    \  void build(const vector<pair<Tx,Ty>> &ps){\r\n    vector<tuple<Tx,Ty,int>>\
    \ psv;\r\n    psv.reserve(ps.size());\r\n    for(auto&&[x,y] : ps) psv.emplace_back(x,\
    \ y, 1);\r\n    build(psv);\r\n  }\r\n\r\n  T query(Tx lx, Tx rx, Ty dy, Ty uy)\
    \ const {\r\n    int l = lower_bound(begin(xs), end(xs), lx) - begin(xs);\r\n\
    \    int r = lower_bound(begin(xs), end(xs), rx) - begin(xs);\r\n    T lres =\
    \ id, rres = id;\r\n    for(l+=n, r+=n; l < r; l>>=1, r>>=1){\r\n      if(l &\
    \ 1){\r\n        int u = lower_bound(begin(ys[l]), end(ys[l]), uy) - begin(ys[l]);\r\
    \n        int d = lower_bound(begin(ys[l]), end(ys[l]), dy) - begin(ys[l]);\r\n\
    \        lres = op(lres, inv(sum[l][u], sum[l][d]));\r\n        ++l;\r\n     \
    \ }\r\n      if(r & 1){\r\n        --r;\r\n        int u = lower_bound(begin(ys[r]),\
    \ end(ys[r]), uy) - begin(ys[r]);\r\n        int d = lower_bound(begin(ys[r]),\
    \ end(ys[r]), dy) - begin(ys[r]);\r\n        rres = op(inv(sum[r][u], sum[r][d]),\
    \ rres);\r\n      }\r\n    }\r\n    return op(lres, rres);\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/rangetree/StaticRangeTree.cpp
  requiredBy:
  - datastructure/rangetree/RangeSetQuery.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/rangetree/StaticRangeTree.cpp
layout: document
redirect_from:
- /library/datastructure/rangetree/StaticRangeTree.cpp
- /library/datastructure/rangetree/StaticRangeTree.cpp.html
title: datastructure/rangetree/StaticRangeTree.cpp
---
