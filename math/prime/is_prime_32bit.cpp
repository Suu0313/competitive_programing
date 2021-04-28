constexpr bool is_prime(int n){
  if(n <= 1) return false;
  if(n == 2 || n == 7 || n == 61) return true;
  if(~n & 1) return false;
  long long d = n-1;
  d >>= __builtin_ctzll(d);
  for(long long a : {2, 7, 61}){
    long long t = d, y = 1;
    {
      long long x = a%n, k = t, m = n;
      while(k){
        if(k & 1) y = y * x % m;
        x = x * x % m; k >>= 1;
      }
    }
    while (t != n-1 && y != 1 && y != n-1) {
        y = y * y % n; 
        t <<= 1;
    }
    if (y != n-1 && ~t & 1) return false;
  }
  return true;
}
