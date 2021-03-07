template <typename T>
vector<pair<T,int>> RunLengthEncoding(const vector<T> &v){
  vector<pair<T,int>> res;
  res.emplace_back(v[0], 0);
  for(auto&&x : v){
    if(res.back().first == x) res.back().second++;
    else res.emplace_back(x, 1);
  }
  return res;
}