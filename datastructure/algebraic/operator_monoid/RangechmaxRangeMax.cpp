#pragma once

#include "../monoid/MaxMonoid.cpp"

template<typename T>
struct RangechmaxRangeMax{
  using Monoid = MaxMonoid<T>;
  using OperatorMonoid = MaxMonoid<T>;

  static void act(Monoid &m, const OperatorMonoid &f){
    m += f;
  }
};
