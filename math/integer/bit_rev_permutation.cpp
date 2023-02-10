#pragma once

vector<int> bit_rev_perm(int k){
  int n = 1 << k;
  vector<int> a(n);
  for(int i = 0, l = 1; i < k; ++i, l <<= 1){
    n >>= 1;
    for(int j = 0; j < l; ++j){
      a[l + j] = a[j] + n;
    }
  }
  return a;
}
