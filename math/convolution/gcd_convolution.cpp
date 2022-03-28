template<typename T>
vector<T> gcd_convolution(vector<T> f, vector<T> g){
  int n = int(max(f.size(), g.size()));
  f.resize(n, 0); g.resize(n, 0);
  f = multiple_fast_zeta_transform(f);
  g = multiple_fast_zeta_transform(g);
  for(int i = 0; i < n; ++i) f[i] *= g[i];
  return multiple_fast_moebius_transform(f);
}
