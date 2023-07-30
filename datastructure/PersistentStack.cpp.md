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
  bundledCode: "#line 2 \"datastructure/PersistentStack.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct PersistentStack{\r\n  struct Node;\r\n  using Np = shared_ptr<Node>;\r\
    \n  template<typename... Args>\r\n  static Np make_np(Args&&... args){ return\
    \ make_shared<Node>(forward<Args>(args)...); }\r\n\r\n  struct Node{\r\n    Np\
    \ next;\r\n    T value;\r\n\r\n    template<typename... Args>\r\n    Node(const\
    \ Np &next, Args&&... args): next(next), value(forward<Args>(args)...) {}\r\n\
    \  };\r\n\r\n  Np ptr = {};\r\n\r\n  constexpr PersistentStack() = default;\r\n\
    \  explicit PersistentStack(const Np &ptr): ptr(ptr) {}\r\n  explicit PersistentStack(Np\
    \ &&ptr): ptr(move(ptr)) {}\r\n\r\n  using self = PersistentStack;\r\n\r\n  bool\
    \ empty() const { return !ptr; }\r\n\r\n  const T &top() const {\r\n    assert(!empty());\r\
    \n    return ptr->value;\r\n  }\r\n\r\n  T &top(){\r\n    assert(!empty());\r\n\
    \    return ptr->value;\r\n  }\r\n\r\n  template<typename... Args>\r\n  self emplace(Args&&...\
    \ args) const { return self(make_np(ptr, forward<Args>(args)...)); }\r\n  self\
    \ push(const T &x) const { return emplace(x); }\r\n  self push(T &&x) const {\
    \ return emplace(move(x)); }\r\n\r\n  self pop() const {\r\n    assert(!empty());\r\
    \n    return self(ptr->next);\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct PersistentStack{\r\n \
    \ struct Node;\r\n  using Np = shared_ptr<Node>;\r\n  template<typename... Args>\r\
    \n  static Np make_np(Args&&... args){ return make_shared<Node>(forward<Args>(args)...);\
    \ }\r\n\r\n  struct Node{\r\n    Np next;\r\n    T value;\r\n\r\n    template<typename...\
    \ Args>\r\n    Node(const Np &next, Args&&... args): next(next), value(forward<Args>(args)...)\
    \ {}\r\n  };\r\n\r\n  Np ptr = {};\r\n\r\n  constexpr PersistentStack() = default;\r\
    \n  explicit PersistentStack(const Np &ptr): ptr(ptr) {}\r\n  explicit PersistentStack(Np\
    \ &&ptr): ptr(move(ptr)) {}\r\n\r\n  using self = PersistentStack;\r\n\r\n  bool\
    \ empty() const { return !ptr; }\r\n\r\n  const T &top() const {\r\n    assert(!empty());\r\
    \n    return ptr->value;\r\n  }\r\n\r\n  T &top(){\r\n    assert(!empty());\r\n\
    \    return ptr->value;\r\n  }\r\n\r\n  template<typename... Args>\r\n  self emplace(Args&&...\
    \ args) const { return self(make_np(ptr, forward<Args>(args)...)); }\r\n  self\
    \ push(const T &x) const { return emplace(x); }\r\n  self push(T &&x) const {\
    \ return emplace(move(x)); }\r\n\r\n  self pop() const {\r\n    assert(!empty());\r\
    \n    return self(ptr->next);\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/PersistentStack.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/PersistentStack.cpp
layout: document
redirect_from:
- /library/datastructure/PersistentStack.cpp
- /library/datastructure/PersistentStack.cpp.html
title: datastructure/PersistentStack.cpp
---
