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
  bundledCode: "#line 1 \"unuse/Ckind.cpp\"\nint Ckind(char c){\r\n  if(isdigit(c))\
    \ return 0;\r\n  if(isupper(c)) return 1;\r\n  if(islower(c)) return 2;\r\n  if(isspace(c))\
    \ return 3;\r\n  \r\n  return 4;\r\n}\r\n\r\nvoid Cchange(char &c){\r\n  if(isupper(c))\
    \ c = tolower(c);\r\n  else if(islower(c)) c = toupper(c);\r\n  return;\r\n}\r\
    \n\r\nbool isvowel(char c){\r\n  vector<char> vowel = {'a','i','u','e','o'};\r\
    \n  for(auto a : vowel) if(a == c) return true;\r\n  return false;\r\n}\r\n"
  code: "int Ckind(char c){\r\n  if(isdigit(c)) return 0;\r\n  if(isupper(c)) return\
    \ 1;\r\n  if(islower(c)) return 2;\r\n  if(isspace(c)) return 3;\r\n  \r\n  return\
    \ 4;\r\n}\r\n\r\nvoid Cchange(char &c){\r\n  if(isupper(c)) c = tolower(c);\r\n\
    \  else if(islower(c)) c = toupper(c);\r\n  return;\r\n}\r\n\r\nbool isvowel(char\
    \ c){\r\n  vector<char> vowel = {'a','i','u','e','o'};\r\n  for(auto a : vowel)\
    \ if(a == c) return true;\r\n  return false;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: unuse/Ckind.cpp
  requiredBy: []
  timestamp: '2023-07-01 13:44:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unuse/Ckind.cpp
layout: document
redirect_from:
- /library/unuse/Ckind.cpp
- /library/unuse/Ckind.cpp.html
title: unuse/Ckind.cpp
---
