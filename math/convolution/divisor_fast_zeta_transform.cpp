template<typename T, class Plus = plus<T>>
vector<T> divisor_fast_zeta_transform(vector<T> f, const Plus &op = Plus{}){
  int n = int(f.size());
  vector<bool> sieve(n, true);
  for(int p = 2; p < n; ++p){
    if(!sieve[p]) continue;
    for(int k = 1; p * k < n; ++k){
      sieve[k * p] = false;
      f[k * p] = op(f[k], f[k * p]);
    }
  }
  return f;
}
