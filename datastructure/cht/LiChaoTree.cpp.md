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
  bundledCode: "#line 2 \"datastructure/cht/LiChaoTree.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct LiChaoTree{\r\n  struct Line{\r\n    T a, b;\r\n    Line(T a, T\
    \ b) : a(a), b(b) {}\r\n    inline T get(T x) const { return a*x + b; }\r\n  \
    \  inline bool over(const Line&l, const T &x) const {\r\n      return get(x) <\
    \ l.get(x);\r\n    }\r\n  };\r\n\r\n  vector<T> xs;\r\n  vector<Line> seg;\r\n\
    \  size_t sz;\r\n\r\n  LiChaoTree(const vector<T> &x, T inf): xs(x){\r\n    sz\
    \ = 1;\r\n    while(sz < xs.size()) sz <<= 1;\r\n    while(xs.size() < sz) xs.push_back(xs.back()\
    \ + 1);\r\n    seg.assign(2*sz, Line(0, inf));\r\n  }\r\n\r\n  void add_line(const\
    \ T &a, const T &b){\r\n    Line l(a, b);\r\n    update(l, 1, 0, sz);\r\n  }\r\
    \n\r\n  void add_segment(const T &a, const T &b, int l, int r){\r\n    Line seg(a,\
    \ b);\r\n    int s = l + sz, t = r + sz, shift = 1;\r\n    for(int s=l+sz, t=r+sz;\
    \ s < t; s>>=1, t>>=1, shift<<=1){\r\n      if(s & 1){\r\n        update(seg,\
    \ s++, l, l+shift);\r\n        l += shift;\r\n      }\r\n      if(t & 1){\r\n\
    \        update(seg, --t, r-shift, r);\r\n        r -= shift;\r\n      }\r\n \
    \   }\r\n  }\r\n\r\n  T query(int k){\r\n    const T x = xs[k];\r\n    k += sz;\r\
    \n    T res = seg[k].get(x);\r\n    while(k >>= 1) res = min(res, seg[k].get(x));\r\
    \n\r\n    return res;\r\n  }\r\n\r\nprivate:\r\n  void update(Line x, int k, int\
    \ l, int r){\r\n    while(true){\r\n      int m = (l + r) >> 1;\r\n      bool\
    \ lover = x.over(seg[k], xs[l]);\r\n      bool mover = x.over(seg[k], xs[m]);\r\
    \n      if(mover) swap(seg[k], x);\r\n      if(l+1 >= r) return;\r\n      if(lover\
    \ != mover) k = 2*k, r = m;\r\n      else k = 2*k + 1, l = m;\r\n    }\r\n  }\r\
    \n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct LiChaoTree{\r\n  struct\
    \ Line{\r\n    T a, b;\r\n    Line(T a, T b) : a(a), b(b) {}\r\n    inline T get(T\
    \ x) const { return a*x + b; }\r\n    inline bool over(const Line&l, const T &x)\
    \ const {\r\n      return get(x) < l.get(x);\r\n    }\r\n  };\r\n\r\n  vector<T>\
    \ xs;\r\n  vector<Line> seg;\r\n  size_t sz;\r\n\r\n  LiChaoTree(const vector<T>\
    \ &x, T inf): xs(x){\r\n    sz = 1;\r\n    while(sz < xs.size()) sz <<= 1;\r\n\
    \    while(xs.size() < sz) xs.push_back(xs.back() + 1);\r\n    seg.assign(2*sz,\
    \ Line(0, inf));\r\n  }\r\n\r\n  void add_line(const T &a, const T &b){\r\n  \
    \  Line l(a, b);\r\n    update(l, 1, 0, sz);\r\n  }\r\n\r\n  void add_segment(const\
    \ T &a, const T &b, int l, int r){\r\n    Line seg(a, b);\r\n    int s = l + sz,\
    \ t = r + sz, shift = 1;\r\n    for(int s=l+sz, t=r+sz; s < t; s>>=1, t>>=1, shift<<=1){\r\
    \n      if(s & 1){\r\n        update(seg, s++, l, l+shift);\r\n        l += shift;\r\
    \n      }\r\n      if(t & 1){\r\n        update(seg, --t, r-shift, r);\r\n   \
    \     r -= shift;\r\n      }\r\n    }\r\n  }\r\n\r\n  T query(int k){\r\n    const\
    \ T x = xs[k];\r\n    k += sz;\r\n    T res = seg[k].get(x);\r\n    while(k >>=\
    \ 1) res = min(res, seg[k].get(x));\r\n\r\n    return res;\r\n  }\r\n\r\nprivate:\r\
    \n  void update(Line x, int k, int l, int r){\r\n    while(true){\r\n      int\
    \ m = (l + r) >> 1;\r\n      bool lover = x.over(seg[k], xs[l]);\r\n      bool\
    \ mover = x.over(seg[k], xs[m]);\r\n      if(mover) swap(seg[k], x);\r\n     \
    \ if(l+1 >= r) return;\r\n      if(lover != mover) k = 2*k, r = m;\r\n      else\
    \ k = 2*k + 1, l = m;\r\n    }\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/cht/LiChaoTree.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/cht/LiChaoTree.cpp
layout: document
redirect_from:
- /library/datastructure/cht/LiChaoTree.cpp
- /library/datastructure/cht/LiChaoTree.cpp.html
title: datastructure/cht/LiChaoTree.cpp
---
