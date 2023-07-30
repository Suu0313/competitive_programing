---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/integer/ceil.cpp
    title: math/integer/ceil.cpp
  - icon: ':warning:'
    path: math/integer/floor.cpp
    title: math/integer/floor.cpp
  - icon: ':warning:'
    path: math/integer/floor_kth_root.cpp
    title: math/integer/floor_kth_root.cpp
  - icon: ':warning:'
    path: math/integer/ipow.cpp
    title: math/integer/ipow.cpp
  - icon: ':warning:'
    path: math/integer/isqrt.cpp
    title: math/integer/isqrt.cpp
  - icon: ':warning:'
    path: math/integer/popcount.cpp
    title: math/integer/popcount.cpp
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
  bundledCode: "#line 2 \"math/integer/ceil.cpp\"\n\r\ntemplate<class T> constexpr\
    \ T ceil(T x, T y) {\r\n  if(y < 0) x = -x, y = -y;\r\n  if(x >= 0) return (x\
    \ + y - 1) / y;\r\n  return x / y;\r\n}\r\n#line 2 \"template/template_integers.cpp\"\
    \n\r\n#line 2 \"math/integer/floor.cpp\"\n\r\ntemplate<class T> constexpr T floor(T\
    \ x, T y) {\r\n  if(y < 0) x = -x, y = -y;\r\n  if(x >= 0) return x / y;\r\n \
    \ return (x - y + 1) / y;\r\n}\r\n#line 4 \"template/template_integers.cpp\"\n\
    \r\n#line 2 \"math/integer/floor_kth_root.cpp\"\n\r\nuint64_t floor_kth_root(uint64_t\
    \ a, int k){\r\n  if(a <= 1 || k <= 1) return a;\r\n  if(k >= 64) return 1;\r\n\
    \  uint64_t res = 0;\r\n  for(int i = 31; i >= 0; --i){\r\n    uint64_t p = 1,\
    \ x = res | (1u << i);\r\n    bool fl = true;\r\n    for(int j = 0; j < k; ++j){\r\
    \n      if(__builtin_mul_overflow(p, x, &p)){ fl = false; break;}\r\n    }\r\n\
    \    if(fl && p <= a) res |= (1u << i);\r\n  }\r\n  return res;\r\n}\r\n#line\
    \ 6 \"template/template_integers.cpp\"\n\r\n#line 2 \"math/integer/isqrt.cpp\"\
    \n\r\nuint64_t isqrt(uint64_t x){\r\n  uint64_t res = 0, over = 1;\r\n  while(over*over\
    \ <= x) over <<= 1;\r\n  while(over-res > 1){\r\n    uint64_t wj = res + ((over-res)\
    \ >> 1);\r\n    ((wj*wj <= x) ? res : over) = wj;\r\n  }\r\n  return res;\r\n\
    }\r\n#line 8 \"template/template_integers.cpp\"\n\r\n#line 2 \"math/integer/ipow.cpp\"\
    \n\r\ntemplate<typename T>\r\nT mod_inv(T a, T m){\r\n  T b = m, u= 1, v = 0;\r\
    \n  while(b){ T t = a/b; a -= t*b; swap(a,b); u -= t*v; swap(u,v); }\r\n  u %=\
    \ m; if(u<0) u+= m;\r\n  return u;\r\n}\r\n\r\ntemplate<typename T>\r\nT ipow(T\
    \ a, int64_t n, T m = 0, T e = 1){\r\n  if(n < 0){ assert(m != 0); return mod_inv(ipow(a,\
    \ -n, m, e), m); }\r\n  T res = e;\r\n  while(n > 0){ if(n&1){ res *= a; if(m)\
    \ res %= m; } a *= a; n >>= 1; if(m) a %= m; }\r\n  return res;\r\n}\r\n#line\
    \ 10 \"template/template_integers.cpp\"\n\r\n#line 2 \"math/integer/popcount.cpp\"\
    \n\r\nconstexpr int popcount(uint64_t x){\r\n  x -= ((x>>1)&0x5555555555555555ULL);\r\
    \n  x = (x&0x3333333333333333ULL) + ((x&0xCCCCCCCCCCCCCCCCULL)>>2);\r\n  x = (x&0x0F0F0F0F0F0F0F0FULL)\
    \ + ((x&0xF0F0F0F0F0F0F0F0ULL)>>4);  \r\n  x *= 0x0101010101010101ULL;\r\n  return\
    \ x >> 56;\r\n}\r\n#line 12 \"template/template_integers.cpp\"\n"
  code: "#include \"../math/integer/ceil.cpp\"\r\n\r\n#include \"../math/integer/floor.cpp\"\
    \r\n\r\n#include \"../math/integer/floor_kth_root.cpp\"\r\n\r\n#include \"../math/integer/isqrt.cpp\"\
    \r\n\r\n#include \"../math/integer/ipow.cpp\"\r\n\r\n#include \"../math/integer/popcount.cpp\""
  dependsOn:
  - math/integer/ceil.cpp
  - math/integer/floor.cpp
  - math/integer/floor_kth_root.cpp
  - math/integer/isqrt.cpp
  - math/integer/ipow.cpp
  - math/integer/popcount.cpp
  isVerificationFile: false
  path: template/template_integers.cpp
  requiredBy:
  - template/template.cpp
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/template_integers.cpp
layout: document
redirect_from:
- /library/template/template_integers.cpp
- /library/template/template_integers.cpp.html
title: template/template_integers.cpp
---
