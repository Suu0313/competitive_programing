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
  bundledCode: "#line 1 \"unuse/Vcout.cpp\"\ntemplate< typename T >\r\nvoid Vcout(const\
    \ vector<T> &v, string sep = \" \"){\r\n  for(int i = 0; i < SZ(v); i++) {\r\n\
    \    cout << v[i] << (i + 1 != SZ(v) ? sep : \"\");\r\n  }\r\n  cout << endl;\r\
    \n}\n"
  code: "template< typename T >\r\nvoid Vcout(const vector<T> &v, string sep = \"\
    \ \"){\r\n  for(int i = 0; i < SZ(v); i++) {\r\n    cout << v[i] << (i + 1 !=\
    \ SZ(v) ? sep : \"\");\r\n  }\r\n  cout << endl;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: unuse/Vcout.cpp
  requiredBy: []
  timestamp: '2021-03-09 18:45:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unuse/Vcout.cpp
layout: document
redirect_from:
- /library/unuse/Vcout.cpp
- /library/unuse/Vcout.cpp.html
title: unuse/Vcout.cpp
---
