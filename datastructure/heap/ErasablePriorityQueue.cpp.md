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
  bundledCode: "#line 1 \"datastructure/heap/ErasablePriorityQueue.cpp\"\ntemplate<typename\
    \ T, class Compair>\r\nstruct ErasablePriorityQueue{\r\n  priority_queue<T, vector<T>,\
    \ Compair> pq, lazy;\r\n  ErasablePriorityQueue() = default;\r\n  void normalize()\
    \ {\r\n    while(!pq.empty() && !lazy.empty() && pq.top() == lazy.top()) pq.pop(),\
    \ lazy.pop();\r\n  }\r\n\r\n  void push(const T &e){ pq.push(e); }\r\n  void erase(const\
    \ T &e){ lazy.push(e); }\r\n  T pop(){\r\n    this->normalize();\r\n    T e =\
    \ pq.top(); pq.pop();\r\n    return e;\r\n  }\r\n  T top(){\r\n    this->normalize();\r\
    \n    return pq.top();\r\n  }\r\n  size_t size() const { return pq.size() - lazy.size();\
    \ }\r\n  bool empty() const { return this->size() == 0; }\r\n};\r\n"
  code: "template<typename T, class Compair>\r\nstruct ErasablePriorityQueue{\r\n\
    \  priority_queue<T, vector<T>, Compair> pq, lazy;\r\n  ErasablePriorityQueue()\
    \ = default;\r\n  void normalize() {\r\n    while(!pq.empty() && !lazy.empty()\
    \ && pq.top() == lazy.top()) pq.pop(), lazy.pop();\r\n  }\r\n\r\n  void push(const\
    \ T &e){ pq.push(e); }\r\n  void erase(const T &e){ lazy.push(e); }\r\n  T pop(){\r\
    \n    this->normalize();\r\n    T e = pq.top(); pq.pop();\r\n    return e;\r\n\
    \  }\r\n  T top(){\r\n    this->normalize();\r\n    return pq.top();\r\n  }\r\n\
    \  size_t size() const { return pq.size() - lazy.size(); }\r\n  bool empty() const\
    \ { return this->size() == 0; }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/heap/ErasablePriorityQueue.cpp
  requiredBy: []
  timestamp: '2023-06-25 00:59:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/heap/ErasablePriorityQueue.cpp
layout: document
redirect_from:
- /library/datastructure/heap/ErasablePriorityQueue.cpp
- /library/datastructure/heap/ErasablePriorityQueue.cpp.html
title: datastructure/heap/ErasablePriorityQueue.cpp
---
