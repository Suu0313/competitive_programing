#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <bits/stdc++.h>
using namespace std;

#include "datastructure/sparsetable/SparseTable.cpp"

#include "datastructure/algebraic/monoid/MinMonoid.cpp"

int main(){
  int n, q; cin >> n >> q;
  vector<int> a(n); for(auto&&e : a) cin >> e;
  SparseTable<MinMonoid<int>> st(a);
  while(q--){
    int l, r; cin >> l >> r;
    cout << st.fold(l, r).x << "\n";
  }
}
