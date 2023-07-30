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
  bundledCode: "#line 2 \"math/Kitamasa.cpp\"\n\r\ntemplate<typename T>\r\nstruct\
    \ Kitamasa{\r\n  const int k;\r\n  const vector<T> a, c;\r\n  const T e, id;\r\
    \n  Kitamasa(const vector<T> &a, const vector<T> &c, const T &e = 1, const T &id\
    \ = 0): k(a.size()), a(a), c(c), e(e), id(id) {}\r\n\r\n  T solve(long long n){\r\
    \n    T res = id;\r\n    auto d = cal(n);\r\n    for(int i = 0; i < k; i++) res\
    \ += d[i] * a[i];\r\n    return res;\r\n  }\r\n\r\nprivate:\r\n  vector<T> p1(const\
    \ vector<T> &x){\r\n    vector<T> res(k, id);\r\n    res[0] = x[k-1] * c[0];\r\
    \n    for(int i = 1; i < k; i++){\r\n      res[i] = x[i-1] + (x[k-1] * c[i]);\r\
    \n    }\r\n    return res;\r\n  }\r\n\r\n  vector<T> sq(const vector<T> &x){\r\
    \n    vector<T> res(k, id);\r\n    auto d = x;\r\n    for(int i = 0; i < k; i++){\r\
    \n      for(int j = 0; j < k; j++){\r\n        res[j] += x[i] * d[j];\r\n    \
    \  }\r\n      d = p1(d);\r\n    }\r\n    return res;\r\n  }\r\n\r\n  vector<T>\
    \ cal(long long n){\r\n    vector<T> res(k, id); res[0] = e;\r\n    \r\n    for(int\
    \ i = 62; i >= 0; i--){\r\n      res = sq(res);\r\n      if(n & (1ll << i)) res\
    \ = p1(res);\r\n    }\r\n    return res;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct Kitamasa{\r\n  const int\
    \ k;\r\n  const vector<T> a, c;\r\n  const T e, id;\r\n  Kitamasa(const vector<T>\
    \ &a, const vector<T> &c, const T &e = 1, const T &id = 0): k(a.size()), a(a),\
    \ c(c), e(e), id(id) {}\r\n\r\n  T solve(long long n){\r\n    T res = id;\r\n\
    \    auto d = cal(n);\r\n    for(int i = 0; i < k; i++) res += d[i] * a[i];\r\n\
    \    return res;\r\n  }\r\n\r\nprivate:\r\n  vector<T> p1(const vector<T> &x){\r\
    \n    vector<T> res(k, id);\r\n    res[0] = x[k-1] * c[0];\r\n    for(int i =\
    \ 1; i < k; i++){\r\n      res[i] = x[i-1] + (x[k-1] * c[i]);\r\n    }\r\n   \
    \ return res;\r\n  }\r\n\r\n  vector<T> sq(const vector<T> &x){\r\n    vector<T>\
    \ res(k, id);\r\n    auto d = x;\r\n    for(int i = 0; i < k; i++){\r\n      for(int\
    \ j = 0; j < k; j++){\r\n        res[j] += x[i] * d[j];\r\n      }\r\n      d\
    \ = p1(d);\r\n    }\r\n    return res;\r\n  }\r\n\r\n  vector<T> cal(long long\
    \ n){\r\n    vector<T> res(k, id); res[0] = e;\r\n    \r\n    for(int i = 62;\
    \ i >= 0; i--){\r\n      res = sq(res);\r\n      if(n & (1ll << i)) res = p1(res);\r\
    \n    }\r\n    return res;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/Kitamasa.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/Kitamasa.cpp
layout: document
redirect_from:
- /library/math/Kitamasa.cpp
- /library/math/Kitamasa.cpp.html
title: math/Kitamasa.cpp
---
