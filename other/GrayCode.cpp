inline pair<int, bool> GrayCode(unsigned long long bit){
  int lsb = __builtin_ctzll(bit);
  return {lsb,  (1ll << lsb)&(bit ^ (bit>>1))};
}
