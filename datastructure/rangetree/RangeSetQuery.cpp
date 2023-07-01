#pragma once

#include "./StaticRangeTree.cpp"

struct RangeSetQuery{
  StaticRangeTree<int, int, int> seg;

  template<typename T>
  RangeSetQuery(const vector<T> &v): seg{}{
    int n = int(v.size());
    map<T, int> mp;
    vector<tuple<int,int,int>> ps;
    for(int i = 0; i < n; ++i){
      if(mp.count(v[i])) ps.emplace_back(i, mp[v[i]], 1);
      mp[v[i]] = i;
    }
    seg.build(ps);
  }

  int query(int l, int r) const {
    return r - l - seg.query(l, r, l, r);
  }
};

// TODO: WM で書き直す

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  vector<int> c(n); for(auto&&e : c) cin >> e, --e;
  vector<int> a(n), pre(n, n);
  for(int i = 0; i < n; i++){
    a[i] = pre[c[i]];
    pre[c[i]] = i;
  }

  WaveletMatrix<20, int> wm(a);

  while(q--){
    int l, r; cin >> l >> r; --l;
    cout << r - l - wm.rank(l, r, l, r) << "\n";
  }
}
