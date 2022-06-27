int levenshtein_distance(const string &s, const string &t){
  int n = int(s.size()), m = int(t.size());
  vector dp(n+1, vector(m+1,n+m));
  for(int i = 0; i < n+1; ++i) dp[i][0] = i;
  for(int i = 0; i < m+1; ++i) dp[0][i] = i;

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      dp[i+1][j+1] = min(
        {dp[i+1][j+1], dp[i][j] + (s[i] != t[j]), dp[i+1][j] + 1, dp[i][j+1] + 1}
      );
    }
  }

  return dp[n][m];
}
