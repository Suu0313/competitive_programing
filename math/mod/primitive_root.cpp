int primitive_root(int64_t p){
  if (p == 2) return 1;
  if (p == 167772161) return 3;
  if (p == 469762049) return 3;
  if (p == 754974721) return 11;
  if (p == 998244353) return 3;
  vector<int64_t> divs = fast_prime_factor(p - 1);
  divs.erase(unique(begin(divs), end(divs)), end(divs));

  auto pow_mod = [](int64_t x, int64_t n, int64_t m) ->int64_t {
    if (m == 1) return 0;
    int64_t r = 1;
    for(x %= m; n; n >>= 1){
      if(n & 1) r = (__int128_t(r) * x) % m;
      x = (__int128_t(x) * x) % m;
    }
    return r;
  };

  for (int g = 2; ; g++) {
    if(none_of(begin(divs), end(divs),
      [&](int64_t d){ return pow_mod(g, (p - 1) / d, p) == 1; }))
        return g;
  }
  assert(("p is not prime?", false));
  return 0;
}
