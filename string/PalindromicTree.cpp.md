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
  bundledCode: "#line 2 \"string/PalindromicTree.cpp\"\n\r\ntemplate<typename T =\
    \ char>\r\nstruct PalindromicTree{\r\nprivate:\r\n  struct Node{\r\n    map<T,\
    \ int> link;\r\n    int link_rev = -1;\r\n    int suffix_link = -1; // same suffix\
    \ maximum pal\r\n    int len; // palindrome length\r\n    int cnt; // freq of\
    \ this\r\n    int idx; // one of the start pos\r\n\r\n    Node() = default;\r\n\
    \    Node(int len, int cnt, int idx = -1): len(len), cnt(cnt), idx(idx) {}\r\n\
    \r\n    int succ(const T &c) const {\r\n      auto it = link.find(c);\r\n    \
    \  if(it == link.end()) return -1;\r\n      return it->second;\r\n    }\r\n  };\r\
    \n\r\n  // find longest P s.t. c + P + c is pal\r\n  int find_next_pal(int k)\
    \ const {\r\n    int pos = int(seq.size()) - 1;\r\n    while(true){\r\n      int\
    \ i = pos - 1 - nodes[k].len;\r\n      if(i >= 0 && seq[i] == seq[pos]) return\
    \ k;\r\n      k = nodes[k].suffix_link;\r\n    }\r\n  }\r\n\r\npublic:\r\n\r\n\
    \  vector<Node> nodes;\r\n  vector<T> seq;\r\n  vector<int> ston;\r\n  int suffix_max;\r\
    \n\r\n\r\n  PalindromicTree(){\r\n    nodes.emplace_back(-1, 0); // odd node\r\
    \n    nodes.emplace_back(0, 0); // even node\r\n    nodes[1].suffix_link = 0;\r\
    \n    suffix_max = 0;\r\n  }\r\n  template<class Iiter>\r\n  PalindromicTree(Iiter\
    \ first, Iiter last): PalindromicTree() {\r\n    add(first, last);\r\n  }\r\n\
    \  template<class Container>\r\n  PalindromicTree(const Container &c): PalindromicTree()\
    \ {\r\n    add(c);\r\n  }\r\n\r\n  void add(const T &c){\r\n    seq.push_back(c);\r\
    \n    int k = find_next_pal(suffix_max);\r\n\r\n    // c + P + c is already exists\r\
    \n    if(int p = nodes[k].succ(c); p != -1){\r\n      ++nodes[p].cnt;\r\n    \
    \  suffix_max = p;\r\n      ston.push_back(p);\r\n      return;\r\n    }\r\n\r\
    \n    // unique\r\n    nodes[k].link[c] = suffix_max = int(nodes.size());\r\n\
    \    ston.push_back(suffix_max);\r\n    int len = nodes[k].len + 2;\r\n    nodes.emplace_back(len,\
    \ 1, int(seq.size()) - len);\r\n    \r\n    nodes.back().link_rev = k;\r\n\r\n\
    \    if(len == 1) nodes.back().suffix_link = 1;\r\n    else nodes.back().suffix_link\
    \ = \r\n      nodes[find_next_pal(nodes[k].suffix_link)].link[c];\r\n  }\r\n\r\
    \n  template<class Iiter>\r\n  void add(Iiter first, Iiter last){\r\n    for(;\
    \ first != last; ++first) add(*first);\r\n  }\r\n  \r\n  template<class Container>\r\
    \n  void add(const Container &c){\r\n    add(begin(c), end(c));\r\n  }\r\n\r\n\
    \  // seq[i] = node[k].last\r\n  int get_node_idx(int i) const { return ston[i];\
    \ }\r\n\r\n  // idx of suffix palindromes of node k\r\n  vector<int> suffix_palindromes(int\
    \ k) const {\r\n    vector<int> ret;\r\n    for(; nodes[k].len > 0; k = nodes[k].suffix_link){\r\
    \n      ret.push_back(k);\r\n    }\r\n    return ret;\r\n  }\r\n\r\n  // idx of\
    \ suffix palindromes of seq\r\n  vector<int> suffix_palindromes() const {\r\n\
    \    return suffix_palindromes(suffix_max);\r\n  }\r\n\r\n  // idx of substring\
    \ palindromes of node k\r\n  vector<int> substr_palindroms(int k) const {\r\n\
    \    vector<int> ret, seen(nodes.size());\r\n    queue<int> qu;\r\n    qu.push(k);\
    \ seen[k] = 1;\r\n    for(; !qu.empty(); qu.pop()){\r\n      int v = qu.front();\r\
    \n      ret.push_back(v);\r\n      for(int u : {nodes[v].suffix_link, nodes[v].link_rev}){\r\
    \n        if(u == -1) continue;\r\n        if(!seen[u]) qu.push(u), seen[u] =\
    \ 1;\r\n      }\r\n    }\r\n    return ret;\r\n  }\r\n\r\n  // not count \"\"\r\
    \n  int count() const { return int(nodes.size()) - 2; }\r\n\r\n  vector<int> palindromes_frequency()\
    \ const {\r\n    int n = int(nodes.size());\r\n    vector<int> freq(n);\r\n  \
    \  for(int i = n - 1; i >= 1; --i){\r\n      freq[i] += nodes[i].cnt;\r\n    \
    \  freq[nodes[i].suffix_link] += freq[i];\r\n    }\r\n    return freq;\r\n  }\r\
    \n\r\n  const Node &operator[](int k) const { return nodes[k]; }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T = char>\r\nstruct PalindromicTree{\r\
    \nprivate:\r\n  struct Node{\r\n    map<T, int> link;\r\n    int link_rev = -1;\r\
    \n    int suffix_link = -1; // same suffix maximum pal\r\n    int len; // palindrome\
    \ length\r\n    int cnt; // freq of this\r\n    int idx; // one of the start pos\r\
    \n\r\n    Node() = default;\r\n    Node(int len, int cnt, int idx = -1): len(len),\
    \ cnt(cnt), idx(idx) {}\r\n\r\n    int succ(const T &c) const {\r\n      auto\
    \ it = link.find(c);\r\n      if(it == link.end()) return -1;\r\n      return\
    \ it->second;\r\n    }\r\n  };\r\n\r\n  // find longest P s.t. c + P + c is pal\r\
    \n  int find_next_pal(int k) const {\r\n    int pos = int(seq.size()) - 1;\r\n\
    \    while(true){\r\n      int i = pos - 1 - nodes[k].len;\r\n      if(i >= 0\
    \ && seq[i] == seq[pos]) return k;\r\n      k = nodes[k].suffix_link;\r\n    }\r\
    \n  }\r\n\r\npublic:\r\n\r\n  vector<Node> nodes;\r\n  vector<T> seq;\r\n  vector<int>\
    \ ston;\r\n  int suffix_max;\r\n\r\n\r\n  PalindromicTree(){\r\n    nodes.emplace_back(-1,\
    \ 0); // odd node\r\n    nodes.emplace_back(0, 0); // even node\r\n    nodes[1].suffix_link\
    \ = 0;\r\n    suffix_max = 0;\r\n  }\r\n  template<class Iiter>\r\n  PalindromicTree(Iiter\
    \ first, Iiter last): PalindromicTree() {\r\n    add(first, last);\r\n  }\r\n\
    \  template<class Container>\r\n  PalindromicTree(const Container &c): PalindromicTree()\
    \ {\r\n    add(c);\r\n  }\r\n\r\n  void add(const T &c){\r\n    seq.push_back(c);\r\
    \n    int k = find_next_pal(suffix_max);\r\n\r\n    // c + P + c is already exists\r\
    \n    if(int p = nodes[k].succ(c); p != -1){\r\n      ++nodes[p].cnt;\r\n    \
    \  suffix_max = p;\r\n      ston.push_back(p);\r\n      return;\r\n    }\r\n\r\
    \n    // unique\r\n    nodes[k].link[c] = suffix_max = int(nodes.size());\r\n\
    \    ston.push_back(suffix_max);\r\n    int len = nodes[k].len + 2;\r\n    nodes.emplace_back(len,\
    \ 1, int(seq.size()) - len);\r\n    \r\n    nodes.back().link_rev = k;\r\n\r\n\
    \    if(len == 1) nodes.back().suffix_link = 1;\r\n    else nodes.back().suffix_link\
    \ = \r\n      nodes[find_next_pal(nodes[k].suffix_link)].link[c];\r\n  }\r\n\r\
    \n  template<class Iiter>\r\n  void add(Iiter first, Iiter last){\r\n    for(;\
    \ first != last; ++first) add(*first);\r\n  }\r\n  \r\n  template<class Container>\r\
    \n  void add(const Container &c){\r\n    add(begin(c), end(c));\r\n  }\r\n\r\n\
    \  // seq[i] = node[k].last\r\n  int get_node_idx(int i) const { return ston[i];\
    \ }\r\n\r\n  // idx of suffix palindromes of node k\r\n  vector<int> suffix_palindromes(int\
    \ k) const {\r\n    vector<int> ret;\r\n    for(; nodes[k].len > 0; k = nodes[k].suffix_link){\r\
    \n      ret.push_back(k);\r\n    }\r\n    return ret;\r\n  }\r\n\r\n  // idx of\
    \ suffix palindromes of seq\r\n  vector<int> suffix_palindromes() const {\r\n\
    \    return suffix_palindromes(suffix_max);\r\n  }\r\n\r\n  // idx of substring\
    \ palindromes of node k\r\n  vector<int> substr_palindroms(int k) const {\r\n\
    \    vector<int> ret, seen(nodes.size());\r\n    queue<int> qu;\r\n    qu.push(k);\
    \ seen[k] = 1;\r\n    for(; !qu.empty(); qu.pop()){\r\n      int v = qu.front();\r\
    \n      ret.push_back(v);\r\n      for(int u : {nodes[v].suffix_link, nodes[v].link_rev}){\r\
    \n        if(u == -1) continue;\r\n        if(!seen[u]) qu.push(u), seen[u] =\
    \ 1;\r\n      }\r\n    }\r\n    return ret;\r\n  }\r\n\r\n  // not count \"\"\r\
    \n  int count() const { return int(nodes.size()) - 2; }\r\n\r\n  vector<int> palindromes_frequency()\
    \ const {\r\n    int n = int(nodes.size());\r\n    vector<int> freq(n);\r\n  \
    \  for(int i = n - 1; i >= 1; --i){\r\n      freq[i] += nodes[i].cnt;\r\n    \
    \  freq[nodes[i].suffix_link] += freq[i];\r\n    }\r\n    return freq;\r\n  }\r\
    \n\r\n  const Node &operator[](int k) const { return nodes[k]; }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/PalindromicTree.cpp
  requiredBy: []
  timestamp: '2023-03-10 19:33:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/PalindromicTree.cpp
layout: document
redirect_from:
- /library/string/PalindromicTree.cpp
- /library/string/PalindromicTree.cpp.html
title: string/PalindromicTree.cpp
---
