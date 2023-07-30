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
  bundledCode: "#line 2 \"container/make_ref_vector.cpp\"\n\r\ntemplate<typename T>\r\
    \nauto make_ref_vector(vector<T> &v, const vector<int> &idx){\r\n  vector<reference_wrapper<T>>\
    \ res;\r\n  for(int i : idx) res.push_back(v[i]);\r\n  return res;\r\n}\r\n\r\n\
    template<typename T>\r\nauto make_ref_vector(vector<T> &v, initializer_list<int>\
    \ idx){\r\n  return make_ref_vector(v, idx);\r\n}\r\n\r\ntemplate<typename T>\r\
    \nauto make_ref_vector(vector<T> &v, const vector<bool> &use){\r\n  vector<reference_wrapper<T>>\
    \ res;\r\n  int n = int(min(v.size(), use.size()));\r\n  for(int i = 0; i < n;\
    \ ++i){\r\n    if(use[i]) res.push_back(v[i]);\r\n  }\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nauto make_ref_vector(vector<T>\
    \ &v, const vector<int> &idx){\r\n  vector<reference_wrapper<T>> res;\r\n  for(int\
    \ i : idx) res.push_back(v[i]);\r\n  return res;\r\n}\r\n\r\ntemplate<typename\
    \ T>\r\nauto make_ref_vector(vector<T> &v, initializer_list<int> idx){\r\n  return\
    \ make_ref_vector(v, idx);\r\n}\r\n\r\ntemplate<typename T>\r\nauto make_ref_vector(vector<T>\
    \ &v, const vector<bool> &use){\r\n  vector<reference_wrapper<T>> res;\r\n  int\
    \ n = int(min(v.size(), use.size()));\r\n  for(int i = 0; i < n; ++i){\r\n   \
    \ if(use[i]) res.push_back(v[i]);\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: container/make_ref_vector.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: container/make_ref_vector.cpp
layout: document
redirect_from:
- /library/container/make_ref_vector.cpp
- /library/container/make_ref_vector.cpp.html
title: container/make_ref_vector.cpp
---
