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
  bundledCode: "#line 2 \"datastructure/cht/DynamicLiChaoTree.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct DynamicLiChaoTree{\r\n  struct Line{\r\n    T a, b;\r\n    Line(T\
    \ a, T b) : a(a), b(b) {}\r\n    inline T get(T x) const { return a*x + b; }\r\
    \n  };\r\n  struct Node{\r\n    Line f;\r\n    Node *l, *r;\r\n    Node(const\
    \ Line &f): f(f), l(nullptr), r(nullptr) {}\r\n  };\r\n\r\n  Node *root;\r\n \
    \ const T low, high, id;\r\n\r\n  DynamicLiChaoTree(const T &low, const T &high,\
    \ const T &id)\r\n    : root(nullptr), low(low), high(high), id(id){}\r\n\r\n\
    \  void add_line(const T &a, const T &b){\r\n    Line f(a, b);\r\n    root = add_line(root,\
    \ f, low, high, f.get(low), f.get(high));\r\n  }\r\n  void add_segment(const T\
    \ &a, const T &b, const T &l, const T &r){\r\n    Line f(a, b);\r\n    root =\
    \ add_segment(root, f, l, r-1, low, high, f.get(low), f.get(high));\r\n  }\r\n\
    \r\n  T query(const T &x) const {\r\n    return query(root, low, high, x);\r\n\
    \  }\r\n\r\nprivate:\r\n  Node *add_line(Node *t, Line &f, const T &l, const T\
    \ &r, const T &f_l, const T &f_r){\r\n    if(!t) return new Node(f);\r\n    T\
    \ t_l = t->f.get(l), t_r = t->f.get(r);\r\n    if(t_l <= f_l && t_r <= f_r){\r\
    \n      return t;\r\n    }else if(t_l >= f_l && t_r >= f_r){\r\n      t->f = f;\
    \ return t;\r\n    }else{\r\n      T m = (l + r)/2;\r\n      if(m == r) --m;\r\
    \n      T t_m = t->f.get(m), f_m = f.get(m);\r\n      if(t_m > f_m){\r\n     \
    \   swap(t->f, f);\r\n        if(f_l >= t_l) t->l = add_line(t->l, f, l, m, t_l,\
    \ t_m);\r\n        else t->r = add_line(t->r, f, m+1, r, t_m+f.a, t_r);\r\n  \
    \    }else{\r\n        if(t_l >= f_l) t->l = add_line(t->l, f, l, m, f_l, f_m);\r\
    \n        else t->r = add_line(t->r, f, m+1, r, f_m+f.a, f_r);\r\n      }\r\n\
    \      return t;\r\n    }\r\n  }\r\n\r\n  Node *add_segment(Node *t, Line &f,\
    \ const T &p, const T &q , const T &l, const T &r, const T &f_l, const T &f_r){\r\
    \n    if(r < p || q < l) return t;\r\n    if(p <= l && r <= q){\r\n      Line\
    \ g{f};\r\n      return add_line(t, g, l, r, f_l, f_r);\r\n    }\r\n    if(t){\r\
    \n      T t_l = t->f.get(l), t_r = t->f.get(r);\r\n      if(t_l <= f_l && t_r\
    \ <= f_r) return t;\r\n    }else{\r\n      t = new Node(Line(0, id));\r\n    }\r\
    \n    T m = (l + r)/2;\r\n    if(m == r) --m;\r\n    T f_m = f.get(m);\r\n   \
    \ t->l = add_segment(t->l, f, p, q, l, m, f_l, f_m);\r\n    t->r = add_segment(t->r,\
    \ f, p, q, m + 1, r, f_m + f.a, f_r);\r\n    return t;\r\n  }\r\n\r\n  T query(const\
    \ Node *t, const T &l, const T &r, const T &x) const {\r\n    if(!t) return id;\r\
    \n    if(l == r) return t->f.get(x);\r\n    T m = (l + r)/2;\r\n    if(m == r)\
    \ --m;\r\n    if(x <= m) return min(t->f.get(x), query(t->l, l, m, x));\r\n  \
    \  else return min(t->f.get(x), query(t->r, m+1, r, x));\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct DynamicLiChaoTree{\r\n\
    \  struct Line{\r\n    T a, b;\r\n    Line(T a, T b) : a(a), b(b) {}\r\n    inline\
    \ T get(T x) const { return a*x + b; }\r\n  };\r\n  struct Node{\r\n    Line f;\r\
    \n    Node *l, *r;\r\n    Node(const Line &f): f(f), l(nullptr), r(nullptr) {}\r\
    \n  };\r\n\r\n  Node *root;\r\n  const T low, high, id;\r\n\r\n  DynamicLiChaoTree(const\
    \ T &low, const T &high, const T &id)\r\n    : root(nullptr), low(low), high(high),\
    \ id(id){}\r\n\r\n  void add_line(const T &a, const T &b){\r\n    Line f(a, b);\r\
    \n    root = add_line(root, f, low, high, f.get(low), f.get(high));\r\n  }\r\n\
    \  void add_segment(const T &a, const T &b, const T &l, const T &r){\r\n    Line\
    \ f(a, b);\r\n    root = add_segment(root, f, l, r-1, low, high, f.get(low), f.get(high));\r\
    \n  }\r\n\r\n  T query(const T &x) const {\r\n    return query(root, low, high,\
    \ x);\r\n  }\r\n\r\nprivate:\r\n  Node *add_line(Node *t, Line &f, const T &l,\
    \ const T &r, const T &f_l, const T &f_r){\r\n    if(!t) return new Node(f);\r\
    \n    T t_l = t->f.get(l), t_r = t->f.get(r);\r\n    if(t_l <= f_l && t_r <= f_r){\r\
    \n      return t;\r\n    }else if(t_l >= f_l && t_r >= f_r){\r\n      t->f = f;\
    \ return t;\r\n    }else{\r\n      T m = (l + r)/2;\r\n      if(m == r) --m;\r\
    \n      T t_m = t->f.get(m), f_m = f.get(m);\r\n      if(t_m > f_m){\r\n     \
    \   swap(t->f, f);\r\n        if(f_l >= t_l) t->l = add_line(t->l, f, l, m, t_l,\
    \ t_m);\r\n        else t->r = add_line(t->r, f, m+1, r, t_m+f.a, t_r);\r\n  \
    \    }else{\r\n        if(t_l >= f_l) t->l = add_line(t->l, f, l, m, f_l, f_m);\r\
    \n        else t->r = add_line(t->r, f, m+1, r, f_m+f.a, f_r);\r\n      }\r\n\
    \      return t;\r\n    }\r\n  }\r\n\r\n  Node *add_segment(Node *t, Line &f,\
    \ const T &p, const T &q , const T &l, const T &r, const T &f_l, const T &f_r){\r\
    \n    if(r < p || q < l) return t;\r\n    if(p <= l && r <= q){\r\n      Line\
    \ g{f};\r\n      return add_line(t, g, l, r, f_l, f_r);\r\n    }\r\n    if(t){\r\
    \n      T t_l = t->f.get(l), t_r = t->f.get(r);\r\n      if(t_l <= f_l && t_r\
    \ <= f_r) return t;\r\n    }else{\r\n      t = new Node(Line(0, id));\r\n    }\r\
    \n    T m = (l + r)/2;\r\n    if(m == r) --m;\r\n    T f_m = f.get(m);\r\n   \
    \ t->l = add_segment(t->l, f, p, q, l, m, f_l, f_m);\r\n    t->r = add_segment(t->r,\
    \ f, p, q, m + 1, r, f_m + f.a, f_r);\r\n    return t;\r\n  }\r\n\r\n  T query(const\
    \ Node *t, const T &l, const T &r, const T &x) const {\r\n    if(!t) return id;\r\
    \n    if(l == r) return t->f.get(x);\r\n    T m = (l + r)/2;\r\n    if(m == r)\
    \ --m;\r\n    if(x <= m) return min(t->f.get(x), query(t->l, l, m, x));\r\n  \
    \  else return min(t->f.get(x), query(t->r, m+1, r, x));\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/cht/DynamicLiChaoTree.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/cht/DynamicLiChaoTree.cpp
layout: document
redirect_from:
- /library/datastructure/cht/DynamicLiChaoTree.cpp
- /library/datastructure/cht/DynamicLiChaoTree.cpp.html
title: datastructure/cht/DynamicLiChaoTree.cpp
---
