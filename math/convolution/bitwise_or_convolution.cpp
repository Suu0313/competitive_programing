template<typename T>
vector<T> bitwise_or_convolution(vector<T> f, vector<T> g){
  f = subset_fast_zeta_transform(f);
  g = subset_fast_zeta_transform(g);
  int n = min(f.size(), g.size());
  for(int i = 0; i < n; ++i) f[i] *= g[i];
  return subset_fast_moebius_transform(f);
}
