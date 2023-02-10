#pragma once

#include ".\\Point.cpp"


template<typename T> bool is_convex(const Polygon<T> &ps, bool strict = true){
  int n = ps.size();
  for(int i = 0; i < n; i++){
    int j = (i+1==n) ? 0 : (i + 1);
    int k = (j+1==n) ? 0 : (j + 1);
    if(strict){
      if(iSP(ps[i], ps[j], ps[k]) != geometry::CCW) return false;
    }else{
      if(iSP(ps[i], ps[j], ps[k]) == geometry::CW) return false;
    }
  }
  return true;
}
