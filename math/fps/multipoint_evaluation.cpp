template< typename T >
vector<T> MultipointEvaluation(const Formalpowerseries<T> &f, const vector<T> &xs){
  int n0 = int(xs.size()), n = 1;
  while(n < n0) n <<= 1;
  vector<Formalpowerseries<T>> g(n*2, {1});
  for(int i = 0; i < n0; ++i) g[i+n] = {-xs[i], 1};
  for(int i = n-1; i > 0; --i) g[i] = g[i*2] * g[i*2 + 1];

  g[1] = f % g[1];
  for(int i = 2; i < n + n0; ++i) g[i] = g[i>>1] % g[i];
  vector<T> res(n0);
  for(int i = 0; i < n0; ++i) res[i] = g[i+n][0];
  return res;
}
