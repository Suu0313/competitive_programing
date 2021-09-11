template<typename M, typename H>
struct DualSegTree{
  int n, height;
  vector<M> lazy;
  const H h;
  const M id;

  DualSegTree(int n0, const H &h, const M &id): n(1), height(0), h(h), id(id){
    while(n < n0){ n <<= 1; ++height; }
    lazy.assign(n * 2, id);
  }

  void update(int l, int r, const M &x){
    if(l >= r || x == id) return;
    l += n; r += n;
    for(int i = height; i>=1; --i) push(l >> i), push((r-1)>>i);
    
    for(; l < r; l>>=1, r>>=1){
      if(l&1) lazy[l] = h(lazy[l], x), ++l;
      if(r&1) --r, lazy[r] = h(lazy[r], x);
    }
  }

  const M &operator[](int k){
    k += n;
    for(int i = height; i>=1; --i) push(k >> i);
    return lazy[k];
  }

private:
  void push(int k){
    if(lazy[k] == id) return;
    lazy[2*k] = h(lazy[2*k], lazy[k]);
    lazy[2*k + 1] = h(lazy[2*k + 1], lazy[k]);
    lazy[k] = id;
  }
};

template<typename M, typename H>
DualSegTree<M, H> get_dualsegtree(int n, const H &h, const M &id){
  return {n, h, id};
}
