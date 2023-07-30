---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: template/template.cpp
    title: template/template.cpp
  - icon: ':warning:'
    path: template/template_integers.cpp
    title: template/template_integers.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/integer/ipow.cpp\"\n\r\ntemplate<typename T>\r\nT mod_inv(T\
    \ a, T m){\r\n  T b = m, u= 1, v = 0;\r\n  while(b){ T t = a/b; a -= t*b; swap(a,b);\
    \ u -= t*v; swap(u,v); }\r\n  u %= m; if(u<0) u+= m;\r\n  return u;\r\n}\r\n\r\
    \ntemplate<typename T>\r\nT ipow(T a, int64_t n, T m = 0, T e = 1){\r\n  if(n\
    \ < 0){ assert(m != 0); return mod_inv(ipow(a, -n, m, e), m); }\r\n  T res = e;\r\
    \n  while(n > 0){ if(n&1){ res *= a; if(m) res %= m; } a *= a; n >>= 1; if(m)\
    \ a %= m; }\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nT mod_inv(T a, T m){\r\n  T b\
    \ = m, u= 1, v = 0;\r\n  while(b){ T t = a/b; a -= t*b; swap(a,b); u -= t*v; swap(u,v);\
    \ }\r\n  u %= m; if(u<0) u+= m;\r\n  return u;\r\n}\r\n\r\ntemplate<typename T>\r\
    \nT ipow(T a, int64_t n, T m = 0, T e = 1){\r\n  if(n < 0){ assert(m != 0); return\
    \ mod_inv(ipow(a, -n, m, e), m); }\r\n  T res = e;\r\n  while(n > 0){ if(n&1){\
    \ res *= a; if(m) res %= m; } a *= a; n >>= 1; if(m) a %= m; }\r\n  return res;\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/integer/ipow.cpp
  requiredBy:
  - template/template_integers.cpp
  - template/template.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/integer/ipow.cpp
layout: document
redirect_from:
- /library/math/integer/ipow.cpp
- /library/math/integer/ipow.cpp.html
title: math/integer/ipow.cpp
---
