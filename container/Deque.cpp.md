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
  bundledCode: "#line 2 \"container/Deque.cpp\"\n\r\ntemplate<typename T>\r\nstruct\
    \ Deque : deque<T>{\r\n  using deque<T>::deque;\r\n  explicit operator bool()\
    \ const { return !(*this).empty(); }\r\n  T Popf(){ T res = this->front(); this->pop_front();\
    \ return res; }\r\n  T Popb(){ T res = this->back(); this->pop_back(); return\
    \ res; }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct Deque : deque<T>{\r\n\
    \  using deque<T>::deque;\r\n  explicit operator bool() const { return !(*this).empty();\
    \ }\r\n  T Popf(){ T res = this->front(); this->pop_front(); return res; }\r\n\
    \  T Popb(){ T res = this->back(); this->pop_back(); return res; }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: container/Deque.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: container/Deque.cpp
layout: document
redirect_from:
- /library/container/Deque.cpp
- /library/container/Deque.cpp.html
title: container/Deque.cpp
---
