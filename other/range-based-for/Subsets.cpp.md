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
  bundledCode: "#line 2 \"other/range-based-for/Subsets.cpp\"\n\r\nstruct subsets{\r\
    \n  struct itr{\r\n    uint64_t s, t;\r\n    bool operator!=([[maybe_unused]]\
    \ monostate e){ return (t&s) != 0; }\r\n    void operator++() { t -= 1; }\r\n\
    \    uint64_t operator*() { return t &= s; }\r\n  };\r\n\r\n  uint64_t s;\r\n\
    \  subsets(uint64_t s) : s(s) {}\r\n\r\n  itr begin() { return {s, (s-1)&s}; }\r\
    \n  monostate end() { return {}; }\r\n};\r\n"
  code: "#pragma once\r\n\r\nstruct subsets{\r\n  struct itr{\r\n    uint64_t s, t;\r\
    \n    bool operator!=([[maybe_unused]] monostate e){ return (t&s) != 0; }\r\n\
    \    void operator++() { t -= 1; }\r\n    uint64_t operator*() { return t &= s;\
    \ }\r\n  };\r\n\r\n  uint64_t s;\r\n  subsets(uint64_t s) : s(s) {}\r\n\r\n  itr\
    \ begin() { return {s, (s-1)&s}; }\r\n  monostate end() { return {}; }\r\n};\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: other/range-based-for/Subsets.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/range-based-for/Subsets.cpp
layout: document
redirect_from:
- /library/other/range-based-for/Subsets.cpp
- /library/other/range-based-for/Subsets.cpp.html
title: other/range-based-for/Subsets.cpp
---
