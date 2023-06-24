template<typename T, class Compair>
struct ErasablePriorityQueue{
  priority_queue<T, vector<T>, Compair> pq, lazy;
  ErasablePriorityQueue() = default;
  void normalize() {
    while(!pq.empty() && !lazy.empty() && pq.top() == lazy.top()) pq.pop(), lazy.pop();
  }

  void push(const T &e){ pq.push(e); }
  void erase(const T &e){ lazy.push(e); }
  T pop(){
    this->normalize();
    T e = pq.top(); pq.pop();
    return e;
  }
  T top(){
    this->normalize();
    return pq.top();
  }
  size_t size() const { return pq.size() - lazy.size(); }
  bool empty() const { return this->size() == 0; }
};
