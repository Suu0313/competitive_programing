---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/DequeAggregation.cpp
    title: datastructure/DequeAggregation.cpp
  - icon: ':heavy_check_mark:'
    path: datastructure/algebraic/monoid/MinMonoid.cpp
    title: datastructure/algebraic/monoid/MinMonoid.cpp
  - icon: ':heavy_check_mark:'
    path: other/sort/hilbert_sort.cpp
    title: other/sort/hilbert_sort.cpp
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
  bundledCode: "#line 1 \"test/verify/lc/staticrmq_DequeAggregation.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"datastructure/DequeAggregation.cpp\"\n\r\ntemplate<typename\
    \ Monoid>\r\nstruct DequeAggregation{\r\n  vector<pair<Monoid, Monoid>> st_l,\
    \ st_r;\r\n\r\n  DequeAggregation() = default;\r\n  template<typename Iiter>\r\
    \n  DequeAggregation(Iiter first, Iiter last){\r\n    for(; first != last; ++first)\
    \ push_back(*first);\r\n  }\r\n  template<class Container>\r\n  DequeAggregation(const\
    \ Container &c): DequeAggregation(begin(c), end(c)) {}\r\n\r\n  Monoid prod()\
    \ const { return top(st_l) + top(st_r); }\r\n  void push_back(const Monoid &x){\
    \ st_r.emplace_back(x, top(st_r) + x); }\r\n  void push_front(const Monoid &x){\
    \ st_l.emplace_back(x, x + top(st_l)); }\r\n\r\n  Monoid pop_back(){\r\n    assert(!empty());\r\
    \n    if(!st_r.empty()){\r\n      Monoid val = move(st_r.back().first);\r\n  \
    \    st_r.pop_back();\r\n      return val;\r\n    }\r\n    int sz = int(st_l.size()),\
    \ l = sz >> 1, r = sz - l;\r\n    for(int i = r - 1; i > 0; --i) push_back(move(st_l[i].first));\r\
    \n    Monoid val = move(st_l.front().first);\r\n    st_l.erase(begin(st_l), begin(st_l)\
    \ + r);\r\n    if(l == 0) return val;\r\n    st_l[0].second = st_l[0].first;\r\
    \n    for(int i = 1; i < l; ++i) st_l[i].second = st_l[i].first + st_l[i - 1].second;\r\
    \n    return val;\r\n  }\r\n\r\n  Monoid pop_front(){\r\n    assert(!empty());\r\
    \n    if(!st_l.empty()){\r\n      Monoid val = move(st_l.back().first);\r\n  \
    \    st_l.pop_back();\r\n      return val;\r\n    }\r\n    int sz = int(st_r.size()),\
    \ r = sz >> 1, l = sz - r;\r\n    for(int i = l - 1; i > 0; --i) push_front(move(st_r[i].first));\r\
    \n    Monoid val = move(st_r.front().first);\r\n    st_r.erase(begin(st_r), begin(st_r)\
    \ + l);\r\n    if(r == 0) return val;\r\n    st_r[0].second = st_r[0].first;\r\
    \n    for(int i = 1; i < r; ++i) st_r[i].second = st_r[i - 1].second + st_r[i].first;\r\
    \n    return val;\r\n  }\r\n\r\n  const Monoid &front() const { return st_l.empty()\
    \ ? st_r.front().first : st_l.back().first; }\r\n  const Monoid &back() const\
    \ { return st_r.empty() ? st_l.front().first : st_r.back().first; }\r\n  const\
    \ Monoid &operator[](int k) const {\r\n    if(k < 0) k += size();\r\n    assert(0\
    \ <= k && k < int(size()));\r\n    k -= st_l.size();\r\n    return (k < 0) ? st_l[~k].first\
    \ : st_r[k].first;\r\n  }\r\n  size_t size() const { return st_l.size() + st_r.size();\
    \ }\r\n  void clear(){ st_l.clear(); st_r.clear(); }\r\n  bool empty() const {\
    \ return st_l.empty() && st_r.empty(); }\r\n  operator bool() const { return !empty();\
    \ }\r\n\r\n  Monoid top(const vector<pair<Monoid, Monoid>> &v) const { return\
    \ v.empty() ? Monoid{} : v.back().second; }\r\n};\r\n#line 7 \"test/verify/lc/staticrmq_DequeAggregation.test.cpp\"\
    \n\n#line 2 \"datastructure/algebraic/monoid/MinMonoid.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct MinMonoid{\r\n  T x = numeric_limits<T>::max();\r\n  MinMonoid()\
    \ = default;\r\n  MinMonoid(const MinMonoid&) = default;\r\n  MinMonoid(MinMonoid&&)\
    \ = default;\r\n\r\n  MinMonoid(const T &x): x(x) {}\r\n\r\n  MinMonoid &operator=(const\
    \ MinMonoid&) = default;\r\n  MinMonoid &operator=(MinMonoid&&) = default;\r\n\
    \r\n  MinMonoid &operator+=(const MinMonoid &m){\r\n    x = min(x, m.x);\r\n \
    \   return (*this);\r\n  }\r\n  MinMonoid operator+(const MinMonoid &m) const\
    \ {\r\n    return MinMonoid(*this) += m;\r\n  }\r\n};\r\n#line 9 \"test/verify/lc/staticrmq_DequeAggregation.test.cpp\"\
    \n\n#line 2 \"other/sort/hilbert_sort.cpp\"\n\r\ntemplate<int pw>\r\nconstexpr\
    \ uint64_t hilbert_length(int x, int y, int rot = 0){\r\n  if constexpr (pw ==\
    \ 0) return 0;\r\n  else{\r\n    int mid = 1 << (pw - 1);\r\n    int seg = (x\
    \ < mid) ? ((y < mid) ? 0 : 3) : ((y < mid) ? 1 : 2);\r\n    seg = (seg + rot)\
    \ & 3;\r\n    constexpr int rotd[4] = {3, 0, 0, 1};\r\n    int nx = x & (x ^ mid),\
    \ ny = y & (y ^ mid);\r\n    int nrot = (rot + rotd[seg]) & 3;\r\n    uint64_t\
    \ sqsz = uint64_t(1) << (pw*2 - 2);\r\n    uint64_t ans = seg * sqsz, rec = hilbert_length<pw\
    \ - 1>(nx, ny, nrot);\r\n\r\n    return ans + ((seg == 1 || seg == 2) ? rec :\
    \ (sqsz - rec - 1));\r\n  }\r\n}\r\n\r\nvector<int> hilbert_sort(const vector<int>\
    \ &l, const vector<int> &r){\r\n  int n = int(l.size());\r\n  vector<uint64_t>\
    \ len(n);\r\n  for(int i = 0; i < n; ++i) len[i] = hilbert_length<30>(l[i], r[i]);\r\
    \n  vector<int> idx(n); iota(begin(idx), end(idx), 0);\r\n  sort(begin(idx), end(idx),\
    \ [&](int i, int j){ return len[i] < len[j]; });\r\n  return idx;\r\n}\r\n#line\
    \ 11 \"test/verify/lc/staticrmq_DequeAggregation.test.cpp\"\n\nint main(){\n \
    \ int n, q; cin >> n >> q;\n  vector<int> a(n); for(auto&&e : a) cin >> e;\n \
    \ vector<int> l(q), r(q);\n  for(int i = 0; i < q; ++i) cin >> l[i] >> r[i];\n\
    \  DequeAggregation<MinMonoid<int>> dq;\n  int nl = 0, nr = 0;\n  vector<int>\
    \ ans(q);\n\n  for(int i : hilbert_sort(l, r)){\n    while(nr < r[i]){\n     \
    \ // add nr\n      dq.push_back(a[nr]);\n      ++nr;\n    }\n  \n    while(l[i]\
    \ < nl){\n      --nl;\n      // add nl\n      dq.push_front(a[nl]);\n    }\n \
    \ \n    while(r[i] < nr){\n      --nr;\n      // rm nr\n      dq.pop_back();\n\
    \    }\n  \n    while(nl < l[i]){\n      // rm nl\n      dq.pop_front();\n   \
    \   ++nl;\n    }\n    ans[i] = dq.prod().x;\n  }\n\n  for(auto&&e : ans) cout\
    \ << e << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"datastructure/DequeAggregation.cpp\"\
    \n\n#include \"datastructure/algebraic/monoid/MinMonoid.cpp\"\n\n#include \"other/sort/hilbert_sort.cpp\"\
    \n\nint main(){\n  int n, q; cin >> n >> q;\n  vector<int> a(n); for(auto&&e :\
    \ a) cin >> e;\n  vector<int> l(q), r(q);\n  for(int i = 0; i < q; ++i) cin >>\
    \ l[i] >> r[i];\n  DequeAggregation<MinMonoid<int>> dq;\n  int nl = 0, nr = 0;\n\
    \  vector<int> ans(q);\n\n  for(int i : hilbert_sort(l, r)){\n    while(nr < r[i]){\n\
    \      // add nr\n      dq.push_back(a[nr]);\n      ++nr;\n    }\n  \n    while(l[i]\
    \ < nl){\n      --nl;\n      // add nl\n      dq.push_front(a[nl]);\n    }\n \
    \ \n    while(r[i] < nr){\n      --nr;\n      // rm nr\n      dq.pop_back();\n\
    \    }\n  \n    while(nl < l[i]){\n      // rm nl\n      dq.pop_front();\n   \
    \   ++nl;\n    }\n    ans[i] = dq.prod().x;\n  }\n\n  for(auto&&e : ans) cout\
    \ << e << \"\\n\";\n}\n"
  dependsOn:
  - datastructure/DequeAggregation.cpp
  - datastructure/algebraic/monoid/MinMonoid.cpp
  - other/sort/hilbert_sort.cpp
  isVerificationFile: true
  path: test/verify/lc/staticrmq_DequeAggregation.test.cpp
  requiredBy: []
  timestamp: '2023-08-01 22:12:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/lc/staticrmq_DequeAggregation.test.cpp
layout: document
redirect_from:
- /verify/test/verify/lc/staticrmq_DequeAggregation.test.cpp
- /verify/test/verify/lc/staticrmq_DequeAggregation.test.cpp.html
title: test/verify/lc/staticrmq_DequeAggregation.test.cpp
---
