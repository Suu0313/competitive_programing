#pragma once

template<typename T>
T max_subarray(const vector<T> &v){
  T res = v[0], sum = 0;
  for(auto&&x : v){
    sum = max(sum + x, x);
    res = max(res, sum);
  }
  return res;
}
