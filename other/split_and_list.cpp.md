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
  bundledCode: "#line 2 \"other/split_and_list.cpp\"\n\r\ntemplate<typename T, class\
    \ Operator, class Compair>\r\npair<vector<T>, vector<T>> split_and_list(const\
    \ vector<T> &a, const T &e, const Operator &op, const Compair &cmp){\r\n  vector<T>\
    \ b(1, e), c(1, e);\r\n\r\n  for(auto&&x : a){\r\n    int n = int(b.size());\r\
    \n    b.reserve(n * 2);\r\n    for(int i = 0; i < n; ++i) b.push_back(op(b[i],\
    \ x));\r\n    inplace_merge(begin(b), begin(b) + n, end(b), cmp);\r\n    swap(b,\
    \ c);\r\n  }\r\n\r\n  return {b, c};\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T, class Operator, class Compair>\r\
    \npair<vector<T>, vector<T>> split_and_list(const vector<T> &a, const T &e, const\
    \ Operator &op, const Compair &cmp){\r\n  vector<T> b(1, e), c(1, e);\r\n\r\n\
    \  for(auto&&x : a){\r\n    int n = int(b.size());\r\n    b.reserve(n * 2);\r\n\
    \    for(int i = 0; i < n; ++i) b.push_back(op(b[i], x));\r\n    inplace_merge(begin(b),\
    \ begin(b) + n, end(b), cmp);\r\n    swap(b, c);\r\n  }\r\n\r\n  return {b, c};\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/split_and_list.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/split_and_list.cpp
layout: document
redirect_from:
- /library/other/split_and_list.cpp
- /library/other/split_and_list.cpp.html
title: other/split_and_list.cpp
---
