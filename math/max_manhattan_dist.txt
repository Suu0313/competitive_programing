template<typename T> // n個,k次元の点
T max_manhattan_distance(vector<vector<T>> &v){
  int n = SZ(v);
  int k = SZ(v.at(0));
  T res = 0;
  vector<T> f(n);

  BREP(bit, k-1){  
    REP(j,n){
      f.at(j) = v.at(j).at(0);
      REP(i,k-1){
        if((bit>>i)&1){
          f.at(j) += v.at(j).at(i+1);
        }else{
          f.at(j) -= v.at(j).at(i+1);
        }
      }
    }
    chmax(res, Vmax(f)-Vmin(f));
  }
  return res;
}