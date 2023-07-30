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
  bundledCode: "#line 2 \"math/prime/divisor_factor.cpp\"\n\r\ntemplate<typename T>\r\
    \nset<T> divisor_factor(T n){\r\n  set<T> s;\r\n  for(T i = 1; i*i <= n; ++i)\
    \ {\r\n    if(n%i != 0) continue;\r\n    s.insert(i);\r\n    s.insert(n/i);\r\n\
    \  }\r\n  return s;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nset<T> divisor_factor(T n){\r\
    \n  set<T> s;\r\n  for(T i = 1; i*i <= n; ++i) {\r\n    if(n%i != 0) continue;\r\
    \n    s.insert(i);\r\n    s.insert(n/i);\r\n  }\r\n  return s;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime/divisor_factor.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime/divisor_factor.cpp
layout: document
redirect_from:
- /library/math/prime/divisor_factor.cpp
- /library/math/prime/divisor_factor.cpp.html
title: math/prime/divisor_factor.cpp
---
