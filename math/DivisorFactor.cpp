set<LL> DivisorFacor(LL N){
  set<LL> s;
  for(LL i = 1; i*i <= N; ++i) {
    if(N%i != 0) continue;
    s.insert(i);
    s.insert(N/i);
  }
  return s;
}