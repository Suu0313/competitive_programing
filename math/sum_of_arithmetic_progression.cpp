#pragma once

template<typename T>
T sum_of_arithmetic_progression(T s, T d, T n){
  return (s + s + (n - 1) * d) * n / 2;
}
