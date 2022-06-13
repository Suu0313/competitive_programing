template<typename T>
vector<T> montmort_number(int n){
  vector<T> dp(n + 1, 1);
  for(int i = 1; i <= n; ++i){
    dp[i] = dp[i-1] * i + (i%2 == 0 ? 1 : -1);
  }
  return dp;
}
