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
  bundledCode: "#line 2 \"math/integer/bit_rev_permutation.cpp\"\n\r\nvector<int>\
    \ bit_rev_perm(int k){\r\n  int n = 1 << k;\r\n  vector<int> a(n);\r\n  for(int\
    \ i = 0, l = 1; i < k; ++i, l <<= 1){\r\n    n >>= 1;\r\n    for(int j = 0; j\
    \ < l; ++j){\r\n      a[l + j] = a[j] + n;\r\n    }\r\n  }\r\n  return a;\r\n\
    }\r\n"
  code: "#pragma once\r\n\r\nvector<int> bit_rev_perm(int k){\r\n  int n = 1 << k;\r\
    \n  vector<int> a(n);\r\n  for(int i = 0, l = 1; i < k; ++i, l <<= 1){\r\n   \
    \ n >>= 1;\r\n    for(int j = 0; j < l; ++j){\r\n      a[l + j] = a[j] + n;\r\n\
    \    }\r\n  }\r\n  return a;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/integer/bit_rev_permutation.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/integer/bit_rev_permutation.cpp
layout: document
redirect_from:
- /library/math/integer/bit_rev_permutation.cpp
- /library/math/integer/bit_rev_permutation.cpp.html
title: math/integer/bit_rev_permutation.cpp
---
