#pragma once

struct StronglyConnectedComponents{
  int N;
  vector<vector<int>> G, rG;

  int group;
  vector<int> compo, order;
  vector<bool> used;

  template<typename T>
  StronglyConnectedComponents(const T &g, bool cal = true):N(g.size()), G(N), rG(N){
    for(int i = 0; i < N; i++){
      for(auto&&e : g[i]){
        G[i].emplace_back(e.to);
        rG[e.to].emplace_back(i);
      }
    }
    if(cal) build();
  }
  StronglyConnectedComponents(int n):N(n), G(n), rG(n){}

  int at(int k){return compo.at(k);}

  void add_edge(int u, int v){
    G[u].emplace_back(v);
    rG[v].emplace_back(u);
  }

  void build(){
    compo.assign(N,-1);
    used.assign(N,false);
    order.clear(); order.reserve(N);
    group = 0;

    for(int i = 0; i < N; i++) dfs(i);
    reverse(order.begin(), order.end());
    for(auto&&e : order){
      if(compo.at(e) == -1){
        rdfs(e,group);
        group++;
      }
    }
  }

  bool issame(int u, int v){
    return compo.at(u) == compo.at(v);
  }

  vector<vector<int>> reconstruct(){
    vector<vector<int>> ret(group);
    for(int i = 0; i < N; i++){
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

  vector<vector<int>> groups(){
    vector<vector<int>> res(group);
    for(int i = 0; i < N; i++){
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
      if(v < N){
        if(used[v]) continue;
        used[v] = true;

        st.emplace(v + N);
        for(auto&&e : G[v]){
          if(used[e]) continue;
          st.emplace(e);
        }
      }else{
        order.emplace_back(v - N);
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
