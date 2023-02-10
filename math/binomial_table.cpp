#pragma once

template<typename T>
vector<vector<T>> binomial_table(int n){
  vector<vector<T>> mat(n+1, vector<T>(n+1));
  for(int i = 0; i <= n; ++i){
    for(int j = 0; j <= i; ++j){
      if(j == 0 || j == i) mat[i][j] = 1;
      else mat[i][j] = mat[i-1][j-1] + mat[i-1][j];
    }
  }
  return mat;
}
