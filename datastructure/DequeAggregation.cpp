
template<typename Monoid>
struct DequeAggregation{
  vector<pair<Monoid, Monoid>> st_l, st_r;

  DequeAggregation() = default;
  template<typename Iiter>
  DequeAggregation(Iiter first, Iiter last){
    for(; first != last; ++first) push_back(*first);
  }
  template<class Container>
  DequeAggregation(const Container &c): DequeAggregation(begin(c), end(c)) {}

  Monoid prod() const { return top(st_l) + top(st_r); }
  void push_back(const Monoid &x){ st_r.emplace_back(x, top(st_r) + x); }
  void push_front(const Monoid &x){ st_l.emplace_back(x, x + top(st_l)); }

  Monoid pop_back(){
    assert(!empty());
    if(!st_r.empty()){
      Monoid val = move(st_r.back().first);
      st_r.pop_back();
      return val;
    }
    int sz = int(st_l.size()), l = sz >> 1, r = sz - l;
    for(int i = r - 1; i > 0; --i) push_back(move(st_l[i].first));
    Monoid val = move(st_l.front().first);
    st_l.erase(begin(st_l), begin(st_l) + r);
    if(l == 0) return val;
    st_l[0].second = st_l[0].first;
    for(int i = 1; i < l; ++i) st_l[i].second = st_l[i].first + st_l[i - 1].second;
    return val;
  }

  Monoid pop_front(){
    assert(!empty());
    if(!st_l.empty()){
      Monoid val = move(st_l.back().first);
      st_l.pop_back();
      return val;
    }
    int sz = int(st_r.size()), r = sz >> 1, l = sz - r;
    for(int i = l - 1; i > 0; --i) push_front(move(st_r[i].first));
    Monoid val = move(st_r.front().first);
    st_r.erase(begin(st_r), begin(st_r) + l);
    if(r == 0) return val;
    st_r[0].second = st_r[0].first;
    for(int i = 1; i < r; ++i) st_r[i].second = st_r[i - 1].second + st_r[i].first;
    return val;
  }

  const Monoid &front() const { return st_l.empty() ? st_r.front().first : st_l.back().first; }
  const Monoid &back() const { return st_r.empty() ? st_l.front().first : st_r.back().first; }
  const Monoid &operator[](int k) const {
    if(k < 0) k += size();
    assert(0 <= k && k < int(size()));
    k -= st_l.size();
    return (k < 0) ? st_l[~k].first : st_r[k].first;
  }
  size_t size() const { return st_l.size() + st_r.size(); }
  void clear(){ st_l.clear(); st_r.clear(); }
  bool empty() const { return st_l.empty() && st_r.empty(); }
  operator bool() const { return !empty(); }

  Monoid top(const vector<pair<Monoid, Monoid>> &v) const { return v.empty() ? Monoid{} : v.back().second; }
};
