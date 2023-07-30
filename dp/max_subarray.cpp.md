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
  bundledCode: "#line 2 \"dp/max_subarray.cpp\"\n\r\ntemplate<typename T>\r\nT max_subarray(const\
    \ vector<T> &v){\r\n  T res = v[0], sum = 0;\r\n  for(auto&&x : v){\r\n    sum\
    \ = max(sum + x, x);\r\n    res = max(res, sum);\r\n  }\r\n  return res;\r\n}\r\
    \n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nT max_subarray(const vector<T>\
    \ &v){\r\n  T res = v[0], sum = 0;\r\n  for(auto&&x : v){\r\n    sum = max(sum\
    \ + x, x);\r\n    res = max(res, sum);\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/max_subarray.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/max_subarray.cpp
layout: document
redirect_from:
- /library/dp/max_subarray.cpp
- /library/dp/max_subarray.cpp.html
title: dp/max_subarray.cpp
---
