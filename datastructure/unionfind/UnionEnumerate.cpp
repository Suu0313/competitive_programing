#pragma once

struct UnionEnumerate{
  vector<int> next;

  UnionEnumerate() = default;
  UnionEnumerate(int n): next(n) { iota(begin(next), end(next), 0); }

  size_t size() const { return next.size(); }

  vector<int> enumerate(int n) const {
    vector<int> res(1, n);

    for(int pos = next[n]; pos != n; pos = next[pos]){
      res.push_back(pos);
    }

    return res;
  }

  vector<vector<int>> group() const {
    int n = int(next.size());
    vector<vector<int>> res;
    vector<bool> seen(n, false);

    for(int i = 0; i < n; ++i){
      if(seen[i]) continue;
      res.push_back(this->enumerate(i));
      for(const int j : res.back()) seen[j] = true;
    }

    return res;
  }

  void unite(int u, int v){ swap(next[u], next[v]); }
};
