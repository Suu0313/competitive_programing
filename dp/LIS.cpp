template <typename T>
vector<T> LIS(const vector<T> &a, bool fl = true) {
  int n = a.size();
  if(n == 0) return {};
  vector<T> dp(n, numeric_limits<T>::max());
  vector<int> idx(n);
  for(int i = 0; i < n; i++){
    if(fl) idx[i] = std::distance(dp.begin(), lower_bound(dp.begin(), dp.end(), a[i]));
    else idx[i] = std::distance(dp.begin(), upper_bound(dp.begin(), dp.end(), a[i]));
    dp[ idx[i] ] = a[i];
  }
  int m = *max_element(idx.begin(), idx.end());
  vector<T> res(m+1);
  for(int i = n-1; i >= 0; i--){
    if(idx[i] == m) res[m--] = a[i];
  }
  return res;
}
