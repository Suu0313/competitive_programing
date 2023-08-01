#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "datastructure/segtree/LazySegTree.cpp"

#include "datastructure/algebraic/operator_monoid/RangeAffineRangeSum.cpp"

#include "math/mod/ModInt.cpp"

int main(){
  int n, q; cin >> n >> q;
  LazySegTree<RangeAffineRangeSum<mint998244353>> seg(n);
  for(int i = 0; i < n; ++i){
    int a; cin >> a;
    seg.set(i, {a});
  }
  seg.build();

  while(q--){
    int t; cin >> t;
    if(t == 0){
      int l, r, c, d; cin >> l >> r >> c >> d;
      seg.update(l, r, {c, d});
    }else{
      int l, r; cin >> l >> r;
      cout << seg.query(l, r).x << "\n";
    }
  }
}
