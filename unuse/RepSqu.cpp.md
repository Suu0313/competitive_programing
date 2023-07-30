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
  bundledCode: "#line 1 \"unuse/RepSqu.cpp\"\nLL RepSqu(LL N, LL P, LL M) {\r\n  if(P\
    \ == 0) {\r\n    return 1;\r\n  }\r\n  if(P%2 == 0) {\r\n    LL t = RepSqu(N,\
    \ P/2, M);\r\n    return t*t % M;\r\n  }\r\n  return (N * RepSqu(N, P-1, M)) %\
    \ M;\r\n}\r\n"
  code: "LL RepSqu(LL N, LL P, LL M) {\r\n  if(P == 0) {\r\n    return 1;\r\n  }\r\
    \n  if(P%2 == 0) {\r\n    LL t = RepSqu(N, P/2, M);\r\n    return t*t % M;\r\n\
    \  }\r\n  return (N * RepSqu(N, P-1, M)) % M;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: unuse/RepSqu.cpp
  requiredBy: []
  timestamp: '2021-03-09 18:45:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unuse/RepSqu.cpp
layout: document
redirect_from:
- /library/unuse/RepSqu.cpp
- /library/unuse/RepSqu.cpp.html
title: unuse/RepSqu.cpp
---
