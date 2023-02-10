#pragma once

template<typename T>
vector<vector<T>> rotate(const vector<vector<T>> &a){
  int h = int(a.size()), w = int(a[0].size());
  vector<vector<T>> b(w, vector<T>(h));
  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      b[j][h-i-1] = a[i][j];
    }
  }
  return b;
}
