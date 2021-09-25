struct TwoSat{
  int n;
  StronglyConnectedComponents scc;
  inline int rev(int x){
    if(x >= n) return x - n;
    else return x + n;
  }

  TwoSat(int n):n(n), scc(n*2){}

  void add_or(int u, int v, bool f=true, bool g=true){
    if(!f) u = rev(u);
    if(!g) v = rev(v);
    scc.addEdge(rev(u), v);
    scc.addEdge(rev(v), u);
  }

  void add_nand(int u, int v, bool f=true, bool g=true){
    if(!f) u = rev(u);
    if(!g) v = rev(v);
    scc.addEdge(u, rev(v));
    scc.addEdge(v, rev(u));
  }

  void add_one(int u, bool f=true){
    if(!f) u = rev(u);
    scc.addEdge(rev(u),u);
  }

  void add_if_then(int u, int v, bool f=true, bool g=true){
    add_or(u, v, !f, g);
  }

  vector<int> answer(){
    scc.build();
    vector<int> res(n);
    for(int i = 0; i < n; i++){
      if(scc.issame(i,rev(i))) return {};
      res.at(i) = scc.at(i) > scc.at(rev(i));
    }
    return res;
  }
};
