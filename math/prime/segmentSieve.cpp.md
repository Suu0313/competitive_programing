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
  bundledCode: "#line 2 \"math/prime/segmentSieve.cpp\"\n\r\nstruct segmentSieve{\r\
    \n  int64_t l, r, m;\r\n  vector<int> small;\r\n  vector<vector<int64_t>> large;\r\
    \n  vector<int64_t> aux;\r\n\r\n  segmentSieve(int64_t l, int64_t r): l(l), r(r),\
    \ m(sqrt(r)+1), small(m), large(r-l), aux(r-l, 1) {\r\n    iota(small.begin(),\
    \ small.end(), 0);\r\n    \r\n    for(int64_t i = 2; i*i < r; ++i){\r\n      if(small[i]\
    \ < i) continue;\r\n      for(int64_t j = i*i; j < m; j += i){\r\n        if(small[j]\
    \ == j) small[j] = i;\r\n      }\r\n      for(int64_t j = (l+i-1)/i*i; j < r;\
    \ j += i){\r\n        int64_t x = j;\r\n        while(x%i == 0){\r\n         \
    \ if(aux[j-l] > m) break;\r\n\r\n          large[j-l].push_back(i);\r\n      \
    \    aux[j-l] *= i;\r\n          x /= i;\r\n        }\r\n      }\r\n    }\r\n\
    \  }\r\n\r\n  vector<int64_t> factor(int64_t n){\r\n    auto res = large[n - l];\r\
    \n    n /= aux[n-l];\r\n\r\n    if(n >= m) res.push_back(n);\r\n    else{\r\n\
    \      while(n > 1){\r\n        res.push_back(small[n]);\r\n        n /= small[n];\r\
    \n      }\r\n    }\r\n    return res;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\nstruct segmentSieve{\r\n  int64_t l, r, m;\r\n  vector<int>\
    \ small;\r\n  vector<vector<int64_t>> large;\r\n  vector<int64_t> aux;\r\n\r\n\
    \  segmentSieve(int64_t l, int64_t r): l(l), r(r), m(sqrt(r)+1), small(m), large(r-l),\
    \ aux(r-l, 1) {\r\n    iota(small.begin(), small.end(), 0);\r\n    \r\n    for(int64_t\
    \ i = 2; i*i < r; ++i){\r\n      if(small[i] < i) continue;\r\n      for(int64_t\
    \ j = i*i; j < m; j += i){\r\n        if(small[j] == j) small[j] = i;\r\n    \
    \  }\r\n      for(int64_t j = (l+i-1)/i*i; j < r; j += i){\r\n        int64_t\
    \ x = j;\r\n        while(x%i == 0){\r\n          if(aux[j-l] > m) break;\r\n\r\
    \n          large[j-l].push_back(i);\r\n          aux[j-l] *= i;\r\n         \
    \ x /= i;\r\n        }\r\n      }\r\n    }\r\n  }\r\n\r\n  vector<int64_t> factor(int64_t\
    \ n){\r\n    auto res = large[n - l];\r\n    n /= aux[n-l];\r\n\r\n    if(n >=\
    \ m) res.push_back(n);\r\n    else{\r\n      while(n > 1){\r\n        res.push_back(small[n]);\r\
    \n        n /= small[n];\r\n      }\r\n    }\r\n    return res;\r\n  }\r\n};\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime/segmentSieve.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime/segmentSieve.cpp
layout: document
redirect_from:
- /library/math/prime/segmentSieve.cpp
- /library/math/prime/segmentSieve.cpp.html
title: math/prime/segmentSieve.cpp
---
