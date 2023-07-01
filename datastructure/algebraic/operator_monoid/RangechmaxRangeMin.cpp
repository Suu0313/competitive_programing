#pragma once

#include "../monoid/MaxMonoid.cpp"
#include "../monoid/MinMonoid.cpp"


template<typename T>
struct RangechmaxRangeMin{
  using Monoid = MinMonoid<T>;
  using OperatorMonoid = MaxMonoid<T>;

  static void act(Monoid &m, const OperatorMonoid &f){
    m.x = max(m.x, f.x);
  }
};
