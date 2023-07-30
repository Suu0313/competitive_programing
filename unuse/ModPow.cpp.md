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
  bundledCode: "#line 1 \"unuse/ModPow.cpp\"\nLL ModPow(LL A, LL N, LL M=MOD){\r\n\
    \  LL res = 1;\r\n  while(N>0){\r\n    if(N&1) res = res * A % M;\r\n    A = A\
    \ * A % M;\r\n    N >>= 1;\r\n  }\r\n  return res;\r\n}\n"
  code: "LL ModPow(LL A, LL N, LL M=MOD){\r\n  LL res = 1;\r\n  while(N>0){\r\n  \
    \  if(N&1) res = res * A % M;\r\n    A = A * A % M;\r\n    N >>= 1;\r\n  }\r\n\
    \  return res;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: unuse/ModPow.cpp
  requiredBy: []
  timestamp: '2021-04-28 11:37:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unuse/ModPow.cpp
layout: document
redirect_from:
- /library/unuse/ModPow.cpp
- /library/unuse/ModPow.cpp.html
title: unuse/ModPow.cpp
---
