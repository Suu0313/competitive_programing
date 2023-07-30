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
  bundledCode: "#line 2 \"other/sum_of_pairs.cpp\"\n\r\ntemplate<typename T>\r\nT\
    \ sum_of_pairs(const vector<T> &v, const T &aa, const T &bb, const T &ab, const\
    \ T &a, const T &b, const T &c){\r\n  int n = int(v.size());\r\n  T res = 0, sum\
    \ = 0;\r\n  for(int i = 0; i < n; ++i){\r\n    res += (aa*(n-i-1) + bb*i) * v[i]*v[i]\
    \ + (a*v[i] + c) * (n-i-1) + (ab*v[i] + b) * sum;\r\n    sum += v[i];\r\n  }\r\
    \n  return res;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nT sum_of_pairs(const vector<T>\
    \ &v, const T &aa, const T &bb, const T &ab, const T &a, const T &b, const T &c){\r\
    \n  int n = int(v.size());\r\n  T res = 0, sum = 0;\r\n  for(int i = 0; i < n;\
    \ ++i){\r\n    res += (aa*(n-i-1) + bb*i) * v[i]*v[i] + (a*v[i] + c) * (n-i-1)\
    \ + (ab*v[i] + b) * sum;\r\n    sum += v[i];\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/sum_of_pairs.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/sum_of_pairs.cpp
layout: document
redirect_from:
- /library/other/sum_of_pairs.cpp
- /library/other/sum_of_pairs.cpp.html
title: other/sum_of_pairs.cpp
---
