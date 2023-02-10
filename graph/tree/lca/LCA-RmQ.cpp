#pragma once

#include "..\\..\\Graph.cpp"

template<typename T = int>
struct LCA{
  Graph<T> g;

  LCA() = default;
  LCA(int n): g(n) {}
  LCA(const Graph<T> &g, int root = 0, bool cal = true): g(g) {
    if(cal) build(root);
  }

  void build(int root = 0){
    size_t n = g.size();
    ord.reserve(n*2 - 1); dep.reserve(n*2 - 1);
    in.resize(n); dist.assign(n, 0);
    dfs(root, -1, 0);
    build_sp();
  }

  void build(const Graph<T> &g, int root = 0){
    this->g = g;
    build(root);
  }

  void add_edge(int u, int v, T cost = 1){
    g.add_edge(u, v, cost);
  }

  int lca(int u, int v) const {
    if(in[u] > in[v]) swap(u, v);
    return u==v ? u : ord[rmq(in[u], in[v])];
  }

  int operator()(int u, int v) const {
    return lca(u, v);
  }

  int get_dist(int u, int v) const {
    return dist[u] + dist[v] - 2*dist[lca(u,v)];
  }

private:
  vector<int> ord, dep, in, dist;

  void dfs(int v, int p, int d){
    in[v] = (int)ord.size();
    ord.emplace_back(v);
    dep.emplace_back(d);
    for(auto&&e : g[v]){
      if(e.to == p) continue;
      dist[e.to] = dist[v] + 1;
      dfs(e.to, v, d+1);
      ord.emplace_back(v);
      dep.emplace_back(d);
    }
  }

  vector<vector<int>> st;
  vector<int> lookup;

  int sp_op(int a, int b) const { return dep[a] < dep[b] ? a : b; }

  void build_sp(){
    int n = int(g.size()), m = n*2 - 1;
    int b = 32 - __builtin_clz(m);

    st.assign(b, vector<int>(m, 0));
    iota(begin(st[0]), end(st[0]), 0);

    for(int i = 1; i < b; i++){
      for(int j = 0; j+(1<<i) <= m; j++){
        st[i][j] = sp_op(st[i-1][j], st[i-1][j+(1<<(i-1))]);
      }
    }

    lookup.assign(m+1, 0);
    for(int i = 2; i <= m; ++i) lookup[i] = lookup[i >> 1] + 1;
  }

  int rmq(int l, int r) const {
    int b = lookup[r - l];
    return sp_op(st[b][l], st[b][r - (1<<b)]);
  }
};
