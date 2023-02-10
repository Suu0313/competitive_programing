#pragma once


template<typename T>
vector<T> knapsack_limitations(const vector<T> &v, const vector<int> &w, const vector<int> &m, int W){
  int n = int(v.size());
  vector<T> dp(W+1), dqv(W+1);
  vector<int> dqi(W+1);
  vector<bool> seen(W+1, false); seen[0] = true;

  for(int i = 0; i < n; ++i){
    if(w[i] == 0){
      for(int j = 0; j <= W; ++j){
        if(seen[j] && dp[j] < dp[j] + v[i] * m[i]) dp[j] =  dp[j] + v[i] * m[i];
      }
    }else{
      for(int a = 0; a < w[i]; ++a){
        int s = 0, t = 0;
        for(int j = 0; w[i]*j + a <= W; ++j){
          if(seen[w[i]*j + a]){
            auto val = dp[w[i]*j + a] - v[i] * j;
            while(s < t && dqv[t-1] < val) --t;
            dqv[t] = val; dqi[t++] = j;
          }
          if(s < t){
            dp[j*w[i] + a] = dqv[s] + v[i] * j;
            seen[j*w[i] + a] = true;
            if(dqi[s] == j-m[i]) ++s;
          }
        }
      }
    }
  }
  return dp;
}
