template<typename T>
Matrix<T> inverse(Matrix<T> a){
  int n = a.height(), m = a.width();
  assert(n == m);
  Matrix<T> g(n, m*2);
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j) g[i][j] = a[i][j];
    g[i][i + n] = 1;
  }
  
  int y = 0;
  for(int d = 0; d < m; ++d){
    int pv = -1;
    for(int i = y; i < n; ++i){ if(g[i][d] != 0){ pv = i; break; }}
    if(pv == -1) return {}; 
    if(y != pv) swap(g[y], g[pv]);

    T inv = T(1) / g[y][d];
    for(int j = d; j < m*2; ++j) g[y][j] *= inv;
    for(int i = 0; i < n; ++i){
      if(i == y) continue;
      T fac = g[i][d];
      for(int j = d; j < m*2; ++j) g[i][j] -= g[y][j] * fac;
    }
    ++y;
  }
  
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j) a[i][j] = g[i][j + n];
  }

  return a;
}
