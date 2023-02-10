#pragma once

#include ".\\superset_fast_zeta_transform.cpp"

#include ".\\superset_fast_mobius_transform.cpp"

template<typename T>
vector<T> bitwise_and_convolution(vector<T> f, vector<T> g){
  f = superset_fast_zeta_transform(f);
  g = superset_fast_zeta_transform(g);
  int n = min(f.size(), g.size());
  for(int i = 0; i < n; ++i) f[i] *= g[i];
  return superset_fast_mobius_transform(f);
}
