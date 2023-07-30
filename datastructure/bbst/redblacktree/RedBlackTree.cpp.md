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
  bundledCode: "#line 2 \"datastructure/bbst/redblacktree/RedBlackTree.cpp\"\n\r\n\
    \r\ntemplate<typename T, class Compair = less<T>>\r\nstruct RedBlackTree{\r\n\
    private:\r\n  enum Color{RED, BLACK, NIL};\r\n\r\n  struct Node{\r\n    T key;\r\
    \n    Color color;\r\n    size_t sz = 0;\r\n    Node *parentP = nullptr, *leftP\
    \ = nullptr, *rightP = nullptr, *nextP = nullptr, *prevP = nullptr;\r\n\r\n  \
    \  constexpr Node(): key{}, color(NIL) {}\r\n    constexpr Node(const T &key,\
    \ Color color): key(key), color(color), sz(1) {}\r\n\r\n    constexpr bool is_valid()\
    \ const { return color != NIL; }\r\n    constexpr bool is_nil() const { return\
    \ color == NIL; }\r\n    constexpr bool is_red() const { return color == RED;\
    \ }\r\n    constexpr bool is_black() const { return color != RED; }\r\n    constexpr\
    \ bool is_left() const { return parentP->leftP == this; }\r\n    constexpr bool\
    \ is_right() const { return parentP->rightP == this; }\r\n    constexpr bool is_root()\
    \ const { return parentP->is_nil(); }\r\n\r\n    constexpr void flip_color(){\r\
    \n      assert(is_valid());\r\n      if(is_red()) color = BLACK;\r\n      else\
    \ color = RED;\r\n    }\r\n\r\n    constexpr Node *successor() const { return\
    \ nextP; }\r\n    constexpr Node *predecessor() const { return prevP; }\r\n  };\r\
    \n  using Np = Node*;\r\n\r\n  Np nil = new Node{};\r\n\r\n  Np root = nil;\r\n\
    \  const Compair cmp;\r\n\r\n  void rotate_left(Np t){\r\n    Np y = t->rightP;\r\
    \n    assert(y->is_valid());\r\n\r\n    t->rightP = y->leftP;\r\n    if(y->leftP->is_valid())\
    \ y->leftP->parentP = t;\r\n    y->parentP = t->parentP;\r\n\r\n    if(t->is_root())\
    \ root = y;\r\n    else if(t->is_left()) t->parentP->leftP = y;\r\n    else t->parentP->rightP\
    \ = y;\r\n\r\n    y->leftP = t; t->parentP = y;\r\n    y->sz = t->sz;\r\n    t->sz\
    \ = t->leftP->sz + t->rightP->sz + 1;\r\n  }\r\n\r\n  void rotate_right(Np t){\r\
    \n    Np y = t->leftP;\r\n    assert(y->is_valid());\r\n\r\n    t->leftP = y->rightP;\r\
    \n    if(y->rightP->is_valid()) y->rightP->parentP = t;\r\n    y->parentP = t->parentP;\r\
    \n\r\n    if(t->is_root()) root = y;\r\n    else if(t->is_left()) t->parentP->leftP\
    \ = y;\r\n    else t->parentP->rightP = y;\r\n\r\n    y->rightP = t; t->parentP\
    \ = y;\r\n    y->sz = t->sz;\r\n    t->sz = t->leftP->sz + t->rightP->sz + 1;\r\
    \n  }\r\n\r\n  void insert_fixup(Np t){\r\n    assert(!!t->parentP);\r\n    while(t->parentP->is_red()){\r\
    \n      if(t->parentP->is_left()){\r\n        Np y = t->parentP->parentP->rightP;\r\
    \n        if(y->is_red()){\r\n          t->parentP->flip_color();\r\n        \
    \  y->flip_color();\r\n          t->parentP->parentP->flip_color();\r\n      \
    \    t = t->parentP->parentP;\r\n        }else{\r\n          if(t->is_right()){\
    \ t = t->parentP; rotate_left(t); }\r\n          t->parentP->flip_color();\r\n\
    \          t->parentP->parentP->flip_color();\r\n          rotate_right(t->parentP->parentP);\r\
    \n        }\r\n      }else{\r\n        Np y = t->parentP->parentP->leftP;\r\n\
    \        if(y->is_red()){\r\n          t->parentP->flip_color();\r\n         \
    \ y->flip_color();\r\n          t->parentP->parentP->flip_color();\r\n       \
    \   t = t->parentP->parentP;\r\n        }else{\r\n          if(t->is_left()){\
    \ t = t->parentP; rotate_right(t); }\r\n          t->parentP->flip_color();\r\n\
    \          t->parentP->parentP->flip_color();\r\n          rotate_left(t->parentP->parentP);\r\
    \n        }\r\n      }\r\n    }\r\n    if(root->is_red()) root->flip_color();\r\
    \n  }\r\n\r\n  void erase_impl(Np t){\r\n    Np x = nil, y = t;\r\n    Color color\
    \ = y->color;\r\n    if(t->leftP->is_nil()){\r\n      x = t->rightP;\r\n     \
    \ transplant(t, t->rightP);\r\n    }else if(t->rightP->is_nil()){\r\n      x =\
    \ t->leftP;\r\n      transplant(t, t->leftP);\r\n    }else{\r\n      y = y->nextP;\r\
    \n      assert(y->is_valid());\r\n      Np m = y->parentP;\r\n      while(m !=\
    \ t){ m->sz -= 1; m = m->parentP; }\r\n      color = y->color; x = y->rightP;\r\
    \n      if(y->parentP == t) x->parentP = y;\r\n      else{\r\n        transplant(y,\
    \ y->rightP);\r\n        y->rightP = t->rightP;\r\n        y->rightP->parentP\
    \ = y;\r\n      }\r\n      transplant(t, y);\r\n      y->leftP = t->leftP;\r\n\
    \      y->leftP->parentP = y;\r\n      y->color = t->color;\r\n      y->sz = t->sz;\r\
    \n    }\r\n\r\n    if(color == BLACK) erase_fixup(x);\r\n    t->nextP->prevP =\
    \ t->prevP;\r\n    t->prevP->nextP = t->nextP;\r\n    delete t;\r\n  }\r\n\r\n\
    \  void erase_fixup(Np t){\r\n    while(!t->is_root() && t->is_black()){\r\n \
    \     if(t->is_left()){\r\n        Np y = t->parentP->rightP;\r\n        if(y->is_red()){\r\
    \n          y->flip_color(); t->parentP->flip_color();\r\n          rotate_left(t->parentP);\r\
    \n          y = t->parentP->rightP;\r\n        }\r\n        if(y->leftP->is_black()\
    \ && y->rightP->is_black()){\r\n          y->flip_color(); t = t->parentP;\r\n\
    \        }else{\r\n          if(y->rightP->is_black()){\r\n            y->leftP->flip_color();\r\
    \n            y->flip_color();\r\n            rotate_right(y);\r\n           \
    \ y = t->parentP->rightP;\r\n          }\r\n          y->color = t->parentP->color;\r\
    \n          t->parentP->color = BLACK;\r\n          y->rightP->color = BLACK;\r\
    \n          rotate_left(t->parentP);\r\n          t = root;\r\n        }\r\n \
    \     }else{\r\n        Np y = t->parentP->leftP;\r\n        if(y->is_red()){\r\
    \n          y->flip_color(); t->parentP->flip_color();\r\n          rotate_right(t->parentP);\r\
    \n          y = t->parentP->leftP;\r\n        }\r\n        if(y->leftP->is_black()\
    \ && y->rightP->is_black()){\r\n          y->flip_color(); t = t->parentP;\r\n\
    \        }else{\r\n          if(y->leftP->is_black()){\r\n            y->rightP->flip_color();\r\
    \n            y->flip_color();\r\n            rotate_left(y);\r\n            y\
    \ = t->parentP->leftP;\r\n          }\r\n          y->color = t->parentP->color;\r\
    \n          t->parentP->color = BLACK;\r\n          y->leftP->color = BLACK;\r\
    \n          rotate_right(t->parentP);\r\n          t = root;\r\n        }\r\n\
    \      }\r\n    }\r\n    if(t->is_red()) t->flip_color();\r\n  }\r\n\r\n  void\
    \ transplant(Np u, Np v){\r\n    if(u->is_root()) root = v;\r\n    else if(u->is_left())\
    \ u->parentP->leftP = v;\r\n    else u->parentP->rightP = v;\r\n    v->parentP\
    \ = u->parentP;\r\n  }\r\n\r\n  Np minimum(Np t) const {\r\n    while(t->leftP->is_valid())\
    \ t = t->leftP;\r\n    return t;\r\n  }\r\n\r\n  Np maximum(Np t) const {\r\n\
    \    while(t->rightP->is_valid()) t = t->rightP;\r\n    return t;\r\n  }\r\n\r\
    \n  Np minimum() const { return nil->nextP; }\r\n  Np maximum() const { return\
    \ nil->prevP; }\r\n\r\n\r\n  Np lower_bound(Np t, const T &key) const {\r\n  \
    \  if(t->is_nil()) return t;\r\n    if(cmp(t->key, key)) return lower_bound(t->rightP,\
    \ key);\r\n    Np l = lower_bound(t->leftP, key);\r\n    if(l->is_nil()) return\
    \ t;\r\n    return l;\r\n  }\r\n\r\n  Np upper_bound(Np t, const T &key) const\
    \ {\r\n    if(t->is_nil()) return t;\r\n    if(!cmp(key, t->key)) return upper_bound(t->rightP,\
    \ key);\r\n    Np l = upper_bound(t->leftP, key);\r\n    if(l->is_nil()) return\
    \ t;\r\n    return l;\r\n  }\r\n\r\n  Np select(Np t, size_t k) const {\r\n  \
    \  assert(!!t);\r\n    size_t r = t->leftP->sz;\r\n    if(k == r) return t;\r\n\
    \    else if(k < r) return select(t->leftP, k);\r\n    else return select(t->rightP,\
    \ k - r - 1);\r\n  }\r\n\r\n  void dump(Np t) const {\r\n    if(t->is_nil()) return;\r\
    \n    dump(t->leftP);\r\n    cout << t->key << \" \";\r\n    dump(t->rightP);\r\
    \n  }\r\n\r\n  size_t rank(Np t) const {\r\n    if(t->is_nil()) return size();\r\
    \n    size_t r = t->leftP->sz;\r\n    Np y = t;\r\n    while(!y->is_root()){\r\
    \n      if(y->is_right()) r += y->parentP->leftP->sz + 1;\r\n      y = y->parentP;\r\
    \n    }\r\n    return r;\r\n  }\r\n\r\n  Np find(const T &key) const {\r\n   \
    \ Np t = root;\r\n    while(t->is_valid() && t->key != key){\r\n      if(cmp(key,\
    \ t->key)) t = t->leftP;\r\n      else t = t->rightP;\r\n    }\r\n    return t;\r\
    \n  }\r\n\r\npublic:\r\n\r\n  RedBlackTree(const Compair &cmp = Compair{}): cmp(cmp)\
    \ {\r\n    root->nextP = root->prevP = nil;\r\n  }\r\n  RedBlackTree(initializer_list<T>\
    \ v ,const Compair &cmp = Compair{}): cmp(cmp) {\r\n    root->nextP = root->prevP\
    \ = nil;\r\n    for(auto&e : v) insert(e);\r\n  }\r\n\r\n  size_t insert(const\
    \ T &key){\r\n    Np t = new Node(key, RED);\r\n    t->leftP = t->rightP = t->nextP\
    \ = t->prevP = nil;\r\n\r\n    Np x = root, y = nil;\r\n    while(x->is_valid()){\r\
    \n      y = x;\r\n      if(cmp(key, x->key)) x = x->leftP;\r\n      else x = x->rightP;\r\
    \n      y->sz += 1;\r\n    }\r\n    assert(!!y);\r\n    t->parentP = y;\r\n  \
    \  if(y->is_nil()){ root->nextP = root->prevP = t;  root = t; }\r\n    else if(cmp(key,\
    \ y->key)){ y->leftP = t; y->prevP->nextP = t; t->nextP = y; t->prevP = y->prevP;\
    \ y->prevP = t; }\r\n    else{ y->rightP = t; y->nextP->prevP = t; t->prevP =\
    \ y; t->nextP = y->nextP; y->nextP = t; }\r\n\r\n    insert_fixup(t);\r\n    return\
    \ rank(t);\r\n  }\r\n\r\n  bool erase(const T &key){\r\n    Np t = find(key),\
    \ y = t;\r\n    if(t->is_nil()) return false;\r\n    assert(t->key == key);\r\n\
    \    while(y->is_valid()){ y->sz -= 1; y = y->parentP; }\r\n    erase_impl(t);\r\
    \n    return true;\r\n  }\r\n\r\n  bool exist(const T &key) const { return find(key)->is_valid();\
    \ }\r\n\r\n  void dump() const {\r\n    dump(root);\r\n    cout << endl;\r\n \
    \ }\r\n\r\n  size_t lower_bound(const T &key) const { return rank(lower_bound(root,\
    \ key)); }\r\n  size_t upper_bound(const T &key) const { return rank(upper_bound(root,\
    \ key)); }\r\n\r\n  T at(int k) const {\r\n    if(k < 0) k += (int)size();\r\n\
    \    assert(0 <= k && k < (int)size());\r\n    return select(root, k)->key;\r\n\
    \  }\r\n\r\n  T operator[](int k) const {\r\n    if(k < 0) k += (int)size();\r\
    \n    assert(0 <= k && k < (int)size());\r\n    return select(root, k)->key;\r\
    \n  }\r\n\r\n  T pop(int k){ T key = at(k); erase(key); return key; }\r\n\r\n\
    \  size_t size() const { return root->sz; }\r\n\r\n  vector<T> enumerate() const\
    \ {\r\n    vector<T> res(size());\r\n    Np t = minimum();\r\n    for(auto&e :\
    \ res){ e = t->key; t = t->nextP; }\r\n    return res;\r\n  }\r\n\r\n  vector<T>\
    \ enumerate_by_key(const T &l, const T &r) const {\r\n    vector<T> res;\r\n \
    \   Np t = lower_bound(root, l);\r\n    while(t->is_valid() && cmp(t->key, r)){\
    \ res.push_back(t->key);  t = t->nextP; }\r\n    return res;\r\n  }\r\n\r\n  vector<T>\
    \ enumerate_by_idx(int l, int r) const {\r\n    if(l < 0) l += (int)size();\r\n\
    \    if(r < 0) r += (int)size();\r\n    if(l < 0 || int(size()) < r || r <= l)\
    \ return {};\r\n    vector<T> res(r - l);\r\n    Np t = select(root, l);\r\n \
    \   for(auto&e : res){ e = t->key; t = t->nextP; }\r\n    return res;\r\n  }\r\
    \n\r\n  struct itr{\r\n    Np t;\r\n    bool operator!=(const itr &it) const {\
    \ return t != it.t; }\r\n    void operator++(){ t = t->successor(); }\r\n    void\
    \ operator--(){ t = t->predecessor(); }\r\n    T operator*() const { return t->key;\
    \ }\r\n    itr &operator=(const itr &it){ t = it.t; return (*this); }\r\n  };\r\
    \n\r\n  struct ritr{\r\n    Np t;\r\n    bool operator!=(const ritr &it) const\
    \ { return t != it.t; }\r\n    void operator++(){ t = t->predecessor(); }\r\n\
    \    void operator--(){ t = t->successor(); }\r\n    T operator*() const { return\
    \ t->key; }\r\n    ritr &operator=(const ritr &it){ t = it.t; return (*this);\
    \ }\r\n  };\r\n\r\n  itr begin() const { return {minimum()}; }\r\n  itr end()\
    \ const { return {nil}; }\r\n  ritr rbegin() const { return {maximum()}; }\r\n\
    \  ritr rend() const { return {nil}; }\r\n\r\n  itr erase(itr it){\r\n    Np t\
    \ = it.t, y = t;\r\n    assert(t->is_valid());\r\n    itr res = it; ++res;\r\n\
    \    while(y->is_valid()){ y->sz -= 1; y = y->parentP; }\r\n    erase_impl(t);\r\
    \n    return res;\r\n  }\r\n\r\n  ritr erase(ritr it){\r\n    Np t = it.t, y =\
    \ t;\r\n    assert(t->is_valid());\r\n    ritr res = it; ++res;\r\n    while(y->is_valid()){\
    \ y->sz -= 1; y = y->parentP; }\r\n    erase_impl(t);\r\n    return res;\r\n \
    \ }\r\n\r\n  void swap(RedBlackTree &tree){\r\n    Np tmp = this->root;\r\n  \
    \  this->root = tree.root;\r\n    tree.root = tmp;\r\n    tmp = this->nil;\r\n\
    \    this->nil = tree.nil;\r\n    tree.nil = tmp;\r\n  }\r\n\r\n  void merge(const\
    \ RedBlackTree &tree){\r\n    for(auto&&e : tree) this->insert(e);\r\n  }\r\n\
    };\r\ntemplate<typename T, class Compair>\r\nvoid swap(RedBlackTree<T, Compair>\
    \ &t1, RedBlackTree<T, Compair> &t2){ t1.swap(t2); }\r\n"
  code: "#pragma once\r\n\r\n\r\ntemplate<typename T, class Compair = less<T>>\r\n\
    struct RedBlackTree{\r\nprivate:\r\n  enum Color{RED, BLACK, NIL};\r\n\r\n  struct\
    \ Node{\r\n    T key;\r\n    Color color;\r\n    size_t sz = 0;\r\n    Node *parentP\
    \ = nullptr, *leftP = nullptr, *rightP = nullptr, *nextP = nullptr, *prevP = nullptr;\r\
    \n\r\n    constexpr Node(): key{}, color(NIL) {}\r\n    constexpr Node(const T\
    \ &key, Color color): key(key), color(color), sz(1) {}\r\n\r\n    constexpr bool\
    \ is_valid() const { return color != NIL; }\r\n    constexpr bool is_nil() const\
    \ { return color == NIL; }\r\n    constexpr bool is_red() const { return color\
    \ == RED; }\r\n    constexpr bool is_black() const { return color != RED; }\r\n\
    \    constexpr bool is_left() const { return parentP->leftP == this; }\r\n   \
    \ constexpr bool is_right() const { return parentP->rightP == this; }\r\n    constexpr\
    \ bool is_root() const { return parentP->is_nil(); }\r\n\r\n    constexpr void\
    \ flip_color(){\r\n      assert(is_valid());\r\n      if(is_red()) color = BLACK;\r\
    \n      else color = RED;\r\n    }\r\n\r\n    constexpr Node *successor() const\
    \ { return nextP; }\r\n    constexpr Node *predecessor() const { return prevP;\
    \ }\r\n  };\r\n  using Np = Node*;\r\n\r\n  Np nil = new Node{};\r\n\r\n  Np root\
    \ = nil;\r\n  const Compair cmp;\r\n\r\n  void rotate_left(Np t){\r\n    Np y\
    \ = t->rightP;\r\n    assert(y->is_valid());\r\n\r\n    t->rightP = y->leftP;\r\
    \n    if(y->leftP->is_valid()) y->leftP->parentP = t;\r\n    y->parentP = t->parentP;\r\
    \n\r\n    if(t->is_root()) root = y;\r\n    else if(t->is_left()) t->parentP->leftP\
    \ = y;\r\n    else t->parentP->rightP = y;\r\n\r\n    y->leftP = t; t->parentP\
    \ = y;\r\n    y->sz = t->sz;\r\n    t->sz = t->leftP->sz + t->rightP->sz + 1;\r\
    \n  }\r\n\r\n  void rotate_right(Np t){\r\n    Np y = t->leftP;\r\n    assert(y->is_valid());\r\
    \n\r\n    t->leftP = y->rightP;\r\n    if(y->rightP->is_valid()) y->rightP->parentP\
    \ = t;\r\n    y->parentP = t->parentP;\r\n\r\n    if(t->is_root()) root = y;\r\
    \n    else if(t->is_left()) t->parentP->leftP = y;\r\n    else t->parentP->rightP\
    \ = y;\r\n\r\n    y->rightP = t; t->parentP = y;\r\n    y->sz = t->sz;\r\n   \
    \ t->sz = t->leftP->sz + t->rightP->sz + 1;\r\n  }\r\n\r\n  void insert_fixup(Np\
    \ t){\r\n    assert(!!t->parentP);\r\n    while(t->parentP->is_red()){\r\n   \
    \   if(t->parentP->is_left()){\r\n        Np y = t->parentP->parentP->rightP;\r\
    \n        if(y->is_red()){\r\n          t->parentP->flip_color();\r\n        \
    \  y->flip_color();\r\n          t->parentP->parentP->flip_color();\r\n      \
    \    t = t->parentP->parentP;\r\n        }else{\r\n          if(t->is_right()){\
    \ t = t->parentP; rotate_left(t); }\r\n          t->parentP->flip_color();\r\n\
    \          t->parentP->parentP->flip_color();\r\n          rotate_right(t->parentP->parentP);\r\
    \n        }\r\n      }else{\r\n        Np y = t->parentP->parentP->leftP;\r\n\
    \        if(y->is_red()){\r\n          t->parentP->flip_color();\r\n         \
    \ y->flip_color();\r\n          t->parentP->parentP->flip_color();\r\n       \
    \   t = t->parentP->parentP;\r\n        }else{\r\n          if(t->is_left()){\
    \ t = t->parentP; rotate_right(t); }\r\n          t->parentP->flip_color();\r\n\
    \          t->parentP->parentP->flip_color();\r\n          rotate_left(t->parentP->parentP);\r\
    \n        }\r\n      }\r\n    }\r\n    if(root->is_red()) root->flip_color();\r\
    \n  }\r\n\r\n  void erase_impl(Np t){\r\n    Np x = nil, y = t;\r\n    Color color\
    \ = y->color;\r\n    if(t->leftP->is_nil()){\r\n      x = t->rightP;\r\n     \
    \ transplant(t, t->rightP);\r\n    }else if(t->rightP->is_nil()){\r\n      x =\
    \ t->leftP;\r\n      transplant(t, t->leftP);\r\n    }else{\r\n      y = y->nextP;\r\
    \n      assert(y->is_valid());\r\n      Np m = y->parentP;\r\n      while(m !=\
    \ t){ m->sz -= 1; m = m->parentP; }\r\n      color = y->color; x = y->rightP;\r\
    \n      if(y->parentP == t) x->parentP = y;\r\n      else{\r\n        transplant(y,\
    \ y->rightP);\r\n        y->rightP = t->rightP;\r\n        y->rightP->parentP\
    \ = y;\r\n      }\r\n      transplant(t, y);\r\n      y->leftP = t->leftP;\r\n\
    \      y->leftP->parentP = y;\r\n      y->color = t->color;\r\n      y->sz = t->sz;\r\
    \n    }\r\n\r\n    if(color == BLACK) erase_fixup(x);\r\n    t->nextP->prevP =\
    \ t->prevP;\r\n    t->prevP->nextP = t->nextP;\r\n    delete t;\r\n  }\r\n\r\n\
    \  void erase_fixup(Np t){\r\n    while(!t->is_root() && t->is_black()){\r\n \
    \     if(t->is_left()){\r\n        Np y = t->parentP->rightP;\r\n        if(y->is_red()){\r\
    \n          y->flip_color(); t->parentP->flip_color();\r\n          rotate_left(t->parentP);\r\
    \n          y = t->parentP->rightP;\r\n        }\r\n        if(y->leftP->is_black()\
    \ && y->rightP->is_black()){\r\n          y->flip_color(); t = t->parentP;\r\n\
    \        }else{\r\n          if(y->rightP->is_black()){\r\n            y->leftP->flip_color();\r\
    \n            y->flip_color();\r\n            rotate_right(y);\r\n           \
    \ y = t->parentP->rightP;\r\n          }\r\n          y->color = t->parentP->color;\r\
    \n          t->parentP->color = BLACK;\r\n          y->rightP->color = BLACK;\r\
    \n          rotate_left(t->parentP);\r\n          t = root;\r\n        }\r\n \
    \     }else{\r\n        Np y = t->parentP->leftP;\r\n        if(y->is_red()){\r\
    \n          y->flip_color(); t->parentP->flip_color();\r\n          rotate_right(t->parentP);\r\
    \n          y = t->parentP->leftP;\r\n        }\r\n        if(y->leftP->is_black()\
    \ && y->rightP->is_black()){\r\n          y->flip_color(); t = t->parentP;\r\n\
    \        }else{\r\n          if(y->leftP->is_black()){\r\n            y->rightP->flip_color();\r\
    \n            y->flip_color();\r\n            rotate_left(y);\r\n            y\
    \ = t->parentP->leftP;\r\n          }\r\n          y->color = t->parentP->color;\r\
    \n          t->parentP->color = BLACK;\r\n          y->leftP->color = BLACK;\r\
    \n          rotate_right(t->parentP);\r\n          t = root;\r\n        }\r\n\
    \      }\r\n    }\r\n    if(t->is_red()) t->flip_color();\r\n  }\r\n\r\n  void\
    \ transplant(Np u, Np v){\r\n    if(u->is_root()) root = v;\r\n    else if(u->is_left())\
    \ u->parentP->leftP = v;\r\n    else u->parentP->rightP = v;\r\n    v->parentP\
    \ = u->parentP;\r\n  }\r\n\r\n  Np minimum(Np t) const {\r\n    while(t->leftP->is_valid())\
    \ t = t->leftP;\r\n    return t;\r\n  }\r\n\r\n  Np maximum(Np t) const {\r\n\
    \    while(t->rightP->is_valid()) t = t->rightP;\r\n    return t;\r\n  }\r\n\r\
    \n  Np minimum() const { return nil->nextP; }\r\n  Np maximum() const { return\
    \ nil->prevP; }\r\n\r\n\r\n  Np lower_bound(Np t, const T &key) const {\r\n  \
    \  if(t->is_nil()) return t;\r\n    if(cmp(t->key, key)) return lower_bound(t->rightP,\
    \ key);\r\n    Np l = lower_bound(t->leftP, key);\r\n    if(l->is_nil()) return\
    \ t;\r\n    return l;\r\n  }\r\n\r\n  Np upper_bound(Np t, const T &key) const\
    \ {\r\n    if(t->is_nil()) return t;\r\n    if(!cmp(key, t->key)) return upper_bound(t->rightP,\
    \ key);\r\n    Np l = upper_bound(t->leftP, key);\r\n    if(l->is_nil()) return\
    \ t;\r\n    return l;\r\n  }\r\n\r\n  Np select(Np t, size_t k) const {\r\n  \
    \  assert(!!t);\r\n    size_t r = t->leftP->sz;\r\n    if(k == r) return t;\r\n\
    \    else if(k < r) return select(t->leftP, k);\r\n    else return select(t->rightP,\
    \ k - r - 1);\r\n  }\r\n\r\n  void dump(Np t) const {\r\n    if(t->is_nil()) return;\r\
    \n    dump(t->leftP);\r\n    cout << t->key << \" \";\r\n    dump(t->rightP);\r\
    \n  }\r\n\r\n  size_t rank(Np t) const {\r\n    if(t->is_nil()) return size();\r\
    \n    size_t r = t->leftP->sz;\r\n    Np y = t;\r\n    while(!y->is_root()){\r\
    \n      if(y->is_right()) r += y->parentP->leftP->sz + 1;\r\n      y = y->parentP;\r\
    \n    }\r\n    return r;\r\n  }\r\n\r\n  Np find(const T &key) const {\r\n   \
    \ Np t = root;\r\n    while(t->is_valid() && t->key != key){\r\n      if(cmp(key,\
    \ t->key)) t = t->leftP;\r\n      else t = t->rightP;\r\n    }\r\n    return t;\r\
    \n  }\r\n\r\npublic:\r\n\r\n  RedBlackTree(const Compair &cmp = Compair{}): cmp(cmp)\
    \ {\r\n    root->nextP = root->prevP = nil;\r\n  }\r\n  RedBlackTree(initializer_list<T>\
    \ v ,const Compair &cmp = Compair{}): cmp(cmp) {\r\n    root->nextP = root->prevP\
    \ = nil;\r\n    for(auto&e : v) insert(e);\r\n  }\r\n\r\n  size_t insert(const\
    \ T &key){\r\n    Np t = new Node(key, RED);\r\n    t->leftP = t->rightP = t->nextP\
    \ = t->prevP = nil;\r\n\r\n    Np x = root, y = nil;\r\n    while(x->is_valid()){\r\
    \n      y = x;\r\n      if(cmp(key, x->key)) x = x->leftP;\r\n      else x = x->rightP;\r\
    \n      y->sz += 1;\r\n    }\r\n    assert(!!y);\r\n    t->parentP = y;\r\n  \
    \  if(y->is_nil()){ root->nextP = root->prevP = t;  root = t; }\r\n    else if(cmp(key,\
    \ y->key)){ y->leftP = t; y->prevP->nextP = t; t->nextP = y; t->prevP = y->prevP;\
    \ y->prevP = t; }\r\n    else{ y->rightP = t; y->nextP->prevP = t; t->prevP =\
    \ y; t->nextP = y->nextP; y->nextP = t; }\r\n\r\n    insert_fixup(t);\r\n    return\
    \ rank(t);\r\n  }\r\n\r\n  bool erase(const T &key){\r\n    Np t = find(key),\
    \ y = t;\r\n    if(t->is_nil()) return false;\r\n    assert(t->key == key);\r\n\
    \    while(y->is_valid()){ y->sz -= 1; y = y->parentP; }\r\n    erase_impl(t);\r\
    \n    return true;\r\n  }\r\n\r\n  bool exist(const T &key) const { return find(key)->is_valid();\
    \ }\r\n\r\n  void dump() const {\r\n    dump(root);\r\n    cout << endl;\r\n \
    \ }\r\n\r\n  size_t lower_bound(const T &key) const { return rank(lower_bound(root,\
    \ key)); }\r\n  size_t upper_bound(const T &key) const { return rank(upper_bound(root,\
    \ key)); }\r\n\r\n  T at(int k) const {\r\n    if(k < 0) k += (int)size();\r\n\
    \    assert(0 <= k && k < (int)size());\r\n    return select(root, k)->key;\r\n\
    \  }\r\n\r\n  T operator[](int k) const {\r\n    if(k < 0) k += (int)size();\r\
    \n    assert(0 <= k && k < (int)size());\r\n    return select(root, k)->key;\r\
    \n  }\r\n\r\n  T pop(int k){ T key = at(k); erase(key); return key; }\r\n\r\n\
    \  size_t size() const { return root->sz; }\r\n\r\n  vector<T> enumerate() const\
    \ {\r\n    vector<T> res(size());\r\n    Np t = minimum();\r\n    for(auto&e :\
    \ res){ e = t->key; t = t->nextP; }\r\n    return res;\r\n  }\r\n\r\n  vector<T>\
    \ enumerate_by_key(const T &l, const T &r) const {\r\n    vector<T> res;\r\n \
    \   Np t = lower_bound(root, l);\r\n    while(t->is_valid() && cmp(t->key, r)){\
    \ res.push_back(t->key);  t = t->nextP; }\r\n    return res;\r\n  }\r\n\r\n  vector<T>\
    \ enumerate_by_idx(int l, int r) const {\r\n    if(l < 0) l += (int)size();\r\n\
    \    if(r < 0) r += (int)size();\r\n    if(l < 0 || int(size()) < r || r <= l)\
    \ return {};\r\n    vector<T> res(r - l);\r\n    Np t = select(root, l);\r\n \
    \   for(auto&e : res){ e = t->key; t = t->nextP; }\r\n    return res;\r\n  }\r\
    \n\r\n  struct itr{\r\n    Np t;\r\n    bool operator!=(const itr &it) const {\
    \ return t != it.t; }\r\n    void operator++(){ t = t->successor(); }\r\n    void\
    \ operator--(){ t = t->predecessor(); }\r\n    T operator*() const { return t->key;\
    \ }\r\n    itr &operator=(const itr &it){ t = it.t; return (*this); }\r\n  };\r\
    \n\r\n  struct ritr{\r\n    Np t;\r\n    bool operator!=(const ritr &it) const\
    \ { return t != it.t; }\r\n    void operator++(){ t = t->predecessor(); }\r\n\
    \    void operator--(){ t = t->successor(); }\r\n    T operator*() const { return\
    \ t->key; }\r\n    ritr &operator=(const ritr &it){ t = it.t; return (*this);\
    \ }\r\n  };\r\n\r\n  itr begin() const { return {minimum()}; }\r\n  itr end()\
    \ const { return {nil}; }\r\n  ritr rbegin() const { return {maximum()}; }\r\n\
    \  ritr rend() const { return {nil}; }\r\n\r\n  itr erase(itr it){\r\n    Np t\
    \ = it.t, y = t;\r\n    assert(t->is_valid());\r\n    itr res = it; ++res;\r\n\
    \    while(y->is_valid()){ y->sz -= 1; y = y->parentP; }\r\n    erase_impl(t);\r\
    \n    return res;\r\n  }\r\n\r\n  ritr erase(ritr it){\r\n    Np t = it.t, y =\
    \ t;\r\n    assert(t->is_valid());\r\n    ritr res = it; ++res;\r\n    while(y->is_valid()){\
    \ y->sz -= 1; y = y->parentP; }\r\n    erase_impl(t);\r\n    return res;\r\n \
    \ }\r\n\r\n  void swap(RedBlackTree &tree){\r\n    Np tmp = this->root;\r\n  \
    \  this->root = tree.root;\r\n    tree.root = tmp;\r\n    tmp = this->nil;\r\n\
    \    this->nil = tree.nil;\r\n    tree.nil = tmp;\r\n  }\r\n\r\n  void merge(const\
    \ RedBlackTree &tree){\r\n    for(auto&&e : tree) this->insert(e);\r\n  }\r\n\
    };\r\ntemplate<typename T, class Compair>\r\nvoid swap(RedBlackTree<T, Compair>\
    \ &t1, RedBlackTree<T, Compair> &t2){ t1.swap(t2); }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/bbst/redblacktree/RedBlackTree.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/bbst/redblacktree/RedBlackTree.cpp
layout: document
redirect_from:
- /library/datastructure/bbst/redblacktree/RedBlackTree.cpp
- /library/datastructure/bbst/redblacktree/RedBlackTree.cpp.html
title: datastructure/bbst/redblacktree/RedBlackTree.cpp
---
