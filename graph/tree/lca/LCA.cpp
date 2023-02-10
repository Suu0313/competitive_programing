#pragma once

template<typename T = int>
struct LCA{
  vector<vector<int>> parent;
  vector<int> dist;

  LCA (vector<vector<T>> &G, int root){ init(G, root); }

  void init(vector<vector<T>> &G, int root){
    int V = G.size();
    int K = 1;
    while((1<<K) < V) K++;
    parent.assign(K, vector<int>(V, -1));
    dist.assign(V,-1);
    dfs(G,root,-1,0);
    for(int k = 0; k < K-1; k++){
      for(int v = 0; v < V; v++){
        if(parent.at(k).at(v)<0){
          parent.at(k+1).at(v) = -1;
        }else{
          parent.at(k+1).at(v) = parent.at(k).at(parent.at(k).at(v));
        }
      }
    }
  }

  void dfs(vector<vector<T>> &G, int v, int p, int d){
    parent.at(0).at(v) = p;
    dist.at(v) = d;
    for(auto &&e : G.at(v)){
      if(e != p) dfs(G, e, v, d+1);
    }
  }

  int quert(int u, int v){
    if(dist.at(u) < dist.at(v)) swap(u,v);
    int K = parent.size();

    for(int k = 0; k < K; k++){
      if((dist.at(u)-dist.at(v))>>k & 1){
        u = parent.at(k).at(u);
      }
    }
    if(u==v) return u;

    for(int k = K-1; k >= 0; k--){
      if(parent.at(k).at(u) != parent.at(k).at(v)){
        u = parent.at(k).at(u);
        v = parent.at(k).at(v);
      }
    }
    return parent.at(0).at(u);
  }

  int getdist(int u, int v){
    return dist.at(u) + dist.at(v) - 2*dist.at(quert(u,v));
  }

  bool isonpath(int u, int v, int a){
    return getdist(u,a) + getdist(a,v) == getdist(u,v);
  }

  bool isonpath(int u, int v, int a, int b){
    return isonpath(u,v,a) && isonpath(u,v,b);
  }
};
