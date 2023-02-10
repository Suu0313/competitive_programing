#pragma once

template<typename T = int>
struct Edge{
  int src, to; T cost; int idx;
  Edge() = default;
  Edge(int src, int to, T cost = -1, int idx = -1): src(src), to(to), cost(cost), idx(idx) {}
  operator int() const { return to; }
};
template<typename T> using Edges = vector<Edge<T>>;

template<typename T = int>
struct Graph : vector<vector<Edge<T>>> {
  using base_t = vector<vector<Edge<T>>>;
  using base_t::base_t;
  size_t es;
  Graph(size_t n): base_t(n), es(0) {}

  int deg(int v) const { return int(base_t::operator[](v).size()); }

  void add_edge(int src, int to, T cost = 1){
    base_t::operator[](src).emplace_back(src, to, cost, es);
    base_t::operator[](to).emplace_back(to, src, cost, es++);
  }
  void add_directed_edge(int src, int to, T cost = 1){
    base_t::operator[](src).emplace_back(src, to, cost, es++);
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
    int n = int(this->size());
    vector<int> vs, ind(n); vs.reserve(n);
    for(const auto&edges : (*this)){
      for(const auto&edge : edges) ++ind[edge.to];
    }
    queue<int> qu;
    for(int v = 0; v < n; ++v){
      if(ind[v] == 0) qu.push(v);
    }
    while(!qu.empty()){
      int v = qu.front(); qu.pop();
      vs.push_back(v);
      for(const auto &e :  base_t::operator[](v)){
        if(--ind[e.to] == 0) qu.push(e.to);
      }
    }
    return vs;
  }

  Graph<T> get_directed_tree(int root = 0) const {
    Graph<T> tree(this->size());
    queue<pair<int, int>> qu;
    for(qu.emplace(root, -1); !qu.empty(); qu.pop()){
      auto[v, p] = qu.front();
      for(const auto &e : base_t::operator[](v)){
        if(e.to == p) continue;
        tree.add_directed_edge(v, e.to, e.cost);
        qu.emplace(e.to, v);
      }
    }
    return tree;
  }

  vector<T> bfs_dist(int root) const {
    vector<T> dist(this->size());
    queue<pair<int, int>> qu;
    for(qu.emplace(root, -1); !qu.empty(); qu.pop()){
      auto[v, p] = qu.front();
      for(const auto &e : base_t::operator[](v)){
        if(e.to == p) continue;
        dist[e.to] = dist[v] + e.cost;
        qu.emplace(e.to, v);
      }
    }
    return dist;
  }
};
