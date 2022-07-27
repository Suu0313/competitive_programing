template<typename T, class Iiter, class Fn>
T max_of(Iiter first, Iiter last, const Fn &f){
  T res = f(*first);
  for(++first; first != last; ++first) res = max(res, f(*first));
  return res;
}

template<typename T, class Fn>
T max_of(int n, const Fn &f){
  T res = f(0);
  for(int i = 1; i < n; ++i) res = max(res, f(i));
  return res;
}
