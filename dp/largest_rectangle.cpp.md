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
  bundledCode: "#line 2 \"dp/largest_rectangle.cpp\"\n\r\ntemplate<typename T>\r\n\
    T largest_rectangle(vector<T> height){\r\n  stack<int> st;\r\n  height.push_back(0);\r\
    \n  vector<int> left(height.size());\r\n  T res = 0;\r\n  for(int i = 0; i < int(height.size());\
    \ i++) {\r\n    while(!st.empty() && height[st.top()] >= height[i]) {\r\n    \
    \  res = max(res, (i - left[st.top()] - 1) * height[st.top()]);\r\n      st.pop();\r\
    \n    }\r\n    left[i] = st.empty() ? -1 : st.top();\r\n    st.emplace(i);\r\n\
    \  }\r\n  return res;\r\n}\r\n\r\ntemplate<typename T>\r\nint largest_rectangle(const\
    \ vector<vector<T>> &tl){\r\n  int w = int(tl[0].size());\r\n  vector<int> dp(w);\r\
    \n  int ans = 0;\r\n  for(auto&&v : tl){\r\n    for(int i = 0; i < w; ++i){\r\n\
    \      if(v[i]) dp[i] = 0;\r\n      else ++dp[i];\r\n    }\r\n    ans = max(ans,\
    \ largest_rectangle(dp));\r\n  }\r\n  return ans;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nT largest_rectangle(vector<T>\
    \ height){\r\n  stack<int> st;\r\n  height.push_back(0);\r\n  vector<int> left(height.size());\r\
    \n  T res = 0;\r\n  for(int i = 0; i < int(height.size()); i++) {\r\n    while(!st.empty()\
    \ && height[st.top()] >= height[i]) {\r\n      res = max(res, (i - left[st.top()]\
    \ - 1) * height[st.top()]);\r\n      st.pop();\r\n    }\r\n    left[i] = st.empty()\
    \ ? -1 : st.top();\r\n    st.emplace(i);\r\n  }\r\n  return res;\r\n}\r\n\r\n\
    template<typename T>\r\nint largest_rectangle(const vector<vector<T>> &tl){\r\n\
    \  int w = int(tl[0].size());\r\n  vector<int> dp(w);\r\n  int ans = 0;\r\n  for(auto&&v\
    \ : tl){\r\n    for(int i = 0; i < w; ++i){\r\n      if(v[i]) dp[i] = 0;\r\n \
    \     else ++dp[i];\r\n    }\r\n    ans = max(ans, largest_rectangle(dp));\r\n\
    \  }\r\n  return ans;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/largest_rectangle.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/largest_rectangle.cpp
layout: document
redirect_from:
- /library/dp/largest_rectangle.cpp
- /library/dp/largest_rectangle.cpp.html
title: dp/largest_rectangle.cpp
---
