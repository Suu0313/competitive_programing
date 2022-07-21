template<typename T, typename OP>
struct SegmentTree{

  int n, n0;
  vector<T> node;
  T id;
  const OP op;

  SegmentTree(int n_, const T &id, const OP &op) : id(id), op(op){
    n = 1;
    n0 = n_;
    while(n < n_) n <<= 1;
    node.assign(2*n, id);
  }

  void init(int n_){
    n = 1;
    n0 = n_;
    while(n < n_) n <<= 1;
    node.assign(2*n, id);
  }

  void set(int k, const T &x){
    node.at(k+n) = x;
  }

  void build(){
    for(int k = n - 1; k > 0; k--){
      node.at(k) = op(node.at(2*k),node.at(2*k+1));
    }
  }

  void build(const vector<T> &v){
    assert((int)v.size() == n0);
    for(int k = 0; k < n0; k++) node[k+n] = v[k];
    build();
  }

  void change(int k, const T &x){
    k += n;
    node.at(k) = x;
    while(k >>= 1){
      node.at(k) = op(node.at(2*k), node.at(2*k+1));
    }
  }

  void change(int l, int r, const T &x){
    for(int k = l; k < r; k++) change(k,x);
  }

  template<typename C>
  void update(int k, const C &c){
    T x = node.at(k+n);
    T x2 = c(x);
    change(k, x2);
  }

  template<typename C>
  void update(int l, int r, const C &c){
    for(int k = l; k < r; k++) update(k,c);
  }

  T at(int k) const { return node.at(k+n); }
  T operator[](int k) const { return node.at(k+n); }

  void add(int k, const T &a){
    T x = at(k)+a;
    change(k,x);
  }

  void add(int l, int r, const T &a){
    for(int k = l; k < r; k++) add(k,a);
  }

  T query(int a, int b){
    if(a==0 && b==n0) return all_query();
    T L = id, R = id;
    for(a += n, b += n; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = op(L, node.at(a++));
      if(b & 1) R = op(node.at(--b), R);
    }
    return op(L, R);
  }

  T all_query() const { return node.at(1); }

  template<typename C>
  int max_right(int l, const C &check){
    if(l == n0) return n0;
    l += n;
    T tm = id;
    do{
      while(l%2 == 0) l >>= 1;
      if(!check(op(tm, node.at(l)))){
        while(l < n){
          l *= 2;
          if(check(op(tm, node.at(l)))){
            tm = op(tm, node.at(l));
            l++;
          }
        }
        return l - n;
      }
      tm = op(tm, node.at(l));
      l++;
    }while((l&-l) != l);
    return n0;
  }

  template<typename C>
  int min_left(int r, const C &check){
    if(r == 0) return 0;
    r += n;
    T tm = id;
    do{
      r--;
      while(r>1 && (r%2)) r >>= 1;
      if(!check(op(node.at(r), tm))){
        while(r < n){
          r = 2*r + 1;
          if(check(op(node.at(r), tm))){
            tm = op(node.at(r), tm);
            r--;
          }
        }
        return r + 1 - n;
      }
      tm = op(node.at(r), tm);
    }while((r&-r) != r);
    return 0;
  }
};

template<typename T, typename OP>
SegmentTree<T,OP> get_segtree(int n, const T &id, const OP &op){
  return {n, id, op};
}

template<typename T, typename OP>
SegmentTree<T,OP> get_segtree(int n, const T &id, const OP &op, const vector<T> &v){
  SegmentTree<T,OP> seg(n, id, op);
  seg.build(v);
  return seg;
}
