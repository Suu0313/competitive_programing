template<typename T>
pair<T, vector<vector<edge<T>>>> Prim(const vector<vector<edge<T>>> &g){
  T sum = 0;
  vector<vector<edge<T>>> mst(g.size());
  vector<bool> used(g.size());
  using tpii = tuple<T, int, int>;
  priority_queue<tpii, vector<tpii>, greater<>> pq;
  pq.emplace(0, 0, -1);
  while(!pq.empty()){
    auto[d, v, p] = pq.top(); pq.pop();
    if(used[v]) continue;
    used[v] = true;
    if(p >= 0){
      sum += d;
      mst[p].emplace_back(p, v, d);
      mst[v].emplace_back(v, p, d);
    }
    for(auto&&e : g[v]){
      if(used[e.to]) continue;
      pq.emplace(e.cost, e.to, v);
    }
  }
  return {sum, mst};
}