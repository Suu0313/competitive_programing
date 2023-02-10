#pragma once

#include "..\\Graph.cpp"

template<typename T>
struct TreeDiameter{
  Graph<T> g;
  vector<int> diameter;

  TreeDiameter(const  Graph<T> &g): g(g), diameter{}, par(g.size(), -1) {}

  T solve(){
    auto p = dfs(0, -1);
    auto q = dfs(p.second, -1);

    diameter.push_back(q.second);
    for(int v = q.second; par[v] != -1; v = par[v]){
      diameter.push_back(par[v]);
    }
    return q.first;
  }

  private:
  vector<int> par;
  pair<T, int> dfs(int v, int p){
    pair<T,int> res(0, v);
    par[v] = p;
    for(auto&&e : g[v]){
      if(e.to == p) continue;
      auto cost = dfs(e.to, v);
      cost.first += e.cost;
      if(res < cost) res = cost;
    }
    return res;
  }
};
