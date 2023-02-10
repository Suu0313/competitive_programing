#pragma once

#include "..\\monoid\\LengthMonoid.cpp"

#include "..\\monoid\\SetMonoid.cpp"

template<typename T>
struct RangeUpdateRangeSum{
  using Monoid = LengthMonoid<T>;
  using OperatorMonoid = SetMonoid<T>;

  static void act(Monoid &m, const OperatorMonoid &f){
    if(f.id) return;
    m.x = f.x * m.l;
  }
};
