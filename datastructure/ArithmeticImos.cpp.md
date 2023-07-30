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
  bundledCode: "#line 2 \"datastructure/ArithmeticImos.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct ArithmeticImos{\r\n  int n, k;\r\n  vector<vector<pair<int, T>>>\
    \ query;\r\n\r\n  ArithmeticImos() = default;\r\n  ArithmeticImos(int n, int k):\
    \ n(n), k(k), query(n + 1) {}\r\n\r\n  void add(int l, int r, const T &x){\r\n\
    \    query[l].emplace_back(0, x);\r\n    query[r].emplace_back(r - l, -x);\r\n\
    \  }\r\n\r\n  vector<T> build(vector<T> a, vector<T> c){\r\n    a.resize(n + k);\r\
    \n    for(int i = 0; i < n; ++i){\r\n      for(int j = 0; j < k; ++j){\r\n   \
    \     a[i + k] += a[i + j] * c[j];\r\n      }\r\n    }\r\n\r\n    vector<T> s(k),\
    \ res(n);\r\n    for(int i = 0; i < n; ++i){\r\n      T t = 0;\r\n      for(int\
    \ j = 0; j < k; ++j) t += s[j] * c[j];\r\n      s.erase(begin(s)); s.push_back(t);\r\
    \n\r\n      for(auto[l, x] : query[i]){\r\n        for(int j = 0; j < k; ++j)\
    \ s[j] += a[l + j] * x;\r\n      }\r\n\r\n      res[i] = s[0];\r\n    }\r\n  \
    \  return res;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct ArithmeticImos{\r\n  int\
    \ n, k;\r\n  vector<vector<pair<int, T>>> query;\r\n\r\n  ArithmeticImos() = default;\r\
    \n  ArithmeticImos(int n, int k): n(n), k(k), query(n + 1) {}\r\n\r\n  void add(int\
    \ l, int r, const T &x){\r\n    query[l].emplace_back(0, x);\r\n    query[r].emplace_back(r\
    \ - l, -x);\r\n  }\r\n\r\n  vector<T> build(vector<T> a, vector<T> c){\r\n   \
    \ a.resize(n + k);\r\n    for(int i = 0; i < n; ++i){\r\n      for(int j = 0;\
    \ j < k; ++j){\r\n        a[i + k] += a[i + j] * c[j];\r\n      }\r\n    }\r\n\
    \r\n    vector<T> s(k), res(n);\r\n    for(int i = 0; i < n; ++i){\r\n      T\
    \ t = 0;\r\n      for(int j = 0; j < k; ++j) t += s[j] * c[j];\r\n      s.erase(begin(s));\
    \ s.push_back(t);\r\n\r\n      for(auto[l, x] : query[i]){\r\n        for(int\
    \ j = 0; j < k; ++j) s[j] += a[l + j] * x;\r\n      }\r\n\r\n      res[i] = s[0];\r\
    \n    }\r\n    return res;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/ArithmeticImos.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/ArithmeticImos.cpp
layout: document
redirect_from:
- /library/datastructure/ArithmeticImos.cpp
- /library/datastructure/ArithmeticImos.cpp.html
title: datastructure/ArithmeticImos.cpp
---
