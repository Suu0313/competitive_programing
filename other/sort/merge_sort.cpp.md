---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: datastructure/fenwicktree/StaticRangeInversionsQuery.cpp
    title: datastructure/fenwicktree/StaticRangeInversionsQuery.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/sort/merge_sort.cpp\"\n\r\ntemplate<typename T>\r\n\
    long long merge_sort(vector<T> &a){\r\n  int n = int(a.size());\r\n  long long\
    \ inv = 0;\r\n\r\n  vector<T> b(n);\r\n  for(int len = 1; len < n; len *= 2){\r\
    \n    for(int l=0,m=len,r=min(len*2,n),i=0; l<n; l=r,m=min(l+len,n),r=min(m+len,n)){\r\
    \n      for(int p = l, q = m; p < m || q < r; ){\r\n        if(p == m){\r\n  \
    \        while(q < r) b[i++] = a[q++];\r\n          break;\r\n        }\r\n  \
    \      if(q == r){\r\n          while(p < m) b[i++] = a[p++];\r\n          break;\r\
    \n        }\r\n\r\n        if(a[p] > a[q]){\r\n          b[i++] = a[q++]; inv\
    \ += m - p;\r\n        }else{\r\n          b[i++] = a[p++];\r\n        }\r\n \
    \     }\r\n    }\r\n    swap(a, b);\r\n  }\r\n\r\n  return inv;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nlong long merge_sort(vector<T>\
    \ &a){\r\n  int n = int(a.size());\r\n  long long inv = 0;\r\n\r\n  vector<T>\
    \ b(n);\r\n  for(int len = 1; len < n; len *= 2){\r\n    for(int l=0,m=len,r=min(len*2,n),i=0;\
    \ l<n; l=r,m=min(l+len,n),r=min(m+len,n)){\r\n      for(int p = l, q = m; p <\
    \ m || q < r; ){\r\n        if(p == m){\r\n          while(q < r) b[i++] = a[q++];\r\
    \n          break;\r\n        }\r\n        if(q == r){\r\n          while(p <\
    \ m) b[i++] = a[p++];\r\n          break;\r\n        }\r\n\r\n        if(a[p]\
    \ > a[q]){\r\n          b[i++] = a[q++]; inv += m - p;\r\n        }else{\r\n \
    \         b[i++] = a[p++];\r\n        }\r\n      }\r\n    }\r\n    swap(a, b);\r\
    \n  }\r\n\r\n  return inv;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/sort/merge_sort.cpp
  requiredBy:
  - datastructure/fenwicktree/StaticRangeInversionsQuery.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/sort/merge_sort.cpp
layout: document
redirect_from:
- /library/other/sort/merge_sort.cpp
- /library/other/sort/merge_sort.cpp.html
title: other/sort/merge_sort.cpp
---
