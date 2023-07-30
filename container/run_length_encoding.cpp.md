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
  bundledCode: "#line 2 \"container/run_length_encoding.cpp\"\n\r\ntemplate <typename\
    \ Container, typename T = typename Container::value_type>\r\nvector<pair<T,int>>\
    \ run_length_encoding(const Container &v){\r\n  if(v.empty()) return {};\r\n \
    \ vector<pair<T,int>> res;\r\n  res.emplace_back(v[0], 0);\r\n  for(auto&&x :\
    \ v){\r\n    if(res.back().first == x) res.back().second++;\r\n    else res.emplace_back(x,\
    \ 1);\r\n  }\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename Container, typename T = typename Container::value_type>\r\
    \nvector<pair<T,int>> run_length_encoding(const Container &v){\r\n  if(v.empty())\
    \ return {};\r\n  vector<pair<T,int>> res;\r\n  res.emplace_back(v[0], 0);\r\n\
    \  for(auto&&x : v){\r\n    if(res.back().first == x) res.back().second++;\r\n\
    \    else res.emplace_back(x, 1);\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: container/run_length_encoding.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: container/run_length_encoding.cpp
layout: document
redirect_from:
- /library/container/run_length_encoding.cpp
- /library/container/run_length_encoding.cpp.html
title: container/run_length_encoding.cpp
---
