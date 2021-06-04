template<typename T>
struct Queue : queue<T>{
  using queue<T>::queue;
  explicit operator bool() const { return !(*this).empty(); }
  T Pop(){ T res = this->front(); this->pop(); return res; }
  void clear(){ (*this) = Queue(); }
};
template<typename T>
struct Stack : stack<T>{
  using stack<T>::stack;
  explicit operator bool() const { return !(*this).empty(); }
  T Pop(){ T res = this->top(); this->pop(); return res; }
  void clear(){ (*this) = Stack(); }
};
template<typename T, typename Container = vector<T>, typename Compare = less<typename Container::value_type>>
struct prque : priority_queue<T, Container, Compare> {
  using priority_queue<T, Container, Compare>::priority_queue;
  explicit operator bool() const { return !(*this).empty(); }
  T Pop(){ T res = this->top(); this->pop(); return res; }
  void clear(){ (*this) = prque(); }
};
template<typename Container, typename Compare>
prque(Compare, Container) -> prque<typename Container::value_type, Container, Compare>;
template<typename T> using prquer = prque<T, vector<T>, greater<T>>;

template<typename T>
struct Deque : deque<T>{
  using deque<T>::deque;
  explicit operator bool() const { return !(*this).empty(); }
  T Popf(){ T res = this->front(); this->pop_front(); return res; }
  T Popb(){ T res = this->back(); this->pop_back(); return res; }
};


template<typename T>
struct Set : set<T> {
  using set<T>::set;
  explicit operator bool() const { return !(*this).empty(); }
  Set operator|(const Set &s) const {
    Set res;
    set_union((*this).begin(), (*this).end(), s.begin(), s.end(), inserter(res, res.end()));
    return res;
  }
  Set operator&(const Set &s) const {
    Set res;
    set_intersection((*this).begin(), (*this).end(), s.begin(), s.end(), inserter(res, res.end()));
    return res;
  }
  Set operator^(const Set &s) const {
    Set res;
    set_symmetric_difference((*this).begin(), (*this).end(), s.begin(), s.end(), inserter(res, res.end()));
    return res;
  }
  Set operator-(const Set &s) const {
    Set res;
    set_difference((*this).begin(), (*this).end(), s.begin(), s.end(), inserter(res, res.end()));
    return res;
  }
};
