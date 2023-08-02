---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: datastructure/waveletmatrix/WaveletMatrix.cpp
    title: datastructure/waveletmatrix/WaveletMatrix.cpp
  - icon: ':warning:'
    path: datastructure/waveletmatrix/WaveletMatrixPointAddRectangleSum.cpp
    title: datastructure/waveletmatrix/WaveletMatrixPointAddRectangleSum.cpp
  - icon: ':warning:'
    path: datastructure/waveletmatrix/WaveletMatrixRectangleSum.cpp
    title: datastructure/waveletmatrix/WaveletMatrixRectangleSum.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/lc/range_kth_smallest_WaveletMatrix.test.cpp
    title: test/verify/lc/range_kth_smallest_WaveletMatrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/waveletmatrix/BitVector.cpp\"\n\r\n\r\nstruct\
    \ BitVector{\r\n  using u16 = uint16_t;\r\n  using u32 = uint32_t;\r\n\r\n  static\
    \ constexpr int s_ws = 16;\r\n  static constexpr int l_ws = 512;\r\n\r\n  vector<u16>\
    \ b_vector;\r\n  vector<u32> l_block;\r\n  vector<u16> s_block;\r\n  u32 cnt_one\
    \ = 0;\r\n\r\n  static int popCount(u32 x){ return __builtin_popcountll(x); }\r\
    \n  static u32 bitMask(int n){ return (u32(1) << n) - 1; }\r\n\r\n  BitVector()\
    \ = default;\r\n  BitVector(const BitVector&) = default;\r\n  BitVector(BitVector&&)\
    \ = default;\r\n  BitVector(const vector<bool> &bit){ init(bit); }\r\n\r\n  BitVector\
    \ &operator=(const BitVector&) = default;\r\n  BitVector &operator=(BitVector&&)\
    \ = default;\r\n\r\n  void init(const vector<bool> &bit){\r\n    const int n =\
    \ int(bit.size());\r\n    b_vector.assign(n / s_ws + 1, 0);\r\n\r\n    for(int\
    \ i = 0; i < n; ++i){\r\n      if(!bit[i]) continue;\r\n      b_vector[i / s_ws]\
    \ |= 1 << (i % s_ws);\r\n    }\r\n\r\n    l_block.assign(n / l_ws + 1, 0);\r\n\
    \    s_block.assign(n / s_ws + 1, 0);\r\n\r\n    for(int i = 0; i <= n; ++i){\r\
    \n      if(i % l_ws == 0) l_block[i / l_ws] = cnt_one;\r\n      if(i % s_ws ==\
    \ 0) s_block[i / s_ws] = cnt_one - l_block[i / l_ws];\r\n\r\n      if(i != n &&\
    \ i % s_ws == 0) cnt_one += popCount(b_vector[i / s_ws]);\r\n    }\r\n  }\r\n\r\
    \n  bool access(int t) const { return (b_vector[t / s_ws] >> (t % s_ws) & 1);\
    \ }\r\n  int rank0(int t) const { return t - rank1(t); }\r\n  int rank1(int t)\
    \ const {\r\n    return l_block[t / l_ws] + s_block[t / s_ws]\r\n    + popCount(b_vector[t\
    \ / s_ws] & bitMask(t % s_ws));\r\n  }\r\n\r\n  int rank0(int s, int t) const\
    \ { return (t - s) - rank1(s, t); }\r\n  int rank1(int s, int t) const { return\
    \ (s == t)  ? 0 : rank1(t) - rank1(s); }\r\n\r\n  int select0(int t) const;\r\n\
    \  int select1(int t) const;\r\n};\r\n"
  code: "#pragma once\r\n\r\n\r\nstruct BitVector{\r\n  using u16 = uint16_t;\r\n\
    \  using u32 = uint32_t;\r\n\r\n  static constexpr int s_ws = 16;\r\n  static\
    \ constexpr int l_ws = 512;\r\n\r\n  vector<u16> b_vector;\r\n  vector<u32> l_block;\r\
    \n  vector<u16> s_block;\r\n  u32 cnt_one = 0;\r\n\r\n  static int popCount(u32\
    \ x){ return __builtin_popcountll(x); }\r\n  static u32 bitMask(int n){ return\
    \ (u32(1) << n) - 1; }\r\n\r\n  BitVector() = default;\r\n  BitVector(const BitVector&)\
    \ = default;\r\n  BitVector(BitVector&&) = default;\r\n  BitVector(const vector<bool>\
    \ &bit){ init(bit); }\r\n\r\n  BitVector &operator=(const BitVector&) = default;\r\
    \n  BitVector &operator=(BitVector&&) = default;\r\n\r\n  void init(const vector<bool>\
    \ &bit){\r\n    const int n = int(bit.size());\r\n    b_vector.assign(n / s_ws\
    \ + 1, 0);\r\n\r\n    for(int i = 0; i < n; ++i){\r\n      if(!bit[i]) continue;\r\
    \n      b_vector[i / s_ws] |= 1 << (i % s_ws);\r\n    }\r\n\r\n    l_block.assign(n\
    \ / l_ws + 1, 0);\r\n    s_block.assign(n / s_ws + 1, 0);\r\n\r\n    for(int i\
    \ = 0; i <= n; ++i){\r\n      if(i % l_ws == 0) l_block[i / l_ws] = cnt_one;\r\
    \n      if(i % s_ws == 0) s_block[i / s_ws] = cnt_one - l_block[i / l_ws];\r\n\
    \r\n      if(i != n && i % s_ws == 0) cnt_one += popCount(b_vector[i / s_ws]);\r\
    \n    }\r\n  }\r\n\r\n  bool access(int t) const { return (b_vector[t / s_ws]\
    \ >> (t % s_ws) & 1); }\r\n  int rank0(int t) const { return t - rank1(t); }\r\
    \n  int rank1(int t) const {\r\n    return l_block[t / l_ws] + s_block[t / s_ws]\r\
    \n    + popCount(b_vector[t / s_ws] & bitMask(t % s_ws));\r\n  }\r\n\r\n  int\
    \ rank0(int s, int t) const { return (t - s) - rank1(s, t); }\r\n  int rank1(int\
    \ s, int t) const { return (s == t)  ? 0 : rank1(t) - rank1(s); }\r\n\r\n  int\
    \ select0(int t) const;\r\n  int select1(int t) const;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/waveletmatrix/BitVector.cpp
  requiredBy:
  - datastructure/waveletmatrix/WaveletMatrixPointAddRectangleSum.cpp
  - datastructure/waveletmatrix/WaveletMatrix.cpp
  - datastructure/waveletmatrix/WaveletMatrixRectangleSum.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/lc/range_kth_smallest_WaveletMatrix.test.cpp
documentation_of: datastructure/waveletmatrix/BitVector.cpp
layout: document
redirect_from:
- /library/datastructure/waveletmatrix/BitVector.cpp
- /library/datastructure/waveletmatrix/BitVector.cpp.html
title: datastructure/waveletmatrix/BitVector.cpp
---
