template<typename T>
struct PersistentSegmentTree{
  using OP = function<T(T,T)>;
  int n, n0;
  const T id;
  const OP op;
  struct Node{
    T val;
    Node *l, *r;
    Node(const T &val): val(val), l(nullptr), r(nullptr) {}
  };
  using Np = Node*;

  PersistentSegmentTree(int n_, const T &id, const OP &op) : n(1), n0(n_), id(id),op(op){
    while(n < n_) n<<=1;
  }

  Np build(){ return build(vector<T>{}); }

  Np build(const vector<T> &v){ return build(0, n, v); }

  Np update(Np root, int k, const T &x){ return update(root, k, x, 0, n); }

  T query(Np root, int l, int r){ return query(root, l, r, 0, n); }

private:

  T val(Np t) const { return !t ? id : t->val; }

  Np merge(Np l, Np r){
    Np t = new Node(op(val(l), val(r)));
    t->l = l; t->r = r;
    return t;
  }

  Np build(int l, int r, const vector<T> &v){
    if(l+1 == r) return new Node(l<int(v.size()) ? v[l] : id);
    int m = l + ((r-l)>>1);
    return merge(build(l, m, v), build(m, r, v));
  }

  Np update(Np t, int k, const T &x, int l, int r){
    if(k < l || r <= k) return t;
    if(l+1 == r) return new Node(x);
    int m = l + ((r-l)>>1);
    return merge(update(t->l, k, x, l, m), update(t->r, k, x, m, r));
  }

  T query(Np t, int ql, int qr, int l, int r) const {
    if(!t || r<=ql || qr<=l) return id;
    if(ql<=l && r<=qr) return t->val;
    int m = l + ((r-l) >> 1);
    return op(query(t->l, ql, qr, l, m), query(t->r, ql, qr, m, r));
  }
};
