#pragma once

#include "./is_prime_64bit.cpp"

int64_t pollard_pho(int64_t n){
  if(~n & 1) return 2;
  if(is_prime_64bit(n)) return n;
  for(int c = 1; ; ++c){
    int64_t x = 2, y = 2, d = 1;
    for( ; d == 1; d = gcd((y - x) >= 0 ? (y - x) : (y - x + n), n)){
      x = (__int128_t(x) * x + c) % n;
      y = (__int128_t(y) * y + c) % n;
      y = (__int128_t(y) * y + c) % n;
    }

    if(d < n) return d;
  }
  return -1;
}

vector<int64_t> fast_prime_factor(int64_t n){
  if(n <= 1) return {};
  if(is_prime(n)) return {n};

  int64_t m = pollard_pho(n);
  vector<int64_t> res = fast_prime_factor(m);
  auto r = fast_prime_factor(n / m);
  res.insert(end(res), begin(r), end(r));
  sort(begin(res), end(res));
  return res;
}
