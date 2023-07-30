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
  bundledCode: "#line 1 \"unuse/old_datastructure/old_lazy_segtree.cpp\"\ntemplate<typename\
    \ M, typename OM, typename F, typename G, typename H>\r\nstruct LazySegTree{\r\
    \n  int n, defn, height;\r\n  vector<M> node;\r\n  vector<OM> lazy;\r\n  vector<int>\
    \ sz;\r\n  const F f;\r\n  const G g;\r\n  const H h;\r\n  const M m;\r\n  const\
    \ OM om;\r\n\r\n  LazySegTree(int _n, const F &f, const G &g, const H &h, const\
    \ M &m, const OM &om): f(f), g(g), h(h), m(m), om(om){\r\n    n = 1;\r\n    defn\
    \ = _n;\r\n    height = 0;\r\n    while(n<defn) n<<=1, height++;\r\n    node.assign(2*n,\
    \ m);\r\n    lazy.assign(n, om);\r\n    sz.assign(2*n, 1);\r\n    for(int k =\
    \ n-1; k >= 0; k--) sz.at(k) = sz.at(2*k) + sz.at(2*k+1);\r\n  }\r\n\r\n  void\
    \ set(int k, const M &x){ node.at(k + n) = x; }\r\n  \r\n  void build(){\r\n \
    \   for(int k = n-1; k >= 0; k--){ node.at(k) = f(node.at(2*k), node.at(2*k+1));\
    \ }\r\n  }\r\n\r\n  void build(const vector<M> &v){\r\n    assert((int)v.size()\
    \ == defn);\r\n    for(int k = 0; k < defn; k++) node[k+n] = v[k];\r\n    build();\r\
    \n  }\r\n\r\n  void change(int k, const M &x){\r\n    k += n;\r\n    for(int i\
    \ = height; i>=1; --i) push(k >> i);\r\n    node.at(k) = x;\r\n    for(int i=1;\
    \ i <= height; i++) propagate(k >> i);\r\n  }\r\n\r\n  void update(int k, const\
    \ OM &x){\r\n    k += n;\r\n    for(int i = height; i>=1; --i) push(k >> i);\r\
    \n    node.at(k) = g(node.at(k), x, sz.at(k));\r\n    for(int i=1; i <= height;\
    \ i++) propagate(k >> i);\r\n  }\r\n\r\n  void update(int l, int r, const OM &x){\r\
    \n    if(l == r) return;\r\n    l += n; r += n;\r\n\r\n    for(int i = height;\
    \ i>=1; --i){\r\n      if(((l>>i)<<i) != l) push(l >> i);\r\n      if(((r>>i)<<i)\
    \ != r) push((r-1) >> i);\r\n    }\r\n\r\n    {\r\n      int l2 = l, r2 = r;\r\
    \n      while(l2 < r2){\r\n        if(l2&1) all_apply(l2++, x);\r\n        if(r2&1)\
    \ all_apply(--r2, x);\r\n        l2 >>= 1;\r\n        r2 >>= 1;\r\n      }\r\n\
    \    }\r\n\r\n    for(int i = 1; i <= height; ++i){\r\n      if(((l>>i)<<i) !=\
    \ l) propagate(l >> i);\r\n      if(((r>>i)<<i) != r) propagate((r-1) >> i);\r\
    \n    }\r\n  }\r\n\r\n  M at(int k){\r\n    k += n;\r\n    for(int i = height;\
    \ i>=1; --i) push(k >> i);\r\n    return node.at(k);\r\n  }\r\n\r\n  M operator[](int\
    \ k){\r\n    k += n;\r\n    for(int i = height; i>=1; --i) push(k >> i);\r\n \
    \   return node.at(k);\r\n  }\r\n\r\n  M query(int l, int r){\r\n    if(l == r)\
    \ return m;\r\n    l += n; r += n;\r\n\r\n    for(int i = height; i>=1; --i){\r\
    \n      if(((l>>i)<<i) != l) push(l >> i);\r\n      if(((r>>i)<<i) != r) push(r\
    \ >> i);\r\n    }\r\n\r\n    M sl = m, sr = m;\r\n    while(l < r){\r\n      if(l&1)\
    \ sl = f(sl, node.at(l++));\r\n      if(r&1) sr = f(node.at(--r), sr);\r\n   \
    \   l >>= 1;\r\n      r >>= 1;\r\n    }\r\n    return f(sl, sr);\r\n  }\r\n\r\n\
    \  M all_query() const { return node.at(1); }\r\n\r\n  template<typename C>\r\n\
    \  int max_right(int l, C &check){\r\n    if(l == defn) return defn;\r\n    l\
    \ += n;\r\n    for(int i = height; i>=1; --i) push(l >> i);\r\n    M sm = m;\r\
    \n    do{\r\n      while(l%2 == 0) l >>= 1;\r\n      if(!check(f(sm, node.at(l)))){\r\
    \n        while(l < n){\r\n          push(l);\r\n          l *= 2;\r\n       \
    \   if(check(f(sm, node.at(l)))){\r\n            sm = f(sm, node.at(l));\r\n \
    \           l++;\r\n          }\r\n        }\r\n        return l - n;\r\n    \
    \  }\r\n      sm = f(sm, node.at(l));\r\n      l++;\r\n    }while((l&-l) != l);\r\
    \n    return defn;\r\n  }\r\n\r\n  template<typename C>\r\n  int max_left(int\
    \ r, C &check){\r\n    if(r == 0) return 0;\r\n    r += n;\r\n    for(int i =\
    \ height; i>=1; --i) push((r-1) >> i);\r\n    M sm = m;\r\n    do{\r\n      while(r>1\
    \ && (r%2)) r >>= 1;\r\n      if(!check(f(node.at(r), sm))){\r\n        while(r\
    \ < n){\r\n          push(r);\r\n          r *= 2*r + 1;\r\n          if(check(f(node.at(r),\
    \ sm))){\r\n            sm = f(node.at(r), sm);\r\n            r--;\r\n      \
    \    }\r\n        }\r\n        return r + 1 - n;\r\n      }\r\n      sm = f(node.at(r),\
    \ sm);\r\n    }while((r&-r) != r);\r\n    return 0;\r\n  }\r\n\r\nprivate:\r\n\
    \  void propagate(int k){ node.at(k) = f(node.at(2*k), node.at(2*k + 1));}\r\n\
    \  void all_apply(int k, OM x){\r\n    node.at(k) = g(node.at(k), x, sz.at(k));\r\
    \n    if(k < n) lazy.at(k) = h(lazy.at(k), x);\r\n  }\r\n  void push(int k){\r\
    \n    if(lazy.at(k) == om) return;\r\n    all_apply(2*k, lazy.at(k));\r\n    all_apply(2*k\
    \ + 1, lazy.at(k));\r\n    lazy.at(k) = om;\r\n  }\r\n};\r\n\r\ntemplate<typename\
    \ M, typename OM, typename F, typename G, typename H>\r\nLazySegTree<M,OM,F,G,H>\
    \ get_lazysegtree(int n, const F &f, const G &g, const H &h, const M &m, const\
    \ OM &om){\r\n  return {n, f, g, h, m, om};\r\n}\r\n\r\ntemplate<typename M, typename\
    \ OM, typename F, typename G, typename H>\r\nLazySegTree<M,OM,F,G,H> get_lazysegtree(int\
    \ n, const F &f, const G &g, const H &h, const M &m, const OM &om, const vector<M>\
    \ &v){\r\n  LazySegTree<M,OM,F,G,H> seg(n, f, g, h, m, om);\r\n  seg.build(v);\r\
    \n  return seg;\r\n}\r\n"
  code: "template<typename M, typename OM, typename F, typename G, typename H>\r\n\
    struct LazySegTree{\r\n  int n, defn, height;\r\n  vector<M> node;\r\n  vector<OM>\
    \ lazy;\r\n  vector<int> sz;\r\n  const F f;\r\n  const G g;\r\n  const H h;\r\
    \n  const M m;\r\n  const OM om;\r\n\r\n  LazySegTree(int _n, const F &f, const\
    \ G &g, const H &h, const M &m, const OM &om): f(f), g(g), h(h), m(m), om(om){\r\
    \n    n = 1;\r\n    defn = _n;\r\n    height = 0;\r\n    while(n<defn) n<<=1,\
    \ height++;\r\n    node.assign(2*n, m);\r\n    lazy.assign(n, om);\r\n    sz.assign(2*n,\
    \ 1);\r\n    for(int k = n-1; k >= 0; k--) sz.at(k) = sz.at(2*k) + sz.at(2*k+1);\r\
    \n  }\r\n\r\n  void set(int k, const M &x){ node.at(k + n) = x; }\r\n  \r\n  void\
    \ build(){\r\n    for(int k = n-1; k >= 0; k--){ node.at(k) = f(node.at(2*k),\
    \ node.at(2*k+1)); }\r\n  }\r\n\r\n  void build(const vector<M> &v){\r\n    assert((int)v.size()\
    \ == defn);\r\n    for(int k = 0; k < defn; k++) node[k+n] = v[k];\r\n    build();\r\
    \n  }\r\n\r\n  void change(int k, const M &x){\r\n    k += n;\r\n    for(int i\
    \ = height; i>=1; --i) push(k >> i);\r\n    node.at(k) = x;\r\n    for(int i=1;\
    \ i <= height; i++) propagate(k >> i);\r\n  }\r\n\r\n  void update(int k, const\
    \ OM &x){\r\n    k += n;\r\n    for(int i = height; i>=1; --i) push(k >> i);\r\
    \n    node.at(k) = g(node.at(k), x, sz.at(k));\r\n    for(int i=1; i <= height;\
    \ i++) propagate(k >> i);\r\n  }\r\n\r\n  void update(int l, int r, const OM &x){\r\
    \n    if(l == r) return;\r\n    l += n; r += n;\r\n\r\n    for(int i = height;\
    \ i>=1; --i){\r\n      if(((l>>i)<<i) != l) push(l >> i);\r\n      if(((r>>i)<<i)\
    \ != r) push((r-1) >> i);\r\n    }\r\n\r\n    {\r\n      int l2 = l, r2 = r;\r\
    \n      while(l2 < r2){\r\n        if(l2&1) all_apply(l2++, x);\r\n        if(r2&1)\
    \ all_apply(--r2, x);\r\n        l2 >>= 1;\r\n        r2 >>= 1;\r\n      }\r\n\
    \    }\r\n\r\n    for(int i = 1; i <= height; ++i){\r\n      if(((l>>i)<<i) !=\
    \ l) propagate(l >> i);\r\n      if(((r>>i)<<i) != r) propagate((r-1) >> i);\r\
    \n    }\r\n  }\r\n\r\n  M at(int k){\r\n    k += n;\r\n    for(int i = height;\
    \ i>=1; --i) push(k >> i);\r\n    return node.at(k);\r\n  }\r\n\r\n  M operator[](int\
    \ k){\r\n    k += n;\r\n    for(int i = height; i>=1; --i) push(k >> i);\r\n \
    \   return node.at(k);\r\n  }\r\n\r\n  M query(int l, int r){\r\n    if(l == r)\
    \ return m;\r\n    l += n; r += n;\r\n\r\n    for(int i = height; i>=1; --i){\r\
    \n      if(((l>>i)<<i) != l) push(l >> i);\r\n      if(((r>>i)<<i) != r) push(r\
    \ >> i);\r\n    }\r\n\r\n    M sl = m, sr = m;\r\n    while(l < r){\r\n      if(l&1)\
    \ sl = f(sl, node.at(l++));\r\n      if(r&1) sr = f(node.at(--r), sr);\r\n   \
    \   l >>= 1;\r\n      r >>= 1;\r\n    }\r\n    return f(sl, sr);\r\n  }\r\n\r\n\
    \  M all_query() const { return node.at(1); }\r\n\r\n  template<typename C>\r\n\
    \  int max_right(int l, C &check){\r\n    if(l == defn) return defn;\r\n    l\
    \ += n;\r\n    for(int i = height; i>=1; --i) push(l >> i);\r\n    M sm = m;\r\
    \n    do{\r\n      while(l%2 == 0) l >>= 1;\r\n      if(!check(f(sm, node.at(l)))){\r\
    \n        while(l < n){\r\n          push(l);\r\n          l *= 2;\r\n       \
    \   if(check(f(sm, node.at(l)))){\r\n            sm = f(sm, node.at(l));\r\n \
    \           l++;\r\n          }\r\n        }\r\n        return l - n;\r\n    \
    \  }\r\n      sm = f(sm, node.at(l));\r\n      l++;\r\n    }while((l&-l) != l);\r\
    \n    return defn;\r\n  }\r\n\r\n  template<typename C>\r\n  int max_left(int\
    \ r, C &check){\r\n    if(r == 0) return 0;\r\n    r += n;\r\n    for(int i =\
    \ height; i>=1; --i) push((r-1) >> i);\r\n    M sm = m;\r\n    do{\r\n      while(r>1\
    \ && (r%2)) r >>= 1;\r\n      if(!check(f(node.at(r), sm))){\r\n        while(r\
    \ < n){\r\n          push(r);\r\n          r *= 2*r + 1;\r\n          if(check(f(node.at(r),\
    \ sm))){\r\n            sm = f(node.at(r), sm);\r\n            r--;\r\n      \
    \    }\r\n        }\r\n        return r + 1 - n;\r\n      }\r\n      sm = f(node.at(r),\
    \ sm);\r\n    }while((r&-r) != r);\r\n    return 0;\r\n  }\r\n\r\nprivate:\r\n\
    \  void propagate(int k){ node.at(k) = f(node.at(2*k), node.at(2*k + 1));}\r\n\
    \  void all_apply(int k, OM x){\r\n    node.at(k) = g(node.at(k), x, sz.at(k));\r\
    \n    if(k < n) lazy.at(k) = h(lazy.at(k), x);\r\n  }\r\n  void push(int k){\r\
    \n    if(lazy.at(k) == om) return;\r\n    all_apply(2*k, lazy.at(k));\r\n    all_apply(2*k\
    \ + 1, lazy.at(k));\r\n    lazy.at(k) = om;\r\n  }\r\n};\r\n\r\ntemplate<typename\
    \ M, typename OM, typename F, typename G, typename H>\r\nLazySegTree<M,OM,F,G,H>\
    \ get_lazysegtree(int n, const F &f, const G &g, const H &h, const M &m, const\
    \ OM &om){\r\n  return {n, f, g, h, m, om};\r\n}\r\n\r\ntemplate<typename M, typename\
    \ OM, typename F, typename G, typename H>\r\nLazySegTree<M,OM,F,G,H> get_lazysegtree(int\
    \ n, const F &f, const G &g, const H &h, const M &m, const OM &om, const vector<M>\
    \ &v){\r\n  LazySegTree<M,OM,F,G,H> seg(n, f, g, h, m, om);\r\n  seg.build(v);\r\
    \n  return seg;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: unuse/old_datastructure/old_lazy_segtree.cpp
  requiredBy: []
  timestamp: '2022-07-22 00:06:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unuse/old_datastructure/old_lazy_segtree.cpp
layout: document
redirect_from:
- /library/unuse/old_datastructure/old_lazy_segtree.cpp
- /library/unuse/old_datastructure/old_lazy_segtree.cpp.html
title: unuse/old_datastructure/old_lazy_segtree.cpp
---
