template<typename T = int>
struct LCA{
  Graph<T> g;

  LCA() {}
  LCA(int n): g(n) {}
  LCA(const Graph<T> &g, int root = 0, bool cal = true): g(g) {
    if(cal) build(root);
  }

  void build(int root = 0){
    size_t n = g.size();
    ord.reserve(n*2 - 1);
    dep.reserve(n*2 - 1);
    in.resize(n);
    dist.assign(n, 0);
    dfs(root, -1, 0);
    vector<int> idx(n*2 - 1);
    iota(idx.begin(), idx.end(), 0);
    auto f = [&](int a, int b){ return dep[a]<dep[b] ? a : b; };
    st = SparseTable<int>(idx, f);
  }

  void build(const Graph<T> &g, int root = 0){
    this->g = g;
    build(root);
  }

  void add_edge(int u, int v, T cost = 1){
    g.add_directed_edge(u, v, cost);
  }

  int lca(int u, int v){
    if(in[u] > in[v]) swap(u, v);
    return u==v ? u : ord[st.fold(in[u], in[v])];
  }

  T get_dist(int u, int v){
    return dist[u] + dist[v] - 2*dist[lca(u,v)];
  }

private:
  vector<int> ord, dep, in;
  vector<T> dist;
  SparseTable<int> st;

  void dfs(int v, int p, int d){
    in[v] = (int)ord.size();
    ord.emplace_back(v);
    dep.emplace_back(d);
    for(auto&&e : g[v]){
      if(e.to == p) continue;
      dist[e.to] = dist[v] + e.cost;
      dfs(e.to, v, d+1);
      ord.emplace_back(v);
      dep.emplace_back(d);
    }
  }
};
