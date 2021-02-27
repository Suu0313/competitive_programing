struct UnionFind {
  
  vector<int> par, siz;
  int cnt,n,smax;
  
  UnionFind() {}
  
  UnionFind(int n_):par(n_), siz(n_,1),cnt(n_),n(n_),smax(1) {
    iota(ALL(par),0);
  }
  
  void init(int n_) {
    par.assign(n_,0);
    siz.assign(n_,1);
    iota(ALL(par),0);
    cnt = n_;
    n = n_;
    smax = 1;
  }
  
  int find(int x) {
    if(par[x] == x){
      return x;
    }else{
      return par[x] = find(par[x]);
    }
  }

  bool unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return false;
    cnt--;

    if(siz[x] < siz[y]){
      swap(x,y);
    }
    siz[x] += siz[y];
    chmax(smax, siz[x]);
    par[y] = x;
    return true;
  }

  bool same(int x, int y){
    return find(x) == find(y);
  }
  
  int size(int x){
    return siz[find(x)];
  }


  vector<vector<int>> groups() {
    vector<int> leader_buf(n), group_size(n);
    for(int i=0; i<n; i++){
      leader_buf.at(i) = find(i);
      group_size.at(leader_buf.at(i))++;
    }
    vector<vector<int>> result(n);
    for(int i=0; i<n; i++){
      result.at(i).reserve(group_size.at(i));
    }
    for(int i=0; i<n; i++){
      result.at(leader_buf.at(i)).EB(i);
    }
    result.erase(
      remove_if(
        ALL(result),
        [&](const vector<int>& v) { return v.empty(); }
      ),
      result.end()
    );
    return result;
  }

};
