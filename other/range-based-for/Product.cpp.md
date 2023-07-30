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
  bundledCode: "#line 2 \"other/range-based-for/Product.cpp\"\n\r\nstruct product{\r\
    \n  struct itr{\r\n    int current;\r\n    vector<int> res;\r\n    product *p;\r\
    \n    bool operator!=([[maybe_unused]] monostate e){ return current != (p->upper);\
    \ }\r\n    void operator++(){ ++current; }\r\n    const vector<int> &operator*(){\r\
    \n      int pos = current, i = 0;\r\n      for(auto&&e : p->bases){ res[i++] =\
    \ pos % e; pos /= e; }\r\n      return res;\r\n    }\r\n  };\r\n  vector<int>\
    \ bases;\r\n  int n, upper;\r\n  product(const vector<int> &bases): bases(bases),\
    \ n(bases.size()), upper(1) {\r\n    for(auto&&e : bases) upper *= e;\r\n  }\r\
    \n  product(int base, int n): bases(n), n(n), upper(1) {\r\n    for(auto&&e :\
    \ bases) upper *= (e = base);\r\n  }\r\n\r\n  itr begin(){ return {0, vector<int>(n),\
    \ this}; }\r\n  monostate end() { return {}; }\r\n};\r\n"
  code: "#pragma once\r\n\r\nstruct product{\r\n  struct itr{\r\n    int current;\r\
    \n    vector<int> res;\r\n    product *p;\r\n    bool operator!=([[maybe_unused]]\
    \ monostate e){ return current != (p->upper); }\r\n    void operator++(){ ++current;\
    \ }\r\n    const vector<int> &operator*(){\r\n      int pos = current, i = 0;\r\
    \n      for(auto&&e : p->bases){ res[i++] = pos % e; pos /= e; }\r\n      return\
    \ res;\r\n    }\r\n  };\r\n  vector<int> bases;\r\n  int n, upper;\r\n  product(const\
    \ vector<int> &bases): bases(bases), n(bases.size()), upper(1) {\r\n    for(auto&&e\
    \ : bases) upper *= e;\r\n  }\r\n  product(int base, int n): bases(n), n(n), upper(1)\
    \ {\r\n    for(auto&&e : bases) upper *= (e = base);\r\n  }\r\n\r\n  itr begin(){\
    \ return {0, vector<int>(n), this}; }\r\n  monostate end() { return {}; }\r\n\
    };\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/range-based-for/Product.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/range-based-for/Product.cpp
layout: document
redirect_from:
- /library/other/range-based-for/Product.cpp
- /library/other/range-based-for/Product.cpp.html
title: other/range-based-for/Product.cpp
---
