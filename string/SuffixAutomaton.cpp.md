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
  bundledCode: "#line 2 \"string/SuffixAutomaton.cpp\"\n\r\ntemplate<typename T =\
    \ char>\r\nstruct SuffixAutomaton{\r\n  using Mp = map<T, int>;\r\n\r\n  struct\
    \ Node{\r\n    Mp next;\r\n    int len, link, id;\r\n    bool is_clone;\r\n  \
    \  Node(const Mp &next, int len, int link, int id, bool is_clone)\r\n    : next(next),\
    \ len(len), link(link), id(id), is_clone(is_clone) {}\r\n\r\n    Node(Node&&)\
    \ = default;\r\n    bool contains(T c) const { return next.find(c) != next.end();\
    \ }\r\n  };\r\n\r\n  vector<Node> nodes;\r\n  int last = 0, gen = 0;\r\n\r\n \
    \ SuffixAutomaton() { make_node(0); }\r\n  template<typename Container>\r\n  SuffixAutomaton(const\
    \ Container &s): SuffixAutomaton() {\r\n    for(auto&&c : s) push(c);\r\n    sort_topologically();\r\
    \n  }\r\n  SuffixAutomaton(const SuffixAutomaton&) = default;\r\n  SuffixAutomaton(SuffixAutomaton&&)\
    \ = default;\r\n\r\n  int make_node(int len){\r\n    int p = int(nodes.size());\r\
    \n    nodes.emplace_back(Mp{}, len, -1, gen++, false);\r\n    return p;\r\n  }\r\
    \n\r\n  int make_node(const Mp &next, int len, int link, bool is_clone){\r\n \
    \   int p = int(nodes.size());\r\n    nodes.emplace_back(next, len, link, gen++,\
    \ is_clone);\r\n    return p;\r\n  }\r\n\r\n  void push(T c){\r\n    int cur =\
    \ make_node(nodes[last].len + 1);\r\n    int p = last;\r\n\r\n    for(; (p !=\
    \ -1) && !nodes[p].contains(c); p = nodes[p].link){\r\n      nodes[p].next[c]\
    \ = cur;\r\n    }\r\n\r\n    int q = (p == -1 ? 0 : nodes[p].next[c]);\r\n   \
    \ if(p == -1 || nodes[p].len+1 == nodes[q].len){\r\n      nodes[cur].link = q;\r\
    \n    }else{\r\n      int nq = make_node(nodes[q].next, nodes[p].len + 1, nodes[q].link,\
    \ true);\r\n      nodes[q].link = nq;\r\n      nodes[cur].link = nq;\r\n\r\n \
    \     for(; p != -1 && nodes[p].next[c] == q; p = nodes[p].link){\r\n        nodes[p].next[c]\
    \ = nq;\r\n      }\r\n    }\r\n    last = cur;\r\n  }\r\n\r\n  void sort_topologically(){\r\
    \n    vector<int> idx; idx.reserve(gen);\r\n    {\r\n      vector<vector<int>>\
    \ base(gen + 1);\r\n      for(int i = 0; i < gen; ++i) base[nodes[i].len].push_back(i);\r\
    \n      for(auto&v : base){\r\n        if(v.empty()) continue;\r\n        idx.insert(end(idx),\
    \ begin(v), end(v));\r\n      }\r\n    }\r\n    vector<int> rev(gen);\r\n    for(int\
    \ i = 0; i < gen; ++i) rev[idx[i]] = i;\r\n    {\r\n      vector<Node> tmp; tmp.reserve(gen);\r\
    \n      for(int i = 0; i < gen; ++i) tmp.emplace_back(move(nodes[idx[i]]));\r\n\
    \      swap(nodes, tmp);\r\n    }\r\n\r\n    for(auto&node : nodes){\r\n     \
    \ for(auto&[c, j] : node.next) j = rev[j];\r\n      if(node.link != -1) node.link\
    \ = rev[node.link];\r\n    }\r\n  }\r\n\r\n  size_t size() const { return nodes.size();\
    \ }\r\n\r\n  template<typename Container>\r\n  int find(const Container &s) const\
    \ {\r\n    int cur = 0;\r\n    for(auto&&c : s){\r\n      if(!nodes[cur].contains(c))\
    \ return -1;\r\n      cur = nodes[cur].next.at(c);\r\n    }\r\n    return cur;\r\
    \n  }\r\n\r\n\r\n  int64_t number_of_substrings() const {\r\n    int64_t res =\
    \ 0;\r\n    for(int i = 1; i < gen; ++i){\r\n      res += nodes[i].len - nodes[nodes[i].link].len;\r\
    \n    }\r\n    return res;\r\n  }\r\n\r\n  int64_t number_of_substrings_dp(){\r\
    \n    vector<int64_t> dp(gen);\r\n    dp[0] = 1;\r\n    int64_t res = 0;\r\n \
    \   for(int i = 0; i < gen; ++i){\r\n      res += dp[i];\r\n      for(auto&[c,\
    \ j] : nodes[i].next){\r\n        dp[j] += dp[i];\r\n      }\r\n    }\r\n    --res;\r\
    \n    return res;\r\n  }\r\n\r\n  vector<int> enum_number_of_substrs(){\r\n  \
    \  vector<int> dp(gen);\r\n    for(int i = gen-1; i >= 1; --i){\r\n      if(!nodes[i].is_clone)\
    \ ++dp[i];\r\n      dp[nodes[i].link] += dp[i];\r\n    }\r\n    return dp;\r\n\
    \  }\r\n\r\n  template<typename Container>\r\n  int number_of_substring(const\
    \ Container &s){\r\n    int cur = this->find(s);\r\n    if(cur == -1) return 0;\r\
    \n    return enum_number_of_substrs[cur];\r\n  }\r\n\r\n  vector<vector<T>> enumerate_substrs()\
    \ const {\r\n    vector<vector<T>> res;\r\n    stack<pair<int, vector<T>>> st;\r\
    \n    st.emplace(0, vector<T>{});\r\n    while(!st.empty()){\r\n      auto[i,\
    \ s] = st.top(); st.pop();\r\n      res.emplace_back(s);\r\n      for(auto&[c,\
    \ j] : nodes[i].next){\r\n        s.push_back(c);\r\n        st.emplace(j, s);\r\
    \n        s.pop_back();\r\n      }\r\n    }\r\n    return res;\r\n  }\r\n\r\n\
    \  template<typename Container>\r\n  vector<T> longest_common_substr(const Container\
    \ &s) const {\r\n    int n = int(s.size());\r\n    if(n == 0) return {};\r\n \
    \   int v = 0, mx = 0, mxp = 0;\r\n    for(int i = 0, l = 0; i < n; ++i){\r\n\
    \      while(v != 0 && !nodes[v].contains(s[i])){\r\n        v = nodes[v].link;\r\
    \n        l = nodes[v].len;\r\n      }\r\n      if(nodes[v].contains(s[i])){\r\
    \n        v = nodes[v].next.at(s[i]);\r\n        ++l;\r\n      }\r\n      if(mx\
    \ < l){\r\n        mx = l; mxp = i;\r\n      }\r\n    }\r\n    return {begin(s)\
    \ + mxp-mx+1, begin(s)+mxp+1};\r\n  }\r\n\r\n  vector<int> enum_first_occurs()\
    \ const {\r\n    vector<int> to(gen, 1e9);\r\n    for(int i = gen-1; i >= 0; --i){\r\
    \n      if(!nodes[i].is_clone) to[i] = nodes[i].len;\r\n      \r\n      if(i &&\
    \ nodes[nodes[i].link].is_clone && to[i] > to[nodes[i].link]){\r\n        to[nodes[i].link]\
    \ = to[i];\r\n      }\r\n    }\r\n    return to;\r\n  }\r\n  \r\n  vector<int64_t>\
    \ number_of_substrings_dp2() const {\r\n    vector<int64_t> dp(gen);\r\n    for(int\
    \ i = gen-1; i >= 0; --i){\r\n      dp[i] = 1;\r\n      for(const auto&[c, j]\
    \ : nodes[i].next){\r\n        dp[i] += dp[j];\r\n      }\r\n    }\r\n    return\
    \ dp;\r\n  }\r\n\r\n  vector<T> kth_substring(int64_t k) const {\r\n    if(k <=\
    \ 0) return {};\r\n    vector<int64_t> dp = number_of_substrings_dp2();\r\n  \
    \  if(dp[0] <= k) return {};\r\n\r\n    int i = 0;\r\n    vector<T> res;\r\n \
    \   while(k > 0){\r\n      --k;\r\n      for(const auto&[c, j] : nodes[i].next){\r\
    \n        if(k < dp[j]){\r\n          res.push_back(c);\r\n          i = j;\r\n\
    \          break;\r\n        }else{\r\n          k -= dp[j];\r\n        }\r\n\
    \      }\r\n    }\r\n    return res;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T = char>\r\nstruct SuffixAutomaton{\r\
    \n  using Mp = map<T, int>;\r\n\r\n  struct Node{\r\n    Mp next;\r\n    int len,\
    \ link, id;\r\n    bool is_clone;\r\n    Node(const Mp &next, int len, int link,\
    \ int id, bool is_clone)\r\n    : next(next), len(len), link(link), id(id), is_clone(is_clone)\
    \ {}\r\n\r\n    Node(Node&&) = default;\r\n    bool contains(T c) const { return\
    \ next.find(c) != next.end(); }\r\n  };\r\n\r\n  vector<Node> nodes;\r\n  int\
    \ last = 0, gen = 0;\r\n\r\n  SuffixAutomaton() { make_node(0); }\r\n  template<typename\
    \ Container>\r\n  SuffixAutomaton(const Container &s): SuffixAutomaton() {\r\n\
    \    for(auto&&c : s) push(c);\r\n    sort_topologically();\r\n  }\r\n  SuffixAutomaton(const\
    \ SuffixAutomaton&) = default;\r\n  SuffixAutomaton(SuffixAutomaton&&) = default;\r\
    \n\r\n  int make_node(int len){\r\n    int p = int(nodes.size());\r\n    nodes.emplace_back(Mp{},\
    \ len, -1, gen++, false);\r\n    return p;\r\n  }\r\n\r\n  int make_node(const\
    \ Mp &next, int len, int link, bool is_clone){\r\n    int p = int(nodes.size());\r\
    \n    nodes.emplace_back(next, len, link, gen++, is_clone);\r\n    return p;\r\
    \n  }\r\n\r\n  void push(T c){\r\n    int cur = make_node(nodes[last].len + 1);\r\
    \n    int p = last;\r\n\r\n    for(; (p != -1) && !nodes[p].contains(c); p = nodes[p].link){\r\
    \n      nodes[p].next[c] = cur;\r\n    }\r\n\r\n    int q = (p == -1 ? 0 : nodes[p].next[c]);\r\
    \n    if(p == -1 || nodes[p].len+1 == nodes[q].len){\r\n      nodes[cur].link\
    \ = q;\r\n    }else{\r\n      int nq = make_node(nodes[q].next, nodes[p].len +\
    \ 1, nodes[q].link, true);\r\n      nodes[q].link = nq;\r\n      nodes[cur].link\
    \ = nq;\r\n\r\n      for(; p != -1 && nodes[p].next[c] == q; p = nodes[p].link){\r\
    \n        nodes[p].next[c] = nq;\r\n      }\r\n    }\r\n    last = cur;\r\n  }\r\
    \n\r\n  void sort_topologically(){\r\n    vector<int> idx; idx.reserve(gen);\r\
    \n    {\r\n      vector<vector<int>> base(gen + 1);\r\n      for(int i = 0; i\
    \ < gen; ++i) base[nodes[i].len].push_back(i);\r\n      for(auto&v : base){\r\n\
    \        if(v.empty()) continue;\r\n        idx.insert(end(idx), begin(v), end(v));\r\
    \n      }\r\n    }\r\n    vector<int> rev(gen);\r\n    for(int i = 0; i < gen;\
    \ ++i) rev[idx[i]] = i;\r\n    {\r\n      vector<Node> tmp; tmp.reserve(gen);\r\
    \n      for(int i = 0; i < gen; ++i) tmp.emplace_back(move(nodes[idx[i]]));\r\n\
    \      swap(nodes, tmp);\r\n    }\r\n\r\n    for(auto&node : nodes){\r\n     \
    \ for(auto&[c, j] : node.next) j = rev[j];\r\n      if(node.link != -1) node.link\
    \ = rev[node.link];\r\n    }\r\n  }\r\n\r\n  size_t size() const { return nodes.size();\
    \ }\r\n\r\n  template<typename Container>\r\n  int find(const Container &s) const\
    \ {\r\n    int cur = 0;\r\n    for(auto&&c : s){\r\n      if(!nodes[cur].contains(c))\
    \ return -1;\r\n      cur = nodes[cur].next.at(c);\r\n    }\r\n    return cur;\r\
    \n  }\r\n\r\n\r\n  int64_t number_of_substrings() const {\r\n    int64_t res =\
    \ 0;\r\n    for(int i = 1; i < gen; ++i){\r\n      res += nodes[i].len - nodes[nodes[i].link].len;\r\
    \n    }\r\n    return res;\r\n  }\r\n\r\n  int64_t number_of_substrings_dp(){\r\
    \n    vector<int64_t> dp(gen);\r\n    dp[0] = 1;\r\n    int64_t res = 0;\r\n \
    \   for(int i = 0; i < gen; ++i){\r\n      res += dp[i];\r\n      for(auto&[c,\
    \ j] : nodes[i].next){\r\n        dp[j] += dp[i];\r\n      }\r\n    }\r\n    --res;\r\
    \n    return res;\r\n  }\r\n\r\n  vector<int> enum_number_of_substrs(){\r\n  \
    \  vector<int> dp(gen);\r\n    for(int i = gen-1; i >= 1; --i){\r\n      if(!nodes[i].is_clone)\
    \ ++dp[i];\r\n      dp[nodes[i].link] += dp[i];\r\n    }\r\n    return dp;\r\n\
    \  }\r\n\r\n  template<typename Container>\r\n  int number_of_substring(const\
    \ Container &s){\r\n    int cur = this->find(s);\r\n    if(cur == -1) return 0;\r\
    \n    return enum_number_of_substrs[cur];\r\n  }\r\n\r\n  vector<vector<T>> enumerate_substrs()\
    \ const {\r\n    vector<vector<T>> res;\r\n    stack<pair<int, vector<T>>> st;\r\
    \n    st.emplace(0, vector<T>{});\r\n    while(!st.empty()){\r\n      auto[i,\
    \ s] = st.top(); st.pop();\r\n      res.emplace_back(s);\r\n      for(auto&[c,\
    \ j] : nodes[i].next){\r\n        s.push_back(c);\r\n        st.emplace(j, s);\r\
    \n        s.pop_back();\r\n      }\r\n    }\r\n    return res;\r\n  }\r\n\r\n\
    \  template<typename Container>\r\n  vector<T> longest_common_substr(const Container\
    \ &s) const {\r\n    int n = int(s.size());\r\n    if(n == 0) return {};\r\n \
    \   int v = 0, mx = 0, mxp = 0;\r\n    for(int i = 0, l = 0; i < n; ++i){\r\n\
    \      while(v != 0 && !nodes[v].contains(s[i])){\r\n        v = nodes[v].link;\r\
    \n        l = nodes[v].len;\r\n      }\r\n      if(nodes[v].contains(s[i])){\r\
    \n        v = nodes[v].next.at(s[i]);\r\n        ++l;\r\n      }\r\n      if(mx\
    \ < l){\r\n        mx = l; mxp = i;\r\n      }\r\n    }\r\n    return {begin(s)\
    \ + mxp-mx+1, begin(s)+mxp+1};\r\n  }\r\n\r\n  vector<int> enum_first_occurs()\
    \ const {\r\n    vector<int> to(gen, 1e9);\r\n    for(int i = gen-1; i >= 0; --i){\r\
    \n      if(!nodes[i].is_clone) to[i] = nodes[i].len;\r\n      \r\n      if(i &&\
    \ nodes[nodes[i].link].is_clone && to[i] > to[nodes[i].link]){\r\n        to[nodes[i].link]\
    \ = to[i];\r\n      }\r\n    }\r\n    return to;\r\n  }\r\n  \r\n  vector<int64_t>\
    \ number_of_substrings_dp2() const {\r\n    vector<int64_t> dp(gen);\r\n    for(int\
    \ i = gen-1; i >= 0; --i){\r\n      dp[i] = 1;\r\n      for(const auto&[c, j]\
    \ : nodes[i].next){\r\n        dp[i] += dp[j];\r\n      }\r\n    }\r\n    return\
    \ dp;\r\n  }\r\n\r\n  vector<T> kth_substring(int64_t k) const {\r\n    if(k <=\
    \ 0) return {};\r\n    vector<int64_t> dp = number_of_substrings_dp2();\r\n  \
    \  if(dp[0] <= k) return {};\r\n\r\n    int i = 0;\r\n    vector<T> res;\r\n \
    \   while(k > 0){\r\n      --k;\r\n      for(const auto&[c, j] : nodes[i].next){\r\
    \n        if(k < dp[j]){\r\n          res.push_back(c);\r\n          i = j;\r\n\
    \          break;\r\n        }else{\r\n          k -= dp[j];\r\n        }\r\n\
    \      }\r\n    }\r\n    return res;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/SuffixAutomaton.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/SuffixAutomaton.cpp
layout: document
redirect_from:
- /library/string/SuffixAutomaton.cpp
- /library/string/SuffixAutomaton.cpp.html
title: string/SuffixAutomaton.cpp
---
