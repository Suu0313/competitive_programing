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
  bundledCode: "#line 2 \"datastructure/cht/PersistentDynamicLiChaoTree.cpp\"\n\r\n\
    template<typename T>\r\nstruct PersistentDynamicLiChaoTree{\r\n  using Pti = pair<T,\
    \ int>;\r\n  struct Line{\r\n    T a, b;\r\n    int idx;\r\n    Line(T a, T b,\
    \ int idx = -1) : a(a), b(b), idx(idx) {}\r\n    inline Pti get(T x) const { return\
    \ {a*x + b, idx}; }\r\n  };\r\n  struct Node{\r\n    Line f;\r\n    Node *l, *r;\r\
    \n    Node(const Line &f): f(f), l(nullptr), r(nullptr) {}\r\n    Node(const Node\
    \ *t): f(t->f), l(t->l), r(t->r) {}\r\n  };\r\n\r\n  const T low, high, id;\r\n\
    \r\n  PersistentDynamicLiChaoTree(const T &low, const T &high, const T &id): low(low),\
    \ high(high), id(id){}\r\n\r\n  static Node *get_root(){ return nullptr; }\r\n\
    \r\n  Node *add_line(Node *root, const T &a, const T &b, int idx){\r\n    Line\
    \ f(a, b, idx);\r\n    return add_line(root, f, low, high, f.get(low), f.get(high));\r\
    \n  }\r\n  Node *add_segment(Node *root, const T &a, const T &b, const T &l, const\
    \ T &r, int idx){\r\n    Line f(a, b, idx);\r\n    return add_segment(root, f,\
    \ l, r-1, low, high, f.get(low), f.get(high));\r\n  }\r\n\r\n  pair<T, int> query(Node\
    \ *root, const T &x) const { return query(root, low, high, x); }\r\n\r\nprivate:\r\
    \n  Node *add_line(Node *t, Line &f, const T &l, const T &r, const Pti &f_l, const\
    \ Pti &f_r){\r\n    if(!t) return new Node(f);\r\n    auto t_l = t->f.get(l),\
    \ t_r = t->f.get(r);\r\n    if(t_l <= f_l && t_r <= f_r){\r\n      return t;\r\
    \n    }else if(t_l >= f_l && t_r >= f_r){\r\n      Node *p = new Node(t);\r\n\
    \      p->f = f; return p;\r\n    }else{\r\n      T m = (l + r)/2;\r\n      if(m\
    \ == r) --m;\r\n      auto t_m = t->f.get(m), f_m = f.get(m);\r\n      Node *p\
    \ = new Node(t);\r\n      if(t_m > f_m){\r\n        swap(p->f, f);\r\n       \
    \ if(f_l >= t_l) p->l = add_line(p->l, f, l, m, t_l, t_m);\r\n        else p->r\
    \ = add_line(p->r, f, m+1, r, {t_m.first+f.a, t_m.second}, t_r);\r\n      }else{\r\
    \n        if(t_l >= f_l) p->l = add_line(p->l, f, l, m, f_l, f_m);\r\n       \
    \ else p->r = add_line(p->r, f, m+1, r, {f_m.first+f.a, f_m.second}, f_r);\r\n\
    \      }\r\n      return p;\r\n    }\r\n  }\r\n\r\n  Node *add_segment(Node *t,\
    \ Line &f, const T &p, const T &q , const T &l, const T &r, const Pti &f_l, const\
    \ Pti &f_r){\r\n    if(r < p || q < l) return t;\r\n    if(p <= l && r <= q){\r\
    \n      Line g{f};\r\n      return add_line(t, g, l, r, f_l, f_r);\r\n    }\r\n\
    \    if(t){\r\n      auto t_l = t->f.get(l), t_r = t->f.get(r);\r\n      if(t_l\
    \ <= f_l && t_r <= f_r) return t;\r\n    }\r\n    Node *s = new Node(Line(0, id));\r\
    \n    T m = (l + r)/2;\r\n    auto f_m = f.get(m);\r\n    s->l = add_segment(s->l,\
    \ f, p, q, l, m, f_l, f_m);\r\n    s->r = add_segment(s->r, f, p, q, m + 1, r,\
    \ {f_m.first+f.a, f_m.second}, f_r);\r\n    return p;\r\n  }\r\n\r\n  pair<T,\
    \ int>  query(const Node *t, const T &l, const T &r, const T &x) const {\r\n \
    \   if(!t) return {id, -1};\r\n    if(l == r) return t->f.get(x);\r\n    T m =\
    \ (l + r)/2;\r\n    if(m == r) --m;\r\n    if(x <= m) return min(t->f.get(x),\
    \ query(t->l, l, m, x));\r\n    else return min(t->f.get(x), query(t->r, m+1,\
    \ r, x));\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct PersistentDynamicLiChaoTree{\r\
    \n  using Pti = pair<T, int>;\r\n  struct Line{\r\n    T a, b;\r\n    int idx;\r\
    \n    Line(T a, T b, int idx = -1) : a(a), b(b), idx(idx) {}\r\n    inline Pti\
    \ get(T x) const { return {a*x + b, idx}; }\r\n  };\r\n  struct Node{\r\n    Line\
    \ f;\r\n    Node *l, *r;\r\n    Node(const Line &f): f(f), l(nullptr), r(nullptr)\
    \ {}\r\n    Node(const Node *t): f(t->f), l(t->l), r(t->r) {}\r\n  };\r\n\r\n\
    \  const T low, high, id;\r\n\r\n  PersistentDynamicLiChaoTree(const T &low, const\
    \ T &high, const T &id): low(low), high(high), id(id){}\r\n\r\n  static Node *get_root(){\
    \ return nullptr; }\r\n\r\n  Node *add_line(Node *root, const T &a, const T &b,\
    \ int idx){\r\n    Line f(a, b, idx);\r\n    return add_line(root, f, low, high,\
    \ f.get(low), f.get(high));\r\n  }\r\n  Node *add_segment(Node *root, const T\
    \ &a, const T &b, const T &l, const T &r, int idx){\r\n    Line f(a, b, idx);\r\
    \n    return add_segment(root, f, l, r-1, low, high, f.get(low), f.get(high));\r\
    \n  }\r\n\r\n  pair<T, int> query(Node *root, const T &x) const { return query(root,\
    \ low, high, x); }\r\n\r\nprivate:\r\n  Node *add_line(Node *t, Line &f, const\
    \ T &l, const T &r, const Pti &f_l, const Pti &f_r){\r\n    if(!t) return new\
    \ Node(f);\r\n    auto t_l = t->f.get(l), t_r = t->f.get(r);\r\n    if(t_l <=\
    \ f_l && t_r <= f_r){\r\n      return t;\r\n    }else if(t_l >= f_l && t_r >=\
    \ f_r){\r\n      Node *p = new Node(t);\r\n      p->f = f; return p;\r\n    }else{\r\
    \n      T m = (l + r)/2;\r\n      if(m == r) --m;\r\n      auto t_m = t->f.get(m),\
    \ f_m = f.get(m);\r\n      Node *p = new Node(t);\r\n      if(t_m > f_m){\r\n\
    \        swap(p->f, f);\r\n        if(f_l >= t_l) p->l = add_line(p->l, f, l,\
    \ m, t_l, t_m);\r\n        else p->r = add_line(p->r, f, m+1, r, {t_m.first+f.a,\
    \ t_m.second}, t_r);\r\n      }else{\r\n        if(t_l >= f_l) p->l = add_line(p->l,\
    \ f, l, m, f_l, f_m);\r\n        else p->r = add_line(p->r, f, m+1, r, {f_m.first+f.a,\
    \ f_m.second}, f_r);\r\n      }\r\n      return p;\r\n    }\r\n  }\r\n\r\n  Node\
    \ *add_segment(Node *t, Line &f, const T &p, const T &q , const T &l, const T\
    \ &r, const Pti &f_l, const Pti &f_r){\r\n    if(r < p || q < l) return t;\r\n\
    \    if(p <= l && r <= q){\r\n      Line g{f};\r\n      return add_line(t, g,\
    \ l, r, f_l, f_r);\r\n    }\r\n    if(t){\r\n      auto t_l = t->f.get(l), t_r\
    \ = t->f.get(r);\r\n      if(t_l <= f_l && t_r <= f_r) return t;\r\n    }\r\n\
    \    Node *s = new Node(Line(0, id));\r\n    T m = (l + r)/2;\r\n    auto f_m\
    \ = f.get(m);\r\n    s->l = add_segment(s->l, f, p, q, l, m, f_l, f_m);\r\n  \
    \  s->r = add_segment(s->r, f, p, q, m + 1, r, {f_m.first+f.a, f_m.second}, f_r);\r\
    \n    return p;\r\n  }\r\n\r\n  pair<T, int>  query(const Node *t, const T &l,\
    \ const T &r, const T &x) const {\r\n    if(!t) return {id, -1};\r\n    if(l ==\
    \ r) return t->f.get(x);\r\n    T m = (l + r)/2;\r\n    if(m == r) --m;\r\n  \
    \  if(x <= m) return min(t->f.get(x), query(t->l, l, m, x));\r\n    else return\
    \ min(t->f.get(x), query(t->r, m+1, r, x));\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/cht/PersistentDynamicLiChaoTree.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/cht/PersistentDynamicLiChaoTree.cpp
layout: document
redirect_from:
- /library/datastructure/cht/PersistentDynamicLiChaoTree.cpp
- /library/datastructure/cht/PersistentDynamicLiChaoTree.cpp.html
title: datastructure/cht/PersistentDynamicLiChaoTree.cpp
---
