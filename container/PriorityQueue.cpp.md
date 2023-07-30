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
  bundledCode: "#line 2 \"container/PriorityQueue.cpp\"\n\r\ntemplate<typename T,\
    \ typename Container = vector<T>, typename Compare = less<typename Container::value_type>>\r\
    \nstruct prque : priority_queue<T, Container, Compare> {\r\n  using priority_queue<T,\
    \ Container, Compare>::priority_queue;\r\n  explicit operator bool() const { return\
    \ !(*this).empty(); }\r\n  T Pop(){ T res = this->top(); this->pop(); return res;\
    \ }\r\n  void clear(){ (*this) = prque(); }\r\n};\r\ntemplate<typename Container,\
    \ typename Compare>\r\nprque(Compare, Container) -> prque<typename Container::value_type,\
    \ Container, Compare>;\r\ntemplate<typename T> using prquer = prque<T, vector<T>,\
    \ greater<T>>;\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T, typename Container = vector<T>,\
    \ typename Compare = less<typename Container::value_type>>\r\nstruct prque : priority_queue<T,\
    \ Container, Compare> {\r\n  using priority_queue<T, Container, Compare>::priority_queue;\r\
    \n  explicit operator bool() const { return !(*this).empty(); }\r\n  T Pop(){\
    \ T res = this->top(); this->pop(); return res; }\r\n  void clear(){ (*this) =\
    \ prque(); }\r\n};\r\ntemplate<typename Container, typename Compare>\r\nprque(Compare,\
    \ Container) -> prque<typename Container::value_type, Container, Compare>;\r\n\
    template<typename T> using prquer = prque<T, vector<T>, greater<T>>;\r\n"
  dependsOn: []
  isVerificationFile: false
  path: container/PriorityQueue.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: container/PriorityQueue.cpp
layout: document
redirect_from:
- /library/container/PriorityQueue.cpp
- /library/container/PriorityQueue.cpp.html
title: container/PriorityQueue.cpp
---
