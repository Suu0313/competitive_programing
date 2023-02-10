#pragma once

template<typename T>
vector<T> partition_function_table(int n){
  vector<T> dp(n + 1); dp[0] = 1;
  for(int i = 1; i <= n; ++i){
    for(int k = 1, p = 1; i >= k*(3*k - 1)/2; ++k, p = -p) dp[i] += dp[i - k*(3*k - 1)/2] * p;
    for(int l = 1, p = 1; i >= l*(3*l + 1)/2; ++l, p = -p) dp[i] += dp[i - l*(3*l + 1)/2] * p;
  }
  return dp;
}
