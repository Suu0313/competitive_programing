#pragma once

template<typename T>
vector<tuple<T, T, T>> quotient_range(T n){
  vector<tuple<T, T, T>> res;
  T l = 1;
  while(l <= n){
    T d = n/l, r = n/d + 1;
    res.emplace_back(l, r, d);
    l = r;
  }
  return res;
}
