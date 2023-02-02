template<typename T, class Compair>
vector<pair<int, int>> satisfied_sections(const vector<T> &a, const Compair &cmp){
  int n = int(a.size());
  vector<pair<int, int>> res(n);
  stack<int> st;
  for(int i = 0; i < n; ++i){
    while(!st.empty() && cmp(a[i], a[st.top()])) st.pop();
    res[i].first = st.empty() ? 0 : (st.top() + 1);
    st.push(i);
  }
  
  while(!st.empty()) st.pop();

  for(int i = n-1; i >= 0; --i){
    while(!st.empty() && cmp(a[i], a[st.top()])) st.pop();
    res[i].second = st.empty() ? n : st.top();
    st.push(i);
  }

  return res;
}
