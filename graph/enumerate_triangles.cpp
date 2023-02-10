#pragma once

#include ".\\Graph.cpp"

template<typename T>
vector<tuple<int,int,int>> enumerate_triangles(const Graph<T> &g){
  int n = int(g.size());
  vector<vector<int>> to(n);
  for(int v = 0; v < n; ++v){
    for(auto&e : g[v]){
      if(forward_as_tuple(g.deg(v), v) > forward_as_tuple(g.deg(e), e.to)){
        to[v].push_back(e);
      }
    }
  }
  vector<tuple<int,int,int>> res;
  vector<int> verify(n);
  for(int i = 0; i < n; ++i){
    for(int j : to[i]) verify[j] = 1;
    for(int j : to[i]) for(int k : to[j]){
      if(verify[k]) res.emplace_back(i, j, k);
    }
    for(int j : to[i]) verify[j] = 0;
  }
  return res;
}
