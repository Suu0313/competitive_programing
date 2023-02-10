#pragma once

template<typename T>
struct CumulativeSum{
  int n, m;
  bool is_built;
  vector<vector<T>> sum;
  CumulativeSum(int n, int m) : n(n), m(m), is_built(false), sum(n+1, vector<T>(m+1)) {}
  CumulativeSum(const vector<vector<T>> &v, bool isbuilt = false){
    is_built = isbuilt;
    if(!isbuilt){
      n = v.size(); m = v.at(0).size();
      sum.assign(n+1, vector<T>(m+1, 0));
      for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
          sum.at(i+1).at(j+1) = v.at(i).at(j);
        }
      }
    }else{
      n = v.size()-1; m = v.at(0).size()-1;
      sum = v;
    }
  }
  vector<T> &operator[](int k) { return sum.at(k); }
  const vector<T> &operator[](int k) const { return sum.at(k); }
  vector<T> &at(int k) { return sum.at(k); }
  const vector<T> &at(int k) const { return sum.at(k); }

  void build(){
    is_built = true;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        sum.at(i+1).at(j+1) += sum.at(i+1).at(j);
      }
    }
    for(int j=0; j<m; j++){
      for(int i=0; i<n; i++){
        sum.at(i+1).at(j+1) += sum.at(i).at(j+1);
      }
    }
  }
  T query(int x1, int x2, int y1, int y2){
    if(!is_built) build();
    return sum.at(x2).at(y2)-sum.at(x1).at(y2)-sum.at(x2).at(y1)+sum.at(x1).at(y1);
  }
};
