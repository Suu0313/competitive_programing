#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "datastructure/fenwicktree/FenwickTree.cpp"

int main(){
  int n, q; cin >> n >> q;
  FenwickTree<int64_t> ft(n);

  for(int i = 0; i < n; ++i){
    int a; cin >> a;
    ft.add(i, a);
  }

  while(q--){
    int  t, l, r; cin >> t >> l >> r;

    if(t == 0) ft.add(l, r);
    else cout << ft.query(l, r) << "\n";
  }
}
