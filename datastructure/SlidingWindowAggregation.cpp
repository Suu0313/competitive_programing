template <class T>
struct SlidingWindowAggregation{
  struct node{
    T val, sum;
    node(const T &val, const T &sum) : val(val), sum(sum){}
  };
  using OP = function<T(T,T)>;
  OP op;
  stack<node> front_stack, back_stack;

  SlidingWindowAggregation(const OP &op): op(op), front_stack(), back_stack(){}

  bool empty() const { return front_stack.empty() && back_stack.empty(); }

  size_t size() const { return front_stack.size() + back_stack.size(); }

  T fold_all() const{
    assert(!empty());
    if(front_stack.empty()) return back_stack.top().sum;
    if(back_stack.empty()) return front_stack.top().sum;
    return op(front_stack.top().sum, back_stack.top().sum);
  }

  void push(const T &x) {
    if(back_stack.empty()){
      back_stack.emplace(x,x);
    }else{
      T s{op(back_stack.top().sum, x)};
      back_stack.emplace(x,s);
    }
  }

  bool pop() {
    if(empty()) return false;
    if(front_stack.empty()){
      front_stack.emplace(back_stack.top().val,back_stack.top().val);
      back_stack.pop();
      while(!back_stack.empty()){
        T s{op(back_stack.top().val, front_stack.top().sum)};
        front_stack.emplace(back_stack.top().val, s);
        back_stack.pop();
      }
    }
    front_stack.pop();
    return true;
  }
};
