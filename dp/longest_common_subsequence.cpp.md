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
  bundledCode: "#line 2 \"dp/longest_common_subsequence.cpp\"\n\r\ntemplate <typename\
    \ T>\r\nT longest_common_subsequence(T s, T t){\r\n  int n = s.size(), m = t.size();\r\
    \n  vector dp(n+1, vector(m+1,0));\r\n  for(int i = 0; i < n; i++)for(int j =\
    \ 0; j < m; j++){\r\n    if(s.at(i)==t.at(j)){\r\n      dp.at(i+1).at(j+1)=dp.at(i).at(j)+1;\r\
    \n    }else{\r\n      dp.at(i+1).at(j+1)=max(dp.at(i+1).at(j),dp.at(i).at(j+1));\r\
    \n    }\r\n  }\r\n  T res;\r\n\r\n  for(int i=n,j=m;i>0&&j>0;){\r\n    if(dp.at(i).at(j)==dp.at(i-1).at(j))i--;\r\
    \n    else if(dp.at(i).at(j)==dp.at(i).at(j-1))j--;\r\n    else{\r\n      i--;j--;\r\
    \n      res.push_back(s.at(i));\r\n    }\r\n  }\r\n  reverse(res.begin(), res.end());\r\
    \n  return res;\r\n}\n"
  code: "#pragma once\r\n\r\ntemplate <typename T>\r\nT longest_common_subsequence(T\
    \ s, T t){\r\n  int n = s.size(), m = t.size();\r\n  vector dp(n+1, vector(m+1,0));\r\
    \n  for(int i = 0; i < n; i++)for(int j = 0; j < m; j++){\r\n    if(s.at(i)==t.at(j)){\r\
    \n      dp.at(i+1).at(j+1)=dp.at(i).at(j)+1;\r\n    }else{\r\n      dp.at(i+1).at(j+1)=max(dp.at(i+1).at(j),dp.at(i).at(j+1));\r\
    \n    }\r\n  }\r\n  T res;\r\n\r\n  for(int i=n,j=m;i>0&&j>0;){\r\n    if(dp.at(i).at(j)==dp.at(i-1).at(j))i--;\r\
    \n    else if(dp.at(i).at(j)==dp.at(i).at(j-1))j--;\r\n    else{\r\n      i--;j--;\r\
    \n      res.push_back(s.at(i));\r\n    }\r\n  }\r\n  reverse(res.begin(), res.end());\r\
    \n  return res;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/longest_common_subsequence.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/longest_common_subsequence.cpp
layout: document
redirect_from:
- /library/dp/longest_common_subsequence.cpp
- /library/dp/longest_common_subsequence.cpp.html
title: dp/longest_common_subsequence.cpp
---
