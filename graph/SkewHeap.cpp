template<typename T, typename Compare = less<T>>
struct SkewHeap{
  struct Node{
    T key, lazy;
    Node *l, *r;
    int idx;
    Node(const T &key, int idx)
      : key(key), lazy(0), l(nullptr), r(nullptr), idx(idx){}
  };
  SkewHeap() = default;
  SkewHeap(const Compare &comp): comp(comp) {}
  
  Node *meld(Node *x, Node *y){
    propagate(x); propagate(y);
    if(!x || !y) return x? x : y;
    if(comp(x->key, y->key)) swap(x, y);
    x->r = meld(y, x->r);
    swap(x->l, x->r);
    return x;
  }
  Node *push(Node *t, const T &key, int idx = -1){
    return meld(t, alloc(key, idx));
  }
  Node *pop(Node *t){
    assert(t);
    return meld(t->l, t->r);
  }
  Node *add(Node *t, const T &lazy){
    if(t){ t->lazy += lazy; propagate(t); }
    return t;
  }
  Node *make_root(){ return nullptr; }

private:
  Compare comp{};
  Node *alloc(const T &key, int idx = -1) const {
    return new Node(key, idx);
  }
  Node *propagate(Node *t){
    if(t && t->lazy!=0){
      if(t->l) t->l->lazy += t->lazy;
      if(t->r) t->r->lazy += t->lazy;
      t->key += t->lazy;
      t->lazy = 0;
    }
    return t;
  }
};
