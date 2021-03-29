template<typename T, typename U>
struct ReRooting{
  struct Edge{
    int to;
    U data;
    T dp, ndp;
    Edge(int to, const U &data, const T &dp, const T &ndp)
      : to(to), data(data), dp(dp), ndp(ndp) {}
  };
  using F = function<T(T, T)>;
  using G = function<T(T, U)>;

  const int V;
  vector<vector<Edge>> tree;
  const F f;
  const G g;
  const T e;
  vector<T> dp, dp_p;

  vector<int> dag, rev;

  ReRooting(int V, const F f, const G g, const T &e)
    : V(V), tree(V), f(f), g(g), e(e), dp(V, e), dp_p(V, e) {}
  
  void add_edge(int u, int v, const U &c){
    tree[u].emplace_back(v, c, e, e);
    tree[v].emplace_back(u, c, e, e);
  }

  void add_edge_bi(int u, int v, const U &c, const U &d){
    tree[u].emplace_back(v, c, e, e);
    tree[v].emplace_back(u, d, e, e);
  }

  vector<T> solve(int root = 0){
    TopologicalSort(root);
    for(int i = V-1; i >= 0; i--) dfs_sub(i, dag[i]);
    for(int i = 0; i < V; i++) dfs_all(i, dag[i]);
    return dp;
  }

private:

  void TopologicalSort(int root){
    queue<int> qu;
    vector<bool> seen(V);
    dag.emplace_back(root); seen[root] = true;

    for(qu.emplace(root); !qu.empty(); qu.pop()){
      int v = qu.front();
      for(auto&&e : tree[v]){
        if(seen[e.to]) continue;
        seen[e.to] = true;
        dag.emplace_back(e.to);
        qu.emplace(e.to);
      }
    }
    rev.resize(V);
    for(int i = 0; i < V; i++) rev[dag[i]] = i;
  }

  void dfs_sub(int idx, int v){
    for(auto&&e : tree[v]){
      if(rev[e.to] < idx) continue;
      dp[v] = f(dp[v], g(dp[e.to], e.data));
    }
  }

  void dfs_all(int idx, int v){
    T buff{e};
    for(int i = 0; i < (int)tree[v].size(); i++){
      auto &e = tree[v][i];
      e.ndp = buff;
      if(rev[e.to] < idx) e.dp = g(dp_p[v], e.data);
      else e.dp = g(dp[e.to], e.data);
      buff = f(buff, e.dp);
    }
    dp[v] = buff;
    buff = e;
    for(int i = (int)tree[v].size()-1; i >= 0; i--){
      auto &e = tree[v][i];
      if(rev[e.to] > idx) dp_p[e.to] = f(e.ndp, buff);
      e.ndp = f(e.ndp, buff); buff = f(buff, e.dp);
    }
  }
};
