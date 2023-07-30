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
  bundledCode: "#line 2 \"math/euler_phi.cpp\"\n\r\ntemplate<typename T>\r\nT euler_phi(T\
    \ n){\r\n  T res = n;\r\n  for(T i = 2; i*i <= n; i++){\r\n    if(n%i == 0){\r\
    \n      res -= res/i;\r\n      while(n%i == 0) n /= i;\r\n    }\r\n  }\r\n  if(n\
    \ > 1) res -= res / n;\r\n  return res;\r\n}\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nT euler_phi(T n){\r\n  T res\
    \ = n;\r\n  for(T i = 2; i*i <= n; i++){\r\n    if(n%i == 0){\r\n      res -=\
    \ res/i;\r\n      while(n%i == 0) n /= i;\r\n    }\r\n  }\r\n  if(n > 1) res -=\
    \ res / n;\r\n  return res;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/euler_phi.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/euler_phi.cpp
layout: document
redirect_from:
- /library/math/euler_phi.cpp
- /library/math/euler_phi.cpp.html
title: math/euler_phi.cpp
---
