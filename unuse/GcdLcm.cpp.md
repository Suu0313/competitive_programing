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
  bundledCode: "#line 1 \"unuse/GcdLcm.cpp\"\nLL gcd(LL a, LL b) { return b?gcd(b,a%b):a;}\r\
    \nLL lcm(LL a, LL b) { return a/gcd(a,b)*b;}\n"
  code: "LL gcd(LL a, LL b) { return b?gcd(b,a%b):a;}\r\nLL lcm(LL a, LL b) { return\
    \ a/gcd(a,b)*b;}"
  dependsOn: []
  isVerificationFile: false
  path: unuse/GcdLcm.cpp
  requiredBy: []
  timestamp: '2021-03-30 00:16:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unuse/GcdLcm.cpp
layout: document
redirect_from:
- /library/unuse/GcdLcm.cpp
- /library/unuse/GcdLcm.cpp.html
title: unuse/GcdLcm.cpp
---
