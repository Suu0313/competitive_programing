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
  bundledCode: "#line 2 \"dp/subset_sum.cpp\"\n\r\nvector<int> subset_sum(const vector<int>\
    \ &a, int x){\r\n  int n = int(a.size()), s = 0;\r\n  vector<int> b(a), d(n),\
    \ idx(n);\r\n  for(auto&e : b){\r\n    if(e < 0) x -= e;\r\n    e = abs(e);\r\n\
    \    s += e;\r\n  }\r\n  if(x < 0 || s < x) return {};\r\n  bool flip = (x*2 <\
    \ s);\r\n  if(flip) x = s - x;\r\n  iota(begin(idx), end(idx), 0);\r\n  sort(begin(idx),\
    \ end(idx), [&](int i, int j){ return b[i] < b[j]; });\r\n  for(int i = 0; i <\
    \ n; ++i) d[i] = b[idx[i]];\r\n  int m = d[n-1], m2 = m*2 + 1, si = 0;\r\n  while(x\
    \ > 0 && si < n) x -= d[si++];\r\n  \r\n  // dp[i][j][k] = si\u3088\u308A\u53F3\
    i\u500B\u3068\u5DE6j\u500B\u3067\u548C\u304Ck\u306B\u306A\u308B\u3088\u3046\u306B\
    \u3067\u304D\u308B\u304B\r\n  // \u305F\u3060\u3057 |x-k| < m\r\n\r\n  // i,k\u304C\
    \u540C\u3058\u306A\u3089j\u306Ftrue\u306E\u4E2D\u3067\u6700\u3082\u5DE6\u306E\u3082\
    \u306E\u3092\u9078\u3076\u306E\u304C\u6700\u9069\u306A\u306E\u3067\r\n  // dp[i][k]\
    \ = min(j)\r\n\r\n  vector<vector<int>> dp(n-si+1, vector<int>(m2, si+1));\r\n\
    \  dp[0][m+x] = 0;\r\n\r\n  for(int i = si; i <= n; ++i){\r\n    /*\r\n    \u307E\
    \u305Ai\u306F\u305D\u306E\u307E\u307Ej\u306E\u9078\u629E \u4ECA\u306Ej\u3092\u4F7F\
    \u3063\u3066\u3088\u308A\u3088\u304F\u3067\u304D\u308B\u306A\u3089\u66F4\u65B0\
    \r\n    \u4E0B\u304B\u3089\u56DE\u3057\u3066\u7D2F\u7A4D\u7684\u306B\u66F4\u65B0\
    \u3059\u308B\r\n    //*/\r\n    for(int k = 0; k < m; ++k) if(dp[i-si][k] != si+1){\r\
    \n      int r = min(si, (i>si) ? dp[i-1-si][k] : si);\r\n      for(int j = dp[i-si][k];\
    \ j < r; ++j){\r\n        dp[i-si][k+d[j]] = min(dp[i-si][k+d[j]], j+1);\r\n \
    \     }\r\n    }\r\n    // early return\r\n    if(dp[i-si][m] != si+1){\r\n  \
    \    vector<int> buf(n), res(n); fill(begin(buf), begin(buf)+si, 1);\r\n\r\n \
    \     for(int k = m; i != si || k != m+x; ){\r\n        int j = dp[i-si][k] -\
    \ 1;\r\n        if(j>=0 && k>=d[j] && dp[i-si][k-d[j]] <= j){\r\n          buf[j]\
    \ = 0; k -= d[j];\r\n        }else{\r\n          --i;\r\n          if(dp[i-si][k]\
    \ != j + 1){\r\n            buf[i] = 1; k += d[i];\r\n          }\r\n        }\r\
    \n      }\r\n      for(int t = 0; t < n; ++t){\r\n        res[idx[t]] = buf[t]\
    \ ^ flip ^ (a[idx[t]] < 0);\r\n      }\r\n      return res;\r\n    }\r\n\r\n \
    \   if(i < n){\r\n      // i\u3092\u4F7F\u3063\u3066\u9032\u3081\u308B (\u5143\
    \u3005\u4F7F\u3063\u3066\u3053\u3068\u306B\u3057\u3066\u3042\u308B\u306E\u3067\
    \u305D\u306E\u307E\u307E)\r\n      for(int k = 0; k < m2; ++k){\r\n        dp[i+1-si][k]\
    \ = min(dp[i+1-si][k], dp[i-si][k]);\r\n      }\r\n      // i\u3092\u4F7F\u308F\
    \u305A\u9032\u3081\u308B (m\u672A\u6E80\u304B\u3089\u3055\u3089\u306B\u6E1B\u3089\
    \u3059\u306E\u306F\u7981\u6B62)\r\n      for(int k = m; k < m2; ++k){\r\n    \
    \    dp[i+1-si][k-d[i]] = min(dp[i+1-si][k-d[i]], dp[i-si][k]);\r\n      }\r\n\
    \    }\r\n  }\r\n  return {};\r\n}\r\n\r\nvector<int> pm_sum(const vector<int>\
    \ &a, int x){\r\n  // sum (-1)^t ai = x\r\n  for(auto&e : a) x += e;\r\n  if(x\
    \ & 1) return {};\r\n  return subset_sum(a, x >> 1);\r\n}\r\n"
  code: "#pragma once\r\n\r\nvector<int> subset_sum(const vector<int> &a, int x){\r\
    \n  int n = int(a.size()), s = 0;\r\n  vector<int> b(a), d(n), idx(n);\r\n  for(auto&e\
    \ : b){\r\n    if(e < 0) x -= e;\r\n    e = abs(e);\r\n    s += e;\r\n  }\r\n\
    \  if(x < 0 || s < x) return {};\r\n  bool flip = (x*2 < s);\r\n  if(flip) x =\
    \ s - x;\r\n  iota(begin(idx), end(idx), 0);\r\n  sort(begin(idx), end(idx), [&](int\
    \ i, int j){ return b[i] < b[j]; });\r\n  for(int i = 0; i < n; ++i) d[i] = b[idx[i]];\r\
    \n  int m = d[n-1], m2 = m*2 + 1, si = 0;\r\n  while(x > 0 && si < n) x -= d[si++];\r\
    \n  \r\n  // dp[i][j][k] = si\u3088\u308A\u53F3i\u500B\u3068\u5DE6j\u500B\u3067\
    \u548C\u304Ck\u306B\u306A\u308B\u3088\u3046\u306B\u3067\u304D\u308B\u304B\r\n\
    \  // \u305F\u3060\u3057 |x-k| < m\r\n\r\n  // i,k\u304C\u540C\u3058\u306A\u3089\
    j\u306Ftrue\u306E\u4E2D\u3067\u6700\u3082\u5DE6\u306E\u3082\u306E\u3092\u9078\u3076\
    \u306E\u304C\u6700\u9069\u306A\u306E\u3067\r\n  // dp[i][k] = min(j)\r\n\r\n \
    \ vector<vector<int>> dp(n-si+1, vector<int>(m2, si+1));\r\n  dp[0][m+x] = 0;\r\
    \n\r\n  for(int i = si; i <= n; ++i){\r\n    /*\r\n    \u307E\u305Ai\u306F\u305D\
    \u306E\u307E\u307Ej\u306E\u9078\u629E \u4ECA\u306Ej\u3092\u4F7F\u3063\u3066\u3088\
    \u308A\u3088\u304F\u3067\u304D\u308B\u306A\u3089\u66F4\u65B0\r\n    \u4E0B\u304B\
    \u3089\u56DE\u3057\u3066\u7D2F\u7A4D\u7684\u306B\u66F4\u65B0\u3059\u308B\r\n \
    \   //*/\r\n    for(int k = 0; k < m; ++k) if(dp[i-si][k] != si+1){\r\n      int\
    \ r = min(si, (i>si) ? dp[i-1-si][k] : si);\r\n      for(int j = dp[i-si][k];\
    \ j < r; ++j){\r\n        dp[i-si][k+d[j]] = min(dp[i-si][k+d[j]], j+1);\r\n \
    \     }\r\n    }\r\n    // early return\r\n    if(dp[i-si][m] != si+1){\r\n  \
    \    vector<int> buf(n), res(n); fill(begin(buf), begin(buf)+si, 1);\r\n\r\n \
    \     for(int k = m; i != si || k != m+x; ){\r\n        int j = dp[i-si][k] -\
    \ 1;\r\n        if(j>=0 && k>=d[j] && dp[i-si][k-d[j]] <= j){\r\n          buf[j]\
    \ = 0; k -= d[j];\r\n        }else{\r\n          --i;\r\n          if(dp[i-si][k]\
    \ != j + 1){\r\n            buf[i] = 1; k += d[i];\r\n          }\r\n        }\r\
    \n      }\r\n      for(int t = 0; t < n; ++t){\r\n        res[idx[t]] = buf[t]\
    \ ^ flip ^ (a[idx[t]] < 0);\r\n      }\r\n      return res;\r\n    }\r\n\r\n \
    \   if(i < n){\r\n      // i\u3092\u4F7F\u3063\u3066\u9032\u3081\u308B (\u5143\
    \u3005\u4F7F\u3063\u3066\u3053\u3068\u306B\u3057\u3066\u3042\u308B\u306E\u3067\
    \u305D\u306E\u307E\u307E)\r\n      for(int k = 0; k < m2; ++k){\r\n        dp[i+1-si][k]\
    \ = min(dp[i+1-si][k], dp[i-si][k]);\r\n      }\r\n      // i\u3092\u4F7F\u308F\
    \u305A\u9032\u3081\u308B (m\u672A\u6E80\u304B\u3089\u3055\u3089\u306B\u6E1B\u3089\
    \u3059\u306E\u306F\u7981\u6B62)\r\n      for(int k = m; k < m2; ++k){\r\n    \
    \    dp[i+1-si][k-d[i]] = min(dp[i+1-si][k-d[i]], dp[i-si][k]);\r\n      }\r\n\
    \    }\r\n  }\r\n  return {};\r\n}\r\n\r\nvector<int> pm_sum(const vector<int>\
    \ &a, int x){\r\n  // sum (-1)^t ai = x\r\n  for(auto&e : a) x += e;\r\n  if(x\
    \ & 1) return {};\r\n  return subset_sum(a, x >> 1);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/subset_sum.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/subset_sum.cpp
layout: document
redirect_from:
- /library/dp/subset_sum.cpp
- /library/dp/subset_sum.cpp.html
title: dp/subset_sum.cpp
---
