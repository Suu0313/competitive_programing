struct UndoUF {
  vector<int> par, siz;
  stack<pair<int,int>> hist;
  
  UndoUF() {}
  UndoUF(int n): par(n,-1),siz(n,1) {
    iota(ALL(par),0);
  }
  void init(int n){
    par.resize(n);
    iota(ALL(par),0);
    siz.assign(n,1);
  }

  int find(int x) {
    if(par[x] == x){
      return x;
    }else{
      return find(par[x]);
    }
  }

  bool unite(int x, int y){
    x = find(x);
    y = find(y);
    hist.emplace(x,par[x]);
    hist.emplace(y,par[y]);
    if(x == y) return false;

    if(siz[x] < siz[y]){
      swap(x,y);
    }
    siz[x] += siz[y];
    par[y] = x;
    return true;
  }

  bool same(int x, int y){
    return find(x) == find(y);
  }

  int size(int x){
    return siz[find(x)];
  }

  bool undo(){
    if(hist.empty()) return false;
    REP(i,2){
      auto[x,px] = hist.top();
      par[x] = px;
      hist.pop();
    }
    return true;
  }

  void clear(){
    while(!hist.empty()) hist.pop();
  }
  
  void rollback(){
    while(!hist.empty()) undo();
  }
};