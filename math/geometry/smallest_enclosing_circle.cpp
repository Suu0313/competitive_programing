template<typename T>
Circle<T> smallest_enclosing_circle(Polygon<T> ps){
  int n = ps.size();
  if(n == 1) return Circle<T>(ps[0], 0);
  random_device seed;
  mt19937 rng(seed());
  shuffle(ps.begin(), ps.end(), rng);
  Circle<T> c(ps[0], ps[1]);
  for(int i = 2; i < n; i++){
    if(c.contains(ps[i]) != 2) continue;
    c = Circle<T>(ps[0], ps[i]);
    for(int j = 1; j < i; j++){
      if(c.contains(ps[j]) != 2) continue;
      c = Circle<T>(ps[i], ps[j]);
      for(int k = 0; k < j; k++){
        if(c.contains(ps[k]) != 2) continue;
        c = Circle<T>(ps[i], ps[j], ps[k]);
      }
    }
  }
  return c;
}
