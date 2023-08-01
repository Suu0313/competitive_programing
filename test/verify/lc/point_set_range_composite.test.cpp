#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <bits/stdc++.h>
using namespace std;

#include "datastructure/segtree/SegmentTree.cpp"

#include "datastructure/algebraic/monoid/CompositeMonoid.cpp"

#include "math/mod/ModInt.cpp"

int main(){
  int n, q; cin >> n >> q;
  SegmentTree<CompositeMonoid<mint998244353>> seg(n);
  for(int i = 0; i < n; ++i){
    int a, b; cin >> a >> b;
    seg.set(i, {a, b});
  }

  seg.build();

  while(q--){
    int t; cin >> t;
    if(t == 0){
      int p, c, d; cin >> p >> c >> d;
      seg.change(p, {c, d});
    }else{
      int l, r, x; cin >> l >> r >> x;
      auto[a, b] = seg.query(l, r);
      cout << (a * x + b) << "\n";
    }
  }
}
