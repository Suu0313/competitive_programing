int64_t CountPrimes(int64_t n){
  int64_t y = pow(n, 0.38);
  if(n < 100) y = 1;
  int64_t iy = n / y;

  vector<int64_t> min_factor(iy + 1, -1), primes;
  for(int64_t i = 2; i <= iy; ++i){
    if(min_factor[i] == -1){
      min_factor[i] = primes.size();
      primes.push_back(i);
    }
    for(int j = 0; j <= min_factor[i]; ++j){
      int64_t p = primes[j];
      if(i * p > iy) break;
      min_factor[i * p] = j;
      if(i % p == 0) break;
    }
  }
  int64_t pi_iy = int64_t(primes.size());
  if(n < 100) return pi_iy;

  int64_t pi_y = 0;
  for(auto&p : primes){
    if(p > y) break;
    ++pi_y;
  }

  int64_t ans = pi_y - 1;

  for(int i = pi_y+1, j = pi_iy-1; i < pi_iy; ++i){
    while(i <= j && primes[i-1]*primes[j-1] > n) --j;
    if(j < i) break;
    ans -= j - i + 1;
  }

  vector<tuple<int64_t, int, int>> rem;
  auto phi = [&](auto f, int64_t m, int a, int sign = 1) -> void{
    if(m == 0) return;
    if(a == 0){ ans += m * sign; return; }
    if(m <= iy){ rem.emplace_back(m, a, sign); return; }
    f(f, m, a-1, sign);
    f(f, m/primes[a-1], a-1, -sign);
  };

  phi(phi, n, pi_y);
  sort(begin(rem), end(rem));
  
  int cur = 2;
  vector<int> fw(pi_iy + 1);
  for(auto&&[m, a, sign] : rem){
    for( ; cur <= m; ++cur){
      for(int idx = min_factor[cur]+1; idx <= pi_iy; idx += (idx & -idx)){
        fw[idx] += 1;
      }
    }
    int sum = 0;
    for(int idx = a; idx > 0; idx -= (idx & -idx)){
      sum += fw[idx];
    }
    ans += (m - sum) * sign;
  }
  return ans;
};
