#pragma once

template<typename T>
struct Imos2D{
  int n, m;
  vector<vector<T>> sum;
  Imos2D(int n, int m) : n(n), m(m) {
    sum.assign(n+1, vector<T>(m+1, 0));
  }
  
  vector<T> &operator[](int k) { return sum.at(k); }
  const vector<T> &operator[](int k) const { return sum.at(k); }
  vector<T> &at(int k) { return sum.at(k); }
  const vector<T> &at(int k) const { return sum.at(k); }

  void build(){
    for(int i=0; i<=n; i++){
      for(int j=0; j<m; j++){
        sum.at(i).at(j+1) += sum.at(i).at(j);
      }
    }
    for(int j=0; j<=m; j++){
      for(int i=0; i<n; i++){
        sum.at(i+1).at(j) += sum.at(i).at(j);
      }
    }
  }
  void add(int x1, int x2, int y1, int y2, T t = 1){
    sum[x1][y1] += t;
    sum[x2][y1] -= t;
    sum[x1][y2] -= t;
    sum[x2][y2] += t;
  }
};
