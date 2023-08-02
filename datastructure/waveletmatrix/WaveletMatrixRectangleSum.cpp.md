---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/waveletmatrix/BitVector.cpp
    title: datastructure/waveletmatrix/BitVector.cpp
  - icon: ':heavy_check_mark:'
    path: datastructure/waveletmatrix/WaveletMatrix.cpp
    title: datastructure/waveletmatrix/WaveletMatrix.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/waveletmatrix/WaveletMatrixRectangleSum.cpp\"\
    \n\r\n#line 2 \"datastructure/waveletmatrix/WaveletMatrix.cpp\"\n\r\n#line 2 \"\
    datastructure/waveletmatrix/BitVector.cpp\"\n\r\n\r\nstruct BitVector{\r\n  using\
    \ u16 = uint16_t;\r\n  using u32 = uint32_t;\r\n\r\n  static constexpr int s_ws\
    \ = 16;\r\n  static constexpr int l_ws = 512;\r\n\r\n  vector<u16> b_vector;\r\
    \n  vector<u32> l_block;\r\n  vector<u16> s_block;\r\n  u32 cnt_one = 0;\r\n\r\
    \n  static int popCount(u32 x){ return __builtin_popcountll(x); }\r\n  static\
    \ u32 bitMask(int n){ return (u32(1) << n) - 1; }\r\n\r\n  BitVector() = default;\r\
    \n  BitVector(const BitVector&) = default;\r\n  BitVector(BitVector&&) = default;\r\
    \n  BitVector(const vector<bool> &bit){ init(bit); }\r\n\r\n  BitVector &operator=(const\
    \ BitVector&) = default;\r\n  BitVector &operator=(BitVector&&) = default;\r\n\
    \r\n  void init(const vector<bool> &bit){\r\n    const int n = int(bit.size());\r\
    \n    b_vector.assign(n / s_ws + 1, 0);\r\n\r\n    for(int i = 0; i < n; ++i){\r\
    \n      if(!bit[i]) continue;\r\n      b_vector[i / s_ws] |= 1 << (i % s_ws);\r\
    \n    }\r\n\r\n    l_block.assign(n / l_ws + 1, 0);\r\n    s_block.assign(n /\
    \ s_ws + 1, 0);\r\n\r\n    for(int i = 0; i <= n; ++i){\r\n      if(i % l_ws ==\
    \ 0) l_block[i / l_ws] = cnt_one;\r\n      if(i % s_ws == 0) s_block[i / s_ws]\
    \ = cnt_one - l_block[i / l_ws];\r\n\r\n      if(i != n && i % s_ws == 0) cnt_one\
    \ += popCount(b_vector[i / s_ws]);\r\n    }\r\n  }\r\n\r\n  bool access(int t)\
    \ const { return (b_vector[t / s_ws] >> (t % s_ws) & 1); }\r\n  int rank0(int\
    \ t) const { return t - rank1(t); }\r\n  int rank1(int t) const {\r\n    return\
    \ l_block[t / l_ws] + s_block[t / s_ws]\r\n    + popCount(b_vector[t / s_ws] &\
    \ bitMask(t % s_ws));\r\n  }\r\n\r\n  int rank0(int s, int t) const { return (t\
    \ - s) - rank1(s, t); }\r\n  int rank1(int s, int t) const { return (s == t) \
    \ ? 0 : rank1(t) - rank1(s); }\r\n\r\n  int select0(int t) const;\r\n  int select1(int\
    \ t) const;\r\n};\r\n#line 4 \"datastructure/waveletmatrix/WaveletMatrix.cpp\"\
    \n\r\ntemplate<size_t bn, typename T>\r\nstruct WaveletMatrix{\r\n  array<BitVector,\
    \ bn> bitvectors = {};\r\n  array<size_t, bn> boundary = {};\r\n  vector<T> a;\r\
    \n  \r\n  WaveletMatrix() = default;\r\n  WaveletMatrix(const vector<T> &a): a(a)\
    \ { init(a); }\r\n\r\n  void init(vector<T> whole){\r\n    size_t n = whole.size();\r\
    \n    for(size_t i = bn; i--; ){\r\n      vector<T> zero, one;\r\n      vector<bool>\
    \ bv(n);\r\n      for(size_t j = 0; j < n; ++j){\r\n        ((whole[j] >> i &\
    \ 1) ? one : zero).push_back(whole[j]);\r\n        bv[j] = (whole[j] >> i & 1);\r\
    \n      }\r\n\r\n      boundary[bn - i - 1] = zero.size();\r\n      bitvectors[bn\
    \ - i - 1].init(bv);\r\n\r\n      if(i == 0) break;\r\n      swap(whole, zero);\r\
    \n      whole.insert(end(whole), begin(one), end(one));\r\n    }\r\n  }\r\n\r\n\
    \  const T &operator[](int t) const { return a[t]; }\r\n\r\n  // count x in a[s,\
    \ t)\r\n  int rank(const T &x, int s, int t) const {\r\n    return rank_leg(x,\
    \ s, t)[1];\r\n  }\r\n\r\n  int rank(const T &l, const T &r, int s, int t) const\
    \ {\r\n    return rank_leg(r, s, t)[0] - rank_leg(l, s, t)[0];\r\n  }\r\n\r\n\
    \  array<int, 3> rank_leg(const T &x, int s, int t) const {\r\n    if(s >= t)\
    \ return {0, 0, 0};\r\n    int lt = 0, gt = 0;\r\n\r\n    for(size_t i = bn; i--;\
    \ ){\r\n      size_t j = bn - i - 1;\r\n      int len = t - s;\r\n      if(x >>\
    \ i & 1){\r\n        s = boundary[j] + bitvectors[j].rank1(s);\r\n        t =\
    \ boundary[j] + bitvectors[j].rank1(t);\r\n      }else{\r\n        s = bitvectors[j].rank0(s);\r\
    \n        t = bitvectors[j].rank0(t);\r\n      }\r\n      ((x >> i & 1) ? lt :\
    \ gt) += len - (t - s);\r\n    }\r\n    return {lt, t - s, gt};\r\n  }\r\n\r\n\
    \  // pos of kth x\r\n  int select(const T &x, int k) const;\r\n\r\n  T kth_smallest(int\
    \ s, int t, int k) const {\r\n    T ret = 0;\r\n    for(size_t i = bn; i--; ){\r\
    \n      size_t j = bn - i - 1;\r\n      int z = bitvectors[j].rank0(s, t);\r\n\
    \r\n      if(k < z){\r\n        s = bitvectors[j].rank0(s);\r\n        t = bitvectors[j].rank0(t);\r\
    \n      }else{\r\n        ret |= T(1) << i;\r\n        s = boundary[j] + bitvectors[j].rank1(s);\r\
    \n        t = boundary[j] + bitvectors[j].rank1(t);\r\n        k -= z;\r\n   \
    \   }\r\n    }\r\n    return ret;\r\n  }\r\n\r\n  T kth_largest(int s, int t,\
    \ int k) const {\r\n    return kth_smallest(s, t, (t - s) - k - 1);\r\n  }\r\n\
    \r\n  vector<pair<T, int>> top_k(int s, int t, int k) const {\r\n    vector<pair<T,\
    \ int>> res; res.reserve(k);\r\n    using ti4t = tuple<int, int, int, size_t,\
    \ T>; // width, left, right, depth, value;\r\n    auto cmp = [](const ti4t &l,\
    \ const ti4t &r) -> bool {\r\n      if(get<0>(l) != get<0>(r)) return get<0>(l)\
    \ < get<0>(r);\r\n      if(get<3>(l) != get<3>(r)) return get<3>(l) > get<3>(r);\r\
    \n      if(get<4>(l) != get<4>(r)) return get<4>(l) > get<4>(r);\r\n      return\
    \ true;\r\n    };\r\n    priority_queue<ti4t, vector<ti4t>, decltype(cmp)> pq{cmp};\r\
    \n    pq.emplace(t - s, s, t, 0, 0);\r\n\r\n    while(!pq.empty()){\r\n      auto[width,\
    \ left, right, depth, value] = pq.top(); pq.pop();\r\n      if(depth >= bn){\r\
    \n        res.emplace_back(value, width);\r\n        if(int(res.size()) >= k)\
    \ break;\r\n        continue;\r\n      }\r\n\r\n      int nl = bitvectors[depth].rank0(left);\r\
    \n      int nr = bitvectors[depth].rank0(right);\r\n      if(nl != nr) pq.emplace(nr\
    \ - nl, nl, nr, depth+1, value);\r\n\r\n      nl = bitvectors[depth].rank1(left);\r\
    \n      nr = bitvectors[depth].rank1(right);\r\n      if(nl != nr) pq.emplace(nr\
    \ - nl, nl, nr, depth+1, value | (T(1) << (bn - depth - 1)));\r\n    }\r\n   \
    \ return res;\r\n  }\r\n\r\n  vector<pair<T, int>> intersect(int s1, int t1, int\
    \ s2, int t2) const;\r\n\r\n  // min x s.t. l <= x < r in a[s, t)\r\n  T get_min(const\
    \ T &l, const T &r, int s, int t) const {\r\n    using t5_t = tuple<int, int,\
    \ size_t, T, int>; // left, right, depth, value, tight;\r\n    stack<t5_t> st;\
    \ st.emplace(s, t, 0, 0, 1);\r\n\r\n    while(!st.empty()){\r\n      auto[left,\
    \ right, depth, value, tight] = st.top(); st.pop();\r\n      if(depth == bn){\r\
    \n        if(value < r) return value;\r\n        continue;\r\n      }\r\n    \
    \  \r\n      int nl = boundary[depth] + bitvectors[depth].rank1(left);\r\n   \
    \   int nr = boundary[depth] + bitvectors[depth].rank1(right);\r\n      int bit\
    \ = (l >> (bn - depth - 1)) & 1;\r\n\r\n      if(nl != nr) st.emplace(nl, nr,\
    \ depth+1, (value << 1) | 1, tight & bit);\r\n\r\n      nl = bitvectors[depth].rank0(left);\r\
    \n      nr = bitvectors[depth].rank0(right);\r\n      if(nl != nr && (!(tight\
    \ && bit))) st.emplace(nl, nr, depth+1, value << 1, tight);\r\n    }\r\n\r\n \
    \   return -1;\r\n  }\r\n\r\n  // max x s.t. l <= x < r in a[s, t)\r\n  T get_max(const\
    \ T &l, const T &r, int s, int t) const {\r\n    using t5_t = tuple<int, int,\
    \ size_t, T, int>; // left, right, depth, value, tight;\r\n    stack<t5_t> st;\
    \ st.emplace(s, t, 0, 0, 1);\r\n\r\n    while(!st.empty()){\r\n      auto[left,\
    \ right, depth, value, tight] = st.top(); st.pop();\r\n      if(depth == bn) return\
    \ value;\r\n\r\n      int nl = bitvectors[depth].rank0(left);\r\n      int nr\
    \ = bitvectors[depth].rank0(right);\r\n      int bit = (l >> (bn - depth - 1))\
    \ & 1;\r\n      T nval = T(1) << (bn - depth - 1);\r\n      if(nl != nr && (!(tight\
    \ && bit))) st.emplace(nl, nr, depth+1, value, tight);\r\n      \r\n      nl =\
    \ boundary[depth] + bitvectors[depth].rank1(left);\r\n      nr = boundary[depth]\
    \ + bitvectors[depth].rank1(right);\r\n      if(nl != nr && ((value | nval) <\
    \ r)) st.emplace(nl, nr, depth+1, value | nval, tight & bit); \r\n    }\r\n\r\n\
    \    return -1;\r\n  }\r\n\r\n  // (x, c) s.t. l <= x < r, c = #{i | ai = x}\r\
    \n  vector<pair<T, int>> enumerate(const T &l, const T &r, int s, int t) const;\r\
    \n};\r\n#line 4 \"datastructure/waveletmatrix/WaveletMatrixRectangleSum.cpp\"\n\
    \r\ntemplate<size_t bn, typename T, typename V>\r\nstruct WaveletMatrixRectangleSum\
    \ : WaveletMatrix<bn, T> {\r\n  vector<V> vs[bn];\r\n  using WaveletMatrix<bn,\
    \ T>::bitvectors;\r\n  using WaveletMatrix<bn, T>::boundary;\r\n  WaveletMatrixRectangleSum()\
    \ = default;\r\n  WaveletMatrixRectangleSum(const vector<T> &a, const vector<V>\
    \ &v): WaveletMatrix<bn, T>(a) { init(a, v); }\r\n\r\n  void init(const vector<T>\
    \ &a, const vector<V> &v){\r\n    size_t n = a.size();\r\n    vector<int> ord(n);\
    \ iota(begin(ord), end(ord), 0);\r\n    for(size_t i = bn; i--; ){\r\n      vector<int>\
    \ zero, one;\r\n      for(size_t j = 0; j < n; ++j) (bitvectors[bn-i-1].access(j)\
    \ ? one : zero).push_back(ord[j]);\r\n      swap(ord, zero);\r\n      ord.insert(end(ord),\
    \ begin(one), end(one));\r\n      size_t j = bn - i - 1;\r\n      vs[j].assign(n\
    \ + 1, V{});\r\n      for(size_t k = 0; k < n; ++k) vs[j][k+1] = vs[j][k] + v[ord[k]];\r\
    \n    }\r\n  }\r\n\r\n  // sum v[i] | s <= i < t, a[i] < x\r\n  V sum(const T\
    \ &x, int s, int t) const {\r\n    V res{};\r\n    for(size_t i = bn; i--; ){\r\
    \n      size_t j = bn - i - 1;\r\n      if(x >> i & 1){\r\n        res += vs[j][bitvectors[j].rank0(t)]\
    \ - vs[j][bitvectors[j].rank0(s)];\r\n        s = boundary[j] + bitvectors[j].rank1(s);\r\
    \n        t = boundary[j] + bitvectors[j].rank1(t);\r\n      }else{\r\n      \
    \  s = bitvectors[j].rank0(s);\r\n        t = bitvectors[j].rank0(t);\r\n    \
    \  }\r\n    }\r\n    return res;\r\n  }\r\n\r\n  V sum(const T &l, const T &r,\
    \ int s, int t) const {\r\n    return sum(r, s, t) - sum(l, s, t);\r\n  }\r\n\
    };\r\n"
  code: "#pragma once\r\n\r\n#include \"./WaveletMatrix.cpp\"\r\n\r\ntemplate<size_t\
    \ bn, typename T, typename V>\r\nstruct WaveletMatrixRectangleSum : WaveletMatrix<bn,\
    \ T> {\r\n  vector<V> vs[bn];\r\n  using WaveletMatrix<bn, T>::bitvectors;\r\n\
    \  using WaveletMatrix<bn, T>::boundary;\r\n  WaveletMatrixRectangleSum() = default;\r\
    \n  WaveletMatrixRectangleSum(const vector<T> &a, const vector<V> &v): WaveletMatrix<bn,\
    \ T>(a) { init(a, v); }\r\n\r\n  void init(const vector<T> &a, const vector<V>\
    \ &v){\r\n    size_t n = a.size();\r\n    vector<int> ord(n); iota(begin(ord),\
    \ end(ord), 0);\r\n    for(size_t i = bn; i--; ){\r\n      vector<int> zero, one;\r\
    \n      for(size_t j = 0; j < n; ++j) (bitvectors[bn-i-1].access(j) ? one : zero).push_back(ord[j]);\r\
    \n      swap(ord, zero);\r\n      ord.insert(end(ord), begin(one), end(one));\r\
    \n      size_t j = bn - i - 1;\r\n      vs[j].assign(n + 1, V{});\r\n      for(size_t\
    \ k = 0; k < n; ++k) vs[j][k+1] = vs[j][k] + v[ord[k]];\r\n    }\r\n  }\r\n\r\n\
    \  // sum v[i] | s <= i < t, a[i] < x\r\n  V sum(const T &x, int s, int t) const\
    \ {\r\n    V res{};\r\n    for(size_t i = bn; i--; ){\r\n      size_t j = bn -\
    \ i - 1;\r\n      if(x >> i & 1){\r\n        res += vs[j][bitvectors[j].rank0(t)]\
    \ - vs[j][bitvectors[j].rank0(s)];\r\n        s = boundary[j] + bitvectors[j].rank1(s);\r\
    \n        t = boundary[j] + bitvectors[j].rank1(t);\r\n      }else{\r\n      \
    \  s = bitvectors[j].rank0(s);\r\n        t = bitvectors[j].rank0(t);\r\n    \
    \  }\r\n    }\r\n    return res;\r\n  }\r\n\r\n  V sum(const T &l, const T &r,\
    \ int s, int t) const {\r\n    return sum(r, s, t) - sum(l, s, t);\r\n  }\r\n\
    };\r\n"
  dependsOn:
  - datastructure/waveletmatrix/WaveletMatrix.cpp
  - datastructure/waveletmatrix/BitVector.cpp
  isVerificationFile: false
  path: datastructure/waveletmatrix/WaveletMatrixRectangleSum.cpp
  requiredBy: []
  timestamp: '2023-07-22 06:20:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/waveletmatrix/WaveletMatrixRectangleSum.cpp
layout: document
redirect_from:
- /library/datastructure/waveletmatrix/WaveletMatrixRectangleSum.cpp
- /library/datastructure/waveletmatrix/WaveletMatrixRectangleSum.cpp.html
title: datastructure/waveletmatrix/WaveletMatrixRectangleSum.cpp
---
