template<typename P=int64_t, typename T=int>
map<P,T> Factoring(P A){
  map<P,T> mp;
  for(P i = 2; i*i<=A; i++){
    while(A%i == 0){ mp[i]++; A/= i; }
  }
  if(A>1) mp[A]++;
  return mp;
}
