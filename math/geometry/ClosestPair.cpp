template<typename T>
double ClosestPair(Polygon<T> &a, int l, int r){
  if(r - l <= 1) return numeric_limits<T>::max();
  int mid = (l + r)/2;
  double x =a[mid].x;
  double d = min(ClosestPair(a,l,mid),ClosestPair(a,mid,r));
  inplace_merge(a.begin()+l,a.begin()+mid,a.begin()+r,cmp_y<T>);

  Polygon<T> b;
  for(int i = l; i < r; i++){
    if(abs(a[i].x-x) >= d) continue;
    for(int j = (int)b.size()-1; j >= 0; j--){
      if(abs(a[i].y-b[j].y) >= d) break;
      d = min(d, a[i].dist(b[j]));
    }
    b.emplace_back(a[i]);
  }
  return d;
}

template<typename T>
double ClosestPair(Polygon<T> &a){
  sort(a.begin(), a.end());
  return ClosestPair(a, 0, a.size());
}
