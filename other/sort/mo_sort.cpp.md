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
  bundledCode: "#line 2 \"other/sort/mo_sort.cpp\"\n\r\nvector<int> mo_sort(int n,\
    \ int q, const vector<int> &l, const vector<int> &r){\r\n  vector<int> idx(q);\
    \ iota(begin(idx), end(idx), 0);\r\n  int d = max<int>(1, n/max<double>(1.0, sqrt(q*2.0/3.0)));\r\
    \n  sort(begin(idx), end(idx), [&](int i, int j){\r\n    if(l[i]/d != l[j]/d)\
    \ return l[i] < l[j];\r\n    else return ((l[i]/d)%2 ? (r[i] < r[j]) : (r[i] >\
    \ r[j]));\r\n  });\r\n  return idx;\r\n}\r\n"
  code: "#pragma once\r\n\r\nvector<int> mo_sort(int n, int q, const vector<int> &l,\
    \ const vector<int> &r){\r\n  vector<int> idx(q); iota(begin(idx), end(idx), 0);\r\
    \n  int d = max<int>(1, n/max<double>(1.0, sqrt(q*2.0/3.0)));\r\n  sort(begin(idx),\
    \ end(idx), [&](int i, int j){\r\n    if(l[i]/d != l[j]/d) return l[i] < l[j];\r\
    \n    else return ((l[i]/d)%2 ? (r[i] < r[j]) : (r[i] > r[j]));\r\n  });\r\n \
    \ return idx;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/sort/mo_sort.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/sort/mo_sort.cpp
layout: document
redirect_from:
- /library/other/sort/mo_sort.cpp
- /library/other/sort/mo_sort.cpp.html
title: other/sort/mo_sort.cpp
---
