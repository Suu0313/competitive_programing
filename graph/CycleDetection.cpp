#pragma once

#include "./Graph.cpp"

template<typename T>
struct CycleDetection{
  Graph<T> g;
  bool directed;
  vector<int> used;
  vector<Edge<T>> pre, cycle;
  CycleDetection(const Graph<T> &g, bool directed = true)
    : g(g), directed(directed), used(g.size()), pre(g.size()) {}

  vector<Edge<T>> find(){
    for(int i = 0; i < (int)g.size(); i++){
      if(used[i]==0 && dfs(i)){
        reverse(cycle.begin(), cycle.end());
        return cycle;
      }
    }
    return {};
  }

private:
  bool dfs(int v, int q = -1){
    used[v] = 1;
    for(auto&&e : g[v]){
      if(e == q && !directed) continue;
      if(used[e] == 0){
        pre[e] = e;
        if(dfs(e, v)) return true;
      }else if(used[e] == 1){
        int p = v;
        while(p != e){
          cycle.emplace_back(pre[p]);
          p = pre[p].src;
        }
        cycle.emplace_back(e);
        return true;
      }
    }
    used[v] = 2;
    return false;
  }
};
