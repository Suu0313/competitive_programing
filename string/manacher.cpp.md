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
  bundledCode: "#line 2 \"string/manacher.cpp\"\n\r\ntemplate<class Container>\r\n\
    vector<int> manacher(const Container &s){\r\n  int n = int(s.size());\r\n  Container\
    \ t(n*2 + 1, s[0]);\r\n  for(int i = 0; i < n; ++i) t[i*2 + 1] = s[i];\r\n  n\
    \ = int(t.size());\r\n  vector<int> dia(n);\r\n  for(int i = 0, j = 0; i < n;\
    \ ){\r\n    while(i - j >= 0 && i + j < n && t[i - j] == t[i + j]) ++j;\r\n  \
    \  dia[i] = j;\r\n    int k = 1;\r\n    for( ;i - k >= 0 && i + k < n && k + dia[i\
    \ - k] < j; ++k){\r\n      dia[i + k] = dia[i - k];\r\n    }\r\n    i += k; j\
    \ -= k;\r\n  }\r\n  for(auto&e : dia) --e;\r\n  return dia;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<class Container>\r\nvector<int> manacher(const\
    \ Container &s){\r\n  int n = int(s.size());\r\n  Container t(n*2 + 1, s[0]);\r\
    \n  for(int i = 0; i < n; ++i) t[i*2 + 1] = s[i];\r\n  n = int(t.size());\r\n\
    \  vector<int> dia(n);\r\n  for(int i = 0, j = 0; i < n; ){\r\n    while(i - j\
    \ >= 0 && i + j < n && t[i - j] == t[i + j]) ++j;\r\n    dia[i] = j;\r\n    int\
    \ k = 1;\r\n    for( ;i - k >= 0 && i + k < n && k + dia[i - k] < j; ++k){\r\n\
    \      dia[i + k] = dia[i - k];\r\n    }\r\n    i += k; j -= k;\r\n  }\r\n  for(auto&e\
    \ : dia) --e;\r\n  return dia;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/manacher.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/manacher.cpp
layout: document
redirect_from:
- /library/string/manacher.cpp
- /library/string/manacher.cpp.html
title: string/manacher.cpp
---
