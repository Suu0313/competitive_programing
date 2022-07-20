template<typename T>
struct DequeAggregation{
  using F = function<T(T, T)>;
  T id;
  F op;
  vector<pair<T, T>> st_l, st_r;

  DequeAggregation() = default;
  DequeAggregation(const T &id, const F &op): id(id), op(op) {}
  template<typename Iiter>
  DequeAggregation(const T &id, const F &op, Iiter first, Iiter last): id(id), op(op) {
    for(; first != last; ++first) push_back(*first);
  }
  template<class Container>
  DequeAggregation(const T &id, const F &op, const Container &c): DequeAggregation(id, op, begin(c), end(c)) {}

  T prod() const { return op(top(st_l), top(st_r)); }
  void push_back(const T &x){ st_r.emplace_back(x, op(top(st_r), x)); }
  void push_front(const T &x){ st_l.emplace_back(x, op(x, top(st_l))); }

  T pop_back(){
    assert(!empty());
    if(!st_r.empty()){
      T val = move(st_r.back().first);
      st_r.pop_back();
      return val;
    }
    int sz = int(st_l.size()), l = sz >> 1, r = sz - l;
    for(int i = r - 1; i > 0; --i) push_back(move(st_l[i].first));
    T val = move(st_l.front().first);
    st_l.erase(begin(st_l), begin(st_l) + r);
    if(l == 0) return val;
    st_l[0].second = st_l[0].first;
    for(int i = 1; i < l; ++i) st_l[i].second = op(st_l[i].first, st_l[i - 1].second);
    return val;
  }

  T pop_front(){
    assert(!empty());
    if(!st_l.empty()){
      T val = move(st_l.back().first);
      st_l.pop_back();
      return val;
    }
    int sz = int(st_r.size()), r = sz >> 1, l = sz - r;
    for(int i = l - 1; i > 0; --i) push_front(move(st_r[i].first));
    T val = move(st_r.front().first);
    st_r.erase(begin(st_r), begin(st_r) + l);
    if(r == 0) return val;
    st_r[0].second = st_r[0].first;
    for(int i = 1; i < r; ++i) st_r[i].second = op(st_r[i - 1].second, st_r[i].first);
    return val;
  }

  const T &front() const { return st_l.empty() ? st_r.front().first : st_l.back().first; }
  const T &back() const { return st_r.empty() ? st_l.front().first : st_r.back().first; }
  const T &operator[](int k) const {
    if(k < 0) k += size();
    assert(0 <= k && k < int(size()));
    k -= st_l.size();
    return (k < 0) ? st_l[~k].first : st_r[k].first;
  }
  size_t size() const { return st_l.size() + st_r.size(); }
  void clear(){ st_l.clear(); st_r.clear(); }
  bool empty() const { return st_l.empty() && st_r.empty(); }
  operator bool() const { return !empty(); }

  T top(const vector<pair<T, T>> &v) const { return v.empty() ? id : v.back().second; }
};
