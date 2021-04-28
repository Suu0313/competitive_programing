constexpr bool is_prime(long long n){
  if(n <= 1) return false;
  constexpr long long witnesses[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  for(long long a : witnesses) if(n == a) return true;
  if(~n & 1) return false;
  long long d = n-1;
  d >>= __builtin_ctzll(d);
  for(long long a : witnesses){
    long long t = d, y = 1;
    {
      long long x = a%n, k = t, m = n;
      while(k){ // there is not int128 in my enviroment
        if(k & 1) y = (__int128_t)y * x % m;
        x = (__int128_t)x * x % m; k >>= 1;
      }
    }
    while (t != n-1 && y != 1 && y != n-1){
        y = (__int128_t)y * y % n; 
        t <<= 1;
    }
    if (y != n-1 && ~t & 1) return false;
  }
  return true;
}
