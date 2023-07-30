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
  bundledCode: "#line 2 \"container/Stack.cpp\"\n\r\ntemplate<typename T>\r\nstruct\
    \ Stack : stack<T>{\r\n  using stack<T>::stack;\r\n  explicit operator bool()\
    \ const { return !(*this).empty(); }\r\n  T Pop(){ T res = this->top(); this->pop();\
    \ return res; }\r\n  void clear(){ (*this) = Stack(); }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct Stack : stack<T>{\r\n\
    \  using stack<T>::stack;\r\n  explicit operator bool() const { return !(*this).empty();\
    \ }\r\n  T Pop(){ T res = this->top(); this->pop(); return res; }\r\n  void clear(){\
    \ (*this) = Stack(); }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: container/Stack.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: container/Stack.cpp
layout: document
redirect_from:
- /library/container/Stack.cpp
- /library/container/Stack.cpp.html
title: container/Stack.cpp
---
