template<typename T>
Formalpowerseries<T> pow_sparse(const Formalpowerseries<T> &f, int64_t k){
  int n = int(f.size());
  vector<pair<int, T>> non_zero;

  for(int i = 0; i < n; ++i){
      if(f[i] == T(0)) continue;
      non_zero.emplace_back(i, f[i]);
  }

  if(non_zero.empty()) return Formalpowerseries<T>(n) + (k == 0);
  int d = non_zero[0].first;
  if(k < 0) assert(d == 0);
  if(k > 0 && d >= (n + k - 1) / k) return Formalpowerseries<T>(n);
  int offset = d * k; assert(offset < n);
  
  T c = f[d], c_inv = c.inverse();
  for(auto&[i, x] : non_zero) i -= d, x *= c_inv;
  non_zero.erase(begin(non_zero));
  /*
  f^k = g
  k f^{k-1} f' = g'
  k f^k f' = f g' = kgf'
  f[0] (i + 1) g[i + 1] x^i= k * sum(jf[j] * g[i - j + 1] x^i) - sum(f[j] * (i - j + 1)g[i - j + 1] x^i (j > 0))
  //*/
  Formalpowerseries<T> g(n - offset); g[0] = 1;
  for(int i = 0; i < n - offset - 1; ++i){
    for(auto&[j, x] : non_zero){
      if(j > i + 1) break;
      g[i + 1] += x * g[i - j + 1] * (T(k) * j - (i - j + 1));
    }
    g[i + 1] /= i + 1;
  }
  if(k >= 0) g *= c.pow(k);
  else g *= c_inv.pow(-k);
  return (g << offset);
}

template<typename T>
Formalpowerseries<T> pow_sparse(const vector<pair<int, T>> &xs, int n, int64_t k){
  Formalpowerseries<T> f(n);
  for(const auto&[i, x] : xs) if(i < n) f[i] += x;
  return pow_sparse(f, k);
}
