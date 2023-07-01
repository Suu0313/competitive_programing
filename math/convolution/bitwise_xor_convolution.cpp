#pragma once

#include "./fast_walsh_hadamard_transform.cpp"

template<typename T>
vector<T> bitwise_xor_convolution(vector<T> f, vector<T> g){
  f = fast_walsh_hadamard_transform(f, false);
  g = fast_walsh_hadamard_transform(g, false);
  int n = int(f.size());
  for(int i = 0; i < n; ++i) f[i] *= g[i];
  return fast_walsh_hadamard_transform(f, true);
}
