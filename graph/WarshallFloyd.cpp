template<typename T>
void WarshallFloyd(vector<vector<T>> &g, T inf){
  const int n = g.size();
  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++)for(int j = 0; j < n; j++){
      if(g[i][k] == inf || g[k][j] == inf) continue;
      g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    }
  }
}

template<typename T>
bool isNegative(vector<vector<T>> &g){
  for(size_t i = 0; i < g.size(); i++){
    if(g[i][i] < 0) return true;
  }
  return false;
}