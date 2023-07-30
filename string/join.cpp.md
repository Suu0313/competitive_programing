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
  bundledCode: "#line 2 \"string/join.cpp\"\n\r\ntemplate<typename Container>\r\n\
    string join(const Container&v, const string &sep = \"\", const string &en = \"\
    \"){\r\n  stringstream s;\r\n  for(size_t i = 0; i < size(v); i++) s << v[i] <<\
    \ (i+1 != size(v) ? sep : en);\r\n  return s.str();\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename Container>\r\nstring join(const Container&v,\
    \ const string &sep = \"\", const string &en = \"\"){\r\n  stringstream s;\r\n\
    \  for(size_t i = 0; i < size(v); i++) s << v[i] << (i+1 != size(v) ? sep : en);\r\
    \n  return s.str();\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/join.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/join.cpp
layout: document
redirect_from:
- /library/string/join.cpp
- /library/string/join.cpp.html
title: string/join.cpp
---
