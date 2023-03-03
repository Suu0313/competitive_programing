#pragma once

#include "..\\mod\\ModInt.cpp"
#include "..\\fps\\NTT.cpp"

/**
* @brief c[k] = sum (a[i + k] & b[i])
* @note a[i], b[i] must 0 or 1
*/
vector<int> and_sum_01(const vector<int> &a, const vector<int> &b){
  assert(a.size() == b.size());
  int n = int(a.size());
  using mint = mint998244353;
  vector<mint> ma(n * 2), mb(n);
  for(int i = 0; i < n; ++i) ma[i] = ma[i + n] = a[i];
  for(int i = 0; i < n; ++i) mb[i] = b[n - 1 - i];

  auto f = NTT::multiply(ma, mb);
  vector<int> c(n);
  for(int i = 0; i < n; ++i) c[i] = f[i + n].x;
  return c;
}
