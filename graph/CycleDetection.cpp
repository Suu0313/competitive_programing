template<typename T>
struct CycleDetection{
  Graph<T> g;
  vector<int> used;
  vector<pair<int, int>> pre, cycle;
  CycleDetection(const Graph<T> &g): g(g), used(g.size()), pre(g.size()) {}

  bool dfs(int v){
    used[v] = 1;
    for(auto&&e : g[v]){
      if(used[e] == 0){
        pre[e] = make_pair(v, e);
        if(dfs(e)) return true;
      }else if(used[e] == 1){
        int p = v;
        while(p != e){
          cycle.emplace_back(pre[p]);
          p = pre[p].first;
        }
        cycle.emplace_back(v, e);
        return true;
      }
    }
    used[v] = 2;
    return false;
  }

  vector<pair<int, int>> find(){
    for(int i = 0; i < (int)g.size(); i++){
      if(used[i]==0 && dfs(i)){
        reverse(cycle.begin(), cycle.end());
        return cycle;
      }
    }
    return {};
  }
};
