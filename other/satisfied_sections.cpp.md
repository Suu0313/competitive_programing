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
  bundledCode: "#line 2 \"other/satisfied_sections.cpp\"\n\r\ntemplate<typename T,\
    \ class Compair>\r\nvector<pair<int, int>> satisfied_sections(const vector<T>\
    \ &a, const Compair &cmp){\r\n  int n = int(a.size());\r\n  vector<pair<int, int>>\
    \ res(n);\r\n  stack<int> st;\r\n  for(int i = 0; i < n; ++i){\r\n    while(!st.empty()\
    \ && cmp(a[i], a[st.top()])) st.pop();\r\n    res[i].first = st.empty() ? 0 :\
    \ (st.top() + 1);\r\n    st.push(i);\r\n  }\r\n  \r\n  while(!st.empty()) st.pop();\r\
    \n\r\n  for(int i = n-1; i >= 0; --i){\r\n    while(!st.empty() && cmp(a[i], a[st.top()]))\
    \ st.pop();\r\n    res[i].second = st.empty() ? n : st.top();\r\n    st.push(i);\r\
    \n  }\r\n\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T, class Compair>\r\nvector<pair<int,\
    \ int>> satisfied_sections(const vector<T> &a, const Compair &cmp){\r\n  int n\
    \ = int(a.size());\r\n  vector<pair<int, int>> res(n);\r\n  stack<int> st;\r\n\
    \  for(int i = 0; i < n; ++i){\r\n    while(!st.empty() && cmp(a[i], a[st.top()]))\
    \ st.pop();\r\n    res[i].first = st.empty() ? 0 : (st.top() + 1);\r\n    st.push(i);\r\
    \n  }\r\n  \r\n  while(!st.empty()) st.pop();\r\n\r\n  for(int i = n-1; i >= 0;\
    \ --i){\r\n    while(!st.empty() && cmp(a[i], a[st.top()])) st.pop();\r\n    res[i].second\
    \ = st.empty() ? n : st.top();\r\n    st.push(i);\r\n  }\r\n\r\n  return res;\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/satisfied_sections.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/satisfied_sections.cpp
layout: document
redirect_from:
- /library/other/satisfied_sections.cpp
- /library/other/satisfied_sections.cpp.html
title: other/satisfied_sections.cpp
---
