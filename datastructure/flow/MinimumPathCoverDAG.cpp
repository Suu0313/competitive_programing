template<class F>
struct MinimumPathCoverDAG{
  int n, s, t;
  F flow;

  MinimumPathCoverDAG() = default;
  MinimumPathCoverDAG(int n): n(n), s(n * 2), t(s + 1), flow(t + 1) {
    for(int i = 0; i < n; ++i){
      flow.add_edge(s, i, 1);
      flow.add_edge(i + n, t, 1);
    }
  }

  void add_edge(int u, int v){
    flow.add_edge(u, v + n, 1);
  }

  int solve(){
    return n - flow.flow(s, t);
  }
};
