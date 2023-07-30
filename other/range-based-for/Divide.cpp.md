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
  bundledCode: "#line 2 \"other/range-based-for/Divide.cpp\"\n\r\nstruct divide{\r\
    \n  struct itr{\r\n    uint64_t s;\r\n    int n;\r\n    bool operator!=([[maybe_unused]]\
    \ monostate e){ return s != 1ull<<n; }\r\n    void operator++(){ ++s; }\r\n  \
    \  vector<vector<int>> operator*(){\r\n      vector<vector<int>> res(1, vector<int>(1,\
    \ 0));\r\n      for(int i = 0; i < n; ++i){\r\n        if(s>>i & 1) res.emplace_back(1,\
    \ i+1);\r\n        else res.back().emplace_back(i+1);\r\n      }\r\n      return\
    \ res;\r\n    }\r\n  };\r\n  int n;\r\n  divide(int n): n(n) {}\r\n\r\n  itr begin(){\
    \ return {0, n-1}; }\r\n  monostate end() { return {}; }\r\n};\r\n"
  code: "#pragma once\r\n\r\nstruct divide{\r\n  struct itr{\r\n    uint64_t s;\r\n\
    \    int n;\r\n    bool operator!=([[maybe_unused]] monostate e){ return s !=\
    \ 1ull<<n; }\r\n    void operator++(){ ++s; }\r\n    vector<vector<int>> operator*(){\r\
    \n      vector<vector<int>> res(1, vector<int>(1, 0));\r\n      for(int i = 0;\
    \ i < n; ++i){\r\n        if(s>>i & 1) res.emplace_back(1, i+1);\r\n        else\
    \ res.back().emplace_back(i+1);\r\n      }\r\n      return res;\r\n    }\r\n \
    \ };\r\n  int n;\r\n  divide(int n): n(n) {}\r\n\r\n  itr begin(){ return {0,\
    \ n-1}; }\r\n  monostate end() { return {}; }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/range-based-for/Divide.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/range-based-for/Divide.cpp
layout: document
redirect_from:
- /library/other/range-based-for/Divide.cpp
- /library/other/range-based-for/Divide.cpp.html
title: other/range-based-for/Divide.cpp
---
