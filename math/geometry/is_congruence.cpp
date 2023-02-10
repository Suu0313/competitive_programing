#pragma once

#include ".\\Point.cpp"


template<typename T>
bool isCongruence(const Polygon<T> &ps, const Polygon<T> &qs){
  int n = int(ps.size()), m = int(qs.size());
  if(n != m) return false;
  if(n <= 1) return true;
  if(n == 2) return geometry::eq((ps[0] - ps[1]).norm(), (qs[0] - qs[1]).norm());

  auto normalize = [](const Polygon<T> &pts) -> vector<T> {
    int n = int(pts.size());
    Point<T> g(0, 0); for(auto&p : pts) g += p;
    Polygon<T> nps; nps.reserve(n);
    for(auto&p : pts){
      if(g == p * n) continue;
      nps.emplace_back(p*n - g);
    }
    arg_sort(nps);
    n = int(nps.size());
    vector<T> res(n * 3);
    for(int i = 0; i < n; ++i){
      int j = (i+1==n) ? 0 : (i+1);
      res[i*3] = nps[i].norm();
      res[i*3+1] = nps[i].dot(nps[j]);
      res[i*3+2] = nps[i].cross(nps[j]);
    }
    return res;
  };
  vector<T> va = normalize(ps), vb = normalize(qs);
  if(va.size() != vb.size()) return false;
  n = int(va.size());
  vector<T> zs(n * 3);
  for(int i = 0; i < n; ++i) zs[i] = va[i];
  for(int i = 0; i < n; ++i) zs[i + n] = vb[i], zs[i + 2*n] = vb[i];

  vector<int> zr(n * 3); zr[0] = n*3;
  
  for(int i = 1, j = 0; i < n*3; ){
    while(i + j < n*3 && geometry::eq(zs[j], zs[i + j])) ++j;
    zr[i] = j;
    if(j == 0){ ++i; continue; }

    int k = 1;
    while(k < j && k+zr[k] < j){ zr[i+k] = zr[k]; ++k; }
    i += k; j -= k;
  }
  for(int i = n; i < n * 2; i += 3){
    if(zr[i] >= n) return true;
  }
  return false;
}
