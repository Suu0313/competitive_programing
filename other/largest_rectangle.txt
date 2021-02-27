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