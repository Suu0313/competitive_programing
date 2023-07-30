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
  bundledCode: "#line 2 \"container/compress.cpp\"\n\r\ntemplate<typename T, class\
    \ Compair = less<T>>\r\nstruct Compress{\r\n  vector<T> a;\r\n  Compair cmp;\r\
    \n  Compress(const vector<T> &a, const Compair &cmp = Compair{}, bool bd = true,\
    \ int base = 0)\r\n  : a(a), cmp(cmp) { if(bd) build(base); }\r\n\r\n  void add(const\
    \ T &x){ a.emplace_back(x); }\r\n  void add(const vector<T> &xs){ for(auto&&x\
    \ : xs ) a.emplace_back(x); }\r\n\r\n  vector<T> dict;\r\n  vector<int> res;\r\
    \n  void build(int base = 0){\r\n    int n = int(a.size());\r\n    if(n == 0)\
    \ return;\r\n\r\n    vector<int> idx(n); iota(idx.begin(), idx.end(), 0);\r\n\
    \    sort(idx.begin(), idx.end(), [&](int i, int j){ return cmp(a[i], a[j]); });\r\
    \n    \r\n    res.assign(n, base); dict.assign(1, a[idx[0]]);\r\n    for(int i\
    \ = 1; i < n; i++){\r\n      int x = idx[i-1], y = idx[i];\r\n      if(a[x] ==\
    \ a[y]) res[y] = res[x];\r\n      else{\r\n        res[y] = res[x] + 1;\r\n  \
    \      dict.emplace_back(a[y]);\r\n      }\r\n    }\r\n  }\r\n\r\n  int get(const\
    \ T &x) const {\r\n    return lower_bound(begin(dict), end(dict), x) - begin(dict);\r\
    \n  }\r\n  const int &operator[](int k) const { return res[k]; }\r\n\r\n  size_t\
    \ size() const { return dict.size(); }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T, class Compair = less<T>>\r\nstruct\
    \ Compress{\r\n  vector<T> a;\r\n  Compair cmp;\r\n  Compress(const vector<T>\
    \ &a, const Compair &cmp = Compair{}, bool bd = true, int base = 0)\r\n  : a(a),\
    \ cmp(cmp) { if(bd) build(base); }\r\n\r\n  void add(const T &x){ a.emplace_back(x);\
    \ }\r\n  void add(const vector<T> &xs){ for(auto&&x : xs ) a.emplace_back(x);\
    \ }\r\n\r\n  vector<T> dict;\r\n  vector<int> res;\r\n  void build(int base =\
    \ 0){\r\n    int n = int(a.size());\r\n    if(n == 0) return;\r\n\r\n    vector<int>\
    \ idx(n); iota(idx.begin(), idx.end(), 0);\r\n    sort(idx.begin(), idx.end(),\
    \ [&](int i, int j){ return cmp(a[i], a[j]); });\r\n    \r\n    res.assign(n,\
    \ base); dict.assign(1, a[idx[0]]);\r\n    for(int i = 1; i < n; i++){\r\n   \
    \   int x = idx[i-1], y = idx[i];\r\n      if(a[x] == a[y]) res[y] = res[x];\r\
    \n      else{\r\n        res[y] = res[x] + 1;\r\n        dict.emplace_back(a[y]);\r\
    \n      }\r\n    }\r\n  }\r\n\r\n  int get(const T &x) const {\r\n    return lower_bound(begin(dict),\
    \ end(dict), x) - begin(dict);\r\n  }\r\n  const int &operator[](int k) const\
    \ { return res[k]; }\r\n\r\n  size_t size() const { return dict.size(); }\r\n\
    };\r\n"
  dependsOn: []
  isVerificationFile: false
  path: container/compress.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: container/compress.cpp
layout: document
redirect_from:
- /library/container/compress.cpp
- /library/container/compress.cpp.html
title: container/compress.cpp
---
