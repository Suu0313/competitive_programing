---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: string/z_algorithm.cpp
    title: string/z_algorithm.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/run_enumerate.cpp\"\n\r\n#line 2 \"string/z_algorithm.cpp\"\
    \n\r\ntemplate<typename Container>\r\nvector<int> z_algorithm(const Container\
    \ &s){\r\n  int n = int(s.size());\r\n  vector<int> z(n + 1); z[0] = n;\r\n  int\
    \ i = 1, j = 0;\r\n  \r\n  while(i < n){\r\n    while(i+j < n && s[j] == s[i+j])\
    \ ++j;\r\n    z[i] = j;\r\n    if(j==0){i++; continue;}\r\n    \r\n    int k =\
    \ 1;\r\n    while(k<j && k+z[k] < j){\r\n      z[i+k] = z[k]; ++k;\r\n    }\r\n\
    \    i += k; j -= k;\r\n  }\r\n  return z;\r\n}\r\n#line 4 \"string/run_enumerate.cpp\"\
    \n\r\ntemplate<typename Container> // (p, l, r)\r\nvector<tuple<int, int, int>>\
    \ run_enumerate(const Container &s){\r\n  auto solve_impl = [](Container l, Container\
    \ r){\r\n    int n = int(l.size()), m = int(r.size());\r\n    r.reserve(n + m*2);\r\
    \n    for(int i = 0; i < n; i++) r.push_back(l[i]);\r\n    for(int i = 0; i <\
    \ m; i++) r.push_back(r[i]);\r\n    reverse(begin(l), end(l));\r\n    vector<int>\
    \ lz = z_algorithm(l), rz = z_algorithm(r);\r\n    vector<tuple<int, int, int>>\
    \ res;\r\n\r\n    for(int p = 1; p <= n; ++p){\r\n      int a = (p == n ? p :\
    \ lz[p] + p);\r\n      int b = min(rz[n + m - p], m);\r\n      if(a + b < 2 *\
    \ p) continue;\r\n      res.emplace_back(p, a, b);\r\n    }\r\n\r\n    return\
    \ res;\r\n  };\r\n\r\n  int n = int(s.size());\r\n\r\n  stack<pair<int, int>>\
    \ st; st.emplace(0, n);\r\n  vector<vector<pair<int, int>>> ps(n + 1);\r\n\r\n\
    \  while(!st.empty()){\r\n    auto[l, r] = st.top(); st.pop();\r\n    if(l+1 >=\
    \ r) continue;\r\n    int m = (l + r)/2;\r\n    st.emplace(l, m); st.emplace(m,\
    \ r);\r\n\r\n    Container ls(begin(s) + l, begin(s) + m), rs(begin(s) + m, begin(s)\
    \ + r);\r\n\r\n    for(auto&&[p, a, b] : solve_impl(ls, rs)) ps[p].emplace_back(m\
    \ - a, m + b);\r\n    reverse(begin(ls), end(ls)); reverse(begin(rs), end(rs));\r\
    \n    for(auto&&[p, a, b] : solve_impl(rs, ls)) ps[p].emplace_back(m - b, m +\
    \ a);\r\n  }\r\n\r\n  vector<tuple<int, int, int>> res;\r\n  set<pair<int, int>>\
    \ seen;\r\n  for(int p = 1; p <= n; ++p){\r\n    sort(begin(ps[p]), end(ps[p]),\r\
    \n      [](auto &x, auto &y){ return make_pair(x.first, -x.second) < make_pair(y.first,\
    \ -y.second); });\r\n\r\n    int nr = -1;\r\n    for(auto&&[l, r] : ps[p]){\r\n\
    \      if(nr < r){\r\n        nr = r;\r\n        if(seen.count({l, r})) continue;\r\
    \n        seen.emplace(l, r);\r\n        res.emplace_back(p, l, r);\r\n      }\r\
    \n    }\r\n  }\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n\r\n#include \"./z_algorithm.cpp\"\r\n\r\ntemplate<typename\
    \ Container> // (p, l, r)\r\nvector<tuple<int, int, int>> run_enumerate(const\
    \ Container &s){\r\n  auto solve_impl = [](Container l, Container r){\r\n    int\
    \ n = int(l.size()), m = int(r.size());\r\n    r.reserve(n + m*2);\r\n    for(int\
    \ i = 0; i < n; i++) r.push_back(l[i]);\r\n    for(int i = 0; i < m; i++) r.push_back(r[i]);\r\
    \n    reverse(begin(l), end(l));\r\n    vector<int> lz = z_algorithm(l), rz =\
    \ z_algorithm(r);\r\n    vector<tuple<int, int, int>> res;\r\n\r\n    for(int\
    \ p = 1; p <= n; ++p){\r\n      int a = (p == n ? p : lz[p] + p);\r\n      int\
    \ b = min(rz[n + m - p], m);\r\n      if(a + b < 2 * p) continue;\r\n      res.emplace_back(p,\
    \ a, b);\r\n    }\r\n\r\n    return res;\r\n  };\r\n\r\n  int n = int(s.size());\r\
    \n\r\n  stack<pair<int, int>> st; st.emplace(0, n);\r\n  vector<vector<pair<int,\
    \ int>>> ps(n + 1);\r\n\r\n  while(!st.empty()){\r\n    auto[l, r] = st.top();\
    \ st.pop();\r\n    if(l+1 >= r) continue;\r\n    int m = (l + r)/2;\r\n    st.emplace(l,\
    \ m); st.emplace(m, r);\r\n\r\n    Container ls(begin(s) + l, begin(s) + m), rs(begin(s)\
    \ + m, begin(s) + r);\r\n\r\n    for(auto&&[p, a, b] : solve_impl(ls, rs)) ps[p].emplace_back(m\
    \ - a, m + b);\r\n    reverse(begin(ls), end(ls)); reverse(begin(rs), end(rs));\r\
    \n    for(auto&&[p, a, b] : solve_impl(rs, ls)) ps[p].emplace_back(m - b, m +\
    \ a);\r\n  }\r\n\r\n  vector<tuple<int, int, int>> res;\r\n  set<pair<int, int>>\
    \ seen;\r\n  for(int p = 1; p <= n; ++p){\r\n    sort(begin(ps[p]), end(ps[p]),\r\
    \n      [](auto &x, auto &y){ return make_pair(x.first, -x.second) < make_pair(y.first,\
    \ -y.second); });\r\n\r\n    int nr = -1;\r\n    for(auto&&[l, r] : ps[p]){\r\n\
    \      if(nr < r){\r\n        nr = r;\r\n        if(seen.count({l, r})) continue;\r\
    \n        seen.emplace(l, r);\r\n        res.emplace_back(p, l, r);\r\n      }\r\
    \n    }\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn:
  - string/z_algorithm.cpp
  isVerificationFile: false
  path: string/run_enumerate.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/run_enumerate.cpp
layout: document
redirect_from:
- /library/string/run_enumerate.cpp
- /library/string/run_enumerate.cpp.html
title: string/run_enumerate.cpp
---
