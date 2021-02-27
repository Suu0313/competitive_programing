template <typename T>
int LIS(const vector<T> &a, bool fl = true) {
  const T LIM = numeric_limits<T>::max()/2;
  int N = SZ(a);
  vector<T> dp(N, LIM);
  for(auto&&x : a){
    if(fl) *LB(ALL(dp),x) = x;
    else *UB(ALL(dp),x) = x;
  }
  return LB(ALL(dp),LIM) - dp.begin();
}