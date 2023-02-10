#pragma once

template<typename T, class Plus = plus<T>>
vector<T> superset_fast_zeta_transform(vector<T> f, const Plus &op = Plus{}){
  int n = int(f.size());
  for(int i = 1; i < n; i <<= 1){
    for(int j = 0; j < n; ++j){
      if((i&j) == 0) f[j] = op(f[j], f[j | i]);
    }
  }
  return f;
}
