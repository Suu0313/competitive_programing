#pragma once

template<typename T>
T mod_inv(T a, T m){
  T b = m, u= 1, v = 0;
  while(b){ T t = a/b; a -= t*b; swap(a,b); u -= t*v; swap(u,v); }
  u %= m; if(u<0) u+= m;
  return u;
}

template<typename T>
T ipow(T a, int64_t n, T m = 0, T e = 1){
  if(n < 0){ assert(m != 0); return mod_inv(ipow(a, -n, m, e), m); }
  T res = e;
  while(n > 0){ if(n&1){ res *= a; if(m) res %= m; } a *= a; n >>= 1; if(m) a %= m; }
  return res;
}
