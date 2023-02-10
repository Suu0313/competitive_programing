#pragma once

template<typename T, class Minus = minus<T>>
vector<T> divisor_fast_mobius_transform(vector<T> f, const Minus &op = Minus{}){
  int n = int(f.size());
  vector<bool> sieve(n, true);
  for(int p = 2; p < n; ++p){
    if(!sieve[p]) continue;
    for(int k = (n-1) / p; k >= 1; --k){
      sieve[p * k] = false;
      f[p * k] = op(f[p * k], f[k]);
    }
  }
  return f;
}
