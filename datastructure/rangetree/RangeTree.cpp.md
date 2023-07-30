---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: datastructure/bbst/treap/Treap.cpp
    title: datastructure/bbst/treap/Treap.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/rangetree/RangeTree.cpp\"\n\r\n#line 2 \"\
    datastructure/bbst/treap/Treap.cpp\"\n\n\ntemplate<typename T, typename Compair\
    \ = less<T>>\nstruct Treap{\nprivate:\n  struct Node;\n\n  using Np = shared_ptr<Node>;\n\
    \  template<class... Args>\n  static Np make_np(Args&&... args){\n    return make_shared<Node>(forward<Args>(args)...);\n\
    \  }\n\n  struct Node{\n    T key;\n    size_t pri, cnt = 1;\n    Np l = {}, r\
    \ = {};\n\n    Node() = default;\n    Node(const T &key, size_t pri): key(key),\
    \ pri(pri) {}\n  };\n\n  Np root = {};\n\n  mt19937 mt;\n  const Compair cmp;\n\
    \n  size_t size(Np t) const { return !t ? 0 : t->cnt; }\n  \n  void update(Np\
    \ t){\n    if(!t) return;\n    t->cnt = size(t->l) + 1 + size(t->r);\n  }\n\n\
    \  void split(Np t, const T &key, Np &l, Np &r){\n    if(!t) l = r = nullptr;\n\
    \    else if(cmp(key, t->key)) split(t->l, key, l, t->l), r = t;\n    else split(t->r,\
    \ key, t->r, r), l = t;\n    update(l); update(r);\n  }\n\n  void merge(Np &t,\
    \ Np l, Np r){\n    if(!l || !r) t = l ? l : r;\n    else if(l->pri > r->pri)\
    \ merge(l->r, l->r, r), t = l;\n    else merge(r->l, l, r->l), t = r;\n    update(t);\n\
    \  }\n\n  void insert(Np &t, Np x){\n    if(!t) t = x;\n    else if(t->pri < x->pri)\
    \ split(t, x->key, x->l, x->r), t = x;\n    else insert(cmp(x->key, t->key) ?\
    \ t->l : t->r, x);\n    update(t);\n  }\n\n  bool erase(Np &t, const T &key){\n\
    \    if(!t) return false;\n    if(t->key == key){ merge(t, t->l, t->r); return\
    \ true; }\n    auto ret = erase(cmp(key, t->key) ? t->l : t->r, key);\n    update(t);\n\
    \    return ret;\n  }\n\n  Np find(Np &t, const T &key){\n    if(!t || t->key\
    \ == key) return t;\n    return find(cmp(key, t->key) ? t->l : t->r, key);\n \
    \ }\n\n  Np min(Np t) const {\n    return !t ? t : (!(t->l) ? t->key : min(t->l));\n\
    \  }\n  Np max(Np t) const {\n    return !t ? t : (!(t->r) ? t->key : max(t->r));\n\
    \  }\n\n  Np at(Np t, size_t k) const {\n    if(!t || size(t->l) == k) return\
    \ t;\n    if(size(t->l) > k) return at(t->l, k);\n    return at(t->r, k-size(t->l)-1);\n\
    \  }\n\n  size_t lower_bound(Np t, const T &key) const {\n    if(!t) return 0;\n\
    \    if(cmp(t->key, key)) return size(t->l) + 1 + lower_bound(t->r, key);\n  \
    \  return lower_bound(t->l, key);\n  }\n\n  size_t upper_bound(Np t, const T &key)\
    \ const {\n    if(!t) return 0;\n    if(!cmp(key, t->key)) return size(t->l) +\
    \ 1 + upper_bound(t->r, key);\n    return upper_bound(t->l, key);\n  }\n\n  void\
    \ enumerate(Np t, const T &l, const T &r, vector<T> &res) const {\n    if(!t)\
    \ return;\n    bool fl = !cmp(t->key, l), fr = cmp(t->key, r);\n    if(fl) enumerate(t->l,\
    \ l, r, res);\n    if(fl && fr) res.emplace_back(t->key);\n    if(fr) enumerate(t->r,\
    \ l, r, res);\n  }\n\n  template<typename F>\n  void enumerate(Np t, const T &l,\
    \ const T &r, const F &f) const {\n    if(!t) return;\n    bool fl = !cmp(t->key,\
    \ l), fr = cmp(t->key, r);\n    if(fl) enumerate(t->l, l, r, f);\n    if(fl &&\
    \ fr) f(t->key);\n    if(fr) enumerate(t->r, l, r, f);\n  }\n\npublic:\n  Treap(const\
    \ Compair &cmp = Compair()): mt(random_device{}()), cmp(cmp) {}\n\n  Treap(initializer_list<T>\
    \ il, const Compair &cmp = Compair())\n    : mt(random_device{}()), cmp(cmp) {\n\
    \    for_each(begin(il), end(il), [&](const T &e){ insert(e); });\n  }\n\n  void\
    \ insert(const T &key){ insert(root, make_np(key, mt())); }\n  bool erase(const\
    \ T &key){ return erase(root, key); }\n  bool exist(const T &key){ return !!find(root,\
    \ key); }\n\n  const T &min(){ return min(root)->key; }\n  const T &max(){ return\
    \ max(root)->key; }\n\n  const T &at(int k) const { return at(root, k>=0?size_t(k):size()+size_t(k))->key;\
    \ }\n  const T &operator[](int k) const { return at(k); }\n\n  T erase_at(int\
    \ k){ auto key=at(k); erase(root, key); return key; }\n\n  size_t size() const\
    \ { return size(root); }\n  bool empty() const { return !root; }\n  explicit operator\
    \ bool() const { return !empty(); }\n\n  size_t lower_bound(const T &key) const\
    \ { return lower_bound(root, key); }\n  size_t upper_bound(const T &key) const\
    \ { return upper_bound(root, key); }\n  size_t count(const T &key) const { return\
    \ upper_bound(key) - lower_bound(key); }\n\n  vector<T> enumerate(const T &l,\
    \ const T &r) const {\n    vector<T> res; enumerate(root, l, r, res); return res;\n\
    \  }\n\n  template<typename F>\n  void enumerate(const T &l, const T &r, const\
    \ F &f) const {\n    enumerate(root, l, r, f);\n  }\n\n  Np find(const T &key){\
    \ return find(root, key); }\n};\n#line 4 \"datastructure/rangetree/RangeTree.cpp\"\
    \n\r\ntemplate<typename Tx, typename Ty>\r\nstruct RangeTree{ // memory yabai\r\
    \n\r\n  struct Node{\r\n    Tx key;\r\n    Treap<pair<Ty, int>> ps;\r\n    bool\
    \ operator<(const Node &t) const { return key < t.key; }\r\n    bool operator==(const\
    \ Node &t) const { return key == t.key; }\r\n\r\n    Node() {}\r\n    Node(const\
    \ Tx &x): key(x), ps() { }\r\n    Node(const Tx &x, const Ty &y, int idx): key(x),\
    \ ps() {\r\n      ps.insert({y, idx});\r\n    }\r\n  };\r\n\r\n  Treap<Node> tree;\r\
    \n  RangeTree() {}\r\n\r\n  void add(const Tx &x, const Ty &y, int idx = -1){\r\
    \n    auto t = tree.find(Node(x));\r\n    if(!t) tree.insert(Node(x, y, idx));\r\
    \n    else t->key.ps.insert({y, idx});\r\n  }\r\n\r\n  vector<tuple<Tx, Ty, int>>\
    \ search(const Tx &l, const Tx &r, const Ty &d, const Ty u){\r\n    vector<tuple<Tx,\
    \ Ty, int>> res;\r\n    auto f = [&](const Node &t){\r\n      auto ps = t.ps.enumerate({d,\
    \ -1}, {u, -1});\r\n      for(auto&[y,idx] : ps) res.emplace_back(t.key, y, idx);\r\
    \n    };\r\n    tree.enumerate({l}, {r}, f);\r\n    return res;\r\n  };\r\n};\r\
    \n"
  code: "#pragma once\r\n\r\n#include \"../bbst/treap/Treap.cpp\"\r\n\r\ntemplate<typename\
    \ Tx, typename Ty>\r\nstruct RangeTree{ // memory yabai\r\n\r\n  struct Node{\r\
    \n    Tx key;\r\n    Treap<pair<Ty, int>> ps;\r\n    bool operator<(const Node\
    \ &t) const { return key < t.key; }\r\n    bool operator==(const Node &t) const\
    \ { return key == t.key; }\r\n\r\n    Node() {}\r\n    Node(const Tx &x): key(x),\
    \ ps() { }\r\n    Node(const Tx &x, const Ty &y, int idx): key(x), ps() {\r\n\
    \      ps.insert({y, idx});\r\n    }\r\n  };\r\n\r\n  Treap<Node> tree;\r\n  RangeTree()\
    \ {}\r\n\r\n  void add(const Tx &x, const Ty &y, int idx = -1){\r\n    auto t\
    \ = tree.find(Node(x));\r\n    if(!t) tree.insert(Node(x, y, idx));\r\n    else\
    \ t->key.ps.insert({y, idx});\r\n  }\r\n\r\n  vector<tuple<Tx, Ty, int>> search(const\
    \ Tx &l, const Tx &r, const Ty &d, const Ty u){\r\n    vector<tuple<Tx, Ty, int>>\
    \ res;\r\n    auto f = [&](const Node &t){\r\n      auto ps = t.ps.enumerate({d,\
    \ -1}, {u, -1});\r\n      for(auto&[y,idx] : ps) res.emplace_back(t.key, y, idx);\r\
    \n    };\r\n    tree.enumerate({l}, {r}, f);\r\n    return res;\r\n  };\r\n};\r\
    \n"
  dependsOn:
  - datastructure/bbst/treap/Treap.cpp
  isVerificationFile: false
  path: datastructure/rangetree/RangeTree.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/rangetree/RangeTree.cpp
layout: document
redirect_from:
- /library/datastructure/rangetree/RangeTree.cpp
- /library/datastructure/rangetree/RangeTree.cpp.html
title: datastructure/rangetree/RangeTree.cpp
---
