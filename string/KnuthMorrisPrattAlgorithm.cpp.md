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
  bundledCode: "#line 2 \"string/KnuthMorrisPrattAlgorithm.cpp\"\n\r\ntemplate<typename\
    \ Container>\r\nstruct KnuthMorrisPrattAlgorithm{\r\n  Container s;\r\n  vector<int>\
    \ mp, kmp;\r\n  KnuthMorrisPrattAlgorithm() = default;\r\n\r\n  KnuthMorrisPrattAlgorithm(const\
    \ Container &s): s(s), mp(s.size()+1, -1), kmp(s.size()+1, -1){\r\n    int n =\
    \ int(s.size());\r\n    for(int i = 0, j = -1; i < n; ){\r\n      while(j >= 0\
    \ && (s[i] != s[j])) j = kmp[j];\r\n      ++i; ++j;\r\n      mp[i] = j;\r\n  \
    \    if(s[i] == s[j]) kmp[i] = kmp[j];\r\n      else kmp[i] = j;\r\n    }\r\n\
    \  }\r\n\r\n  template<typename T>\r\n  void push_back(T c){\r\n    int i = int(s.size()),\
    \ j = mp[i];\r\n    s.push_back(c);\r\n    kmp.pop_back();\r\n    kmp.push_back(((j\
    \ >= 0) && (s[i] == s[j])) ? kmp[j] : j);\r\n\r\n\r\n    while(j >= 0 && (s[i]\
    \ != s[j])) j = kmp[j];\r\n    ++i; ++j;\r\n    mp.push_back(j);\r\n    kmp.push_back(j);\r\
    \n  }\r\n\r\n  void pop_back(){\r\n    s.pop_back();\r\n    mp.pop_back();\r\n\
    \    kmp.pop_back();\r\n    kmp.back() = mp.back();\r\n  }\r\n\r\n  // period\
    \ of [0, i)\r\n  int period(int i) const { return i - mp[i]; }\r\n\r\n  // t[i:i+n]\
    \ == s\r\n  vector<int> match(const Container &t) const {\r\n    int n = int(s.size()),\
    \ m = int(t.size());\r\n    vector<int> res;\r\n\r\n    for(int i = 0, j = 0;\
    \ j < m; ){\r\n      while(i >= 0 && (s[i] != t[j])) i = kmp[i];\r\n      ++i;\
    \ ++j;\r\n      if(i >= n){\r\n        res.push_back(j-i); i = kmp[i];\r\n   \
    \   }\r\n    }\r\n    return res;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename Container>\r\nstruct KnuthMorrisPrattAlgorithm{\r\
    \n  Container s;\r\n  vector<int> mp, kmp;\r\n  KnuthMorrisPrattAlgorithm() =\
    \ default;\r\n\r\n  KnuthMorrisPrattAlgorithm(const Container &s): s(s), mp(s.size()+1,\
    \ -1), kmp(s.size()+1, -1){\r\n    int n = int(s.size());\r\n    for(int i = 0,\
    \ j = -1; i < n; ){\r\n      while(j >= 0 && (s[i] != s[j])) j = kmp[j];\r\n \
    \     ++i; ++j;\r\n      mp[i] = j;\r\n      if(s[i] == s[j]) kmp[i] = kmp[j];\r\
    \n      else kmp[i] = j;\r\n    }\r\n  }\r\n\r\n  template<typename T>\r\n  void\
    \ push_back(T c){\r\n    int i = int(s.size()), j = mp[i];\r\n    s.push_back(c);\r\
    \n    kmp.pop_back();\r\n    kmp.push_back(((j >= 0) && (s[i] == s[j])) ? kmp[j]\
    \ : j);\r\n\r\n\r\n    while(j >= 0 && (s[i] != s[j])) j = kmp[j];\r\n    ++i;\
    \ ++j;\r\n    mp.push_back(j);\r\n    kmp.push_back(j);\r\n  }\r\n\r\n  void pop_back(){\r\
    \n    s.pop_back();\r\n    mp.pop_back();\r\n    kmp.pop_back();\r\n    kmp.back()\
    \ = mp.back();\r\n  }\r\n\r\n  // period of [0, i)\r\n  int period(int i) const\
    \ { return i - mp[i]; }\r\n\r\n  // t[i:i+n] == s\r\n  vector<int> match(const\
    \ Container &t) const {\r\n    int n = int(s.size()), m = int(t.size());\r\n \
    \   vector<int> res;\r\n\r\n    for(int i = 0, j = 0; j < m; ){\r\n      while(i\
    \ >= 0 && (s[i] != t[j])) i = kmp[i];\r\n      ++i; ++j;\r\n      if(i >= n){\r\
    \n        res.push_back(j-i); i = kmp[i];\r\n      }\r\n    }\r\n    return res;\r\
    \n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/KnuthMorrisPrattAlgorithm.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/KnuthMorrisPrattAlgorithm.cpp
layout: document
redirect_from:
- /library/string/KnuthMorrisPrattAlgorithm.cpp
- /library/string/KnuthMorrisPrattAlgorithm.cpp.html
title: string/KnuthMorrisPrattAlgorithm.cpp
---
