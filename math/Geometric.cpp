bool anrlim(LL a, LL r, LL n, LL lim, LL &res){
  --n;
  while(n>0){
    if(a>lim || r>lim){
      return true;
    }
    if(n&1){
      a *= r;
    }
    r *= r;
    n >>= 1;
  }
  res = a;
  return a>lim;
}