template<typename T>
struct Stack : stack<T>{
  using stack<T>::stack;
  explicit operator bool() const { return !(*this).empty(); }
  T Pop(){ T res = this->top(); this->pop(); return res; }
  void clear(){ (*this) = Stack(); }
};
