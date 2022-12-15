template<typename T>
vector<T> sqrt_sparse(vector<pair<int, T>> f, const function< T(T) > &get_sqrt, int n){

  if(f.empty()) return vector<T>(n);
  int d = f[0].first, offset = d >> 1;
  if(d & 1) return {};

  T c = f[0].second, c_inv = c.inverse(), inv2 = T(2).inverse();
  T sc = get_sqrt(c);
  if(sc * sc != c) return {};
  for(auto&[i, x] : f) i -= d, x *= c_inv;
  f.erase(begin(f));

  int mod = T::get_mod();
  vector<T> g(n - offset), inv(n - offset, 1); g[0] = 1;
  for(int i = 0; i < n - offset - 1; ++i){
    for(auto&[j, x] : f){
      if(j > i + 1) break;
      g[i + 1] += x * g[i - j + 1] * (inv2 * j - (i - j + 1));
    }
    if(i > 0) inv[i + 1] = -inv[mod%(i + 1)] * (mod/(i + 1));
    g[i + 1] *= inv[i + 1];
  }
  for(auto &e : g) e *= sc;
  g.resize(n); rotate(begin(g), begin(g) + n - offset, end(g));
  return g;
}

template<typename T>
vector<T> sqrt_sparse(const vector<T> &f, const function< T(T) > &get_sqrt, int n = -1){
  if(n == -1) n = int(f.size());
  vector<pair<int, T>> xs;
  for(int i = 0, m = int(f.size()); i < m; ++i){
    if(f[i] != T(0)) xs.emplace_back(i, f[i]);
  }
  return sqrt_sparse(xs, get_sqrt, n);
}
