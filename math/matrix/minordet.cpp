#pragma once

#include "./Matrix.cpp"

template<typename T>
T minordet(const Matrix<T> &a, size_t i, size_t j){
  assert(a.height() == a.width());
  size_t n = a.height();
  if(n == 1) return 1;
  Matrix m(n - 1);
  for(size_t r = 0; r < n; ++r){
    for(size_t c = 0; c < n; ++c){
      if(r == i || c == j) continue;
      m[r - (r>i)][c - (c>j)] = a[r][c];
    }
  }
  return determinant(m) * ((i+j)%2 ? -1 : 1);
}
