template <typename T>
T TSP(const vector<vector<T>> &dist, int s = -1, int t = -1, const T &inf = numeric_limits<T>::max()){
  const int n = dist.size();
  vector dp(1<<n, vector(n, inf));

  if(t == -1){
    if(s >= 0) dp.at(1<<s).at(s) = 0;
    else for(int i=0; i < n; i++) dp.at(1<<i).at(i) = 0;
  }else{
    if(s == t) dp.at(0).at(s) = 0;
    else if(s >= 0) dp.at(1<<s).at(s) = 0;
    else for(int i=0; i < n; i++) dp.at(0).at(i) = 0;
  }

  for(int bit = 0; bit < (1<<n); bit++)
    for(int i=0; i < n; i++) for(int j=0; j < n; j++)
      if((i != j)&&(~bit >> j & 1)&&(dp.at(bit).at(i) != inf))
        dp.at(bit|(1<<j)).at(j)
          = min(dp.at(bit|(1<<j)).at(j), dp.at(bit).at(i) + dist.at(i).at(j));
  
  if(t == -1){
    return *min_element(begin(dp.at((1<<n)-1)), end(dp.at((1<<n)-1)));
  }else{
    return dp.at((1<<n)-1).at(t);
  }
}
