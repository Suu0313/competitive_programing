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
  bundledCode: "#line 2 \"other/range-based-for/NextPermutation.cpp\"\n\r\ntemplate<class\
    \ Container = vector<int>>\r\nstruct permutation{\r\n  struct itr{\r\n    Container\
    \ c; bool fl;\r\n    bool operator!=([[maybe_unused]] monostate e) const { return\
    \ fl; }\r\n    void operator++() { fl = next_permutation(std::begin(c), std::end(c));\
    \ }\r\n    Container &operator*() { return c; }\r\n  };\r\n\r\n  Container c;\r\
    \n  permutation(int n): c(n) { iota(std::begin(c), std::end(c), 0); }\r\n  permutation(const\
    \ Container &c): c(c) {}\r\n\r\n  itr begin(){ return {c, true}; }\r\n  monostate\
    \ end() { return {}; }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<class Container = vector<int>>\r\nstruct permutation{\r\
    \n  struct itr{\r\n    Container c; bool fl;\r\n    bool operator!=([[maybe_unused]]\
    \ monostate e) const { return fl; }\r\n    void operator++() { fl = next_permutation(std::begin(c),\
    \ std::end(c)); }\r\n    Container &operator*() { return c; }\r\n  };\r\n\r\n\
    \  Container c;\r\n  permutation(int n): c(n) { iota(std::begin(c), std::end(c),\
    \ 0); }\r\n  permutation(const Container &c): c(c) {}\r\n\r\n  itr begin(){ return\
    \ {c, true}; }\r\n  monostate end() { return {}; }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/range-based-for/NextPermutation.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/range-based-for/NextPermutation.cpp
layout: document
redirect_from:
- /library/other/range-based-for/NextPermutation.cpp
- /library/other/range-based-for/NextPermutation.cpp.html
title: other/range-based-for/NextPermutation.cpp
---
