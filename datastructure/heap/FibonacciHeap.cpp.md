---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/shortestpath/dijkstra_fibonacci.cpp
    title: graph/shortestpath/dijkstra_fibonacci.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/heap/FibonacciHeap.cpp\"\n\r\ntemplate<typename\
    \ key_t, typename val_t, class Compair = less<key_t>>\r\nstruct FibonacciHeap{\r\
    \n  struct Node;\r\n  using Np = Node *;\r\n  \r\n  struct Node{\r\n    key_t\
    \ key;\r\n    val_t val;\r\n    Node() = default;\r\n    Node(const key_t &key,\
    \ const val_t &val): key(key), val(val) {}\r\n\r\n    Np p = nullptr, child =\
    \ nullptr, left = this, right = this;\r\n\r\n    size_t degree = 0;  \r\n    bool\
    \ mark = false;\r\n  };\r\nprivate:\r\n\r\n  Np root;\r\n  size_t sz;\r\n  Compair\
    \ cmp;\r\n\r\n  void insert(Np &p1, Np &p2){\r\n    Np rr = p1->right;\r\n   \
    \ p1->right = p2; p2->left = p1;\r\n    p2->right = rr; rr->left = p2;\r\n  }\r\
    \n\r\n  void merge(Np &p1, Np &p2){\r\n    Np r1 = p1->right, r2 = p2->left;\r\
    \n    p1->right = p2; p2->left = p1;\r\n    r2->right = r1; r1->left = r2;\r\n\
    \  }\r\n\r\n  vector<Np> get_Np_list(Np r){\r\n    assert(!!r);\r\n    vector<Np>\
    \ nps;\r\n    Np w = r;\r\n    do{\r\n      nps.push_back(w);\r\n      w = w->right;\r\
    \n    }while(w != r);\r\n    return nps;\r\n  }\r\n\r\n  void consolidate(){\r\
    \n    vector<Np> a, nps = get_Np_list(root);\r\n\r\n    for(Np w : nps){\r\n \
    \     Np x = w;\r\n      size_t d = x->degree;\r\n      \r\n      while(d < a.size()\
    \ && !!a[d]){\r\n        Np y = a[d];\r\n        if(cmp(y->key, x->key)) swap(x,\
    \ y);\r\n        heap_link(y, x);\r\n        a[d] = nullptr;\r\n        ++d;\r\
    \n      }\r\n\r\n      if(a.size() <= d) a.resize(d + 1, nullptr);\r\n      a[d]\
    \ = x;\r\n    }\r\n    root = nullptr;\r\n    for(Np x : a){\r\n      if(!x) continue;\r\
    \n      if(!root){\r\n        x->left = x->right = x;\r\n        root = x;\r\n\
    \      }else{\r\n        insert(root, x);\r\n        if(cmp(x->key, root->key))\
    \ root = x;\r\n      }\r\n    }\r\n    assert(!!root);\r\n  }\r\n\r\n  void heap_link(Np\
    \ &y, Np &x){\r\n    if(y->right != y) delete_node(y);\r\n    if(!x->child) x->child\
    \ = y;\r\n    else insert(x->child, y);\r\n    y->p = x;\r\n    x->degree += 1;\r\
    \n    y->mark = false;\r\n  }\r\n\r\n  void cascading_cut(Np &y){\r\n    Np z\
    \ = y->p;\r\n    if(!!z){\r\n      if(!y->mark) y->mark = true;\r\n      else{\r\
    \n        cut(y, z);\r\n        cascading_cut(z);\r\n      }\r\n    }\r\n  }\r\
    \n\r\n  void erase(Np &x, const key_t &linf){\r\n    decrease(x, linf);\r\n  \
    \  pop();\r\n  }\r\n\r\n  void delete_node(Np &x){\r\n    Np l = x->left, r =\
    \ x->right;\r\n    l->right = r; r->left = l;\r\n    x->left = x->right = x;\r\
    \n  }\r\n\r\n  void cut(Np &x, Np &y){\r\n    if(x->right == x){\r\n      y->child\
    \ = nullptr;\r\n    }else{\r\n      y->child = x->right;\r\n      delete_node(x);\r\
    \n    }\r\n    y->degree -= 1;\r\n    insert(root, x);\r\n    x->p = nullptr;\r\
    \n    x->mark = false;\r\n  }\r\n\r\npublic:\r\n  FibonacciHeap(const Compair\
    \ &cmp = Compair{}): root(nullptr), sz(0), cmp(cmp) {}\r\n  FibonacciHeap(const\
    \ FibonacciHeap&) = default;\r\n  FibonacciHeap(FibonacciHeap&&) = default;\r\n\
    \r\n  FibonacciHeap &operator=(const FibonacciHeap&) = default;\r\n  FibonacciHeap\
    \ &operator=(FibonacciHeap&&) = default;\r\n\r\n  size_t size() const { return\
    \ sz; }\r\n  bool empty() const { return !sz; }\r\n\r\n  pair<key_t, val_t> top()\
    \ const {\r\n    assert(!!root);\r\n    return {root->key, root->val};\r\n  }\r\
    \n\r\n  Np push(const key_t &key, const val_t &val){\r\n    Np x = new Node(key,\
    \ val);\r\n\r\n    if(!root){\r\n      root = x;\r\n    }else{\r\n      insert(root,\
    \ x);\r\n      if(cmp(key, root->key)) root = x;\r\n    }\r\n\r\n    ++sz;\r\n\
    \    return x;\r\n  }\r\n\r\n  void merge(FibonacciHeap &h2){\r\n    if(!h2.root)\
    \ return;\r\n    sz += h2.sz;\r\n\r\n    if(!root){\r\n      root = h2.root;\r\
    \n      return;\r\n    }\r\n    merge(root, h2.root);\r\n    if(cmp(h2.root->key,\
    \ root->key)) root = h2.root;\r\n  }\r\n\r\n  pair<key_t, val_t> pop(){\r\n  \
    \  assert((\"can't pop\" ,!!root));\r\n    pair<key_t, val_t> res = {root->key,\
    \ root->val};\r\n\r\n    Np c = root->child;\r\n\r\n    if(!!c){\r\n      vector<Np>\
    \ nps = get_Np_list(c);\r\n      for(Np x : nps){\r\n        insert(root, x);\r\
    \n        x->p = nullptr;\r\n      }\r\n    }\r\n\r\n    if(root->right == root){\r\
    \n      delete root;\r\n      root = nullptr;\r\n    }else{\r\n      Np z = root;\r\
    \n      root = root->right;\r\n      delete_node(z);\r\n      delete z;\r\n  \
    \    consolidate();\r\n    }\r\n    --sz;\r\n\r\n    return res;\r\n  }\r\n\r\n\
    \  void decrease(Np &x, const key_t &key){\r\n    assert(!!x);\r\n    assert(!cmp(x->key,\
    \ key));\r\n    x->key = key;\r\n    Np y = x->p;\r\n    if(!!y && cmp(x->key,\
    \ y->key)){\r\n      cut(x, y);\r\n      cascading_cut(y);\r\n    }\r\n    if(cmp(x->key,\
    \ root->key)) root = x;\r\n  }\r\n\r\n  static Np get_np() { return nullptr; }\r\
    \n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename key_t, typename val_t, class Compair\
    \ = less<key_t>>\r\nstruct FibonacciHeap{\r\n  struct Node;\r\n  using Np = Node\
    \ *;\r\n  \r\n  struct Node{\r\n    key_t key;\r\n    val_t val;\r\n    Node()\
    \ = default;\r\n    Node(const key_t &key, const val_t &val): key(key), val(val)\
    \ {}\r\n\r\n    Np p = nullptr, child = nullptr, left = this, right = this;\r\n\
    \r\n    size_t degree = 0;  \r\n    bool mark = false;\r\n  };\r\nprivate:\r\n\
    \r\n  Np root;\r\n  size_t sz;\r\n  Compair cmp;\r\n\r\n  void insert(Np &p1,\
    \ Np &p2){\r\n    Np rr = p1->right;\r\n    p1->right = p2; p2->left = p1;\r\n\
    \    p2->right = rr; rr->left = p2;\r\n  }\r\n\r\n  void merge(Np &p1, Np &p2){\r\
    \n    Np r1 = p1->right, r2 = p2->left;\r\n    p1->right = p2; p2->left = p1;\r\
    \n    r2->right = r1; r1->left = r2;\r\n  }\r\n\r\n  vector<Np> get_Np_list(Np\
    \ r){\r\n    assert(!!r);\r\n    vector<Np> nps;\r\n    Np w = r;\r\n    do{\r\
    \n      nps.push_back(w);\r\n      w = w->right;\r\n    }while(w != r);\r\n  \
    \  return nps;\r\n  }\r\n\r\n  void consolidate(){\r\n    vector<Np> a, nps =\
    \ get_Np_list(root);\r\n\r\n    for(Np w : nps){\r\n      Np x = w;\r\n      size_t\
    \ d = x->degree;\r\n      \r\n      while(d < a.size() && !!a[d]){\r\n       \
    \ Np y = a[d];\r\n        if(cmp(y->key, x->key)) swap(x, y);\r\n        heap_link(y,\
    \ x);\r\n        a[d] = nullptr;\r\n        ++d;\r\n      }\r\n\r\n      if(a.size()\
    \ <= d) a.resize(d + 1, nullptr);\r\n      a[d] = x;\r\n    }\r\n    root = nullptr;\r\
    \n    for(Np x : a){\r\n      if(!x) continue;\r\n      if(!root){\r\n       \
    \ x->left = x->right = x;\r\n        root = x;\r\n      }else{\r\n        insert(root,\
    \ x);\r\n        if(cmp(x->key, root->key)) root = x;\r\n      }\r\n    }\r\n\
    \    assert(!!root);\r\n  }\r\n\r\n  void heap_link(Np &y, Np &x){\r\n    if(y->right\
    \ != y) delete_node(y);\r\n    if(!x->child) x->child = y;\r\n    else insert(x->child,\
    \ y);\r\n    y->p = x;\r\n    x->degree += 1;\r\n    y->mark = false;\r\n  }\r\
    \n\r\n  void cascading_cut(Np &y){\r\n    Np z = y->p;\r\n    if(!!z){\r\n   \
    \   if(!y->mark) y->mark = true;\r\n      else{\r\n        cut(y, z);\r\n    \
    \    cascading_cut(z);\r\n      }\r\n    }\r\n  }\r\n\r\n  void erase(Np &x, const\
    \ key_t &linf){\r\n    decrease(x, linf);\r\n    pop();\r\n  }\r\n\r\n  void delete_node(Np\
    \ &x){\r\n    Np l = x->left, r = x->right;\r\n    l->right = r; r->left = l;\r\
    \n    x->left = x->right = x;\r\n  }\r\n\r\n  void cut(Np &x, Np &y){\r\n    if(x->right\
    \ == x){\r\n      y->child = nullptr;\r\n    }else{\r\n      y->child = x->right;\r\
    \n      delete_node(x);\r\n    }\r\n    y->degree -= 1;\r\n    insert(root, x);\r\
    \n    x->p = nullptr;\r\n    x->mark = false;\r\n  }\r\n\r\npublic:\r\n  FibonacciHeap(const\
    \ Compair &cmp = Compair{}): root(nullptr), sz(0), cmp(cmp) {}\r\n  FibonacciHeap(const\
    \ FibonacciHeap&) = default;\r\n  FibonacciHeap(FibonacciHeap&&) = default;\r\n\
    \r\n  FibonacciHeap &operator=(const FibonacciHeap&) = default;\r\n  FibonacciHeap\
    \ &operator=(FibonacciHeap&&) = default;\r\n\r\n  size_t size() const { return\
    \ sz; }\r\n  bool empty() const { return !sz; }\r\n\r\n  pair<key_t, val_t> top()\
    \ const {\r\n    assert(!!root);\r\n    return {root->key, root->val};\r\n  }\r\
    \n\r\n  Np push(const key_t &key, const val_t &val){\r\n    Np x = new Node(key,\
    \ val);\r\n\r\n    if(!root){\r\n      root = x;\r\n    }else{\r\n      insert(root,\
    \ x);\r\n      if(cmp(key, root->key)) root = x;\r\n    }\r\n\r\n    ++sz;\r\n\
    \    return x;\r\n  }\r\n\r\n  void merge(FibonacciHeap &h2){\r\n    if(!h2.root)\
    \ return;\r\n    sz += h2.sz;\r\n\r\n    if(!root){\r\n      root = h2.root;\r\
    \n      return;\r\n    }\r\n    merge(root, h2.root);\r\n    if(cmp(h2.root->key,\
    \ root->key)) root = h2.root;\r\n  }\r\n\r\n  pair<key_t, val_t> pop(){\r\n  \
    \  assert((\"can't pop\" ,!!root));\r\n    pair<key_t, val_t> res = {root->key,\
    \ root->val};\r\n\r\n    Np c = root->child;\r\n\r\n    if(!!c){\r\n      vector<Np>\
    \ nps = get_Np_list(c);\r\n      for(Np x : nps){\r\n        insert(root, x);\r\
    \n        x->p = nullptr;\r\n      }\r\n    }\r\n\r\n    if(root->right == root){\r\
    \n      delete root;\r\n      root = nullptr;\r\n    }else{\r\n      Np z = root;\r\
    \n      root = root->right;\r\n      delete_node(z);\r\n      delete z;\r\n  \
    \    consolidate();\r\n    }\r\n    --sz;\r\n\r\n    return res;\r\n  }\r\n\r\n\
    \  void decrease(Np &x, const key_t &key){\r\n    assert(!!x);\r\n    assert(!cmp(x->key,\
    \ key));\r\n    x->key = key;\r\n    Np y = x->p;\r\n    if(!!y && cmp(x->key,\
    \ y->key)){\r\n      cut(x, y);\r\n      cascading_cut(y);\r\n    }\r\n    if(cmp(x->key,\
    \ root->key)) root = x;\r\n  }\r\n\r\n  static Np get_np() { return nullptr; }\r\
    \n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/heap/FibonacciHeap.cpp
  requiredBy:
  - graph/shortestpath/dijkstra_fibonacci.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/heap/FibonacciHeap.cpp
layout: document
redirect_from:
- /library/datastructure/heap/FibonacciHeap.cpp
- /library/datastructure/heap/FibonacciHeap.cpp.html
title: datastructure/heap/FibonacciHeap.cpp
---
