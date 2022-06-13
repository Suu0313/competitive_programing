template<typename T>
vector<vector<T>> partition_table(int n, int k){
  vector<vector<T>> dp(n + 1, vector<T>(k + 1));
  dp[0][0] = 1;
  for(int i = 0; i <= n; i++){
    for(int j = 1; j <= k; j++){
      dp[i][j] = dp[i][j - 1];
      if(i >= j) dp[i][j] += dp[i - j][j];
    }
  }
  return dp;
}
