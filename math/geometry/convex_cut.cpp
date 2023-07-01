#pragma once

#include "./Geometry.cpp"

template<typename T>
pair<Polygon<T>,Polygon<T>> convex_cut(const Polygon<T> &ps, const Line<T> &l){
  Polygon<T> lres, rres;
  int n = ps.size();
  for(int i = 0; i < n; i++){
    int j = (i+1==n) ? 0 : (i + 1);
    int a = iSP(l.a, l.b, ps[i]), b = iSP(l.a, l.b, ps[j]);
    if(a != -1) lres.emplace_back(ps[i]);
    if(a != 1) rres.emplace_back(ps[i]);
    if(a*b < 0){
      auto p = Line(ps[i], ps[j]).cross_point(l);
      lres.emplace_back(p); rres.emplace_back(p);
    }
  }
  return make_pair(lres, rres);
}
