template<typename T>
struct EppsteinsAlgorithm{
  int n;
  Graph<T> g, rg;
  vector<T> rdist;
  vector<vector<int>> chs;
  vector<int> par, idx;

  EppsteinsAlgorithm(int n): n(n), g(n), rg(n) {}

  void add_directed_edge(int s, int t, const T &d){
    g.add_directed_edge(s, t, d);
    rg.add_directed_edge(t, s, d);
  }

  void dijkstra_rev(int t){
    rdist.assign(n, -1);
    chs.resize(n);
    par.assign(n, -1);
    idx.assign(n, -1);
    rdist[t] = 0;
    priority_queue pq{greater<>{}, vector<pair<T, int>>()};
    pq.emplace(0, t);
    vector<bool> seen(n);
    while(!pq.empty()){
      auto[d, v] = pq.top(); pq.pop();
      if(seen[v]) continue;
      seen[v] = true;

      if(par[v] != -1) chs[par[v]].push_back(v);

      for(const auto& e : rg[v]){
        auto nd = d + e.cost;
        if(rdist[e] == -1 || nd < rdist[e]){
          rdist[e] = nd;
          par[e] = v;
          idx[e] = e.idx;
          pq.emplace(nd, e);
        }
      }
    }
  }

  using Heap = PersistentLeftistHeap<pair<T, int>>;
  using Np = typename Heap::Np;
  Heap heap;
  vector<Np> h;

  void build_heap(int t){
    h.assign(n, Heap::make_root());
    queue<int> qu; qu.push(t);
    while(!qu.empty()){
      int v = qu.front(); qu.pop();

      for(const auto&e : g[v]){
        if(e.idx != idx[v] && rdist[e.to] != -1)
          h[v] = heap.push(h[v], {e.cost - rdist[v] + rdist[e.to], e.to});
      }

      if(par[v] != -1) h[v] = heap.meld(h[v], h[par[v]]);
      for(int e : chs[v]) qu.push(e);
    }
  }

  vector<T> k_shortest_walk(int s, int t, size_t k){
    dijkstra_rev(t);
    if(rdist[s] == -1) return {};
    build_heap(t);

    using P = pair<T, Np>;

    auto cmp = [&](const P &a, const P &b){ return a.first > b.first; };
    priority_queue pq{cmp, vector<P>()};

    auto get_v = [&](const Np &p){ return p->val.first; };

    Np h_s = Heap::make_root();
    h_s = heap.push(h_s, {rdist[s], s});
    pq.emplace(rdist[s], h_s);
    
    vector<T> ans;

    while(!pq.empty()){
      auto[d, p] = pq.top(); pq.pop();
      auto[cost, to] = p->val;
      ans.push_back(d);
      if(ans.size() == k) break;

      if(p->l) pq.emplace(d + get_v(p->l) - cost, p->l);
      if(p->r) pq.emplace(d + get_v(p->r) - cost, p->r);
      if(h[to]) pq.emplace(d + get_v(h[to]), h[to]);
    }

    return ans;
  }
};
