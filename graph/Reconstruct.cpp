template<typename T>
vector<vector<T>> Reconstruct(const Graph<T> &g, const vector<int> &r){
  int m = int(r.size());
  vector<vector<T>> res(m, vector<T>(m));
  for(int i = 0; i < m; ++i){
    auto dist = Dijkstra(g, r[i]);
    for(int j = 0; j < m; ++j) res[i][j] = dist[r[j]];
  }
  return res;
}
