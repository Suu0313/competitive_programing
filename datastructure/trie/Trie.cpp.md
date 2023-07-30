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
  bundledCode: "#line 2 \"datastructure/trie/Trie.cpp\"\n\r\ntemplate<typename T>\r\
    \nstruct Trie{\r\n  Trie(): ptr(1), sz(1) {}\r\n\r\n  vector<map<T, size_t>> ptr;\r\
    \n  vector<size_t> sz;\r\n\r\n  template<class Iter>\r\n  int add(Iter first,\
    \ Iter last){\r\n    int i = 0; ++sz[0];\r\n    for(; first != last; ++first){\r\
    \n      T c = *first;\r\n      if(auto it = ptr[i].find(c); it == ptr[i].end()){\r\
    \n        ptr[i][c] = sz.size();\r\n        sz.push_back(0);\r\n        ptr.push_back({});\r\
    \n      }\r\n      sz[i = ptr[i][c]] += 1;\r\n    }\r\n    return i;\r\n  }\r\n\
    \r\n  template<class Container>\r\n  int add(const Container &c){  return add(begin(c),\
    \ end(c)); }\r\n\r\n  template<class Iter>\r\n  int cnt(Iter first, Iter last)\
    \ const {\r\n    int i = 0;\r\n    for(; first != last; ++first){\r\n      T c\
    \ = *first;\r\n      if(const auto it = ptr[i].find(c); it == ptr[i].end()){\r\
    \n        return 0;\r\n      }\r\n      i = ptr[i][c];\r\n    }\r\n    return\
    \ sz[i];\r\n  }\r\n\r\n  template<class Container>\r\n  size_t cnt(const Container\
    \ &c) const { return cnt(begin(c), end(c)); }\r\n\r\n  vector<vector<int>> get_graph()\
    \ const {\r\n    int n = int(sz.size());\r\n    vector<vector<int>> g(n);\r\n\
    \    for(int i = 0; i < n; ++i){\r\n      for(const auto[c, to] : ptr[i]) g[i].push_back(to);\r\
    \n    }\r\n    return g;\r\n  }\r\n\r\n  int succ(int p, const T &c) const {\r\
    \n    if(ptr[p].find(c) == ptr[p].end()) return -1;\r\n    return ptr[p].at(c);\r\
    \n  }\r\n\r\n  size_t size() const { return sz.size(); }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct Trie{\r\n  Trie(): ptr(1),\
    \ sz(1) {}\r\n\r\n  vector<map<T, size_t>> ptr;\r\n  vector<size_t> sz;\r\n\r\n\
    \  template<class Iter>\r\n  int add(Iter first, Iter last){\r\n    int i = 0;\
    \ ++sz[0];\r\n    for(; first != last; ++first){\r\n      T c = *first;\r\n  \
    \    if(auto it = ptr[i].find(c); it == ptr[i].end()){\r\n        ptr[i][c] =\
    \ sz.size();\r\n        sz.push_back(0);\r\n        ptr.push_back({});\r\n   \
    \   }\r\n      sz[i = ptr[i][c]] += 1;\r\n    }\r\n    return i;\r\n  }\r\n\r\n\
    \  template<class Container>\r\n  int add(const Container &c){  return add(begin(c),\
    \ end(c)); }\r\n\r\n  template<class Iter>\r\n  int cnt(Iter first, Iter last)\
    \ const {\r\n    int i = 0;\r\n    for(; first != last; ++first){\r\n      T c\
    \ = *first;\r\n      if(const auto it = ptr[i].find(c); it == ptr[i].end()){\r\
    \n        return 0;\r\n      }\r\n      i = ptr[i][c];\r\n    }\r\n    return\
    \ sz[i];\r\n  }\r\n\r\n  template<class Container>\r\n  size_t cnt(const Container\
    \ &c) const { return cnt(begin(c), end(c)); }\r\n\r\n  vector<vector<int>> get_graph()\
    \ const {\r\n    int n = int(sz.size());\r\n    vector<vector<int>> g(n);\r\n\
    \    for(int i = 0; i < n; ++i){\r\n      for(const auto[c, to] : ptr[i]) g[i].push_back(to);\r\
    \n    }\r\n    return g;\r\n  }\r\n\r\n  int succ(int p, const T &c) const {\r\
    \n    if(ptr[p].find(c) == ptr[p].end()) return -1;\r\n    return ptr[p].at(c);\r\
    \n  }\r\n\r\n  size_t size() const { return sz.size(); }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/trie/Trie.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/trie/Trie.cpp
layout: document
redirect_from:
- /library/datastructure/trie/Trie.cpp
- /library/datastructure/trie/Trie.cpp.html
title: datastructure/trie/Trie.cpp
---
