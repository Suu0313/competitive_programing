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
  bundledCode: "#line 2 \"other/range-based-for/Enumerate.cpp\"\n\r\ntemplate<class\
    \ Container>\r\nstruct Enumerate{\r\n  struct itr{\r\n    int idx;\r\n    typename\
    \ Container::iterator it;\r\n    bool operator!=(const typename Container::iterator\
    \ &e) const { return it != e; }\r\n    void operator++(){ ++idx; ++it; }\r\n \
    \   pair<int, typename Container::value_type> operator*(){ return {idx, *it};\
    \ }\r\n  };\r\n\r\n  Container c;\r\n  Enumerate(const Container &c): c(c){ }\r\
    \n\r\n  itr begin(){ return {0, std::begin(c)}; }\r\n  typename Container::iterator\
    \ end(){ return std::end(c); }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<class Container>\r\nstruct Enumerate{\r\n  struct\
    \ itr{\r\n    int idx;\r\n    typename Container::iterator it;\r\n    bool operator!=(const\
    \ typename Container::iterator &e) const { return it != e; }\r\n    void operator++(){\
    \ ++idx; ++it; }\r\n    pair<int, typename Container::value_type> operator*(){\
    \ return {idx, *it}; }\r\n  };\r\n\r\n  Container c;\r\n  Enumerate(const Container\
    \ &c): c(c){ }\r\n\r\n  itr begin(){ return {0, std::begin(c)}; }\r\n  typename\
    \ Container::iterator end(){ return std::end(c); }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/range-based-for/Enumerate.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/range-based-for/Enumerate.cpp
layout: document
redirect_from:
- /library/other/range-based-for/Enumerate.cpp
- /library/other/range-based-for/Enumerate.cpp.html
title: other/range-based-for/Enumerate.cpp
---
