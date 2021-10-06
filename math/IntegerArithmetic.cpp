template<class T> constexpr T Ceil(T x, T y) {
  if(y < 0) x = -x, y = -y;
  if(x >= 0) return (x + y - 1) / y;
  return x / y;
}

template<class T> constexpr T Floor(T x, T y) {
  if(y < 0) x = -x, y = -y;
  if(x >= 0) return x / y;
  return (x - y + 1) / y;
}

template<class T> constexpr T Mid(T x, T y) {
  return (x&y) + ((x^y) >> 1);
}

uint64_t Sqrt(uint64_t x){
  uint64_t res = 0, over = 1;
  while(over*over <= x) over <<= 1;
  while(over-res > 1){
    uint64_t wj = res + ((over-res) >> 1);
    ((wj*wj <= x) ? res : over) = wj;
  }
  return res;
}

uint64_t floor_kth_root(uint64_t a, int k){
  if(a <= 1 || k <= 1) return a;
  if(k >= 64) return 1;
  uint64_t res = 0;
  for(int i = 31; i >= 0; --i){
    uint64_t p = 1, x = res | (1u << i);
    bool fl = true;
    for(int j = 0; j < k; ++j){
      if(__builtin_mul_overflow(p, x, &p)){ fl = false; break;}
    }
    if(fl && p <= a) res |= (1u << i);
  }
  return res;
}
