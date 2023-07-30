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
  bundledCode: "#line 2 \"other/slide_min.cpp\"\n\r\ntemplate<typename T>\r\nvector<T>\
    \ slide_min(const vector<T> &v, int k){\r\n  int n = SZ(v);\r\n  deque<int> deq;\r\
    \n  vector<T> res;\r\n  for(int i = 0; i < n; ++i){\r\n    while(!deq.empty()\
    \ && v.at(deq.back()) >= v.at(i)){\r\n      deq.pop_back();\r\n    }\r\n    deq.push_back(i);\r\
    \n    if(i-k+1 >= 0){\r\n      res.emplace_back(v.at(deq.front()));\r\n      if(deq.front()\
    \ == i - k + 1) deq.pop_front();\r\n    }\r\n  }\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nvector<T> slide_min(const vector<T>\
    \ &v, int k){\r\n  int n = SZ(v);\r\n  deque<int> deq;\r\n  vector<T> res;\r\n\
    \  for(int i = 0; i < n; ++i){\r\n    while(!deq.empty() && v.at(deq.back()) >=\
    \ v.at(i)){\r\n      deq.pop_back();\r\n    }\r\n    deq.push_back(i);\r\n   \
    \ if(i-k+1 >= 0){\r\n      res.emplace_back(v.at(deq.front()));\r\n      if(deq.front()\
    \ == i - k + 1) deq.pop_front();\r\n    }\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/slide_min.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/slide_min.cpp
layout: document
redirect_from:
- /library/other/slide_min.cpp
- /library/other/slide_min.cpp.html
title: other/slide_min.cpp
---
