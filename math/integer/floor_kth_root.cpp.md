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
  bundledCode: "#line 2 \"math/integer/floor_kth_root.cpp\"\n\r\nuint64_t floor_kth_root(uint64_t\
    \ a, int k){\r\n  if(a <= 1 || k <= 1) return a;\r\n  if(k >= 64) return 1;\r\n\
    \  uint64_t res = 0;\r\n  for(int i = 31; i >= 0; --i){\r\n    uint64_t p = 1,\
    \ x = res | (1u << i);\r\n    bool fl = true;\r\n    for(int j = 0; j < k; ++j){\r\
    \n      if(__builtin_mul_overflow(p, x, &p)){ fl = false; break;}\r\n    }\r\n\
    \    if(fl && p <= a) res |= (1u << i);\r\n  }\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n\r\nuint64_t floor_kth_root(uint64_t a, int k){\r\n  if(a\
    \ <= 1 || k <= 1) return a;\r\n  if(k >= 64) return 1;\r\n  uint64_t res = 0;\r\
    \n  for(int i = 31; i >= 0; --i){\r\n    uint64_t p = 1, x = res | (1u << i);\r\
    \n    bool fl = true;\r\n    for(int j = 0; j < k; ++j){\r\n      if(__builtin_mul_overflow(p,\
    \ x, &p)){ fl = false; break;}\r\n    }\r\n    if(fl && p <= a) res |= (1u <<\
    \ i);\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/integer/floor_kth_root.cpp
  requiredBy:
  - template/template_integers.cpp
  - template/template.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/integer/floor_kth_root.cpp
layout: document
redirect_from:
- /library/math/integer/floor_kth_root.cpp
- /library/math/integer/floor_kth_root.cpp.html
title: math/integer/floor_kth_root.cpp
---
