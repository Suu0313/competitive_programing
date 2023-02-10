template<typename T>
pair<vector<T>, vector<int>> ShortestPathFasterAlgorithm(const Graph<T> &g, int s){
  int n = int(g.size());
  vector<T> dist(n);
  vector<int> inque(n), cnt(n), state(n);
  stack<int> st;
  st.push(s); inque[s] = cnt[s] = state[s] = 1; 

  while(!st.empty()){
    int v = st.top(); st.pop();
    inque[v] = 0;

    for(auto&e : g[v]){
      if(state[e.to] == 2) continue;

      if(state[v] == 2){
        state[e.to] = 2;
        if(!inque[e.to]){
          inque[e.to] = 1;
          st.push(e.to);
        }
        continue;
      }

      if(state[e.to] && (dist[v] + e.cost >= dist[e.to])) continue;
      dist[e.to] = dist[v] + e.cost;
      state[e.to] = 1;
      if(!inque[e.to]){
        if(n <= ++cnt[e.to]) state[e.to] = 2;
        inque[e.to] = 1;
        st.push(e.to);
      }
    }
  }
  return {dist, state};
}
