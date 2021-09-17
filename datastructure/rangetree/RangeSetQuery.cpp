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
