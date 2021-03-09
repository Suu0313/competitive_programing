template<typename T>
vector<T> slide_min(const vector<T> &v, int k){
  int n = SZ(v);
  deque<int> deq;
  vector<T> res;
  for(int i = 0; i < n; ++i){
    while(!deq.empty() && v.at(deq.back()) >= v.at(i)){
      deq.pop_back();
    }
    deq.push_back(i);
    if(i-k+1 >= 0){
      res.emplace_back(v.at(deq.front()));
      if(deq.front() == i - k + 1) deq.pop_front();
    }
  }
  return res;
}
