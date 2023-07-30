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
  bundledCode: "#line 2 \"other/range-based-for/Supersets.cpp\"\n\r\nstruct supersets{\r\
    \n  struct itr{\r\n    uint64_t s, t;\r\n    bool operator!=(uint64_t e){ return\
    \ (t|s) < e; }\r\n    void operator++() { t += 1; }\r\n    uint64_t operator*()\
    \ { return t |= s; }\r\n  };\r\n\r\n  int n;\r\n  uint64_t s;\r\n  supersets(int\
    \ n, uint64_t s) : n(n), s(s) {}\r\n\r\n  itr begin() { return {s, s}; }\r\n \
    \ uint64_t end() { return 1ull << n; }\r\n};\r\n"
  code: "#pragma once\r\n\r\nstruct supersets{\r\n  struct itr{\r\n    uint64_t s,\
    \ t;\r\n    bool operator!=(uint64_t e){ return (t|s) < e; }\r\n    void operator++()\
    \ { t += 1; }\r\n    uint64_t operator*() { return t |= s; }\r\n  };\r\n\r\n \
    \ int n;\r\n  uint64_t s;\r\n  supersets(int n, uint64_t s) : n(n), s(s) {}\r\n\
    \r\n  itr begin() { return {s, s}; }\r\n  uint64_t end() { return 1ull << n; }\r\
    \n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/range-based-for/Supersets.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/range-based-for/Supersets.cpp
layout: document
redirect_from:
- /library/other/range-based-for/Supersets.cpp
- /library/other/range-based-for/Supersets.cpp.html
title: other/range-based-for/Supersets.cpp
---
