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
  bundledCode: "#line 2 \"string/palindromic_length.cpp\"\n\r\ntemplate<class Container>\r\
    \nvector<int> palindromic_length(Container s){\r\n  int n = int(s.size());\r\n\
    \  vector<int> pl(n+1), gpl(n+1);\r\n  queue<tuple<int,int,int>> g, g2, g3;\r\n\
    \r\n  for(int j = 0; j < n; ++j){\r\n\r\n    while(!g.empty()){\r\n      auto[i,\
    \ d, k] = g.front(); g.pop();\r\n      if(i >= 1 && s[i-1] == s[j]) g2.emplace(i-1,\
    \ d, k);\r\n    }\r\n\r\n    int r = -j - 1;\r\n    while(!g2.empty()){\r\n  \
    \    auto[i, d, k] = g2.front(); g2.pop();\r\n      if(i-r != d){\r\n        g3.emplace(i,\
    \ i-r, 1);\r\n        if(k > 1) g3.emplace(i+d, d, k-1);\r\n      }else{\r\n \
    \       g3.emplace(i, d, k);\r\n      }\r\n      r = i + (k-1) * d;\r\n    }\r\
    \n\r\n    if(j > 0 && s[j-1] == s[j]){\r\n      g3.emplace(j-1, j-1-r, 1);\r\n\
    \      r = j - 1;\r\n    }\r\n    g3.emplace(j, j-r, 1);\r\n\r\n    auto[ni, nd,\
    \ nk] = g3.front(); g3.pop();\r\n    while(!g3.empty()){\r\n      auto[i, d, k]\
    \ = g3.front(); g3.pop();\r\n      if(nd == d){\r\n        nk += k;\r\n      }else{\r\
    \n        g.emplace(ni, nd, nk);\r\n        tie(ni, nd, nk) = make_tuple(i, d,\
    \ k);\r\n      }\r\n    }\r\n    g.emplace(ni, nd, nk);\r\n    pl[j+1] = j + 1;\r\
    \n    g2 = g;\r\n    while(!g.empty()){\r\n      auto[i, d, k] = g.front(); g.pop();\r\
    \n      r = i + (k - 1) * d;\r\n      int m = pl[r] + 1;\r\n      if(k > 1) m\
    \ = min(m, gpl[i - d + 1]);\r\n      if(d <= i + 1) gpl[i - d + 1] = m;\r\n  \
    \    pl[j+1] = min(pl[j+1], m);\r\n    }\r\n    swap(g, g2);\r\n  }\r\n  return\
    \ pl;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<class Container>\r\nvector<int> palindromic_length(Container\
    \ s){\r\n  int n = int(s.size());\r\n  vector<int> pl(n+1), gpl(n+1);\r\n  queue<tuple<int,int,int>>\
    \ g, g2, g3;\r\n\r\n  for(int j = 0; j < n; ++j){\r\n\r\n    while(!g.empty()){\r\
    \n      auto[i, d, k] = g.front(); g.pop();\r\n      if(i >= 1 && s[i-1] == s[j])\
    \ g2.emplace(i-1, d, k);\r\n    }\r\n\r\n    int r = -j - 1;\r\n    while(!g2.empty()){\r\
    \n      auto[i, d, k] = g2.front(); g2.pop();\r\n      if(i-r != d){\r\n     \
    \   g3.emplace(i, i-r, 1);\r\n        if(k > 1) g3.emplace(i+d, d, k-1);\r\n \
    \     }else{\r\n        g3.emplace(i, d, k);\r\n      }\r\n      r = i + (k-1)\
    \ * d;\r\n    }\r\n\r\n    if(j > 0 && s[j-1] == s[j]){\r\n      g3.emplace(j-1,\
    \ j-1-r, 1);\r\n      r = j - 1;\r\n    }\r\n    g3.emplace(j, j-r, 1);\r\n\r\n\
    \    auto[ni, nd, nk] = g3.front(); g3.pop();\r\n    while(!g3.empty()){\r\n \
    \     auto[i, d, k] = g3.front(); g3.pop();\r\n      if(nd == d){\r\n        nk\
    \ += k;\r\n      }else{\r\n        g.emplace(ni, nd, nk);\r\n        tie(ni, nd,\
    \ nk) = make_tuple(i, d, k);\r\n      }\r\n    }\r\n    g.emplace(ni, nd, nk);\r\
    \n    pl[j+1] = j + 1;\r\n    g2 = g;\r\n    while(!g.empty()){\r\n      auto[i,\
    \ d, k] = g.front(); g.pop();\r\n      r = i + (k - 1) * d;\r\n      int m = pl[r]\
    \ + 1;\r\n      if(k > 1) m = min(m, gpl[i - d + 1]);\r\n      if(d <= i + 1)\
    \ gpl[i - d + 1] = m;\r\n      pl[j+1] = min(pl[j+1], m);\r\n    }\r\n    swap(g,\
    \ g2);\r\n  }\r\n  return pl;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/palindromic_length.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/palindromic_length.cpp
layout: document
redirect_from:
- /library/string/palindromic_length.cpp
- /library/string/palindromic_length.cpp.html
title: string/palindromic_length.cpp
---
