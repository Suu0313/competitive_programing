template<typename T>
struct Set : set<T> {
  using set<T>::set;
  explicit operator bool() const { return !(*this).empty(); }
  Set operator|(const Set &s) const {
    Set res;
    set_union((*this).begin(), (*this).end(), s.begin(), s.end(), inserter(res, res.end()));
    return res;
  }
  Set &operator|=(const Set &s){
    for(auto&&e : s) this->insert(e);
    return (*this);
  }
  Set operator&(const Set &s) const {
    Set res;
    set_intersection((*this).begin(), (*this).end(), s.begin(), s.end(), inserter(res, res.end()));
    return res;
  }
  Set operator&=(const Set &s){ return (*this) = (*this) & s; }
  Set operator^(const Set &s) const {
    Set res;
    set_symmetric_difference((*this).begin(), (*this).end(), s.begin(), s.end(), inserter(res, res.end()));
    return res;
  }
  Set &operator^=(const Set &s){
    for(auto&&e : s){
      if(this->exist(e)) this->erase(e);
      else this->insert(e);
    }
    return (*this);
  }
  Set operator-(const Set &s) const {
    Set res;
    set_difference((*this).begin(), (*this).end(), s.begin(), s.end(), inserter(res, res.end()));
    return res;
  }
  Set &operator-=(const Set &s){
    for(auto&&e : s) this->erase(e);
    return (*this);
  }
  const T &operator[](int k) const {
    if(k >= 0) return *std::next(this->begin(), k);
    else return *std::prev(this->end(), -k);
  }
  bool exist(const T &x) const { return (*this).find(x) != (*this).end(); }
};
