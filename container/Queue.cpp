#pragma once

template<typename T>
struct Queue : queue<T>{
  using queue<T>::queue;
  explicit operator bool() const { return !(*this).empty(); }
  T Pop(){ T res = this->front(); this->pop(); return res; }
  void clear(){ (*this) = Queue(); }
};
