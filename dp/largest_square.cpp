#pragma once

template<typename T>
int largest_square(const vector<vector<T>> &tl){
  int h = int(tl.size()), w = int(tl[0].size());
  vector<int> dp(w);
  for(int i = 0; i < w; ++i) dp[i] = !tl[0][i];
  int ans = *max_element(begin(dp), end(dp));

  for(int i = 1; i < h; ++i){
    vector<int> ndp(w); swap(dp, ndp);
    dp[0] = !tl[i][0];
    for(int j = 1; j < w; ++j){
      if(tl[i][j]) continue;
      dp[j] = min({dp[j-1], ndp[j], ndp[j-1]}) + 1;
    }
    ans = max(ans, *max_element(begin(dp), end(dp)));
  }
  return ans;
}
