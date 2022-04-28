vector<int> enumerate_primes(int n){
  vector<bool> table(n + 1, 1);
  vector<int> ps;

  for(int i = 2; i <= n; ++i){
    if(table[i]) ps.push_back(i);
    for(int p : ps){
      if(p * int64_t(i) > n) break;
      table[p * i] = 0;
    }
  }

  return ps;
}
