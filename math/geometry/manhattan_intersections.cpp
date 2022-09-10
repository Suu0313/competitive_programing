template<typename T>
int64_t manhattanIntersections(vector<Segment<T>> ss){
  const int n = int(ss.size());
  vector<T> xs(n*2);
  for(int i = 0; i < n; ++i) xs[i] = ss[i].a.x, xs[i+n] = ss[i].b.x;
  sort(begin(xs), end(xs)); xs.erase(unique(begin(xs), end(xs)), end(xs));
  const int m = int(xs.size());

  auto lb = [&](const T &x){
    return (int)std::distance(begin(xs), lower_bound(begin(xs),end(xs), x)); };
  
  vector<tuple<T, int, int>> qs;
  for(auto&&[a, b] : ss){
    if(a.y == b.y){
      if(a.x > b.x) swap(a, b);
      qs.emplace_back(a.y, lb(a.x), lb(b.x));
    }else{
      if(a.y > b.y) swap(a, b);
      qs.emplace_back(a.y, -1, lb(a.x)); qs.emplace_back(b.y, m, lb(b.x));
    }
  }

  sort(begin(qs), end(qs));
  vector<int> fw(m + 1);
  auto add = [&](int x, int c){
    for(int idx = x+1; idx <= m; idx += (idx&-idx)) fw[idx] += c;
  };
  auto sum = [&](int i){
    int ret = 0;
    for(int idx = i; idx > 0; idx -= (idx & -idx)) ret += fw[idx];
    return ret;
  };
  int64_t ans = 0;
  for(auto&[y, a, b] : qs){
    if(a == -1) add(b, 1);
    else if(a == m) add(b, -1);
    else ans += sum(b+1) - sum(a);
  }
  return ans;
}
