#pragma once

template<typename T>
T largest_rectangle(vector<T> height){
  stack<int> st;
  height.push_back(0);
  vector<int> left(height.size());
  T res = 0;
  for(int i = 0; i < int(height.size()); i++) {
    while(!st.empty() && height[st.top()] >= height[i]) {
      res = max(res, (i - left[st.top()] - 1) * height[st.top()]);
      st.pop();
    }
    left[i] = st.empty() ? -1 : st.top();
    st.emplace(i);
  }
  return res;
}

template<typename T>
int largest_rectangle(const vector<vector<T>> &tl){
  int w = int(tl[0].size());
  vector<int> dp(w);
  int ans = 0;
  for(auto&&v : tl){
    for(int i = 0; i < w; ++i){
      if(v[i]) dp[i] = 0;
      else ++dp[i];
    }
    ans = max(ans, largest_rectangle(dp));
  }
  return ans;
}
