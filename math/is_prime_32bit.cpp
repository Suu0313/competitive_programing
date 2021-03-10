constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = x % m;
    if(y < 0) y += m;
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}

constexpr bool is_prime(int n){
  if(n <= 1) return false;
  if(n == 2 || n == 7 || n == 61) return true;
  if(~n & 1) return false;
  long long d = n-1;
  d >>= __builtin_ctzll(d);
  for(long long a : {2, 7, 61}){
    long long t = d;
    long long y = pow_mod_constexpr(a, t, n);
    while(t!= n-1 && y != 1 && y != n-1){
      y = y*y % n;
      t <<= 1;
    }
    if(y != n-1 && t % 2 == 0) return false;
  }
  return true;
}

