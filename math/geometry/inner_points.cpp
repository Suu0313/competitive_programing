template<typename T>
pair<int64_t, int64_t> InnerPoints(const Polygon<T> &ps){
  int n = int(ps.size());
  if(n < 2) return {0, n};
  if(n == 2){
    auto[x, y] = ps[0] - ps[1];
    return {0, gcd(x, y) + 1};
  }
  int64_t s2 = Area(ps, false);
  int64_t b = 0;
  for(int i = 0; i < n; ++i){
    int j = (i+1==n) ? 0 : i+1;
    auto[x, y] = ps[i] - ps[j];
    b += gcd(x, y);
  }
  return {(s2 - b)/2+1, b};
}
