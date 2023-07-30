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
  bundledCode: "#line 2 \"math/convert_base.cpp\"\n\r\ntemplate<typename T, typename\
    \ T2>\r\nvector<T> convert_base_10tob(T x, T2 b) {\r\n  vector<T> ret;\r\n  T\
    \ t = 1, k = abs(b);\r\n  while(x) {\r\n    ret.emplace_back((x * t) % k);\r\n\
    \    if(ret.back() < 0) ret.back() += k;\r\n    x -= ret.back() * t;\r\n    x\
    \ /= k; t *= b / k;\r\n  }\r\n  if(ret.empty()) ret.emplace_back(0);\r\n  reverse(begin(ret),\
    \ end(ret));\r\n  return ret;\r\n}\r\n\r\ntemplate<typename T, typename T2>\r\n\
    T convert_base_bto10(const vector<T> &a, T2 b) {\r\n  T ret = 0;\r\n  for(auto&e\
    \ : a) (ret *= b) += e;\r\n  return ret;\r\n}\r\n\r\ntemplate<typename T = int>\r\
    \nvector<T> stov(const string &s, char c = '0'){\r\n  int n = int(s.size());\r\
    \n  vector<T> res(n);\r\n  for(int i = 0; i < n; ++i) res[i] = s[i] - c;\r\n \
    \ return res;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T, typename T2>\r\nvector<T> convert_base_10tob(T\
    \ x, T2 b) {\r\n  vector<T> ret;\r\n  T t = 1, k = abs(b);\r\n  while(x) {\r\n\
    \    ret.emplace_back((x * t) % k);\r\n    if(ret.back() < 0) ret.back() += k;\r\
    \n    x -= ret.back() * t;\r\n    x /= k; t *= b / k;\r\n  }\r\n  if(ret.empty())\
    \ ret.emplace_back(0);\r\n  reverse(begin(ret), end(ret));\r\n  return ret;\r\n\
    }\r\n\r\ntemplate<typename T, typename T2>\r\nT convert_base_bto10(const vector<T>\
    \ &a, T2 b) {\r\n  T ret = 0;\r\n  for(auto&e : a) (ret *= b) += e;\r\n  return\
    \ ret;\r\n}\r\n\r\ntemplate<typename T = int>\r\nvector<T> stov(const string &s,\
    \ char c = '0'){\r\n  int n = int(s.size());\r\n  vector<T> res(n);\r\n  for(int\
    \ i = 0; i < n; ++i) res[i] = s[i] - c;\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/convert_base.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/convert_base.cpp
layout: document
redirect_from:
- /library/math/convert_base.cpp
- /library/math/convert_base.cpp.html
title: math/convert_base.cpp
---
