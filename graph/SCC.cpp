struct SCC{
  //StronglyConnectedComponents
  int N;
  VVI G, rG;

  int group;
  VI compo, order;
  VB used;

  SCC(VVI &G):N(SZ(G)), G(G), rG(SZ(G)){
    REP(i,N){
      for(auto e : G.at(i)){
        rG.at(e).EB(i);
      }
    }
  }
  SCC(int n):N(n), G(n), rG(n){}

  int at(int k){return compo.at(k);}

  void addEdge(int u, int v){
    G.at(u).EB(v);
    rG.at(v).EB(u);
  }

  void dfs(int now){
    if(used.at(now)) return;
    used.at(now) = true;
    for(auto to : G.at(now)) dfs(to);
    //帰りがけ順で突っ込む
    order.EB(now);
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

    REP(i,N) dfs(i);
    reverse(ALL(order));
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

  VVI reconstruct(){
    VVI ret(group);
    REP(i,N){
      for(auto to : G.at(i)){
        int s = compo.at(i);
        int t = compo.at(to);
        if(s != t) ret.at(s).EB(t);
      }
    }
    for(auto&&v : ret){
      SORT(v);
      v.erase(unique(ALL(v)), v.end());
    }
    return ret;
  }

  VVI groups(){
    VVI res(group);
    REP(i,N){
      int p = compo.at(i);
      res.at(p).EB(i);
    }
    return res;
  }
};
