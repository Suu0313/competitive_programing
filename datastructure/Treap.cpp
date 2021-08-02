template<typename T>
struct Treap{

  Treap(): seed_gen(), mt(seed_gen()) {}

  void insert(const T &key){ insert(root, new Node(key, mt())); }
  bool erase(const T &key){ return erase(root, key); }
  bool find(const T &key){ return find(root, key); }

  const T &min(){ return min(root); }
  const T &max(){ return max(root); }

  const T &at(int k) const { return at(root, k>=0?size_t(k):size()+size_t(k)); }
  const T &operator[](int k) const { return at(k); }

  T erase_at(int k){ auto key = at(k); return (erase(root, key), key); }

  size_t size() const { return size(root); }
  bool empty() const { return !root; }
  explicit operator bool() const { return !empty(); }

private:
  random_device seed_gen;
  mt19937 mt;

  struct Node{
    T key;
    size_t priority, cnt;
    Node *l, *r;

    Node(const T &key, size_t priority)
      : key(key), priority(priority), cnt(1), l(nullptr), r(nullptr) {}
  } *root = nullptr;
  using np = Node*;

  size_t size(np t) const { return !t ? 0 : t->cnt; }
  
  void update(np t){
    if(!t) return;
    t->cnt = size(t->l) + 1 + size(t->r);
  }

  void split(np t, const T &key, np &l, np &r){
    update(t);
    if(!t) l = r = nullptr;
    else if(key < t->key) split(t->l, key, l, t->l), r = t;
    else split(t->r, key, t->r, r), l = t;
    update(l); update(r);
  }

  void merge(np &t, np l, np r){
    update(l); update(r);
    if(!l || !r) t = l ? l : r;
    else if(l->priority > r->priority) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
    update(t);
  }

  void insert(np &t, np x){
    if(!t) t = x;
    else if(t->priority < x->priority) split(t, x->key, x->l, x->r), t = x;
    else insert(x->key < t->key ? t->l : t->r, x);
    update(t);
  }

  bool erase(np &t, const T &key){
    if(!t) return false;
    if(t->key == key){ merge(t, t->l, t->r); return true; }
    auto ret = erase(key < t->key ? t->l : t->r, key);
    update(t);
    return ret;
  }

  bool find(np &t, const T &key){
    if(!t) return false;
    if(t->key == key) return true; 
    return find(key < t->key ? t->l : t->r, key);
  }

  const T &min(np t) const {
    assert(!!t);
    return !t->l ? t->key : min(t->l);
  }
  const T &max(np t) const {
    assert(!!t);
    return !t->r ? t->key : max(t->r);
  }

  const T &at(np t, size_t k) const {
    assert(t);
    if(size(t->l) == k) return t->key;
    if(size(t->l) > k) return at(t->l, k);
    return at(t->r, k-size(t->l)-1);
  }
};
