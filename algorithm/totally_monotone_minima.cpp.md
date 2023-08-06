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
  bundledCode: "#line 1 \"algorithm/totally_monotone_minima.cpp\"\n/**\n * [0 <= i\
    \ < h) find f(i) O(h + w)\n * \n * @tparam F (int, int, int) -> bool\n * @param\
    \ h \n * @param w \n * @param f (i, pj, nj) -> nj is better than pj\n * @return\
    \ vector<int> f[i] is best j\n * @todo monotone_minima \u3088\u308A\u9045\u3044\
    \u306E\u3092\u4F55\u3068\u304B\u3057\u305F\u3044\n */\ntemplate<typename F> \n\
    vector<int> totally_monotone_minima(int h, int w, const F &f){\n  auto rec = [&](auto\
    \ self, const vector<int> &hidx, const vector<int> &widx) -> vector<int> {\n\n\
    \    int n = int(hidx.size());\n    if(n == 0) return {};\n    vector<int> nwidx;\
    \ nwidx.reserve(n);\n    for(int j : widx){\n      while(!nwidx.empty() && f(hidx[nwidx.size()\
    \ - 1], nwidx.back(), j)) nwidx.pop_back();\n      if(int(nwidx.size()) < n) nwidx.push_back(j);\n\
    \    }\n\n    vector<int> ridx; ridx.reserve(n/2);\n    for(int i = 1; i < n;\
    \ i += 2) ridx.push_back(hidx[i]);\n    auto rans = self(self, ridx, nwidx);\n\
    \n    vector<int> ans(n);\n    for(int i = 1, j = 0; i < n; i += 2, ++j) ans[i]\
    \ = rans[j];\n\n    for(int i = 0, j = 0; i < n; i += 2){\n      ans[i] = nwidx[j];\n\
    \      for(int r = (i+1 == n ? nwidx.back() : ans[i + 1]); nwidx[j] != r; ){\n\
    \        ++j;\n        if(f(hidx[i], ans[i], nwidx[j])) ans[i] = nwidx[j];\n \
    \     }\n    }\n    return ans;\n  };\n  vector<int> hidx(h); iota(hidx.begin(),\
    \ hidx.end(), 0);\n  vector<int> widx(w); iota(widx.begin(), widx.end(), 0);\n\
    \  return rec(rec, hidx, widx);\n}\n"
  code: "/**\n * [0 <= i < h) find f(i) O(h + w)\n * \n * @tparam F (int, int, int)\
    \ -> bool\n * @param h \n * @param w \n * @param f (i, pj, nj) -> nj is better\
    \ than pj\n * @return vector<int> f[i] is best j\n * @todo monotone_minima \u3088\
    \u308A\u9045\u3044\u306E\u3092\u4F55\u3068\u304B\u3057\u305F\u3044\n */\ntemplate<typename\
    \ F> \nvector<int> totally_monotone_minima(int h, int w, const F &f){\n  auto\
    \ rec = [&](auto self, const vector<int> &hidx, const vector<int> &widx) -> vector<int>\
    \ {\n\n    int n = int(hidx.size());\n    if(n == 0) return {};\n    vector<int>\
    \ nwidx; nwidx.reserve(n);\n    for(int j : widx){\n      while(!nwidx.empty()\
    \ && f(hidx[nwidx.size() - 1], nwidx.back(), j)) nwidx.pop_back();\n      if(int(nwidx.size())\
    \ < n) nwidx.push_back(j);\n    }\n\n    vector<int> ridx; ridx.reserve(n/2);\n\
    \    for(int i = 1; i < n; i += 2) ridx.push_back(hidx[i]);\n    auto rans = self(self,\
    \ ridx, nwidx);\n\n    vector<int> ans(n);\n    for(int i = 1, j = 0; i < n; i\
    \ += 2, ++j) ans[i] = rans[j];\n\n    for(int i = 0, j = 0; i < n; i += 2){\n\
    \      ans[i] = nwidx[j];\n      for(int r = (i+1 == n ? nwidx.back() : ans[i\
    \ + 1]); nwidx[j] != r; ){\n        ++j;\n        if(f(hidx[i], ans[i], nwidx[j]))\
    \ ans[i] = nwidx[j];\n      }\n    }\n    return ans;\n  };\n  vector<int> hidx(h);\
    \ iota(hidx.begin(), hidx.end(), 0);\n  vector<int> widx(w); iota(widx.begin(),\
    \ widx.end(), 0);\n  return rec(rec, hidx, widx);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/totally_monotone_minima.cpp
  requiredBy: []
  timestamp: '2023-08-06 19:24:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/totally_monotone_minima.cpp
layout: document
redirect_from:
- /library/algorithm/totally_monotone_minima.cpp
- /library/algorithm/totally_monotone_minima.cpp.html
title: algorithm/totally_monotone_minima.cpp
---
