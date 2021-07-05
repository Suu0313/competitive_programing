template<typename T>
vector<tuple<T>> Zip(vector<T> &v){
  vector<tuple<T>> vt(v.size());
  for(size_t i = 0; i < v.size(); i++) vt[i] = make_tuple(v[i]);
  return vt;
}
template<typename T, typename... Ts>
auto Zip(vector<T> &v, Ts&&... vs){
  auto vt = Zip(v); auto vts = Zip(vs...);
  size_t m = min(vt.size(), vts.size());
  auto te = decltype(vt)(1)[0]; auto tse = decltype(vts)(1)[0];
  vector res(m, tuple_cat(te, tse));
  for(size_t i = 0; i < m; i++) res[i] = tuple_cat(vt[i], vts[i]);
  return res;
}

template<typename T>
vector<tuple<int, T>> Enumerate(vector<T> &v){
  vector<int> idx(v.size()); iota(idx.begin(), idx.end(), 0);
  return Zip(idx, v);
}
template<typename T, typename... Ts>
auto Enumerate(vector<T> &v, Ts&&... vs){
  vector<int> idx(v.size()); iota(idx.begin(), idx.end(), 0);
  return Zip(idx, v, vs...);
}
