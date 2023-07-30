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
  bundledCode: "#line 2 \"container/makeV.cpp\"\n\r\ntemplate<typename T>\r\nvector<T>\
    \ make_v(size_t a,T b){return vector<T>(a,b);}\r\n\r\ntemplate<typename... Ts>\r\
    \nauto make_v(size_t a,Ts... ts){\r\n  return vector<decltype(make_v(ts...))>(a,make_v(ts...));\r\
    \n}\r\n\r\ntemplate<typename T>\r\nvalarray<T> make_va(size_t a,T b){return valarray(b,a);}\r\
    \ntemplate<typename... Ts>\r\nauto make_va(size_t a,Ts... ts){ return valarray(make_va(ts...),\
    \ a); }\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nvector<T> make_v(size_t a,T b){return\
    \ vector<T>(a,b);}\r\n\r\ntemplate<typename... Ts>\r\nauto make_v(size_t a,Ts...\
    \ ts){\r\n  return vector<decltype(make_v(ts...))>(a,make_v(ts...));\r\n}\r\n\r\
    \ntemplate<typename T>\r\nvalarray<T> make_va(size_t a,T b){return valarray(b,a);}\r\
    \ntemplate<typename... Ts>\r\nauto make_va(size_t a,Ts... ts){ return valarray(make_va(ts...),\
    \ a); }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: container/makeV.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: container/makeV.cpp
layout: document
redirect_from:
- /library/container/makeV.cpp
- /library/container/makeV.cpp.html
title: container/makeV.cpp
---
