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
  bundledCode: "#line 2 \"math/carmichael_func.cpp\"\n\r\ntemplate<typename T>\r\n\
    constexpr T carmichael_func(T n){\r\n  auto ppow = [&](T p, int e) -> T {\r\n\
    \    T ret = 1;\r\n    for(; e > 0; e >>= 1, p *= p) if(e % 2 == 1) ret *= p;\r\
    \n    return ret;\r\n  };\r\n\r\n  T lam = 1;\r\n  {\r\n    int r = 0;\r\n   \
    \ while(n%2 == 0) ++r, n >>= 1;\r\n    lam *= ppow(2, r - 1) * (p - 1);\r\n  \
    \  if(r >= 3) lam /= 2;\r\n  }\r\n\r\n  for(T p = 3; p * p <= n; ++p){\r\n   \
    \ if(n % p != 0) continue;\r\n    int r = 0;\r\n    do n /= p, ++r; while(n %\
    \ p == 0);\r\n    lam = lcm(lam , ppow(p, r - 1) * (p - 1));\r\n  }\r\n\r\n  if(n\
    \ > 1) lam = lcm(lam , (n - 1));\r\n  \r\n  return lam;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nconstexpr T carmichael_func(T\
    \ n){\r\n  auto ppow = [&](T p, int e) -> T {\r\n    T ret = 1;\r\n    for(; e\
    \ > 0; e >>= 1, p *= p) if(e % 2 == 1) ret *= p;\r\n    return ret;\r\n  };\r\n\
    \r\n  T lam = 1;\r\n  {\r\n    int r = 0;\r\n    while(n%2 == 0) ++r, n >>= 1;\r\
    \n    lam *= ppow(2, r - 1) * (p - 1);\r\n    if(r >= 3) lam /= 2;\r\n  }\r\n\r\
    \n  for(T p = 3; p * p <= n; ++p){\r\n    if(n % p != 0) continue;\r\n    int\
    \ r = 0;\r\n    do n /= p, ++r; while(n % p == 0);\r\n    lam = lcm(lam , ppow(p,\
    \ r - 1) * (p - 1));\r\n  }\r\n\r\n  if(n > 1) lam = lcm(lam , (n - 1));\r\n \
    \ \r\n  return lam;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/carmichael_func.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/carmichael_func.cpp
layout: document
redirect_from:
- /library/math/carmichael_func.cpp
- /library/math/carmichael_func.cpp.html
title: math/carmichael_func.cpp
---
