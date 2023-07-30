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
  bundledCode: "#line 2 \"graph/chromatic_number.cpp\"\n\r\nint chromatic_number(const\
    \ vector<int> &es){\r\n  const int n = int(es.size());\r\n  vector<int> ind(1\
    \ << n), cnt((1 << n) + 1);\r\n  ind[0] = 1; cnt[1] = 1;\r\n\r\n  for(int s =\
    \ 1; s < (1 << n); ++s){\r\n    int v = __builtin_ctz(s);\r\n    ind[s] = ind[s\
    \ ^ (1 << v)] + ind[(s ^ (1 << v)) & ~es[v]];\r\n    cnt[ind[s]] += __builtin_parity(s)\
    \ ? -1 : 1;\r\n  }\r\n  vector<pair<int,int>> buf;\r\n  for(int i = 1; i <= (1\
    \ << n); ++i){\r\n    if(cnt[i]) buf.emplace_back(i, cnt[i]);\r\n  }\r\n  \r\n\
    \  constexpr int bil = 1000000000;\r\n  constexpr int mods[] = {bil+7, bil+11,\
    \ bil+21};\r\n  int res = n;\r\n  for(auto m : mods){\r\n    auto indk = buf;\r\
    \n    for(int k = 1; k < res; ++k){\r\n      int64_t sum = 0;\r\n      for(auto&&[i,\
    \ x] : indk) sum += (x = int64_t(x)*i % m);\r\n      if(sum % m) res = k;\r\n\
    \    }\r\n  }\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n\r\nint chromatic_number(const vector<int> &es){\r\n  const\
    \ int n = int(es.size());\r\n  vector<int> ind(1 << n), cnt((1 << n) + 1);\r\n\
    \  ind[0] = 1; cnt[1] = 1;\r\n\r\n  for(int s = 1; s < (1 << n); ++s){\r\n   \
    \ int v = __builtin_ctz(s);\r\n    ind[s] = ind[s ^ (1 << v)] + ind[(s ^ (1 <<\
    \ v)) & ~es[v]];\r\n    cnt[ind[s]] += __builtin_parity(s) ? -1 : 1;\r\n  }\r\n\
    \  vector<pair<int,int>> buf;\r\n  for(int i = 1; i <= (1 << n); ++i){\r\n   \
    \ if(cnt[i]) buf.emplace_back(i, cnt[i]);\r\n  }\r\n  \r\n  constexpr int bil\
    \ = 1000000000;\r\n  constexpr int mods[] = {bil+7, bil+11, bil+21};\r\n  int\
    \ res = n;\r\n  for(auto m : mods){\r\n    auto indk = buf;\r\n    for(int k =\
    \ 1; k < res; ++k){\r\n      int64_t sum = 0;\r\n      for(auto&&[i, x] : indk)\
    \ sum += (x = int64_t(x)*i % m);\r\n      if(sum % m) res = k;\r\n    }\r\n  }\r\
    \n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/chromatic_number.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/chromatic_number.cpp
layout: document
redirect_from:
- /library/graph/chromatic_number.cpp
- /library/graph/chromatic_number.cpp.html
title: graph/chromatic_number.cpp
---
