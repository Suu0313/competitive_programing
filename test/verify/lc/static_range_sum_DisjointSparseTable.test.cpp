#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "datastructure/sparsetable/DisjointSparseTable.cpp"

int main(){
  int n, q; cin >> n >> q;
  vector<int> a(n); for(auto&&e : a) cin >> e;
  DisjointSparseTable<int64_t> st(a);
  while(q--){
    int l, r; cin >> l >> r;
    cout << st.query(l, r) << "\n";
  }
}
