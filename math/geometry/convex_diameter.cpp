template<typename T>
double convex_diameter(Polygon<T> ps){
  ps = convex_hull(ps);
  int n = ps.size();
  if(n == 2) return ps[0].dist(ps[1]);
  int i=0, j=0;
  for(int k = 0; k < n; k++){
    if(!(ps[i] < ps[k])) i = k;
    if(ps[j] < ps[k]) j = k;
  }
  double res = 0;
  int si = i, sj = j;
  while(i!=sj || j!=si){
    res = max(res, ps[i].dist(ps[j]));
    if(geometry::lt((ps[(i+1)%n]-ps[i]).cross(ps[(j+1)%n]-ps[j]), T(0))){
      i = (i + 1)%n;
    }else{
      j = (j + 1)%n;
    }
  }
  return res;
}
