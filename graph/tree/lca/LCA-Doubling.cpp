template<typename T>
struct LCA{
  vector<vector<int>> parent;
  vector<int> depth;
  vector<T> dist;

  LCA(const Graph<T> &G, int root){ init(G, root); }

  int quert(int u, int v){
    if(depth.at(u) < depth.at(v)) swap(u,v);
    int K = parent.size();

    for(int k = 0; k < K; k++){
      if((depth.at(u)-depth.at(v))>>k & 1){
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

  T getdist(int u, int v){
    return dist.at(u) + dist.at(v) - 2*dist.at(quert(u,v));
  }

  bool isonpath(int u, int v, int a){
    return getdist(u,a) + getdist(a,v) == getdist(u,v);
  }

  bool isonpath(int u, int v, int a, int b){
    return isonpath(u,v,a) && isonpath(u,v,b);
  }

private:

  void init(const Graph<T> &G, int root){
    int V = G.size();
    int K = 1;
    while((1<<K) < V) K++;
    parent.assign(K, vector<int>(V, -1));
    depth.assign(V,-1);
    dist.assign(V, 0);
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

  void dfs(const Graph<T> &G, int v, int p, int d){
    parent.at(0).at(v) = p;
    depth.at(v) = d;
    for(auto &&e : G.at(v)){
      if(e != p){
        dist.at(e) = dist.at(v) + e.cost;
        dfs(G, e, v, d+1);
      }
    }
  }
};