template<typename T>
Graph<T> DFSTree(const Graph<T> &g, int root = 0){
  vector<bool> seen(g.size()); seen[root] = true;
  stack<int> st; st.push(root);
  Graph<T> res(g.size());

  while(!st.empty()){
    int v = st.top(); st.pop();
    for(auto&&e : g[v]){
      if(seen[e]) continue;
      seen[e] = true;
      st.emplace(e);
      res.add_directed_edge(v, e.to, e.cost);
    }
  }
  return res;
}