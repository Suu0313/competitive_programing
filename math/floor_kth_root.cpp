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
