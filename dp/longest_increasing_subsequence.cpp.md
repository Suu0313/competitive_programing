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
  bundledCode: "#line 2 \"dp/longest_increasing_subsequence.cpp\"\n\r\ntemplate <typename\
    \ T>\r\nvector<T> longest_increasing_subsequence(const vector<T> &a, bool fl =\
    \ true) {\r\n  int n = a.size();\r\n  if(n == 0) return {};\r\n  vector<T> dp(n,\
    \ numeric_limits<T>::max());\r\n  vector<int> idx(n);\r\n  for(int i = 0; i <\
    \ n; i++){\r\n    if(fl) idx[i] = std::distance(dp.begin(), lower_bound(dp.begin(),\
    \ dp.end(), a[i]));\r\n    else idx[i] = std::distance(dp.begin(), upper_bound(dp.begin(),\
    \ dp.end(), a[i]));\r\n    dp[ idx[i] ] = a[i];\r\n  }\r\n  int m = *max_element(idx.begin(),\
    \ idx.end());\r\n  vector<T> res(m+1);\r\n  for(int i = n-1; i >= 0; i--){\r\n\
    \    if(idx[i] == m) res[m--] = a[i];\r\n  }\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename T>\r\nvector<T> longest_increasing_subsequence(const\
    \ vector<T> &a, bool fl = true) {\r\n  int n = a.size();\r\n  if(n == 0) return\
    \ {};\r\n  vector<T> dp(n, numeric_limits<T>::max());\r\n  vector<int> idx(n);\r\
    \n  for(int i = 0; i < n; i++){\r\n    if(fl) idx[i] = std::distance(dp.begin(),\
    \ lower_bound(dp.begin(), dp.end(), a[i]));\r\n    else idx[i] = std::distance(dp.begin(),\
    \ upper_bound(dp.begin(), dp.end(), a[i]));\r\n    dp[ idx[i] ] = a[i];\r\n  }\r\
    \n  int m = *max_element(idx.begin(), idx.end());\r\n  vector<T> res(m+1);\r\n\
    \  for(int i = n-1; i >= 0; i--){\r\n    if(idx[i] == m) res[m--] = a[i];\r\n\
    \  }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/longest_increasing_subsequence.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/longest_increasing_subsequence.cpp
layout: document
redirect_from:
- /library/dp/longest_increasing_subsequence.cpp
- /library/dp/longest_increasing_subsequence.cpp.html
title: dp/longest_increasing_subsequence.cpp
---
