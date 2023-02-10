#pragma once

template<class T> constexpr T floor(T x, T y) {
  if(y < 0) x = -x, y = -y;
  if(x >= 0) return x / y;
  return (x - y + 1) / y;
}
