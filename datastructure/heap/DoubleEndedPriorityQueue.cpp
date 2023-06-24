#pragma once

template<typename T>
struct DoubleEndedPriorityQueue{
  DoubleEndedPriorityQueue() = default;
  DoubleEndedPriorityQueue(const DoubleEndedPriorityQueue&) = default;
  DoubleEndedPriorityQueue(DoubleEndedPriorityQueue&&) = default;
  DoubleEndedPriorityQueue &operator=(const DoubleEndedPriorityQueue&) = default;
  DoubleEndedPriorityQueue &operator=(DoubleEndedPriorityQueue&&) = default;

  vector<T> c;
  DoubleEndedPriorityQueue(const vector<T> &c): c(c) { make_heap(); }
  template<class Iiter>
  DoubleEndedPriorityQueue(Iiter first, Iiter last): c(first, last) { make_heap(); }

  void reserve(size_t n){ c.reserve(n); }
  size_t size() const { return c.size(); }
  bool empty() const { return c.empty(); }
  explicit operator bool() const { return !c.empty(); }

  const T& get_min() const { return c.at(size() > size_t(1)); }

  const T& get_max() const { return c.front(); }

  void push(const T &x){
    c.push_back(x);
    lift_up(c.size() - 1);
  }

  template <class... Args>
  void emplace_back(Args&&... args){
    c.emplace_back(args...);
    lift_up(c.size() - 1);
  }

  void pop_min() {
    if(c.size() < size_t(3)){
      c.pop_back();
    }else{
      swap(c[1], c.back()); c.pop_back();
      lift_up(down(1));
    }
  }

  void pop_max() {
    if(c.size() < size_t(2)){
      c.pop_back();
    }else{
      swap(c.front(), c.back()); c.pop_back();
      lift_up(down(0));
    }
  }


  size_t lift_up(size_t k, size_t root = 1){
    if((k | 1) != c.size() && c[k & ~1] < c[k | 1]){
      swap(c[k], c[k ^ 1]); k ^= 1;
    }
    
    for(size_t p; root < k && c[p = par(k)] < c[k]; k = p) swap(c[p], c[k]);
    for(size_t p; root < k && c[k] < c[p = (par(k)|1)] ; k = p) swap(c[p], c[k]);

    return k;
  }

  size_t down(size_t k){
    size_t n = c.size();
    if(k & 1){
      for(size_t i; 2 * k + 1 < n; k = i){
        i = 2 * k + 3;
        if(n <= i || c[i - 2] < c[i]) i -= 2;
        if(n <= i || !(c[i] < c[k])) break;
        swap(c[i], c[k]);
      }
    }else{
      for(size_t i; 2 * k + 2 < n; k = i){
        i = 2 * k + 4;
        if(n <= i ||  c[i] < c[i - 2]) i -= 2;
        if(n <= i || !(c[k] < c[i])) break;
        swap(c[i], c[k]);
      }
    }
    return k;
  }

private:

  constexpr size_t par(size_t k) const { return ((k >> 1) - 1) & ~1; }

  void make_heap(){
    for(size_t k = c.size(); k--; ){
      if(k & 1 && c[k - 1] < c[k]) swap(c[k - 1], c[k]);
      lift_up(down(k), k);
    }
  }
};
