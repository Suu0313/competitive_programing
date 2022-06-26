template<typename T>
set<T> divisor_factor(T n){
  set<T> s;
  for(T i = 1; i*i <= n; ++i) {
    if(n%i != 0) continue;
    s.insert(i);
    s.insert(n/i);
  }
  return s;
}
