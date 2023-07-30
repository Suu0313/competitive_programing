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
  bundledCode: "#line 1 \"unuse/oldcom.cpp\"\nLL fac[MAX], finv[MAX], inv[MAX];\r\n\
    \r\nvoid ConInit(LL M=MOD) {\r\n  fac[0] = fac[1] = 1;\r\n  finv[0] = finv[1]\
    \ = 1;\r\n  inv[1] = 1;\r\n  for (int i = 2; i < MAX; i++){\r\n    fac[i] = fac[i\
    \ - 1] * i % M;\r\n    inv[i] = M - inv[M%i] * (M / i) % M;\r\n    finv[i] = finv[i\
    \ - 1] * inv[i] % M;\r\n  }\r\n}\r\n\r\nLL COM(int n, int k, LL M=MOD){\r\n  if\
    \ (n < k) return 0;\r\n  if (n < 0 || k < 0) return 0;\r\n  return fac[n] * (finv[k]\
    \ * finv[n - k] % M) % M;\r\n}\r\n\r\nLL PARM(int n, int k, LL M=MOD){\r\n  if\
    \ (n < k) return 0;\r\n  if (n < 0 || k < 0) return 0;\r\n  return fac[n] *finv[n\
    \ - k] % M;\r\n}\r\n\r\nLL HOM(int n, int k, LL M=MOD){\r\n  if(n < 0 || k < 0)\
    \ return 0;\r\n  if(k == 0) return 1;\r\n  return COM(n+k-1, k, M);\r\n}\n"
  code: "LL fac[MAX], finv[MAX], inv[MAX];\r\n\r\nvoid ConInit(LL M=MOD) {\r\n  fac[0]\
    \ = fac[1] = 1;\r\n  finv[0] = finv[1] = 1;\r\n  inv[1] = 1;\r\n  for (int i =\
    \ 2; i < MAX; i++){\r\n    fac[i] = fac[i - 1] * i % M;\r\n    inv[i] = M - inv[M%i]\
    \ * (M / i) % M;\r\n    finv[i] = finv[i - 1] * inv[i] % M;\r\n  }\r\n}\r\n\r\n\
    LL COM(int n, int k, LL M=MOD){\r\n  if (n < k) return 0;\r\n  if (n < 0 || k\
    \ < 0) return 0;\r\n  return fac[n] * (finv[k] * finv[n - k] % M) % M;\r\n}\r\n\
    \r\nLL PARM(int n, int k, LL M=MOD){\r\n  if (n < k) return 0;\r\n  if (n < 0\
    \ || k < 0) return 0;\r\n  return fac[n] *finv[n - k] % M;\r\n}\r\n\r\nLL HOM(int\
    \ n, int k, LL M=MOD){\r\n  if(n < 0 || k < 0) return 0;\r\n  if(k == 0) return\
    \ 1;\r\n  return COM(n+k-1, k, M);\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: unuse/oldcom.cpp
  requiredBy: []
  timestamp: '2021-03-09 18:45:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unuse/oldcom.cpp
layout: document
redirect_from:
- /library/unuse/oldcom.cpp
- /library/unuse/oldcom.cpp.html
title: unuse/oldcom.cpp
---
