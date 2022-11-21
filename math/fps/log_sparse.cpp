template<typename T>
Formalpowerseries<T> log_sparse(const Formalpowerseries<T> &f){
  int n = int(f.size());
  assert(f[0] == T(1));

  /*
  log f = g
  f'/f = g'
  fg' = f'
  //*/

  vector<pair<int, T>> non_zero;
  for(int i = 1; i < n; ++i)
    if(f[i] != T(0)) non_zero.emplace_back(i, f[i]);

  Formalpowerseries<T> g(n - 1);
  for(int i = 0; i < n - 1; ++i){
    g[i] = f[i + 1] * (i + 1);
    for(const auto&[j, x] : non_zero){
      if(j > i) break;
      g[i] -= x * g[i - j];
    }
  }
  return g.integral();
}
