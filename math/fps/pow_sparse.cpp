template<typename T>
vector<T> pow_sparse(vector<pair<int, T>> f, int64_t k, int n){
  if(f.empty()){
    vector<T> g(n);
    if(k == 0 && n != 0) g[0] = 1;
    return g;
  }
  int d = f[0].first;
  if(k < 0) assert(d == 0);
  if(k > 0 && d >= (n + k - 1) / k) return vector<T>(n);
  int offset = d * k; assert(offset < n);
  
  T c = f[0].second, c_inv = c.inverse();
  int mod = T::get_mod();
  for(auto&[i, x] : f) i -= d, x *= c_inv;
  f.erase(begin(f));

  vector<T> g(n - offset), inv(n - offset, 1); g[0] = 1;
  for(int i = 0; i < n - offset - 1; ++i){
    for(auto&[j, x] : f){
      if(j > i + 1) break;
      g[i + 1] += x * g[i - j + 1] * (T(k) * j - (i - j + 1));
    }
    if(i > 0) inv[i + 1] = -inv[mod%(i + 1)] * (mod/(i + 1));
    g[i + 1] *= inv[i + 1];
  }

  T cp = (k >= 0 ? c.pow(k) : c_inv.pow(-k));
  for(auto &e : g) e *= cp;
  g.resize(n); rotate(begin(g), begin(g) + n - offset, end(g));
  return g;
}


template<typename T>
vector<T> pow_sparse(const vector<T> &f, int64_t k, int n = -1){
  if(n == -1) n = int(f.size());
  vector<pair<int, T>> xs;
  for(int i = 0, m = int(f.size()); i < m; ++i){
    if(f[i] != T(0)) xs.emplace_back(i, f[i]);
  }
  return pow_sparse(xs, k, n);
}
