template<typename T>
Formalpowerseries<T> exp_sparse(const Formalpowerseries<T> &f){
  int n = int(f.size());
  if(n == 0) return {T(1)};
  assert(f[0] == T(0));

  /*
  e^f = g
  f' e^g = g'
  g' = f' g
  (i + 1) g[i + 1] x^i = sum f'[j]g[i - j]x^i
  //*/

  vector<pair<int, T>> non_zero;
  for(int i = 1; i < n; ++i)
    if(f[i] != T(0)) non_zero.emplace_back(i - 1, f[i] * i);

  Formalpowerseries<T> g(n); g[0] = 1;
  for(int i = 0; i < n - 1; ++i){
    for(const auto&[j, x] : non_zero){
      if(j > i) break;
      g[i + 1] += x * g[i - j];
    }
    g[i + 1] /= i + 1;
  }
  return g;
}
