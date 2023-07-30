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
  bundledCode: "#line 2 \"dp/montmort_number.cpp\"\n\r\ntemplate<typename T>\r\nvector<T>\
    \ montmort_number(int n){\r\n  vector<T> dp(n + 1, 1);\r\n  for(int i = 1; i <=\
    \ n; ++i){\r\n    dp[i] = dp[i-1] * i + (i%2 == 0 ? 1 : -1);\r\n  }\r\n  return\
    \ dp;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nvector<T> montmort_number(int\
    \ n){\r\n  vector<T> dp(n + 1, 1);\r\n  for(int i = 1; i <= n; ++i){\r\n    dp[i]\
    \ = dp[i-1] * i + (i%2 == 0 ? 1 : -1);\r\n  }\r\n  return dp;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/montmort_number.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/montmort_number.cpp
layout: document
redirect_from:
- /library/dp/montmort_number.cpp
- /library/dp/montmort_number.cpp.html
title: dp/montmort_number.cpp
---
