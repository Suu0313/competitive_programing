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
  bundledCode: "#line 2 \"math/integer/fibonnaci_search.cpp\"\n\r\ntemplate<typename\
    \ T, typename U, typename F, typename C>\r\nT fibonnaci_search(T l, T r, const\
    \ F &f, const C &cmp){\r\n  if(l >= r) return l;\r\n  vector<T> fib(2, 1);\r\n\
    \  T d = r - l;\r\n  for(int i = 0; fib.back() <= d + 1; ++i) fib.push_back(fib[i]\
    \ + fib[i + 1]);\r\n\r\n  auto sf = [&](T x) -> optional<U> {\r\n    if(x < l\
    \ || r < x) return nullopt;\r\n    return f(x);\r\n  };\r\n\r\n  int i = int(fib.size());\r\
    \n  T lx = l-1, rx = lx + fib[--i];\r\n  T nl = lx + fib[i - 2], nr = lx + fib[--i];\r\
    \n  optional<U> lv = sf(nl), rv = sf(nr);\r\n\r\n  while(lx + 2 < rx){\r\n   \
    \ --i;\r\n    if(!rv || cmp(lv.value(), rv.value())){\r\n      rx = nr; nr = nl;\
    \ rv = lv;\r\n      nl = lx + fib[i - 1];\r\n      lv = sf(nl);\r\n    }else{\r\
    \n      lx = nl; nl = nr; lv = rv;\r\n      nr = lx + fib[i];\r\n      rv = sf(nr);\r\
    \n    }\r\n  }\r\n\r\n  return lx + 1;\r\n}\r\n\r\nuint64_t ftou(double f){\r\n\
    \  uint64_t u; memcpy(&u, &f, sizeof f);\r\n  return (u >> 63 & 1) ? ~u : u ^\
    \ (1ull << 63);\r\n}\r\ndouble utof(uint64_t u){\r\n  u = ((u >> 63 & 1) ? u ^\
    \ (1ull << 63) : ~u);\r\n  double f; memcpy(&f, &u, sizeof u);\r\n  return f;\r\
    \n}\r\n\r\ntemplate<typename T, typename F, typename C>\r\ndouble fibonnaci_search_exactly(double\
    \ l, double r, const F &f, const C &cmp){\r\n  uint64_t x = fibonnaci_search<uint64_t,\
    \ T>(\r\n      ftou(l), ftou(r), [&](uint64_t x){ return f(utof(x)); }, cmp\r\n\
    \  );\r\n  return utof(x);\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T, typename U, typename F, typename\
    \ C>\r\nT fibonnaci_search(T l, T r, const F &f, const C &cmp){\r\n  if(l >= r)\
    \ return l;\r\n  vector<T> fib(2, 1);\r\n  T d = r - l;\r\n  for(int i = 0; fib.back()\
    \ <= d + 1; ++i) fib.push_back(fib[i] + fib[i + 1]);\r\n\r\n  auto sf = [&](T\
    \ x) -> optional<U> {\r\n    if(x < l || r < x) return nullopt;\r\n    return\
    \ f(x);\r\n  };\r\n\r\n  int i = int(fib.size());\r\n  T lx = l-1, rx = lx + fib[--i];\r\
    \n  T nl = lx + fib[i - 2], nr = lx + fib[--i];\r\n  optional<U> lv = sf(nl),\
    \ rv = sf(nr);\r\n\r\n  while(lx + 2 < rx){\r\n    --i;\r\n    if(!rv || cmp(lv.value(),\
    \ rv.value())){\r\n      rx = nr; nr = nl; rv = lv;\r\n      nl = lx + fib[i -\
    \ 1];\r\n      lv = sf(nl);\r\n    }else{\r\n      lx = nl; nl = nr; lv = rv;\r\
    \n      nr = lx + fib[i];\r\n      rv = sf(nr);\r\n    }\r\n  }\r\n\r\n  return\
    \ lx + 1;\r\n}\r\n\r\nuint64_t ftou(double f){\r\n  uint64_t u; memcpy(&u, &f,\
    \ sizeof f);\r\n  return (u >> 63 & 1) ? ~u : u ^ (1ull << 63);\r\n}\r\ndouble\
    \ utof(uint64_t u){\r\n  u = ((u >> 63 & 1) ? u ^ (1ull << 63) : ~u);\r\n  double\
    \ f; memcpy(&f, &u, sizeof u);\r\n  return f;\r\n}\r\n\r\ntemplate<typename T,\
    \ typename F, typename C>\r\ndouble fibonnaci_search_exactly(double l, double\
    \ r, const F &f, const C &cmp){\r\n  uint64_t x = fibonnaci_search<uint64_t, T>(\r\
    \n      ftou(l), ftou(r), [&](uint64_t x){ return f(utof(x)); }, cmp\r\n  );\r\
    \n  return utof(x);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/integer/fibonnaci_search.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/integer/fibonnaci_search.cpp
layout: document
redirect_from:
- /library/math/integer/fibonnaci_search.cpp
- /library/math/integer/fibonnaci_search.cpp.html
title: math/integer/fibonnaci_search.cpp
---
