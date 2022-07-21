template<class Operation>
struct LazySegTree{
  using Monoid = typename Operation::Monoid;
  using OperatorMonoid = typename Operation::OperatorMonoid;

  int n, height;
  vector<Monoid> node;
  vector<OperatorMonoid> lazy;
  vector<int> sz;


  LazySegTree() = default;
  LazySegTree(int n): n(n), height(ilog2(n)), node(n * 2), lazy(n) {}
  LazySegTree(int n, const Monoid &x): n(n), height(ilog2(n)), node(n * 2, x), lazy(n) { build(); }
  template<typename Iiter>
  LazySegTree(Iiter first, Iiter last): LazySegTree(int(distance(first, last))) {
    for(int i = 0; i < n; ++i, ++first) node[i + n] = *first;
    build();
  }
  template<class Container>
  LazySegTree(const Container &c): LazySegTree(begin(c), end(c)) {}


  void build(){
    for(int k = n-1; k >= 0; k--) propagate(k);
  }

  void set(int k, const Monoid &x){ node[k + n] = x; }

  void change(int k, const Monoid &x){
    k += n;
    resolve(k);
    node[k] = x;
    build(k);
  }

  void update(int k, const OperatorMonoid &x){
    k += n;
    resolve(k); apply(k, x); build(k);
  }

  void update(int l, int r, const OperatorMonoid &x){
    if(l == r) return;
    l += n; r += n;
    int dl = l, dr = r;
    resolve(dl); resolve(dr - 1);

    for(; l < r; l >>= 1, r >>= 1){
      if(l & 1) apply(l++, x);
      if(r & 1) apply(--r, x);
    }

    build(dl); build(dr - 1);
  }

  Monoid operator[](int k){
    resolve[k += n];
    return node[k];
  }

  Monoid query(int l, int r){
    Monoid res_l{}, res_r{};
    if(l == r) return res_l;
    l += n; r += n;
    resolve(l); resolve(r - 1);

    for(; l < r; l >>= 1, r >>= 1){
      if(l & 1) res_l += node[l++];
      if(r & 1) res_r = node[--r] + res_r;
    }
    return res_l += res_r;
  }

  template<typename C>
  int max_right(int l, C &check){
    if(l == n) return n;
    l += n;
    resolve(l);
    Monoid x{};
    int r = n * 2, h = 0;
    for(; l < r; l >>= 1, r >>= 1, ++h){
      if(l & 1){
        if(!check(x + node[l])){
          while(l < n){
            l <<= 1;
            if(check(x + node[l])) x += node[l++];
          }
          return l - n;
        }
        x += node[l++];
      }
      if(r & 1) --r;
    }

    while(r <<= 1, h--){
      if(((r + 1) << h) <= n * 2) {
        if(!check(x + node[r])){
          while(r < n){
            r <<= 1;
            if(check(x + node[r])) x += node[r++];
          }
          return r - n;
        }
        x += node[r++];
      }
    }

    return n;
  }

  template<typename C>
  int max_left(int r, C &check){
    if(r == 0) return 0;
    r += n;
    resolve(r - 1);
    Monoid x{};
    int l = n, h = 0;
    for(; l < r; l >>= 1, r >>= 1, ++h){
      if(l & 1) ++l;
      if(r & 1){
        --r;
        if(!check(node[r] + x)){
          while(r < n){
            r = 2*r + 1;
            if(check(node[r] + x)) x = node[r--] + x;
          }
          return r - n + 1;
        }
        x = node[r] + x;
      }
    }

    while(l <<= 1, h--){
      if(((l - 1) << h) >= n){
        --l;
        if(!check(node[l] + x)){
          while(l < n){
            l = l * 2 + 1;
            if(check(node[l] + x)) x = node[l--] + x;
          }
          return l - n + 1;
        }
        x = node[l] + x;
      }
    }
    return 0;
  }

private:
  int ilog2(int m){ return 31 - __builtin_clz(m); }
  void propagate(int k){ node[k] = node[k<<1] + node[k<<1 | 1]; }
  void build(int k){
    while(k){
      k >>= 1;
      propagate(k);
      Operation::act(node[k], lazy[k]);
    }
  }
  void apply(int k, const OperatorMonoid &x){
    Operation::act(node[k], x);
    if(k < n) lazy[k] += x;
  }
  void resolve(int k){
    OperatorMonoid id{};
    for(int h = height + 2; h > 0; --h){
      int i = k >> h;
      if(lazy[i] != id){
        apply(i << 1, lazy[i]);
        apply(i << 1 | 1, lazy[i]);
        lazy[i] = id;
      }
    }
  }
};
