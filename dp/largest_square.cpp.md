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
  bundledCode: "#line 2 \"dp/largest_square.cpp\"\n\r\ntemplate<typename T>\r\nint\
    \ largest_square(const vector<vector<T>> &tl){\r\n  int h = int(tl.size()), w\
    \ = int(tl[0].size());\r\n  vector<int> dp(w);\r\n  for(int i = 0; i < w; ++i)\
    \ dp[i] = !tl[0][i];\r\n  int ans = *max_element(begin(dp), end(dp));\r\n\r\n\
    \  for(int i = 1; i < h; ++i){\r\n    vector<int> ndp(w); swap(dp, ndp);\r\n \
    \   dp[0] = !tl[i][0];\r\n    for(int j = 1; j < w; ++j){\r\n      if(tl[i][j])\
    \ continue;\r\n      dp[j] = min({dp[j-1], ndp[j], ndp[j-1]}) + 1;\r\n    }\r\n\
    \    ans = max(ans, *max_element(begin(dp), end(dp)));\r\n  }\r\n  return ans;\r\
    \n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nint largest_square(const vector<vector<T>>\
    \ &tl){\r\n  int h = int(tl.size()), w = int(tl[0].size());\r\n  vector<int> dp(w);\r\
    \n  for(int i = 0; i < w; ++i) dp[i] = !tl[0][i];\r\n  int ans = *max_element(begin(dp),\
    \ end(dp));\r\n\r\n  for(int i = 1; i < h; ++i){\r\n    vector<int> ndp(w); swap(dp,\
    \ ndp);\r\n    dp[0] = !tl[i][0];\r\n    for(int j = 1; j < w; ++j){\r\n     \
    \ if(tl[i][j]) continue;\r\n      dp[j] = min({dp[j-1], ndp[j], ndp[j-1]}) + 1;\r\
    \n    }\r\n    ans = max(ans, *max_element(begin(dp), end(dp)));\r\n  }\r\n  return\
    \ ans;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/largest_square.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/largest_square.cpp
layout: document
redirect_from:
- /library/dp/largest_square.cpp
- /library/dp/largest_square.cpp.html
title: dp/largest_square.cpp
---
