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
  bundledCode: "#line 1 \"unuse/whole.cpp\"\n#define WHOLE(some_of, n, i, ...) ([&]{\
    \ vector<int> index(n); iota(begin(index), end(index), 0); return some_of(begin(index),\
    \ end(index) , [&](int i){ __VA_ARGS__; } );})()\r\n"
  code: "#define WHOLE(some_of, n, i, ...) ([&]{ vector<int> index(n); iota(begin(index),\
    \ end(index), 0); return some_of(begin(index), end(index) , [&](int i){ __VA_ARGS__;\
    \ } );})()\r\n"
  dependsOn: []
  isVerificationFile: false
  path: unuse/whole.cpp
  requiredBy: []
  timestamp: '2022-04-06 05:08:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unuse/whole.cpp
layout: document
redirect_from:
- /library/unuse/whole.cpp
- /library/unuse/whole.cpp.html
title: unuse/whole.cpp
---
