bool IsPrime(LL N){
  if(N <= 1) return false;
  for(LL i = 2; i*i <= N; ++i){
    if(N%i == 0) return false;
  }
  return true;
}