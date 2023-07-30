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
  bundledCode: "#line 2 \"other/range-based-for/NextCombination.cpp\"\n\r\nstruct\
    \ combination{\r\n  struct itr{\r\n    uint64_t bit;\r\n    bool operator!=(uint64_t\
    \ e){ return bit < e; }\r\n    void operator++() {\r\n      uint64_t buff = bit\
    \ | (bit-1);\r\n      bit = (buff+1) | (((~ buff & - ~ buff) - 1) >> (__builtin_ctzll(bit)\
    \ + 1));\r\n    }\r\n    uint64_t operator*() { return bit; }\r\n  };\r\n\r\n\
    \  int n, k;\r\n  combination(int n, int k) : n(n), k(k) {}\r\n\r\n  itr begin()\
    \ { return {(1ull << k)-1}; }\r\n  uint64_t end() { return 1ull << n; }\r\n};\r\
    \n"
  code: "#pragma once\r\n\r\nstruct combination{\r\n  struct itr{\r\n    uint64_t\
    \ bit;\r\n    bool operator!=(uint64_t e){ return bit < e; }\r\n    void operator++()\
    \ {\r\n      uint64_t buff = bit | (bit-1);\r\n      bit = (buff+1) | (((~ buff\
    \ & - ~ buff) - 1) >> (__builtin_ctzll(bit) + 1));\r\n    }\r\n    uint64_t operator*()\
    \ { return bit; }\r\n  };\r\n\r\n  int n, k;\r\n  combination(int n, int k) :\
    \ n(n), k(k) {}\r\n\r\n  itr begin() { return {(1ull << k)-1}; }\r\n  uint64_t\
    \ end() { return 1ull << n; }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/range-based-for/NextCombination.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/range-based-for/NextCombination.cpp
layout: document
redirect_from:
- /library/other/range-based-for/NextCombination.cpp
- /library/other/range-based-for/NextCombination.cpp.html
title: other/range-based-for/NextCombination.cpp
---
