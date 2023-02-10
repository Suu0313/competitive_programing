#pragma once

template<typename T>
T sum_of_pairs(const vector<T> &v, const T &aa, const T &bb, const T &ab, const T &a, const T &b, const T &c){
  int n = int(v.size());
  T res = 0, sum = 0;
  for(int i = 0; i < n; ++i){
    res += (aa*(n-i-1) + bb*i) * v[i]*v[i] + (a*v[i] + c) * (n-i-1) + (ab*v[i] + b) * sum;
    sum += v[i];
  }
  return res;
}
