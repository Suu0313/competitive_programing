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
  bundledCode: "#line 2 \"dp/knapsack_limitations.cpp\"\n\r\n\r\ntemplate<typename\
    \ T>\r\nvector<T> knapsack_limitations(const vector<T> &v, const vector<int> &w,\
    \ const vector<int> &m, int W){\r\n  int n = int(v.size());\r\n  vector<T> dp(W+1),\
    \ dqv(W+1);\r\n  vector<int> dqi(W+1);\r\n  vector<bool> seen(W+1, false); seen[0]\
    \ = true;\r\n\r\n  for(int i = 0; i < n; ++i){\r\n    if(w[i] == 0){\r\n     \
    \ for(int j = 0; j <= W; ++j){\r\n        if(seen[j] && dp[j] < dp[j] + v[i] *\
    \ m[i]) dp[j] =  dp[j] + v[i] * m[i];\r\n      }\r\n    }else{\r\n      for(int\
    \ a = 0; a < w[i]; ++a){\r\n        int s = 0, t = 0;\r\n        for(int j = 0;\
    \ w[i]*j + a <= W; ++j){\r\n          if(seen[w[i]*j + a]){\r\n            auto\
    \ val = dp[w[i]*j + a] - v[i] * j;\r\n            while(s < t && dqv[t-1] < val)\
    \ --t;\r\n            dqv[t] = val; dqi[t++] = j;\r\n          }\r\n         \
    \ if(s < t){\r\n            dp[j*w[i] + a] = dqv[s] + v[i] * j;\r\n          \
    \  seen[j*w[i] + a] = true;\r\n            if(dqi[s] == j-m[i]) ++s;\r\n     \
    \     }\r\n        }\r\n      }\r\n    }\r\n  }\r\n  return dp;\r\n}\r\n"
  code: "#pragma once\r\n\r\n\r\ntemplate<typename T>\r\nvector<T> knapsack_limitations(const\
    \ vector<T> &v, const vector<int> &w, const vector<int> &m, int W){\r\n  int n\
    \ = int(v.size());\r\n  vector<T> dp(W+1), dqv(W+1);\r\n  vector<int> dqi(W+1);\r\
    \n  vector<bool> seen(W+1, false); seen[0] = true;\r\n\r\n  for(int i = 0; i <\
    \ n; ++i){\r\n    if(w[i] == 0){\r\n      for(int j = 0; j <= W; ++j){\r\n   \
    \     if(seen[j] && dp[j] < dp[j] + v[i] * m[i]) dp[j] =  dp[j] + v[i] * m[i];\r\
    \n      }\r\n    }else{\r\n      for(int a = 0; a < w[i]; ++a){\r\n        int\
    \ s = 0, t = 0;\r\n        for(int j = 0; w[i]*j + a <= W; ++j){\r\n         \
    \ if(seen[w[i]*j + a]){\r\n            auto val = dp[w[i]*j + a] - v[i] * j;\r\
    \n            while(s < t && dqv[t-1] < val) --t;\r\n            dqv[t] = val;\
    \ dqi[t++] = j;\r\n          }\r\n          if(s < t){\r\n            dp[j*w[i]\
    \ + a] = dqv[s] + v[i] * j;\r\n            seen[j*w[i] + a] = true;\r\n      \
    \      if(dqi[s] == j-m[i]) ++s;\r\n          }\r\n        }\r\n      }\r\n  \
    \  }\r\n  }\r\n  return dp;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/knapsack_limitations.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/knapsack_limitations.cpp
layout: document
redirect_from:
- /library/dp/knapsack_limitations.cpp
- /library/dp/knapsack_limitations.cpp.html
title: dp/knapsack_limitations.cpp
---
