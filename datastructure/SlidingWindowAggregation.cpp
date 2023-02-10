#pragma once

template <class SemiGroup>
struct SlidingWindowAggregation{
  stack<pair<SemiGroup, SemiGroup>> front_stack, back_stack;

  SlidingWindowAggregation(): front_stack(), back_stack(){}

  bool empty() const { return front_stack.empty() && back_stack.empty(); }

  size_t size() const { return front_stack.size() + back_stack.size(); }

  SemiGroup fold_all() const{
    if(this->empty()) return SemiGroup{};

    if(front_stack.empty()) return back_stack.top().second;
    if(back_stack.empty()) return front_stack.top().second;
    return front_stack.top().second + back_stack.top().second;
  }

  void push(const SemiGroup &x) {
    if(back_stack.empty()) back_stack.emplace(x, x);
    else back_stack.emplace(x, back_stack.top().second + x);
  }

  bool pop() {
    if(this->empty()) return false;
    if(front_stack.empty()){
      front_stack.emplace(back_stack.top().first, back_stack.top().first);
      back_stack.pop();
      while(!back_stack.empty()){
        front_stack.emplace(back_stack.top().first, back_stack.top().first + front_stack.top().second);
        back_stack.pop();
      }
    }
    front_stack.pop();
    return true;
  }
};
