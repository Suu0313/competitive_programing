template<class Compair = less<int>>
vector<int> CartesianTree(const vector<int> &a, const Compair &cmp = Compair{}){
  int n = int(a.size());
  vector<int> p(n, -1);
  stack<int> st;

  for(int i = 0; i < n; ++i){
    int c = -1;
    while(!st.empty() && cmp(a[i],  a[st.top()])){
      c = st.top(); st.pop();
    }
    
    if(c != -1) p[c] = i;
    if(!st.empty()) p[i] = st.top();
    st.push(i);
  }
  return p;
}
