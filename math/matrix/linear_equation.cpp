#pragma once

#include ".\\Matrix.cpp"

template<typename T>
pair<vector<T>, Matrix<T>> linear_equation(const Matrix<T> &a, const vector<T> &b){
  int n = a.height(), m = a.width();
  Matrix<T> g(n, m + 1);
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j) g[i][j] = a[i][j];
  for(int i = 0; i < n; ++i) g[i][m] = b[i];

  int y = 0;
  vector<int> rs;
  vector<pair<int, int>> ps;

  for(int d = 0; d < m; ++d){
    int pv = -1;
    for(int i = y; i < n; ++i){ if(g[i][d] != 0){ pv = i; break; }}
    if(pv == -1){ rs.push_back(d); continue; }
    if(y != pv) swap(g[y], g[pv]);

    T inv = T(1) / g[y][d];
    for(int j = d; j <= m; ++j) g[y][j] *= inv;
    for(int i = 0; i < n; ++i){
      if(i == y) continue;
      T fac = g[i][d];
      for(int j = d; j <= m; ++j) g[i][j] -= g[y][j] * fac;
    }
    ps.emplace_back(y, d);
    ++y;
  }
  for(int i = y; i < n; ++i) if(g[i][m] != 0) return {vector<T>{}, Matrix<T>{}};
  
  int r = int(rs.size());
  vector<T> res(m);
  Matrix<T> basis(r, m);

  for(auto&[i, j] : ps) res[j] = g[i][m];

  for(int d = 0; d < r; ++d){
    int s = rs[d];
    basis[d][s] = 1;
    for(auto&[i, j] : ps) basis[d][j] = -g[i][s];
  }

  return {res, basis};
}
