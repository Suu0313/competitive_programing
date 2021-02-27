template<typename T>
vector<T> slide_min(const vector<T> &v, int k){
  int n = SZ(v);
  deque<int> deq;
  vector<T> res;
  REP(i,n){
    while(!deq.empty() && v.at(deq.back()) >= v.at(i)){
      deq.POB();
    }
    deq.PB(i);
    if(i-k+1 >= 0){
      res.EB(v.at(deq.front()));
      if(deq.front() == i - k + 1) deq.pop_front();
    }
  }
  return res;
}