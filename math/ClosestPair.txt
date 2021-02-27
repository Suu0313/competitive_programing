bool comp_y(const point &a, const point &b){
  return a.y < b.y;
}

double ClosestPair(polygon &a, int l, int r){
  // x で昇順ソートしてから渡す
  if(r - l <= 1) return INF;
  int mid = (l + r)/2;
  double x =a.at(mid).x;
  double d = min(ClosestPair(a,l,mid),ClosestPair(a,mid,r));
  inplace_merge(a.begin()+l,a.begin()+mid,a.begin()+r,comp_y);

  polygon b;
  FOR(i, l, r){
    if(abs(a.at(i).x-x) >= d) continue;
    REPR(j, SZ(b)){
      if(abs(a.at(i).y-b.at(j).y) >= d) break;
      chmin(d, (a.at(i)-b.at(j)).Abs());
    }
    b.EB(a.at(i));
  }
  return d;
}