template<typename T>
struct RASMDQ_RSQ{
  using P = pair<T, T>;
  static constexpr auto f = plus<T>{};
  static constexpr auto g = [](T c, P d, int e) { return c*d.first + d.second*e; };
  static constexpr auto h = [](P a, P b) { return make_pair(a.first*b.first, a.second*b.first+b.second); };
  LazySegTree<T, P, decltype(f),  decltype(g),  decltype(h)> seg;
  
  RASMDQ_RSQ(int n): seg(n, f, g, h, 0, {1, 0}) { seg.build(); }
  RASMDQ_RSQ(const vector<T> &a): seg(a.size(), f, g, h, 0, {1, 0}) { seg.build(a); }

  auto operator()(int l, int r){
    struct{
      int l, r;
      LazySegTree<T, P, decltype(f),  decltype(g),  decltype(h)> &s;
      operator T(){ return s.query(l, r); }
      auto &operator++(){ s.update(l, r, {1, 1}); return (*this); }
      auto &operator--(){ s.update(l, r, {1, -1}); return (*this); }
      auto &operator+=(const T &x){ s.update(l, r, {1, x}); return (*this); }
      auto &operator-=(const T &x){ s.update(l, r, {1, -x}); return (*this); }
      auto &operator*=(const T &x){ s.update(l, r, {x, 0}); return (*this); }
      auto &operator/=(const T &x){ s.update(l, r, {T(1)/x, 0}); return (*this); }
    } proxy{l, r, seg};
    return proxy;
  }
  auto operator[](int k){
    struct{
      int k;
      LazySegTree<T, P, decltype(f),  decltype(g),  decltype(h)> &s;
      operator T(){ return s[k]; }
      auto &operator++(){ s.update(k, {1, 1}); return (*this); }
      auto &operator--(){ s.update(k, {1, -1}); return (*this); }
      auto &operator+=(const T &x){ s.update(k, {1, x}); return (*this); }
      auto &operator-=(const T &x){ s.update(k, {1, -x}); return (*this); }
      auto &operator*=(const T &x){ s.update(k, {x, 0}); return (*this); }
      auto &operator/=(const T &x){ s.update(k, {T(1)/x, 0}); return (*this); }
    } proxy{k, seg};
    return proxy;
  }
};
