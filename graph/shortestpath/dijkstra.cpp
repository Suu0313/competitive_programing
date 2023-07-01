#pragma once

#include "../Graph.cpp"

template<typename T>
vector<T> dijkstra(const Graph<T> &g, int s){
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

template<typename T>
vector<vector<T>> dijkstra_APSP(const Graph<T> &g){
  int n = int(g.size());
  vector<vector<T>> dist; dist.reserve(n);
  for(int v = 0; v < n; ++v) dist.push_back(Dijkstra(g, v));
  return dist;
}
