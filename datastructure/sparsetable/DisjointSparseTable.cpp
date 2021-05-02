template<typename T>
struct DisjointSparseTable{
  using F = function<T(T, T)>;
  F f;
  vector<vector<T>> table;
  vector<int> lookup;
  
  DisjointSparseTable() {}
  DisjointSparseTable(const vector<T> &v, const F &f): f(f){
    const int n = v.size();
    const int b = 32 - __builtin_clz(n);
    table.assign(b, vector<T>(n));
    for(int i = 0; i < n; i++) table.at(0).at(i) = v.at(i);

    for(int i = 1; i < b; i++){
      int shift = 1 << i;
      for(int j = 0; j < n; j += shift << 1){
        int t = min(j+shift, n);
        table.at(i).at(t-1) = v.at(t-1);
        for(int k = t-2; k >= j; k--) table.at(i).at(k) = f(v.at(k), table.at(i).at(k+1));
        if(n <= t) break;
        table.at(i).at(t) = v.at(t);
        int r = min(t+shift, n);
        for(int k = t+1; k < r; k++) table.at(i).at(k) = f(table.at(i).at(k-1), v.at(k));
      }
    }
    lookup.assign(1 << b, 0);
    for(int i = 2; i < (1 << b); i++){
      lookup.at(i) = lookup.at(i>>1) + 1;
    }
  }

  T query(int l, int r) const {
    if(l >= --r) return table.at(0).at(l);
    int p = lookup.at(l ^ r);
    return f(table.at(p).at(l), table.at(p).at(r));
  }
};