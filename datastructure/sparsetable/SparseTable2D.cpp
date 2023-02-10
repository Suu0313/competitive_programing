#pragma once


template<typename T>
struct SparseTable2D{
  using F = function<T(T, T)>;
  const F f;
  vector<vector<vector<vector<T>>>> table;
  vector<int> lookup;

  SparseTable2D(const vector<vector<T>> &v, const F &f): f(f){
    const int n = v.size(), m = v[0].size();
    const int nb = 32 - __builtin_clz(n), mb = 32 - __builtin_clz(m);
    table.assign(nb, vector(n, vector(mb, vector<T>(m))));
    for(int rj = 0; rj < n; rj++){

      for(int cj = 0; cj < m; cj++) table[0][rj][0][cj] = v[rj][cj];

      for(int ci = 1; ci < mb; ci++){
        for(int cj = 0; cj+(1<<ci) <= m; cj++){
          table[0][rj][ci][cj]
            = f(table[0][rj][ci-1][cj], table[0][rj][ci-1][cj+(1<<(ci-1))]);
        }
      }
    }

    for(int ri = 1; ri <= nb; ri++){
      for(int rj = 0; rj+(1<<ri) <= n; rj++){
        for(int ci = 0; ci < mb; ci++){
          for(int cj = 0; cj < m; cj++){
            table[ri][rj][ci][cj]
              = f(table[ri-1][rj][ci][cj], table[ri-1][rj+(1<<(ri-1))][ci][cj]);
          }
        }
      }
    }

    int l = max(n, m);
    lookup.assign(l+1, 0);
    for(int i = 2; i < l+1; i++){
      lookup[i] = lookup[i>>1] + 1;
    }
  }

  T fold(int x1, int x2, int y1, int y2) const {
    int nb = lookup[x2 - x1], mb = lookup[y2 - y1];
    T R1 = f(table[nb][x1][mb][y1], table[nb][x1][mb][y2 - (1<<mb)]);
    T R2 = f(table[nb][x2 - (1<<nb)][mb][y1], table[nb][x2 - (1<<nb)][mb][y2 - (1<<mb)]);
    return f(R1, R2);
  }
};
