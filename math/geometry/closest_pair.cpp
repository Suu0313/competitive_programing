#pragma once

#include ".\\Point.cpp"

template<typename T>
pair<Point<T>, Point<T>> closest_pair(Polygon<T> a){
  sort(a.begin(), a.end());
  Polygon<T> b = a;
  pair<Point<T>, Point<T>> p = {a[0], a[1]};
  T nl = (a[0] - a[1]).norm();

  int n = int(a.size());
  for(int d = 1; d < n; d *= 2){
    for(int l = 0; l < n; l += d * 2){
      int m = min(n, l + d);
      if(m == n) break;
      T x = b[m].x;
      int r = min(n, l + d * 2);
      inplace_merge(begin(a) + l, begin(a) + m, begin(a) + r, cmp_y<T>);

      Polygon<T> b;
      for(int i = l; i < r; i++){
        if((a[i].x - x) * (a[i].x - x) >= nl) continue;
        for(int j = int(b.size())-1; j >= 0; j--){
          if((a[i].y - b[j].y) * (a[i].y - b[j].y) >= nl) break;
          if(nl > (a[i] - b[j]).norm()){
            nl = (a[i] - b[j]).norm();
            p = {a[i], b[j]};
          }
        }
        b.emplace_back(a[i]);
      }
    }
  }

  return p;
}
