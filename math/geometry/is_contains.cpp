#pragma once

#include "./Point.cpp"


template<typename T>
int is_contains(const Polygon<T> &ps, const Point<T>& p){
  bool in = false;
  int n = ps.size();
  for(int i = 0; i < n; i++){
    Point<T> a = ps[i] - p, b = ps[(i+1)%n] - p;
    if(a.y > b.y) swap(a, b);
    if(geometry::le(a.y, T(0)) && geometry::lt(T(0), b.y) && geometry::lt(a.cross(b), T(0))){
      in = !in;
    }
    if(geometry::is_zero(a.cross(b)) && geometry::le(a.dot(b), T(0))) return 1; // on
  }
  return in? 2 : 0; // in/out
}
