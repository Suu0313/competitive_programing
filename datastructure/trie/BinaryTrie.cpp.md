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
  bundledCode: "#line 2 \"datastructure/trie/BinaryTrie.cpp\"\n\r\ntemplate<typename\
    \ T = unsigned,  int B = 32>\r\nstruct BinaryTrie{\r\n  vector<array<int, 2>>\
    \ to;\r\n  vector<size_t> sz, cnt;\r\n\r\n  BinaryTrie(): to(1, {0, 0}), sz(1),\
    \ cnt(1) {}\r\n\r\n  BinaryTrie(int n): to(1, {0, 0}), sz(1), cnt(1) {\r\n   \
    \ to.reserve(n); sz.reserve(n); cnt.reserve(n);\r\n  }\r\n\r\n  size_t size()\
    \ const { return sz[0]; }\r\n\r\n  bool empty() const { return !sz[0]; }\r\n\r\
    \n  size_t count(T x) const {\r\n    int pos = 0;\r\n    for(int i = B-1; i >=\
    \ 0; --i){\r\n      int j = x >> i & 1;\r\n      if(to[pos][j] == 0) return 0;\r\
    \n      pos = to[pos][j];\r\n    }\r\n    return cnt[pos];\r\n  }\r\n\r\n  int\
    \ insert(T x){\r\n    int pos = 0; ++sz[pos];\r\n    for(int i = B-1; i >= 0;\
    \ --i){\r\n      int j = x >> i & 1;\r\n      if(to[pos][j] == 0) to[pos][j] =\
    \ add_node();\r\n      ++sz[pos = to[pos][j]];\r\n    }\r\n    ++cnt[pos];\r\n\
    \    return pos;\r\n  }\r\n\r\n  int erase(T x){\r\n    int pos = 0;\r\n    for(int\
    \ i = B-1; i >= 0; --i){\r\n      int j = x >> i & 1;\r\n      if(to[pos][j] ==\
    \ 0 || !sz[to[pos][j]]) return -1;\r\n      pos = to[pos][j];\r\n    }\r\n\r\n\
    \    if(!cnt[pos]) return -1;\r\n\r\n    pos = 0; --sz[pos];\r\n    for(int i\
    \ = B-1; i >= 0; --i){\r\n      int j = x >> i & 1;\r\n      --sz[pos = to[pos][j]];\r\
    \n    }\r\n    --cnt[pos];\r\n    return pos;\r\n  }\r\n\r\n  T min(T x = 0) const\
    \ {\r\n    int pos = 0;\r\n    T mn = 0;\r\n    for(int i = B-1; i >= 0; --i){\r\
    \n      int j = x >> i & 1, k = j;\r\n      if(to[pos][j] == 0 || !sz[to[pos][j]])\
    \ j ^= 1;\r\n      if(to[pos][j] == 0 || !sz[to[pos][j]]) break;\r\n      if(j\
    \ != k) mn |= T(1) << i;\r\n      pos = to[pos][j];\r\n    }\r\n    return mn;\r\
    \n  }\r\n\r\n  /*\r\n  TODO: lb, ub, kth, max\r\n  //*/\r\n\r\nprivate:\r\n  size_t\
    \ add_node(){\r\n    size_t i = to.size();\r\n    to.push_back({0, 0});\r\n  \
    \  sz.push_back(0);\r\n    cnt.push_back(0);\r\n    return i;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T = unsigned,  int B = 32>\r\nstruct\
    \ BinaryTrie{\r\n  vector<array<int, 2>> to;\r\n  vector<size_t> sz, cnt;\r\n\r\
    \n  BinaryTrie(): to(1, {0, 0}), sz(1), cnt(1) {}\r\n\r\n  BinaryTrie(int n):\
    \ to(1, {0, 0}), sz(1), cnt(1) {\r\n    to.reserve(n); sz.reserve(n); cnt.reserve(n);\r\
    \n  }\r\n\r\n  size_t size() const { return sz[0]; }\r\n\r\n  bool empty() const\
    \ { return !sz[0]; }\r\n\r\n  size_t count(T x) const {\r\n    int pos = 0;\r\n\
    \    for(int i = B-1; i >= 0; --i){\r\n      int j = x >> i & 1;\r\n      if(to[pos][j]\
    \ == 0) return 0;\r\n      pos = to[pos][j];\r\n    }\r\n    return cnt[pos];\r\
    \n  }\r\n\r\n  int insert(T x){\r\n    int pos = 0; ++sz[pos];\r\n    for(int\
    \ i = B-1; i >= 0; --i){\r\n      int j = x >> i & 1;\r\n      if(to[pos][j] ==\
    \ 0) to[pos][j] = add_node();\r\n      ++sz[pos = to[pos][j]];\r\n    }\r\n  \
    \  ++cnt[pos];\r\n    return pos;\r\n  }\r\n\r\n  int erase(T x){\r\n    int pos\
    \ = 0;\r\n    for(int i = B-1; i >= 0; --i){\r\n      int j = x >> i & 1;\r\n\
    \      if(to[pos][j] == 0 || !sz[to[pos][j]]) return -1;\r\n      pos = to[pos][j];\r\
    \n    }\r\n\r\n    if(!cnt[pos]) return -1;\r\n\r\n    pos = 0; --sz[pos];\r\n\
    \    for(int i = B-1; i >= 0; --i){\r\n      int j = x >> i & 1;\r\n      --sz[pos\
    \ = to[pos][j]];\r\n    }\r\n    --cnt[pos];\r\n    return pos;\r\n  }\r\n\r\n\
    \  T min(T x = 0) const {\r\n    int pos = 0;\r\n    T mn = 0;\r\n    for(int\
    \ i = B-1; i >= 0; --i){\r\n      int j = x >> i & 1, k = j;\r\n      if(to[pos][j]\
    \ == 0 || !sz[to[pos][j]]) j ^= 1;\r\n      if(to[pos][j] == 0 || !sz[to[pos][j]])\
    \ break;\r\n      if(j != k) mn |= T(1) << i;\r\n      pos = to[pos][j];\r\n \
    \   }\r\n    return mn;\r\n  }\r\n\r\n  /*\r\n  TODO: lb, ub, kth, max\r\n  //*/\r\
    \n\r\nprivate:\r\n  size_t add_node(){\r\n    size_t i = to.size();\r\n    to.push_back({0,\
    \ 0});\r\n    sz.push_back(0);\r\n    cnt.push_back(0);\r\n    return i;\r\n \
    \ }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/trie/BinaryTrie.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/trie/BinaryTrie.cpp
layout: document
redirect_from:
- /library/datastructure/trie/BinaryTrie.cpp
- /library/datastructure/trie/BinaryTrie.cpp.html
title: datastructure/trie/BinaryTrie.cpp
---
