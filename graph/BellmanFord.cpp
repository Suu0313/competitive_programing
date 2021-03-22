template<typename T>
vector<T> BellmanFord(const Edges<T> &edges, int V, int s){
  const T inf = numeric_limits<T>::max();
  vector<T> dist(V, inf); dist[s] = 0;
  for(int i = 0; i < V-1; i++){
    for(auto&&e : edges){
      if(dist[e.src] == inf) continue;
      dist[e.to] = min(dist[e.to], dist[e.src] + e.cost);
    }
  }

  for(auto&&e : edges){
    if(dist[e.src] == inf) continue;
    if(dist[e.to] > dist[e.src] + e.cost) return vector<T>();
  }

  return dist;
}
