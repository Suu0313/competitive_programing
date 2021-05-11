#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"

#include <bits/stdc++.h>
using namespace std;

#include "../../math/prime/PrimeFact.cpp"

int main(){
  int n; cin >> n;
  vector<int> ans;

  auto mp = Factoring(n);
  for(auto&&[x, t] : mp){
    while(t--) ans.push_back(x);
  }

  int m = ans.size();
  cout << n << ": ";
  for(int i = 0; i < m; i++) cout << ans[i] << " \n"[i+1 == m];
}
