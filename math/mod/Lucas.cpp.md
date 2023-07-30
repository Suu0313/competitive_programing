---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/mod/Combination.cpp
    title: math/mod/Combination.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/mod/Lucas.cpp\"\n\r\n#line 2 \"math/mod/Combination.cpp\"\
    \n\r\ntemplate<typename T>\r\nstruct Combination{\r\n  // T \u306F mint \u306E\
    \u60F3\u5B9A\u3067\u3059\r\n  int N;\r\n  vector<T> fact_, inv_, finv_;\r\n\r\n\
    \  Combination(int n = 10):N(n+1), fact_(N,1), inv_(N,1), finv_(N,1){\r\n    int\
    \ mod = fact_.at(0).get_mod();\r\n\r\n    for (int i = 2; i < N; i++){\r\n   \
    \   fact_.at(i) = fact_.at(i-1) * i;\r\n      inv_.at(i) = -inv_.at(mod%i) * (mod/i);\r\
    \n      finv_.at(i) = finv_.at(i-1) * inv_.at(i);\r\n    }\r\n  }\r\n\r\n  void\
    \ init(int n) {\r\n    N = n+1;\r\n    fact_.assign(N, 1);\r\n    inv_.assign(N,\
    \ 1);\r\n    finv_.assign(N, 1);\r\n\r\n    int mod = fact_.at(0).get_mod();\r\
    \n\r\n    for (int i = 2; i < N; i++){\r\n      fact_.at(i) = fact_.at(i-1) *\
    \ i;\r\n      inv_.at(i) = -inv_.at(mod%i) * (mod/i);\r\n      finv_.at(i) = finv_.at(i-1)\
    \ * inv_.at(i);\r\n    }\r\n  }\r\n\r\n  T fact(int n){\r\n    if(n < 0) return\
    \ 0;\r\n    append(n);\r\n    return fact_.at(n);\r\n  }\r\n  T inv(int n){\r\n\
    \    if(n < 0) return 0;\r\n    append(n);\r\n    return inv_.at(n);\r\n  }\r\n\
    \  T finv(int n){\r\n    if(n < 0) return 0;\r\n    append(n);\r\n    return finv_.at(n);\r\
    \n  }\r\n\r\n  T com(int n, int k){\r\n    if (n < k) return 0;\r\n    if (n <\
    \ 0 || k < 0) return 0;\r\n    append(n);\r\n    return fact_.at(n) * finv_.at(k)\
    \ * finv_.at(n-k);\r\n  }\r\n\r\n  T parm(int n, int k){\r\n    if (n < k) return\
    \ 0;\r\n    if (n < 0 || k < 0) return 0;\r\n    append(n);\r\n    return fact_.at(n)\
    \ *finv_.at(n-k);\r\n  }\r\n\r\n  T hom(int n, int k){\r\n    if(n < 0 || k <\
    \ 0) return 0;\r\n    if(k == 0) return 1;\r\n    append(n+k-1);\r\n    return\
    \ com(n+k-1, k);\r\n  }\r\n\r\n  T catalan(int n){\r\n    return catalan(n, n,\
    \ 1);\r\n  }\r\n\r\n  T catalan(int n, int k){\r\n    return catalan(n, k, 1);\r\
    \n  }\r\n\r\n  T catalan(int n, int k, int m){\r\n    if(k < m) return com(n+k,\
    \ k);\r\n    if(k < n+m-1) return com(n+k, k) - com(n+k, k-m);\r\n    return 0;\r\
    \n  }\r\n  \r\n  T random_walk(int n, int x){\r\n    if(n < abs(x) || n%2 != abs(x)%2)\
    \ return 0;\r\n    return com(n, (n + x)/2);\r\n  }\r\n\r\n  T random_walk(int\
    \ n, int x, int y){\r\n    return random_walk(n, x+y) * random_walk(n, x-y);\r\
    \n  }\r\n\r\n  T mul(std::initializer_list<int> ks){\r\n    int n = accumulate(begin(ks),\
    \ end(ks), 0);\r\n    T res = fact(n);\r\n    for(int k : ks) res *= finv(k);\r\
    \n    return res;\r\n  }\r\n\r\nprivate:\r\n  void append(int n){\r\n    if(n\
    \ < N) return;\r\n    fact_.resize(n+1);\r\n    inv_.resize(n+1);\r\n    finv_.resize(n+1);\r\
    \n\r\n    int mod = fact_.at(0).get_mod();\r\n\r\n    for (int i = N; i < n+1;\
    \ i++){\r\n      fact_.at(i) = fact_.at(i-1) * i;\r\n      inv_.at(i) = -inv_.at(mod%i)\
    \ * (mod/i);\r\n      finv_.at(i) = finv_.at(i-1) * inv_.at(i);\r\n    }\r\n\r\
    \n    N = n+1;\r\n  }\r\n};\r\n#line 4 \"math/mod/Lucas.cpp\"\n\r\ntemplate<typename\
    \ T, int p = T::get_mod()>\r\nstruct Lucas{\r\n  Combination<T> bc;\r\n\r\n  Lucas():\
    \ bc(p-1) {}\r\n\r\n  T com(int64_t n, int64_t k){\r\n    if(n < k) return 0;\r\
    \n    if(n < 0 || k < 0) return 0;\r\n    T res = 1;\r\n    while(n){\r\n    \
    \  res *= bc.com(n%p, k%p);\r\n      if(k == 0 || res == 0) return res;\r\n  \
    \    n /= p; k /= p;\r\n    }\r\n    return res;\r\n  }\r\n\r\n  T hom(int64_t\
    \ n, int64_t k){\r\n    if(n < 0 || k < 0) return 0;\r\n    if(k == 0) return\
    \ 1;\r\n    return com(n+k-1, k);\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include \"./Combination.cpp\"\r\n\r\ntemplate<typename\
    \ T, int p = T::get_mod()>\r\nstruct Lucas{\r\n  Combination<T> bc;\r\n\r\n  Lucas():\
    \ bc(p-1) {}\r\n\r\n  T com(int64_t n, int64_t k){\r\n    if(n < k) return 0;\r\
    \n    if(n < 0 || k < 0) return 0;\r\n    T res = 1;\r\n    while(n){\r\n    \
    \  res *= bc.com(n%p, k%p);\r\n      if(k == 0 || res == 0) return res;\r\n  \
    \    n /= p; k /= p;\r\n    }\r\n    return res;\r\n  }\r\n\r\n  T hom(int64_t\
    \ n, int64_t k){\r\n    if(n < 0 || k < 0) return 0;\r\n    if(k == 0) return\
    \ 1;\r\n    return com(n+k-1, k);\r\n  }\r\n};\r\n"
  dependsOn:
  - math/mod/Combination.cpp
  isVerificationFile: false
  path: math/mod/Lucas.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod/Lucas.cpp
layout: document
redirect_from:
- /library/math/mod/Lucas.cpp
- /library/math/mod/Lucas.cpp.html
title: math/mod/Lucas.cpp
---
