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
  bundledCode: "#line 2 \"math/prime/FastSieve.cpp\"\n\r\nstruct FastSieve{\r\n  using\
    \ i8 = uint8_t;\r\n  int n, m;\r\n  vector<i8> table;\r\n\r\n  FastSieve() = default;\r\
    \n  FastSieve(int n): n(n), m(n/30 + 1), table(m, 0xff) {\r\n    table[0] = 0xfe;\r\
    \n    int sn = ceil(sqrt(n) + 0.1), sni = sn / 30;\r\n    for(int i = 0; i <=\
    \ sni ; ++i){\r\n      for(int bit = table[i]; bit; bit &= (bit - 1)){\r\n   \
    \     int pos = ctz(bit), k = ptoi[pos];\r\n        int p = 30 * i + 2 * k;\r\n\
    \        for(int j = i * p + (k * k)/30, np = pos; j < m; j += i * c1[np] + c0[pos][np],\
    \ np = (np + 1)&7){\r\n          table[j] &= mask[pos][np];\r\n        }\r\n \
    \     }\r\n    }\r\n  }\r\n\r\n  static int ctz(int bit){ return (bit == 0) ?\
    \ -1 : __builtin_ctz(bit); }\r\n  static constexpr int ptoi[8] = {1, 7, 11, 13,\
    \ 17, 19, 23, 29};\r\n  static constexpr int c1[8] = {6, 4, 2, 4, 2, 4, 6, 2};\r\
    \n\r\n  static constexpr int c0[8][8] = {\r\n    {0, 0, 0, 0, 0, 0, 0, 1}, {1,\
    \ 1, 1, 0, 1, 1, 1, 1},\r\n    {2, 2, 0, 2, 0, 2, 2, 1}, {3, 1, 1, 2, 1, 1, 3,\
    \ 1},\r\n    {3, 3, 1, 2, 1, 3, 3, 1}, {4, 2, 2, 2, 2, 2, 4, 1},\r\n    {5, 3,\
    \ 1, 4, 1, 3, 5, 1}, {6, 4, 2, 4, 2, 4, 6, 1}\r\n  };\r\n  static constexpr int\
    \ mask[8][8] = {\r\n    {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f},\r\n\
    \    {0xfd, 0xdf, 0xef, 0xfe, 0x7f, 0xf7, 0xfb, 0xbf},\r\n    {0xfb, 0xef, 0xfe,\
    \ 0xbf, 0xfd, 0x7f, 0xf7, 0xdf},\r\n    {0xf7, 0xfe, 0xbf, 0xdf, 0xfb, 0xfd, 0x7f,\
    \ 0xef},\r\n    {0xef, 0x7f, 0xfd, 0xfb, 0xdf, 0xbf, 0xfe, 0xf7},\r\n    {0xdf,\
    \ 0xf7, 0x7f, 0xfd, 0xbf, 0xfe, 0xef, 0xfb},\r\n    {0xbf, 0xfb, 0xf7, 0x7f, 0xfe,\
    \ 0xef, 0xdf, 0xfd},\r\n    {0x7f, 0xbf, 0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0xfe}\r\
    \n  };\r\n\r\n  vector<int> prime_table() const {\r\n    vector<int> ps;\r\n \
    \   for(int p : {2, 3, 5}){\r\n      if(p > n) return ps;\r\n      ps.push_back(p);\r\
    \n    }\r\n    for(int i = 0; i < m; ++i){\r\n      for(int bit = table[i]; bit;\
    \ bit &= (bit - 1)){\r\n        int pos = ctz(bit), k = ptoi[pos];\r\n       \
    \ int p = i * 30 + k;\r\n        if(p > n) return ps;\r\n        ps.push_back(p);\r\
    \n      }\r\n    }\r\n    return ps;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\nstruct FastSieve{\r\n  using i8 = uint8_t;\r\n  int n,\
    \ m;\r\n  vector<i8> table;\r\n\r\n  FastSieve() = default;\r\n  FastSieve(int\
    \ n): n(n), m(n/30 + 1), table(m, 0xff) {\r\n    table[0] = 0xfe;\r\n    int sn\
    \ = ceil(sqrt(n) + 0.1), sni = sn / 30;\r\n    for(int i = 0; i <= sni ; ++i){\r\
    \n      for(int bit = table[i]; bit; bit &= (bit - 1)){\r\n        int pos = ctz(bit),\
    \ k = ptoi[pos];\r\n        int p = 30 * i + 2 * k;\r\n        for(int j = i *\
    \ p + (k * k)/30, np = pos; j < m; j += i * c1[np] + c0[pos][np], np = (np + 1)&7){\r\
    \n          table[j] &= mask[pos][np];\r\n        }\r\n      }\r\n    }\r\n  }\r\
    \n\r\n  static int ctz(int bit){ return (bit == 0) ? -1 : __builtin_ctz(bit);\
    \ }\r\n  static constexpr int ptoi[8] = {1, 7, 11, 13, 17, 19, 23, 29};\r\n  static\
    \ constexpr int c1[8] = {6, 4, 2, 4, 2, 4, 6, 2};\r\n\r\n  static constexpr int\
    \ c0[8][8] = {\r\n    {0, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 0, 1, 1, 1, 1},\r\n\
    \    {2, 2, 0, 2, 0, 2, 2, 1}, {3, 1, 1, 2, 1, 1, 3, 1},\r\n    {3, 3, 1, 2, 1,\
    \ 3, 3, 1}, {4, 2, 2, 2, 2, 2, 4, 1},\r\n    {5, 3, 1, 4, 1, 3, 5, 1}, {6, 4,\
    \ 2, 4, 2, 4, 6, 1}\r\n  };\r\n  static constexpr int mask[8][8] = {\r\n    {0xfe,\
    \ 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f},\r\n    {0xfd, 0xdf, 0xef, 0xfe, 0x7f,\
    \ 0xf7, 0xfb, 0xbf},\r\n    {0xfb, 0xef, 0xfe, 0xbf, 0xfd, 0x7f, 0xf7, 0xdf},\r\
    \n    {0xf7, 0xfe, 0xbf, 0xdf, 0xfb, 0xfd, 0x7f, 0xef},\r\n    {0xef, 0x7f, 0xfd,\
    \ 0xfb, 0xdf, 0xbf, 0xfe, 0xf7},\r\n    {0xdf, 0xf7, 0x7f, 0xfd, 0xbf, 0xfe, 0xef,\
    \ 0xfb},\r\n    {0xbf, 0xfb, 0xf7, 0x7f, 0xfe, 0xef, 0xdf, 0xfd},\r\n    {0x7f,\
    \ 0xbf, 0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0xfe}\r\n  };\r\n\r\n  vector<int> prime_table()\
    \ const {\r\n    vector<int> ps;\r\n    for(int p : {2, 3, 5}){\r\n      if(p\
    \ > n) return ps;\r\n      ps.push_back(p);\r\n    }\r\n    for(int i = 0; i <\
    \ m; ++i){\r\n      for(int bit = table[i]; bit; bit &= (bit - 1)){\r\n      \
    \  int pos = ctz(bit), k = ptoi[pos];\r\n        int p = i * 30 + k;\r\n     \
    \   if(p > n) return ps;\r\n        ps.push_back(p);\r\n      }\r\n    }\r\n \
    \   return ps;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime/FastSieve.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime/FastSieve.cpp
layout: document
redirect_from:
- /library/math/prime/FastSieve.cpp
- /library/math/prime/FastSieve.cpp.html
title: math/prime/FastSieve.cpp
---
