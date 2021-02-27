LL ModInv(LL a, LL M){
  LL b = M, u= 1, v = 0;
  while(b){
    LL t = a/b;
    a -= t*b; swap(a,b);
    u -= t*v; swap(u,v);
  }
  u %= M;
  if(u<0) u+= M;
  return u;
}