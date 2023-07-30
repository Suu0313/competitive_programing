---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: template/template.cpp
    title: template/template.cpp
  - icon: ':warning:'
    path: template/template_integers.cpp
    title: template/template_integers.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/integer/popcount.cpp\"\n\r\nconstexpr int popcount(uint64_t\
    \ x){\r\n  x -= ((x>>1)&0x5555555555555555ULL);\r\n  x = (x&0x3333333333333333ULL)\
    \ + ((x&0xCCCCCCCCCCCCCCCCULL)>>2);\r\n  x = (x&0x0F0F0F0F0F0F0F0FULL) + ((x&0xF0F0F0F0F0F0F0F0ULL)>>4);\
    \  \r\n  x *= 0x0101010101010101ULL;\r\n  return x >> 56;\r\n}\r\n"
  code: "#pragma once\r\n\r\nconstexpr int popcount(uint64_t x){\r\n  x -= ((x>>1)&0x5555555555555555ULL);\r\
    \n  x = (x&0x3333333333333333ULL) + ((x&0xCCCCCCCCCCCCCCCCULL)>>2);\r\n  x = (x&0x0F0F0F0F0F0F0F0FULL)\
    \ + ((x&0xF0F0F0F0F0F0F0F0ULL)>>4);  \r\n  x *= 0x0101010101010101ULL;\r\n  return\
    \ x >> 56;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/integer/popcount.cpp
  requiredBy:
  - template/template_integers.cpp
  - template/template.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/integer/popcount.cpp
layout: document
redirect_from:
- /library/math/integer/popcount.cpp
- /library/math/integer/popcount.cpp.html
title: math/integer/popcount.cpp
---
