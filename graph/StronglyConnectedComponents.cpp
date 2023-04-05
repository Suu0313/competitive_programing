#pragma once

struct StronglyConnectedComponents{
  int n;
  vector<vector<int>> G, rG;

  int group;
  vector<int> compo, order;
  vector<bool> used;

  template<typename T>
  StronglyConnectedComponents(const T &g, bool cal = true):n(g.size()), G(n), rG(n){
    for(int i = 0; i < n; i++){
      for(auto&&e : g[i]){
        G[i].emplace_back(e.to);
        rG[e.to].emplace_back(i);
      }
    }
    if(cal) build();
  }
  StronglyConnectedComponents(int n):n(n), G(n), rG(n){}

  int at(int k) const { return compo.at(k); }
  int operator[](int k) const { return compo.at(k); }

  void add_edge(int u, int v){
    G[u].emplace_back(v);
    rG[v].emplace_back(u);
  }

  void build(){
    compo.assign(n,-1);
    used.assign(n,false);
    order.clear(); order.reserve(n);
    group = 0;

    for(int i = 0; i < n; i++) dfs(i);
    reverse(order.begin(), order.end());
    for(auto&&e : order){
      if(compo.at(e) == -1){
        rdfs(e,group);
        group++;
      }
    }
  }

  bool is_same(int u, int v) const { return compo.at(u) == compo.at(v); }

  vector<vector<int>> reconstruct() const {
    vector<vector<int>> ret(group);
    for(int i = 0; i < n; i++){
      for(auto to : G.at(i)){
        int s = compo.at(i);
        int t = compo.at(to);
        if(s != t) ret.at(s).emplace_back(t);
      }
    }
    for(auto&&v : ret){
      sort(v.begin(), v.end());
      v.erase(unique(v.begin(), v.end()), v.end());
    }
    return ret;
  }

  vector<vector<int>> groups() const {
    vector<vector<int>> res(group);
    for(int i = 0; i < n; i++){
      int p = compo.at(i);
      res.at(p).emplace_back(i);
    }
    return res;
  }

private:
  void dfs(int now){
    if(used[now]) return;

    stack<int> st;
    st.emplace(now);

    while(!st.empty()){
      auto v = st.top(); st.pop();
      if(v < n){
        if(used[v]) continue;
        used[v] = true;

        st.emplace(v + n);
        for(auto&&e : G[v]){
          if(used[e]) continue;
          st.emplace(e);
        }
      }else{
        order.emplace_back(v - n);
      }
    }
  }

  void rdfs(int now, int cnt){
    if(compo.at(now) != -1) return;
    compo.at(now) = cnt;

    stack<int> st; st.push(now);
    while(!st.empty()){
      auto v = st.top(); st.pop();

      for(auto&&e : rG[v]){
        if(compo[e] != -1) continue;
        compo[e] = cnt;
        st.push(e);
      }
    }
  }
};
