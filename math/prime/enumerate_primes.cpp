#pragma once

vector<int> enumerate_primes(int n){
  vector<bool> table(n + 1, 1);
  vector<int> ps;
  int i = 2;
  for(; i * i <= n; ++i){
    if(!table[i]) continue;
    ps.push_back(i);
    for(int j = i * i; j <= n; j += i) table[j] = 0;
  }

  for(; i <= n; ++i) if(table[i]) ps.push_back(i);

  return ps;
}
