#pragma once

#include ".\\Formalpowerseries.cpp"

template<typename T>
T FastKitamasa(const Formalpowerseries<T> &c, const Formalpowerseries<T> &a, long long n){
  Formalpowerseries<T> d({1}), xn({0, 1}), f(-c);
  f.push_back(1);
  while(n){
    if(n & 1) d = d * xn % f;
    xn = xn * xn % f;
    n >>= 1;
  }
  return a.dot(d).eval(1);
}
