#pragma once

template<class Monoid>
struct DualSegTree{
  int n, height;
  vector<Monoid> lazy;

  DualSegTree() = default;
  DualSegTree(int n): n(n), height(ilog2(n)), lazy(n * 2) {}
  DualSegTree(int n, const Monoid &x): n(n), height(ilog2(n)), lazy(n * 2) {
    for(int i = 0; i < n; ++i) lazy[i + n] = x;
  }
  template<typename Iiter>
  DualSegTree(Iiter first, Iiter last): DualSegTree(int(distance(first, last))) {
    for(int i = 0; i < n; ++i, ++first) lazy[i + n] = *first;
  }
  template<class Container>
  DualSegTree(const Container &c): DualSegTree(begin(c), end(c)) {}


  void update(int k, const Monoid &x){
    if(x == Monoid{}) return;
    resolve(k += n);
    lazy[k] += x;
  }

  void update(int l, int r, const Monoid &x){
    if(l >= r || x == Monoid{}) return;
    l += n; r += n;
    resolve(l); resolve(r - 1);

    for(; l < r; l >>= 1, r >>= 1){
      if(l & 1) lazy[l++] += x;
      if(r & 1) lazy[--r] += x;
    }
  }

  const Monoid &operator[](int k){
    resolve(k += n);
    return lazy[k];
  }

private:
  int ilog2(int m){ return 31 - __builtin_clz(m); }

  void resolve(int k){
    Monoid id{};
    for(int h = height + 2; h > 0; --h){
      int i = k >> h;
      if(lazy[i] != id){
        lazy[i << 1] += lazy[i];
        lazy[i << 1 | 1] += lazy[i];
        lazy[i] = id;
      }
    }
  }
};
