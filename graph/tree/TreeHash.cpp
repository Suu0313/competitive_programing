struct TreeHash{
  unordered_map<uint64_t, int> mp;
  RollingHash rh;
  TreeHash(): mp{}, rh{} {}

  int to_hash(vector<int> &vs){
    sort(begin(vs), end(vs));
    auto hs = rh.query(rh.build(vs));
    if(mp.find(hs) == mp.end()){
      int h = int(mp.size()) + 1;
      mp[hs] = h;
    }
    return mp[hs];
  }

  vector<int> to_hash_v(const vector<int> &vs){
    int n = int(vs.size());
    auto hs = rh.build(vs);
    vector<int> res(n);
    for(int i = 0; i < n; ++i){
      auto hl = rh.query(hs, 0, i), hr = rh.query(hs, i + 1);
      auto nh = rh.cat(hl, hr, vs.size() - i - 1);
      if(mp.find(nh) == mp.end()){
        int h = int(mp.size()) + 1;
        mp[nh] = h;
      }
      res[i] = mp[nh];
    }
    return res;
  }

  template<typename T>
  vector<int> rooted_AHUHash(Graph<T> tree, int r = 0){
    tree = tree.get_directed_tree(r);
    vector<int> idx = tree.topological_order();
    reverse(begin(idx), end(idx));
    vector<int> dp(idx.size());
    for(int v : idx){
      vector<int> hs;
      for(const auto&e : tree[v]) hs.push_back(dp[e]);
      dp[v] = to_hash(hs);
    }
    return dp;
  }

  // (v, p): h
  template<typename T>
  map<pair<int, int>, int> AHUHash(const Graph<T> &tree){
    map<pair<int, int>, int> res;
    vector<int> idx = tree.get_directed_tree(0).topological_order();
    int n = int(idx.size());
    vector<int> rev(n);
    for(int i = 0; i < n; ++i) rev[idx[i]] = i;
    vector<int> dp0 = rooted_AHUHash(tree, 0);

    for(int v : idx){
      vector<pair<int, int>> hs_idx;
      for(const auto&e : tree[v]){
        if(rev[v] < rev[e]) hs_idx.emplace_back(dp0[e], e.to);
        else hs_idx.emplace_back(res.at(make_pair(e.to, v)), e.to);
      }
      sort(begin(hs_idx), end(hs_idx));
      int m = int(hs_idx.size());
      vector<int> hs(m);
      for(int i = 0; i < m; ++i) hs[i] = hs_idx[i].first;
      vector<int> nhs = to_hash_v(hs);
      for(int i = 0; i < m; ++i) res[make_pair(v, hs_idx[i].second)] = nhs[i];
      res[make_pair(v, -1)] = to_hash(hs);
    }
    return res;
  }
};
