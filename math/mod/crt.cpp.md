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
  bundledCode: "#line 2 \"math/mod/crt.cpp\"\n\r\ntemplate<typename T>\r\npair<int64_t,\
    \ int64_t> crt(const vector<T> &r, const vector<T> &m){\r\n\r\n  auto inv_gcd\
    \ = [](int64_t a, int64_t b) -> pair<int64_t, int64_t> {\r\n    if(a == 0) return\
    \ {b, 0};\r\n    int64_t s = b, t = a;\r\n    int64_t m0 = 0, m1 = 1;\r\n    while(t){\r\
    \n      int64_t u = s/t; s -= t*u; m0 -= m1*u;\r\n      int64_t tmp = s; s = t;\
    \ t = tmp; tmp = m0; m0 = m1; m1 = tmp;\r\n    }\r\n    if(m0 < 0) m0 += b/s;\r\
    \n    return {s, m0};\r\n  };\r\n\r\n  int n = int(r.size());\r\n  int64_t r0\
    \ = 0, m0 = 1;\r\n  for(int i = 0; i < n; i++){\r\n    int64_t r1 = r[i], m1 =\
    \ m[i];\r\n    r1 %= m1;\r\n    if(r1 < 0) r1 += m1;\r\n    if(m0 < m1){ swap(r0,\
    \ r1); swap(m0, m1); }\r\n    if(m0 % m1 == 0){\r\n      if(r0 % m1 != r1) return\
    \ {0, 0};\r\n      continue;\r\n    }\r\n    auto[g, im] = inv_gcd(m0, m1);\r\n\
    \    int64_t u1 = m1 / g;\r\n    if((r1-r0) % g) return {0, 0};\r\n    int64_t\
    \ x = (r1-r0) / g % u1 * im % u1;\r\n    r0 += x * m0;\r\n    m0 *= u1;\r\n  \
    \  if(r0 < 0) r0 += m0;\r\n  }\r\n  return {r0, m0};\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\npair<int64_t, int64_t> crt(const\
    \ vector<T> &r, const vector<T> &m){\r\n\r\n  auto inv_gcd = [](int64_t a, int64_t\
    \ b) -> pair<int64_t, int64_t> {\r\n    if(a == 0) return {b, 0};\r\n    int64_t\
    \ s = b, t = a;\r\n    int64_t m0 = 0, m1 = 1;\r\n    while(t){\r\n      int64_t\
    \ u = s/t; s -= t*u; m0 -= m1*u;\r\n      int64_t tmp = s; s = t; t = tmp; tmp\
    \ = m0; m0 = m1; m1 = tmp;\r\n    }\r\n    if(m0 < 0) m0 += b/s;\r\n    return\
    \ {s, m0};\r\n  };\r\n\r\n  int n = int(r.size());\r\n  int64_t r0 = 0, m0 = 1;\r\
    \n  for(int i = 0; i < n; i++){\r\n    int64_t r1 = r[i], m1 = m[i];\r\n    r1\
    \ %= m1;\r\n    if(r1 < 0) r1 += m1;\r\n    if(m0 < m1){ swap(r0, r1); swap(m0,\
    \ m1); }\r\n    if(m0 % m1 == 0){\r\n      if(r0 % m1 != r1) return {0, 0};\r\n\
    \      continue;\r\n    }\r\n    auto[g, im] = inv_gcd(m0, m1);\r\n    int64_t\
    \ u1 = m1 / g;\r\n    if((r1-r0) % g) return {0, 0};\r\n    int64_t x = (r1-r0)\
    \ / g % u1 * im % u1;\r\n    r0 += x * m0;\r\n    m0 *= u1;\r\n    if(r0 < 0)\
    \ r0 += m0;\r\n  }\r\n  return {r0, m0};\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/mod/crt.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod/crt.cpp
layout: document
redirect_from:
- /library/math/mod/crt.cpp
- /library/math/mod/crt.cpp.html
title: math/mod/crt.cpp
---
