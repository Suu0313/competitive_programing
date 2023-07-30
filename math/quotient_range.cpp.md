---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: x in [l, r),  n // x = d, O(sqrt(n))
    links: []
  bundledCode: "#line 2 \"math/quotient_range.cpp\"\n\r\n/**\r\n * @brief x in [l,\
    \ r),  n // x = d, O(sqrt(n))\r\n * \r\n * @tparam T \r\n * @param n \r\n * @return\
    \ vector<tuple<T, T, T>> (l, r, d)\r\n */\r\ntemplate<typename T>\r\nvector<tuple<T,\
    \ T, T>> quotient_range(T n){\r\n  vector<tuple<T, T, T>> res;\r\n  T l = 1;\r\
    \n  while(l <= n){\r\n    T d = n/l, r = n/d + 1;\r\n    res.emplace_back(l, r,\
    \ d);\r\n    l = r;\r\n  }\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n\r\n/**\r\n * @brief x in [l, r),  n // x = d, O(sqrt(n))\r\
    \n * \r\n * @tparam T \r\n * @param n \r\n * @return vector<tuple<T, T, T>> (l,\
    \ r, d)\r\n */\r\ntemplate<typename T>\r\nvector<tuple<T, T, T>> quotient_range(T\
    \ n){\r\n  vector<tuple<T, T, T>> res;\r\n  T l = 1;\r\n  while(l <= n){\r\n \
    \   T d = n/l, r = n/d + 1;\r\n    res.emplace_back(l, r, d);\r\n    l = r;\r\n\
    \  }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/quotient_range.cpp
  requiredBy: []
  timestamp: '2023-05-13 03:14:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/quotient_range.cpp
layout: document
redirect_from:
- /library/math/quotient_range.cpp
- /library/math/quotient_range.cpp.html
title: x in [l, r),  n // x = d, O(sqrt(n))
---
