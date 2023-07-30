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
  bundledCode: "#line 2 \"other/max_of.cpp\"\n\r\ntemplate<typename T, class Iiter,\
    \ class Fn>\r\nT max_of(Iiter first, Iiter last, const Fn &f){\r\n  T res = f(*first);\r\
    \n  for(++first; first != last; ++first) res = max(res, f(*first));\r\n  return\
    \ res;\r\n}\r\n\r\ntemplate<typename T, class Fn>\r\nT max_of(int n, const Fn\
    \ &f){\r\n  T res = f(0);\r\n  for(int i = 1; i < n; ++i) res = max(res, f(i));\r\
    \n  return res;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T, class Iiter, class Fn>\r\nT max_of(Iiter\
    \ first, Iiter last, const Fn &f){\r\n  T res = f(*first);\r\n  for(++first; first\
    \ != last; ++first) res = max(res, f(*first));\r\n  return res;\r\n}\r\n\r\ntemplate<typename\
    \ T, class Fn>\r\nT max_of(int n, const Fn &f){\r\n  T res = f(0);\r\n  for(int\
    \ i = 1; i < n; ++i) res = max(res, f(i));\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/max_of.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/max_of.cpp
layout: document
redirect_from:
- /library/other/max_of.cpp
- /library/other/max_of.cpp.html
title: other/max_of.cpp
---
