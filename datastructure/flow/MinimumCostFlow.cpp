template<typename cap_t, typename cost_t>
struct PrimalDual{
  struct Edge{
    int to;
    cap_t cap;
    cost_t cost;
    size_t rev_idx;
    bool is_rev;
  };

  int n;
  vector<vector<Edge>> g;
  vector<cost_t> min_cost, potential;
  
  PrimalDual(int n): n(n), g(n), min_cost(n), potential(n) {}

  void add_edge(int from, int to, cap_t cap, cost_t cost){
    g[from].emplace_back((Edge){to, cap, cost, g[to].size(), false});
    g[to].emplace_back((Edge){from, 0, -cost, g[from].size()-1, true});
  }

  cost_t flow(int s, int t, cap_t flow_limit){
    using P = pair<cost_t, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    cost_t res = 0, inf = numeric_limits<cost_t>::max();
    vector<pair<int, int>> pre(n);

    while(flow_limit > 0){
      pq.emplace(0, s);
      min_cost.assign(n, inf);
      min_cost[s] = 0;

      while(!pq.empty()){
        auto[cost, v] = pq.top(); pq.pop();
        if(min_cost[v] < cost) continue;
        for(int i = 0, m = int(g[v].size()); i < m; ++i){
          Edge &e = g[v][i];
          cost_t ncost = cost + e.cost + potential[v] - potential[e.to];
          
          if(e.cap > 0 && min_cost[e.to] > ncost){
            assert(ncost >= 0);
            min_cost[e.to] = ncost;
            pq.emplace(ncost, e.to);
            pre[e.to] = make_pair(v, i);
          }
        }
      }

      if(min_cost[t] == inf) return -1;
      for(int v = 0; v < n; ++v) if(min_cost[v] != inf) potential[v] += min_cost[v];
      cap_t min_cap = flow_limit;
      for(int v = t; v != s; v = pre[v].first){
        auto[i, j] = pre[v];
        min_cap = min(min_cap, g[i][j].cap);
      }
      for(int v = t; v != s; v = pre[v].first){
        auto[i, j] = pre[v];
        g[i][j].cap -= min_cap;
        g[v][g[i][j].rev_idx].cap += min_cap;
      }
      flow_limit -= min_cap;
      res += min_cap * potential[t];
    }
    return res;
  }

  vector<cost_t> slope(int s, int t, cap_t flow_limit){
    using P = pair<cost_t, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    cost_t inf = numeric_limits<cost_t>::max();
    vector<pair<int, int>> pre(n);

    vector<cost_t> ret(1, 0);

    while(flow_limit > 0){
      pq.emplace(0, s);
      min_cost.assign(n, inf);
      min_cost[s] = 0;

      while(!pq.empty()){
        auto[cost, v] = pq.top(); pq.pop();
        if(min_cost[v] < cost) continue;
        for(int i = 0, m = int(g[v].size()); i < m; ++i){
          Edge &e = g[v][i];
          cost_t ncost = cost + e.cost + potential[v] - potential[e.to];
          
          if(e.cap > 0 && min_cost[e.to] > ncost){
            assert(ncost >= 0);
            min_cost[e.to] = ncost;
            pq.emplace(ncost, e.to);
            pre[e.to] = make_pair(v, i);
          }
        }
      }

      if(min_cost[t] == inf) return ret;
      for(int v = 0; v < n; ++v) if(min_cost[v] != inf) potential[v] += min_cost[v];
      cap_t min_cap = flow_limit;
      for(int v = t; v != s; v = pre[v].first){
        auto[i, j] = pre[v];
        min_cap = min(min_cap, g[i][j].cap);
      }
      for(int v = t; v != s; v = pre[v].first){
        auto[i, j] = pre[v];
        g[i][j].cap -= min_cap;
        g[v][g[i][j].rev_idx].cap += min_cap;
      }
      flow_limit -= min_cap;
      for(cap_t i = 0; i < min_cap; ++i){
        ret.push_back(ret.back() + potential[t]);
      }
    }
    return ret;
  }

  vector<pair<cap_t, cost_t>> slope_sparse(int s, int t, cap_t flow_limit){
    // ToDo
  }

  void remove_minus_dag(int s){
    queue<int> qu;
    vector<int> in(n);
    cost_t inf = numeric_limits<cost_t>::max();
    potential.assign(n, inf); potential[s] = 0;

    for(int i = 0; i < n; ++i){
      for(auto&&e : g[i]){
        if(e.is_rev) continue;
        ++in[e.to];
      }
    }

    for(int i = 0; i < n; ++i) if(in[i] == 0) qu.push(i);

    while(!qu.empty()){
      int v = qu.front(); qu.pop();
      for(auto&&e : g[v]){
        if(e.is_rev) continue;
        if(potential[v] != inf){
          potential[e.to] = min(potential[e.to], potential[v] + e.cost);
        }
        if(--in[e.to] == 0) qu.push(e.to);
      }
    }
  }
};
