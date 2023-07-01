#pragma once

#include "../Graph.cpp"

#include "../../string/RollingHash.cpp"

template<typename T>
struct IsomorphismofTree{
  unordered_map<uint64_t, int> mp;
  RollingHash rh;
 
  IsomorphismofTree(): mp{}, rh{} {}
 
  bool Isomorphism(const Graph<T> &tree1, const Graph<T> &tree2){
    auto cs1 = CenterofTree(tree1), cs2 = CenterofTree(tree2);
    for(auto&c1 : cs1)for(auto&c2 : cs2){
      if(AHUHash(tree1, c1) == AHUHash(tree2, c2)) return true;
    }
    return false;
  }
 
  bool Isomorphism(const Graph<T> &tree1, int p1, const Graph<T> &tree2, int p2){
    return (AHUHash(tree1, p1) == AHUHash(tree2, p2));
  }
 
  int AHUHash(const Graph<T> &tree, int v, int p = -1){
    vector<int> res;
    for(auto&e : tree[v]){
      if(e.to == p) continue;
      res.emplace_back(AHUHash(tree, e.to, v));
    }
    sort(begin(res), end(res));
    auto hs = rh.query(rh.build(res));
    if(mp.find(hs) == mp.end()){
      int h = int(mp.size()) + 1;
      mp[hs] = h;
    }
    return mp[hs];
  }
 
  vector<int> CenterofTree(const Graph<T> &tree, int p = 0){
    auto[dist, par]  = bfs(tree, p);
    int u = max_element(begin(dist), end(dist)) - begin(dist);
 
    tie(dist, par) = bfs(tree, u);
    auto it = max_element(begin(dist), end(dist));
    int dmax = *it, v = it - begin(dist);
 
    for(int i = 0; i < dmax/2; ++i) v = par[v];
 
    if(dmax%2 == 0) return {v};
    return {v, par[v]};
  }
 
  pair<vector<int>, vector<int>> bfs(const Graph<T> &tree, int pp = 0){
    int n = int(tree.size());
    vector<int> dist(n, -1), par(n, -1);
    dist[pp] = 0;
    queue<pair<int, int>> qu;
    for(qu.emplace(pp, -1); !qu.empty(); qu.pop()){
      auto[v, p] = qu.front();
      for(auto&e : tree[v]){
        if(e.to == p) continue;
        par[e.to] = v;
        dist[e.to] = dist[v] + 1;
        qu.emplace(e.to, v);
      }
    }
    return {dist, par};
  }
};
