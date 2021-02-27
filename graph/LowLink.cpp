struct LowLink{
  VVI G;
  VB used;
  VI ord, low;
  VI aps;
  VPII bridges;
  LowLink(VVI &G_) : G(G_){
    int N = SZ(G);
    used.assign(N,false);
    ord.assign(N,0);
    low.assign(N,0);
    int k = 0;
    REP(i,N){
      if(!used.at(i)) k = dfs(i, k, -1);
    }
    SORT(aps);
    SORT(bridges);
  }

  int dfs(int id, int k, int par){
    used.at(id) = true;
    ord.at(id) = k++;
    low.at(id) = ord.at(id);
    bool isAps = false;
    int cnt = 0;
    for(auto e : G.at(id)){
      if(!used.at(e)) {
        cnt++;
        k = dfs(e,k,id);
        chmin(low.at(id),low.at(e));
        if(par != -1 && ord.at(id)<=low.at(e)) isAps = true;
        if(ord.at(id) < low.at(e)) bridges.EB(min(id,e),max(id,e));
      }else if(e != par) {
        chmin(low.at(id),ord.at(e));
      }
    }
    if(par == -1 && cnt >= 2) isAps = true;
    if(isAps) aps.EB(id);
    return k;
  
  }
};
