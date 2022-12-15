template<typename T>
vector<T> mulinv_sparse(vector<T> f, vector<pair<int, T>> g, int d){
  assert(!g.empty());
  auto[p, c] = g[0];
  assert(p == 0 && c != T(0));
  T c_inv = c.inverse();

  g.erase(begin(g));

  f.resize(d);
  f[0] *= c_inv;

  for(int i = 1; i < d; ++i){
    for(const auto&[j, x] : g){
      if(j > i) break;
      f[i] -= x * f[i - j];
    }
    f[i] *= c_inv;
  }
  return f;
}

template<typename T>
vector<T> mulinv_sparse(const vector<T> &f, const vector<T> &g, int n){
  vector<pair<int, T>> xs;
  for(int i = 0, m = int(g.size()); i < m; ++i){
    if(g[i] != T(0)) xs.emplace_back(i, g[i]);
  }
  return mulinv_sparse(f, xs, n);
}
