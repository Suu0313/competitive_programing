#pragma once

/**
 * @brief x in [l, r),  n // x = d, O(sqrt(n))
 * 
 * @tparam T 
 * @param n 
 * @return vector<tuple<T, T, T>> (l, r, d)
 */
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
