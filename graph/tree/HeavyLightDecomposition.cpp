template<typename T = int>
struct HeavyLightDecomposition{
  int n;
  Graph<T> g;
  vector<int> sz, depth, par, in, out, rev, branch;
  vector<T> dist;

  HeavyLightDecomposition(const Graph<T> &g, int root = 0):
      n(g.size()), g(g),
      sz(n,0), depth(n,0), par(n,0),
      in(n,0), out(n,0), rev(n,0), branch(n,0), dist(n,0) {
    dfs0(root); dfs(root);
  }

  int level_ancestor(int v, int k) const {
    if(depth[v] < k) return -1;
    while(1){
      int u = branch[v];
      if(in[v]-k >= in[u]) return rev[in[v] - k];
      k -= in[v] - in[u] + 1;
      v = par[u];
    }
  }

  int jump(int u, int v, int k) const {
    int p = lca(u, v);
    if(depth[u] + depth[v] - 2*depth[p] < k) return -1;
    if(depth[u] - depth[p] >= k) return level_ancestor(u, k);
    k -= depth[u] - depth[p];
    return level_ancestor(v, depth[v] - depth[p] - k);
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

  bool cmp_in(int u, int v) const {
    return in[u] < in[v];
  }

  vector<pair<int, int>> auxiliary(vector<int> vs) const {
    auto cmp = [&](int u, int v){ return in[u] < in[v]; };
    sort(vs.begin(), vs.end(), cmp);
    vs.erase(unique(vs.begin(), vs.end()), vs.end());
    int k = vs.size();
    for(int i = 1; i < k; i++) vs.emplace_back(lca(vs[i-1], vs[i]));
    sort(vs.begin(), vs.end(), cmp);
    vs.erase(unique(vs.begin(), vs.end()), vs.end());
    vector<pair<int, int>> es;
    stack<int> st;
    for(auto&&v : vs){
      while(!st.empty() && out[st.top()] <= in[v]) st.pop();
      if(!st.empty()) es.emplace_back(st.top(), v);
      st.emplace(v);
    }
    return es;
  }

  int to_vertex(int k) const { return rev[k]; }

  int to_idx(int v) const { return in[v]; }


  int to_idx(int u, int v) const {
    if(in[u] > in[v]) swap(u, v);
    assert(par[v] == u);
    return in[v];
  }
  
  template<typename Q>
  void update_vertex(int v, const Q &q) const { q(in[v]); }

  template<typename Q>
  void update_edge(int u, int v, const Q &q) const {
    if(in[u] > in[v]) swap(u, v);
    assert(par[v] == u);
    q(in[v]);
  }

  template<typename Q>
  void update_subtree(int v, const Q &q, bool isedge = false) const {
    q(in[v]+isedge, out[v]);
  }

  template<typename Q>
  void update_path(int u, int v, const Q &q, bool isedge = false) const {
    for(;; v = par[branch[v]]){
      if(in[u] > in[v]) swap(u, v);
      if(branch[u] == branch[v]) break;
      q(in[branch[v]], in[v] + 1);
    }
    q(in[u]+isedge, in[v] + 1);
  }

  vector<pair<int,int>> get_segments(int u, int v, bool isedge = false) const {
    vector<pair<int,int>> l, r;
    while(branch[u] != branch[v]){
      if(in[u] > in[v]) l.emplace_back(in[u]+1, in[branch[u]]), u=par[branch[u]];
      else r.emplace_back(in[branch[v]], in[v]+1), v=par[branch[v]];
    }
    if(in[u] > in[v])  l.emplace_back(in[u]+1, in[v]+isedge);
    else r.emplace_back(in[u]+isedge, in[v]+1);
    reverse(begin(r), end(r));
    for(auto&e : r) l.push_back(e);
    return l;
  }

  template<typename M, typename F>
  M query_path(int u, int v, const F &get_val, bool isedge = false) const {
    M l{}, r{};
    for(;; v = par[branch[v]]){
      if(in[u] > in[v]) swap(u, v), swap(l, r);
      if(branch[u] == branch[v]) break;
      l += get_val(in[branch[v]], in[v] + 1);
    }
    return get_val(in[u]+isedge, in[v] + 1) + l + r;
  }

  template<typename U, typename F>
  U query_subtree(int v, const F &f, bool isedge = false) const {
    return f(in[v]+isedge, out[v]);
  }

  template<typename M, typename F1, typename F2>
  M query_path(int u, int v, const F1 &get_val1, const F2 &get_val2, bool isedge) const {
    M res{};
    for(auto&[a, b] : get_segments(u, v, isedge)){
      if(a > b) res += get_val2(b, a);
      else res += get_val1(a, b);
    }
    return res;
  }

private:
  void dfs0(int root){
    stack<int> st;
    st.emplace(root);
    par[root] = -1;
    while(!st.empty()){
      auto v = st.top(); st.pop();
      if(v < n){
        sz[v] = 1; st.emplace(v + n);
        if(g[v].size() && g[v][0] == par[v]) swap(g[v].front(), g[v].back());
        
        for(auto&&to : g[v]){
          if(to == par[v]) continue;
          depth[to] = depth[v] + 1;
          dist[to] = dist[v] + to.cost;
          par[to] = v;
          st.emplace(to);
        }
      }else{
        v -= n;
        for(auto&&to : g[v]){
          sz[v] += sz[to];
          if(sz[g[v].front()] < sz[to]) swap(g[v].front(), to);
        }
      }
    }
  }

  void dfs(int root){
    stack<int> st;
    st.emplace(root);
    int t = 0;
    while(!st.empty()){
      auto v = st.top(); st.pop();
      if(v < n){
        in[v] = t++; rev[in[v]] = v;
        st.emplace(v + n);
        for(int i = (int)g[v].size()-1; i >= 0; i--){
          auto&&to = g[v][i];
          if(to == par[v]) continue;
          if(g[v].front() == to) branch[to] = branch[v];
          else branch[to] = to;
          st.emplace(to);
        }
      }else{
        out[v - n] = t;
      }
    }
  }
};
