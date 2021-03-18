template<typename T>
struct DisjointSparseTable2D{
  using F = function<T(T, T)>;
  const F f;
  vector<vector<vector<vector<T>>>> table;
  vector<int> lookup;

  DisjointSparseTable2D(const vector<vector<T>> &v, const F &f): f(f){
    const int n = v.size(), m = v[0].size();
    const int nb = 32 - __builtin_clz(n), mb = 32 - __builtin_clz(m);
    table.assign(nb, vector(n, vector(mb, vector<T>(m))));
    for(int rj = 0; rj < n; rj++){

      for(int cj = 0; cj < m; cj++) table[0][rj][0][cj] = v[rj][cj];

      for(int ci = 1; ci < mb; ci++){
        int shift = 1 << ci;
        for(int cj = 0; cj < n; cj += shift << 1){
          int t = min(cj+shift, m);
          table[0][rj][ci][t-1] = v[rj][t-1];
          for(int k = t-2; k >= cj; k--){
            table[0][rj][ci][k] = f(v[rj][k], table[0][rj][ci][k+1]);
          }
          if(m <= t) break;
          table[0][rj][ci][t] = v[rj][t];
          int r = min(t+shift, m);
          for(int k = t+1; k < r; k++){
            table[0][rj][ci][k] = f(table[0][rj][ci][k-1], v[rj][k]);
          }
        }
      }
    }

    for(int ri = 1; ri < nb; ri++){
      int rshift = 1 << ri;
      for(int rj = 0; rj < n; rj += rshift << 1){
        int rt = min(rj+rshift, n);
        for(int ci = 0; ci < mb; ci++){
          for(int cj = 0; cj < m; cj++){
            table[ri][rt-1][ci][cj] = table[0][rt-1][ci][cj];
            for(int k = rt-2; k >= rj; k--){
              table[ri][k][ci][cj] = f(table[0][k][ci][cj], table[ri][k+1][ci][cj]);
            }
            if(n <= rt) break;
            table[ri][rt][ci][cj] = table[0][rt][ci][cj];
            int r = min(rt+rshift, n);
            for(int k = rt+1; k < r; k++){
              table[ri][k][ci][cj] = f(table[ri][k-1][ci][cj], table[0][k][ci][cj]);
            }
          }
        }
      }
    }
    const int b = max(nb, mb);
    lookup.assign(1 << b, 0);
    for(int i = 2; i < (1 << b); i++){
      lookup.at(i) = lookup.at(i>>1) + 1;
    }
  }

  T query(int x1, int x2, int y1, int y2) const {
    x2--; y2--;
    if(x1 >= x2){
      if(y1 >= y2) return table[0][x1][0][y1];
      int p = lookup[y1 ^ y2];
      return f(table[0][x1][p][y1], table[0][x1][p][y2]);
    }
    int np = lookup[x1 ^ x2];
    if(y1 >= y2) return f(table[np][x1][0][y1], table[np][x2][0][y1]);
    int mp = lookup[y1 ^ y2];
    T R1 = f(table[np][x1][mp][y1], table[np][x1][mp][y2]);
    T R2 = f(table[np][x2][mp][y1], table[np][x2][mp][y2]);
    return f(R1, R2);
  }
};
