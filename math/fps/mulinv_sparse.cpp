template<typename T>
Formalpowerseries<T> mulinv_sparse(const Formalpowerseries<T> &f, const Formalpowerseries<T> &g, int d){
  int n = int(g.size());
  assert(g[0] != T(0));
  T c_inv = g[0].inverse();

  vector<pair<int, T>> non_zero;
  for(int i = 1; i < n; ++i)
    if(g[i] != T(0)) non_zero.emplace_back(i, g[i]);

  Formalpowerseries<T> h(d); h += f.pre(d);
  h[0] *= c_inv;

  for(int i = 1; i < d; ++i){
    for(const auto&[j, x] : non_zero){
      if(j > i) break;
      h[i] -= x * h[i - j];
    }
    h[i] *= c_inv;
  }
  return h;
}


template<typename T>
Formalpowerseries<T> mulinv_sparse(const Formalpowerseries<T> &f, const vector<pair<int, T>> &xs, int d){
  Formalpowerseries<T> g(d);
  for(const auto&[i, x] : xs) if(i < d) g[i] += x;
  return mulinv_sparse(f, g, d);
}
