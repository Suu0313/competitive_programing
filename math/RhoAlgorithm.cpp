vector<long long> RhoAlgorithm(long long n){
  vector<long long> res;
  auto f = [&](long long x){ return ((__int128_t)x * x + 1)%n; };
  while(~n & 1){
    res.emplace_back(2);
    n >>= 1;
  }
  while(n > 1){
    long long x = 2, y = 2, g = 1;
    while(g == 1){
      x = f(x);
      y = f(f(y));
      g = gcd(x-y, n);
    }
    if(g == 0) g = n; // it has bugs...
    res.emplace_back(g); n /= g;
  }
  return res;
}
