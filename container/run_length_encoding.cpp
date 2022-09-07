template <typename Container, typename T = typename Container::value_type>
vector<pair<T,int>> run_length_encoding(const Container &v){
  if(v.empty()) return {};
  vector<pair<T,int>> res;
  res.emplace_back(v[0], 0);
  for(auto&&x : v){
    if(res.back().first == x) res.back().second++;
    else res.emplace_back(x, 1);
  }
  return res;
}
