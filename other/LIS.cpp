template <typename T>
int LIS(const vector<T> &a, bool fl = true) {
  const T LIM = numeric_limits<T>::max()/2;
  int N = a.size();
  vector<T> dp(N, LIM);
  for(auto&&x : a){
    if(fl) *lower_bound(dp.begin(), dp.end(), x) = x;
    else *upper_bound(dp.begin(), dp.end(), x) = x;
  }
  return lower_bound(dp.begin(), dp.end(), LIM) - dp.begin();
}
