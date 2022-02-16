template<typename T>
int Contains(const Polygon<T> &ps, const Point<T>& p){
  bool in = false;
  int n = ps.size();
  for(int i = 0; i < n; i++){
    Point<T> a = ps[i] - p, b = ps[(i+1)%n] - p;
    if(a.y > b.y) swap(a, b);
    if(a.y <= 0 && 0 < b.y && Cross(a,b) < 0) in = !in;
    if(geometry::is_zero(Cross(a, b)) && geometry::le(Dot(a, b), T(0))) return 1; // on
  }
  return in? 2 : 0; // in/out
}
