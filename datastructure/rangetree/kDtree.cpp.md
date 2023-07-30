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
  bundledCode: "#line 2 \"datastructure/rangetree/kDtree.cpp\"\n\r\ntemplate<typename\
    \ T, int D>\r\nstruct kDTree{\r\n  struct Node{\r\n    int idx, l, r, axis;\r\n\
    \    T mn, mx;\r\n    Node(): idx(-1), l(-1), r(-1), axis(0), mn(0), mx(0) {}\r\
    \n  };\r\n\r\n  vector<array<T, D>> ps;\r\n  vector<int> idx;\r\n  vector<Node>\
    \ ts;\r\n  int root;\r\n\r\n  kDTree() {}\r\n  kDTree(int n) { ps.reserve(n);\
    \ }\r\n\r\n  void push(const array<T, D> &p){ ps.push_back(p); }\r\n\r\n  void\
    \ build(){\r\n    int n = int(ps.size());\r\n    idx.resize(n); iota(begin(idx),\
    \ end(idx), 0);\r\n    ts.resize(n);\r\n    int pos = 0;\r\n    root = build(0,\
    \ n, pos);\r\n  }\r\n\r\n  int build(int l, int r, int &pos){\r\n    if(l >= r)\
    \ return -1;\r\n    int m = (l + r) >> 1;\r\n    int cur = pos++;\r\n    {\r\n\
    \      auto[mn,mx] = minmax_element(begin(idx)+l, begin(idx)+r,\r\n        [&](int\
    \ i, int j){ return ps[i][0] < ps[j][0]; });\r\n      ts[cur].mn = ps[*mn][0];\r\
    \n      ts[cur].mx = ps[*mx][0];\r\n    }\r\n    for(int k = 1; k < D; ++k){\r\
    \n      auto[mn,mx] = minmax_element(begin(idx)+l, begin(idx)+r,\r\n        [&](int\
    \ i, int j){ return ps[i][k] < ps[j][k]; });\r\n      if(ps[*mx][k]-ps[*mn][k]\
    \ > ts[cur].mx-ts[cur].mn){\r\n        ts[cur].axis = k;\r\n        ts[cur].mn\
    \ = ps[*mn][k]; ts[cur].mx = ps[*mx][k];\r\n      }\r\n    }\r\n    nth_element(begin(idx)+l,\
    \ begin(idx)+m, begin(idx)+r,\r\n      [&](int i, int j){ return ps[i][ts[cur].axis]\
    \ < ps[j][ts[cur].axis]; });\r\n    \r\n    ts[cur].idx = idx[m];\r\n    ts[cur].l\
    \ = build(l, m, pos);\r\n    ts[cur].r = build(m+1, r, pos);\r\n    return cur;\r\
    \n  }\r\n\r\n  vector<int> find(const array<T, D> &l, const array<T, D> &r) const\
    \ {\r\n    vector<int> res;\r\n    find(root, l, r, res);\r\n    return res;\r\
    \n  }\r\n\r\n  void find(int t, const array<T, D> &l, const array<T, D> &r, vector<int>\
    \ &res) const {\r\n    if(t == -1 || ts[t].idx == -1) return;\r\n    auto p =\
    \ ps[ts[t].idx];\r\n\r\n    bool fl = true;\r\n    for(int k = 0; k < D; ++k){\r\
    \n      if(p[k] < l[k] || r[k] <= p[k]){ fl = false; break; }\r\n    }\r\n   \
    \ if(fl) res.push_back(ts[t].idx);\r\n    int k = ts[t].axis;\r\n    if(ts[t].l\
    \ != -1 && l[k] <= p[k]) find(ts[t].l, l, r, res);\r\n    if(ts[t].r != -1 &&\
    \ p[k] < r[k]) find(ts[t].r, l, r, res);\r\n  }\r\n\r\n  int nnSearch(const array<T,\
    \ D> &q) const {\r\n    int res = -1;\r\n    T m_norm = numeric_limits<T>::max();\r\
    \n    nnSearch(root, q, res, m_norm);\r\n    return res;\r\n  }\r\n\r\n  void\
    \ nnSearch(int t, const array<T, D> &q, int &guess,T &m_norm) const {\r\n    if(t\
    \ == -1 || ts[t].idx == -1) return;\r\n    auto p = ps[ts[t].idx];\r\n    T norm\
    \ = Norm(p, q);\r\n    if(norm < m_norm){ guess = ts[t].idx; m_norm = norm; }\r\
    \n    int k = ts[t].axis;\r\n    if(m_norm < Norm(q[k], clamp(q[k], ts[t].mn,\
    \ ts[t].mx))) return;\r\n\r\n    bool dir = q[k] < p[k];\r\n    nnSearch((dir?\
    \ ts[t].l : ts[t].r), q, guess, m_norm);\r\n    \r\n    T diff = (p[k] - q[k])*(p[k]\
    \ - q[k]);\r\n    if(diff < m_norm) nnSearch((dir? ts[t].r : ts[t].l), q, guess,\
    \ m_norm);\r\n  }\r\n\r\n  using PPQ = priority_queue<pair<T, int>>;\r\n\r\n \
    \ vector<int> knnSearch(const array<T, D> &q, int k) const {\r\n    if(k == 0)\
    \ return {};\r\n    if(k == 1) return { nnSearch(q) };\r\n    PPQ pq;\r\n    knnSearch(root,\
    \ q, pq, k);\r\n    vector<int> res(pq.size());\r\n    for(int i = int(pq.size())-1;\
    \ i >= 0; --i){\r\n      res[i] = pq.top().second; pq.pop();\r\n    }\r\n    return\
    \ res;\r\n  }\r\n\r\n  void knnSearch(int t, const array<T, D> &q, PPQ &pq, int\
    \ k) const {\r\n    if(t == -1 || ts[t].idx == -1) return;\r\n    auto p = ps[ts[t].idx];\r\
    \n    T norm = Norm(p, q);\r\n    pq.emplace(norm, ts[t].idx);\r\n    if(int(pq.size())\
    \ > k) pq.pop();\r\n\r\n    int axis = ts[t].axis;\r\n    if(int(pq.size()) ==\
    \ k && pq.top().first < Norm(q[axis], clamp(q[axis], ts[t].mn, ts[t].mx))) return;\r\
    \n    bool dir = q[axis] < p[axis];\r\n    knnSearch((dir? ts[t].l : ts[t].r),\
    \ q, pq, k);\r\n    \r\n    T diff = (p[axis] - q[axis])*(p[axis] - q[axis]);\r\
    \n    if(int(pq.size()) < k || diff < pq.top().first)\r\n      knnSearch((dir?\
    \ ts[t].r : ts[t].l), q, pq, k);\r\n  }\r\n\r\n  vector<int> radiusSearch(const\
    \ array<T, D> &q, const T &norm) const {\r\n    vector<int> res;\r\n    radiusSearch(root,\
    \ q, norm, res);\r\n    return res;\r\n  }\r\n\r\n  void radiusSearch(int t, const\
    \ array<T, D> &q, const T &norm, vector<int> &res) const {\r\n    if(t == -1 ||\
    \ ts[t].idx == -1) return;\r\n    auto p = ps[ts[t].idx];\r\n    if(!(norm < Norm(p,\
    \ q))) res.push_back(ts[t].idx);\r\n    int k = ts[t].axis;\r\n    if(norm < Norm(q[k],\
    \ clamp(q[k], ts[t].mn, ts[t].mx))) return;\r\n    bool dir = q[k] < p[k];\r\n\
    \    radiusSearch((dir? ts[t].l : ts[t].r), q, norm, res);\r\n    \r\n    T diff\
    \ = (p[k] - q[k])*(p[k] - q[k]);\r\n    if(!(norm < diff)) radiusSearch((dir?\
    \ ts[t].r : ts[t].l), q, norm, res);\r\n  }\r\n\r\n  static T Norm(const array<T,\
    \ D> &p, const array<T, D> &q){\r\n    T norm = 0;\r\n    for(int k = 0; k < D;\
    \ ++k) norm += (p[k]-q[k]) * (p[k]-q[k]);\r\n    return norm;\r\n  }\r\n\r\n \
    \ static T Norm(const T &a, const T &b){\r\n    return (a-b) * (a-b);\r\n  }\r\
    \n};\r\n\r\ntemplate<typename T>\r\nstruct twoDTree : kDTree<T, 2> {\r\n  using\
    \ kDTree<T, 2>::kDTree;\r\n  void push(const T &x, const T &y){ kDTree<T, 2>::push(\
    \ array<T,2>{x, y} ); }\r\n  vector<int> find(const T &l, const T &r, const T\
    \ &d, const T &u) const {\r\n    return kDTree<T, 2>::find(array<T,2>{l, d}, array<T,2>{r,\
    \ u});\r\n  }\r\n  int nnSearch(const T &x, const T &y) const {\r\n    return\
    \ kDTree<T, 2>::nnSearch( array<T,2>{x, y} );\r\n  }\r\n  vector<int> knnSearch(const\
    \ T &x, const T &y, int k) const {\r\n    return kDTree<T, 2>::knnSearch( array<T,2>{x,\
    \ y}, k);\r\n  }\r\n  vector<int> radiusSearch(const T &x, const T &y, const T\
    \ &norm) const {\r\n    return kDTree<T, 2>::radiusSearch( array<T,2>{x, y}, norm);\r\
    \n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T, int D>\r\nstruct kDTree{\r\n  struct\
    \ Node{\r\n    int idx, l, r, axis;\r\n    T mn, mx;\r\n    Node(): idx(-1), l(-1),\
    \ r(-1), axis(0), mn(0), mx(0) {}\r\n  };\r\n\r\n  vector<array<T, D>> ps;\r\n\
    \  vector<int> idx;\r\n  vector<Node> ts;\r\n  int root;\r\n\r\n  kDTree() {}\r\
    \n  kDTree(int n) { ps.reserve(n); }\r\n\r\n  void push(const array<T, D> &p){\
    \ ps.push_back(p); }\r\n\r\n  void build(){\r\n    int n = int(ps.size());\r\n\
    \    idx.resize(n); iota(begin(idx), end(idx), 0);\r\n    ts.resize(n);\r\n  \
    \  int pos = 0;\r\n    root = build(0, n, pos);\r\n  }\r\n\r\n  int build(int\
    \ l, int r, int &pos){\r\n    if(l >= r) return -1;\r\n    int m = (l + r) >>\
    \ 1;\r\n    int cur = pos++;\r\n    {\r\n      auto[mn,mx] = minmax_element(begin(idx)+l,\
    \ begin(idx)+r,\r\n        [&](int i, int j){ return ps[i][0] < ps[j][0]; });\r\
    \n      ts[cur].mn = ps[*mn][0];\r\n      ts[cur].mx = ps[*mx][0];\r\n    }\r\n\
    \    for(int k = 1; k < D; ++k){\r\n      auto[mn,mx] = minmax_element(begin(idx)+l,\
    \ begin(idx)+r,\r\n        [&](int i, int j){ return ps[i][k] < ps[j][k]; });\r\
    \n      if(ps[*mx][k]-ps[*mn][k] > ts[cur].mx-ts[cur].mn){\r\n        ts[cur].axis\
    \ = k;\r\n        ts[cur].mn = ps[*mn][k]; ts[cur].mx = ps[*mx][k];\r\n      }\r\
    \n    }\r\n    nth_element(begin(idx)+l, begin(idx)+m, begin(idx)+r,\r\n     \
    \ [&](int i, int j){ return ps[i][ts[cur].axis] < ps[j][ts[cur].axis]; });\r\n\
    \    \r\n    ts[cur].idx = idx[m];\r\n    ts[cur].l = build(l, m, pos);\r\n  \
    \  ts[cur].r = build(m+1, r, pos);\r\n    return cur;\r\n  }\r\n\r\n  vector<int>\
    \ find(const array<T, D> &l, const array<T, D> &r) const {\r\n    vector<int>\
    \ res;\r\n    find(root, l, r, res);\r\n    return res;\r\n  }\r\n\r\n  void find(int\
    \ t, const array<T, D> &l, const array<T, D> &r, vector<int> &res) const {\r\n\
    \    if(t == -1 || ts[t].idx == -1) return;\r\n    auto p = ps[ts[t].idx];\r\n\
    \r\n    bool fl = true;\r\n    for(int k = 0; k < D; ++k){\r\n      if(p[k] <\
    \ l[k] || r[k] <= p[k]){ fl = false; break; }\r\n    }\r\n    if(fl) res.push_back(ts[t].idx);\r\
    \n    int k = ts[t].axis;\r\n    if(ts[t].l != -1 && l[k] <= p[k]) find(ts[t].l,\
    \ l, r, res);\r\n    if(ts[t].r != -1 && p[k] < r[k]) find(ts[t].r, l, r, res);\r\
    \n  }\r\n\r\n  int nnSearch(const array<T, D> &q) const {\r\n    int res = -1;\r\
    \n    T m_norm = numeric_limits<T>::max();\r\n    nnSearch(root, q, res, m_norm);\r\
    \n    return res;\r\n  }\r\n\r\n  void nnSearch(int t, const array<T, D> &q, int\
    \ &guess,T &m_norm) const {\r\n    if(t == -1 || ts[t].idx == -1) return;\r\n\
    \    auto p = ps[ts[t].idx];\r\n    T norm = Norm(p, q);\r\n    if(norm < m_norm){\
    \ guess = ts[t].idx; m_norm = norm; }\r\n    int k = ts[t].axis;\r\n    if(m_norm\
    \ < Norm(q[k], clamp(q[k], ts[t].mn, ts[t].mx))) return;\r\n\r\n    bool dir =\
    \ q[k] < p[k];\r\n    nnSearch((dir? ts[t].l : ts[t].r), q, guess, m_norm);\r\n\
    \    \r\n    T diff = (p[k] - q[k])*(p[k] - q[k]);\r\n    if(diff < m_norm) nnSearch((dir?\
    \ ts[t].r : ts[t].l), q, guess, m_norm);\r\n  }\r\n\r\n  using PPQ = priority_queue<pair<T,\
    \ int>>;\r\n\r\n  vector<int> knnSearch(const array<T, D> &q, int k) const {\r\
    \n    if(k == 0) return {};\r\n    if(k == 1) return { nnSearch(q) };\r\n    PPQ\
    \ pq;\r\n    knnSearch(root, q, pq, k);\r\n    vector<int> res(pq.size());\r\n\
    \    for(int i = int(pq.size())-1; i >= 0; --i){\r\n      res[i] = pq.top().second;\
    \ pq.pop();\r\n    }\r\n    return res;\r\n  }\r\n\r\n  void knnSearch(int t,\
    \ const array<T, D> &q, PPQ &pq, int k) const {\r\n    if(t == -1 || ts[t].idx\
    \ == -1) return;\r\n    auto p = ps[ts[t].idx];\r\n    T norm = Norm(p, q);\r\n\
    \    pq.emplace(norm, ts[t].idx);\r\n    if(int(pq.size()) > k) pq.pop();\r\n\r\
    \n    int axis = ts[t].axis;\r\n    if(int(pq.size()) == k && pq.top().first <\
    \ Norm(q[axis], clamp(q[axis], ts[t].mn, ts[t].mx))) return;\r\n    bool dir =\
    \ q[axis] < p[axis];\r\n    knnSearch((dir? ts[t].l : ts[t].r), q, pq, k);\r\n\
    \    \r\n    T diff = (p[axis] - q[axis])*(p[axis] - q[axis]);\r\n    if(int(pq.size())\
    \ < k || diff < pq.top().first)\r\n      knnSearch((dir? ts[t].r : ts[t].l), q,\
    \ pq, k);\r\n  }\r\n\r\n  vector<int> radiusSearch(const array<T, D> &q, const\
    \ T &norm) const {\r\n    vector<int> res;\r\n    radiusSearch(root, q, norm,\
    \ res);\r\n    return res;\r\n  }\r\n\r\n  void radiusSearch(int t, const array<T,\
    \ D> &q, const T &norm, vector<int> &res) const {\r\n    if(t == -1 || ts[t].idx\
    \ == -1) return;\r\n    auto p = ps[ts[t].idx];\r\n    if(!(norm < Norm(p, q)))\
    \ res.push_back(ts[t].idx);\r\n    int k = ts[t].axis;\r\n    if(norm < Norm(q[k],\
    \ clamp(q[k], ts[t].mn, ts[t].mx))) return;\r\n    bool dir = q[k] < p[k];\r\n\
    \    radiusSearch((dir? ts[t].l : ts[t].r), q, norm, res);\r\n    \r\n    T diff\
    \ = (p[k] - q[k])*(p[k] - q[k]);\r\n    if(!(norm < diff)) radiusSearch((dir?\
    \ ts[t].r : ts[t].l), q, norm, res);\r\n  }\r\n\r\n  static T Norm(const array<T,\
    \ D> &p, const array<T, D> &q){\r\n    T norm = 0;\r\n    for(int k = 0; k < D;\
    \ ++k) norm += (p[k]-q[k]) * (p[k]-q[k]);\r\n    return norm;\r\n  }\r\n\r\n \
    \ static T Norm(const T &a, const T &b){\r\n    return (a-b) * (a-b);\r\n  }\r\
    \n};\r\n\r\ntemplate<typename T>\r\nstruct twoDTree : kDTree<T, 2> {\r\n  using\
    \ kDTree<T, 2>::kDTree;\r\n  void push(const T &x, const T &y){ kDTree<T, 2>::push(\
    \ array<T,2>{x, y} ); }\r\n  vector<int> find(const T &l, const T &r, const T\
    \ &d, const T &u) const {\r\n    return kDTree<T, 2>::find(array<T,2>{l, d}, array<T,2>{r,\
    \ u});\r\n  }\r\n  int nnSearch(const T &x, const T &y) const {\r\n    return\
    \ kDTree<T, 2>::nnSearch( array<T,2>{x, y} );\r\n  }\r\n  vector<int> knnSearch(const\
    \ T &x, const T &y, int k) const {\r\n    return kDTree<T, 2>::knnSearch( array<T,2>{x,\
    \ y}, k);\r\n  }\r\n  vector<int> radiusSearch(const T &x, const T &y, const T\
    \ &norm) const {\r\n    return kDTree<T, 2>::radiusSearch( array<T,2>{x, y}, norm);\r\
    \n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/rangetree/kDtree.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/rangetree/kDtree.cpp
layout: document
redirect_from:
- /library/datastructure/rangetree/kDtree.cpp
- /library/datastructure/rangetree/kDtree.cpp.html
title: datastructure/rangetree/kDtree.cpp
---
