#pragma once

#include "../Formalpowerseries.cpp"

template< typename T >
Formalpowerseries<T> bernoulli_number(int n){
  Formalpowerseries<T> f(n+1, 1);
  int mod = T::get_mod();
  for(int i = 1; i <= n; ++i) f[i] = -f[mod % (i + 1) - 1] * (mod / (i + 1));
  for(int i = 1; i <= n; ++i) f[i] *= f[i-1];
  f = f.inv();
  T fc = 1;
  for(int i = 2; i <= n; ++i) f[i] *= (fc *= i);
  return f;
}
