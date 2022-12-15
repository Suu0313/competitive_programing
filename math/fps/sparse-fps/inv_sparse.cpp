template<typename T>
vector<T> inv_sparse(vector<pair<int, T>> f, int n){
  assert(!f.empty());
  auto[p, c] = f[0];
  assert(p == 0 && c != T(0));

  T c_inv = c.inverse();
  f.erase(begin(f));

  vector<T> g(n); g[0] = c_inv;
  for(int i = 1; i < n; ++i){
    for(const auto&[j, x] : f){
      if(j > i) break;
      g[i] -= x * g[i - j];
    }
    g[i] *= c_inv;
  }
  return g;
}

template<typename T>
vector<T> inv_sparse(const vector<T> &f, int n = -1){
  if(n == -1) n = int(f.size());
  vector<pair<int, T>> xs;
  for(int i = 0, m = int(f.size()); i < m; ++i){
    if(f[i] != T(0)) xs.emplace_back(i, f[i]);
  }
  return inv_sparse(xs, n);
}
