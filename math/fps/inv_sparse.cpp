template<typename T>
Formalpowerseries<T> inv_sparse(const Formalpowerseries<T> &f){
  int n = int(f.size());
  assert(f[0] != T(0));

  vector<pair<int, T>> non_zero;

  for(int i = 1; i < n; ++i)
    if(f[i] != T(0)) non_zero.emplace_back(i, f[i]);

  T c_inv = f[0].inverse();

  Formalpowerseries<T> g(n); g[0] = c_inv;
  for(int i = 1; i < n; ++i){
    for(const auto&[j, x] : non_zero){
      if(j > i) break;
      g[i] -= x * g[i - j];
    }
    g[i] *= c_inv;
  }
  return g;
}
