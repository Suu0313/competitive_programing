#pragma once

template <typename T=int>
struct FenwickTree{
  int n;
  vector<T> node;
  FenwickTree() = default;
  FenwickTree(int n_) : n(n_+1), node(n) {}
  FenwickTree(const FenwickTree&) = default;
  FenwickTree(FenwickTree&&) = default;
  FenwickTree &operator=(const FenwickTree&) = default;
  FenwickTree &operator=(FenwickTree&&) = default;

  void add(int i, T x){
    for(int idx = i+1; idx < n; idx += (idx & -idx)){
      node.at(idx) += x;
    }
  }

  T sum(int i) const { //[0,i)
    T s{};
    for(int idx = i; idx > 0; idx -= (idx & -idx)){
      s += node.at(idx);
    }
    return s;
  }
  T query(int l, int r) const { //[l,r)
    return sum(r)-sum(l); 
  }

  T operator[](int i) const { return query(i,i+1); }

  int lower_bound(T w) const {
    if(w <= 0) return 0;
    int x = 0, r = 1;
    while(r < n) r *= 2;
    for(int len = r; len>0; len>>=1){
      if(x+len<n && node.at(x+len) < w){
        w -= node.at(x+=len);
      }
    }
    return x;
  }
};
