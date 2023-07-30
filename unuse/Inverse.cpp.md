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
  bundledCode: "#line 1 \"unuse/Inverse.cpp\"\ntemplate<typename T>\r\nT ModInv(T\
    \ a, T m){\r\n  T b = m, u= 1, v = 0;\r\n  while(b){\r\n    T t = a/b;\r\n   \
    \ a -= t*b; swap(a,b);\r\n    u -= t*v; swap(u,v);\r\n  }\r\n  u %= m; if(u<0)\
    \ u+= m;\r\n  return u;\r\n}\r\n"
  code: "template<typename T>\r\nT ModInv(T a, T m){\r\n  T b = m, u= 1, v = 0;\r\n\
    \  while(b){\r\n    T t = a/b;\r\n    a -= t*b; swap(a,b);\r\n    u -= t*v; swap(u,v);\r\
    \n  }\r\n  u %= m; if(u<0) u+= m;\r\n  return u;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: unuse/Inverse.cpp
  requiredBy: []
  timestamp: '2021-03-31 03:45:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unuse/Inverse.cpp
layout: document
redirect_from:
- /library/unuse/Inverse.cpp
- /library/unuse/Inverse.cpp.html
title: unuse/Inverse.cpp
---
