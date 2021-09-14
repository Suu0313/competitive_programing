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
        pq.emplace(dist[e.to] = d + e.cost, e.to);
      }
    }
  }
  return dist;
}

template<typename T, typename T2, typename F>
vector<T> Dijkstra(const Graph<T2> &g, int s, const F &f){
  priority_queue<pair<T, int>,vector<pair<T, int>>, greater<>> pq;
  vector<T> dist(g.size(), -1);
  vector<bool> seen(g.size(), false);
  pq.emplace(0, s); dist[s] = 0;
  while(!pq.empty()){
    auto[d,v] = pq.top(); pq.pop();
    if(seen[v]) continue;
    seen[v] = true;
    for(auto&&e : g[v]){
      auto nd = f(d, e);
      if(dist[e.to]==-1 || dist[e.to]>nd){
        pq.emplace(dist[e.to] = nd, e.to);
      }
    }
  }
  return dist;
}

template<typename T>
pair<T, vector<int>> Dijkstra_restore(const Graph<T> &g, int s, int t){
  priority_queue<pair<T, int>,vector<pair<T, int>>, greater<>> pq;
  vector<T> dist(g.size(), -1);
  vector<int> pre(g.size(), -1);
  vector<bool> seen(g.size(), false);
  pq.emplace(0, s); dist[s] = 0;
  while(!pq.empty()){
    auto[d,v] = pq.top(); pq.pop();
    if(seen[v]) continue;
    seen[v] = true;
    for(auto&&e : g[v]){
      if(dist[e.to]==-1 || dist[e.to]>d+e.cost){
        pre[e.to] = v;
        pq.emplace(dist[e.to] = d + e.cost, e.to);
      }
    }
  }
  if(!seen[t]) return {-1, {}};
  vector<int> log(1, t);
  for(int v = t; v != s; ){
    log.emplace_back(v = pre[v]);
  }
  reverse(begin(log), end(log));
  return {dist[t], log};
}
