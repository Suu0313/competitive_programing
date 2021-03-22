template<typename T = int>
struct Edge{
  int src, to; T cost; int idx;
  Edge(){}
  Edge(int src, int to, T cost = -1, int idx = -1): src(src), to(to), cost(cost), idx(idx) {}
  operator int() const { return to; }
};
template<typename T>
using Edges = vector<Edge<T>>;

template<typename T>
struct Graph {
  vector<vector<Edge<T>>> g;
  size_t es;
  Graph() {};
  Graph(size_t n): g(n), es(0) {}
  size_t size() const{ return g.size(); }

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

  void build(int m, int base = 1, bool weighted = false, bool directed = false){
    for (int i = 0; i < m; i++){
      int u, v; cin >> u >> v; u -= base; v -= base;
      T c = T(1);
      if(weighted) cin >> c;
      if(directed) add_directed_edge(u, v, c);
      else add_edge(u, v, c);
    }
  }
};
