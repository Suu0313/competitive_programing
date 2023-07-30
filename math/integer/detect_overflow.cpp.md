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
  bundledCode: "#line 2 \"math/integer/detect_overflow.cpp\"\n\r\n#define ADD_OVERFLOW(a,\
    \ b) __builtin_add_overflow_p (a, b, (decltype(a)) 0)\r\n#define SUB_OVERFLOW(a,\
    \ b) __builtin_sub_overflow_p (a, b, (decltype(a)) 0)\r\n#define MUL_OVERFLOW(a,\
    \ b) __builtin_mul_overflow_p (a, b, (decltype(a)) 0)\r\n\r\ntemplate<typename\
    \ T>\r\nT ADD(const T &a, const T &b, const T &lim = numeric_limits<T>::max()){\r\
    \n  if(ADD_OVERFLOW(a,b)){ return lim; } return min(a+b, lim);\r\n}\r\ntemplate<typename\
    \ T>\r\nT SUB(const T &a, const T &b, const T &lim = numeric_limits<T>::lowest()){\r\
    \n  if(SUB_OVERFLOW(a,b)){ return lim; } return max(a-b, lim);\r\n}\r\ntemplate<typename\
    \ T>\r\nT MUL(const T &a, const T &b, const T &lim = numeric_limits<T>::max()){\r\
    \n  if(MUL_OVERFLOW(a,b)){ return lim; } return min(a*b, lim);\r\n}\r\n"
  code: "#pragma once\r\n\r\n#define ADD_OVERFLOW(a, b) __builtin_add_overflow_p (a,\
    \ b, (decltype(a)) 0)\r\n#define SUB_OVERFLOW(a, b) __builtin_sub_overflow_p (a,\
    \ b, (decltype(a)) 0)\r\n#define MUL_OVERFLOW(a, b) __builtin_mul_overflow_p (a,\
    \ b, (decltype(a)) 0)\r\n\r\ntemplate<typename T>\r\nT ADD(const T &a, const T\
    \ &b, const T &lim = numeric_limits<T>::max()){\r\n  if(ADD_OVERFLOW(a,b)){ return\
    \ lim; } return min(a+b, lim);\r\n}\r\ntemplate<typename T>\r\nT SUB(const T &a,\
    \ const T &b, const T &lim = numeric_limits<T>::lowest()){\r\n  if(SUB_OVERFLOW(a,b)){\
    \ return lim; } return max(a-b, lim);\r\n}\r\ntemplate<typename T>\r\nT MUL(const\
    \ T &a, const T &b, const T &lim = numeric_limits<T>::max()){\r\n  if(MUL_OVERFLOW(a,b)){\
    \ return lim; } return min(a*b, lim);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/integer/detect_overflow.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/integer/detect_overflow.cpp
layout: document
redirect_from:
- /library/math/integer/detect_overflow.cpp
- /library/math/integer/detect_overflow.cpp.html
title: math/integer/detect_overflow.cpp
---
