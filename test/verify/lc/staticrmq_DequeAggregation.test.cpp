#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <bits/stdc++.h>
using namespace std;

#include "datastructure/DequeAggregation.cpp"

#include "datastructure/algebraic/monoid/MinMonoid.cpp"

#include "other/sort/hilbert_sort.cpp"

int main(){
  int n, q; cin >> n >> q;
  vector<int> a(n); for(auto&&e : a) cin >> e;
  vector<int> l(q), r(q);
  for(int i = 0; i < q; ++i) cin >> l[i] >> r[i];
  DequeAggregation<MinMonoid<int>> dq;
  int nl = 0, nr = 0;
  vector<int> ans(q);

  for(int i : hilbert_sort(l, r)){
    while(nr < r[i]){
      // add nr
      dq.push_back(a[nr]);
      ++nr;
    }
  
    while(l[i] < nl){
      --nl;
      // add nl
      dq.push_front(a[nl]);
    }
  
    while(r[i] < nr){
      --nr;
      // rm nr
      dq.pop_back();
    }
  
    while(nl < l[i]){
      // rm nl
      dq.pop_front();
      ++nl;
    }
    ans[i] = dq.prod().x;
  }

  for(auto&&e : ans) cout << e << "\n";
}
