#pragma once

#include "..\\monoid\\MinMonoid.cpp"

template<typename T>
struct RangeAddRangeMin{
  using Monoid = MinMonoid<T>;
  using OperatorMonoid = T;

  static void act(Monoid &m, const OperatorMonoid &f){
    m.x += f;
  }
};
