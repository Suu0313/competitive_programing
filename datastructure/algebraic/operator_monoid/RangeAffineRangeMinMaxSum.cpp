#pragma once

#include "..\\monoid\\MinMaxSumMonoid.cpp"
#include "..\\monoid\\CompositeMonoid.cpp"

template<typename T>
struct RangeAffineRangeMinMaxSum{
  using Monoid = MinMaxSumMonoid<T>;
  using OperatorMonoid = CompositeMonoid<T>;

  static void act(Monoid &m, const OperatorMonoid &f){
    T x1 = f.a * m.mn + f.b;
    T x2 = f.a * m.mx + f.b;
    T sum = f.a * m.sum + f.b * m.len;
    m = Monoid(min(x1, x2), max(x1, x2), sum, m.len);
  }
};
