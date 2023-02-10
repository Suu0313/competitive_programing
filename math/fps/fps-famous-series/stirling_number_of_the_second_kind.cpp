#pragma once

#include "..\\Formalpowerseries.cpp"

template<typename T>
Formalpowerseries<T> stirling_number_of_the_second_kind(int n){
  int mod = T::get_mod();
  Formalpowerseries<T> f(n + 1, 1);
  for(int i = 2; i <= n; ++i) f[i] = -f[mod % i] * (mod / i);
  for(int i = 3; i <= n; ++i) f[i] *= f[i - 1];
  Formalpowerseries<T> g = f;
  for(int i = 0; i <= n; ++i) f[i] *= T(i).pow(n);
  for(int i = 1; i <= n; i += 2) g[i] = -g[i];
  return (f * g).pre(n + 1);
}
