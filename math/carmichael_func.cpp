template<typename T>
constexpr T carmichael_func(T n){
  auto ppow = [&](T p, int e) -> T {
    T ret = 1;
    for(; e > 0; e >>= 1, p *= p) if(e % 2 == 1) ret *= p;
    return ret;
  };

  T lam = 1;
  {
    int r = 0;
    while(n%2 == 0) ++r, n >>= 1;
    lam *= ppow(2, r - 1) * (p - 1);
    if(r >= 3) lam /= 2;
  }

  for(T p = 3; p * p <= n; ++p){
    if(n % p != 0) continue;
    int r = 0;
    do n /= p, ++r; while(n % p == 0);
    lam = lcm(lam , ppow(p, r - 1) * (p - 1));
  }

  if(n > 1) lam = lcm(lam , (n - 1));
  
  return lam;
}
