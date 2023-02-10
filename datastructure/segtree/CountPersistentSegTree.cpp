#pragma once

template<typename T, typename M>
struct CountPersistentSegTree{
  using OP = function<M(M, M)>;

  const M id;
  const OP op, inv;

  CountPersistentSegTree(const M &id, const OP &op, const OP &inv): id(id), op(op), inv(inv) { }

  void add(const T &x, const T &y, const M &v){
    ps.emplace_back(x, y, v);
  }

  void build(){
    sort(begin(ps), end(ps));
    int m = int(ps.size());
    xs.resize(m);
    ys.resize(m);
    roots.resize(m+1, nullptr);

    for(int i = 0; i < m; ++i){
      auto[x,y,v] = ps[i];
      xs[i] = x;
      ys[i] = y;
    }
    compress();
    n0 = int(pys.size());
    for(n=1; n < n0; n<<=1);

    for(int i = 0; i < m; ++i){
      auto[x,y,v] = ps[i];
      roots[i+1] = add(roots[i], v, ks[i], 0, n);
    }
  }

  M fold(const T &lx, const T &rx, const T &ly, const T &ry){
    return inv(fold(roots[lb(xs, rx)],  lb(pys, ly), lb(pys, ry), 0, n), fold(roots[lb(xs, lx)],  lb(pys, ly), lb(pys, ry), 0, n));
  }

  int count(const T &lx, const T &rx, const T &ly, const T &ry){
    return count(roots[lb(xs, rx)],  lb(pys, ly), lb(pys, ry), 0, n) - count(roots[lb(xs, lx)],  lb(pys, ly), lb(pys, ry), 0, n);
  }

  T kth_element(const T &lx, const T &rx, int k){
    return pys[kth_element(roots[lb(xs, rx)], roots[lb(xs, lx)], k, 0, n)];
  }

private:
  struct Node{
    M val; int cnt;
    Node *l = nullptr, *r = nullptr;
    Node() {}
    Node(const M &val, int cnt): val(val), cnt(cnt) {};
  };
  using Np = Node*;
  int n, n0;
  vector<tuple<T,T,M>> ps;
  vector<T> xs, ys, pys;
  vector<int> ks;
  vector<Np> roots;

  void compress(){
    int m = ys.size();
    vector<int> idx(m); iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&](int i, int j){ return ys[i] < ys[j]; });
    pys.assign(1, ys[idx[0]]);
    ks.assign(m, 0);
    for(int i = 1; i < m; ++i){
      int a = idx[i-1], b = idx[i];
      if(ys[a] == ys[b]) ks[b] = ks[a];
      else{
        ks[b] = ks[a] + 1;
        pys.emplace_back(ys[b]);
      }
    }
  }

  int lb(const vector<T> &vs, const T &v){
    return lower_bound(begin(vs), end(vs), v) - begin(vs);
  }

  int cnt(Np t){ return !t ? 0 : t->cnt; }
  M val(Np t) { return !t ? id : t->val; }

  Np add(Np t, const M &v, int k, int l, int r){
    if(k < l || r <= k) return t;
    Np s = new Node(op(val(t), v), cnt(t)+1);
    if(t){ s->l = t->l; s->r = t->r; }
    if(l+1 == r) return s;
    int m = l + ((r-l) >> 1);
    s->l = add(s->l, v, k, l, m);
    s->r = add(s->r, v, k, m, r);
    return s;
  }

  int count(Np t, int ql, int qr, int l, int r){
    if(!t || qr<=l || r<=ql) return 0;
    if(ql<=l && r<=qr) return cnt(t);
    int m = l + ((r-l) >> 1);
    return count(t->l, ql, qr, l, m) + count(t->r, ql, qr, m, r);
  }

  M fold(Np t, int ql, int qr, int l, int r){
    if(!t || qr<=l || r<=ql) return id;
    if(ql<=l && r<=qr) return val(t);
    int m = l + ((r-l) >> 1);
    return op(fold(t->l, ql, qr, l, m), fold(t->r, ql, qr, m, r));
  }

  int kth_element(Np s, Np t, int k, int l, int r){
    if(l+1 == r) return l;
    if(!s) s = new Node(id, 0);
    if(!t) t = new Node(id, 0);
    int lc = cnt(s->l) - cnt(t->l);
    int m = l + ((r-l) >> 1);
    if(lc > k) return kth_element(s->l, t->l, k, l, m);
    return kth_element(s->r, t->r, k-lc, m, r);
  }
};
