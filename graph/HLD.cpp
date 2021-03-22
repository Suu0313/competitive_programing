template<typename T = int>
struct HeavyLightDecomposition{
  int n, root;
  Graph<T> g;
  vector<int> sz, depth, par, in, out, rev, branch;
  vector<T> dist;

  HeavyLightDecomposition(const Graph<T> &g, int root = 0):
      n(g.size()), root(root), g(g),
      sz(n,0), depth(n,0), par(n,0),
      in(n,0), out(n,0), rev(n,0), branch(n,0), dist(n,0) {
    int t = 0;
    dfs0(root, -1, 0);
    dfs(root, -1, t);
  }

  int la(int v, int k){
    while(1){
      int u = branch[v];
      if(in[v]-k >= in[u]) return rev[in[v] - k];
      k -= in[v] - in[u] + 1;
      v = par[u];
    }
  }

  int lca(int u, int v) const {
    for(;; v = par[branch[v]]){
      if(in[u] > in[v]) swap(u, v);
      if(branch[u] == branch[v]) return u;
    }
  }

  T get_dist(int u, int v) const {
    return dist[u] + dist[v] - 2*dist[lca(u, v)];
  }

  template<typename Q>
  void update(int u, int v, const Q &q, bool isedge = false){
    for(;; v = par[branch[v]]){
      if(in[u] > in[v]) swap(u, v);
      if(branch[u] == branch[v]) break;
      q(in[branch[v]], in[v] + 1);
    }
    q(in[u]+isedge, in[v] + 1);
  }

  template<typename Q>
  void update(int v, const Q &q, bool isedge = false){
    q(in[v]+isedge, out[v]);
  }

  template<typename U, typename Q, typename F, typename S>
  U query(int u, int v, const U &ui, const Q &q, const F &f, const S &s, bool isedge = false){
    U l = ui, r = ui;
    for(;; v = par[branch[v]]){
      if(in[u] > in[v]) swap(u, v), swap(l, r);
      if(branch[u] == branch[v]) break;
      l = f(q(in[branch[v]], in[v] + 1), l);
    }
    return s(f(q(in[u]+isedge, in[v] + 1), l), r);
  }

  template<typename U, typename Q, typename F>
  U query(int u, int v, const U &ui, const Q &q, const F &f, bool isedge = false){
    return query(u, v, ui, q, f, f, isedge);
  }

private:
  void dfs0(int v, int p, int d){
    sz[v] = 1; depth[v] = d; par[v] = p;
    if(g[v].size() && g[v].front() == p) swap(g[v].front(), g[v].back());
    for(auto&&to : g[v]){
      if(to == p) continue;
      dist[to] = dist[v] + to.cost;
      dfs0(to, v, d+1);
      sz[v] += sz[to];
      if(sz[g[v].front()] < sz[to]) swap(g[v].front(), to);
    }
  }

  void dfs(int v, int p, int &t){
    in[v] = t++; rev[in[v]] = v;
    for(auto&&to : g[v]){
      if(to == p) continue;
      if(g[v].front() == to) branch[to] = branch[v];
      else branch[to] = to;
      dfs(to, v, t);
    }
    out[v] = t;
  }
};
