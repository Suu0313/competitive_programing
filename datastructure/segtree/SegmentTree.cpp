#pragma once

/**
 * @brief Segment Tree
 * @docs docs/SegmentTree.md
 */

template<class Monoid>
struct SegmentTree{
  int n;
  vector<Monoid> node;

  SegmentTree() = default;
  SegmentTree(int n): n(n), node(n * 2) {}
  SegmentTree(int n, const Monoid &x): n(n), node(n * 2, x){ build(); }
  template<class Iiter>
  SegmentTree(Iiter first, Iiter last): SegmentTree(int(distance(first, last))){
    for(int i = 0; i < n; ++i, ++first) node[i + n] = *first;
    build();
  }
  template<class Container>
  SegmentTree(const Container &c): SegmentTree(begin(c), end(c)) {}


  void build(){
    for(int k = n - 1; k > 0; --k) node[k] = node[k << 1] + node[k << 1 | 1];
  }

  void set(int k, const Monoid &x){ node[k + n] = x; }

  void change(int k, const Monoid &x){
    k += n;
    node[k] = x;
    while(k >>= 1) node[k] = node[k << 1] + node[k << 1 | 1];
  }

  void change(int l, int r, const Monoid &x){
    for(int k = l; k < r; k++) change(k, x);
  }

  template<typename F>
  void update(int k, const F &f){
    change(k, f(node[k + n]));
  }

  template<typename F>
  void update(int l, int r, const F &f){
    for(int k = l; k < r; k++) update(k, f);
  }

  const Monoid &operator[](int k) const { return node[k + n]; }

  Monoid query(int l, int r) const {
    Monoid res_l{}, res_r{};
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
      if(l & 1) res_l += node[l++];
      if(r & 1) res_r = node[--r] + res_r;
    }
    return res_l += res_r;
  }

  template<typename C>
  int max_right(int l, const C &check){
    if(l == n) return n;
    Monoid x{};
    l += n;
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
  int min_left(int r, const C &check){
    if(r == 0) return 0;
    Monoid x{};
    r += n;
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
};
