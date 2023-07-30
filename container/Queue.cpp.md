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
  bundledCode: "#line 2 \"container/Queue.cpp\"\n\r\ntemplate<typename T>\r\nstruct\
    \ Queue : queue<T>{\r\n  using queue<T>::queue;\r\n  explicit operator bool()\
    \ const { return !(*this).empty(); }\r\n  T Pop(){ T res = this->front(); this->pop();\
    \ return res; }\r\n  void clear(){ (*this) = Queue(); }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct Queue : queue<T>{\r\n\
    \  using queue<T>::queue;\r\n  explicit operator bool() const { return !(*this).empty();\
    \ }\r\n  T Pop(){ T res = this->front(); this->pop(); return res; }\r\n  void\
    \ clear(){ (*this) = Queue(); }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: container/Queue.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: container/Queue.cpp
layout: document
redirect_from:
- /library/container/Queue.cpp
- /library/container/Queue.cpp.html
title: container/Queue.cpp
---
