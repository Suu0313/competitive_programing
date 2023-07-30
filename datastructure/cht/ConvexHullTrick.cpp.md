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
  bundledCode: "#line 2 \"datastructure/cht/ConvexHullTrick.cpp\"\n\r\ntemplate <typename\
    \ T>\r\nstruct ConvexHullTrick{\r\n  struct Line{\r\n    T a, b;\r\n    Line(T\
    \ a, T b): a(a), b(b){}\r\n  };\r\n  deque<Line> Lines;\r\n  const bool isMin;\r\
    \n\r\n  ConvexHullTrick(bool isMin = true): isMin(isMin) {}\r\n  \r\n  bool empty()\
    \ const { return Lines.empty(); }\r\n  void clear() { Lines.clear(); }\r\n\r\n\
    \  T get_y(const Line &l, const T &x) const {\r\n    return l.a * x + l.b;\r\n\
    \  }\r\n\r\n  bool needless(const Line& l, const Line& m, const Line& r){\r\n\
    \    return (m.a-l.a)*(r.b-m.b) >= (m.b-l.b)*(r.a-m.a);\r\n  }\r\n  bool comp(const\
    \ Line &l, const Line &r, T x){\r\n    return get_y(l, x) >= get_y(r, x);\r\n\
    \  }\r\n\r\n  void add(T a, T b){\r\n    if(!isMin) a*=-1, b*=-1;\r\n    Line\
    \ l(a,b);\r\n    int n = Lines.size();\r\n    if(n == 0){\r\n      Lines.emplace_back(l);\r\
    \n      return;\r\n    }\r\n    auto[na, nb] = Lines.front();\r\n    if(n == 1){\r\
    \n      if(na == a){\r\n        if(nb > b) Lines.front() = l;\r\n      }else if(na\
    \ <= a){\r\n        Lines.emplace_front(l);\r\n      }else{\r\n        Lines.emplace_back(l);\r\
    \n      }\r\n      return;\r\n    }\r\n    if(na <= a){\r\n      while(n>=2 &&\
    \ needless(Lines.front(),Lines[1],l)){\r\n        Lines.pop_front(); n--;\r\n\
    \      }\r\n      Lines.emplace_front(l);\r\n    }else{\r\n      while(n>=2 &&\
    \ needless(Lines[n-2],Lines[n-1],l)){\r\n        Lines.pop_back(); n--;\r\n  \
    \    }\r\n      Lines.emplace_back(l);\r\n    }\r\n  }\r\n\r\n  T query(T x){\r\
    \n    assert(!empty());\r\n    int l = -1, r = Lines.size()-1;\r\n    while(r-l\
    \ > 1){\r\n      int m = (l+r) >> 1;\r\n      if(comp(Lines[m], Lines[m+1], x))\
    \ l = m;\r\n      else r = m;\r\n    }\r\n    if(isMin) return get_y(Lines[r],\
    \ x);\r\n    return -get_y(Lines[r], x);\r\n  }\r\n\r\n  T query_inc(T x){\r\n\
    \    assert(!empty());\r\n    while(int(Lines.size())>=2 && comp(Lines.front(),Lines[1],x))\
    \ Lines.pop_front();\r\n    if(isMin) return get_y(Lines.front(), x);\r\n    return\
    \ -get_y(Lines.front(), x);\r\n  }\r\n\r\n  T query_dec(T x){\r\n    assert(!empty());\r\
    \n    while(int(Lines.size())>=2 && comp(Lines.back(),Lines[int(Lines.size())-2],x))\
    \ Lines.pop_back();\r\n    if(isMin) return get_y(Lines.back(), x);\r\n    return\
    \ -get_y(Lines.back(), x);\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename T>\r\nstruct ConvexHullTrick{\r\n\
    \  struct Line{\r\n    T a, b;\r\n    Line(T a, T b): a(a), b(b){}\r\n  };\r\n\
    \  deque<Line> Lines;\r\n  const bool isMin;\r\n\r\n  ConvexHullTrick(bool isMin\
    \ = true): isMin(isMin) {}\r\n  \r\n  bool empty() const { return Lines.empty();\
    \ }\r\n  void clear() { Lines.clear(); }\r\n\r\n  T get_y(const Line &l, const\
    \ T &x) const {\r\n    return l.a * x + l.b;\r\n  }\r\n\r\n  bool needless(const\
    \ Line& l, const Line& m, const Line& r){\r\n    return (m.a-l.a)*(r.b-m.b) >=\
    \ (m.b-l.b)*(r.a-m.a);\r\n  }\r\n  bool comp(const Line &l, const Line &r, T x){\r\
    \n    return get_y(l, x) >= get_y(r, x);\r\n  }\r\n\r\n  void add(T a, T b){\r\
    \n    if(!isMin) a*=-1, b*=-1;\r\n    Line l(a,b);\r\n    int n = Lines.size();\r\
    \n    if(n == 0){\r\n      Lines.emplace_back(l);\r\n      return;\r\n    }\r\n\
    \    auto[na, nb] = Lines.front();\r\n    if(n == 1){\r\n      if(na == a){\r\n\
    \        if(nb > b) Lines.front() = l;\r\n      }else if(na <= a){\r\n       \
    \ Lines.emplace_front(l);\r\n      }else{\r\n        Lines.emplace_back(l);\r\n\
    \      }\r\n      return;\r\n    }\r\n    if(na <= a){\r\n      while(n>=2 &&\
    \ needless(Lines.front(),Lines[1],l)){\r\n        Lines.pop_front(); n--;\r\n\
    \      }\r\n      Lines.emplace_front(l);\r\n    }else{\r\n      while(n>=2 &&\
    \ needless(Lines[n-2],Lines[n-1],l)){\r\n        Lines.pop_back(); n--;\r\n  \
    \    }\r\n      Lines.emplace_back(l);\r\n    }\r\n  }\r\n\r\n  T query(T x){\r\
    \n    assert(!empty());\r\n    int l = -1, r = Lines.size()-1;\r\n    while(r-l\
    \ > 1){\r\n      int m = (l+r) >> 1;\r\n      if(comp(Lines[m], Lines[m+1], x))\
    \ l = m;\r\n      else r = m;\r\n    }\r\n    if(isMin) return get_y(Lines[r],\
    \ x);\r\n    return -get_y(Lines[r], x);\r\n  }\r\n\r\n  T query_inc(T x){\r\n\
    \    assert(!empty());\r\n    while(int(Lines.size())>=2 && comp(Lines.front(),Lines[1],x))\
    \ Lines.pop_front();\r\n    if(isMin) return get_y(Lines.front(), x);\r\n    return\
    \ -get_y(Lines.front(), x);\r\n  }\r\n\r\n  T query_dec(T x){\r\n    assert(!empty());\r\
    \n    while(int(Lines.size())>=2 && comp(Lines.back(),Lines[int(Lines.size())-2],x))\
    \ Lines.pop_back();\r\n    if(isMin) return get_y(Lines.back(), x);\r\n    return\
    \ -get_y(Lines.back(), x);\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/cht/ConvexHullTrick.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/cht/ConvexHullTrick.cpp
layout: document
redirect_from:
- /library/datastructure/cht/ConvexHullTrick.cpp
- /library/datastructure/cht/ConvexHullTrick.cpp.html
title: datastructure/cht/ConvexHullTrick.cpp
---
