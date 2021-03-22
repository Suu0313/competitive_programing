template<typename T>
vector<T> Dijkstra(const Graph<T> &g, int s){
  priority_queue<pair<T, int>,vector<pair<T, int>>, greater<>> pq;
  vector<T> dist(g.size(), -1);
  vector<bool> seen(g.size(), false);
  pq.emplace(0, s); dist[s] = 0;
  while(!pq.empty()){
    auto[d,v] = pq.top(); pq.pop();
    if(seen[v]) continue;
    seen[v] = true;
    for(auto&&e : g[v]){
      if(dist[e.to]==-1 || dist[e.to]>d+e.cost){
        dist[e.to] = d + e.cost;
        pq.emplace(dist[e.to], e.to);
      }
    }
  }
  return dist;
}
