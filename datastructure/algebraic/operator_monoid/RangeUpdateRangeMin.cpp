#pragma once

#include "../monoid/MinMonoid.cpp"
#include "../monoid/SetMonoid.cpp"

template<typename T>
struct RangeUpdateRangeMin{
  using Monoid = MinMonoid<T>;
  using OperatorMonoid = SetMonoid<T>;

  static void act(Monoid &m, const OperatorMonoid &f){
    m.x = f.x;
  }
};
