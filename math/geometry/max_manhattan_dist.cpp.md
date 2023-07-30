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
  bundledCode: "#line 2 \"math/geometry/max_manhattan_dist.cpp\"\n\r\ntemplate<typename\
    \ T> // n\u500B,k\u6B21\u5143\u306E\u70B9\r\nT max_manhattan_distance(vector<vector<T>>\
    \ &v){\r\n  int n = v.size();\r\n  int k = v[0].size();\r\n  T res = 0;\r\n  vector<T>\
    \ f(n);\r\n\r\n  for(int bit = 0; bit < (1 << (k-1)); bit++){\r\n    for(int j\
    \ = 0; j < n; j++){\r\n      f.at(j) = v.at(j).at(0);\r\n      for(int i = 0;\
    \ i < k-1; i++){\r\n        if((bit>>i)&1){\r\n          f.at(j) += v.at(j).at(i+1);\r\
    \n        }else{\r\n          f.at(j) -= v.at(j).at(i+1);\r\n        }\r\n   \
    \   }\r\n    }\r\n    res = max(res, max(f) - min(f));\r\n  }\r\n  return res;\r\
    \n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T> // n\u500B,k\u6B21\u5143\u306E\u70B9\
    \r\nT max_manhattan_distance(vector<vector<T>> &v){\r\n  int n = v.size();\r\n\
    \  int k = v[0].size();\r\n  T res = 0;\r\n  vector<T> f(n);\r\n\r\n  for(int\
    \ bit = 0; bit < (1 << (k-1)); bit++){\r\n    for(int j = 0; j < n; j++){\r\n\
    \      f.at(j) = v.at(j).at(0);\r\n      for(int i = 0; i < k-1; i++){\r\n   \
    \     if((bit>>i)&1){\r\n          f.at(j) += v.at(j).at(i+1);\r\n        }else{\r\
    \n          f.at(j) -= v.at(j).at(i+1);\r\n        }\r\n      }\r\n    }\r\n \
    \   res = max(res, max(f) - min(f));\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/geometry/max_manhattan_dist.cpp
  requiredBy: []
  timestamp: '2023-02-10 15:04:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/geometry/max_manhattan_dist.cpp
layout: document
redirect_from:
- /library/math/geometry/max_manhattan_dist.cpp
- /library/math/geometry/max_manhattan_dist.cpp.html
title: math/geometry/max_manhattan_dist.cpp
---
