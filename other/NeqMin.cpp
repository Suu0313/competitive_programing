struct NeqMin{
  set<pair<int, int>> s;
  NeqMin(){
    s.emplace(INT_MIN, INT_MIN);
    s.emplace(INT_MAX, INT_MAX);
  }
  bool contains(int x) const {
    auto it = prev(s.LB(MP(x+1,x+1)));
    auto [l,u] = *it;
    return l<=x && x<=u;
  }
  bool insert(int x){
    auto nit = s.LB(MP(x+1,x+1));
    auto it = prev(nit);
    auto [l,u] = *it;
    auto [nl,nu] = *nit;
    if(l<=x && x<=u) return false;
    if(u == x-1){
      if(nl == x+1){
        s.erase(it);
        s.erase(nit);
        s.emplace(l,nu);
      }else{
        s.erase(it);
        s.emplace(l,x);
      }
    }else{
      if(nl == x+1){
        s.erase(nit);
        s.emplace(x,nu);
      }else{
        s.emplace(x,x);
      }
    }
    return true;
  }
  int mex(int x=0) const {
    auto [l,u] = *prev(s.LB(MP(x+1,x+1)));
    if(l<=x && x<=u) return u+1;
    else return x;
  }
  int cnt() const {
    return (int)s.size() - 2;
  }
};