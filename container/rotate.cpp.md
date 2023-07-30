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
  bundledCode: "#line 2 \"container/rotate.cpp\"\n\r\ntemplate<typename T>\r\nvector<vector<T>>\
    \ rotate(const vector<vector<T>> &a){\r\n  int h = int(a.size()), w = int(a[0].size());\r\
    \n  vector<vector<T>> b(w, vector<T>(h));\r\n  for(int i = 0; i < h; ++i){\r\n\
    \    for(int j = 0; j < w; ++j){\r\n      b[j][h-i-1] = a[i][j];\r\n    }\r\n\
    \  }\r\n  return b;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nvector<vector<T>> rotate(const\
    \ vector<vector<T>> &a){\r\n  int h = int(a.size()), w = int(a[0].size());\r\n\
    \  vector<vector<T>> b(w, vector<T>(h));\r\n  for(int i = 0; i < h; ++i){\r\n\
    \    for(int j = 0; j < w; ++j){\r\n      b[j][h-i-1] = a[i][j];\r\n    }\r\n\
    \  }\r\n  return b;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: container/rotate.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: container/rotate.cpp
layout: document
redirect_from:
- /library/container/rotate.cpp
- /library/container/rotate.cpp.html
title: container/rotate.cpp
---
