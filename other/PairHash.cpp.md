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
  bundledCode: "#line 2 \"other/PairHash.cpp\"\n\r\nstruct PairHash{\r\n  static size_t\
    \ hash0;\r\n\r\n  template<typename T1, typename T2>\r\n  size_t operator()(const\
    \ pair<T1, T2> &p) const {\r\n    auto hash1 = hash<T1>{}(p.first);\r\n    auto\
    \ hash2 = hash<T2>{}(p.second);\r\n\r\n    size_t seed = 0;\r\n    seed ^= hash1\
    \ + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n    seed ^= hash2 + 0x9e3779b9\
    \ + (seed << 6) + (seed >> 2);\r\n    seed ^= hash0 + 0x9e3779b9 + (seed << 6)\
    \ + (seed >> 2);\r\n\r\n    return seed;\r\n  }\r\n};\r\nsize_t PairHash::hash0\
    \ = (size_t) random_device{}();\r\n"
  code: "#pragma once\r\n\r\nstruct PairHash{\r\n  static size_t hash0;\r\n\r\n  template<typename\
    \ T1, typename T2>\r\n  size_t operator()(const pair<T1, T2> &p) const {\r\n \
    \   auto hash1 = hash<T1>{}(p.first);\r\n    auto hash2 = hash<T2>{}(p.second);\r\
    \n\r\n    size_t seed = 0;\r\n    seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed\
    \ >> 2);\r\n    seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n  \
    \  seed ^= hash0 + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n\r\n    return seed;\r\
    \n  }\r\n};\r\nsize_t PairHash::hash0 = (size_t) random_device{}();\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/PairHash.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/PairHash.cpp
layout: document
redirect_from:
- /library/other/PairHash.cpp
- /library/other/PairHash.cpp.html
title: other/PairHash.cpp
---
