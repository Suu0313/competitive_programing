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
  bundledCode: "#line 1 \"unuse/nextpermutation.cpp\"\ntemplate<typename T>\r\nbool\
    \ NextP(vector<T> &a){\r\n  int n = int(a.size());\r\n  int i = -1;\r\n  for(int\
    \ d = n-2; d >= 0; d--){\r\n    if(a.at(d)<a.at(d+1)){\r\n      i = d;\r\n   \
    \   break;\r\n    }\r\n  }\r\n  if(i == -1) return false;\r\n  int j = i;\r\n\
    \  for(int d = n-1; d >= 0; d--){\r\n    if(a.at(d)>a.at(i)){\r\n      j = d;\r\
    \n      break;\r\n    }\r\n  }\r\n  swap(a.at(i),a.at(j));\r\n  reverse(a.begin()+i+1,a.end());\r\
    \n  return true;\r\n}\n"
  code: "template<typename T>\r\nbool NextP(vector<T> &a){\r\n  int n = int(a.size());\r\
    \n  int i = -1;\r\n  for(int d = n-2; d >= 0; d--){\r\n    if(a.at(d)<a.at(d+1)){\r\
    \n      i = d;\r\n      break;\r\n    }\r\n  }\r\n  if(i == -1) return false;\r\
    \n  int j = i;\r\n  for(int d = n-1; d >= 0; d--){\r\n    if(a.at(d)>a.at(i)){\r\
    \n      j = d;\r\n      break;\r\n    }\r\n  }\r\n  swap(a.at(i),a.at(j));\r\n\
    \  reverse(a.begin()+i+1,a.end());\r\n  return true;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: unuse/nextpermutation.cpp
  requiredBy: []
  timestamp: '2021-03-09 18:45:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unuse/nextpermutation.cpp
layout: document
redirect_from:
- /library/unuse/nextpermutation.cpp
- /library/unuse/nextpermutation.cpp.html
title: unuse/nextpermutation.cpp
---
