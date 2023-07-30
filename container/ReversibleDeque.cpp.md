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
  bundledCode: "#line 2 \"container/ReversibleDeque.cpp\"\n\r\ntemplate<typename T>\r\
    \nstruct ReversibleDeque{\r\n  deque<T> dq;\r\n  bool rev = false;\r\n\r\n  ReversibleDeque()\
    \ = default;\r\n  ReversibleDeque(size_t n, const T &v): dq(n, v), rev(false)\
    \ {}\r\n  ReversibleDeque(size_t n): dq(n), rev(false) {}\r\n  template <class\
    \ InputIterator>\r\n  ReversibleDeque(InputIterator first, InputIterator last):\
    \ dq(first, last), rev(false) {}\r\n  ReversibleDeque(initializer_list<T> il):\
    \ dq(il), rev(false) {}\r\n\r\n  size_t size() const { return dq.size(); }\r\n\
    \r\n  T &operator[](size_t n){ return rev ? dq[size() - n - 1] : dq[n]; }\r\n\
    \  const T &operator[](size_t n) const { return rev ? dq[size() - n - 1] : dq[n];\
    \ }\r\n\r\n  T &front(){ return rev ? dq.back() : dq.front(); }\r\n  const T &front()\
    \ const { return rev ? dq.back() : dq.front(); }\r\n\r\n  T &back(){ return rev\
    \ ? dq.front() : dq.back(); }\r\n  const T &back() const { return rev ? dq.front()\
    \ : dq.back(); }\r\n\r\n  void clear(){ dq.clear(); }\r\n  void reverse(){ rev\
    \ = !rev; }\r\n  \r\n  void push_front(const T &x){\r\n    if(rev) dq.push_back(x);\r\
    \n    else dq.push_front(x);\r\n  }\r\n  void push_front(T &&x){\r\n    if(rev)\
    \ dq.push_back(x);\r\n    else dq.push_front(x);\r\n  }\r\n\r\n  void push_back(const\
    \ T &x){\r\n    if(rev) dq.push_front(x);\r\n    else dq.push_back(x);\r\n  }\r\
    \n  void push_back(T &&x){\r\n    if(rev) dq.push_front(x);\r\n    else dq.push_back(x);\r\
    \n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct ReversibleDeque{\r\n \
    \ deque<T> dq;\r\n  bool rev = false;\r\n\r\n  ReversibleDeque() = default;\r\n\
    \  ReversibleDeque(size_t n, const T &v): dq(n, v), rev(false) {}\r\n  ReversibleDeque(size_t\
    \ n): dq(n), rev(false) {}\r\n  template <class InputIterator>\r\n  ReversibleDeque(InputIterator\
    \ first, InputIterator last): dq(first, last), rev(false) {}\r\n  ReversibleDeque(initializer_list<T>\
    \ il): dq(il), rev(false) {}\r\n\r\n  size_t size() const { return dq.size();\
    \ }\r\n\r\n  T &operator[](size_t n){ return rev ? dq[size() - n - 1] : dq[n];\
    \ }\r\n  const T &operator[](size_t n) const { return rev ? dq[size() - n - 1]\
    \ : dq[n]; }\r\n\r\n  T &front(){ return rev ? dq.back() : dq.front(); }\r\n \
    \ const T &front() const { return rev ? dq.back() : dq.front(); }\r\n\r\n  T &back(){\
    \ return rev ? dq.front() : dq.back(); }\r\n  const T &back() const { return rev\
    \ ? dq.front() : dq.back(); }\r\n\r\n  void clear(){ dq.clear(); }\r\n  void reverse(){\
    \ rev = !rev; }\r\n  \r\n  void push_front(const T &x){\r\n    if(rev) dq.push_back(x);\r\
    \n    else dq.push_front(x);\r\n  }\r\n  void push_front(T &&x){\r\n    if(rev)\
    \ dq.push_back(x);\r\n    else dq.push_front(x);\r\n  }\r\n\r\n  void push_back(const\
    \ T &x){\r\n    if(rev) dq.push_front(x);\r\n    else dq.push_back(x);\r\n  }\r\
    \n  void push_back(T &&x){\r\n    if(rev) dq.push_front(x);\r\n    else dq.push_back(x);\r\
    \n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: container/ReversibleDeque.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: container/ReversibleDeque.cpp
layout: document
redirect_from:
- /library/container/ReversibleDeque.cpp
- /library/container/ReversibleDeque.cpp.html
title: container/ReversibleDeque.cpp
---
