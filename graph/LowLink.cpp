#pragma once

#include "./Graph.cpp"

template<typename T>
struct LowLink{
  Graph<T> G;
  vector<bool> used;
  vector<int> ord, low, aps;
  vector<pair<int, int>> bridges;
  LowLink(const Graph<T> &G_) : G(G_){
    int N = G.size();
    used.assign(N,false);
    ord.assign(N,0);
    low.assign(N,0);
    int k = 0;
    for(int i = 0; i < N; i++){
      if(!used.at(i)) k = dfs(i, k, -1);
    }
    sort(aps.begin(), aps.end());
    sort(bridges.begin(), bridges.end());
  }

  int dfs(int id, int k, int par){
    used.at(id) = true;
    ord.at(id) = k++;
    low.at(id) = ord.at(id);
    bool isAps = false;
    int cnt = 0;
    for(auto&&e : G.at(id)){
      if(!used.at(e)) {
        cnt++;
        k = dfs(e,k,id);
        low.at(id) = min(low.at(id),low.at(e));
        if(par != -1 && ord.at(id)<=low.at(e)) isAps = true;
        if(ord.at(id) < low.at(e)) bridges.emplace_back(min<int>(id,e),max<int>(id,e));
      }else if(e != par) {
        low.at(id) = min(low.at(id),ord.at(e));
      }
    }
    if(par == -1 && cnt >= 2) isAps = true;
    if(isAps) aps.emplace_back(id);
    return k;
  }
};
