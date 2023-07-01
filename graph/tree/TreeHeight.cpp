#pragma once

#include "../Graph.cpp"

template<typename T>
struct TreeHeight{
  Graph<T> g;
  vector<T> height;
  TreeHeight(const Graph<T> &g): g(g), height(g.size()) {
    const size_t n = g.size();
    vector<T> height_p(n, -1), height_q(n, -1);
    int p = dfs(0, height_p);
    height_p.assign(n, -1);
    int q = dfs(p, height_p);
    dfs(q, height_q);

    for(size_t i = 0; i < n; i++){
      height[i] = max(height_p[i], height_q[i]);
    }
  }
private:
  int dfs(int s, vector<T> &h){
    stack<int> st; st.push(s);
    int t = s; T d = 0; h[s] = 0;
    while(!st.empty()){
      int v = st.top(); st.pop();
      for(auto&&e : g[v]){
        if(h[e.to] >= 0) continue;
        h[e.to] = h[v] + e.cost;
        if(d < h[e.to]){
          t = e.to; d = h[e.to];
        }
        st.push(e.to);
      }
    }
    return t;
  }
};
