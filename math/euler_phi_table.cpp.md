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
  bundledCode: "#line 2 \"math/euler_phi_table.cpp\"\n\r\nvector<int> euler_phi_table(int\
    \ n) {\r\n  vector<int> euler(n+1);\r\n  iota(euler.begin(), euler.end(), 0);\r\
    \n  \r\n  for(int i = 2; i <= n; i++){\r\n    if(euler[i] == i) {\r\n      for(int\
    \ j = i; j <= n; j += i) {\r\n        euler[j] = euler[j] / i * (i - 1);\r\n \
    \     }\r\n    }\r\n  }\r\n  return euler;\r\n}\n"
  code: "#pragma once\r\n\r\nvector<int> euler_phi_table(int n) {\r\n  vector<int>\
    \ euler(n+1);\r\n  iota(euler.begin(), euler.end(), 0);\r\n  \r\n  for(int i =\
    \ 2; i <= n; i++){\r\n    if(euler[i] == i) {\r\n      for(int j = i; j <= n;\
    \ j += i) {\r\n        euler[j] = euler[j] / i * (i - 1);\r\n      }\r\n    }\r\
    \n  }\r\n  return euler;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/euler_phi_table.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/euler_phi_table.cpp
layout: document
redirect_from:
- /library/math/euler_phi_table.cpp
- /library/math/euler_phi_table.cpp.html
title: math/euler_phi_table.cpp
---
