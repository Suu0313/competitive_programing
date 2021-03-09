void SplitandList(vector<long long> &a, vector<long long> &b, vector<long long> &c){
  b.assign(1,0); c.assign(1,0);
  auto merge = [&](LL x){
    vector<long long> d;
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
}
