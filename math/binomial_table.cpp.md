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
  bundledCode: "#line 2 \"math/binomial_table.cpp\"\n\r\ntemplate<typename T>\r\n\
    vector<vector<T>> binomial_table(int n){\r\n  vector<vector<T>> mat(n+1, vector<T>(n+1));\r\
    \n  for(int i = 0; i <= n; ++i){\r\n    for(int j = 0; j <= i; ++j){\r\n     \
    \ if(j == 0 || j == i) mat[i][j] = 1;\r\n      else mat[i][j] = mat[i-1][j-1]\
    \ + mat[i-1][j];\r\n    }\r\n  }\r\n  return mat;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nvector<vector<T>> binomial_table(int\
    \ n){\r\n  vector<vector<T>> mat(n+1, vector<T>(n+1));\r\n  for(int i = 0; i <=\
    \ n; ++i){\r\n    for(int j = 0; j <= i; ++j){\r\n      if(j == 0 || j == i) mat[i][j]\
    \ = 1;\r\n      else mat[i][j] = mat[i-1][j-1] + mat[i-1][j];\r\n    }\r\n  }\r\
    \n  return mat;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/binomial_table.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/binomial_table.cpp
layout: document
redirect_from:
- /library/math/binomial_table.cpp
- /library/math/binomial_table.cpp.html
title: math/binomial_table.cpp
---
