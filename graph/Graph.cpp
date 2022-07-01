template<typename T = int>
struct Edge{
  int src, to; T cost; int idx;
  Edge(){}
  Edge(int src, int to, T cost = -1, int idx = -1): src(src), to(to), cost(cost), idx(idx) {}
  operator int() const { return to; }
};
template<typename T> using Edges = vector<Edge<T>>;

template<typename T = bool>
struct Graph {
  vector<vector<Edge<T>>> g;
  size_t es;
  Graph() {};
  Graph(size_t n): g(n), es(0) {}
  size_t size() const { return g.size(); }
  int deg(int v) const { return int(g[v].size()); }

  vector<Edge<T>> &operator[](int k) { return g.at(k); }
  const vector<Edge<T>> &operator[](int k) const { return g.at(k); }
  vector<Edge<T>> &at(int k) { return g.at(k); }
  const vector<Edge<T>> &at(int k) const { return g.at(k); }

  void add_edge(int src, int to, T cost = 1){
    g[src].emplace_back(src, to, cost, es);
    g[to].emplace_back(to, src, cost, es++);
  }
  void add_directed_edge(int src, int to, T cost = 1){
    g[src].emplace_back(src, to, cost, es++);
  }

  void read(int m, int base = 1, bool weighted = false, bool directed = false, const T &id = 1){
    for (int i = 0; i < m; i++){
      int u, v; cin >> u >> v; u -= base; v -= base;
      T c = id;
      if(weighted) cin >> c;
      if(directed) add_directed_edge(u, v, c);
      else add_edge(u, v, c);
    }
  }
  
  vector<int> topological_order() const {
    int n = int(g.size());
    vector<int> vs, ind(n); vs.reserve(n);
    for(int v = 0; v < n; ++v){
      for(const auto&e : g[v]) ++ind[e];
    }
    queue<int> qu;
    for(int v = 0; v < n; ++v){
      if(ind[v] == 0) qu.push(v);
    }
    while(!qu.empty()){
      int v = qu.front(); qu.pop();
      vs.push_back(v);
      for(auto e : g[v]){
        if(--ind[e] == 0) qu.push(e);
      }
    }
    return vs;
  }

  Graph<T> get_directed_tree(int root = 0) const {
    Graph<T> tree(g.size());
    queue<pair<int, int>> qu;
    qu.emplace(root, -1);
    for(qu.emplace(root, -1); !qu.empty(); qu.pop()){
      auto[v, p] = qu.front();
      for(const auto &e : g[v]){
        if(e.to == p) continue;
        tree.add_directed_edge(v, e.to, e.cost);
        qu.emplace(e.to, v);
      }
    }
    return tree;
  }
};
