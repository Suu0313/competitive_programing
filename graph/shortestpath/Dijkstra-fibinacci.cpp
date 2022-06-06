template<typename T>
vector<T> Dijkstra(const Graph<T> &g, int s){
  FibonacciHeap<T, int> heap;
  vector nodes(g.size(), heap.get_np());
  vector<T> dist(g.size(), numeric_limits<T>::max());
  nodes[s] = heap.push(0, s); dist[s] = 0;

  while(!heap.empty()){
    auto[d, v] = heap.pop();

    for(auto&&e : g[v]){
      int u = e.to;
      T nd = d + e.cost;
      if(dist[u] <= nd) continue;
      dist[u] = nd;
      if(!nodes[u]){
        nodes[u] = heap.push(nd, u);
      }else{
        heap.decrease(nodes[u], nd);
      }
    }
  }
  return dist;
}
