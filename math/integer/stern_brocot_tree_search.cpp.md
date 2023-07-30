---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: binary search on stern-brocot tree
    links: []
  bundledCode: "#line 2 \"math/integer/stern_brocot_tree_search.cpp\"\n\r\n/**\r\n\
    \ * @brief binary search on stern-brocot tree\r\n * \r\n * @tparam F bool<uint64_t,\
    \ uint64_t>\r\n * @param f (a, b) => check(a / b) f(0, 1) != f(1, 0)\r\n * @param\
    \ limit a <= limit && b <= limit\r\n * @return pair<pair<uint64_t, uint64_t>,\
    \ pair<uint64_t, uint64_t>>\r\n */\r\ntemplate<typename F>\r\nauto stern_brocot_tree_search(const\
    \ F &f, uint64_t limit){\r\n  using P = pair<uint64_t, uint64_t>;\r\n  auto add\
    \ = [](const P &a, const P &b) -> P { return { a.first+b.first, a.second+b.second\
    \ }; };\r\n  auto mul = [](const P &a, uint64_t k) -> P { return { a.first * k,\
    \ a.second * k }; };\r\n  auto Pf = [&](const P &a) -> bool { return f(a.first,\
    \ a.second); };\r\n\r\n  P low(0, 1), high(1, 0);\r\n  bool low_judge = f(0, 1);\r\
    \n  while(true){\r\n    P mid = add(low, high);\r\n    if(max(mid.first, mid.second)\
    \ > limit) break;\r\n    bool mid_judge = Pf(mid);\r\n    P &s = (low_judge!=mid_judge\
    \ ? low : high);\r\n    P &l = (low_judge==mid_judge ? low : high);\r\n\r\n  \
    \  uint64_t a = 0, b = 1;\r\n    while(true){\r\n      P wj = add(mid, mul(s,\
    \ b));\r\n      if(max(wj.first, wj.second) > limit || mid_judge != Pf(wj)) break;\r\
    \n      a = b; b += b;\r\n    }\r\n\r\n    while(a + 1 < b){\r\n      uint64_t\
    \ m = (a + b)/2;\r\n      P wj = add(mid, mul(s, m));\r\n      if(max(wj.first,\
    \ wj.second) > limit) b = m;\r\n      else (Pf(wj)==mid_judge ? a : b) = m;\r\n\
    \    }\r\n    l = add(mid, mul(s, a));\r\n  }\r\n\r\n  return make_pair(low, high);\r\
    \n}\r\n"
  code: "#pragma once\r\n\r\n/**\r\n * @brief binary search on stern-brocot tree\r\
    \n * \r\n * @tparam F bool<uint64_t, uint64_t>\r\n * @param f (a, b) => check(a\
    \ / b) f(0, 1) != f(1, 0)\r\n * @param limit a <= limit && b <= limit\r\n * @return\
    \ pair<pair<uint64_t, uint64_t>, pair<uint64_t, uint64_t>>\r\n */\r\ntemplate<typename\
    \ F>\r\nauto stern_brocot_tree_search(const F &f, uint64_t limit){\r\n  using\
    \ P = pair<uint64_t, uint64_t>;\r\n  auto add = [](const P &a, const P &b) ->\
    \ P { return { a.first+b.first, a.second+b.second }; };\r\n  auto mul = [](const\
    \ P &a, uint64_t k) -> P { return { a.first * k, a.second * k }; };\r\n  auto\
    \ Pf = [&](const P &a) -> bool { return f(a.first, a.second); };\r\n\r\n  P low(0,\
    \ 1), high(1, 0);\r\n  bool low_judge = f(0, 1);\r\n  while(true){\r\n    P mid\
    \ = add(low, high);\r\n    if(max(mid.first, mid.second) > limit) break;\r\n \
    \   bool mid_judge = Pf(mid);\r\n    P &s = (low_judge!=mid_judge ? low : high);\r\
    \n    P &l = (low_judge==mid_judge ? low : high);\r\n\r\n    uint64_t a = 0, b\
    \ = 1;\r\n    while(true){\r\n      P wj = add(mid, mul(s, b));\r\n      if(max(wj.first,\
    \ wj.second) > limit || mid_judge != Pf(wj)) break;\r\n      a = b; b += b;\r\n\
    \    }\r\n\r\n    while(a + 1 < b){\r\n      uint64_t m = (a + b)/2;\r\n     \
    \ P wj = add(mid, mul(s, m));\r\n      if(max(wj.first, wj.second) > limit) b\
    \ = m;\r\n      else (Pf(wj)==mid_judge ? a : b) = m;\r\n    }\r\n    l = add(mid,\
    \ mul(s, a));\r\n  }\r\n\r\n  return make_pair(low, high);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/integer/stern_brocot_tree_search.cpp
  requiredBy: []
  timestamp: '2023-05-18 20:41:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/integer/stern_brocot_tree_search.cpp
layout: document
redirect_from:
- /library/math/integer/stern_brocot_tree_search.cpp
- /library/math/integer/stern_brocot_tree_search.cpp.html
title: binary search on stern-brocot tree
---
