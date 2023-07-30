#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A"

#include <bits/stdc++.h>
using namespace std;

#include "datastructure/unionfind/UnionFind.cpp"

int main() {
  int n, q; cin >> n >> q;
  UnionFind uf(n);

  while(q--){
    int com, x, y; cin >> com >> x >> y;
    if(com == 0) uf.unite(x, y);
    else cout << uf.same(x, y) << "\n";
  }
}
