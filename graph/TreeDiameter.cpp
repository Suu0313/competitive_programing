template<typename T>
struct TreeDiameter{
  Graph<T> g;
  TreeDiameter(const  Graph<T> &g): g(g) {}
  T solve(){
    auto p = dfs(0, -1);
    auto q = dfs(p.second, -1);
    return q.first;
  }
  private:
  pair<T, int> dfs(int v, int p){
    pair<T,int> res(0, v);
    for(auto&&e : g[v]){
      if(e.to == p) continue;
      auto cost = dfs(e.to, v);
      cost.first += e.cost;
      if(res < cost) res = cost;
    }
    return res;
  }
};
