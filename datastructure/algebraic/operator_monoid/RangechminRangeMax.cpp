#pragma once

#include "..\\monoid\\MaxMonoid.cpp"
#include "..\\monoid\\MinMonoid.cpp"

template<typename T>
struct RangechminRangeMax{
  using Monoid = MaxMonoid<T>;
  using OperatorMonoid = MinMonoid<T>;

  static void act(Monoid &m, const OperatorMonoid &f){
    m.x = min(m.x, f.x);
  }
};
