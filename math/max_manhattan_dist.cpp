template<typename T> // n個,k次元の点
T max_manhattan_distance(vector<vector<T>> &v){
  int n = v.size();
  int k = v[0].size();
  T res = 0;
  vector<T> f(n);

  for(int bit = 0; bit < (1 << (k-1)); bit++){
    for(int j = 0; j < n; j++){
      f.at(j) = v.at(j).at(0);
      for(int i = 0; i < k-1; i++){
        if((bit>>i)&1){
          f.at(j) += v.at(j).at(i+1);
        }else{
          f.at(j) -= v.at(j).at(i+1);
        }
      }
    }
    res = max(res, max(f) - min(f));
  }
  return res;
}
