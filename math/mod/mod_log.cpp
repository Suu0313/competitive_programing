template<typename T>
T mod_log(T x, T y, T m){ // x^k = y mod m
  if(m == 1 || y == 1) return 0;
  if(x == 0){
    if(y == 0) return 1;
    return -1;
  }

  auto inv = [](T a, T c){
    T b = c, u= 1, v = 0;
    while(b){
      T t = a/b;
      a -= t*b; swap(a,b);
      u -= t*v; swap(u,v);
    }
    u %= c; if(u<0) u+= c;
    return u;
  };

  T d = 0, xd = 1;
  for(T l = m; l > 0; l >>= 1){
    if(xd == y) return d;
    (xd *= x) %= m; ++d;
  }

  {
    T g = gcd(xd, m);
    if(y % g != 0) return -1;
    m /= g;
    (y *= inv(xd, m)) %= m;
  }
  
  T h = 0, gs = 1;
  for(T ix = inv(x, m); h*h < m; ++h) (gs *= ix) %= m;

  unordered_map<T, T> bs;
  for(T s = 0, b = 1; s < h; ++s){
    if(bs.count(b)) break;
    bs[b] = s; (b *= x) %= m;
  }
  
  for(T s = 0, g = y; s < h; ++s){
    if(bs.count(g)) return d + s*h + bs[g];
    (g *= gs) %= m;
  }
  return -1;
}
