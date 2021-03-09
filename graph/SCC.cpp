struct SCC{
  //  StronglyConnectedComponents
  int N;
  vector<vector<int>> G, rG;

  int group;
  vector<int> compo, order;
  vector<bool> used;

  SCC(vector<vector<int>> &G):N(G.size()), G(N), rG(N){
    for(int i = 0; i < N; i++){
      for(auto e : G.at(i)){
        rG.at(e).EB(i);
      }
    }
  }
  SCC(int n):N(n), G(n), rG(n){}

  int at(int k){return compo.at(k);}

  void addEdge(int u, int v){
    G.at(u).emplace_back(v);
    rG.at(v).emplace_back(u);
  }

  void dfs(int now){
    if(used.at(now)) return;
    used.at(now) = true;
    for(auto to : G.at(now)) dfs(to);
    //  帰りがけ順で突っ込む
    order.emplace_back(now);
  }
  void rdfs(int now, int cnt){
    if(compo.at(now) != -1) return;
    compo.at(now) = cnt;
    for(auto to : rG.at(now)) rdfs(to, cnt);
  }

  void build(){
    compo.assign(N,-1);
    used.assign(N,false);
    order.clear();
    group = 0;

    for(int i = 0; i < N; i++) dfs(i);
    reverse(order.begin(), order.end());
    for(auto e : order){
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
};
