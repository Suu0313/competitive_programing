template<typename T, typename Compair = less<T>>
struct Treap{

  Treap(const Compair &cmp = Compair()): seed_gen(), mt(seed_gen()), cmp(cmp) {}

  Treap(initializer_list<T> il, const Compair &cmp = Compair())
    : seed_gen(), mt(seed_gen()), cmp(cmp) {
    for_each(begin(il), end(il), [&](const T &e){ insert(e); });
  }

  void insert(const T &key){ insert(root, new Node(key, mt())); }
  bool erase(const T &key){ return erase(root, key); }
  bool exist(const T &key){ return !!find(root, key); }

  const T &min(){ return min(root)->key; }
  const T &max(){ return max(root)->key; }

  const T &at(int k) const { return at(root, k>=0?size_t(k):size()+size_t(k))->key; }
  const T &operator[](int k) const { return at(k); }

  T erase_at(int k){ auto key=at(k); erase(root, key); return key; }

  size_t size() const { return size(root); }
  bool empty() const { return !root; }
  explicit operator bool() const { return !empty(); }

  size_t lower_bound(const T &key) const { return lower_bound(root, key); }
  size_t upper_bound(const T &key) const { return upper_bound(root, key); }
  size_t count(const T &key) const { return upper_bound(key) - lower_bound(key); }

private:
  random_device seed_gen;
  mt19937 mt;
  const Compair cmp;

  struct Node{
    T key;
    size_t pri, cnt;
    Node *l, *r;

    Node(const T &key, size_t pri)
      : key(key), pri(pri), cnt(1), l(nullptr), r(nullptr) {}
  } *root = nullptr;
  using np = Node*;

  size_t size(np t) const { return !t ? 0 : t->cnt; }
  
  void update(np t){
    if(!t) return;
    t->cnt = size(t->l) + 1 + size(t->r);
  }

  void split(np t, const T &key, np &l, np &r){
    if(!t) l = r = nullptr;
    else if(cmp(key, t->key)) split(t->l, key, l, t->l), r = t;
    else split(t->r, key, t->r, r), l = t;
    update(l); update(r);
  }

  void merge(np &t, np l, np r){
    if(!l || !r) t = l ? l : r;
    else if(l->pri > r->pri) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
    update(t);
  }

  void insert(np &t, np x){
    if(!t) t = x;
    else if(t->pri < x->pri) split(t, x->key, x->l, x->r), t = x;
    else insert(cmp(x->key, t->key) ? t->l : t->r, x);
    update(t);
  }

  bool erase(np &t, const T &key){
    if(!t) return false;
    if(t->key == key){ merge(t, t->l, t->r); return true; }
    auto ret = erase(cmp(key, t->key) ? t->l : t->r, key);
    update(t);
    return ret;
  }

  np find(np &t, const T &key){
    if(!t || t->key == key) return t;
    return find(cmp(key, t->key) ? t->l : t->r, key);
  }

  np min(np t) const {
    return !t ? t : (!(t->l) ? t->key : min(t->l));
  }
  np max(np t) const {
    return !t ? t : (!(t->r) ? t->key : max(t->r));
  }

  np at(np t, size_t k) const {
    if(!t || size(t->l) == k) return t;
    if(size(t->l) > k) return at(t->l, k);
    return at(t->r, k-size(t->l)-1);
  }

  size_t lower_bound(np t, const T &key) const {
    if(!t) return 0;
    if(cmp(t->key, key)) return size(t->l) + 1 + lower_bound(t->r, key);
    return lower_bound(t->l, key);
  }

  size_t upper_bound(np t, const T &key) const {
    if(!t) return 0;
    if(!cmp(key, t->key)) return size(t->l) + 1 + upper_bound(t->r, key);
    return upper_bound(t->l, key);
  }
};
