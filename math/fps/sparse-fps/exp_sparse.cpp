#pragma once

template<typename T>
vector<T> exp_sparse(vector<pair<int, T>> f, int n){
  if(n == 0) return {};

  for(auto&[i, x] : f) x *= i--;

  vector<T> g(n), inv(n, 1); g[0] = 1;
  int mod = T::get_mod();

  for(int i = 0; i < n - 1; ++i){
    for(const auto&[j, x] : f){
      if(j > i) break;
      g[i + 1] += x * g[i - j];
    }
    if(i != 0) inv[i + 1] = -inv[mod % (i + 1)] * (mod / (i + 1));
    g[i + 1] *= inv[i + 1];
  }
  return g;
}

template<typename T>
vector<T> exp_sparse(const vector<T> &f, int n = -1){
  if(n == -1) n = int(f.size());
  vector<pair<int, T>> xs;
  for(int i = 0, m = int(f.size()); i < m; ++i){
    if(f[i] != T(0)) xs.emplace_back(i, f[i]);
  }
  return exp_sparse(xs, n);
}
