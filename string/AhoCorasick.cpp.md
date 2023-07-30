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
  bundledCode: "#line 2 \"string/AhoCorasick.cpp\"\n\r\ntemplate<typename T>\r\nstruct\
    \ AhoCorasick{\r\n  AhoCorasick(): ptr(1), cnt(1) {}\r\n\r\n  vector<map<T, int>>\
    \ ptr;\r\n  vector<int> fail, cnt;\r\n\r\n  size_t size() const { return cnt.size();\
    \ }\r\n  int operator[](int v) const { return cnt[v]; }\r\n\r\n  int succ(int\
    \ v, const T &c) const {\r\n    while(v != -1){\r\n      auto it = ptr[v].find(c);\r\
    \n      if(it != ptr[v].end()) return it->second;\r\n      v = fail[v];\r\n  \
    \  }\r\n    return 0;\r\n  }\r\n\r\n  int add_node(int v, const T &c){\r\n   \
    \ auto it = ptr[v].find(c);\r\n    if(it == ptr[v].end()){\r\n      ptr[v][c]\
    \ = cnt.size();\r\n      ptr.push_back({});\r\n      cnt.push_back(0);\r\n   \
    \ }\r\n    return ptr[v][c];\r\n  }\r\n\r\n  template<class Iter>\r\n  int add(Iter\
    \ first, Iter last){\r\n    int v = 0;\r\n    for(; first != last; ++first){\r\
    \n      T c = *first;\r\n      v = add_node(v, c);\r\n    }\r\n    ++cnt[v];\r\
    \n    return v;\r\n  }\r\n\r\n  template<class Container>\r\n  int add(const Container\
    \ &c){  return add(begin(c), end(c)); }\r\n\r\n  void build(){\r\n    fail.assign(this->size(),\
    \ -1);\r\n    queue<int> qu;\r\n    for(qu.push(0); !qu.empty(); qu.pop()){\r\n\
    \      int v = qu.front();\r\n      for(auto[c, to] : ptr[v]){\r\n        fail[to]\
    \ = this->succ(fail[v], c);\r\n        cnt[to] += cnt[fail[to]];\r\n        qu.push(to);\r\
    \n      }\r\n    }\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct AhoCorasick{\r\n  AhoCorasick():\
    \ ptr(1), cnt(1) {}\r\n\r\n  vector<map<T, int>> ptr;\r\n  vector<int> fail, cnt;\r\
    \n\r\n  size_t size() const { return cnt.size(); }\r\n  int operator[](int v)\
    \ const { return cnt[v]; }\r\n\r\n  int succ(int v, const T &c) const {\r\n  \
    \  while(v != -1){\r\n      auto it = ptr[v].find(c);\r\n      if(it != ptr[v].end())\
    \ return it->second;\r\n      v = fail[v];\r\n    }\r\n    return 0;\r\n  }\r\n\
    \r\n  int add_node(int v, const T &c){\r\n    auto it = ptr[v].find(c);\r\n  \
    \  if(it == ptr[v].end()){\r\n      ptr[v][c] = cnt.size();\r\n      ptr.push_back({});\r\
    \n      cnt.push_back(0);\r\n    }\r\n    return ptr[v][c];\r\n  }\r\n\r\n  template<class\
    \ Iter>\r\n  int add(Iter first, Iter last){\r\n    int v = 0;\r\n    for(; first\
    \ != last; ++first){\r\n      T c = *first;\r\n      v = add_node(v, c);\r\n \
    \   }\r\n    ++cnt[v];\r\n    return v;\r\n  }\r\n\r\n  template<class Container>\r\
    \n  int add(const Container &c){  return add(begin(c), end(c)); }\r\n\r\n  void\
    \ build(){\r\n    fail.assign(this->size(), -1);\r\n    queue<int> qu;\r\n   \
    \ for(qu.push(0); !qu.empty(); qu.pop()){\r\n      int v = qu.front();\r\n   \
    \   for(auto[c, to] : ptr[v]){\r\n        fail[to] = this->succ(fail[v], c);\r\
    \n        cnt[to] += cnt[fail[to]];\r\n        qu.push(to);\r\n      }\r\n   \
    \ }\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/AhoCorasick.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/AhoCorasick.cpp
layout: document
redirect_from:
- /library/string/AhoCorasick.cpp
- /library/string/AhoCorasick.cpp.html
title: string/AhoCorasick.cpp
---
