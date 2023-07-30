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
  bundledCode: "#line 2 \"string/split.cpp\"\n\r\ntemplate <typename F>\r\nvoid split(const\
    \ string& str, char delim, const F& f){\r\n  istringstream iss{str};\r\n  string\
    \ token;\r\n  while(getline(iss, token, delim)){\r\n    f(token);\r\n  }\r\n}\r\
    \nvector<string> split(const string& str, char delim=' ', bool rmsp = true){\r\
    \n  vector<string> tokens;\r\n  split(str, delim, [&tokens, &rmsp](const string&\
    \ token){\r\n    if(!(rmsp && token.empty())) tokens.emplace_back(token);\r\n\
    \  });\r\n  return tokens;\r\n}\n"
  code: "#pragma once\r\n\r\ntemplate <typename F>\r\nvoid split(const string& str,\
    \ char delim, const F& f){\r\n  istringstream iss{str};\r\n  string token;\r\n\
    \  while(getline(iss, token, delim)){\r\n    f(token);\r\n  }\r\n}\r\nvector<string>\
    \ split(const string& str, char delim=' ', bool rmsp = true){\r\n  vector<string>\
    \ tokens;\r\n  split(str, delim, [&tokens, &rmsp](const string& token){\r\n  \
    \  if(!(rmsp && token.empty())) tokens.emplace_back(token);\r\n  });\r\n  return\
    \ tokens;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/split.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/split.cpp
layout: document
redirect_from:
- /library/string/split.cpp
- /library/string/split.cpp.html
title: string/split.cpp
---
