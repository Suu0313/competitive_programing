template<typename M, typename OM = M>
struct LazySegTree{
  using F = function<M(M, M)>;
  using G = function<M(M, OM)>;
  using H = function<OM(OM, OM)>;

  int n, defn, height;
  vector<M> node;
  vector<OM> lazy;
  const F f;
  const G g;
  const H h;
  const M m;
  const OM om;

  LazySegTree(int _n, const F f, const G g, const H h, const M m, const OM om): f(f), g(g), h(h), m(m), om(om){
    n = 1;
    defn = _n;
    height = 0;
    while(n<defn) n<<=1, height++;
    node.assign(2*n, m);
    lazy.assign(2*n, om);
  }

  void set(int k, const M &x){
    node.at(k + n) = x;
  }
  
  void build(){
    for(int k = n-1; k >= 0; k--){
      node.at(k) = f(node.at(2*k), node.at(2*k+1));
    }
  }

  void build(const vector<M> &v){
    assert((int)v.size() == defn);
    for(int k = 0; k < defn; k++) node[k+n] = v[k];
    build();
  }

  void change(int k, const M &x){
    k += n;
    for(int i = height; i>=1; --i) push(k >> i);
    node.at(k) = x;
    for(int i=1; i <= height; i++) propagate(k >> i);
  }
  void update(int k, const OM &x){
    k += n;
    for(int i = height; i>=1; --i) push(k >> i);
    node.at(k) = g(node.at(k), x);
    for(int i=1; i <= height; i++) propagate(k >> i);
  }

  void update(int l, int r, const OM &x){
    if(l == r) return;
    l += n; r += n;

    for(int i = height; i>=1; --i){
      if(((l>>i)<<i) != l) push(l >> i);
      if(((r>>i)<<i) != r) push((r-1) >> i);
    }

    {
      int l2 = l, r2 = r;
      while(l2 < r2){
        if(l2&1) all_apply(l2++, x);
        if(r2&1) all_apply(--r2, x);
        l2 >>= 1;
        r2 >>= 1;
      }
    }

    for(int i = 1; i <= height; ++i){
      if(((l>>i)<<i) != l) propagate(l >> i);
      if(((r>>i)<<i) != r) propagate((r-1) >> i);
    }
  }

  M at(int k){
    k += n;
    for(int i = height; i>=1; --i) push(k >> i);
    return node.at(k);
  }

  M query(int l, int r){
    if(l == r) return m;
    l += n; r += n;

    for(int i = height; i>=1; --i){
      if(((l>>i)<<i) != l) push(l >> i);
      if(((r>>i)<<i) != r) push(r >> i);
    }

    M sl = m, sr = m;
    while(l < r){
      if(l&1) sl = f(sl, node.at(l++));
      if(r&1) sr = f(node.at(--r), sr);
      l >>= 1;
      r >>= 1;
    }
    return f(sl, sr);
  }

  M all_query() const { return node.at(1); }

  template<typename C>
  int max_right(int l, C &check){
    if(l == defn) return defn;
    l += n;
    for(int i = height; i>=1; --i) push(l >> i);
    M sm = m;
    do{
      while(l%2 == 0) l >>= 1;
      if(!check(f(sm, node.at(l)))){
        while(l < n){
          push(l);
          l *= 2;
          if(check(f(sm, node.at(l)))){
            sm = f(sm, node.at(l));
            l++;
          }
        }
        return l - n;
      }
      sm = f(sm, node.at(l));
      l++;
    }while((l&-l) != l);
    return defn;
  }

  template<typename C>
  int max_left(int r, C &check){
    if(r == 0) return 0;
    r += n;
    for(int i = height; i>=1; --i) push((r-1) >> i);
    M sm = m;
    do{
      while(r>1 && (r%2)) r >>= 1;
      if(!check(f(node.at(r), sm))){
        while(r < n){
          push(r);
          r *= 2*r + 1;
          if(check(f(node.at(r), sm))){
            sm = f(node.at(r), sm);
            r--;
          }
        }
        return r + 1 - n;
      }
      sm = f(node.at(r), sm);
    }while((r&-r) != r);
    return 0;
  }

private:
  void propagate(int k){ node.at(k) = f(node.at(2*k), node.at(2*k + 1));}
  void all_apply(int k, OM x){
    node.at(k) = g(node.at(k), x);
    if(k < n) lazy.at(k) = h(lazy.at(k), x);
  }
  void push(int k){
    all_apply(2*k, lazy.at(k));
    all_apply(2*k + 1, lazy.at(k));
    lazy.at(k) = om;
  }
};
