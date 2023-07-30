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
  bundledCode: "#line 2 \"container/concat.cpp\"\n\r\ntemplate<typename T>\r\nvector<T>\
    \ concat(const vector<T> &a, const vector<T> &b){\r\n  vector<T> res = a;\r\n\
    \  res.reserve(a.size() + b.size());\r\n  res.insert(end(res), begin(b), end(b));\r\
    \n  return res;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nvector<T> concat(const vector<T>\
    \ &a, const vector<T> &b){\r\n  vector<T> res = a;\r\n  res.reserve(a.size() +\
    \ b.size());\r\n  res.insert(end(res), begin(b), end(b));\r\n  return res;\r\n\
    }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: container/concat.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: container/concat.cpp
layout: document
redirect_from:
- /library/container/concat.cpp
- /library/container/concat.cpp.html
title: container/concat.cpp
---
