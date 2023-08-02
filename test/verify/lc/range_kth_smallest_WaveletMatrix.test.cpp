#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include <bits/stdc++.h>
using namespace std;

#include "datastructure/waveletmatrix/WaveletMatrix.cpp"

int main(){
  int n, q; cin >> n >> q;
  vector<int> a(n); for(auto&&e : a) cin >> e;
  WaveletMatrix<30, int> wm(a);

  while(q--){
    int l, r, k; cin >> l >> r >> k;
    cout << wm.kth_smallest(l, r, k) << "\n";
  }
}
