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
  bundledCode: "#line 1 \"unuse/debugout.cpp\"\n#ifdef _DEBUG\r\ntemplate<typename\
    \ T> void debug_out(T &&t) { cout << t << \"\\n\"; }\r\ntemplate <typename T,\
    \ typename... Ts>\r\nvoid debug_out(T&& t, Ts&&... ts){ cout << t << \", \"; debug_out(ts...);\
    \ }\r\n#define dbg(...) do{ cout <<\"L: \"<<__LINE__<<\" [ \" << #__VA_ARGS__\
    \ << \" ]: \"; debug_out(__VA_ARGS__); } while(false)\r\n#else\r\n#define dbg(...)\r\
    \n#endif\n"
  code: "#ifdef _DEBUG\r\ntemplate<typename T> void debug_out(T &&t) { cout << t <<\
    \ \"\\n\"; }\r\ntemplate <typename T, typename... Ts>\r\nvoid debug_out(T&& t,\
    \ Ts&&... ts){ cout << t << \", \"; debug_out(ts...); }\r\n#define dbg(...) do{\
    \ cout <<\"L: \"<<__LINE__<<\" [ \" << #__VA_ARGS__ << \" ]: \"; debug_out(__VA_ARGS__);\
    \ } while(false)\r\n#else\r\n#define dbg(...)\r\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: unuse/debugout.cpp
  requiredBy: []
  timestamp: '2021-04-19 15:55:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unuse/debugout.cpp
layout: document
redirect_from:
- /library/unuse/debugout.cpp
- /library/unuse/debugout.cpp.html
title: unuse/debugout.cpp
---
