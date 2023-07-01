#pragma once

#include "./CentroidDecomposition.cpp"

template<typename T>
struct ContourAggregationQueryOnTree{
  ContourAggregationQueryOnTree() = default;
  ContourAggregationQueryOnTree(size_t n): decomp(n) {}
  ContourAggregationQueryOnTree(const Graph<T> &tree): decomp(tree) { build(); }

  CentroidDecomposition<T> decomp;
  vector<bool> used;
  vector<int> par;

  vector<int> vs;
  vector<vector<int>> idx;
  vector<vector<tuple<int, int, int>>> id_dist;
  vector<vector<int>> bound;
  vector<vector<vector<pair<int, int>>>> range;

  void build(){
    int n = int(decomp.size());
    auto[tree, root] = decomp.decomposition();

    used.assign(n, false);
    par.assign(n, -1);

    vs.resize(n); iota(begin(vs), end(vs), 0);
    idx.resize(n); for(int i = 0; i < n; ++i) idx[i].push_back(i);
    
    id_dist.resize(n);
    bound.resize(n);
    range.resize(n);

    queue<int> qu; qu.push(root);

    while(!qu.empty()){
      int centroid = qu.front(); qu.pop();
      bfs(centroid);

      for(auto&e : tree[centroid]){
        par[e.to] = centroid;
        qu.emplace(e.to);
      }
    }
  }

  size_t vs_size() const { return vs.size(); }

  void bfs(int c){
    used[c] = true;
    
    queue<tuple<int, int, int, int>> qu;
    {
      int id = 0;
      for(auto&e : decomp[c]){
        if(used[e]) continue;
        qu.emplace(e.to, id++, c, 1);
      }
      range[c].resize(id);
      id_dist[c].emplace_back(c, id, 0);
    }

    if(qu.empty()) return;

    while(!qu.empty()){
      auto[v, id, p, d] = qu.front(); qu.pop();
      int ord = int(vs.size());
      if(int(bound[c].size()) <= d - 1) bound[c].push_back(ord);
      if(int(range[c][id].size()) <= d - 1) range[c][id].emplace_back(ord, ord + 1);
      else range[c][id][d - 1].second = ord + 1;

      id_dist[v].emplace_back(c, id, d);
      idx[v].push_back(ord);
      vs.push_back(v);

      for(auto&e : decomp[v]){
        if(used[e]) continue;
        if(e.to == p) continue;
        qu.emplace(e.to, id, v, d + 1);
      }
    }
    bound[c].push_back(vs.size());
  }

  vector<int> enumerarte_idx(int v) const { return idx[v]; }

  template<class Monoid, typename F>
  Monoid query(int v, int d, const F &get_val) const {
    Monoid res{};
    for(auto[c, id, dist] : id_dist[v]){
      int nd = d - dist;
      if(nd < 0) continue;
      if(nd == 0){
        res += get_val(c, c + 1);
        continue;
      }
      if(int(bound[c].size()) <= nd) continue;
      int l = bound[c][nd - 1], r = bound[c][nd];
      if(int(range[c].size()) == id || int(range[c][id].size()) <= nd - 1){
        res += get_val(l, r);
      }else{
        auto[ml, mr] = range[c][id][nd - 1];
        res += get_val(l, ml) + get_val(mr, r);
      }
    }
    return res;
  }
};
