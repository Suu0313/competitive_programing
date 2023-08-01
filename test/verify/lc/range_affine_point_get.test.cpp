#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include <bits/stdc++.h>
using namespace std;

#include "datastructure/segtree/DualSegTree.cpp"

#include "datastructure/algebraic/monoid/CompositeMonoid.cpp"

#include "math/mod/ModInt.cpp"

int main() {
  int n, q; cin >> n >> q;
  vector<int> x(n); for(auto&&e : x) cin >> e;
  DualSegTree<CompositeMonoid<mint998244353>> seg(n);
  while(q--){
    int t; cin >> t;
    if(t == 0){
      int l, r, b, c; cin >> l >> r >> b >> c;
      seg.update(l, r, {b, c});
    }else{
      int i; cin >> i;
      auto[a, b] = seg[i];
      cout << a * x[i] + b << "\n";
    }
  }
}
