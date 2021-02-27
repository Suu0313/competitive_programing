struct PotentializedUF {
  
  vector<int> par, siz;
  vector<int> diff_weight;
  
  PotentializedUF() {}
  
  PotentializedUF(int n):par(n), siz(n,1), diff_weight(n,0) {
    iota(ALL(par),0);
  }
  
  void init(int n) {
    
    par.assign(n,0);
    siz.assign(n,1);
    diff_weight.assign(n,0);
    iota(ALL(par),0);
  }
  
  
  int find(int x) {
    if(par[x] == x){
      return x;
    }else{
      int r = find(par[x]);
      diff_weight[x] += diff_weight[par[x]];
      return par[x] = r;
    }
  }

  void unite(int x, int y, int w){
    w += weight(x); w -= weight(y);
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(siz[x] < siz[y]){
      swap(x,y); w = -w;
    }
    siz[x] += siz[y];
    par[y] = x;
    diff_weight[y] = w;
  }

  int weight(int x){
    find(x);
    return diff_weight[x];
  }

  int diff(int x, int y){
    if(same(x,y)){
      return weight(y) - weight(x);
    }
    return -1;
  }

  bool same(int x, int y){
    return find(x) == find(y);
  }
  
  int size(int x){
    return siz[find(x)];
  }

};