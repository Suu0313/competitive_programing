struct PartiallyPersistentUF {
  vector<int> par, siz, last;
  int now;
  vector<vector<pair<int,int>>> hist;
  
  PartiallyPersistentUF() {}
  PartiallyPersistentUF(int n): par(n,-1),siz(n,1),last(n,INF),now(0) {
    iota(ALL(par),0);
    hist.assign(n,vector<pair<int,int>>(1,{0,1}));
  }
  void init(int n){
    par.resize(n);
    iota(ALL(par),0);
    siz.assign(n,1);
    last.assign(n,INF);
    now = 0;
    hist.assign(n,VPII(1,{0,1}));
  }

  int find(int t,int x) {
    while(last.at(x)<=t) x = par.at(x);
    return x;
  }

  pair<bool,int> unite(int x, int y){
    x = find(now, x);
    y = find(now, y);
    now++;
    if(x == y) return {false,now-1};

    if(siz[x] < siz[y]){
      swap(x,y);
    }
    siz[x] += siz[y];
    par[y] = x;
    last[y] = now;
    hist.at(x).EB(now, siz[x]);
    return {true, now-1};
  }

  bool same(int t, int x, int y){
    return find(t, x) == find(t, y);
  }

  int size(int t, int x){
    x = find(t, x);
    return prev(partition_point(
      ALL(hist.at(x)),
      [t](PII &h){ return h.FI<=t;})
      )->SE;
  }
};
