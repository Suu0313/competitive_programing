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
  bundledCode: "#line 2 \"math/mod/primitive_root.cpp\"\n\r\nint primitive_root(int64_t\
    \ p){\r\n  if (p == 2) return 1;\r\n  if (p == 167772161) return 3;\r\n  if (p\
    \ == 469762049) return 3;\r\n  if (p == 754974721) return 11;\r\n  if (p == 998244353)\
    \ return 3;\r\n  vector<int64_t> divs = fast_prime_factor(p - 1);\r\n  divs.erase(unique(begin(divs),\
    \ end(divs)), end(divs));\r\n\r\n  auto pow_mod = [](int64_t x, int64_t n, int64_t\
    \ m) ->int64_t {\r\n    if (m == 1) return 0;\r\n    int64_t r = 1;\r\n    for(x\
    \ %= m; n; n >>= 1){\r\n      if(n & 1) r = (__int128_t(r) * x) % m;\r\n     \
    \ x = (__int128_t(x) * x) % m;\r\n    }\r\n    return r;\r\n  };\r\n\r\n  for\
    \ (int g = 2; ; g++) {\r\n    if(none_of(begin(divs), end(divs),\r\n      [&](int64_t\
    \ d){ return pow_mod(g, (p - 1) / d, p) == 1; }))\r\n        return g;\r\n  }\r\
    \n  assert((\"p is not prime?\", false));\r\n  return 0;\r\n}\r\n"
  code: "#pragma once\r\n\r\nint primitive_root(int64_t p){\r\n  if (p == 2) return\
    \ 1;\r\n  if (p == 167772161) return 3;\r\n  if (p == 469762049) return 3;\r\n\
    \  if (p == 754974721) return 11;\r\n  if (p == 998244353) return 3;\r\n  vector<int64_t>\
    \ divs = fast_prime_factor(p - 1);\r\n  divs.erase(unique(begin(divs), end(divs)),\
    \ end(divs));\r\n\r\n  auto pow_mod = [](int64_t x, int64_t n, int64_t m) ->int64_t\
    \ {\r\n    if (m == 1) return 0;\r\n    int64_t r = 1;\r\n    for(x %= m; n; n\
    \ >>= 1){\r\n      if(n & 1) r = (__int128_t(r) * x) % m;\r\n      x = (__int128_t(x)\
    \ * x) % m;\r\n    }\r\n    return r;\r\n  };\r\n\r\n  for (int g = 2; ; g++)\
    \ {\r\n    if(none_of(begin(divs), end(divs),\r\n      [&](int64_t d){ return\
    \ pow_mod(g, (p - 1) / d, p) == 1; }))\r\n        return g;\r\n  }\r\n  assert((\"\
    p is not prime?\", false));\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/mod/primitive_root.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod/primitive_root.cpp
layout: document
redirect_from:
- /library/math/mod/primitive_root.cpp
- /library/math/mod/primitive_root.cpp.html
title: math/mod/primitive_root.cpp
---
