#pragma once

#include "./Point.cpp"


template<typename T>
double bitonicTSP(const Polygon<T> &ps){
  int n = int(ps.size());
  vector dp(n, vector(n, 0.0));
  for(int j = 1; j < n; ++j){
    for(int i = 0; i < j; ++i){
      if(i == 0 && j == 1) dp[i][j] = ps[i].dist(ps[j]);
      else if(i < j-1) dp[i][j] = dp[i][j-1] + ps[j-1].dist(ps[j]);
      else{
        dp[i][j] = numeric_limits<double>::infinity();
        for(int k = 0; k < i; ++k) dp[i][j] = min(dp[i][j], dp[k][i] + ps[j].dist(ps[k]));
      }
    }
  }
  double ans = numeric_limits<double>::infinity();
  for(int k = 0; k < n-1; ++k) ans = min(ans, dp[k][n-1] + ps[k].dist(ps[n-1]));
  return ans;
}
