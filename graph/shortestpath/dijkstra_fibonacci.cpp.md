---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: datastructure/heap/FibonacciHeap.cpp
    title: datastructure/heap/FibonacciHeap.cpp
  - icon: ':warning:'
    path: graph/Graph.cpp
    title: graph/Graph.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/shortestpath/dijkstra_fibonacci.cpp\"\n\r\n#line 2\
    \ \"graph/Graph.cpp\"\n\r\ntemplate<typename T = int>\r\nstruct Edge{\r\n  int\
    \ src, to; T cost; int idx;\r\n  Edge() = default;\r\n  Edge(int src, int to,\
    \ T cost = -1, int idx = -1): src(src), to(to), cost(cost), idx(idx) {}\r\n  operator\
    \ int() const { return to; }\r\n};\r\ntemplate<typename T> using Edges = vector<Edge<T>>;\r\
    \n\r\ntemplate<typename T = int>\r\nstruct Graph : vector<vector<Edge<T>>> {\r\
    \n  using base_t = vector<vector<Edge<T>>>;\r\n  using base_t::base_t;\r\n  size_t\
    \ es;\r\n  Graph(size_t n): base_t(n), es(0) {}\r\n\r\n  int deg(int v) const\
    \ { return int(base_t::operator[](v).size()); }\r\n\r\n  void add_edge(int src,\
    \ int to, T cost = 1){\r\n    base_t::operator[](src).emplace_back(src, to, cost,\
    \ es);\r\n    base_t::operator[](to).emplace_back(to, src, cost, es++);\r\n  }\r\
    \n  void add_directed_edge(int src, int to, T cost = 1){\r\n    base_t::operator[](src).emplace_back(src,\
    \ to, cost, es++);\r\n  }\r\n\r\n  void read(int m, int base = 1, bool weighted\
    \ = false, bool directed = false, const T &id = 1){\r\n    for (int i = 0; i <\
    \ m; i++){\r\n      int u, v; cin >> u >> v; u -= base; v -= base;\r\n      T\
    \ c = id;\r\n      if(weighted) cin >> c;\r\n      if(directed) add_directed_edge(u,\
    \ v, c);\r\n      else add_edge(u, v, c);\r\n    }\r\n  }\r\n  \r\n  vector<int>\
    \ topological_order() const {\r\n    int n = int(this->size());\r\n    vector<int>\
    \ vs, ind(n); vs.reserve(n);\r\n    for(const auto&edges : (*this)){\r\n     \
    \ for(const auto&edge : edges) ++ind[edge.to];\r\n    }\r\n    queue<int> qu;\r\
    \n    for(int v = 0; v < n; ++v){\r\n      if(ind[v] == 0) qu.push(v);\r\n   \
    \ }\r\n    while(!qu.empty()){\r\n      int v = qu.front(); qu.pop();\r\n    \
    \  vs.push_back(v);\r\n      for(const auto &e :  base_t::operator[](v)){\r\n\
    \        if(--ind[e.to] == 0) qu.push(e.to);\r\n      }\r\n    }\r\n    return\
    \ vs;\r\n  }\r\n\r\n  Graph<T> get_directed_tree(int root = 0) const {\r\n   \
    \ Graph<T> tree(this->size());\r\n    queue<pair<int, int>> qu;\r\n    for(qu.emplace(root,\
    \ -1); !qu.empty(); qu.pop()){\r\n      auto[v, p] = qu.front();\r\n      for(const\
    \ auto &e : base_t::operator[](v)){\r\n        if(e.to == p) continue;\r\n   \
    \     tree.add_directed_edge(v, e.to, e.cost);\r\n        qu.emplace(e.to, v);\r\
    \n      }\r\n    }\r\n    return tree;\r\n  }\r\n\r\n  vector<T> bfs_dist(int\
    \ root) const {\r\n    vector<T> dist(this->size());\r\n    queue<pair<int, int>>\
    \ qu;\r\n    for(qu.emplace(root, -1); !qu.empty(); qu.pop()){\r\n      auto[v,\
    \ p] = qu.front();\r\n      for(const auto &e : base_t::operator[](v)){\r\n  \
    \      if(e.to == p) continue;\r\n        dist[e.to] = dist[v] + e.cost;\r\n \
    \       qu.emplace(e.to, v);\r\n      }\r\n    }\r\n    return dist;\r\n  }\r\n\
    };\r\n#line 4 \"graph/shortestpath/dijkstra_fibonacci.cpp\"\n\r\n#line 2 \"datastructure/heap/FibonacciHeap.cpp\"\
    \n\r\ntemplate<typename key_t, typename val_t, class Compair = less<key_t>>\r\n\
    struct FibonacciHeap{\r\n  struct Node;\r\n  using Np = Node *;\r\n  \r\n  struct\
    \ Node{\r\n    key_t key;\r\n    val_t val;\r\n    Node() = default;\r\n    Node(const\
    \ key_t &key, const val_t &val): key(key), val(val) {}\r\n\r\n    Np p = nullptr,\
    \ child = nullptr, left = this, right = this;\r\n\r\n    size_t degree = 0;  \r\
    \n    bool mark = false;\r\n  };\r\nprivate:\r\n\r\n  Np root;\r\n  size_t sz;\r\
    \n  Compair cmp;\r\n\r\n  void insert(Np &p1, Np &p2){\r\n    Np rr = p1->right;\r\
    \n    p1->right = p2; p2->left = p1;\r\n    p2->right = rr; rr->left = p2;\r\n\
    \  }\r\n\r\n  void merge(Np &p1, Np &p2){\r\n    Np r1 = p1->right, r2 = p2->left;\r\
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
    \n};\r\n#line 6 \"graph/shortestpath/dijkstra_fibonacci.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nvector<T> dijkstra_fibonacci(const Graph<T> &g, int s){\r\n  FibonacciHeap<T,\
    \ int> heap;\r\n  vector nodes(g.size(), heap.get_np());\r\n  vector<T> dist(g.size(),\
    \ numeric_limits<T>::max());\r\n  nodes[s] = heap.push(0, s); dist[s] = 0;\r\n\
    \r\n  while(!heap.empty()){\r\n    auto[d, v] = heap.pop();\r\n\r\n    for(auto&&e\
    \ : g[v]){\r\n      int u = e.to;\r\n      T nd = d + e.cost;\r\n      if(dist[u]\
    \ <= nd) continue;\r\n      dist[u] = nd;\r\n      if(!nodes[u]){\r\n        nodes[u]\
    \ = heap.push(nd, u);\r\n      }else{\r\n        heap.decrease(nodes[u], nd);\r\
    \n      }\r\n    }\r\n  }\r\n  return dist;\r\n}\r\n"
  code: "#pragma once\r\n\r\n#include \"../Graph.cpp\"\r\n\r\n#include \"../../datastructure/heap/FibonacciHeap.cpp\"\
    \r\n\r\ntemplate<typename T>\r\nvector<T> dijkstra_fibonacci(const Graph<T> &g,\
    \ int s){\r\n  FibonacciHeap<T, int> heap;\r\n  vector nodes(g.size(), heap.get_np());\r\
    \n  vector<T> dist(g.size(), numeric_limits<T>::max());\r\n  nodes[s] = heap.push(0,\
    \ s); dist[s] = 0;\r\n\r\n  while(!heap.empty()){\r\n    auto[d, v] = heap.pop();\r\
    \n\r\n    for(auto&&e : g[v]){\r\n      int u = e.to;\r\n      T nd = d + e.cost;\r\
    \n      if(dist[u] <= nd) continue;\r\n      dist[u] = nd;\r\n      if(!nodes[u]){\r\
    \n        nodes[u] = heap.push(nd, u);\r\n      }else{\r\n        heap.decrease(nodes[u],\
    \ nd);\r\n      }\r\n    }\r\n  }\r\n  return dist;\r\n}\r\n"
  dependsOn:
  - graph/Graph.cpp
  - datastructure/heap/FibonacciHeap.cpp
  isVerificationFile: false
  path: graph/shortestpath/dijkstra_fibonacci.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/shortestpath/dijkstra_fibonacci.cpp
layout: document
redirect_from:
- /library/graph/shortestpath/dijkstra_fibonacci.cpp
- /library/graph/shortestpath/dijkstra_fibonacci.cpp.html
title: graph/shortestpath/dijkstra_fibonacci.cpp
---
