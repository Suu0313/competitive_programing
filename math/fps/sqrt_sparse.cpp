template<typename T>
Formalpowerseries<T> sqrt_sparse(const Formalpowerseries<T> &f, const function< T(T) > &get_sqrt){
  int n = int(f.size());
  vector<pair<int, T>> non_zero;

  for(int i = 0; i < n; ++i){
      if(f[i] == T(0)) continue;
      non_zero.emplace_back(i, f[i]);
  }

  if(non_zero.empty()) return Formalpowerseries<T>(n);
  int d = non_zero[0].first, offset = d >> 1;
  if(d & 1) return {};

  T c = f[d], c_inv = c.inverse(), inv2 = T(2).inverse();
  T sc = get_sqrt(c);
  if(sc * sc != c) return {};
  for(auto&[i, x] : non_zero) i -= d, x *= c_inv;
  non_zero.erase(begin(non_zero));

  Formalpowerseries<T> g(n - offset); g[0] = 1;
  for(int i = 0; i < n - offset - 1; ++i){
    for(auto&[j, x] : non_zero){
      if(j > i + 1) break;
      g[i + 1] += x * g[i - j + 1] * (inv2 * j - (i - j + 1));
    }
    g[i + 1] /= i + 1;
  }
  g *= sc;
  return (g << offset);
}
