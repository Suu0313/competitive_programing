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
  bundledCode: "#line 2 \"math/integer/gray_code.cpp\"\n\r\ninline pair<int, bool>\
    \ gray_code(unsigned long long bit){\r\n  int lsb = __builtin_ctzll(bit);\r\n\
    \  return {lsb,  (1ll << lsb)&(bit ^ (bit>>1))};\r\n}\r\n"
  code: "#pragma once\r\n\r\ninline pair<int, bool> gray_code(unsigned long long bit){\r\
    \n  int lsb = __builtin_ctzll(bit);\r\n  return {lsb,  (1ll << lsb)&(bit ^ (bit>>1))};\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/integer/gray_code.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/integer/gray_code.cpp
layout: document
redirect_from:
- /library/math/integer/gray_code.cpp
- /library/math/integer/gray_code.cpp.html
title: math/integer/gray_code.cpp
---
