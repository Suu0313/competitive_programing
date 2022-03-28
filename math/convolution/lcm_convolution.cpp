template<typename T>
vector<T> lcm_convolution(vector<T> f, vector<T> g){
  int n = int(max(f.size(), g.size()));
  f.resize(n, 0); g.resize(n, 0);
  f = divisor_fast_zeta_transform(f);
  g = divisor_fast_zeta_transform(g);
  for(int i = 0; i < n; ++i) f[i] *= g[i];
  return divisor_fast_moebius_transform(f);
}
