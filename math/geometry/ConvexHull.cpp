template<typename T>
Polygon<T> ConvexHull(Polygon<T> ps, bool strict = true){
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  Polygon<T> res(2 * n);
  auto check = [&](int i){
    if(strict) return Cross(res[k-1]-res[k-2], ps[i]-res[k-1]) <= 0;
    return Cross(res[k-1]-res[k-2], ps[i]-res[k-1]) < 0;
  };
  for(int i = 0; i < n; res[k++] = ps[i++]){
    while(k > 1 && check(i)) k--;
  }
  for(int i = n-2, t=k+1; i >= 0; res[k++] = ps[i--]){
    while(k >= t && check(i)) k--;
  }
  res.resize(k-1);
  return res;
}
