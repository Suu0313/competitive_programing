#pragma once

#include "./Formalpowerseries.cpp"

template< typename T >
Formalpowerseries<T> taylor_shift(const Formalpowerseries<T> &f, const T &c){
  int n = int(f.size()), mod = T::get_mod();
  vector<T> finv(n, 1), fact(n, 1);
  for(int i = 2; i < n; ++i){
    fact[i] = fact[i - 1] * i;
    finv[i] = -finv[mod % i] * (mod / i);
  }

  for(int i = 3; i < n; ++i) finv[i] *= finv[i - 1];

  Formalpowerseries<T> rf(n), exp_cx(n, 1);
  for(int i = 0; i < n; ++i) rf[n - i - 1] = f[i] * fact[i];
  for(int i = 1; i < n; ++i) exp_cx[i] = exp_cx[i - 1] * c;
  for(int i = 2; i < n; ++i) exp_cx[i] *= finv[i];

  Formalpowerseries<T> g = (rf * exp_cx).pre(n).rev();
  for(int i = 2; i < n; ++i) g[i] *= finv[i];
  return g;
}
