template<typename T>
vector<T> log_sparse(vector<pair<int, T>> f, int n){
  if(n == 0) return {};
  assert(!f.empty());
  auto[p, c] = f[0];
  assert(p == 0 && c == T(1));

  f.erase(begin(f));

  vector<T> g(n - 1), inv(n, 1);
  int mod = T::get_mod();

  auto it = begin(f);

  for(int i = 0; i < n - 1; ++i){
    while(it != end(f) && it->first < i + 1) ++it;
    if(it != end(f) && it->first == i + 1){
      g[i] = (it->second) * (i + 1);
    }
    for(const auto&[j, x] : f){
      if(j > i) break;
      g[i] -= x * g[i - j];
    }
  }

  g.insert(begin(g), 0);

  for(int i = 2; i < n; ++i) g[i] *= (inv[i] = -inv[mod%i] * (mod/i));

  return g;
}


template<typename T>
vector<T> log_sparse(const vector<T> &f, int n = -1){
  if(n == -1) n = int(f.size());
  vector<pair<int, T>> xs;
  for(int i = 0, m = int(f.size()); i < m; ++i){
    if(f[i] != T(0)) xs.emplace_back(i, f[i]);
  }
  return log_sparse(xs, n);
}
