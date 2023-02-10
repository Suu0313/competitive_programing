#pragma once

#include "..\\monoid\\MaxMonoid.cpp"

template<typename T>
struct RangeAddRangeMax{
  using Monoid = MaxMonoid<T>;
  using OperatorMonoid = T;

  static void act(Monoid &m, const OperatorMonoid &f){
    m.x += f;
  }
};
