#pragma once

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
