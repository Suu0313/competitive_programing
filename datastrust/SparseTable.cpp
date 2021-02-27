template<typename T>
struct SparseTable{
  using F = function<T(T, T)>;
  const F f;
  vector<vector<T>> table;
  vector<int> lookup;
  
  SparseTable(const vector<T> &v, const F &f): f(f){
    const int n = v.size();
    const int b = 32 - __builtin_clz(n);
    table.assign(b, vector<T>(n));
    for(int i = 0; i < n; i++) table.at(0).at(i) = v.at(i);

    for(int i = 1; i < b; i++){
      for(int j = 0; j+(1<<i) <= n; j++){
        table.at(i).at(j) = f(table.at(i-1).at(j), table.at(i-1).at(j+(1<<(i-1))));
      }
    }
    lookup.assign(n+1, 0);
    for(int i = 2; i < n+1; i++){
      lookup.at(i) = lookup.at(i>>1) + 1;
    }
  }

  T fold(int l, int r) const {
    int b = lookup.at(r-l);
    return f(table.at(b).at(l), table.at(b).at(r - (1<<b)));
  }
};
