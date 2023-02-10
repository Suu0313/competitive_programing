#pragma once

template<typename T>
struct ReversibleDeque{
  deque<T> dq;
  bool rev = false;

  ReversibleDeque() = default;
  ReversibleDeque(size_t n, const T &v): dq(n, v), rev(false) {}
  ReversibleDeque(size_t n): dq(n), rev(false) {}
  template <class InputIterator>
  ReversibleDeque(InputIterator first, InputIterator last): dq(first, last), rev(false) {}
  ReversibleDeque(initializer_list<T> il): dq(il), rev(false) {}

  size_t size() const { return dq.size(); }

  T &operator[](size_t n){ return rev ? dq[size() - n - 1] : dq[n]; }
  const T &operator[](size_t n) const { return rev ? dq[size() - n - 1] : dq[n]; }

  T &front(){ return rev ? dq.back() : dq.front(); }
  const T &front() const { return rev ? dq.back() : dq.front(); }

  T &back(){ return rev ? dq.front() : dq.back(); }
  const T &back() const { return rev ? dq.front() : dq.back(); }

  void clear(){ dq.clear(); }
  void reverse(){ rev = !rev; }
  
  void push_front(const T &x){
    if(rev) dq.push_back(x);
    else dq.push_front(x);
  }
  void push_front(T &&x){
    if(rev) dq.push_back(x);
    else dq.push_front(x);
  }

  void push_back(const T &x){
    if(rev) dq.push_front(x);
    else dq.push_back(x);
  }
  void push_back(T &&x){
    if(rev) dq.push_front(x);
    else dq.push_back(x);
  }
};
