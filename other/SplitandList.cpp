template<typename T>
pair<vector<T>, vector<T>> SplitAndList(const vector<T> &a){
  vector<T> b(1, T{}), c(1, T{});
  auto merge = [&](T x){
    vector<T> d;
    auto it = b.begin();
    for(auto&&y : b){
      while(x+*it < y) d.emplace_back(x + *it++);
      d.emplace_back(y);
    }
    while(it < b.end()) d.emplace_back(x + *it++);
    swap(b, d);
  };
  for(auto&&x : a){
    merge(x); swap(b, c);
  }
  return {b, c};
}
