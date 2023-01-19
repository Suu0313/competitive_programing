template <class Cap>
struct Dinic{
  using cap_type = Cap;
  int n;
  struct edge{
    int to, rev;
    Cap cap;
    edge(int to, int rev, Cap cap) : to(to), rev(rev), cap(cap) {}
  };
  vector<pair<int,int>> pos;
  vector<vector<edge>> graph;
  
  Dinic(): n(0) {}
  Dinic(int n): n(n), graph(n) {}

  int add_edge(int from, int to, Cap cap){
    int res = pos.size();
    pos.emplace_back(from, graph.at(from).size());
    graph.at(from).emplace_back(to, graph.at(to).size(), cap);
    graph.at(to).emplace_back(from, graph.at(from).size()-1, 0);
    return res;
  }

  void change_edge(int i, Cap new_cap, Cap new_flow){
    auto& e = graph.at(pos.at(i).first).at(pos.at(i).second);
    auto& re = graph.at(e.to).at(e.rev);
    e.cap = new_cap - new_flow;
    re.cap = new_flow;
  }

  Cap flow(int s, int t){
    return flow(s, t, numeric_limits<Cap>::max());
  }
  Cap flow(int s, int t, Cap flow_limit){
    vector<int> level(n), iter(n);

    auto bfs = [&](){
      fill(level.begin(), level.end(), -1);
      level.at(s) = 0;
      queue<int> que;
      que.push(s);
      while(!que.empty()){
        int v = que.front(); que.pop();
        for(auto e : graph.at(v)){
          if(e.cap==0 || level.at(e.to)>=0) continue;
          level.at(e.to) = level.at(v)+1;
          if(e.to == t) return;
          que.push(e.to);
        }
      }
    };
    auto dfs = [&](auto self, const int v, Cap up){
      if(v == s) return up;
      Cap res = 0;
      int lv = level.at(v);
      for(int i = iter.at(v); i < int(graph.at(v).size()); i++){
        edge &e = graph.at(v).at(i);
        if(lv<=level.at(e.to) || graph.at(e.to).at(e.rev).cap==0) continue;
        Cap d = self(self, e.to, min(up-res, graph.at(e.to).at(e.rev).cap));
        if(d <= 0) continue;
        graph.at(v).at(i).cap += d;
        graph.at(e.to).at(e.rev).cap -= d;
        res += d;
        if(res == up) return res;
      }
      level.at(v) = n;
      return res;
    };

    Cap flow = 0;
    while(flow < flow_limit){
      bfs();
      if(level.at(t) == -1) break;
      fill(iter.begin(), iter.end(), 0);
      Cap f = dfs(dfs, t, flow_limit - flow);
      if(!f) break;
      flow += f;
    }
    return flow;
  }

  vector<bool> min_cut(int s){
    vector<bool> visited(n,false);
    queue<int> que;
    que.push(s);
    while(!que.empty()){
      int p = que.front(); que.pop();
      visited.at(p) = true;
      for(auto e : graph.at(p)){
        if(e.cap && !visited.at(e.to)){
          visited.at(e.to) = true;
          que.push(e.to);
        }
      }
    }
    return visited;
  }

  struct egdeinfo{
    int from, to;
    Cap cap, flow;
    egdeinfo(int from, int to, Cap cap, Cap flow):from(from), to(to), cap(cap), flow(flow) {}
  };
  egdeinfo get_edge(int i){
    auto [x,y] = pos.at(i);
    auto e = graph.at(x).at(y);
    auto re = graph.at(e.to).at(e.rev);
    return egdeinfo(x, e.to, e.cap+re.cap, re.cap);
  }
  vector<egdeinfo> edges(){
    vector<egdeinfo> res;
    int m = pos.size();
    res.reserve(m);
    for(int i = 0; i < m; i++) res.emplace_back(get_edge(i));
    return res;
  }
};
