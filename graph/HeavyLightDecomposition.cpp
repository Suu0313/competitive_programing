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
  U query(int u, int v, const U &ui, const Q &q, const F &f, const S &s, bool isedge){
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

  template<typename U, typename F>
  U query(int v, const F &f, bool isedge = false){
    return f(in[v]+isedge, out[v]);
  }

private:
  void dfs0(int root){
    stack<pair<int, bool>> st;
    st.emplace(root, true);
    par[root] = -1;
    while(!st.empty()){
      auto[v, f] = st.top(); st.pop();
      if(f){
        sz[v] = 1; st.emplace(v, false);
        if(g[v].size() && g[v][0] == par[v]) swap(g[v].front(), g[v].back());
        
        for(auto&&to : g[v]){
          if(to == par[v]) continue;
          depth[to] = depth[v] + 1;
          dist[to] = dist[v] + to.cost;
          par[to] = v;
          st.emplace(to, true);
        }
      }else{
        for(auto&&to : g[v]){
          sz[v] += sz[to];
          if(sz[g[v].front()] < sz[to]) swap(g[v].front(), to);
        }
      }
    }
  }

  void dfs(int root){
    stack<pair<int, bool>> st;
    st.emplace(root, true);
    int t = 0;
    while(!st.empty()){
      auto[v, f] = st.top(); st.pop();
      if(f){
        in[v] = t++; rev[in[v]] = v;
        st.emplace(v, false);
        for(int i = (int)g[v].size()-1; i >= 0; i--){
          auto&&to = g[v][i];
          if(to == par[v]) continue;
          if(g[v].front() == to) branch[to] = branch[v];
          else branch[to] = to;
          st.emplace(to, true);
        }
      }else{
        out[v] = t;
      }
    }
  }
};
