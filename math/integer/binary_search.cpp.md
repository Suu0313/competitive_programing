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
  bundledCode: "#line 2 \"math/integer/binary_search.cpp\"\n\r\ntemplate<typename\
    \ T, typename F>\r\npair<T, T> ibinary_search(T ok, T ng, const F &isok){\r\n\
    \  while(abs(ok - ng) > 1){\r\n    T wj = (ok & ng) + ((ok ^ ng) >> 1);\r\n  \
    \  (isok(wj)?ok : ng) = wj;\r\n  }\r\n  return {ok, ng};\r\n}\r\n\r\n\r\nuint64_t\
    \ ftou(double f){\r\n  uint64_t u; memcpy(&u, &f, sizeof f);\r\n  return (u >>\
    \ 63 & 1) ? ~u : u ^ (1ull << 63);\r\n}\r\ndouble utof(uint64_t u){\r\n  u = ((u\
    \ >> 63 & 1) ? u ^ (1ull << 63) : ~u);\r\n  double f; memcpy(&f, &u, sizeof u);\r\
    \n  return f;\r\n}\r\n\r\ntemplate<typename F>\r\ndouble binary_search_exactly(double\
    \ ok, double ng, const F &f){\r\n  uint64_t uok = ftou(ok), ung = ftou(ng);\r\n\
    \  while(true){\r\n    uint64_t uwj = (uok & ung) + (uok ^ ung)/2;\r\n    if(uok\
    \ == uwj || ung == uwj) break;\r\n    double wj = utof(uwj);\r\n    (f(wj) ? uok\
    \ : ung) = uwj;\r\n  }\r\n  return utof(uok);\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T, typename F>\r\npair<T, T> ibinary_search(T\
    \ ok, T ng, const F &isok){\r\n  while(abs(ok - ng) > 1){\r\n    T wj = (ok &\
    \ ng) + ((ok ^ ng) >> 1);\r\n    (isok(wj)?ok : ng) = wj;\r\n  }\r\n  return {ok,\
    \ ng};\r\n}\r\n\r\n\r\nuint64_t ftou(double f){\r\n  uint64_t u; memcpy(&u, &f,\
    \ sizeof f);\r\n  return (u >> 63 & 1) ? ~u : u ^ (1ull << 63);\r\n}\r\ndouble\
    \ utof(uint64_t u){\r\n  u = ((u >> 63 & 1) ? u ^ (1ull << 63) : ~u);\r\n  double\
    \ f; memcpy(&f, &u, sizeof u);\r\n  return f;\r\n}\r\n\r\ntemplate<typename F>\r\
    \ndouble binary_search_exactly(double ok, double ng, const F &f){\r\n  uint64_t\
    \ uok = ftou(ok), ung = ftou(ng);\r\n  while(true){\r\n    uint64_t uwj = (uok\
    \ & ung) + (uok ^ ung)/2;\r\n    if(uok == uwj || ung == uwj) break;\r\n    double\
    \ wj = utof(uwj);\r\n    (f(wj) ? uok : ung) = uwj;\r\n  }\r\n  return utof(uok);\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/integer/binary_search.cpp
  requiredBy: []
  timestamp: '2023-02-24 02:44:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/integer/binary_search.cpp
layout: document
redirect_from:
- /library/math/integer/binary_search.cpp
- /library/math/integer/binary_search.cpp.html
title: math/integer/binary_search.cpp
---
