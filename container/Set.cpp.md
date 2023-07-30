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
  bundledCode: "#line 2 \"container/Set.cpp\"\n\r\ntemplate<typename T>\r\nstruct\
    \ Set : set<T> {\r\n  using set<T>::set;\r\n  explicit operator bool() const {\
    \ return !(*this).empty(); }\r\n  Set operator|(const Set &s) const {\r\n    Set\
    \ res;\r\n    set_union((*this).begin(), (*this).end(), s.begin(), s.end(), inserter(res,\
    \ res.end()));\r\n    return res;\r\n  }\r\n  Set &operator|=(const Set &s){\r\
    \n    for(auto&&e : s) this->insert(e);\r\n    return (*this);\r\n  }\r\n  Set\
    \ operator&(const Set &s) const {\r\n    Set res;\r\n    set_intersection((*this).begin(),\
    \ (*this).end(), s.begin(), s.end(), inserter(res, res.end()));\r\n    return\
    \ res;\r\n  }\r\n  Set operator&=(const Set &s){ return (*this) = (*this) & s;\
    \ }\r\n  Set operator^(const Set &s) const {\r\n    Set res;\r\n    set_symmetric_difference((*this).begin(),\
    \ (*this).end(), s.begin(), s.end(), inserter(res, res.end()));\r\n    return\
    \ res;\r\n  }\r\n  Set &operator^=(const Set &s){\r\n    for(auto&&e : s){\r\n\
    \      if(this->exist(e)) this->erase(e);\r\n      else this->insert(e);\r\n \
    \   }\r\n    return (*this);\r\n  }\r\n  Set operator-(const Set &s) const {\r\
    \n    Set res;\r\n    set_difference((*this).begin(), (*this).end(), s.begin(),\
    \ s.end(), inserter(res, res.end()));\r\n    return res;\r\n  }\r\n  Set &operator-=(const\
    \ Set &s){\r\n    for(auto&&e : s) this->erase(e);\r\n    return (*this);\r\n\
    \  }\r\n  const T &operator[](int k) const {\r\n    if(k >= 0) return *std::next(this->begin(),\
    \ k);\r\n    else return *std::prev(this->end(), -k);\r\n  }\r\n  bool exist(const\
    \ T &x) const { return (*this).find(x) != (*this).end(); }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct Set : set<T> {\r\n  using\
    \ set<T>::set;\r\n  explicit operator bool() const { return !(*this).empty();\
    \ }\r\n  Set operator|(const Set &s) const {\r\n    Set res;\r\n    set_union((*this).begin(),\
    \ (*this).end(), s.begin(), s.end(), inserter(res, res.end()));\r\n    return\
    \ res;\r\n  }\r\n  Set &operator|=(const Set &s){\r\n    for(auto&&e : s) this->insert(e);\r\
    \n    return (*this);\r\n  }\r\n  Set operator&(const Set &s) const {\r\n    Set\
    \ res;\r\n    set_intersection((*this).begin(), (*this).end(), s.begin(), s.end(),\
    \ inserter(res, res.end()));\r\n    return res;\r\n  }\r\n  Set operator&=(const\
    \ Set &s){ return (*this) = (*this) & s; }\r\n  Set operator^(const Set &s) const\
    \ {\r\n    Set res;\r\n    set_symmetric_difference((*this).begin(), (*this).end(),\
    \ s.begin(), s.end(), inserter(res, res.end()));\r\n    return res;\r\n  }\r\n\
    \  Set &operator^=(const Set &s){\r\n    for(auto&&e : s){\r\n      if(this->exist(e))\
    \ this->erase(e);\r\n      else this->insert(e);\r\n    }\r\n    return (*this);\r\
    \n  }\r\n  Set operator-(const Set &s) const {\r\n    Set res;\r\n    set_difference((*this).begin(),\
    \ (*this).end(), s.begin(), s.end(), inserter(res, res.end()));\r\n    return\
    \ res;\r\n  }\r\n  Set &operator-=(const Set &s){\r\n    for(auto&&e : s) this->erase(e);\r\
    \n    return (*this);\r\n  }\r\n  const T &operator[](int k) const {\r\n    if(k\
    \ >= 0) return *std::next(this->begin(), k);\r\n    else return *std::prev(this->end(),\
    \ -k);\r\n  }\r\n  bool exist(const T &x) const { return (*this).find(x) != (*this).end();\
    \ }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: container/Set.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: container/Set.cpp
layout: document
redirect_from:
- /library/container/Set.cpp
- /library/container/Set.cpp.html
title: container/Set.cpp
---
