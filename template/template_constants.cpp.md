---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template_constants.cpp\"\n\r\nconstexpr double\
    \ EPS = 1e-10;\r\nconstexpr double PI  = 3.141592653589793238462643383279;\r\n\
    constexpr int INF = numeric_limits<int>::max()/2;\r\nconstexpr long long LINF\
    \ = numeric_limits<long long>::max()/3;\r\nconstexpr long long MOD1 = 1e9+7;\r\
    \nconstexpr long long MOD2 = 998244353;\r\nconstexpr long long TEN(int n) { return\
    \ n? 10*TEN(n-1) : 1; }\r\n\r\nconstexpr int dx[] = {1,0,-1,0,1,1,-1,-1}, dy[]\
    \ = {0,1,0,-1,1,-1,1,-1};\r\n"
  code: "#pragma once\r\n\r\nconstexpr double EPS = 1e-10;\r\nconstexpr double PI\
    \  = 3.141592653589793238462643383279;\r\nconstexpr int INF = numeric_limits<int>::max()/2;\r\
    \nconstexpr long long LINF = numeric_limits<long long>::max()/3;\r\nconstexpr\
    \ long long MOD1 = 1e9+7;\r\nconstexpr long long MOD2 = 998244353;\r\nconstexpr\
    \ long long TEN(int n) { return n? 10*TEN(n-1) : 1; }\r\n\r\nconstexpr int dx[]\
    \ = {1,0,-1,0,1,1,-1,-1}, dy[] = {0,1,0,-1,1,-1,1,-1};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: template/template_constants.cpp
  requiredBy:
  - template/template.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/template_constants.cpp
layout: document
redirect_from:
- /library/template/template_constants.cpp
- /library/template/template_constants.cpp.html
title: template/template_constants.cpp
---
