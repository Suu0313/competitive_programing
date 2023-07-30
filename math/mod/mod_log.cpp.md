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
  bundledCode: "#line 2 \"math/mod/mod_log.cpp\"\n\r\ntemplate<typename T>\r\nT mod_log(T\
    \ x, T y, T m){ // x^k = y mod m\r\n  if(m == 1 || y == 1) return 0;\r\n  if(x\
    \ == 0){\r\n    if(y == 0) return 1;\r\n    return -1;\r\n  }\r\n\r\n  auto inv\
    \ = [](T a, T c){\r\n    T b = c, u= 1, v = 0;\r\n    while(b){\r\n      T t =\
    \ a/b;\r\n      a -= t*b; swap(a,b);\r\n      u -= t*v; swap(u,v);\r\n    }\r\n\
    \    u %= c; if(u<0) u+= c;\r\n    return u;\r\n  };\r\n\r\n  T d = 0, xd = 1;\r\
    \n  for(T l = m; l > 0; l >>= 1){\r\n    if(xd == y) return d;\r\n    (xd *= x)\
    \ %= m; ++d;\r\n  }\r\n\r\n  {\r\n    T g = gcd(xd, m);\r\n    if(y % g != 0)\
    \ return -1;\r\n    m /= g;\r\n    (y *= inv(xd, m)) %= m;\r\n  }\r\n  \r\n  T\
    \ h = 0, gs = 1;\r\n  for(T ix = inv(x, m); h*h < m; ++h) (gs *= ix) %= m;\r\n\
    \r\n  unordered_map<T, T> bs;\r\n  for(T s = 0, b = 1; s < h; ++s){\r\n    if(bs.count(b))\
    \ break;\r\n    bs[b] = s; (b *= x) %= m;\r\n  }\r\n  \r\n  for(T s = 0, g = y;\
    \ s < h; ++s){\r\n    if(bs.count(g)) return d + s*h + bs[g];\r\n    (g *= gs)\
    \ %= m;\r\n  }\r\n  return -1;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nT mod_log(T x, T y, T m){ //\
    \ x^k = y mod m\r\n  if(m == 1 || y == 1) return 0;\r\n  if(x == 0){\r\n    if(y\
    \ == 0) return 1;\r\n    return -1;\r\n  }\r\n\r\n  auto inv = [](T a, T c){\r\
    \n    T b = c, u= 1, v = 0;\r\n    while(b){\r\n      T t = a/b;\r\n      a -=\
    \ t*b; swap(a,b);\r\n      u -= t*v; swap(u,v);\r\n    }\r\n    u %= c; if(u<0)\
    \ u+= c;\r\n    return u;\r\n  };\r\n\r\n  T d = 0, xd = 1;\r\n  for(T l = m;\
    \ l > 0; l >>= 1){\r\n    if(xd == y) return d;\r\n    (xd *= x) %= m; ++d;\r\n\
    \  }\r\n\r\n  {\r\n    T g = gcd(xd, m);\r\n    if(y % g != 0) return -1;\r\n\
    \    m /= g;\r\n    (y *= inv(xd, m)) %= m;\r\n  }\r\n  \r\n  T h = 0, gs = 1;\r\
    \n  for(T ix = inv(x, m); h*h < m; ++h) (gs *= ix) %= m;\r\n\r\n  unordered_map<T,\
    \ T> bs;\r\n  for(T s = 0, b = 1; s < h; ++s){\r\n    if(bs.count(b)) break;\r\
    \n    bs[b] = s; (b *= x) %= m;\r\n  }\r\n  \r\n  for(T s = 0, g = y; s < h; ++s){\r\
    \n    if(bs.count(g)) return d + s*h + bs[g];\r\n    (g *= gs) %= m;\r\n  }\r\n\
    \  return -1;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/mod/mod_log.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod/mod_log.cpp
layout: document
redirect_from:
- /library/math/mod/mod_log.cpp
- /library/math/mod/mod_log.cpp.html
title: math/mod/mod_log.cpp
---
