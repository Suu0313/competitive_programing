template<typename T>
double ConvexDiameter(const Polygon<T> &ps){
  Polygon<T> qs = ConvexHull(ps);
  int n = qs.size();
  if(n == 2) return qs[0].dist(qs[1]);
  int i=0, j=0;
  for(int k = 0; k < n; k++){
    if(!(qs[i] < qs[k])) i = k;
    if(qs[j] < qs[k]) j = k;
  }
  double res = 0;
  int si = i, sj = j;
  while(i!=sj || j!=si){
    res = max(res, qs[i].dist(qs[j]));
    if(Cross(qs[(i+1)%n]-qs[i], qs[(j+1)%n]-qs[j]) < 0){
      i = (i + 1)%n;
    }else{
      j = (j + 1)%n;
    }
  }
  return res;
}
