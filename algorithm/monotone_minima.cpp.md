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
  bundledCode: "#line 1 \"algorithm/monotone_minima.cpp\"\n/**\n * [0 <= i < h) find\
    \ f(i) O(h + wlogh)\n * \n * @tparam F (int, int, int) -> bool\n * @param h \n\
    \ * @param w \n * @param f (i, pj, nj) -> nj is better than pj\n * @return vector<int>\
    \ f[i] is best j\n * @todo \u975E\u518D\u5E30\u306B\u3067\u304D\u306A\u3044\u3093\
    \u3067\u3059\u304B\u3053\u308C\n */\ntemplate<typename F> \nvector<int> monotone_minima(int\
    \ h, int w, const F &f){\n  auto rec = [&](auto self, const vector<int> &idx)\
    \ -> vector<int> {\n    int n = int(idx.size());\n    if(n == 0) return {};\n\
    \    vector<int> ridx; ridx.reserve(n/2);\n    for(int i = 1; i < n; i += 2) ridx.push_back(idx[i]);\n\
    \    auto rans = self(self, ridx);\n    vector<int> ans(n);\n    for(int i = 1,\
    \ j = 0; i < n; i += 2, ++j) ans[i] = rans[j];\n    for(int i = 0, j = 0; i <\
    \ n; i += 2){\n      ans[i] = j;\n      for(int r = (i+1 == n ? w - 1 : ans[i\
    \ + 1]); j != r; ){\n        ++j;\n        if(f(idx[i], ans[i], j)) ans[i] = j;\n\
    \      }\n    }\n    return ans;\n  };\n  vector<int> idx(h); iota(idx.begin(),\
    \ idx.end(), 0);\n  return rec(rec, idx);\n}\n"
  code: "/**\n * [0 <= i < h) find f(i) O(h + wlogh)\n * \n * @tparam F (int, int,\
    \ int) -> bool\n * @param h \n * @param w \n * @param f (i, pj, nj) -> nj is better\
    \ than pj\n * @return vector<int> f[i] is best j\n * @todo \u975E\u518D\u5E30\u306B\
    \u3067\u304D\u306A\u3044\u3093\u3067\u3059\u304B\u3053\u308C\n */\ntemplate<typename\
    \ F> \nvector<int> monotone_minima(int h, int w, const F &f){\n  auto rec = [&](auto\
    \ self, const vector<int> &idx) -> vector<int> {\n    int n = int(idx.size());\n\
    \    if(n == 0) return {};\n    vector<int> ridx; ridx.reserve(n/2);\n    for(int\
    \ i = 1; i < n; i += 2) ridx.push_back(idx[i]);\n    auto rans = self(self, ridx);\n\
    \    vector<int> ans(n);\n    for(int i = 1, j = 0; i < n; i += 2, ++j) ans[i]\
    \ = rans[j];\n    for(int i = 0, j = 0; i < n; i += 2){\n      ans[i] = j;\n \
    \     for(int r = (i+1 == n ? w - 1 : ans[i + 1]); j != r; ){\n        ++j;\n\
    \        if(f(idx[i], ans[i], j)) ans[i] = j;\n      }\n    }\n    return ans;\n\
    \  };\n  vector<int> idx(h); iota(idx.begin(), idx.end(), 0);\n  return rec(rec,\
    \ idx);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/monotone_minima.cpp
  requiredBy: []
  timestamp: '2023-08-06 19:24:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/monotone_minima.cpp
layout: document
redirect_from:
- /library/algorithm/monotone_minima.cpp
- /library/algorithm/monotone_minima.cpp.html
title: algorithm/monotone_minima.cpp
---
