---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: string/run_enumerate.cpp
    title: string/run_enumerate.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/z_algorithm.cpp\"\n\r\ntemplate<typename Container>\r\
    \nvector<int> z_algorithm(const Container &s){\r\n  int n = int(s.size());\r\n\
    \  vector<int> z(n + 1); z[0] = n;\r\n  int i = 1, j = 0;\r\n  \r\n  while(i <\
    \ n){\r\n    while(i+j < n && s[j] == s[i+j]) ++j;\r\n    z[i] = j;\r\n    if(j==0){i++;\
    \ continue;}\r\n    \r\n    int k = 1;\r\n    while(k<j && k+z[k] < j){\r\n  \
    \    z[i+k] = z[k]; ++k;\r\n    }\r\n    i += k; j -= k;\r\n  }\r\n  return z;\r\
    \n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename Container>\r\nvector<int> z_algorithm(const\
    \ Container &s){\r\n  int n = int(s.size());\r\n  vector<int> z(n + 1); z[0] =\
    \ n;\r\n  int i = 1, j = 0;\r\n  \r\n  while(i < n){\r\n    while(i+j < n && s[j]\
    \ == s[i+j]) ++j;\r\n    z[i] = j;\r\n    if(j==0){i++; continue;}\r\n    \r\n\
    \    int k = 1;\r\n    while(k<j && k+z[k] < j){\r\n      z[i+k] = z[k]; ++k;\r\
    \n    }\r\n    i += k; j -= k;\r\n  }\r\n  return z;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/z_algorithm.cpp
  requiredBy:
  - string/run_enumerate.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/z_algorithm.cpp
layout: document
redirect_from:
- /library/string/z_algorithm.cpp
- /library/string/z_algorithm.cpp.html
title: string/z_algorithm.cpp
---
