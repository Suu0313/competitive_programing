#pragma once

#include "./Matrix.cpp"

template<typename T>
int rank(Matrix<T> a){
  int n = a.height(), m = a.width();
  int y = 0;
  for(int d = 0; d < m; ++d){
    int pv = -1;
    for(int i = y; i < n; ++i){ if(g[i][d] != 0){ pv = i; break; }}
    if(pv == -1){ continue; }
    if(y != pv) swap(g[y], g[pv]);

    T inv = T(1) / g[y][d];
    for(int j = d; j < m; ++j) g[y][j] *= inv;
    for(int i = 0; i < n; ++i){
      if(i == y) continue;
      T fac = g[i][d];
      for(int j = d; j < m; ++j) g[i][j] -= g[y][j] * fac;
    }
    ++y;
  }
  return y;
}
