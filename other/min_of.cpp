#pragma once

template<typename T, class Iiter, class Fn>
T min_of(Iiter first, Iiter last, const Fn &f){
  T res = f(*first);
  for(++first; first != last; ++first) res = min(res, f(*first));
  return res;
}

template<typename T, class Fn>
T min_of(int n, const Fn &f){
  T res = f(0);
  for(int i = 1; i < n; ++i) res = min(res, f(i));
  return res;
}
