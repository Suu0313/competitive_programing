#pragma once

#include "..\\Graph.cpp"

#include ".\\shortest_path_faster_algorithm.cpp"

template<typename T>
vector<vector<T>> johnson_APSP(const Graph<T> &g){
  int n = int(g.size());
  Graph<T> g_s(n + 1), ng(n);
  for(int v = 0; v < n; ++v){
    for(auto&&e : g[v]) g_s.add_directed_edge(v, e.to, e.cost);
    g_s.add_directed_edge(n, v, 0);
  }
  auto[dist_s, state] = shortest_path_faster_algorithm(g_s, n);
  for(int v = 0; v < n; ++v){
    if(state[v] == 2) return {};
  }
  for(int v = 0; v < n; ++v){
    for(auto&&e : g[v]) ng.add_directed_edge(v, e.to, e.cost + dist_s[v] - dist_s[e.to]);
  }
  vector<vector<T>> dist; dist.reserve(n);
  auto inf = numeric_limits<T>::max();
  for(int v = 0; v < n; ++v){
    dist.push_back(Dijkstra(ng, v));
    for(int u = 0; u < n; ++u){
      if(dist[v][u] != inf) dist[v][u] -= dist_s[v] - dist_s[u];
    }
  }
  return dist;
}
