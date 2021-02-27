template<typename T>
struct DataUF {
  
  vector<int> par, siz;
  int cnt,n,smax;
  vector<T> node;
  const T e;
  using F = function<void(T&,T&)>;
  const F f;
  
  DataUF() {}
  
  DataUF(int n_, T e, F f):par(n_), siz(n_,1),cnt(n_),n(n_),smax(1),node(n_,e),e(e),f(f) {
    iota(par.begin(),par.end(),0);
  }

  T& at(int k){
    return node.at(k);
  }
  
  int find(int x) {
    if(par[x] == x){
      return x;
    }else{
      return par[x] = find(par[x]);
    }
  }

  void set(int k, T t){
    node.at(k) = t;
  }


  bool unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return false;
    cnt--;

    if(siz[x] < siz[y]){
      swap(x,y);
    }
    f(node.at(x),node.at(y));
    siz[x] += siz[y];
    smax = max(smax, siz[x]);
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
    for(int i = 0; i < n; i++){
      leader_buf.at(i) = find(i);
      group_size.at(leader_buf.at(i))++;
    }
    vector<vector<int>> result(n);
    for(int i = 0; i < n; i++){
      result.at(i).reserve(group_size.at(i));
    }
    for(int i = 0; i < n; i++){
      result.at(leader_buf.at(i)).EB(i);
    }
    result.erase(
      remove_if(
        result.begin(),
        result.end(),
        [&](const VI& v) { return v.empty(); }
      ),
      result.end()
    );
    return result;
  }
};
