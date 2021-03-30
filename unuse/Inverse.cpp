template<typename T>
T ModInv(T a, T m){
  T b = m, u= 1, v = 0;
  while(b){
    T t = a/b;
    a -= t*b; swap(a,b);
    u -= t*v; swap(u,v);
  }
  u %= m; if(u<0) u+= m;
  return u;
}
