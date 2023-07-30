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
  bundledCode: "#line 2 \"dp/partition_function_table.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nvector<T> partition_function_table(int n){\r\n  vector<T> dp(n + 1); dp[0]\
    \ = 1;\r\n  for(int i = 1; i <= n; ++i){\r\n    for(int k = 1, p = 1; i >= k*(3*k\
    \ - 1)/2; ++k, p = -p) dp[i] += dp[i - k*(3*k - 1)/2] * p;\r\n    for(int l =\
    \ 1, p = 1; i >= l*(3*l + 1)/2; ++l, p = -p) dp[i] += dp[i - l*(3*l + 1)/2] *\
    \ p;\r\n  }\r\n  return dp;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nvector<T> partition_function_table(int\
    \ n){\r\n  vector<T> dp(n + 1); dp[0] = 1;\r\n  for(int i = 1; i <= n; ++i){\r\
    \n    for(int k = 1, p = 1; i >= k*(3*k - 1)/2; ++k, p = -p) dp[i] += dp[i - k*(3*k\
    \ - 1)/2] * p;\r\n    for(int l = 1, p = 1; i >= l*(3*l + 1)/2; ++l, p = -p) dp[i]\
    \ += dp[i - l*(3*l + 1)/2] * p;\r\n  }\r\n  return dp;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/partition_function_table.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/partition_function_table.cpp
layout: document
redirect_from:
- /library/dp/partition_function_table.cpp
- /library/dp/partition_function_table.cpp.html
title: dp/partition_function_table.cpp
---
