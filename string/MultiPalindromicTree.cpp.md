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
  bundledCode: "#line 2 \"string/MultiPalindromicTree.cpp\"\n\r\ntemplate<typename\
    \ T = char>\r\nstruct MultiPalindromicTree{\r\nprivate:\r\n  struct Node{\r\n\
    \    map<T, int> link;\r\n    int link_rev = -1;\r\n    int suffix_link = -1;\
    \ // same suffix maximum pal\r\n    int len; // palindrome length\r\n    vector<int>\
    \ cnt; // freq of this\r\n    pair<int, int> idx; // one of the start pos\r\n\r\
    \n    Node() = default;\r\n    Node(int n, int len): len(len), cnt(n, 0), idx(-1,\
    \ -1) {}\r\n\r\n    int succ(const T &c) const {\r\n      auto it = link.find(c);\r\
    \n      if(it == link.end()) return -1;\r\n      return it->second;\r\n    }\r\
    \n  };\r\n\r\n  // find longest P s.t. c + P + c is pal\r\n  int find_next_pal(int\
    \ p, int k) const {\r\n    int pos = int(seq[p].size()) - 1;\r\n    while(true){\r\
    \n      int i = pos - 1 - nodes[k].len;\r\n      if(i >= 0 && seq[p][i] == seq[p][pos])\
    \ return k;\r\n      k = nodes[k].suffix_link;\r\n    }\r\n  }\r\n\r\npublic:\r\
    \n\r\n  int n;\r\n  vector<Node> nodes;\r\n  vector<vector<T>> seq;\r\n  vector<vector<int>>\
    \ ston;\r\n  vector<int> suffix_max;\r\n\r\n\r\n  MultiPalindromicTree(int n):\
    \ n(n), seq(n), ston(n), suffix_max(n){\r\n    nodes.emplace_back(n, -1); // odd\
    \ node\r\n    nodes.emplace_back(n, 0); // even node\r\n    nodes[1].suffix_link\
    \ = 0;\r\n  }\r\n\r\n  void add(int i, const T &c){\r\n    seq[i].push_back(c);\r\
    \n    int k = find_next_pal(i, suffix_max[i]);\r\n\r\n    // c + P + c is already\
    \ exists\r\n    if(int p = nodes[k].succ(c); p != -1){\r\n      ++nodes[p].cnt[i];\r\
    \n      suffix_max[i] = p;\r\n      ston[i].push_back(p);\r\n      return;\r\n\
    \    }\r\n\r\n    // unique\r\n    nodes[k].link[c] = suffix_max[i] = int(nodes.size());\r\
    \n    ston[i].push_back(suffix_max[i]);\r\n    int len = nodes[k].len + 2;\r\n\
    \    nodes.emplace_back(n, len);\r\n    \r\n    nodes.back().cnt[i] = 1;\r\n \
    \   nodes.back().idx = {i, int(seq[i].size()) - len};\r\n    nodes.back().link_rev\
    \ = k;\r\n\r\n    if(len == 1) nodes.back().suffix_link = 1;\r\n    else nodes.back().suffix_link\
    \ = \r\n      nodes[find_next_pal(i, nodes[k].suffix_link)].link[c];\r\n  }\r\n\
    \r\n  template<class Iiter>\r\n  void add(int i, Iiter first, Iiter last){\r\n\
    \    for(; first != last; ++first) add(i, *first);\r\n  }\r\n  \r\n  template<class\
    \ Container>\r\n  void add(int i, const Container &c){\r\n    add(i, begin(c),\
    \ end(c));\r\n  }\r\n\r\n  // idx of suffix palindromes of node k\r\n  vector<int>\
    \ suffix_palindromes(int k) const {\r\n    vector<int> ret;\r\n    for(; nodes[k].len\
    \ > 0; k = nodes[k].suffix_link){\r\n      ret.push_back(k);\r\n    }\r\n    return\
    \ ret;\r\n  }\r\n\r\n  // idx of substring palindromes of node k\r\n  vector<int>\
    \ substr_palindroms(int k) const {\r\n    vector<int> ret, seen(nodes.size());\r\
    \n    queue<int> qu;\r\n    qu.push(k); seen[k] = 1;\r\n    for(; !qu.empty();\
    \ qu.pop()){\r\n      int v = qu.front();\r\n      ret.push_back(v);\r\n     \
    \ for(int u : {nodes[v].suffix_link, nodes[v].link_rev}){\r\n        if(!seen[u])\
    \ qu.push(u), seen[u] = 1;\r\n      }\r\n    }\r\n    return ret;\r\n  }\r\n\r\
    \n  // not count \"\"\r\n  int count() const { return int(nodes.size()) - 2; }\r\
    \n\r\n  vector<vector<int>> palindromes_frequency() const {\r\n    int m = int(nodes.size());\r\
    \n    vector<vector<int>> freq(m, vector<int>(n));\r\n    for(int i = m - 1; i\
    \ >= 1; --i){\r\n      for(int j = 0; j < n; ++j){\r\n        freq[i][j] += nodes[i].cnt[j];\r\
    \n        freq[nodes[i].suffix_link][j] += freq[i][j];\r\n      }\r\n    }\r\n\
    \    return freq;\r\n  }\r\n\r\n  const Node &operator[](int k) const { return\
    \ nodes[k]; }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T = char>\r\nstruct MultiPalindromicTree{\r\
    \nprivate:\r\n  struct Node{\r\n    map<T, int> link;\r\n    int link_rev = -1;\r\
    \n    int suffix_link = -1; // same suffix maximum pal\r\n    int len; // palindrome\
    \ length\r\n    vector<int> cnt; // freq of this\r\n    pair<int, int> idx; //\
    \ one of the start pos\r\n\r\n    Node() = default;\r\n    Node(int n, int len):\
    \ len(len), cnt(n, 0), idx(-1, -1) {}\r\n\r\n    int succ(const T &c) const {\r\
    \n      auto it = link.find(c);\r\n      if(it == link.end()) return -1;\r\n \
    \     return it->second;\r\n    }\r\n  };\r\n\r\n  // find longest P s.t. c +\
    \ P + c is pal\r\n  int find_next_pal(int p, int k) const {\r\n    int pos = int(seq[p].size())\
    \ - 1;\r\n    while(true){\r\n      int i = pos - 1 - nodes[k].len;\r\n      if(i\
    \ >= 0 && seq[p][i] == seq[p][pos]) return k;\r\n      k = nodes[k].suffix_link;\r\
    \n    }\r\n  }\r\n\r\npublic:\r\n\r\n  int n;\r\n  vector<Node> nodes;\r\n  vector<vector<T>>\
    \ seq;\r\n  vector<vector<int>> ston;\r\n  vector<int> suffix_max;\r\n\r\n\r\n\
    \  MultiPalindromicTree(int n): n(n), seq(n), ston(n), suffix_max(n){\r\n    nodes.emplace_back(n,\
    \ -1); // odd node\r\n    nodes.emplace_back(n, 0); // even node\r\n    nodes[1].suffix_link\
    \ = 0;\r\n  }\r\n\r\n  void add(int i, const T &c){\r\n    seq[i].push_back(c);\r\
    \n    int k = find_next_pal(i, suffix_max[i]);\r\n\r\n    // c + P + c is already\
    \ exists\r\n    if(int p = nodes[k].succ(c); p != -1){\r\n      ++nodes[p].cnt[i];\r\
    \n      suffix_max[i] = p;\r\n      ston[i].push_back(p);\r\n      return;\r\n\
    \    }\r\n\r\n    // unique\r\n    nodes[k].link[c] = suffix_max[i] = int(nodes.size());\r\
    \n    ston[i].push_back(suffix_max[i]);\r\n    int len = nodes[k].len + 2;\r\n\
    \    nodes.emplace_back(n, len);\r\n    \r\n    nodes.back().cnt[i] = 1;\r\n \
    \   nodes.back().idx = {i, int(seq[i].size()) - len};\r\n    nodes.back().link_rev\
    \ = k;\r\n\r\n    if(len == 1) nodes.back().suffix_link = 1;\r\n    else nodes.back().suffix_link\
    \ = \r\n      nodes[find_next_pal(i, nodes[k].suffix_link)].link[c];\r\n  }\r\n\
    \r\n  template<class Iiter>\r\n  void add(int i, Iiter first, Iiter last){\r\n\
    \    for(; first != last; ++first) add(i, *first);\r\n  }\r\n  \r\n  template<class\
    \ Container>\r\n  void add(int i, const Container &c){\r\n    add(i, begin(c),\
    \ end(c));\r\n  }\r\n\r\n  // idx of suffix palindromes of node k\r\n  vector<int>\
    \ suffix_palindromes(int k) const {\r\n    vector<int> ret;\r\n    for(; nodes[k].len\
    \ > 0; k = nodes[k].suffix_link){\r\n      ret.push_back(k);\r\n    }\r\n    return\
    \ ret;\r\n  }\r\n\r\n  // idx of substring palindromes of node k\r\n  vector<int>\
    \ substr_palindroms(int k) const {\r\n    vector<int> ret, seen(nodes.size());\r\
    \n    queue<int> qu;\r\n    qu.push(k); seen[k] = 1;\r\n    for(; !qu.empty();\
    \ qu.pop()){\r\n      int v = qu.front();\r\n      ret.push_back(v);\r\n     \
    \ for(int u : {nodes[v].suffix_link, nodes[v].link_rev}){\r\n        if(!seen[u])\
    \ qu.push(u), seen[u] = 1;\r\n      }\r\n    }\r\n    return ret;\r\n  }\r\n\r\
    \n  // not count \"\"\r\n  int count() const { return int(nodes.size()) - 2; }\r\
    \n\r\n  vector<vector<int>> palindromes_frequency() const {\r\n    int m = int(nodes.size());\r\
    \n    vector<vector<int>> freq(m, vector<int>(n));\r\n    for(int i = m - 1; i\
    \ >= 1; --i){\r\n      for(int j = 0; j < n; ++j){\r\n        freq[i][j] += nodes[i].cnt[j];\r\
    \n        freq[nodes[i].suffix_link][j] += freq[i][j];\r\n      }\r\n    }\r\n\
    \    return freq;\r\n  }\r\n\r\n  const Node &operator[](int k) const { return\
    \ nodes[k]; }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/MultiPalindromicTree.cpp
  requiredBy: []
  timestamp: '2023-03-10 19:28:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/MultiPalindromicTree.cpp
layout: document
redirect_from:
- /library/string/MultiPalindromicTree.cpp
- /library/string/MultiPalindromicTree.cpp.html
title: string/MultiPalindromicTree.cpp
---
