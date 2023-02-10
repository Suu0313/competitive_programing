#pragma once

#include "..\\monoid\\MaxMonoid.cpp"
#include "..\\monoid\\SetMonoid.cpp"


template<typename T>
struct RangeUpdateRangeMax{
  using Monoid = MaxMonoid<T>;
  using OperatorMonoid = SetMonoid<T>;

  static void act(Monoid &m, const OperatorMonoid &f){
    m.x = f.x;
  }
};
