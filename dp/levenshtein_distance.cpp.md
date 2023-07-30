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
  bundledCode: "#line 2 \"dp/levenshtein_distance.cpp\"\n\r\nint levenshtein_distance(const\
    \ string &s, const string &t){\r\n  int n = int(s.size()), m = int(t.size());\r\
    \n  vector dp(n+1, vector(m+1,n+m));\r\n  for(int i = 0; i < n+1; ++i) dp[i][0]\
    \ = i;\r\n  for(int i = 0; i < m+1; ++i) dp[0][i] = i;\r\n\r\n  for(int i = 0;\
    \ i < n; ++i){\r\n    for(int j = 0; j < m; ++j){\r\n      dp[i+1][j+1] = min(\r\
    \n        {dp[i+1][j+1], dp[i][j] + (s[i] != t[j]), dp[i+1][j] + 1, dp[i][j+1]\
    \ + 1}\r\n      );\r\n    }\r\n  }\r\n\r\n  return dp[n][m];\r\n}\r\n"
  code: "#pragma once\r\n\r\nint levenshtein_distance(const string &s, const string\
    \ &t){\r\n  int n = int(s.size()), m = int(t.size());\r\n  vector dp(n+1, vector(m+1,n+m));\r\
    \n  for(int i = 0; i < n+1; ++i) dp[i][0] = i;\r\n  for(int i = 0; i < m+1; ++i)\
    \ dp[0][i] = i;\r\n\r\n  for(int i = 0; i < n; ++i){\r\n    for(int j = 0; j <\
    \ m; ++j){\r\n      dp[i+1][j+1] = min(\r\n        {dp[i+1][j+1], dp[i][j] + (s[i]\
    \ != t[j]), dp[i+1][j] + 1, dp[i][j+1] + 1}\r\n      );\r\n    }\r\n  }\r\n\r\n\
    \  return dp[n][m];\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/levenshtein_distance.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/levenshtein_distance.cpp
layout: document
redirect_from:
- /library/dp/levenshtein_distance.cpp
- /library/dp/levenshtein_distance.cpp.html
title: dp/levenshtein_distance.cpp
---
