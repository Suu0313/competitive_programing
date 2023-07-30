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
  bundledCode: "#line 2 \"math/integer/isqrt.cpp\"\n\r\nuint64_t isqrt(uint64_t x){\r\
    \n  uint64_t res = 0, over = 1;\r\n  while(over*over <= x) over <<= 1;\r\n  while(over-res\
    \ > 1){\r\n    uint64_t wj = res + ((over-res) >> 1);\r\n    ((wj*wj <= x) ? res\
    \ : over) = wj;\r\n  }\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n\r\nuint64_t isqrt(uint64_t x){\r\n  uint64_t res = 0, over\
    \ = 1;\r\n  while(over*over <= x) over <<= 1;\r\n  while(over-res > 1){\r\n  \
    \  uint64_t wj = res + ((over-res) >> 1);\r\n    ((wj*wj <= x) ? res : over) =\
    \ wj;\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/integer/isqrt.cpp
  requiredBy:
  - template/template_integers.cpp
  - template/template.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/integer/isqrt.cpp
layout: document
redirect_from:
- /library/math/integer/isqrt.cpp
- /library/math/integer/isqrt.cpp.html
title: math/integer/isqrt.cpp
---
