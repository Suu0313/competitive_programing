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
  bundledCode: "#line 2 \"graph/tree/cartesian_tree.cpp\"\n\r\ntemplate<class T, class\
    \ Compair = less<T>>\r\nvector<int> cartesian_tree(const vector<T> &a, const Compair\
    \ &cmp = Compair{}){\r\n  int n = int(a.size());\r\n  vector<int> p(n, -1);\r\n\
    \  stack<int> st;\r\n\r\n  for(int i = 0; i < n; ++i){\r\n    int c = -1;\r\n\
    \    while(!st.empty() && cmp(a[i],  a[st.top()])){\r\n      c = st.top(); st.pop();\r\
    \n    }\r\n    \r\n    if(c != -1) p[c] = i;\r\n    if(!st.empty()) p[i] = st.top();\r\
    \n    st.push(i);\r\n  }\r\n  return p;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<class T, class Compair = less<T>>\r\nvector<int>\
    \ cartesian_tree(const vector<T> &a, const Compair &cmp = Compair{}){\r\n  int\
    \ n = int(a.size());\r\n  vector<int> p(n, -1);\r\n  stack<int> st;\r\n\r\n  for(int\
    \ i = 0; i < n; ++i){\r\n    int c = -1;\r\n    while(!st.empty() && cmp(a[i],\
    \  a[st.top()])){\r\n      c = st.top(); st.pop();\r\n    }\r\n    \r\n    if(c\
    \ != -1) p[c] = i;\r\n    if(!st.empty()) p[i] = st.top();\r\n    st.push(i);\r\
    \n  }\r\n  return p;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/cartesian_tree.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/cartesian_tree.cpp
layout: document
redirect_from:
- /library/graph/tree/cartesian_tree.cpp
- /library/graph/tree/cartesian_tree.cpp.html
title: graph/tree/cartesian_tree.cpp
---
