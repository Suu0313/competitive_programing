VI TopoSort(VVI &G){
  VI ans;
  int n = SZ(G);
  VI ind(n,0);
  REP(i,n){
    for(auto e : G.at(i)){
      ind.at(e)++;
    }
  }
  queue<int> que;
  REP(i,n){
    if(ind.at(i)==0) que.push(i);
  }
  while(!que.empty()){
    int now = que.front(); que.pop();
    ans.PB(now);
    for(auto e : G.at(now)){
      ind.at(e)--;
      if(ind.at(e)==0) que.push(e);
    }
  }
  return ans;
}
