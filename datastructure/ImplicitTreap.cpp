template<typename T, typename E>
struct ImplicitTreap{
  using F = function<T(T, T)>;
  using G = function<T(T, E, size_t)>;
  using H = function<E(E, E)>;

  ImplicitTreap() {}
  ImplicitTreap(const T &id, const E &l_id, const F &f, const G &g, const H &h)
  : seed_gen(), mt(seed_gen()), id(id), l_id(l_id), f(f), g(g), h(h) {}

  void insert(int k, const T &value){ insert(root, tok(k), new Node(value, mt(), id, l_id)); }
  void push_front(const T &value){ insert(0, value); }
  void push_back(const T &value){ insert(size(), value); }

  void erase(int k){ erase(root, tok(k)); }

  void update(int l, int r, const E &x){ if(x != l_id) update(root, tok(l), tok(r), x); }
  T query(int l, int r){ return query(root, tok(l), tok(r)); }

  void update(int k, const E &x){ update(k, k+1, x); }
  T query(int k){ return query(k, k+1); }

  void reverse(int l, int r){ reverse(root, tok(l), tok(r)); }
  void rotate(int l, int m, int r){ rotate(root, tok(l), tok(m), tok(r)); }

  T at(int k){ return at(root, tok(k)); }
  T operator[](int k){ return at(root, k); }

  size_t size() const { return size(root); }
  bool empty() const { return !root; }
  explicit operator bool() const { return !empty(); }

  void dump() { dump(root); cout << "\n"; }

  template<typename C>
  int find(int L, int R, const C &check, bool left = true){
    L = tok(L), R = tok(R);
    if(L > R) return -1;
    if(!left) reverse(L, R);
    np l, m, r;
    split(root, L, l, m); split(m, R-L, m, r);
    T cum = id;
    int res = find(m, cum, check);
    merge(m, m, r); merge(root, l, m);
    if(left) res = L + res;
    else reverse(L, R), res = R - res;
    return res;
  }

private:
  size_t tok(int k) const {
    if(k >= 0) return k;
    return size() + k;
  }

  random_device seed_gen;
  mt19937 mt;

  const T id;
  const E l_id;
  const F f;
  const G g;
  const H h;
  
  struct Node{
    T value, acc;
    E lazy;
    size_t pri, cnt;
    bool rev;
    Node *l, *r;

    Node(const T &value, size_t pri, const T &a, const E &b)
    : value(value), acc(a), lazy(b), pri(pri), cnt(1), rev(false), l(nullptr), r(nullptr) {}
  } *root = nullptr;

  using np = Node *;

  size_t size(np t) const { return !t ? 0 : t->cnt; }
  const T &acc(np t) const { return !t ? id : t->acc; }
  
  void push_up(np t){
    if(!t) return;
    t->cnt = size(t->l) + 1 + size(t->r);
    t->acc = f(acc(t->l), f(t->value, acc(t->r)));
  }

  void push_down(np t){
    if(!t) return;
    if(t->rev){
      t->rev = false;
      swap(t->l, t->r);
      if(t->l) t->l->rev ^= 1;
      if(t->r) t->r->rev ^= 1;
    }

    if(t->lazy != l_id){
      if(t->l){
        t->l->lazy = h(t->l->lazy, t->lazy);
        t->l->acc = g(t->l->acc, t->lazy, size(t->l));
      }
      if(t->r){
        t->r->lazy = h(t->r->lazy, t->lazy);
        t->r->acc = g(t->r->acc, t->lazy, size(t->r));
      }
      t->value = g(t->value, t->lazy, 1);
      t->lazy = l_id;
    }
    push_up(t);
  }

  void split(np t, size_t key, np &l, np &r){
    if(!t){
      l = r = nullptr; return;
    }
    push_down(t);
    size_t idx = size(t->l) + 1;
    if(key < idx) split(t->l, key, l, t->l), r = t;
    else split(t->r, key-idx, t->r, r), l = t;
    push_up(l); push_up(r);
  }

  void merge(np &t, np l, np r){
    push_down(r); push_down(l);
    if(!l || !r) t = !r ? l : r;
    else if(l->pri > r->pri) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
    push_up(t);
  }

  void insert(np &t, size_t key, np x){
    np l, r;
    split(t, key, l, r);
    merge(l, l, x);
    merge(t, l, r);
  }

  void erase(np &t, size_t key){
    np l, m, r;
    split(t, key+1, m, r);
    split(m, key, l, m);
    merge(t, l, r);
  }

  T query(np t, size_t L, size_t R){
    if(L > R) return id;
    np l, m, r;
    split(t, L, l, m); split(m, R-L, m, r);
    T res = m->acc;
    merge(m, m, r); merge(t, l, m);
    return res;
  }

  void update(np t, size_t L, size_t R, const E &x){
    if(L > R) return;
    np l, m, r;
    split(t, L, l, m); split(m, R-L, m, r);
    m->lazy = h(m->lazy, x); 
    m->acc = g(m->acc, x, size(m));
    merge(m, m, r); merge(t, l, m);
  }

  void reverse(np t, size_t L, size_t R){
    if(L > R) return;
    np l, m, r;
    split(t, L, l, m); split(m, R-L, m, r);
    m->rev ^= 1;
    merge(m, m, r); merge(t, l, m);
  }

  void rotate(np t, size_t l, size_t m, size_t r){
    reverse(t, l, r); reverse(t, l, l+r-m); reverse(t, l+r-m, r);
  }

  T at(np t, size_t k){
    np l, m, r;
    split(t, k, l, m); split(m, 1, m, r);
    T res = m->acc;
    merge(m, m, r); merge(t, l, m);
    return res;
  }

  void dump(np t){
    if(!t) return;
    push_down(t);
    dump(t->l);
    cout << t->value << " ";
    dump(t->r);
  }

  template<typename C>
  int find(np t, T &cum, const C &check){
    if(!t) return 0;
    if(!check(f(cum, acc(t->l)))) return find(t->l, cum, check);
    cum = f(cum, acc(t->l));
    if(!check(f(cum, t->value))) return size(t->l);
    cum = f(cum, t->value);
    return size(t->l) + 1 + find(t->r, cum, check);
  }
};
