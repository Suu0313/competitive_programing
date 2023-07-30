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
  bundledCode: "#line 2 \"datastructure/SlidingWindowAggregation.cpp\"\n\r\ntemplate\
    \ <class SemiGroup>\r\nstruct SlidingWindowAggregation{\r\n  stack<pair<SemiGroup,\
    \ SemiGroup>> front_stack, back_stack;\r\n\r\n  SlidingWindowAggregation(): front_stack(),\
    \ back_stack(){}\r\n\r\n  bool empty() const { return front_stack.empty() && back_stack.empty();\
    \ }\r\n\r\n  size_t size() const { return front_stack.size() + back_stack.size();\
    \ }\r\n\r\n  SemiGroup fold_all() const{\r\n    if(this->empty()) return SemiGroup{};\r\
    \n\r\n    if(front_stack.empty()) return back_stack.top().second;\r\n    if(back_stack.empty())\
    \ return front_stack.top().second;\r\n    return front_stack.top().second + back_stack.top().second;\r\
    \n  }\r\n\r\n  void push(const SemiGroup &x) {\r\n    if(back_stack.empty()) back_stack.emplace(x,\
    \ x);\r\n    else back_stack.emplace(x, back_stack.top().second + x);\r\n  }\r\
    \n\r\n  bool pop() {\r\n    if(this->empty()) return false;\r\n    if(front_stack.empty()){\r\
    \n      front_stack.emplace(back_stack.top().first, back_stack.top().first);\r\
    \n      back_stack.pop();\r\n      while(!back_stack.empty()){\r\n        front_stack.emplace(back_stack.top().first,\
    \ back_stack.top().first + front_stack.top().second);\r\n        back_stack.pop();\r\
    \n      }\r\n    }\r\n    front_stack.pop();\r\n    return true;\r\n  }\r\n};\r\
    \n"
  code: "#pragma once\r\n\r\ntemplate <class SemiGroup>\r\nstruct SlidingWindowAggregation{\r\
    \n  stack<pair<SemiGroup, SemiGroup>> front_stack, back_stack;\r\n\r\n  SlidingWindowAggregation():\
    \ front_stack(), back_stack(){}\r\n\r\n  bool empty() const { return front_stack.empty()\
    \ && back_stack.empty(); }\r\n\r\n  size_t size() const { return front_stack.size()\
    \ + back_stack.size(); }\r\n\r\n  SemiGroup fold_all() const{\r\n    if(this->empty())\
    \ return SemiGroup{};\r\n\r\n    if(front_stack.empty()) return back_stack.top().second;\r\
    \n    if(back_stack.empty()) return front_stack.top().second;\r\n    return front_stack.top().second\
    \ + back_stack.top().second;\r\n  }\r\n\r\n  void push(const SemiGroup &x) {\r\
    \n    if(back_stack.empty()) back_stack.emplace(x, x);\r\n    else back_stack.emplace(x,\
    \ back_stack.top().second + x);\r\n  }\r\n\r\n  bool pop() {\r\n    if(this->empty())\
    \ return false;\r\n    if(front_stack.empty()){\r\n      front_stack.emplace(back_stack.top().first,\
    \ back_stack.top().first);\r\n      back_stack.pop();\r\n      while(!back_stack.empty()){\r\
    \n        front_stack.emplace(back_stack.top().first, back_stack.top().first +\
    \ front_stack.top().second);\r\n        back_stack.pop();\r\n      }\r\n    }\r\
    \n    front_stack.pop();\r\n    return true;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/SlidingWindowAggregation.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/SlidingWindowAggregation.cpp
layout: document
redirect_from:
- /library/datastructure/SlidingWindowAggregation.cpp
- /library/datastructure/SlidingWindowAggregation.cpp.html
title: datastructure/SlidingWindowAggregation.cpp
---
