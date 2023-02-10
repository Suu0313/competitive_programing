#pragma once

template<typename T, class Minus = minus<T>>
vector<T> multiple_fast_mobius_transform(vector<T> f, const Minus &op = Minus{}){
  int n = int(f.size());
  vector<bool> sieve(n, true);
  for(int p = 2; p < n; ++p){
    if(!sieve[p]) continue;
    for(int k = 1; p * k < n; ++k){
      sieve[p * k] = false;
      f[k] = op(f[k], f[p * k]);
    }
  }
  return f;
}
