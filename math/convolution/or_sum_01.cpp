#pragma once

#include "./and_sum_01.cpp"

/**
* @brief c[k] = sum (a[i + k] | b[i])
* @note a[i], b[i] must 0 or 1
*/
vector<int> or_sum_01(vector<int> a, vector<int> b){
  assert(a.size() == b.size());
  int n = int(a.size());
  for(auto&&e : a) e = 1 - e;
  for(auto&&e : b) e = 1 - e;
  vector<int> c = and_sum_01(a, b);
  for(auto&&e : c) e = n - e;
  return c;
}