template<typename T, class Plus = plus<T>>
vector<T> multiple_fast_zeta_transform(vector<T> f, const Plus &op = Plus{}){
  int n = int(f.size());
  vector<bool> sieve(n, true);
  for(int p = 2; p < n; ++p){
    if(!sieve[p]) continue;
    for(int k = (n-1) / p; k >= 1; --k){
      sieve[k * p] = false;
      f[k] = op(f[k], f[k * p]);
    }
  }
  return f;
}
