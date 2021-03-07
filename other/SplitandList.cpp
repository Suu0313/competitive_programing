void SplitandList(VLL &a, VLL &b, VLL &c){
  b.assign(1,0); c.assign(1,0);
  auto merge = [&](LL x){
    VLL d;
    auto it = b.begin();
    for(auto&&y : b){
      while(x+*it < y) d.EB(x + *it++);
      d.EB(y);
    }
    while(it < b.end()) d.EB(x + *it++);
    swap(b, d);
  };
  for(auto&&x : a){
    merge(x); swap(b, c);
  }
}