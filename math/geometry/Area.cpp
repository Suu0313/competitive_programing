template<typename T> T Area(const Polygon<T> &ps, bool harf = true){
  if((int)ps.size() < 3) return 0;
  T res = Cross(ps.back(), ps.front());
  for(int i = 0; i < (int)ps.size()-1; i++){
    res += Cross(ps[i], ps[i+1]);
  }
  if(harf) res /= 2;
  return res;
}

template<typename T>
double CommonArea(const Circle<T> &c, const Polygon<T> &ps){
  int n = int(ps.size());
  if(n < 3) return 0;

  auto calc_impl = [&](Point<T> p, Point<T> q, bool tri) -> double{
    p -= c.o; q -= c.o;
    if(tri) return Cross(p, q)/2.0;
    return c.r*c.r*((q / p).arg())/2.0;
  };

  auto CommonArea_impl = [&](Point<T> p, Point<T> q){
    if(c.Contains(p) <= 1 && c.Contains(q) <= 1) return calc_impl(p, q, 1);
    Polygon<T> cs = c.CrossPoints(Segment<T>(p, q));
    Polygon<T> pa = c.CrossPoints(Segment<T>(c.o, p));
    Polygon<T> pb = c.CrossPoints(Segment<T>(c.o, q));
    int m = int(cs.size());
    if(m == 0) return calc_impl(pa[0], pb[0], 0);
    if(m == 2){
      return calc_impl(pa[0], cs[0], 0) + calc_impl(cs[0], cs[1], 1) + calc_impl(cs[1], pb[0], 0);
    }
    if(c.Contains(p) <= 1){
      assert(pb.size());
      return calc_impl(p, cs[0], 1) + calc_impl(cs[0], pb[0], 0);
    }else if(c.Contains(q) <= 1){
      assert(pa.size());
      return calc_impl(pa[0], cs[0], 0) + calc_impl(cs[0], q, 1);
    }else return calc_impl(pa[0], pb[0], 0);

    assert(false);
    return 0.0;
  };

  double sum = 0;
  for(int i = 0; i < n; ++i){
    int j = (i+1==n ? 0 : i+1);
    sum += CommonArea_impl(ps[i], ps[j]);
  }
  return sum;
}

template<typename T>
double CommonArea(const Circle<T> &c1, const Circle<T> &c2){
  int k = c1.Intersect(c2);
  if(k >= 3) return 0;
  if(k <= 1) return min(c1.Area(), c2.Area());
  auto ps = c1.CrossPoints(c2);
  return abs(c1.r*c1.r*((ps[0] - c1.o)/(c2.o - c1.o)).arg())
    + abs(c2.r*c2.r*((ps[0] - c2.o)/(c1.o - c2.o)).arg())
    - abs(Area(Polygon<T>{c1.o, ps[0], c2.o, ps[1]}));
}
