template<typename T>
T ChinesePostmanProblem(const Graph<T> &g){
  int n = int(g.size());
  T sum = 0;
  vector<int> vs;
  T inf = numeric_limits<T>::max();
  vector dist(n, vector(n, inf));
  for(int v = 0; v < n; ++v) dist[v][v] = 0;

  for(int v = 0; v < n; ++v){
    if(g.deg(v)&1) vs.push_back(v);
    for(auto&e : g[v]){
      sum += e.cost;
      dist[v][e] = min(dist[v][e], e.cost);
    }
  }

  sum /= 2;
  
  for(int k = 0; k < n; ++k){
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        if(dist[i][k] == inf || dist[k][j] == inf) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int m = int(vs.size());
  vector dp(1<<m, inf); dp[0] = 0;
  for(int bit = 0; bit < (1ll << m); ++bit){
    for(int i = 0; i < m; ++i){
      for(int j = 0; j < m; ++j){
        if(i == j) continue;
        if((bit>>i&1) == 0 || (bit>>j&1) == 0) continue;
        if(dp[bit-(1<<i)-(1<<j)] == inf) continue;
        if(dist[vs[i]][vs[j]] == inf) continue;
        dp[bit] = min(dp[bit], dp[bit-(1<<i)-(1<<j)] + dist[vs[i]][vs[j]]);
      }
    }
  }

  if(dp[(1<<m)-1] == inf) return inf;
  return sum + dp[(1<<m)-1];
}
