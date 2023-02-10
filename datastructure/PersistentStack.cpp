#pragma once

template<typename T>
struct PersistentStack{
  struct Node;
  using Np = shared_ptr<Node>;
  template<typename... Args>
  static Np make_np(Args&&... args){ return make_shared<Node>(forward<Args>(args)...); }

  struct Node{
    Np next;
    T value;

    template<typename... Args>
    Node(const Np &next, Args&&... args): next(next), value(forward<Args>(args)...) {}
  };

  Np ptr = {};

  constexpr PersistentStack() = default;
  explicit PersistentStack(const Np &ptr): ptr(ptr) {}
  explicit PersistentStack(Np &&ptr): ptr(move(ptr)) {}

  using self = PersistentStack;

  bool empty() const { return !ptr; }

  const T &top() const {
    assert(!empty());
    return ptr->value;
  }

  T &top(){
    assert(!empty());
    return ptr->value;
  }

  template<typename... Args>
  self emplace(Args&&... args) const { return self(make_np(ptr, forward<Args>(args)...)); }
  self push(const T &x) const { return emplace(x); }
  self push(T &&x) const { return emplace(move(x)); }

  self pop() const {
    assert(!empty());
    return self(ptr->next);
  }
};
