template<typename T>
struct Deque : deque<T>{
  using deque<T>::deque;
  explicit operator bool() const { return !(*this).empty(); }
  T Popf(){ T res = this->front(); this->pop_front(); return res; }
  T Popb(){ T res = this->back(); this->pop_back(); return res; }
};
