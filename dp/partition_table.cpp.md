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
  bundledCode: "#line 2 \"dp/partition_table.cpp\"\n\r\ntemplate<typename T>\r\nvector<vector<T>>\
    \ partition_table(int n, int k){\r\n  vector<vector<T>> dp(n + 1, vector<T>(k\
    \ + 1));\r\n  dp[0][0] = 1;\r\n  for(int i = 0; i <= n; i++){\r\n    for(int j\
    \ = 1; j <= k; j++){\r\n      dp[i][j] = dp[i][j - 1];\r\n      if(i >= j) dp[i][j]\
    \ += dp[i - j][j];\r\n    }\r\n  }\r\n  return dp;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nvector<vector<T>> partition_table(int\
    \ n, int k){\r\n  vector<vector<T>> dp(n + 1, vector<T>(k + 1));\r\n  dp[0][0]\
    \ = 1;\r\n  for(int i = 0; i <= n; i++){\r\n    for(int j = 1; j <= k; j++){\r\
    \n      dp[i][j] = dp[i][j - 1];\r\n      if(i >= j) dp[i][j] += dp[i - j][j];\r\
    \n    }\r\n  }\r\n  return dp;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/partition_table.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/partition_table.cpp
layout: document
redirect_from:
- /library/dp/partition_table.cpp
- /library/dp/partition_table.cpp.html
title: dp/partition_table.cpp
---
